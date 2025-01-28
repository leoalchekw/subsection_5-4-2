//=====[Libraries]=============================================================

#include "entry.h"

#include "mbed.h"
#include "arm_book_lib.h"

#include "light_sensor.h"

//=====[Declaration of private defines]========================================

#define DAY_LEVEL 0.6


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut entrywayLight(LED3);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

lightState_t LightDetectorState = DAY;

//=====[Declarations (prototypes) of private functions]========================

void entryLightSwitch();

//=====[Implementations of public functions]===================================

void entryLightInit(){
    lightSensorInit();
    entrywayLight = OFF;
    
}

void entryLightUpdate(){
    entryLightSwitch();
    switch(LightDetectorState){

    case DAY:
        entrywayLight = ON;
        break;
        
    case NIGHT:
        entrywayLight = OFF;
        break;
    }
}

//=====[Implementations of private functions]==================================

void entryLightSwitch(){

    if (lightSensorRead() >= DAY_LEVEL){
        LightDetectorState = NIGHT;
    }
    else{
        LightDetectorState = DAY;
    }
}