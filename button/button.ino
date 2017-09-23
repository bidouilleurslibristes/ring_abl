#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

// ring
int ring_noise[255] = {0};
unsigned char noise_token = 0;

// detector
int threshold = 50;
int val = 0;

// Wifi
const char* ssid = "waf";
const char* password = "jaioublie"; 

// http clien
HTTPClient http_ok;
HTTPClient http_ring;

//http server
ESP8266WebServer server(80);

void handle_set_threshold()
{
  threshold = server.arg("value").toInt();
  server.send(200, "text/plain", "New value of threshold are "+ String(threshold));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  http_ring.begin("http://192.168.43.97/ring");
  http_ok.begin("http://192.168.43.97/ok");

  //set server request
  server.on("/threshold", handle_set_threshold);

  server.begin();
  Serial.println("HTTP server started");
}


void loop() {
  server.handleClient();
  
  if(millis() % 500 != 0)
  {
    return;
  }

  if(millis() % 20000 == 0)
  {
    http_ok.GET(); 
  }
  
  val = analogRead(A0);
  int mean = noise_mean();

  Serial.println(val);
  if(val < mean - threshold)
  {
    Serial.println("WIN");
    http_ring.GET();
  }
  
  ring_noise[noise_token] = val;
  
  noise_token++;
}

int noise_mean()
{
  long sum = 0;
  
  for(unsigned char i = 0; i != 255; i++)
  {
    sum += ring_noise[i];
  }
  
  return sum/255;
}
