#include <ESP8266WiFi.h>
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
}


void loop() {
  if(millis() % 50 != 0)
  {
    return;
  }

  if(millis() % 20000 == 0)
  {
    http_ok.GET();  
  }
  val = analogRead(A0);
  int mean = noise_mean();
  
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
