#include "support.h"

const char * ssid = APSSID;
const char * password = APPSK;

void apSetup() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println(F("Configuring access point."));
    WiFi.mode(WIFI_AP_STA);
#ifdef ESP32
    WiFi.setSleep(false);
#else
    WiFi.setSleepMode(WIFI_NONE_SLEEP);
#endif
    WiFi.softAP(ssid, password);
    const char * myIP = WiFi.softAPIP().toString().c_str();

    Serial.print(F("SSID:    "));
    Serial.println(ssid);

    Serial.print(F("PWD:     "));
    Serial.println(password);

    Serial.print(F("IP:      "));
    Serial.println(myIP);
}

void doUpdate() {
    String clients = "Clients: ";
    String clientDispl = clients + WiFi.softAPgetStationNum();
    Serial.println(clientDispl);

#ifdef ESP32
    if (toggle) {
        toggle = false;
        u8x8.clearDisplay();
        u8x8.drawString(0, 0, clientDispl.c_str());
    } else {
        toggle = true;
        u8x8.clearDisplay();
        u8x8.drawString(0, 0, "SSID:");
        u8x8.drawString(6, 0, ssid);
        u8x8.drawString(0, 1, "PWD:");
        u8x8.drawString(6, 1, password);   
    }
#endif
}

void setSerial() {
    _delay(3000); // Delay to allow monitor to start
    Serial.begin(BAUD);
    Serial.setDebugOutput(true);
    Serial.flush();
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.setPrefix(printTimestamp);
    Log.notice(F("Serial logging started at %l." CR), BAUD);
}

void printTimestamp(Print *_logOutput) {
    char c[12];
    sprintf(c, "%10lu ", millis());
    _logOutput->print(c);
}

void _delay(unsigned long ulDelay) {
    // Safe semi-blocking delay
#ifdef ESP32
    vTaskDelay(ulDelay); // Builtin to ESP32
#elif defined ESP8266
    unsigned long ulNow = millis();
    unsigned long ulThen = ulNow + ulDelay;
    while (ulThen > millis()) {
        yield(); // ESP8266 needs to yield()
    }
#endif
}
