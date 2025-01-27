#include "MRCC.h"
#include "STD_TYPES.h"

#define MRCC_BASE_ADDRESS (0x40023800)

#define MPWR_BASE_ADDRESS    (0x40007000UL)
#define MFLASH_BASE_ADDRESS  (0x40023C00UL)

typedef struct {
    volatile uint32_t PWR_CR;
    volatile uint32_t PWR_CSR;
}MPWR_structReg_t;

typedef struct {
    volatile uint32_t FLASH_ACR;
    volatile uint32_t FLASH_KEYR;
    volatile uint32_t FLASH_SR;
    volatile uint32_t FLASH_CR;
    volatile uint32_t FLASH_OPTCR; 
}MFLASH_structReg_t;

volatile MPWR_structReg_t* PWR_REG = ((volatile MPWR_structReg_t*)MPWR_BASE_ADDRESS);

volatile MFLASH_structReg_t* FLASH_REG = ((volatile MFLASH_structReg_t*)MFLASH_BASE_ADDRESS);


typedef struct
{
    volatile uint32_t MRCC_CR;
    volatile uint32_t MRCC_PLLCFGR;
    volatile uint32_t MRCC_CFGR;
    volatile uint32_t MRCC_CIR;
    volatile uint32_t MRCC_AHB1RSTR;
    volatile uint32_t MRCC_AHB2RSTR;
    volatile const uint32_t Reserved[2];
    volatile uint32_t MRCC_APB1RSTR;
    volatile uint32_t MRCC_APB2RSTR;
    volatile const uint32_t Reserved1[2];
    volatile uint32_t MRCC_AHB1ENR;
    volatile uint32_t MRCC_AHB2ENR;
    volatile const uint32_t Reserved2[2];
    volatile uint32_t MRCC_APB1ENR;
    volatile uint32_t MRCC_APB2ENR;
    volatile const uint32_t Reserved3[2];
    volatile uint32_t MRCC_AHB1LPENR;
    volatile uint32_t MRCC_AHB2LPENR;
    volatile const uint32_t Reserved4[2];
    volatile uint32_t MRCC_APB1LPENR;
    volatile uint32_t MRCC_APB2LPENR;
    volatile const uint32_t Reserved5[2];
    volatile uint32_t MRCC_BDCR;
    volatile uint32_t MRCC_CSR;
    volatile const uint32_t Reserved6[2];
    volatile uint32_t MRCC_SSCGR;
    volatile uint32_t MRCC_PLLI2SCFGR;
    volatile const uint32_t Reserved7;
    volatile uint32_t MRCC_DCKCFGR;

} MRCC_strReg_t;

MRCC_strReg_t *MRCC = (MRCC_strReg_t *)MRCC_BASE_ADDRESS;

// Array of peripherals
const uint64_t MRCC_Peripherals[] = {
    MRCC_PERIPH_GPIOA,
    MRCC_PERIPH_GPIOB,
    MRCC_PERIPH_GPIOC,
    MRCC_PERIPH_GPIOD,
    MRCC_PERIPH_GPIOE,
    MRCC_PERIPH_GPIOH,
    MRCC_PERIPH_CRC,
    MRCC_PERIPH_DMA1,
    MRCC_PERIPH_DMA2,
    MRCC_PERIPH_OTGFS,
    MRCC_PERIPH_RNG,
    MRCC_PERIPH_TIM2,
    MRCC_PERIPH_TIM3,
    MRCC_PERIPH_TIM4,
    MRCC_PERIPH_TIM5,
    MRCC_PERIPH_WWDG,
    MRCC_PERIPH_SPI2,
    MRCC_PERIPH_SPI3,
    MRCC_PERIPH_USART2,
    MRCC_PERIPH_I2C1,
    MRCC_PERIPH_I2C2,
    MRCC_PERIPH_I2C3,
    MRCC_PERIPH_PWR,
    MRCC_PERIPH_TIM1,
    MRCC_PERIPH_USART1,
    MRCC_PERIPH_USART6,
    MRCC_PERIPH_ADC1,
    MRCC_PERIPH_SDIO,
    MRCC_PERIPH_SPI1,
    MRCC_PERIPH_SPI4,
    MRCC_PERIPH_SYSCFG,
    MRCC_PERIPH_TIM9,
    MRCC_PERIPH_TIM10,
    MRCC_PERIPH_TIM11
};

