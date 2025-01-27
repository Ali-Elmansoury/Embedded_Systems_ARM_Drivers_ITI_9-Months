#ifndef MRCC_H_
#define MRCC_H_

#include "STD_TYPES.h"

#define MRCC_CLK_HSI_ON_MASK         0x00000000
#define MRCC_CLK_HSI_RDY_MASK        0x00000002

#define MRCC_CLK_HSE_ON_MASK         0x00010000
#define MRCC_CLK_HSE_RDY_MASK        0x00020000

#define MRCC_CLK_PLL_ON_MASK         0x01000000
#define MRCC_CLK_PLL_RDY_MASK        0x02000000

#define MRCC_CR_HSI_ON               0
#define MRCC_CR_HSI_RDY              1

#define MRCC_CR_HSE_ON               16
#define MRCC_CR_HSE_RDY              17

#define MRCC_CR_PLL_ON               24
#define MRCC_CR_PLL_RDY              25

#define MRCC_HSI_TIMEOUT             500
#define MRCC_HSE_TIMEOUT             100000
#define MRCC_PLL_TIMEOUT             5000

#define MRCC_CFGR_SW_MASK            0xFFFFFFFC
#define MRCC_CFGR_SWS_MASK           0x00000003

#define MRCC_CFGR_SWS                2
#define MRCC_CFGR_SW                 2

#define MRCC_NOT_READY               0
#define MRCC_READY                   1

#define MAX_PLL_CLK_INDEX           1

#define MRCC_PLLCFGR_PLLSRC_MASK     0x00400000

#define MRCC_PLL_Q_MASK              0xF0FFFFFF
#define MRCC_PLL_M_MASK              0xFFFFFFC0
#define MRCC_PLL_N_MASK              0xFFFF803F
#define MRCC_PLL_P_MASK              0xFFFCFFFF

#define MRCC_PLLCFGR_Q               24
#define MRCC_PLLCFGR_N               6
#define MRCC_PLLCFGR_P               16

#define MRCC_PLLCFGR_Q_LOWER_VAL     2
#define MRCC_PLLCFGR_Q_HIGHER_VAL    15

#define MRCC_PLLCFGR_M_LOWER_VAL     2
#define MRCC_PLLCFGR_M_HIGHER_VAL    63

#define MRCC_PLLCFGR_N_LOWER_VAL     50
#define MRCC_PLLCFGR_N_HIGHER_VAL    432

#define MRCC_PLL_P_2_MASK            0
#define MRCC_PLL_P_4_MASK            1
#define MRCC_PLL_P_6_MASK            2
#define MRCC_PLL_P_8_MASK            3

// Macros for VCO frequency validation
#define MRCC_PLL_VCO_MIN 1000000  // 1 MHz
#define MRCC_PLL_VCO_MAX 2000000  // 2 MHz
#define MRCC_PLL_VCO_OUTPUT_MIN 192000000 // 192 MHz
#define MRCC_PLL_VCO_OUTPUT_MAX 432000000 // 432 MHz
#define MRCC_PLL_OUTPUT_MAX  84000000 // 84 MHz
#define MRCC_PLL_USB_OTG_OUTPUT_MAX  48000000 // 48 MHz


#define MRCC_HSI_CLK_CFG 16000000 // 16 MHz
#define MRCC_HSE_CLK_CFG 8000000  // 8 MHz


// Bus numbers
#define MRCC_BUS_AHB1 0
#define MRCC_BUS_AHB2 1
#define MRCC_BUS_APB1 2
#define MRCC_BUS_APB2 3

