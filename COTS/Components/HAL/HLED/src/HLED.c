#include "HLED.h"
#include "HLED_cfg.h"
#include "MGPIO.h"
#include "STD_TYPES.h"

extern HLED_strLedCfg_t HLED_strLedCfg[HLED_NUM_OF_LEDS];

HLED_enuErrorStatus_t HLED_vInit(void)
{
    HLED_enuErrorStatus_t Loc_enuErrorStatus = HLED_enuErrorStatus_OK;
    for (uint8_t iterator = 0; iterator < HLED_NUM_OF_LEDS; iterator++)
    {
        MGPIO_strPinCfg_t Loc_strPinCfg = {
            .MGPIO_Mode = MGPIO_enuPinMode_GENERAL_PURPOSE_OUTPUT,
            .MGPIO_PinPullType = MGPIO_enuPinPullType_NO_PULL,
            .MGPIO_PinAltFunction = MGPIO_enuPinAltFunction_AF0_SYSTEM,
            .MGPIO_PinSpeed = MGPIO_enuPinSpeed_LOW,
            .MGPIO_Port = HLED_strLedCfg[iterator].HLED_enuPort,
            .MGPIO_Pin = HLED_strLedCfg[iterator].HLED_enuPin,
            .MGPIO_OutputType = HLED_strLedCfg[iterator].HLED_enuPinType
        };
        Loc_enuErrorStatus = MGPIO_enuConfigPin(&Loc_strPinCfg);
    }
    return Loc_enuErrorStatus;
}

HLED_enuErrorStatus_t HLED_enuSetLedState(uint8_t Copy_u8LedName, uint8_t Copy_u8State)
{
    HLED_enuErrorStatus_t Loc_enuErrorStatus = HLED_enuErrorStatus_OK;
    MGPIO_enuPorts_t Loc_u32portNum = HLED_strLedCfg[Copy_u8LedName].HLED_enuPort;
    MGPIO_enuPins_t Loc_u32pinNum = HLED_strLedCfg[Copy_u8LedName].HLED_enuPin;
    HLED_enuLedConnection_t Loc_ledConnection = HLED_strLedCfg[Copy_u8LedName].HLED_enuLedConnection;
    if (Copy_u8LedName > HLED_NUM_OF_LEDS)
    {
        Loc_enuErrorStatus = HLED_enuError_INVALID_NUM_OF_LEDS;
    }
    else if (Copy_u8State != HLED_enuLED_ON && Copy_u8State != HLED_enuLED_OFF)
    {
        Loc_enuErrorStatus = HLED_enuError_INVALID_LED_STATE;
    }
    else
    {
        if (Loc_ledConnection == HLED_enuLED_SOURCE && Copy_u8State == HLED_enuLED_ON)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_HIGH);
        }
        else if (Loc_ledConnection == HLED_enuLED_SOURCE && Copy_u8State == HLED_enuLED_OFF)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_LOW);
        }
        else if (Loc_ledConnection == HLED_enuLED_SINK && Copy_u8State == HLED_enuLED_ON)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_LOW);
        }
        else if (Loc_ledConnection == HLED_enuLED_SINK && Copy_u8State == HLED_enuLED_OFF)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_HIGH);
        }
        else
        {
            Loc_enuErrorStatus = HLED_enuError_INVALID_LED_CONNECTION;
        }
    }
    return Loc_enuErrorStatus;
}

HLED_enuErrorStatus_t HLED_enuToggleLedState(uint8_t Copy_u8LedName)
{
    HLED_enuErrorStatus_t Loc_enuErrorStatus = HLED_enuErrorStatus_OK;
    MGPIO_enuPorts_t Loc_u32portNum = HLED_strLedCfg[Copy_u8LedName].HLED_enuPort;
    MGPIO_enuPins_t Loc_u32pinNum = HLED_strLedCfg[Copy_u8LedName].HLED_enuPin;
    HLED_enuLedConnection_t Loc_ledConnection = HLED_strLedCfg[Copy_u8LedName].HLED_enuLedConnection;
    uint32_t Loc_u32LedState = 0;
    Loc_enuErrorStatus = MGPIO_enuGetPinState(Loc_u32portNum, Loc_u32pinNum, &Loc_u32LedState);

    if (Copy_u8LedName > HLED_NUM_OF_LEDS)
    {
        Loc_enuErrorStatus = HLED_enuError_INVALID_NUM_OF_LEDS;
    }
    else if (Loc_u32LedState != HLED_enuLED_ON && Loc_u32LedState != HLED_enuLED_OFF)
    {
        Loc_enuErrorStatus = HLED_enuError_INVALID_LED_STATE;
    }
    else
    {
        if (Loc_ledConnection == HLED_enuLED_SOURCE && Loc_u32LedState == HLED_enuLED_ON)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_LOW);
        }
        else if (Loc_ledConnection == HLED_enuLED_SOURCE && Loc_u32LedState == HLED_enuLED_OFF)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_HIGH);
        }
        else if (Loc_ledConnection == HLED_enuLED_SINK && Loc_u32LedState == HLED_enuLED_ON)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_HIGH);
        }
        else if (Loc_ledConnection == HLED_enuLED_SINK && Loc_u32LedState == HLED_enuLED_OFF)
        {
            Loc_enuErrorStatus = MGPIO_enuSetPinState(Loc_u32portNum, Loc_u32pinNum, MGPIO_enuPinState_LOW);
        }
        else
        {
            Loc_enuErrorStatus = HLED_enuError_INVALID_LED_CONNECTION;
        }
    }
    return Loc_enuErrorStatus;
}