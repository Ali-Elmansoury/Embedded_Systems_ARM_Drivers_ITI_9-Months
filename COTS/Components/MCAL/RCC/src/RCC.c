#include "RCC.h"
#include "STD_TYPES.h"

#define RCC_BASE_ADDRESS 0x40023800

typedef struct
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_PLLCFGR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_AHB1RSTR;
    volatile uint32_t RCC_AHB2RSTR;
    volatile const uint32_t Reserved[2];
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_APB2RSTR;
    volatile const uint32_t Reserved1[2];
    volatile uint32_t RCC_AHB1ENR;
    volatile uint32_t RCC_AHB2ENR;
    volatile const uint32_t Reserved2[2];
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_APB2ENR;
    volatile const uint32_t Reserved3[2];
    volatile uint32_t RCC_AHB1LPENR;
    volatile uint32_t RCC_AHB2LPENR;
    volatile const uint32_t Reserved4[2];
    volatile uint32_t RCC_APB1LPENR;
    volatile uint32_t RCC_APB2LPENR;
    volatile const uint32_t Reserved5[2];
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
    volatile const uint32_t Reserved6[2];
    volatile uint32_t RCC_SSCGR;
    volatile uint32_t RCC_PLLI2SCFGR;
    volatile const uint32_t Reserved7;
    volatile uint32_t RCC_DCKCFGR;

} RCC_strReg_t;

RCC_strReg_t *RCC = (RCC_strReg_t *)RCC_BASE_ADDRESS;

// Array of peripherals
const uint64_t RCC_Peripherals[] = {
    RCC_PERIPH_GPIOA,
    RCC_PERIPH_GPIOB,
    RCC_PERIPH_GPIOC,
    RCC_PERIPH_GPIOD,
    RCC_PERIPH_GPIOE,
    RCC_PERIPH_GPIOH,
    RCC_PERIPH_CRC,
    RCC_PERIPH_DMA1,
    RCC_PERIPH_DMA2,
    RCC_PERIPH_OTGFS,
    RCC_PERIPH_RNG,
    RCC_PERIPH_TIM2,
    RCC_PERIPH_TIM3,
    RCC_PERIPH_TIM4,
    RCC_PERIPH_TIM5,
    RCC_PERIPH_WWDG,
    RCC_PERIPH_SPI2,
    RCC_PERIPH_SPI3,
    RCC_PERIPH_USART2,
    RCC_PERIPH_I2C1,
    RCC_PERIPH_I2C2,
    RCC_PERIPH_I2C3,
    RCC_PERIPH_PWR,
    RCC_PERIPH_TIM1,
    RCC_PERIPH_USART1,
    RCC_PERIPH_USART6,
    RCC_PERIPH_ADC1,
    RCC_PERIPH_SDIO,
    RCC_PERIPH_SPI1,
    RCC_PERIPH_SPI4,
    RCC_PERIPH_SYSCFG,
    RCC_PERIPH_TIM9,
    RCC_PERIPH_TIM10,
    RCC_PERIPH_TIM11
};

// Number of peripherals in the array
#define RCC_NUM_PERIPHERALS (sizeof(RCC_Peripherals) / sizeof(RCC_Peripherals[0]))

