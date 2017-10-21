#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>

extern "C" {
#include "user_interface.h"
}


#define HTTP_MAX_DATA_WAIT 500 //ms to wait for the client to send the request
#define HTTP_MAX_POST_WAIT 500 //ms to wait for POST data to arrive
#define HTTP_MAX_SEND_WAIT 500 //ms to wait for data chunk to be ACKed
#define HTTP_MAX_CLOSE_WAIT 200 //ms to wait for the client to close the connection


// WiFi
const char* ssid     = "ring_abl";
const char* password = "nous avons oubliez";
const int channel = 6;

IPAddress local_IP(192,168,1,2);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

// Ring
int I_RING = 0;
unsigned long last_runned = 0;
int interval_between_steps = 1000;

// Neopixel
#define PIN            4
#define MAX_PIXEL_NUMBER 100

int num_pixels = 15;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAX_PIXEL_NUMBER, PIN, NEO_GRB + NEO_KHZ800);

// debug
int last_time = 0;

void handle_root()
{
  Serial.println("in handle root...");
  server.send(200, "text/plain", "Hello from ring abl root.");
  Serial.println("...end handle root");
}

void get_ok()
{
 
  Serial.println("in get ok...");  
  server.send(200, "text/plain", "");  
  Serial.println("...end get ok");
 
}

void get_ring()
{
  Serial.println("in get ring...");    
  server.send(200, "text/plain", "");  

  if(I_RING == 0)
  {
    Serial.println("     in if I_RING == 0...");    
    last_runned = millis();
    I_RING = 20;
    Serial.println("     ...I_RING = 20");    
  }
  Serial.println("...end get ring");    
}

void make_ring()
{
  if((millis() - last_runned) < interval_between_steps){
    return;
  }

  // Begin of animation
  last_runned = millis();

  int red = 0;
  int blue = 0;
  int green = 0;
  
  if(I_RING % 2 == 0)
  {
    red = 100;
    blue = 0;
    green = 0;
  }
  else
  {
    red = 0;
    blue = 0;
    green = 100;  
  }
  
  for(int i=0;i< (num_pixels);i++){
    pixels.setPixelColor(i, red, green, blue); 
  }
  
  pixels.show(); // This sends the updated pixel color to the hardware.
  I_RING--;
  Serial.println("...end make ring (set color)");    

}

void stop_ring()
{
  for(int i = 0; i != num_pixels; i++)
    pixels.setPixelColor(i, 0, 0, 0);  
  pixels.show();
}

void setup() {
  Serial.begin(9600);
  Serial.setDebugOutput(true);

  // connect to wifi
  connect_to_wifi();
  
  server.on("/", handle_root);
  server.on("/ok", get_ok);
  server.on("/ring", get_ring);

  server.begin();
  Serial.println("HTTP server started");
  
  pixels.begin();
  Serial.println("Neopixels started");
}

void loop() {
  server.handleClient();

  if((millis() - last_time) > 1500){
    last_time = millis();
    Serial.print(millis()); 
    uint32_t free = system_get_free_heap_size();
    Serial.print(" - ");
    Serial.println(free);
  }

  if(I_RING != 0)
  {
    make_ring(); 
  }
  else
  {
    stop_ring();  
  }
}


void connect_to_wifi(){
  Serial.print("wifi status disconnected?"); Serial.println(WiFi.status() != WL_CONNECTED);

  
  IPAddress local_IP(192,168,1,2);
  IPAddress gateway(192,168,1,1);
  IPAddress subnet(255,255,255,0);
  WiFi.config(local_IP, gateway, subnet);
  
  if(WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
      
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());
  }
}

