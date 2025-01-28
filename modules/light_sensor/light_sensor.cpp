//=====[Libraries]=============================================================

#include "mbed.h"

#include "entry.h"
#include "light_sensor.h"


//=====[Declaration of private defines]========================================

#define LDR_NUMBER_OF_AVG_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

AnalogIn LDR(A2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]===========

float LDR_reading = 0.0;
float LDR_readings[LDR_NUMBER_OF_AVG_SAMPLES];
float LDRReadingAvg = 0.0;

//=====[Declarations (prototypes) of private functions]========================

void lightSensorUpdate();

//=====[Implementations of public functions]===================================

void lightSensorInit(){
    int x;

    for( x=0; x<LDR_NUMBER_OF_AVG_SAMPLES; x++){
        LDR_readings[x] = 0;
    }
}


float lightSensorRead(){
    lightSensorUpdate();
    return LDRReadingAvg;

}
//=====[Implementations of private functions]==================================

void lightSensorUpdate(){
    static int LDRSampleIndex = 0;
    float LDRReadingsSum;
    int x;

    LDR_readings[LDRSampleIndex] = LDR.read();
       LDRSampleIndex++;
    if ( LDRSampleIndex >= LDR_NUMBER_OF_AVG_SAMPLES) {
        LDRSampleIndex = 0;
    }
    
   LDRReadingsSum = 0.0;
    for (x = 0; x < LDR_NUMBER_OF_AVG_SAMPLES; x++) {
        LDRReadingsSum = LDRReadingsSum + LDR_readings[x];
    }
    LDRReadingAvg = LDRReadingsSum / LDR_NUMBER_OF_AVG_SAMPLES;

}