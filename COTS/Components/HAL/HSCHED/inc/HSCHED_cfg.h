#ifndef HSCHED_CFG_H
#define HSCHED_CFG_H

#include "HSCHED.h"
#include "STD_TYPES.h"

#define HSCHED_MAX_RUNNABLES 100

typedef void (*HSCHED_cbf_t) (void);

typedef struct 
{
    uint8_t u8Priority;
    uint32_t u32Periodicity;
    HSCHED_cbf_t Cbf;
    uint32_t u32FirstDelay;
}HSCHED_strRunnableCfg_t;

#endif //HSCHED_CFG_H