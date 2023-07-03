#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <Wire.h>

// Replace with your network credentials
const char* ssid = "KENYA";
const char* password = "12345678";

// REPLACE with your Domain name and URL path or IP address with path
const char* serverName = "https://iot.yoursitename.com/post-esp-data.php";

// Keep this API Key value to be compatible with the PHP code provided in the project page.
// If you change the apiKeyValue value, the PHP file /post-esp-data.php also needs to have the same key
String apiKeyValue = "tPmAT5Ab3j7F9";

String sensorName = "TDS Sensor";
String sensorLocation = "MFA";
String safety = "Safe";
 int temperature = random(19,24); // Generate a random number between 24 and 25

const int analogPin = 34; // Analog pin connected to the TDS sensor

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check WiFi connection status
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure *client = new WiFiClientSecure;
    client->setInsecure(); // Don't use SSL certificate
    HTTPClient https;

    // Your Domain name with URL path or IP address with path
    https.begin(*client, serverName);

    // Specify content-type header
    https.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Read analog value from the TDS sensor
    int sensorValue = analogRead(analogPin);
    float tdsValue = map(sensorValue, 0, 4095, 0, 1000); // Map the sensor value to the TDS range (0-1000 ppm)

    // Prepare your HTTP POST request data
    String httpRequestData =
                         "api_key=" + apiKeyValue +
                         "&sensor=" + sensorName  +
                         "&location=" + sensorLocation +
                         "&value1=" + String(tdsValue) + // Convert tdsValue to String and assign it to value1
                         "&value2=" + temperature + 
                         "&value3=" + String(sensorValue) + // Convert tdsValue to String and assign it to value1
                         "";

    Serial.println(httpRequestData);

    int httpResponseCode = https.POST(httpRequestData);

    if (httpResponseCode > 0) {
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
  // Send an HTTP POST request every 2 seconds
  delay(1000);
}
