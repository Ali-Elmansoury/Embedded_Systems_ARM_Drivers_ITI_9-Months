#ifndef MGPIO_H
#define MGPIO_H

#include "STD_TYPES.h"

typedef enum
{
    MGPIO_enuErrorStatus_OK,
    MGPIO_enuErrorStatus_NOK,
    MGPIO_enuErrorStatus_NULLPTR,
    MGPIO_enuErrorStatus_INVALID_PIN_CFG,
    MGPIO_enuErrorStatus_INVALID_PORT,
    MGPIO_enuErrorStatus_INVALID_PIN,
    MGPIO_enuErrorStatus_INVALID_PIN_MODE,
    MGPIO_enuErrorStatus_INVALID_PIN_OUTPUT_TYPE,
    MGPIO_enuErrorStatus_INVALID_PIN_PULL_TYPE,
    MGPIO_enuErrorStatus_INVALID_PIN_SPEED,
    MGPIO_enuErrorStatus_INVALID_PIN_ALT_FUNCTION,
    MGPIO_enuErrorStatus_INVALID_PIN_STATE
}MGPIO_enuErrorStatus_t;


typedef enum{
    MGPIO_enuPORT_A,
    MGPIO_enuPORT_B,
    MGPIO_enuPORT_C,
    MGPIO_enuPORT_D,
    MGPIO_enuPORT_E,
    MGPIO_enuPORT_H=7,
}MGPIO_enuPorts_t;

typedef enum{
    MGPIO_enuPIN_0,
    MGPIO_enuPIN_1,
    MGPIO_enuPIN_2,
    MGPIO_enuPIN_3,
    MGPIO_enuPIN_4,
    MGPIO_enuPIN_5,
    MGPIO_enuPIN_6,
    MGPIO_enuPIN_7,
    MGPIO_enuPIN_8,
    MGPIO_enuPIN_9,
    MGPIO_enuPIN_10,
    MGPIO_enuPIN_11,
    MGPIO_enuPIN_12,
    MGPIO_enuPIN_13,
    MGPIO_enuPIN_14,
    MGPIO_enuPIN_15
}MGPIO_enuPins_t;

typedef enum{
    MGPIO_enuPinMode_INPUT,
    MGPIO_enuPinMode_GENERAL_PURPOSE_OUTPUT,
    MGPIO_enuPinMode_ALTFUNCTION,
    MGPIO_enuPinMode_ANALOG
}MGPIO_enuPinMode_t;


typedef enum{
    MGPIO_enuPinOutputType_PUSH_PULL,
    MGPIO_enuPinOutputType_OPEN_DRAIN
}MGPIO_enuPinOutputType_t;

typedef enum{
    MGPIO_enuPinPullType_NO_PULL,
    MGPIO_enuPinPullType_PULL_UP,
    MGPIO_enuPinPullType_PULL_DOWN
}MGPIO_enuPinPullType_t;

typedef enum{
    MGPIO_enuPinSpeed_LOW,
    MGPIO_enuPinSpeed_MEDUIM,
    MGPIO_enuPinSpeed_HIGH,
    MGPIO_enuPinSpeed_VERY_HIGH
}MGPIO_enuPinSpeed_t;

typedef enum{
    MGPIO_enuPinAltFunction_AF0_SYSTEM,    
    MGPIO_enuPinAltFunction_AF1_TIM_1_TIM2,
    MGPIO_enuPinAltFunction_AF2_TIM_3__5,
    MGPIO_enuPinAltFunction_AF3_TIM_9__11,
    MGPIO_enuPinAltFunction_AF4_I2C_1__3,
    MGPIO_enuPinAltFunction_AF5_SPI_1__4,
    MGPIO_enuPinAltFunction_AF6_SPI_3,
    MGPIO_enuPinAltFunction_AF7_USART_1__2,
    MGPIO_enuPinAltFunction_AF8_USART_6,
    MGPIO_enuPinAltFunction_AF9_I2C_2__3,
    MGPIO_enuPinAltFunction_AF10_OTG_FS,
    MGPIO_enuPinAltFunction_AF11,
    MGPIO_enuPinAltFunction_AF12_SDIO,
    MGPIO_enuPinAltFunction_AF13,
    MGPIO_enuPinAltFunction_AF14,
    MGPIO_enuPinAltFunction_AF15_EVENTOUT
}MGPIO_enuPinAltFunction_t;

typedef enum {
  MGPIO_enuPinState_LOW,
  MGPIO_enuPinState_HIGH
}MGPIO_enuPinState_t;

typedef struct
{
    MGPIO_enuPorts_t MGPIO_Port;
    MGPIO_enuPins_t MGPIO_Pin;
    MGPIO_enuPinMode_t MGPIO_Mode;
    MGPIO_enuPinOutputType_t MGPIO_OutputType;
    MGPIO_enuPinPullType_t MGPIO_PinPullType;
    MGPIO_enuPinSpeed_t MGPIO_PinSpeed;
    MGPIO_enuPinAltFunction_t MGPIO_PinAltFunction;
} MGPIO_strPinCfg_t;

MGPIO_enuErrorStatus_t MGPIO_enuConfigPin(MGPIO_strPinCfg_t* Addr_PinCfg);
MGPIO_enuErrorStatus_t MGPIO_enuSetPinState(MGPIO_enuPorts_t Copy_u32Port, MGPIO_enuPins_t Copy_u32Pin, MGPIO_enuPinState_t Copy_u32PinState);
MGPIO_enuErrorStatus_t MGPIO_enuTogglePinState(MGPIO_enuPorts_t Copy_u32Port, MGPIO_enuPins_t Copy_u32Pin);
MGPIO_enuErrorStatus_t MGPIO_enuGetPinState(MGPIO_enuPorts_t Copy_u32Port, MGPIO_enuPins_t Copy_u32Pin, uint32_t* Addr_PinState);

#endif // MGPIO_H