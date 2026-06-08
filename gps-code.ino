#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// GPS setup
TinyGPSPlus gps;
SoftwareSerial gpsSerial(4, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Startup message
  display.setCursor(0, 0);
  display.println("GPS Initializing...");
  display.display();
  delay(2000);
}

void loop() {

  // Read GPS data
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c);
    Serial.print(c); // optional debug
  }

  // Update display every loop
  display.clearDisplay();
  display.setCursor(0, 0);

  if (gps.location.isValid()) {
    display.print("Lat: ");
    display.println(gps.location.lat(), 6);

    display.print("Lng: ");
    display.println(gps.location.lng(), 6);
  } else {
    display.println("Waiting for GPS...");
    display.println("Go outside!");
  }

  display.display();

  delay(1000); // refresh every second
}