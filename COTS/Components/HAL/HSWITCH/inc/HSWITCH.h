#ifndef SWITCH_H
#define SWITCH_H

#include "STD_TYPES.h"

typedef enum
{
  HSWITCH_enuSwitch_NOT_PRESSED,
  HSWITCH_enuSwitch_PRESSED
} HSWITCH_enuSwitchState_t;

typedef enum
{
  HSWITCH_enuErrorStatus_OK,
  HSWITCH_enuErrorStatus_NOK,
  HSWITCH_enuErrorStatus_NULLPTR,
  HSWITCH_enuErrorStatus_INVALID_PIN_CFG,
  HSWITCH_enuErrorStatus_INVALID_PORT,
  HSWITCH_enuErrorStatus_INVALID_PIN,
  HSWITCH_enuErrorStatus_INVALID_PIN_MODE,
  HSWITCH_enuErrorStatus_INVALID_PIN_OUTPUT_TYPE,
  HSWITCH_enuErrorStatus_INVALID_PIN_PULL_TYPE,
  HSWITCH_enuErrorStatus_INVALID_PIN_SPEED,
  HSWITCH_enuErrorStatus_INVALID_PIN_ALT_FUNCTION,
  HSWITCH_enuErrorStatus_INVALID_PIN_STATE,
  HSWITCH_enuError_INVALID_NUM_OF_SWITCHS,
  HSWITCH_enuError_INVALID_SWITCH_CONNECTION
} HSWITCH_enuErrorStatus_t;

typedef enum
{
  HSWITCH_enuSwitch_NO_PULL,
  HSWITCH_enuSwitch_INTERNAL_PULL_UP,
  HSWITCH_enuSwitch_INTERNAL_PULL_DOWN,
} HSWITCH_enuSwitchConnection_t;

typedef enum
{
  HSWITCH_enuSwitchDebounce_OFF,
  HSWITCH_enuSwitchDebounce_ON
} HSWITCH_enuSwitchDebounce_t;

HSWITCH_enuErrorStatus_t HSWITCH_vInit(void);
HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(uint8_t Copy_u8SwitchName, uint32_t *Add_u8State);

#endif // SWITCH_H