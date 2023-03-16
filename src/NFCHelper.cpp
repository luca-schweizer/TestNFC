#include "NFCHelper.hh"

NFCHelper::NFCHelper(int _ss_pin, int _rst_pin)
{
    ss_pin = _ss_pin;
    rst_pin = _rst_pin;
    rfid = MFRC522(ss_pin, rst_pin);
}

// should be called during setup()
void NFCHelper::setup()
{    
    SPI.begin(); // init SPI bus
    rfid.PCD_Init(); // init MFRC522
}


String NFCHelper::checkForCard()
{
    if (rfid.PICC_IsNewCardPresent()) 
    { // new tag is available
        uidtext = "";
        if (rfid.PICC_ReadCardSerial()) { // NUID has been reader
        
            MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
            Serial.print("RFID/NFC Tag Type: ");
            Serial.println(rfid.PICC_GetTypeName(piccType));

            // print UID in Serial Monitor in the hex format
            Serial.print("UID:");
            for (int i = 0; i < rfid.uid.size; i++) {
                uidtext += String(rfid.uid.uidByte[i], HEX);
            }

            rfid.PICC_HaltA(); // halt PICC
            rfid.PCD_StopCrypto1(); // stop encryption on PCD

            return uidtext;
        }
        return "-1";
        
    }
    else
        return "-1";

}