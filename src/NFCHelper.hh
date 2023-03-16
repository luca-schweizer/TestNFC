// NFCHelper.h
#ifndef NFCHELPER_H // include guard
#define NFCHELPER_H

#include <MFRC522.h>
#include <string.h>

class NFCHelper
{
    private:
        int ss_pin;
        int rst_pin;
        MFRC522 rfid;
        String uidtext;
    public:
        NFCHelper(int _ss_pin, int _rst_pin);
        void setup();
        String checkForCard();
        String getTagID() {return uidtext; };

};


#endif /* NFCHELPER_H */