RCC_enuErrorStatus_t RCC_enuEnableClk(RCC_enuClk_t Copy_enuClk)
{
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuError_OK;
    uint32_t Loc_u32Timeout = 0;
    uint8_t Loc_u8State;
    switch (Copy_enuClk)
    {
    case RCC_enuClk_HSI:
        RCC->RCC_CR |= RCC_CLK_HSI_ON_MASK;
        Loc_u32Timeout = RCC_HSI_TIMEOUT;
        Loc_u8State = ((RCC->RCC_CR & RCC_CLK_HSI_RDY_MASK) >> RCC_CR_HSI_RDY);
        while ((!Loc_u8State) && (Loc_u32Timeout--))
        {
            Loc_u8State = ((RCC->RCC_CR & RCC_CLK_HSI_RDY_MASK) >> RCC_CR_HSI_RDY);
        }
        break;

    case RCC_enuClk_HSE:
        RCC->RCC_CR |= RCC_CLK_HSE_ON_MASK;
        Loc_u32Timeout = RCC_HSE_TIMEOUT;
        Loc_u8State = ((RCC->RCC_CR & RCC_CLK_HSE_RDY_MASK) >> RCC_CR_HSE_RDY);
        while ((!Loc_u8State) && (Loc_u32Timeout--))
        {
            Loc_u8State = ((RCC->RCC_CR & RCC_CLK_HSE_RDY_MASK) >> RCC_CR_HSE_RDY);
        }
        break;

    case RCC_enuClk_PLL:
        RCC->RCC_CR |= RCC_CLK_PLL_ON_MASK;
        Loc_u32Timeout = RCC_PLL_TIMEOUT;
        Loc_u8State = ((RCC->RCC_CR & RCC_CLK_PLL_RDY_MASK) >> RCC_CR_PLL_RDY);
        while ((!Loc_u8State) && (Loc_u32Timeout--))
        {
            Loc_u8State = ((RCC->RCC_CR & RCC_CLK_PLL_RDY_MASK) >> RCC_CR_PLL_RDY);
        }
        break;

    default:
        Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
        break;
    }
    if (!Loc_u8State)
    {
        Loc_enuErrorStatus = RCC_enuError_CLK_NOT_READY;
    }
    return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisableClk(RCC_enuClk_t Copy_enuClk)
{
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuError_OK;
    switch (Copy_enuClk)
    {
    case RCC_enuClk_HSI:
        RCC->RCC_CR &= (~RCC_CLK_HSI_ON_MASK);
        break;

    case RCC_enuClk_HSE:
        RCC->RCC_CR &= (~RCC_CLK_HSE_ON_MASK);
        break;

    case RCC_enuClk_PLL:
        RCC->RCC_CR &= (~RCC_CLK_PLL_ON_MASK);
        break;

    default:
        Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
        break;
    }
    return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuGetClkStatus(RCC_enuClk_t Copy_enuClk, uint32_t *Addr_status)
{
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuError_OK;
    if (Addr_status == NULL)
    {
        Loc_enuErrorStatus = RCC_enuError_NULL_POINTER;
    }
    else
    {
        switch (Copy_enuClk)
        {
        case RCC_enuClk_HSI:
            *Addr_status = ((RCC->RCC_CR & RCC_CLK_HSI_RDY_MASK) >> RCC_CR_HSI_RDY);
            break;

        case RCC_enuClk_HSE:
            *Addr_status = ((RCC->RCC_CR & RCC_CLK_HSE_RDY_MASK) >> RCC_CR_HSE_RDY);
            break;

        case RCC_enuClk_PLL:
            *Addr_status = ((RCC->RCC_CR & RCC_CLK_PLL_RDY_MASK) >> RCC_CR_PLL_RDY);
            break;

        default:
            Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
            break;
        }
        return Loc_enuErrorStatus;
    }
}

RCC_enuClk_t RCC_enuGetSysClk(void)
{
    return ((RCC->RCC_CFGR & RCC_CFGR_SWS) >> RCC_CFGR_SW);
}

RCC_enuErrorStatus_t RCC_enuSelectSysClk(RCC_enuClk_t Copy_enuClk)
{
    uint32_t Loc_u32Temp = RCC->RCC_CFGR;
    uint32_t *Loc_u32ClkStatus; // check for dtype
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuGetClkStatus(Copy_enuClk, Loc_u32ClkStatus);
    if (RCC_enuGetSysClk() == Copy_enuClk)
    {
        Loc_enuErrorStatus = RCC_enuError_ClkIsAlreadySet;
    }
    else if (Loc_enuErrorStatus != RCC_enuError_OK) // check
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
    }
    else if (*Loc_u32ClkStatus == RCC_NOT_READY)
    {
        Loc_enuErrorStatus = RCC_enuError_CLK_NOT_READY;
    }
    else
    {
        Loc_u32Temp = ((RCC->RCC_CFGR & RCC_CFGR_SW_MASK) | Copy_enuClk);
        RCC->RCC_CFGR = Loc_u32Temp;
    }
    return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuSetPLLCfg(RCC_strPLLCfg_t* Addr_PLLCfg)
{
    uint32_t Loc_u32PLLClkStatus;
    uint32_t Loc_u32SysClkStatus_PLLCfg;
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuError_OK;
    RCC_enuErrorStatus_t Loc_enuPLLClkErrorStatus = RCC_enuGetClkStatus(RCC_enuClk_PLL, &Loc_u32PLLClkStatus);
    RCC_enuErrorStatus_t Loc_enuSysClkErrorStatus_PLLCfg = RCC_enuGetClkStatus(Addr_PLLCfg->PLL_CLK, &Loc_u32SysClkStatus_PLLCfg);
    if (Loc_enuPLLClkErrorStatus != RCC_enuError_OK) // 7nksha
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Loc_enuSysClkErrorStatus_PLLCfg != RCC_enuError_OK) // 7nksha
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Loc_u32PLLClkStatus == RCC_NOT_READY)
    {
        Loc_enuErrorStatus = RCC_enuError_CLK_NOT_READY;
    }
    else if (Loc_u32PLLClkStatus)
    {
        Loc_enuErrorStatus = RCC_enuError_PLL_ON;
    }
    else if (Loc_u32SysClkStatus_PLLCfg != RCC_enuError_OK)
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Addr_PLLCfg->PLL_CLK == RCC_enuClk_HSE)
    {
        RCC->RCC_PLLCFGR |= RCC_PLLCFGR_PLLSRC_MASK;
    }
    else if (Addr_PLLCfg->PLL_CLK == RCC_enuClk_HSI)
    {
        RCC->RCC_PLLCFGR &= (~RCC_PLLCFGR_PLLSRC_MASK);
    }
    else if (Addr_PLLCfg->PLL_Q < RCC_PLLCFGR_Q_LOWER_VAL || Addr_PLLCfg->PLL_Q > RCC_PLLCFGR_Q_HIGHER_VAL)
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_PLL_Q_CFG;
    }
    else if (Addr_PLLCfg->PLL_M < RCC_PLLCFGR_M_LOWER_VAL || Addr_PLLCfg->PLL_M > RCC_PLLCFGR_M_HIGHER_VAL)
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_PLL_M_CFG;
    }
    else if (Addr_PLLCfg->PLL_N < RCC_PLLCFGR_N_LOWER_VAL || Addr_PLLCfg->PLL_N > RCC_PLLCFGR_N_HIGHER_VAL)
    {
        Loc_enuErrorStatus = RCC_enuError_INVALID_PLL_N_CFG;
    }
    else
    {
        switch (Addr_PLLCfg->PLL_P)
        {
            case RCC_PLL_P_2_MASK:
                (RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_P_MASK) | (RCC_PLL_P_2_MASK << RCC_PLLCFGR_P)));
                break;

            case RCC_PLL_P_4_MASK:
                (RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_P_MASK) | (RCC_PLL_P_4_MASK << RCC_PLLCFGR_P)));
                break;

            case RCC_PLL_P_6_MASK:
                (RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_P_MASK) | (RCC_PLL_P_6_MASK << RCC_PLLCFGR_P)));
                break;

            case RCC_PLL_P_8_MASK:
                (RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_P_MASK) | (RCC_PLL_P_8_MASK << RCC_PLLCFGR_P)));
                break;

            default:
                Loc_enuErrorStatus = RCC_enuError_INVALID_PLL_P_CFG;
                break;
        }

        RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_N_MASK) | (Addr_PLLCfg->PLL_N << RCC_PLLCFGR_N));
        RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_Q_MASK) | (Addr_PLLCfg->PLL_Q << RCC_PLLCFGR_Q));
        RCC->RCC_PLLCFGR = ((RCC->RCC_PLLCFGR & RCC_PLL_M_MASK) | (Addr_PLLCfg->PLL_M ));
    }

    return Loc_enuErrorStatus;
}

