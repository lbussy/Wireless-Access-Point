# Wireless Access Point

This is a small wireless access point written for the ESP32 or ESP8266.  I created this using the [Heltec Wifi Kit 32](https://heltec.org/project/wifi-kit-32/) (actually a Chinese knock-off from Aliexpress) which is an ESP32 equipped with a 0.96″ OLED display.  When used on this device the display will alternate between the SSID/Password and the number of clients connected.

This has also been tested on the Wemos D1 Mini without the OLED.  In this case, one may use the Serial debug to see the number of connected clients.

This Wireless Access Point (WAP) will only emulate a WAP and not do any routing.  I needed this for testing IoT devices and testing workflows which included connecting to a WAP.  I could have driven to Microcenter and purchased a small 2.4Ghz WAP in the time it took me to figure out the display, but that's why we roll our own, right?

The WAP SSID and Password may be set in `support.h`:

```
#define APSSID "ESP_AP"
#define APPSK "nospoon!"
```

This project has been created and configured for PlatformIO.  I highly recommend this IDE, however, if you use something else like the Arduino IDE you will have to hack your way through it.  Doing so, at a minimum you would have to install the [U8g2 library](https://github.com/olikraus/u8g2) which handles the OLED work.
