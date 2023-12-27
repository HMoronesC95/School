#include <esp_now.h>
#include <WiFi.h>
int LED_BUILTIN = 2;
int rele_riego = 23;

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t broadcastAddress1[] = {0xEC, 0x62, 0x60, 0x94, 0xE1, 0xB8};//mac1
uint8_t broadcastAddress2[] = {0x30, 0xC6, 0xF7, 0x0D, 0xF6, 0xA4};//mac2

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
  if(recive_board.id == 1){
    Serial.print("Data from board 1: ");
 //   Serial.println(recive_board.x2);
 //   Serial.println(recive_board.y2);
    Serial.println();
    if(recive_board.valvula_aljibe == 1){
      digitalWrite(rele_riego, HIGH);
    }
    else if(recive_board.valvula_aljibe == 0){
      digitalWrite(rele_riego, LOW);
    }
    
  }
  if(recive_board.id == 2){
    Serial.print("Data from board 2: ");
 //   Serial.println(recive_board.x3);
 //   Serial.println(recive_board.y3);
    Serial.println();
  }
}

 
void setup() {
 
  Serial.begin(115200);

  pinMode (LED_BUILTIN, OUTPUT);

  pinMode (rele, OUTPUT);
 
  WiFi.mode(WIFI_STA);
 
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

    // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);

  // Register peer
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // register first peer  
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  
  // register second peer  
  memcpy(peerInfo.peer_addr, broadcastAddress2, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {

 // send_board.x2 = 1;
 // send_board.y2 = random(0,20);
 // send_board.x3 = 2;
//  send_board.y3 = 0;
 
  esp_err_t result1 = esp_now_send(
    broadcastAddress1, 
    (uint8_t *) &send_board,
    sizeof(send_board));
   
  if (result1 == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(500);

 // send_board.x2 = 1;
 // send_board.y2 = 0;
 // send_board.x3 = 2;
 // send_board.y3 = random(0,20);
  
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

  
  
  delay(2000);
}
