#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>

// WiFi
const char* ssid     = "waf";
const char* password = "jaioublie";

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

void handle_root()
{
  server.send(200, "text/plain", "Hello from ring abl root.");
}

void get_ok()
{
  server.send(200, "text/plain", "Great if you are button you run");  
}

void get_ring()
{
  server.send(200, "text/plain", "I ring");  

  if(I_RING == 0)
  {
    last_runned = millis();
    I_RING = 20;
  }
}

void make_ring()
{
  if((millis() - last_runned) < interval_between_steps)
    return;

  // Begin of animation
  last_runned = millis();

  int red = 0;
  int blue = 0;
  int green = 0;
  
  if(I_RING % 2 == 0)
  {
    red = 255;
    blue = 0;
    green = 0;
  }
  else
  {
    red = 0;
    blue = 0;
    green = 255;  
  }
  
  for(int i=0;i< (num_pixels);i++){
    pixels.setPixelColor(i, red, green, blue); 
  }
  
  pixels.show(); // This sends the updated pixel color to the hardware.
  
  I_RING--;
}

void stop_ring()
{
  for(int i = 0; i != num_pixels; i++)
    pixels.setPixelColor(i, 0, 0, 0);  
  pixels.show();
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
    
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

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

  if(I_RING != 0)
  {
    make_ring(); 
  }
  else
  {
    stop_ring();  
  }
}
