#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FastLED.h>

#define LED_PIN     D2  // Pin connected to the LED strip
#define NUM_LEDS    60  // Number of LEDs in your strip

CRGB leds[NUM_LEDS];

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Initialize LED strip
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(50);

  // Start the web server
  server.on("/turnOn", HTTP_POST, [](){
    turnOnLEDs();
    server.send(200, "text/plain", "LED strip turned on");
  });
  server.on("/turnOff", HTTP_POST, [](){
    turnOffLEDs();
    server.send(200, "text/plain", "LED strip turned off");
  });
  server.on("/changeColor", HTTP_POST, [](){
    String color = server.arg("color");
    changeColor(color);
    server.send(200, "text/plain", "LED strip color changed to " + color);
  });
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void turnOnLEDs() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}

void turnOffLEDs() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void changeColor(String color) {
  if (color == "red") {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
  } else if (color == "green") {
    fill_solid(leds, NUM_LEDS, CRGB::Green);
  } else if (color == "blue") {
    fill_solid(leds, NUM_LEDS, CRGB::Blue);
  } else if (color == "yellow") {
    fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  } else if (color == "purple") {
    fill_solid(leds, NUM_LEDS, CRGB::Purple);
  } else if (color == "cyan") {
    fill_solid(leds, NUM_LEDS, CRGB::Cyan);
  } else if (color == "white") {
    fill_solid(leds, NUM_LEDS, CRGB::White);
  }
  FastLED.show();
}
