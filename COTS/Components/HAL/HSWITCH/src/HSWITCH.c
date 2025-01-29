#include "HSWITCH.h"
#include "HSWITCH_cfg.h"
#include "MGPIO.h"
#include "STD_TYPES.h"

void delayMs(uint32_t Copy_u32SysClk, uint16_t Copy_u16NumOfMs)
{
    volatile uint32_t Loc_u32LoopCount = 0UL;
    volatile uint32_t Loc_u32Cycles = (uint32_t)Copy_u32SysClk / 1000UL * (uint32_t)Copy_u16NumOfMs * 2UL / 25UL;

    for (Loc_u32LoopCount = 0UL; Loc_u32LoopCount < Loc_u32Cycles; Loc_u32LoopCount++)
    {
        __asm__ volatile("nop");
    }
}

extern HSWITCH_strSwitchCfg_t HSWITCH_strSwitchCfg[HSWITCH_NUM_OF_SWITCHS];

HSWITCH_enuErrorStatus_t HSWITCH_vInit(void)
{
    HSWITCH_enuErrorStatus_t Loc_enuErrorStatus = HSWITCH_enuErrorStatus_OK;
    for (uint8_t iterator = 0; iterator < HSWITCH_NUM_OF_SWITCHS; iterator++)
    {
        MGPIO_strPinCfg_t Loc_strPinCfg = {
            .MGPIO_Mode = MGPIO_enuPinMode_INPUT,
            .MGPIO_PinPullType = HSWITCH_strSwitchCfg[iterator].HSWITCH_enuSwitchConnection,
            .MGPIO_PinAltFunction = MGPIO_enuPinAltFunction_AF0_SYSTEM,
            .MGPIO_PinSpeed = MGPIO_enuPinSpeed_LOW,
            .MGPIO_Port = HSWITCH_strSwitchCfg[iterator].HSWITCH_enuSwitchPort,
            .MGPIO_Pin = HSWITCH_strSwitchCfg[iterator].HSWITCH_enuSwitchPin,
            .MGPIO_OutputType = MGPIO_enuPinOutputType_PUSH_PULL
        };
        Loc_enuErrorStatus = MGPIO_enuConfigPin(&Loc_strPinCfg);
    }
    return Loc_enuErrorStatus;
}

MGPIO_enuErrorStatus_t static MGPIO_enuGetSwitchStateWithDebounce(MGPIO_enuPorts_t Copy_enuPortNum, MGPIO_enuPins_t Copy_enuPinNum, uint32_t *Add_u8PinValue)
{
    MGPIO_enuErrorStatus_t Loc_enuErrorStatus = MGPIO_enuGetPinState(Copy_enuPortNum, Copy_enuPinNum, Add_u8PinValue);
    if (Loc_enuErrorStatus == HSWITCH_enuErrorStatus_NOK)
    {
        if (Add_u8PinValue != NULL)
        {
            delayMs(84000000, 20);
            Loc_enuErrorStatus = MGPIO_enuGetPinState(Copy_enuPortNum, Copy_enuPinNum, Add_u8PinValue);
        }
        else
        {
            Loc_enuErrorStatus = HSWITCH_enuSwitch_NO_PULL;
        }
    }
    return Loc_enuErrorStatus;
}

HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(uint8_t Copy_u8SwitchName, uint32_t *Add_u8State)
{
    HSWITCH_enuErrorStatus_t Loc_enuErrorStatus = HSWITCH_enuErrorStatus_NOK;
    MGPIO_enuPorts_t Loc_u32portNum = HSWITCH_strSwitchCfg[Copy_u8SwitchName].HSWITCH_enuSwitchPort;
    MGPIO_enuPins_t Loc_u32pinNum = HSWITCH_strSwitchCfg[Copy_u8SwitchName].HSWITCH_enuSwitchPin;
    HSWITCH_enuSwitchDebounce_t Loc_switchDebounce = HSWITCH_strSwitchCfg[Copy_u8SwitchName].HSWITCH_enuSwitchDebounce;
    if (Copy_u8SwitchName > HSWITCH_NUM_OF_SWITCHS)
    {
        Loc_enuErrorStatus = HSWITCH_enuError_INVALID_NUM_OF_SWITCHS;
    }
    else if (Add_u8State == NULL)
    {
        Loc_enuErrorStatus = HSWITCH_enuSwitch_NO_PULL;
    }
    else
    {
        Loc_enuErrorStatus = HSWITCH_enuErrorStatus_OK;
        if (Loc_switchDebounce == HSWITCH_enuSwitchDebounce_ON)
        {
            Loc_enuErrorStatus = MGPIO_enuGetSwitchStateWithDebounce(Loc_u32portNum, Loc_u32pinNum, Add_u8State);
        }
        else
        {
            Loc_enuErrorStatus = MGPIO_enuGetPinState(Loc_u32portNum, Loc_u32pinNum, Add_u8State);
        }
    }
    return Loc_enuErrorStatus;
}