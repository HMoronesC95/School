int LED_BUILTIN = 2;

int sensor_nivel = 25;
int x = 5;
int y = 18;

void setup() {

pinMode (LED_BUILTIN, OUTPUT);
pinMode (sensor_nivel, INPUT);
pinMode (x, OUTPUT);
pinMode (y, OUTPUT);


}


void loop() {

if(digitalRead(sensor_nivel) == HIGH)
  digitalWrite(LED_BUILTIN, HIGH);
else if(digitalRead(sensor_nivel) == LOW)
  digitalWrite(LED_BUILTIN, LOW);
else {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  }

}