// Number of peripherals in the array
#define MRCC_NUM_PERIPHERALS (sizeof(MRCC_Peripherals) / sizeof(MRCC_Peripherals[0]))

MRCC_enuErrorStatus_t MRCC_enuEnableClk(MRCC_enuClk_t Copy_enuClk)
{
    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuError_OK;
    uint32_t Loc_u32Timeout = 0;
    uint8_t Loc_u8State=0;
    switch (Copy_enuClk)
    {
    case MRCC_enuClk_HSI:
        MRCC->MRCC_CR |= MRCC_CLK_HSI_ON_MASK;
        Loc_u32Timeout = MRCC_HSI_TIMEOUT;
        Loc_u8State = ((MRCC->MRCC_CR & MRCC_CLK_HSI_RDY_MASK) >> MRCC_CR_HSI_RDY);
        while ((!Loc_u8State) && (Loc_u32Timeout--))
        {
            Loc_u8State = ((MRCC->MRCC_CR & MRCC_CLK_HSI_RDY_MASK) >> MRCC_CR_HSI_RDY);
        }
        break;

    case MRCC_enuClk_HSE:
        MRCC->MRCC_CR |= MRCC_CLK_HSE_ON_MASK;
        Loc_u32Timeout = MRCC_HSE_TIMEOUT;
        Loc_u8State = ((MRCC->MRCC_CR & MRCC_CLK_HSE_RDY_MASK) >> MRCC_CR_HSE_RDY);
        while ((!Loc_u8State) && (Loc_u32Timeout--))
        {
            Loc_u8State = ((MRCC->MRCC_CR & MRCC_CLK_HSE_RDY_MASK) >> MRCC_CR_HSE_RDY);
        }
        break;

    case MRCC_enuClk_PLL:
        MRCC->MRCC_CR |= MRCC_CLK_PLL_ON_MASK;
        Loc_u32Timeout = MRCC_PLL_TIMEOUT;
        Loc_u8State = ((MRCC->MRCC_CR & MRCC_CLK_PLL_RDY_MASK) >> MRCC_CR_PLL_RDY);
        while ((!Loc_u8State) && (Loc_u32Timeout--))
        {
            Loc_u8State = ((MRCC->MRCC_CR & MRCC_CLK_PLL_RDY_MASK) >> MRCC_CR_PLL_RDY);
        }
        break;

    default:
        Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
        break;
    }
    if (!Loc_u8State)
    {
        Loc_enuErrorStatus = MRCC_enuError_CLK_NOT_READY;
    }
    return Loc_enuErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_enuDisableClk(MRCC_enuClk_t Copy_enuClk)
{
    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuError_OK;
    switch (Copy_enuClk)
    {
    case MRCC_enuClk_HSI:
        MRCC->MRCC_CR &= (~MRCC_CLK_HSI_ON_MASK);
        break;

    case MRCC_enuClk_HSE:
        MRCC->MRCC_CR &= (~MRCC_CLK_HSE_ON_MASK);
        break;

    case MRCC_enuClk_PLL:
        MRCC->MRCC_CR &= (~MRCC_CLK_PLL_ON_MASK);
        break;

    default:
        Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
        break;
    }
    return Loc_enuErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_enuGetClkStatus(MRCC_enuClk_t Copy_enuClk, uint32_t *Addr_status)
{
    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuError_OK;
    if (Addr_status == NULL)
    {
        Loc_enuErrorStatus = MRCC_enuError_NULL_POINTER;
    }
    else
    {
        switch (Copy_enuClk)
        {
        case MRCC_enuClk_HSI:
            *Addr_status = ((MRCC->MRCC_CR & MRCC_CLK_HSI_RDY_MASK) >> MRCC_CR_HSI_RDY);
            break;

        case MRCC_enuClk_HSE:
            *Addr_status = ((MRCC->MRCC_CR & MRCC_CLK_HSE_RDY_MASK) >> MRCC_CR_HSE_RDY);
            break;

        case MRCC_enuClk_PLL:
            *Addr_status = ((MRCC->MRCC_CR & MRCC_CLK_PLL_RDY_MASK) >> MRCC_CR_PLL_RDY);
            break;

        default:
            Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
            break;
        }
    }
    return Loc_enuErrorStatus;
}

MRCC_enuClk_t MRCC_enuGetSysClk(void)
{
    return ((MRCC->MRCC_CFGR & MRCC_CFGR_SWS) >> MRCC_CFGR_SW);
}

MRCC_enuErrorStatus_t MRCC_enuSelectSysClk(MRCC_enuClk_t Copy_enuClk)
{
    uint32_t Loc_u32Temp = 0;
    uint32_t Loc_u32ClkStatus = 0; // check for dtype
    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuGetClkStatus(Copy_enuClk, &Loc_u32ClkStatus);
    if (MRCC_enuGetSysClk() == Copy_enuClk)
    {
        Loc_enuErrorStatus = MRCC_enuError_ClkIsAlreadySet;
    }
    else if (Loc_enuErrorStatus != MRCC_enuError_OK) // check
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Loc_u32ClkStatus == MRCC_NOT_READY)
    {
        Loc_enuErrorStatus = MRCC_enuError_CLK_NOT_READY;
    }
    else
    {
        Loc_u32Temp = ((MRCC->MRCC_CFGR & MRCC_CFGR_SW_MASK) | Copy_enuClk);
        MRCC->MRCC_CFGR = Loc_u32Temp;
    }
    return Loc_enuErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_enuSetPLLCfg(MRCC_strPLLCfg_t* Addr_PLLCfg)
{
    uint32_t Loc_u32PLLClkStatus;
    uint32_t Loc_u32SysClkStatus_PLLCfg;
    uint32_t Loc_u32VCOInputFreq = 0;
    uint32_t Loc_u32VCOOutputFreq = 0;
    uint32_t Loc_u32PLLOutputFreq = 0;
    uint32_t Loc_u32USB_OTG_Freq = 0;

    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuError_OK;
    MRCC_enuErrorStatus_t Loc_enuPLLClkErrorStatus = MRCC_enuGetClkStatus(MRCC_enuClk_PLL, &Loc_u32PLLClkStatus);
    MRCC_enuErrorStatus_t Loc_enuSysClkErrorStatus_PLLCfg = MRCC_enuGetClkStatus(Addr_PLLCfg->PLL_CLK, &Loc_u32SysClkStatus_PLLCfg);

    // Existing checks
    if (Loc_enuPLLClkErrorStatus != MRCC_enuError_OK)
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Loc_enuSysClkErrorStatus_PLLCfg != MRCC_enuError_OK)
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Loc_u32PLLClkStatus == MRCC_READY)
    {
        Loc_enuErrorStatus = MRCC_enuError_CLK_READY;
    }
    else if (Loc_u32PLLClkStatus)
    {
        Loc_enuErrorStatus = MRCC_enuError_PLL_ON;
    }
    else if (Loc_u32SysClkStatus_PLLCfg != MRCC_enuError_OK)
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_CLK_TYPE;
    }
    else if (Addr_PLLCfg->PLL_Q < MRCC_PLLCFGR_Q_LOWER_VAL || Addr_PLLCfg->PLL_Q > MRCC_PLLCFGR_Q_HIGHER_VAL)
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_PLL_Q_CFG;
    }
    else if (Addr_PLLCfg->PLL_M < MRCC_PLLCFGR_M_LOWER_VAL || Addr_PLLCfg->PLL_M > MRCC_PLLCFGR_M_HIGHER_VAL)
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_PLL_M_CFG;
    }
    else if (Addr_PLLCfg->PLL_N < MRCC_PLLCFGR_N_LOWER_VAL || Addr_PLLCfg->PLL_N > MRCC_PLLCFGR_N_HIGHER_VAL)
    {
        Loc_enuErrorStatus = MRCC_enuError_INVALID_PLL_N_CFG;
    }
    else
    {
        // Calculate VCO Input Frequency
        if (Addr_PLLCfg->PLL_CLK == MRCC_enuClk_HSE)
        {
            Loc_u32VCOInputFreq = MRCC_HSE_CLK_CFG / Addr_PLLCfg->PLL_M;
        }
        else if (Addr_PLLCfg->PLL_CLK == MRCC_enuClk_HSI)
        {
            Loc_u32VCOInputFreq = MRCC_HSI_CLK_CFG / Addr_PLLCfg->PLL_M;
        }

        // Check VCO Input Frequency Range
        if (Loc_u32VCOInputFreq < MRCC_PLL_VCO_MIN || Loc_u32VCOInputFreq > MRCC_PLL_VCO_MAX)
        {
            Loc_enuErrorStatus = MRCC_enuError_INVALID_VCO_INPUT_FREQ;
        }

        // Calculate VCO Output Frequency
        Loc_u32VCOOutputFreq = Loc_u32VCOInputFreq * Addr_PLLCfg->PLL_N;

        // Check VCO Output Frequency Range
        if (Loc_u32VCOOutputFreq < MRCC_PLL_VCO_OUTPUT_MIN || Loc_u32VCOOutputFreq > MRCC_PLL_VCO_OUTPUT_MAX)
        {
            Loc_enuErrorStatus = MRCC_enuError_INVALID_VCO_OUTPUT_FREQ;
        }

        // NEW: Validate PLL Output Clock
        const int PLLP_VALUES[] = {2, 4, 6, 8};  // Lookup table for PLLP divisors
        uint32_t pll_divisor = PLLP_VALUES[Addr_PLLCfg->PLL_P]; // Get divisor based on macro (0-3)
        Loc_u32PLLOutputFreq = Loc_u32VCOOutputFreq / pll_divisor;

        if (Loc_u32PLLOutputFreq > MRCC_PLL_OUTPUT_MAX)
        {
            Loc_enuErrorStatus = MRCC_enuError_INVALID_PLL_OUTPUT_FREQ;
        }

        // Calculate USB OTG FS, SDIO, and RNG Frequency
        Loc_u32USB_OTG_Freq = Loc_u32VCOOutputFreq / Addr_PLLCfg->PLL_Q;

        // Check Frequency Range for USB OTG FS, SDIO, and RNG
        if (Loc_u32USB_OTG_Freq != MRCC_PLL_USB_OTG_OUTPUT_MAX) // 48 MHz required for USB OTG FS
        {
            Loc_enuErrorStatus = MRCC_enuError_INVALID_USB_OTG_OUTPUT_FREQ;
        }

        if (Addr_PLLCfg->PLL_CLK == MRCC_enuClk_HSE)
        {
            MRCC->MRCC_PLLCFGR |= MRCC_PLLCFGR_PLLSRC_MASK;
        }
        else if (Addr_PLLCfg->PLL_CLK == MRCC_enuClk_HSI)
        {
            MRCC->MRCC_PLLCFGR &= (~MRCC_PLLCFGR_PLLSRC_MASK);
        }

        switch (Addr_PLLCfg->PLL_P)
        {
            case MRCC_PLL_P_2_MASK:
                MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_P_MASK) | (MRCC_PLL_P_2_MASK << MRCC_PLLCFGR_P));
                break;

            case MRCC_PLL_P_4_MASK:
                MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_P_MASK) | (MRCC_PLL_P_4_MASK << MRCC_PLLCFGR_P));
                break;

            case MRCC_PLL_P_6_MASK:
                MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_P_MASK) | (MRCC_PLL_P_6_MASK << MRCC_PLLCFGR_P));
                break;

            case MRCC_PLL_P_8_MASK:
                MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_P_MASK) | (MRCC_PLL_P_8_MASK << MRCC_PLLCFGR_P));
                break;

            default:
                Loc_enuErrorStatus = MRCC_enuError_INVALID_PLL_P_CFG;
                break;
        }

        MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_N_MASK) | (Addr_PLLCfg->PLL_N << MRCC_PLLCFGR_N));
        MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_Q_MASK) | (Addr_PLLCfg->PLL_Q << MRCC_PLLCFGR_Q));
        MRCC->MRCC_PLLCFGR = ((MRCC->MRCC_PLLCFGR & MRCC_PLL_M_MASK) | (Addr_PLLCfg->PLL_M));
    }

    return Loc_enuErrorStatus;
}

