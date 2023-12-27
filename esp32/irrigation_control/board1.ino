#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

#include "fauxmoESP.h"

#define BOMBA "La bomba"
#define ALJIBE "El aljibe"

fauxmoESP fauxmo;

//api firease 
//AIzaSyBaxDD_JNf3MVa2F2OwkvIxhhhqkAmC_DI

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "Totalplay-2.4G-8ff0"
#define WIFI_PASSWORD "yzrQBPaevPT2fbyd"

// Insert Firebase project API Key
#define API_KEY "AIzaSyBaxDD_JNf3MVa2F2OwkvIxhhhqkAmC_DI"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://control-casa-1cace-default-rtdb.firebaseio.com/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

int intValue;
double doubleValue;

int LED_BUILTIN = 2;

int Relevador_Bomba_Signal = 0;
int Relevador_Bomba = 18;

int Relevador_Aljibe_Signal = 0;
int Relevador_Aljibe = 5;

const int Caudalimetro_Bombapin = 15;
const float factor_k = 0.45;
volatile int pulseConter;
double volume = 0;
double volume_anterior = 0;
double volume_acum = 0;
int volume_flag = 0;
long t0 = 0;
const int measureInterval = 1000;

int data_change_alexa = 0;

int sensor_nivel = 25;
int sensor_nivel_flag = 0;

//---Función que se ejecuta en interrupción---------------
void ISRCountPulse()
{
   pulseConter++;
}
float GetFrequency()
{
   pulseConter = 0;
   interrupts();
   delay(measureInterval);
   noInterrupts();
   return (float)pulseConter * 1000 / measureInterval;
}
void SumVolume(float dV)
{
   volume += (dV / 60 * (millis() - t0) / 1000.0);
   t0 = millis();
}

