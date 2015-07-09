//****************************************************************
//*  Name    : Bluetooth Room Thermometer Demo                   *
//*  Author  : Robert Joseph Korn                                *
//*  Notice  : Copyright (c) 2015 Open Valley Consulting Corp    *
//*          : All Rights Reserved                               *
//*  Date    : 7/9/15                                            *
//*  Version : 1.0                                               *
//*  Notes   : Works with onewire library                        *
//*          : Used with app inventor on Android                 *
//*          :                                                   *
//****************************************************************

#include <OneWire.h>
#include <DallasTemperature.h>

int X = 0;
char buf[4] = "";
double T;

OneWire  oneWire(5); 
DallasTemperature sensors(&oneWire);
DeviceAddress tempSensor;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  sensors.setResolution(tempSensor, 12);
  sensors.setWaitForConversion(false);
}

void loop() {
    sensors.requestTemperatures(); 
    if (sensors.isConversionAvailable(0))
  {
   T = sensors.getTempCByIndex(0);
   X = map(T, -30, 40, 0, 300);
   sprintf(buf, "%04d",X);
   Serial.println(buf);
  }
   delay(2500);
}

