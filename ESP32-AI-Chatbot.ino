#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>  // Include ArduinoJson library

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* ollamaUrl = "YOUR_OLLAMA_URL";
const char* modelName = "YOUR_MODEL_NAME";

const String context = "You are talking to a virtual assistant designed to help";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // This removes any whitespace characters including '\r'

    if (input.equalsIgnoreCase("exit")) {
      Serial.println("Exiting...");
      return; // Stop the loop
    }

    String response = askQuestion(input);
    Serial.println("Assistant: " + response);
  }
  delay(100);
}

String askQuestion(String question) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(client, ollamaUrl);
    http.addHeader("Content-Type", "application/json");

    String requestBody = createRequestBody(question);
    int httpResponseCode = http.POST(requestBody);

    if (httpResponseCode > 0) {
      String response = http.getString(); // Get the full JSON response as a string
      http.end();

      // Parse JSON response to extract only the assistant's message
      DynamicJsonDocument doc(1024); // Adjust the size based on your expected response size
      deserializeJson(doc, response);
      const char* content = doc["message"]["content"]; // Navigate to the "content" field in "message"

      return String(content); // Return only the content of the assistant's message
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
      http.end();
      return "Failed to get a response due to a network error.";
    }
  } else {
    return "WiFi not connected.";
  }
}

String createRequestBody(String question) {
  String json = "{";
  json += "\"model\": \"" + String(modelName) + "\",";
  json += "\"messages\": [{\"role\": \"system\", \"content\": \"" + context + "\"}, {\"role\": \"user\", \"content\": \"" + question + "\"}],";
  json += "\"stream\": false";
  json += "}";
  return json;
}