#include "WifiHelper.hh" 

WifiHelper::WifiHelper(char* _ssid, char* _password)
{
    ssid = _ssid;
    password = _password;
}


void WifiHelper::connectToWifi()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    //Serial.print("Connecting to "); Serial.println("ssid");
    
    uint8_t i = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        //Serial.print('.');
        delay(500);
    
        /*if ((++i % 16) == 0)
        {
        Serial.println(F(" still trying to connect"));
        }*/
    }
    
    //Serial.print(F("Connected. My IP address is: "));
    //Serial.println(WiFi.localIP());
    myIPis = WiFi.localIP().toString();
}

void WifiHelper::sendToWebsite(String url, String postData)
{
    // Send to website
    if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(client, url);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    // Data to send with HTTP POST
    String httpRequestData = postData;           
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);

    // If you need an HTTP request with a content type: application/json, use the following:
    //http.addHeader("Content-Type", "application/json");
    //int httpResponseCode = http.POST("{\"id\":\"Test \"}" );
    // + '  \",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");

    // If you need an HTTP request with a content type: text/plain
    //http.addHeader("Content-Type", "text/plain");
    //int httpResponseCode = http.POST("Hello, World!");

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
        
    // Free resources
    http.end();
    client.stop();
    }
    else {
    //Serial.println("WiFi Disconnected");
    }
}