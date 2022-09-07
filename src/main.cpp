#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>

const char *WIFI_SSID = "<wifi_name>";
const char *WIFI_PASSWORD = "<password>";

AsyncWebServer server(80);

// Called when you click send button in browser
void callback(unsigned char* data, unsigned int length) 
{
    // Null terminator
    data[length] = '\0';
    // Send to TX
    Serial.println((char*) data);

    // Display in browser the message you sent
    WebSerial.print("> ");
    WebSerial.println((char*) data);
}

void setup()
{
    Serial.begin(115200);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println(WiFi.localIP());
    WebSerial.begin(&server);
    WebSerial.msgCallback(callback);
    server.begin();
}

void loop()
{
    // Read serial from RX
    if (Serial.available() > 0) {
        String str = Serial.readStringUntil('\n');
        WebSerial.println(str);
    }
}
