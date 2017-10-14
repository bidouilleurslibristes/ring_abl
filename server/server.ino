#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>

// WiFi
const char* ssid     = "ring_abl";
const char* password = "nous avons oubliez";
const int channel = 6;

IPAddress local_IP(192,168,1,1);
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
  /*
  Serial.println("in handle root...");
  server.send(200, "text/plain", "Hello from ring abl root.");
  Serial.println("...end handle root");
  */
}

void get_ok()
{
 
  Serial.println("in get ok...");  
  server.send(200, "text/plain", "Great if you are button you run");  
  Serial.println("...end get ok");
 
}

void get_ring()
{
  Serial.println("in get ring...");    
  server.send(200, "text/plain", "I ring");  

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

  /*
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
  */
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
  
  Serial.print("Setting soft-AP configuration ... ");
  WiFi.mode(WIFI_AP);
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  
  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid, password, channel, false) ? "Ready" : "Failed!");
  Serial.println("WiFi created");
  Serial.println(WiFi.softAPIP());

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

  if((millis() - last_time) > 500){
    last_time = millis();
    Serial.println(millis()); 
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

