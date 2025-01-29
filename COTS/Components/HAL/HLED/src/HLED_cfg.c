#include "HLED_cfg.h"
#include "HLED.h"
#include "MGPIO.h"

HLED_strLedCfg_t HLED_strLedCfg[HLED_NUM_OF_LEDS] = {
    [HLED_LED_START] = {
        .HLED_enuPort = MGPIO_enuPORT_A,
        .HLED_enuPin = MGPIO_enuPIN_0,
        .HLED_enuPinType = MGPIO_enuPinOutputType_PUSH_PULL,
        .HLED_enuLedConnection = HLED_enuLED_SOURCE
    },
    [HLED_LED_STOP] = {
        .HLED_enuPort = MGPIO_enuPORT_A,
        .HLED_enuPin = MGPIO_enuPIN_1,
        .HLED_enuPinType = MGPIO_enuPinOutputType_PUSH_PULL,
        .HLED_enuLedConnection = HLED_enuLED_SOURCE
    },
    [HLED_LED_ALERT] = {
        .HLED_enuPort = MGPIO_enuPORT_A,
        .HLED_enuPin = MGPIO_enuPIN_2,
        .HLED_enuPinType = MGPIO_enuPinOutputType_PUSH_PULL,
        .HLED_enuLedConnection = HLED_enuLED_SOURCE
    }
};