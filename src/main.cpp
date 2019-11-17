#include "main.h"

void setup() {
    setSerial();    // Starts serial and ArduinoLog
    apSetup();
#ifdef ESP32
    u8x8.begin();
    u8x8.setFont(u8x8_font_victoriabold8_r); // u8x8_font_victoriabold8_n
#endif
}

void loop() {
    // Declarations for main program
    // ...
    while (true) { // Loop for program
        doUpdate();
#ifdef ESP8266
        MDNS.update();
        yield();
#endif
        _delay(LOOP * 1000);
    }
}
