#include <Wire.h>
#include "HardwareTimer.h"
TwoWire WIRE2 (2,I2C_FAST_MODE);
#define Wire WIRE2
#define PPR   1024
#define TS  0.002
#define PWMA1 PB6
#define PWMA2 PB7
#define PWMB1 PB8
#define PWMB2 PB9  

#define DBG_PIN PB12

//#define DEBUG

#define UMAX  99
#define DEADB 3
#define OFFS  0.0005
#define LEVEL 2
#define SAMPLES 1000

bool enable = false;
int serial_counter = 0;
int setpt_counter = 0;
long tick_timer = 0;
int gyro_address = 0x68;
int gyro_cal_value = 748;


const double k1 = -18.0;//24
const double k2 = -0.38;//.38;
const double k3 = -0.95;
const double k4 = -0.01;
const double k0 = 0.95;
const double ki = -0.0;
double sum_ki = 0;


/*
const double k1 = -18.0;
const double k2 = -0.38;
const double k3 = -0.95;
const double k4 = -0.01;
const double k0 = 0.95;
*/
double output = 0.0;
double reference = 0;
double offset_angle = 0.0;

float rate, angle;
float bias = 5.706787109375;
float P[2][2] = {{1.0, 0}, {0, 1.0}};
const float Q_angle = 0.00;//1;
const float Q_gyroBias = 0.00;//1;
const float R_measure = 0.3;
HardwareTimer pwmTimer(4);
HardwareTimer encoderA(2);
HardwareTimer encoderB(3);
long intsA = 0;
long intsB = 0;
long int countA[2] = {0, 0};
long int countB[2] = {0, 0};

void updateCounterA(void);
void updateCounterB(void);


void setup()
{
  #ifdef DEBUG
  Serial.begin(115200);
  while(!Serial) delayMicroseconds(10);
  #endif
  Serial2.begin(115200);
  while(!Serial2) delayMicroseconds(10);
  Wire.begin();

  pwmTimer.pause();
  pwmTimer.setPrescaleFactor(71);
  pwmTimer.setOverflow(99);
  pwmTimer.resume();

  encoderA.setMode(0, TIMER_ENCODER);
  encoderA.pause();
  encoderA.setPrescaleFactor(1);
  encoderA.setOverflow(PPR);
  encoderA.setCount(0);
  encoderA.setEdgeCounting(TIMER_SMCR_SMS_ENCODER3);
  encoderA.attachInterrupt(0, updateCounterA);
  encoderA.resume();

  encoderB.setMode(0, TIMER_ENCODER);
  encoderB.pause();
  encoderB.setPrescaleFactor(1);
  encoderB.setOverflow(PPR);
  encoderB.setCount(0);
  encoderB.setEdgeCounting(TIMER_SMCR_SMS_ENCODER3);
  encoderB.attachInterrupt(0, updateCounterB);
  encoderB.resume();

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PWMA1, PWM);
  pinMode(PWMA2, PWM);
  pinMode(PWMB1, PWM);
  pinMode(PWMB2, PWM);
  pinMode(DBG_PIN, OUTPUT);

  Wire.beginTransmission(gyro_address);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(gyro_address);
  Wire.write(0x1B);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(gyro_address);
  Wire.write(0x1C);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(gyro_address);
  Wire.write(0x1A);
  Wire.write(0x03);
  Wire.endTransmission();

  long counter = 0, sum = 0, i = 0;
  while(counter < SAMPLES)
  {
    Wire.beginTransmission(gyro_address);
    Wire.write(0x45);
    Wire.endTransmission();
    Wire.requestFrom(gyro_address, 2);
    short int yaw_raw_data = (Wire.read() << 8 | Wire.read());
    sum += yaw_raw_data;
    while (tick_timer > micros()) ;
    tick_timer += int(TS * 1e6);
    counter++;
    i = (i + 1) % 25;
    if (!i) digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  gyro_cal_value = sum / SAMPLES;
  bias = gyro_cal_value * (250/32768.0);
  tick_timer = micros() + int(TS * 1e6);
}