void setup(){

  attachInterrupt(digitalPinToInterrupt(Caudalimetro_Bombapin), ISRCountPulse, RISING);
  t0 = millis();
  
  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(Relevador_Bomba, OUTPUT);
  digitalWrite(Relevador_Bomba, LOW);

  pinMode(Relevador_Aljibe, OUTPUT);
  digitalWrite(Relevador_Aljibe, LOW);

  pinMode(Caudalimetro_Bombapin, INPUT);

  pinMode (sensor_nivel, INPUT);

  fauxmo.setPort(80); // This is required for gen3 devices
  fauxmo.enable(true);
  fauxmo.addDevice(BOMBA);
  fauxmo.addDevice(ALJIBE);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    // Callback when a command from Alexa is received. 
    // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
    // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
    // Just remember not to delay too much here, this is a callback, exit as soon as possible.
    // If you have to do something more involved here set a flag and process it in your main loop.
        
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);

    if ( (strcmp(device_name, BOMBA) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 2 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        //digitalWrite(LED_BUILTIN, HIGH);
        Relevador_Bomba_Signal = 1;
        data_change_alexa = 1;
      } else {
       // digitalWrite(LED_BUILTIN, LOW);
        Relevador_Bomba_Signal = 0;
        data_change_alexa = 2;
      }
    }

      if ( (strcmp(device_name, ALJIBE) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 2 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        //digitalWrite(LED_BUILTIN, HIGH);
        Relevador_Aljibe_Signal = 1;
        data_change_alexa = 3;
      } else {
       // digitalWrite(LED_BUILTIN, LOW);
        Relevador_Aljibe_Signal = 0;
        data_change_alexa = 4;
      }
    }
  });
  delay(100);

  if(Firebase.ready()){
    if (Firebase.RTDB.getDouble(&fbdo, "Casa/Agua/Sensores/Caudalimetro_Bomba")) {
      if (fbdo.dataType() == "double") {
        doubleValue = (double)fbdo.doubleData();
        if(doubleValue > 0){
          volume_acum = doubleValue;
        }else{
          volume_acum = 0;
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
  }
 
}

void DB_Send(){

  if(volume != volume_anterior){
    
    if (Firebase.RTDB.setDouble(&fbdo, "Casa/Agua/Sensores/Caudalimetro_Bomba", volume)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }

  if(data_change_alexa == 1){

    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Bomba", 1)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 0;          
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }else if(data_change_alexa == 2){
    
    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Bomba", 0)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 0;          
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }
  else if (data_change_alexa == 3){
    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Aljibe", 1)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 0;          
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }  
  }
  else if (data_change_alexa == 4){
    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Aljibe", 0)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 0;          
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }  
  }
  
if(sensor_nivel_flag == 1){
  
    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Sensores/Nivel_Aljibe", 1)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 0;   
      sensor_nivel_flag = 3;     
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  
}else if(sensor_nivel_flag == 2){
    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Sensores/Nivel_Aljibe", 0)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 0;   
      sensor_nivel_flag = 4;       
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }
   
}

void DB_Recive(){
  
    if (Firebase.RTDB.getInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Bomba")) {
      if (fbdo.dataType() == "int") {
        intValue = (int)fbdo.intData();
        if(intValue == 1){
          Relevador_Bomba_Signal = 1;
        }else{
          Relevador_Bomba_Signal = 0;
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }

    if (Firebase.RTDB.getInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Aljibe")) {
      if (fbdo.dataType() == "int") {
        intValue = (int)fbdo.intData();
        if(intValue == 1){
          Relevador_Aljibe_Signal = 1;
        }else{
          Relevador_Aljibe_Signal = 0;
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
}

void Caudalimetro_Input(){

   volume_anterior = volume;

   // obtener frecuencia en Hz
   float frequency = GetFrequency();
   // calcular caudal L/min
   float flow_Lmin = frequency / factor_k;
   

   if(volume_flag == 0){
    if(flow_Lmin > 0){
      SumVolume(flow_Lmin);
      volume = volume_acum;
      volume_flag = 1;
    }
    else{
      volume_flag = 0;
    }
   }
   else if(volume_flag == 1){
    if(flow_Lmin > 0){
      SumVolume(flow_Lmin);
    }
    else{
      volume_flag = 2;
    } 
   }
   else if(volume_flag == 2){
    volume_acum = volume;
    volume_flag = 0;
   }
}

void loop(){

  
   fauxmo.handle();
  
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 2000 || sendDataPrevMillis == 0)){
    
    sendDataPrevMillis = millis();

    DB_Send();
    
    if(data_change_alexa == 0)
      DB_Recive();
  }

  if(Relevador_Bomba_Signal == 1){
    digitalWrite(Relevador_Bomba, HIGH);
  }
  else{
    digitalWrite(Relevador_Bomba, LOW);
  }

  if(Relevador_Aljibe_Signal == 1){
    digitalWrite(Relevador_Aljibe, HIGH);
  }
  else{
    digitalWrite(Relevador_Aljibe, LOW);
  }

  Caudalimetro_Input();

  if(sensor_nivel_flag == 0){
    if(digitalRead(sensor_nivel) == HIGH){
      //digitalWrite(LED_BUILTIN, HIGH);
      sensor_nivel_flag = 1;
    }
    else{
     // digitalWrite(LED_BUILTIN, LOW);
      sensor_nivel_flag = 2;
    }
  }
  else if (sensor_nivel_flag == 1){
    if(digitalRead(sensor_nivel) == HIGH){
      sensor_nivel_flag = 1;
    }
    else{
      sensor_nivel_flag = 0;
    }
  }
  else if (sensor_nivel_flag == 2){
    if(digitalRead(sensor_nivel) == LOW){
      sensor_nivel_flag = 2;
    }
    else{
      sensor_nivel_flag = 0;
    }
  }
  else if (sensor_nivel_flag == 3){
    if(digitalRead(sensor_nivel) == HIGH){
      sensor_nivel_flag = 3;
    }
    else{
      sensor_nivel_flag = 0;
    } 
  }
  else if(sensor_nivel_flag == 4){
    if(digitalRead(sensor_nivel) == LOW){
      sensor_nivel_flag = 4;
    }
    else{
      sensor_nivel_flag = 0;
    } 
  }
  
}