static bool RCC_IsValidPeripheral(uint64_t peripheral) {
    int low = 0;
    int high = RCC_NUM_PERIPHERALS - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (RCC_Peripherals[mid] == peripheral) {
            return TRUE; 
        } else if (RCC_Peripherals[mid] < peripheral) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return FALSE; 
}

RCC_enuErrorStatus_t RCC_enuEnablePeripheralClk(uint64_t Copy_peripheral)
{
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuError_OK;
    if (RCC_IsValidPeripheral(Copy_peripheral))
    {
        uint32_t Loc_u32BusNo = RCC_PERIPH_BUS(Copy_peripheral);
        uint32_t Loc_u32BitNo = RCC_PERIPH_BIT(Copy_peripheral);
        switch (Loc_u32BusNo)
        {
        case RCC_BUS_AHB1:
            RCC->RCC_AHB1ENR |= (1 << Loc_u32BitNo);
            break;

        case RCC_BUS_AHB2:
            RCC->RCC_AHB2ENR |= (1 << Loc_u32BitNo);
            break;

        case RCC_BUS_APB1:
            RCC->RCC_APB1ENR |= (1 << Loc_u32BitNo);
            break;

        case RCC_BUS_APB2:
            RCC->RCC_APB2ENR |= (1 << Loc_u32BitNo);
            break;
        
        default:
            Loc_enuErrorStatus = RCC_enuError_INVALID_PERIPHERAL;
            break;
        }
    }
    else
    {
        /*Do Nothing*/
    }
    return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisablePeripheralClk(uint64_t Copy_peripheral)
{
    RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuError_OK;
    if (RCC_IsValidPeripheral(Copy_peripheral))
    {
        uint32_t Loc_u32BusNo = RCC_PERIPH_BUS(Copy_peripheral);
        uint32_t Loc_u32BitNo = RCC_PERIPH_BIT(Copy_peripheral);
        switch (Loc_u32BusNo)
        {
        case RCC_BUS_AHB1:
            RCC->RCC_AHB1ENR &= ~(1 << Loc_u32BitNo);
            break;

        case RCC_BUS_AHB2:
            RCC->RCC_AHB2ENR &= ~(1 << Loc_u32BitNo);
            break;

        case RCC_BUS_APB1:
            RCC->RCC_APB1ENR &= ~(1 << Loc_u32BitNo);
            break;

        case RCC_BUS_APB2:
            RCC->RCC_APB2ENR &= ~(1 << Loc_u32BitNo);
            break;
        
        default:
            Loc_enuErrorStatus = RCC_enuError_INVALID_PERIPHERAL;
            break;
        }
    }
    else
    {
        /*Do Nothing*/
    }
    return Loc_enuErrorStatus;
}

void RCC_vInit(void);