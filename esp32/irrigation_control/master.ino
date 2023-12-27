#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

#include "fauxmoESP.h"

#define SERIAL_BAUDRATE 115200

#define WIFI_SSID "Totalplay-2.4G-8ff0"
#define WIFI_PASS "yzrQBPaevPT2fbyd"

#define ALJIBE "El aljibe"
#define BOMBA "La bomba"
#define RIEGO "El riego"

int LED_BUILTIN = 2;

int rele_aljibe = 5;
int rele_bomba = 18;

fauxmoESP fauxmo;

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t broadcastAddress2[] = {0x30, 0xC6, 0xF7, 0x0D, 0xF6, 0xA4};//mac2
uint8_t broadcastAddress3[] = {0x78, 0x21, 0x84, 0x82, 0xDA, 0x34};//mac3

typedef struct send_struct {
  int id = 1;
  bool valvula_aljibe;
  bool bomba;
  bool valvula_riego;
  int y3;
} send_message;

  send_message send_board;

  esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

typedef struct recive_struct {
  int id;
  bool valvula_aljibe;
  bool bomba;
  bool valvula_riego;
  int y3;
}recive_message;

  recive_message recive_board;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&recive_board, incomingData, sizeof(recive_board));
  Serial.print("Bytes received: ");
  Serial.println(len);
  if(recive_board.id == 2){
    Serial.print("Data from board 2: ");
  }
  if(recive_board.id == 3){
    Serial.print("Data from board 3: ");
  }
}

// Wi-Fi Connection
void wifiSetup() {
  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);

  // Connect
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();

  // Connected!
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}



void setup() {
 
  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();

  pinMode(rele_aljibe, OUTPUT);
  pinMode(rele_bomba, OUTPUT);

  pinMode (LED_BUILTIN, OUTPUT);
 
 
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

    // Wi-Fi connection
  wifiSetup();
  esp_now_register_send_cb(OnDataSent);

    // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);

  // Register peer
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // register first peer  
  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  
  // register second peer  
  memcpy(peerInfo.peer_addr, broadcastAddress3, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

 // By default, fauxmoESP creates it's own webserver on the defined port
  // The TCP port must be 80 for gen3 devices (default is 1901)
  // This has to be done before the call to enable()
  fauxmo.createServer(true); // not needed, this is the default value
  fauxmo.setPort(80); // This is required for gen3 devices

  // You have to call enable(true) once you have a WiFi connection
  // You can enable or disable the library at any moment
  // Disabling it will prevent the devices from being discovered and switched
  fauxmo.enable(true);
  // You can use different ways to invoke alexa to modify the devices state:
  // "Alexa, turn lamp two on"

  // Add virtual devices
  
  fauxmo.addDevice(ALJIBE);

  fauxmo.addDevice(BOMBA);
  fauxmo.addDevice(RIEGO);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    // Callback when a command from Alexa is received. 
    // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
    // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
    // Just remember not to delay too much here, this is a callback, exit as soon as possible.
    // If you have to do something more involved here set a flag and process it in your main loop.
        
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);

    if ( (strcmp(device_name, ALJIBE) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 2 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        digitalWrite(rele_aljibe, HIGH);
      } else {
        digitalWrite(rele_aljibe, LOW);
      }
    }
    if ( (strcmp(device_name, BOMBA) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 1 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        digitalWrite(rele_bomba, HIGH);
      } else {
        digitalWrite(rele_bomba, LOW);
      }
    }
       if ( (strcmp(device_name, RIEGO) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 1 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        send_board.valvula_riego = 1;
      } else {
        send_board.valvula_riego = 0;
      }
    }
  });
  
}
 
void loop() {

//  send_board.x2 = 2;
//  send_board.y2 = random(0,20);
//  send_board.x3 = 3;
//  send_board.y3 = 0;
 
  esp_err_t result2 = esp_now_send(
    broadcastAddress2, 
    (uint8_t *) &send_board,
    sizeof(send_board));
   
  if (result2 == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(500);

 // send_board.x2 = 2;
 // send_board.y2 = 0;
//  send_board.x3 = 3;
//  send_board.y3 = random(0,20);
  
  esp_err_t result3 = esp_now_send(
    broadcastAddress3, 
    (uint8_t *) &send_board,
    sizeof(send_board));

  if (result3 == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  
  delay(500);
}
