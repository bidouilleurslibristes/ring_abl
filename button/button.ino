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

// Led light when they aren't connect
int pin_led_no_wifi = 16;

// Led message send
int pin_led_message_send = 5;

void handle_set_threshold()
{
  threshold = server.arg("value").toInt();
  server.send(200, "text/plain", "New value of threshold are "+ String(threshold));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // LED setting
  pinMode(pin_led_no_wifi, OUTPUT);
  pinMode(pin_led_message_send, OUTPUT);
  
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    digitalWrite(pin_led_no_wifi, HIGH);
  }
  
  digitalWrite(pin_led_no_wifi, LOW);
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
  
  if(WiFi.status() != WL_CONNECTED)
  {
    //WiFi.begin(ssid, password);
    digitalWrite(pin_led_no_wifi, HIGH);
  }
  else
  {
    digitalWrite(pin_led_no_wifi, LOW);
  }
  
  val = analogRead(A0);
  int mean = noise_mean();
  
  if(digitalRead(pin_led_message_send) == HIGH)
  {
    digitalWrite(pin_led_message_send, LOW);
  }

  Serial.println(val);
  if(val < mean - threshold)
  {
    Serial.println("WIN");
    if(http_ring.GET() == HTTP_CODE_OK)
    {
      digitalWrite(pin_led_message_send, HIGH);
    }  
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