// Peripheral definitions
#define MRCC_PERIPH_GPIOA    ((uint64_t)(0)  | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_GPIOB    ((uint64_t)(1)  | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_GPIOC    ((uint64_t)(2)  | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_GPIOD    ((uint64_t)(3)  | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_GPIOE    ((uint64_t)(4)  | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_GPIOH    ((uint64_t)(7)  | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_CRC      ((uint64_t)(12) | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_DMA1     ((uint64_t)(21) | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_DMA2     ((uint64_t)(22) | ((uint64_t)MRCC_BUS_AHB1 << 32))
#define MRCC_PERIPH_OTGFS    ((uint64_t)(7)  | ((uint64_t)MRCC_BUS_AHB2 << 32))
#define MRCC_PERIPH_RNG      ((uint64_t)(6)  | ((uint64_t)MRCC_BUS_AHB2 << 32))
#define MRCC_PERIPH_TIM2     ((uint64_t)(0)  | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_TIM3     ((uint64_t)(1)  | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_TIM4     ((uint64_t)(2)  | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_TIM5     ((uint64_t)(3)  | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_WWDG     ((uint64_t)(11) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_SPI2     ((uint64_t)(14) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_SPI3     ((uint64_t)(15) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_USART2   ((uint64_t)(17) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_I2C1     ((uint64_t)(21) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_I2C2     ((uint64_t)(22) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_I2C3     ((uint64_t)(23) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_PWR      ((uint64_t)(28) | ((uint64_t)MRCC_BUS_APB1 << 32))
#define MRCC_PERIPH_TIM1     ((uint64_t)(0)  | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_USART1   ((uint64_t)(4)  | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_USART6   ((uint64_t)(5)  | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_ADC1     ((uint64_t)(8)  | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_SDIO     ((uint64_t)(11) | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_SPI1     ((uint64_t)(12) | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_SPI4     ((uint64_t)(13) | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_SYSCFG   ((uint64_t)(14) | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_TIM9     ((uint64_t)(16) | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_TIM10    ((uint64_t)(17) | ((uint64_t)MRCC_BUS_APB2 << 32))
#define MRCC_PERIPH_TIM11    ((uint64_t)(18) | ((uint64_t)MRCC_BUS_APB2 << 32))

#define MRCC_PERIPH_BIT(periph) ((uint32_t)(periph & 0xFFFFFFFF)) 
#define MRCC_PERIPH_BUS(periph) ((uint32_t)((periph >> 32) & 0xFFFFFFFF)) 

typedef enum {
    MRCC_enuError_NOK,
    MRCC_enuError_OK,
    MRCC_enuError_INVALID_CLK_TYPE,
    MRCC_enuError_CLK_READY,
    MRCC_enuError_CLK_NOT_READY,
    MRCC_enuError_NULL_POINTER,
    MRCC_enuError_ClkIsAlreadySet,
    MRCC_enuError_PLL_ON,
    MRCC_enuError_INVALID_PLL_Q_CFG,
    MRCC_enuError_INVALID_PLL_M_CFG,
    MRCC_enuError_INVALID_PLL_N_CFG,
    MRCC_enuError_INVALID_PLL_P_CFG,
    MRCC_enuError_INVALID_PERIPHERAL,
    MRCC_enuError_INVALID_VCO_INPUT_FREQ,
    MRCC_enuError_INVALID_VCO_OUTPUT_FREQ,
    MRCC_enuError_INVALID_PLL_OUTPUT_FREQ,
    MRCC_enuError_INVALID_USB_OTG_OUTPUT_FREQ
} MRCC_enuErrorStatus_t;

typedef enum {
    MRCC_enuClk_HSI,
    MRCC_enuClk_HSE,
    MRCC_enuClk_PLL
} MRCC_enuClk_t;

typedef struct
{
    uint8_t PLL_Q;
    uint8_t PLL_P;
    uint8_t PLL_M;
    uint16_t PLL_N;
    MRCC_enuClk_t PLL_CLK;
} MRCC_strPLLCfg_t;

MRCC_enuErrorStatus_t MRCC_enuEnableClk(MRCC_enuClk_t Copy_enuClk);
MRCC_enuErrorStatus_t MRCC_enuDisableClk(MRCC_enuClk_t Copy_enuClk);
MRCC_enuErrorStatus_t MRCC_enuSelectSysClk(MRCC_enuClk_t Copy_enuClk);
MRCC_enuErrorStatus_t MRCC_enuGetClkStatus(MRCC_enuClk_t Copy_enuClk, uint32_t* Addr_status);
MRCC_enuClk_t MRCC_enuGetSysClk(void);
MRCC_enuErrorStatus_t MRCC_enuSetPLLCfg(MRCC_strPLLCfg_t* Addr_PLLCfg);
MRCC_enuErrorStatus_t MRCC_enuEnablePeripheralClk(uint64_t Copy_peripheral);
MRCC_enuErrorStatus_t MRCC_enuDisablePeripheralClk(uint64_t Copy_peripheral);
void MRCC_vPLL40MHz_Init(void);
void MRCC_vPLL84MHz_Init(void);

#endif //MRCC_H_