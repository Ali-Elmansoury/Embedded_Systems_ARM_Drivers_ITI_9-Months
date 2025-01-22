#ifndef RCC_H_
#define RCC_H_

#include "STD_TYPES.h"

#define RCC_CLK_HSI_ON_MASK         0x00000000
#define RCC_CLK_HSI_RDY_MASK        0x00000001

#define RCC_CLK_HSE_ON_MASK         0x00010000
#define RCC_CLK_HSE_RDY_MASK        0x00020000

#define RCC_CLK_PLL_ON_MASK         0x01000000
#define RCC_CLK_PLL_RDY_MASK        0x02000000

#define RCC_CR_HSI_ON               0
#define RCC_CR_HSI_RDY              1

#define RCC_CR_HSE_ON               16
#define RCC_CR_HSE_RDY              17

#define RCC_CR_PLL_ON               24
#define RCC_CR_PLL_RDY              25

#define RCC_HSI_TIMEOUT             500
#define RCC_HSE_TIMEOUT             100000
#define RCC_PLL_TIMEOUT             5000

#define RCC_CFGR_SW_MASK            0xFFFFFFFC
#define RCC_CFGR_SWS_MASK           0x00000003

#define RCC_CFGR_SWS                2
#define RCC_CFGR_SW                 2

#define RCC_NOT_READY               0
#define RCC_READY                   1

#define MAX_PLL_CLK_INDEX           1

#define RCC_PLLCFGR_PLLSRC_MASK     0x00400000

#define RCC_PLL_Q_MASK              0xF0FFFFFF
#define RCC_PLL_M_MASK              0xFFFFFFC0
#define RCC_PLL_N_MASK              0xFFFF803F
#define RCC_PLL_P_MASK              0xFFFCFFFF

#define RCC_PLLCFGR_Q               24
#define RCC_PLLCFGR_N               6
#define RCC_PLLCFGR_P               16

#define RCC_PLLCFGR_Q_LOWER_VAL     2
#define RCC_PLLCFGR_Q_HIGHER_VAL    15

#define RCC_PLLCFGR_M_LOWER_VAL     2
#define RCC_PLLCFGR_M_HIGHER_VAL    63

#define RCC_PLLCFGR_N_LOWER_VAL     192
#define RCC_PLLCFGR_N_HIGHER_VAL    432

#define RCC_PLL_P_2_MASK            0
#define RCC_PLL_P_4_MASK            1
#define RCC_PLL_P_6_MASK            2
#define RCC_PLL_P_8_MASK            3

// Bus numbers
#define RCC_BUS_AHB1 0
#define RCC_BUS_AHB2 1
#define RCC_BUS_APB1 2
#define RCC_BUS_APB2 3

// Peripheral definitions
#define RCC_PERIPH_GPIOA    ((uint64_t)(0)  | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_GPIOB    ((uint64_t)(1)  | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_GPIOC    ((uint64_t)(2)  | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_GPIOD    ((uint64_t)(3)  | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_GPIOE    ((uint64_t)(4)  | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_GPIOH    ((uint64_t)(7)  | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_CRC      ((uint64_t)(12) | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_DMA1     ((uint64_t)(21) | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_DMA2     ((uint64_t)(22) | ((uint64_t)RCC_BUS_AHB1 << 32))
#define RCC_PERIPH_OTGFS    ((uint64_t)(7)  | ((uint64_t)RCC_BUS_AHB2 << 32))
#define RCC_PERIPH_RNG      ((uint64_t)(6)  | ((uint64_t)RCC_BUS_AHB2 << 32))
#define RCC_PERIPH_TIM2     ((uint64_t)(0)  | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_TIM3     ((uint64_t)(1)  | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_TIM4     ((uint64_t)(2)  | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_TIM5     ((uint64_t)(3)  | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_WWDG     ((uint64_t)(11) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_SPI2     ((uint64_t)(14) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_SPI3     ((uint64_t)(15) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_USART2   ((uint64_t)(17) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_I2C1     ((uint64_t)(21) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_I2C2     ((uint64_t)(22) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_I2C3     ((uint64_t)(23) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_PWR      ((uint64_t)(28) | ((uint64_t)RCC_BUS_APB1 << 32))
#define RCC_PERIPH_TIM1     ((uint64_t)(0)  | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_USART1   ((uint64_t)(4)  | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_USART6   ((uint64_t)(5)  | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_ADC1     ((uint64_t)(8)  | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_SDIO     ((uint64_t)(11) | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_SPI1     ((uint64_t)(12) | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_SPI4     ((uint64_t)(13) | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_SYSCFG   ((uint64_t)(14) | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_TIM9     ((uint64_t)(16) | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_TIM10    ((uint64_t)(17) | ((uint64_t)RCC_BUS_APB2 << 32))
#define RCC_PERIPH_TIM11    ((uint64_t)(18) | ((uint64_t)RCC_BUS_APB2 << 32))

#define RCC_PERIPH_BIT(periph) ((uint32_t)(periph & 0xFFFFFFFF)) 
#define RCC_PERIPH_BUS(periph) ((uint32_t)((periph >> 32) & 0xFFFFFFFF)) 

typedef enum {
    RCC_enuError_NOK,
    RCC_enuError_OK,
    RCC_enuError_INVALID_CLK_TYPE,
    RCC_enuError_CLK_NOT_READY,
    RCC_enuError_NULL_POINTER,
    RCC_enuError_ClkIsAlreadySet,
    RCC_enuError_PLL_ON,
    RCC_enuError_INVALID_PLL_Q_CFG,
    RCC_enuError_INVALID_PLL_M_CFG,
    RCC_enuError_INVALID_PLL_N_CFG,
    RCC_enuError_INVALID_PLL_P_CFG,
    RCC_enuError_INVALID_PERIPHERAL

}RCC_enuErrorStatus_t;

typedef enum {
    RCC_enuClk_HSI,
    RCC_enuClk_HSE,
    RCC_enuClk_PLL
}RCC_enuClk_t;

typedef struct
{
    uint8_t PLL_Q;
    uint8_t PLL_P;
    uint8_t PLL_M;
    uint16_t PLL_N;
    RCC_enuClk_t PLL_CLK;
} RCC_strPLLCfg_t;

RCC_enuErrorStatus_t RCC_enuEnableClk(RCC_enuClk_t Copy_enuClk);
RCC_enuErrorStatus_t RCC_enuDisableClk(RCC_enuClk_t Copy_enuClk);
RCC_enuErrorStatus_t RCC_enuSelectSysClk(RCC_enuClk_t Copy_enuClk);
RCC_enuErrorStatus_t RCC_enuGetClkStatus(RCC_enuClk_t Copy_enuClk, uint32_t* Addr_status);
RCC_enuClk_t RCC_enuGetSysClk(void);
RCC_enuErrorStatus_t RCC_enuSetPLLCfg(RCC_strPLLCfg_t* Addr_PLLCfg);
RCC_enuErrorStatus_t RCC_enuEnablePeripheralClk(uint64_t Copy_peripheral);
RCC_enuErrorStatus_t RCC_enuDisablePeripheralClk(uint64_t Copy_peripheral);
void RCC_vInit(void);

#endif //RCC_H_