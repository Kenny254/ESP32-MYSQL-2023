
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>


// Replace with your network credentials
const char* ssid     = "MFA-STAFF";
const char* password = "12345678";

// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "https://iot.mpesafoundationacademy.ac.ke/post-esp-data.php";

// Keep this API Key value to be compatible with the PHP code provided in the project page. 
// If you change the apiKeyValue value, the PHP file /post-esp-data.php also needs to have the same key 
String apiKeyValue = "tPmAT5Ab3j7F9";

String sensorName = "TDS Sensor";
String sensorLocation = "MFA";
String value1 = "50";
String value2 = "40";
String value3 = "10";

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

 
}

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    WiFiClientSecure *client = new WiFiClientSecure;
    client->setInsecure(); //don't use SSL certificate
    HTTPClient https;
    
    // Your Domain name with URL path or IP address with path
    https.begin(*client, serverName);
    
    // Specify content-type header
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
    String httpRequestData = 
                             "api_key=" + apiKeyValue + 
                             "&sensor=" + sensorName  +
                             "&location=" + sensorLocation +
                             "&value1=" + value1  +
                             "&value2=" + value2  +
                             "&value3=" + value3  +
                             "";
    Serial.println(httpRequestData);


   int httpResponseCode = https.POST(httpRequestData);

    
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    https.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 30 seconds
  delay(2000);  
}