static bool MRCC_IsValidPeripheral(uint64_t peripheral) {
    int low = 0;
    int high = MRCC_NUM_PERIPHERALS - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (MRCC_Peripherals[mid] == peripheral) {
            return TRUE; 
        } else if (MRCC_Peripherals[mid] < peripheral) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return FALSE; 
}

MRCC_enuErrorStatus_t MRCC_enuEnablePeripheralClk(uint64_t Copy_peripheral)
{
    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuError_OK;
    if (MRCC_IsValidPeripheral(Copy_peripheral))
    {
        uint32_t Loc_u32BusNo = MRCC_PERIPH_BUS(Copy_peripheral);
        uint32_t Loc_u32BitNo = MRCC_PERIPH_BIT(Copy_peripheral);
        switch (Loc_u32BusNo)
        {
        case MRCC_BUS_AHB1:
            MRCC->MRCC_AHB1ENR |= (1 << Loc_u32BitNo);
            break;

        case MRCC_BUS_AHB2:
            MRCC->MRCC_AHB2ENR |= (1 << Loc_u32BitNo);
            break;

        case MRCC_BUS_APB1:
            MRCC->MRCC_APB1ENR |= (1 << Loc_u32BitNo);
            break;

        case MRCC_BUS_APB2:
            MRCC->MRCC_APB2ENR |= (1 << Loc_u32BitNo);
            break;
        
        default:
            Loc_enuErrorStatus = MRCC_enuError_INVALID_PERIPHERAL;
            break;
        }
    }
    else
    {
        /*Do Nothing*/
    }
    return Loc_enuErrorStatus;
}

