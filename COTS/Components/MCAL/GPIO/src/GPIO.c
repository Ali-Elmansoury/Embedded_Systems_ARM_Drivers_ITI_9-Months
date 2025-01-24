#include "GPIO.h"

#define GPIOA_BASE_ADDRESS (0x40020000UL)
#define GPIOB_BASE_ADDRESS (0x40020400UL)
#define GPIOC_BASE_ADDRESS (0x40020800UL)
#define GPIOD_BASE_ADDRESS (0x40020C00UL)
#define GPIOE_BASE_ADDRESS (0x40021000UL)
#define GPIOH_BASE_ADDRESS (0x40021C00UL)

volatile GPIO_structREGS_t* GPIOA_REG = ((volatile GPIO_structREGS_t*)GPIOA_BASE_ADDRESS);
 
volatile GPIO_structREGS_t* GPIOB_REG = ((volatile GPIO_structREGS_t*)GPIOB_BASE_ADDRESS);

volatile GPIO_structREGS_t* GPIOC_REG = ((volatile GPIO_structREGS_t*)GPIOC_BASE_ADDRESS);

volatile GPIO_structREGS_t* GPIOD_REG = ((volatile GPIO_structREGS_t*)GPIOD_BASE_ADDRESS);

volatile GPIO_structREGS_t* GPIOE_REG = ((volatile GPIO_structREGS_t*)GPIOE_BASE_ADDRESS);

volatile GPIO_structREGS_t* GPIOH_REG = ((volatile GPIO_structREGS_t*)GPIOH_BASE_ADDRESS);

typedef struct {
    volatile uint32_t GPIO_MODER;
    volatile uint32_t GPIO_OTYPER;
    volatile uint32_t GPIO_OSPEEDR;
    volatile uint32_t GPIO_PUPDR;
    volatile uint32_t GPIO_IDR;
    volatile uint32_t GPIO_ODR;
    volatile uint32_t GPIO_BSRR;
    volatile uint32_t GPIO_LCKR;
    volatile uint32_t GPIO_AFRL;
    volatile uint32_t GPIO_AFRH;
}GPIO_structREGS_t;

typedef struct {
    GPIO_enuPorts_t GPIO_Port;
    GPIO_enuPins_t GPIO_Pin;
    GPIO_enuPinMode_t GPIO_Mode;
    GPIO_enuPinOutputType_t GPIO_OutputType;
}GPIO_strPinCfg_t;