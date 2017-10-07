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
const char* ssid     = "ring_abl";
const char* password = "nous avons oubliez"; 

// http client
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
  
  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  Serial.print("WL_IDLE_STATUS ");
  Serial.println(WL_IDLE_STATUS);
  Serial.print("WL_NO_SSID_AVAIL ");
  Serial.println(WL_NO_SSID_AVAIL);
  Serial.print("WL_SCAN_COMPLETED ");
  Serial.println(WL_SCAN_COMPLETED);
  Serial.print("WL_CONNECTED ");
  Serial.println(WL_CONNECTED);
  Serial.print("WL_CONNECT_FAILED ");
  Serial.println(WL_CONNECT_FAILED);
  Serial.print("WL_CONNECTION_LOST ");
  Serial.println(WL_CONNECTION_LOST);
  Serial.print("WL_DISCONNECTED ");
  Serial.println(WL_DISCONNECTED);

  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(WiFi.status());
    }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  http_ring.begin("http://192.168.1.1/ring");
  http_ok.begin("http://192.168.1.1/ok");

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