MRCC_enuErrorStatus_t MRCC_enuDisablePeripheralClk(uint64_t Copy_peripheral)
{
    MRCC_enuErrorStatus_t Loc_enuErrorStatus = MRCC_enuError_OK;
    if (MRCC_IsValidPeripheral(Copy_peripheral))
    {
        uint32_t Loc_u32BusNo = MRCC_PERIPH_BUS(Copy_peripheral);
        uint32_t Loc_u32BitNo = MRCC_PERIPH_BIT(Copy_peripheral);
        switch (Loc_u32BusNo)
        {
        case MRCC_BUS_AHB1:
            MRCC->MRCC_AHB1ENR &= ~(1 << Loc_u32BitNo);
            break;

        case MRCC_BUS_AHB2:
            MRCC->MRCC_AHB2ENR &= ~(1 << Loc_u32BitNo);
            break;

        case MRCC_BUS_APB1:
            MRCC->MRCC_APB1ENR &= ~(1 << Loc_u32BitNo);
            break;

        case MRCC_BUS_APB2:
            MRCC->MRCC_APB2ENR &= ~(1 << Loc_u32BitNo);
            break;
        
        default:
            Loc_enuErrorStatus = MRCC_enuError_INVALID_PERIPHERAL;
            break;
        }
    }
    else
    {
        /*Do Nothing*/
    }
    return Loc_enuErrorStatus;
}

