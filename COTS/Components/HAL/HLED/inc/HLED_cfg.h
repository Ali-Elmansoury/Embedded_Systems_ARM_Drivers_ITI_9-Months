#ifndef HLED_CFG_H
#define HLED_CFG_H

#include "STD_TYPES.h"
#include "HLED.h"
#include "MGPIO.h"

#define HLED_NUM_OF_LEDS 3

#define HLED_LED_START 0
#define HLED_LED_STOP 1
#define HLED_LED_ALERT 2

typedef struct {
    MGPIO_enuPorts_t HLED_enuPort;
    MGPIO_enuPins_t HLED_enuPin;
    MGPIO_enuPinOutputType_t HLED_enuPinType;
    HLED_enuLedConnection_t HLED_enuLedConnection;
}HLED_strLedCfg_t;

#endif // HLED_CFG_H