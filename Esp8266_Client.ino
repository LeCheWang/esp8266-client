/*
	Esp8266 Websockets Client

	This sketch:
        1. Connects to a WiFi network
        2. Connects to a Websockets server
        3. Sends the websockets server a message ("Hello Server")
        4. Prints all incoming messages while the connection is open

	Hardware:
        For this sketch you only need an ESP8266 board.

	Created 15/02/2019
	By Gil Maimon
	https://github.com/gilmaimon/ArduinoWebsockets

*/

#include <ArduinoWebsockets.h>
#include <ESP8266WiFi.h>
#include <Wire.h> 
#include "rgb_lcd.h"

const char* ssid = "PhongPhuong"; //Enter SSID
const char* password = "12345678900"; //Enter Password
const char* websockets_server_host = "wss://realtime.gorokiapp.com"; //Enter server adress
const uint16_t websockets_server_port = 443; // Enter server port
const char* ID_AREA="642d3cd0435ca36eda05177d";

using namespace websockets;

WebsocketsClient client;

//lcd
rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

void setup() {
  Serial.begin(9600);

  // lcd.begin(16, 2);
  // lcd.setRGB(colorR, colorG, colorB);

  //pin led
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT); //not use
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT); //not use
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  // Connect to wifi
  WiFi.begin(ssid, password);

  // Wait some time to connect to wifi
  for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
      Serial.print(".");
      delay(1000);
  }

  // Check if connected to wifi
  if(WiFi.status() != WL_CONNECTED) {
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.println("No Wifi!");
    lcd.print("No Wifi!");
    return;
  }

  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("WIFI Connected");
  Serial.println("Connected to Wifi, Connecting to server.");
  // try to connect to Websockets server
  connectWebSocket();
}

void loop() {
  //let the websockets client check for incoming messages
  if(client.available()) {
      client.poll();
  }

  delay(500);

  // // run callback when messages are received
  onMessage();
}

void connectWebSocket(){
  bool connected = client.connect(websockets_server_host);
  if(connected) {
      Serial.println("Connected!");
      lcd.setCursor(0, 1);
      lcd.print("              ");
      lcd.setCursor(0, 1);
      lcd.print("WS Connected");
  } else {
      Serial.println("Not Connected!");
  }  
}

void onMessage(){
  client.onMessage([&](WebsocketsMessage message) {
    Serial.print("Got Message: ");
    Serial.println(message.data());

      //led 0
      if (message.data() == "642d3cd0435ca36eda05177d;0;0"){
        Serial.println(0);
        digitalWrite(0, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("0: OFF");
      }else if (message.data() == "642d3cd0435ca36eda05177d;0;1"){
        Serial.println(1);
        digitalWrite(0, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("0: ON");
      }else if (message.data() == "642d3cd0435ca36eda05177d;2;0"){  //led 2
        Serial.println(0);
        digitalWrite(2, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("2: OFF");
      }else if (message.data() == "642d3cd0435ca36eda05177d;2;1"){
        Serial.println(1);
        digitalWrite(2, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("2: ON");
      } else if (message.data() == "642d3cd0435ca36eda05177d;4;0"){ //led 4
        Serial.println(0);
        digitalWrite(4, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("4: OFF");
      } else if (message.data() == "642d3cd0435ca36eda05177d;4;1"){
        Serial.println(1);
        digitalWrite(4, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("4: ON");
      } else if (message.data() == "642d3cd0435ca36eda05177d;5;0"){ //led 5
        Serial.println(0);
        digitalWrite(5, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("5: OFF");
      } else if (message.data() == "642d3cd0435ca36eda05177d;5;1"){
        Serial.println(1);
        digitalWrite(5, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("5: ON");
      } else if (message.data() == "642d3cd0435ca36eda05177d;12;0"){ //led 12
        Serial.println(0);
        digitalWrite(12, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("12: OFF");
      } else if (message.data() == "642d3cd0435ca36eda05177d;12;1"){ 
        Serial.println(1);
        digitalWrite(12, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("12: ON");
      } else if (message.data() == "642d3cd0435ca36eda05177d;14;0"){ //led 14
        Serial.println(0);
        digitalWrite(14, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("14: OFF");
      } else if (message.data() == "642d3cd0435ca36eda05177d;14;1"){
        Serial.println(1);
        digitalWrite(14, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("14: ON");
      } else if (message.data() == "642d3cd0435ca36eda05177d;16;0"){ //led 16
        Serial.println(0);
        digitalWrite(16, LOW);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("16: OFF");
      } else if (message.data() == "642d3cd0435ca36eda05177d;16;1"){
        Serial.println(1);
        digitalWrite(16, HIGH);
        lcd.setCursor(0, 1);
        lcd.print("              ");
        lcd.setCursor(0, 1);
        lcd.print("16: ON");
      }
  });
}