static void ConfigrationsFor84MHzPLL(void){
    PWR_REG->PWR_CR&=~(0xC000);    // clear pin 14 & 15  
    PWR_REG->PWR_CR|=(0x8000);     // set pin 15
    FLASH_REG->FLASH_ACR&=~(0xF);  // clear FLASH_ACR_LATENCY_Pos bits
    FLASH_REG->FLASH_ACR|=0x2;     // Set 2 wait states for 84MHz FLASH_ACR_LATENCY_Pos
    FLASH_REG->FLASH_ACR|=0x100;   // Enable prefetch buffer FLASH_ACR_PRFTEN
    FLASH_REG->FLASH_ACR|=0x200;   // Enable instruction cache FLASH_ACR_ICEN
    FLASH_REG->FLASH_ACR|=0x400;   // Enable data cache FLASH_ACR_DCEN
}

void MRCC_vPLL40MHz_Init(void)
{
    MRCC_strPLLCfg_t Loc_PLLcfg = {
        .PLL_CLK = MRCC_enuClk_HSI,
        .PLL_M = 16,
        .PLL_N = 320,
        .PLL_P = MRCC_PLL_P_8_MASK,
        .PLL_Q = 15};

    // Variables to store function return statuses
    MRCC_enuErrorStatus_t Loc_enuDisableClkStatus;
    MRCC_enuErrorStatus_t Loc_enuSetPLLCfgStatus;
    MRCC_enuErrorStatus_t Loc_enuEnableClkStatus;
    MRCC_enuErrorStatus_t Loc_enuSelectSysClkStatus;

    // Disable PLL clock
    Loc_enuDisableClkStatus = MRCC_enuDisableClk(MRCC_enuClk_PLL);

    // Configure PLL
    Loc_enuSetPLLCfgStatus = MRCC_enuSetPLLCfg(&Loc_PLLcfg);

    // Enable PLL clock
    Loc_enuEnableClkStatus = MRCC_enuEnableClk(MRCC_enuClk_PLL);

    // Select PLL as system clock
    Loc_enuSelectSysClkStatus = MRCC_enuSelectSysClk(MRCC_enuClk_PLL);

}

