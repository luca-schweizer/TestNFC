// WifiHelper.hh
#ifndef WIFIHELPER_H // include guard
#define WIFIHELPER_H

#include <WiFi.h>
#include <HTTPClient.h>
#include <string.h>

class WifiHelper
{
    private:
        char* ssid;
        char* password;
        String myIPis;
    public:
        WifiHelper(char* _ssid, char* _password);
        void connectToWifi();
        void sendToWebsite(String url, String postData);
};


#endif /* WIFIHELPER_H */