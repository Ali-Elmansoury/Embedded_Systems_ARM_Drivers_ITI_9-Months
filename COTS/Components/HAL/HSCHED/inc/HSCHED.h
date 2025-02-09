#ifndef HSCHED_H
#define HSCHED_H

#include "STD_TYPES.h"
#include "HSCHED_cfg.h"

typedef enum {
    HSCHED_enuErrorStatus_NOK,
    HSCHED_enuErrorStatus_OK,
    HSCHED_enuErrorStatus_NULL_POINTER,
    HSCHED_enuErrorStatus_LOCATION_OCCUPIED_INVALID_PRIORITY
}HSCHED_enuErrorStatus_t;

void HSCHED_vSchedInit();
HSCHED_enuErrorStatus_t HSCHED_enuSchedRegisterRunnable(HSCHED_strRunnableCfg_t *Addr_strRunnableCfg);
void HSCHED_vSchedStart();
void HSCHED_vSchedStop();

#endif //HSCHED_H