void MRCC_vPLL84MHz_Init(void)
{
    MRCC_strPLLCfg_t Loc_PLLcfg = {
        .PLL_CLK = MRCC_enuClk_HSI,
        .PLL_M = 16,
        .PLL_N = 336,
        .PLL_P = MRCC_PLL_P_4_MASK,
        .PLL_Q = 15};

    // Variables to store function return statuses
    MRCC_enuErrorStatus_t Loc_enuDisableClkStatus;
    MRCC_enuErrorStatus_t Loc_enuSetPLLCfgStatus;
    MRCC_enuErrorStatus_t Loc_enuEnableClkStatus;
    MRCC_enuErrorStatus_t Loc_enuSelectSysClkStatus;
    MRCC_enuErrorStatus_t Loc_enuEnablePeripheralClk;

    // Disable PLL clock
    Loc_enuDisableClkStatus = MRCC_enuDisableClk(MRCC_enuClk_PLL);

    //Enable PWR peripheral
    Loc_enuEnablePeripheralClk = MRCC_enuEnablePeripheralClk(MRCC_PERIPH_PWR);

    //PWR & Flash configs for PLL
    ConfigrationsFor84MHzPLL();

    // Configure PLL
    Loc_enuSetPLLCfgStatus = MRCC_enuSetPLLCfg(&Loc_PLLcfg);

    // Enable PLL clock
    Loc_enuEnableClkStatus = MRCC_enuEnableClk(MRCC_enuClk_PLL);

    // Select PLL as system clock
    Loc_enuSelectSysClkStatus = MRCC_enuSelectSysClk(MRCC_enuClk_PLL);
}