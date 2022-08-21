#ifndef IOT_SET
#define IOT_SET

#include <Arduino.h>
#include <string>

#define ALEN(a) ((int) (sizeof(a) / sizeof(a[0]))) 

extern const char *boiler[];

typedef struct { int position; const char *replacement; } replacement_t;
void get_Html(String& html, const char *[], int, replacement_t [], int);

#define getHtml(strout, boiler, repls) get_Html(strout, boiler, ALEN(boiler), repls, ALEN(repls));


// MAC address 
extern char MAC_ADDRESS[];
void getMAC(char *);

// LED utilities
void ledOn();
void ledOff();
void blink(int = 1, int = 300);

// what time did we start?
extern unsigned long firstSliceMillis;

// what time did we last run this action?
extern unsigned long lastSliceMillis;

// a control iterator for slicing up the main loop ///////////////////////////
extern int loopIteration;
extern const int LOOP_ROLLOVER; // how many loops per action sequence


// declarations for Ex06

// the wifi and HTTP server libraries ////////////////////////////////////////
#include <WiFi.h>
#include <WebServer.h>

// globals for a wifi access point and webserver /////////////////////////////
extern String apSSID;           // SSID of the AP
extern WebServer webServer;     // a simple web server

// function protos
void setup06();
void loop06();
void startAP();
void printIPs();
void startWebServer();
void handleNotFound();
void handleRoot();
void handleHello();


// declarations for Ex08

#include "WiFiClientSecure.h"

// globals and utilities for connecting to COM3505 cloud server
extern WiFiClientSecure com3505Client; // the web client library class
extern const char *com3505Addr;
extern const int   com3505Port;
extern const char* wifiSsid;
extern const char* wifiPassword;
bool cloudConnect();       // initialise com3505Client; true when connected
void cloudGet(String url); // do a GET on com3505Client
String cloudRead();        // read a line of response following a request
bool cloudAvailable();     // is there more to read from the response?
void cloudStop();          // shut connection on com3505Client


// declarations for Ex09

void setup09();
void loop09();
void initWebServer();
void hndlNotFound();
void hndlRoot();
void hndlWifi();
void hndlWifichz();
void hndlStatus();
void apListForm(String& f);
String ip2str(IPAddress address);


// declarations for Ex10

#include <HTTPClient.h> // ESP32 library for making HTTP requests
#include <Update.h>     // OTA update library

extern int firmwareVersion; // used to check for updates
int doCloudGet(HTTPClient *, String);
void handleOTAProgress(size_t done, size_t total);


// declarations for Ex11

#include <DNSServer.h>

extern DNSServer dnsServer;


// (Ex12 does't export anything)

// end of THING_H guard
#endif
