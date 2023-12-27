//CODIGO PARA EL CONTROL DE UN SCOOTER
int pwm1 = 3;
int pwm2 = 5; 
int pot_pin = A0;
int output;
int pwm_value;
int sentido_pin = 8;
int parking_pin = 7;
int led_parking = 2;
int led_drive = 4;
int counter = 0;

void setup() {
  Serial.begin(9600);           //  setup serial
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(sentido_pin, INPUT_PULLUP);
  pinMode(parking_pin, INPUT_PULLUP);
  digitalWrite(led_parking, 0);
  digitalWrite(led_drive, 0);
  
}

void loop() 
{
  int parking_condition = digitalRead(parking_pin);

  if (!counter) digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  counter++;
  
  if(parking_condition == LOW)
  {
    digitalWrite(led_parking, 0);
    output = analogRead(pot_pin);
    pwm_value = output - 170;
    if(pwm_value < 0)
      pwm_value = 0;
    pwm_value = int(pwm_value*0.36);
    if(pwm_value > 255)
      pwm_value = 255;

    int sentido_condition = digitalRead(sentido_pin);
  
    if(sentido_condition == HIGH)
    {
      analogWrite(pwm1, pwm_value);
      analogWrite(pwm2, 0); 
      digitalWrite(led_drive, 0);   
    }
    else 
    {
      analogWrite(pwm2, pwm_value);
      analogWrite(pwm1, 0); 
      digitalWrite(led_drive, 1);
    }
  }//fin del parking condition. la siguiente parte "else" es cuando la entrada esta en LOW
  else
  {
      
      analogWrite(pwm1, 0);
      analogWrite(pwm2, 0);  
      digitalWrite(led_parking, 1);
      digitalWrite(led_drive, 0);
  }

  //Serial.println(pwm_value);          // debug value

}//fin del loop
