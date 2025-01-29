#ifndef HLED_H
#define HLED_H

#include "STD_TYPES.h"

typedef enum {
  HLED_enuLED_OFF,
  HLED_enuLED_ON
}HLED_enuLedState_t;

typedef enum
{
    HLED_enuErrorStatus_OK,
    HLED_enuErrorStatus_NOK,
    HLED_enuErrorStatus_NULLPTR,
    HLED_enuErrorStatus_INVALID_PIN_CFG,
    HLED_enuErrorStatus_INVALID_PORT,
    HLED_enuErrorStatus_INVALID_PIN,
    HLED_enuErrorStatus_INVALID_PIN_MODE,
    HLED_enuErrorStatus_INVALID_PIN_OUTPUT_TYPE,
    HLED_enuErrorStatus_INVALID_PIN_PULL_TYPE,
    HLED_enuErrorStatus_INVALID_PIN_SPEED,
    HLED_enuErrorStatus_INVALID_PIN_ALT_FUNCTION,
    HLED_enuErrorStatus_INVALID_PIN_STATE,
    HLED_enuError_INVALID_NUM_OF_LEDS,
    HLED_enuError_INVALID_LED_STATE,
    HLED_enuError_INVALID_LED_CONNECTION
}HLED_enuErrorStatus_t;

typedef enum {
    HLED_enuLED_SOURCE,
    HLED_enuLED_SINK
}HLED_enuLedConnection_t;

HLED_enuErrorStatus_t HLED_vInit(void);
HLED_enuErrorStatus_t HLED_enuSetLedState(uint8_t Copy_u8LedName, uint8_t Copy_u8State);
HLED_enuErrorStatus_t HLED_enuToggleLedState(uint8_t Copy_u8LedName);


#endif // HLED_H