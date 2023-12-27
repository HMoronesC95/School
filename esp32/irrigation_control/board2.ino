#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

#include "fauxmoESP.h"

#define RIEGO "El riego"

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

int Relevador_Riego_Signal = 0;
int Relevador_Riego = 23;

const int Caudalimetro_Riegopin = 4;
const int factor_k = 3.5;
volatile int pulseConter;
double volume = 0;
double volume_anterior = 0;
double volume_acum = 0;
int volume_flag = 0;
long t0 = 0;
const int measureInterval = 1000;

int data_change_alexa = 0;

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

  attachInterrupt(digitalPinToInterrupt(Caudalimetro_Riegopin), ISRCountPulse, RISING);
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
  pinMode(Relevador_Riego, OUTPUT);
  digitalWrite(Relevador_Riego, LOW);

  pinMode(Caudalimetro_Riegopin, INPUT);

  fauxmo.setPort(80); // This is required for gen3 devices
  fauxmo.enable(true);
  fauxmo.addDevice(RIEGO);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    // Callback when a command from Alexa is received. 
    // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
    // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
    // Just remember not to delay too much here, this is a callback, exit as soon as possible.
    // If you have to do something more involved here set a flag and process it in your main loop.
        
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);

    if ( (strcmp(device_name, RIEGO) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 2 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        //digitalWrite(LED_BUILTIN, HIGH);
        Relevador_Riego_Signal = 1;
        data_change_alexa = 1;
      } else {
       // digitalWrite(LED_BUILTIN, LOW);
        Relevador_Riego_Signal = 0;
        data_change_alexa = 3;
      }
    }
  });
  delay(100);

  if(Firebase.ready()){
    if (Firebase.RTDB.getDouble(&fbdo, "Casa/Agua/Sensores/Caudalimetro_Riego")) {
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
    
    if (Firebase.RTDB.setDouble(&fbdo, "Casa/Agua/Sensores/Caudalimetro_Riego", volume)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }
  /*
  else{

    if (Firebase.RTDB.setDouble(&fbdo, "Casa/Agua/Sensores/Caudalimetro_Riego", volume_acum)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    
  }
  */
  if(data_change_alexa == 1){

    if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Riego", 1)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
      data_change_alexa = 2;          
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }else if(data_change_alexa == 2){
    
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

     
    }else if(data_change_alexa == 3){
      if (Firebase.RTDB.setInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Riego", 0)){
        Serial.println("PASSED");
        Serial.println("PATH: " + fbdo.dataPath());
        Serial.println("TYPE: " + fbdo.dataType());
        data_change_alexa = 4;          
      }
      else {
        Serial.println("FAILED");
        Serial.println("REASON: " + fbdo.errorReason());
      }              
    }  
    else if(data_change_alexa == 4){
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
    
}

void DB_Recive(){
  
    if (Firebase.RTDB.getInt(&fbdo, "Casa/Agua/Actuadores/Relevador_Riego")) {
      if (fbdo.dataType() == "int") {
        intValue = (int)fbdo.intData();
        if(intValue == 1){
          Relevador_Riego_Signal = 1;
        }else{
          Relevador_Riego_Signal = 0;
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
    
   
   /*
   Serial.print(" Caudal: ");
   Serial.print(flow_Lmin, 3);
   Serial.print(" (L/min)\tConsumo:");
   Serial.print(volume, 1);
   Serial.println(" (L)");
  */
  
}

void loop(){

  
   fauxmo.handle();
  
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 2000 || sendDataPrevMillis == 0)){
    
    sendDataPrevMillis = millis();

    DB_Send();
    
    if(data_change_alexa == 0)
      DB_Recive();
  }

  if(Relevador_Riego_Signal == 1){
    digitalWrite(Relevador_Riego, HIGH);
  }
  else{
    digitalWrite(Relevador_Riego, LOW);
  }

  Caudalimetro_Input();
  
}
