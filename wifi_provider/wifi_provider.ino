#include <ESP8266WiFi.h>


// WiFi
const char* ssid     = "ring_abl";
const char* password = "nous avons oubliez";
const int channel = 6;

IPAddress local_IP(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);


void setup() {
  
  Serial.begin(9600);
  Serial.setDebugOutput(true);
  
  WiFi.mode(WIFI_AP);
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  
  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid, password, channel, false) ? "Ready" : "Failed!");
  Serial.println("WiFi created");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
