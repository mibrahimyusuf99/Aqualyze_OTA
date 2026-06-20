#include "arduino_secrets.h"
/*
 ============================================================
 PROGRAM: Firmware V2 - OTA Update
 FILE   : Aqualyze_ota_v2.ino
 ENTITAS: ESP32 DevKit 38-pin
 THING  : Aqualyze_OTA_Node
 DEVICE : Aqualyze_0.1
 VERSI  : 2.0.0
 UPLOAD : OTA melalui WiFi dari Arduino Cloud
 ============================================================
*/
#include "thingProperties.h"

#define LED_PIN 2

const char* FIRMWARE_VERSION = "2.0.0";

unsigned long lastCounterMillis = 0;
const unsigned long counterInterval = 5000; // 5 detik

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  firmwareVersionCloud = FIRMWARE_VERSION;
  deviceStatus = "V2 Online - OTA OK";
  Serial.println("Firmware V2 - boot selesai setelah OTA");
}

void loop() {
  ArduinoCloud.update();
  updateCounterV2();
}

void updateCounterV2() {
  if (millis() - lastCounterMillis >= counterInterval) {
    otaCounter++;
    lastCounterMillis = millis();
    deviceStatus = "V2 Online - tick " + String(otaCounter);
    blinkHeartbeat();
    Serial.print("V2 tick: ");
    Serial.println(otaCounter);
  }
}

void blinkHeartbeat() {
  digitalWrite(LED_PIN, HIGH);
  delay(80);
  digitalWrite(LED_PIN, LOW);
}

void onLedStateChange() {
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}

void onDeviceStatusChange() {
  // kosong, deviceStatus cuma di-set dari firmware
}

void onFirmwareVersionCloudChange() {
  // kosong, firmwareVersionCloud cuma di-set dari firmware
}

void onOtaCounterChange() {
  // kosong, otaCounter cuma di-set dari firmware
}