#ifndef _MAIN_H
#define _MAIN_H

#include "support.h"

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

void setup();
void loop();

#endif // _MAIN_H
