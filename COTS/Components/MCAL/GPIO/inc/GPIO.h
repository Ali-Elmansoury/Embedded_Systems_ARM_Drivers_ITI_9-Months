#ifndef GPIO_H
#define GPIO_H

#include "STD_TYPES.h"

typedef enum
{
    GPIO_enu_OK,
    GPIO_enu_NOK,
    GPIO_enu_NULLPTR
}GPIO_enuErrorStatus_t;


typedef enum{
    GPIO_enuPORT_A,
    GPIO_enuPORT_B,
    GPIO_enuPORT_C,
    GPIO_enuPORT_D,
    GPIO_enuPORT_E,
    GPIO_enuPORT_H=7,
}GPIO_enuPorts_t;

typedef enum{
    GPIO_enuPIN_0,
    GPIO_enuPIN_1,
    GPIO_enuPIN_2,
    GPIO_enuPIN_3,
    GPIO_enuPIN_4,
    GPIO_enuPIN_5,
    GPIO_enuPIN_6,
    GPIO_enuPIN_7,
    GPIO_enuPIN_8,
    GPIO_enuPIN_9,
    GPIO_enuPIN_10,
    GPIO_enuPIN_11,
    GPIO_enuPIN_12,
    GPIO_enuPIN_13,
    GPIO_enuPIN_14,
    GPIO_enuPIN_15
}GPIO_enuPins_t;

typedef enum{
    GPIO_enuPinMode_INPUT,
    GPIO_enuPinMode_OUTPUT,
    GPIO_enuPinMode_ALTERFUNCTION,
    GPIO_enuPinMode_ANALOG
}GPIO_enuPinMode_t;


typedef enum{
    GPIO_enuPinOutputType_PUSH_PULL,
    GPIO_enuPinOutputType_OPEN_DRAIN
}GPIO_enuPinOutputType_t;

#endif // GPIO_H