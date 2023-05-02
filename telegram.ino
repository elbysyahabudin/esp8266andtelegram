#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "Your WiFi";
const char* password = "Your WiFi Password";

const char* token = "";
String id = "";
WiFiClientSecure client;

UniversalTelegramBot bot(token, client);

void setup() {
  
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  client.setInsecure();
}

void loop() 
{
  bot.sendMessage(id, "Hello Telegram! ESP8266 here!", ""); 
  delay(2000);
}
