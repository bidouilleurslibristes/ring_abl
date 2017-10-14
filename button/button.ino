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

// timestamp
unsigned long last_ring_ts;

//http server
ESP8266WebServer server(80);

// Led light when they aren't connect
int pin_led_no_wifi = 4;

// Led message send
int pin_led_message_send = 5;

// Led detect light
int pin_led_detection = 12;


void handle_set_threshold()
{
  threshold = server.arg("value").toInt();
  server.send(200, "text/plain", "New value of threshold are "+ String(threshold));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  connect_to_wifi();

  // LED setting
  pinMode(pin_led_no_wifi, OUTPUT);
  pinMode(pin_led_message_send, OUTPUT);
  pinMode(pin_led_detection, OUTPUT);

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

  if(millis() % 2000 == 0)
  {
    _get("/ok"); 
  }
  
  if(WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(pin_led_no_wifi, HIGH);
    //WiFi.begin(ssid, password);
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

  if(digitalRead(pin_led_detection) == HIGH)
  {
    digitalWrite(pin_led_detection, LOW);
  }


  Serial.println(val);
  if(val < mean - threshold)
  {
    Serial.print("TS: ");
    Serial.println((millis() - last_ring_ts));

    if ((millis() - last_ring_ts) < 10000){
      return;
    }

    digitalWrite(pin_led_detection, HIGH);
    int resp_code;
    resp_code = _get("/ring");
    if(resp_code == HTTP_CODE_OK)
    {
      Serial.println("WIN");
      last_ring_ts = millis();
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

void connect_to_wifi(){
  digitalWrite(pin_led_no_wifi, HIGH);
  Serial.print("wifi status disconnected?"); Serial.println(WiFi.status() != WL_CONNECTED);

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
  digitalWrite(pin_led_no_wifi, LOW);

}


int _get(const String &endpoint){

  if(WiFi.status() != WL_CONNECTED){
    return -1
  }
  
  HTTPClient _client;
  const String url = "http://192.168.1.1"+ endpoint;
  _client.begin(url);
  
  int res = _client.GET();
  Serial.print(url); Serial.print(" :: result from get: "); Serial.println(res);
  _client.end();
  return res;
}

