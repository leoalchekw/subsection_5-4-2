//=====[#include guards - begin]===============================================

#ifndef _ENTRY_H_
#define _ENTRY_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
    NIGHT,
    DAY
} lightState_t;


//=====[Declarations (prototypes) of public functions]=========================

void entryLightInit();
void entryLightUpdate();

//=====[#include guards - end]=================================================

#endif // _ENTRY_H_