#include "HSCHED.h"
#include "HSCHED_cfg.h"
#include "MSYSTICK.h"

static volatile HSCHED_strRunnableCfg_t *HSCHED_arrRunnableCfg[HSCHED_MAX_RUNNABLES] = {0};

static void HSCHED_vRun()
{
    static uint32_t u32CurrentTime = 0;
    u32CurrentTime++;
    for (uint8_t i = 0; i < HSCHED_MAX_RUNNABLES; i++)
    {
        if (HSCHED_arrRunnableCfg[i] != NULL && HSCHED_arrRunnableCfg[i]->Cbf != NULL)
        {
            if (HSCHED_arrRunnableCfg[i]->u32FirstDelay == 0 && (u32CurrentTime % HSCHED_arrRunnableCfg[i]->u32Periodicity) == 0) 
            {
                HSCHED_arrRunnableCfg[i]->Cbf();
            }
            else if (HSCHED_arrRunnableCfg[i]->u32FirstDelay != 0)
            {
                HSCHED_arrRunnableCfg[i]->u32FirstDelay--;
            }
        }
    }
}

void HSCHED_vSchedInit()
{
    MSYSTICK_vInit();
    MSYSTICK_enuSetCyclicCbf(HSCHED_vRun, 1);
}

HSCHED_enuErrorStatus_t HSCHED_enuSchedRegisterRunnable(HSCHED_strRunnableCfg_t *Addr_strRunnableCfg)
{
    HSCHED_enuErrorStatus_t Loc_enuErrorStatus = HSCHED_enuErrorStatus_OK;
    if (Addr_strRunnableCfg == NULL)
    {
        Loc_enuErrorStatus = HSCHED_enuErrorStatus_NULL_POINTER;
    }
    else
    {
        if (HSCHED_arrRunnableCfg[Addr_strRunnableCfg->u8Priority] == NULL)
        {
            HSCHED_arrRunnableCfg[Addr_strRunnableCfg->u8Priority] = Addr_strRunnableCfg;
        }
        else
        {
            Loc_enuErrorStatus = HSCHED_enuErrorStatus_LOCATION_OCCUPIED_INVALID_PRIORITY;
        }
    }
    return Loc_enuErrorStatus;
}

void HSCHED_vSchedStart()
{
    MSYSTICK_vStart();
    while (1);
}

void HSCHED_vSchedStop()
{
    MSYSTICK_vStop();
}