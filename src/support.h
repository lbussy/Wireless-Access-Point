#ifndef _SUPPORT_H
#define _SUPPORT_H

#ifdef ESP32
#include <U8x8lib.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#elif defined ESP8266
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#endif

#include <ArduinoLog.h>
#include <Arduino.h>

#ifndef APCONFIG
#define APCONFIG
#define APSSID "ESP_AP"
#define APPSK "nospoon!"
#define LOOP 5
#endif

#ifdef ESP32
namespace {
    U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/15, /* data=*/4, /* reset=*/16);
    bool toggle = false;
}
#endif 

void setSerial();
void apSetup();
void doUpdate();
void printTimestamp(Print*);
void _delay(unsigned long);

#endif // _SUPPORT_H
