/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-rfid-nfc
 */

#include <SPI.h>
#include <MFRC522.h>
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "WifiHelper.hh"
#include "NFCHelper.hh"

#define LED 2
#define SS_PIN  21  // ESP32 pin GIOP5 
#define RST_PIN 27 // ESP32 pin GIOP27 

WifiHelper wifiHelper("Luke", "obstgarten");
NFCHelper nfcHelper(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  nfcHelper.setup();
  wifiHelper.connectToWifi();

  Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");
}

void loop() {
  
  if(nfcHelper.checkForCard()!="-1")
  {
      // Light signal
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);

      wifiHelper.sendToWebsite("http://git.prodoxon.com/index.php", "id="+nfcHelper.getTagID());            
  }
}