void loop()
{ 
  digitalWrite(DBG_PIN, HIGH);
  /*** Measure **************************************************/
  Wire.beginTransmission(gyro_address);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(gyro_address, 12);
  short int raw_x_acc  = (Wire.read() << 8 | Wire.read()) - 430; //489
  short int dummy_word = Wire.read() << 8 | Wire.read();
  short int raw_z_acc  = Wire.read() << 8 | Wire.read();
  dummy_word = Wire.read() << 8 | Wire.read();
  dummy_word = Wire.read() << 8 | Wire.read();
  short int raw_y_gyro = Wire.read() << 8 | Wire.read();

  float x_acc = raw_x_acc * 0.00006103515625;
  float z_acc = raw_z_acc * 0.00006103515625;
  float acc_angle = atan2(-x_acc, z_acc) * 57.295779513082323;
  float y_gyro = raw_y_gyro * 0.00762939453125;

  /*** Prediction ***************************************************/
  rate = y_gyro - bias;
  angle = angle + TS * rate;

  P[0][0] = P[0][0] + TS * (TS*P[1][1] - P[0][1] - P[1][0] + Q_angle);
  P[0][1] = P[0][1] - TS * P[0][0];
  P[1][0] = P[1][0] - TS * P[0][0];
  P[1][1] = P[1][1] + TS * Q_gyroBias;

  /*** Update *******************************************************/
  float y = acc_angle - angle;
  float S = P[0][0] + R_measure;
  float K0 = P[0][0] / S;
  float K1 = P[1][0] / S;
  angle = angle + K0 * y;
  bias = bias + K1 * y;

  float p00_temp = P[0][0];
  float p01_temp = P[0][1];
  P[0][0] = P[0][0] - K0 * p00_temp;
  P[0][1] = P[0][1] - K0 * p01_temp;
  P[1][0] = P[1][0] - K1 * p00_temp;
  P[1][1] = P[1][1] - K1 * p01_temp;

  digitalWrite(DBG_PIN, LOW);
  
  if (fabs(angle) < 0.1) enable = true;
  if (fabs(angle) > 40) enable = false;
  
  if (enable)
  {
    countA[1] = countA[0];
    countA[0] = intsA * PPR + encoderA.getCount();
    countB[1] = countB[0];
    countB[0] = intsB * PPR + encoderB.getCount();
    float x_pos = (countA[0] + countB[0]) / 2.0;
    float x_rate = ((countA[0] - countA[1]) + (countB[0] - countB[1]))/2.0;

    sum_ki = sum_ki + ki * angle;

    output = k1 * angle + k2 * rate + k3 * x_pos + k4 * x_rate + sum_ki;

    if (output > UMAX) output = UMAX;
    if (output < -UMAX) output = -UMAX;

    if (angle > 0.0 && output < 0.0){
      offset_angle -= OFFS;
      sum_ki = 0;
    }
    if (angle < 0.0 && output > 0.0){
      offset_angle += OFFS;
      sum_ki = 0;
    }

    if (output >= 0)
    {
      pwmWrite(PWMA1, 0);
      pwmWrite(PWMB1, 0);
      pwmWrite(PWMA2, (int)output + LEVEL);
      pwmWrite(PWMB2, (int)output);
    }
    else
    {
      pwmWrite(PWMA1, -(int)(output - LEVEL));
      pwmWrite(PWMB1, -(int)output);
      pwmWrite(PWMA2, 0);
      pwmWrite(PWMB2, 0);
    }
  }
  else
  {
    pwmWrite(PWMA1, 0);
    pwmWrite(PWMB1, 0);
    pwmWrite(PWMA2, 0);
    pwmWrite(PWMB2, 0);
       
    offset_angle = 0.0;
    output = 0.0;
  }
  serial_counter = (serial_counter + 1) % 500;
  if (!serial_counter)
  {
    Serial2.println(".");
  }
  #ifdef DEBUG
  if (!serial_counter)
  {
    Serial.print(acc_angle);
    Serial.print("\t");
    Serial.print(angle);
    Serial.print("\t");
    Serial.print(output);
    Serial.print("\n");
  }
  #endif
  while (tick_timer > micros()) ;
  tick_timer += int(TS * 1e6);
}

void updateCounterA(void)
{
  if (encoderA.getDirection())
    intsA--;
  else
    intsA++;
}

void updateCounterB(void)
{
  if (encoderB.getDirection())
    intsB--;
  else
    intsB++;
}
