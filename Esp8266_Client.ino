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

const char* ssid = "PhongPhuong"; //Enter SSID
const char* password = "12345678900"; //Enter Password
const char* websockets_server_host = "wss://realtime.gorokiapp.com"; //Enter server adress
const uint16_t websockets_server_port = 443; // Enter server port
const char* ID_AREA="642d3cd0435ca36eda05177d";

using namespace websockets;

WebsocketsClient client;

int giatri;
int camBienRung = 16;
void setup() {
    Serial.begin(9600);

    //pin led
    pinMode(camBienRung, INPUT);
    pinMode(5, OUTPUT);
    // Connect to wifi
    // WiFi.begin(ssid, password);

    // // Wait some time to connect to wifi
    // for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
    //     Serial.print(".");
    //     delay(1000);
    // }

    // // Check if connected to wifi
    // if(WiFi.status() != WL_CONNECTED) {
    //     Serial.println("No Wifi!");
    //     return;
    // }

    // Serial.println("Connected to Wifi, Connecting to server.");
    // // try to connect to Websockets server
    // bool connected = client.connect(websockets_server_host);
    // if(connected) {
    //     Serial.println("Connecetd!");
    //     client.send("Hello Server");
    // } else {
    //     Serial.println("Not Connected!");
    // }
    
    // // run callback when messages are received
    // client.onMessage([&](WebsocketsMessage message) {
    //   Serial.print("Got Message: ");
    //   Serial.println(message.data());
    //   if (message.data() == "undefined;16;0") {
    //     Serial.println(0);
    //     digitalWrite(16, LOW);
    //   }
    //   if (message.data() == "undefined;16;1") {
    //     Serial.println(1);
    //     digitalWrite(16, HIGH);
    //   }
    // });
}

void loop() {
  giatri = digitalRead(camBienRung);
  Serial.print("rung: ");
  Serial.println(giatri);
  delay(200);
    // let the websockets client check for incoming messages
    // if(client.available()) {
    //     client.poll();
    // }
    // delay(500);
}