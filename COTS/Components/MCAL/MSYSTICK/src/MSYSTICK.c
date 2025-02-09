#include "MSYSTICK.h"
#include "STD_TYPES.h"

#define MSYSTICK_BASE_ADDRESS (0xE000E010)

typedef struct
{
    volatile uint32_t MSYSTICK_STK_CTRL;
    volatile uint32_t MSYSTICK_STK_LOAD;
    volatile uint32_t MSYSTICK_STK_VAL;
    volatile uint32_t MSYSTICK_STK_CALIB;
} MSYSTICK_strReg_t;

volatile MSYSTICK_strReg_t *MSYSTICK_Reg = ((volatile MSYSTICK_strReg_t *)MSYSTICK_BASE_ADDRESS);

static MSYSTICK_cbf_t MSYSTICK_Callback = NULL;

volatile uint32_t Global_u32LoadValue = 0;
volatile uint32_t Global_u32Counter = 0;
// volatile uint32_t Global_u32Delay = 0;

void MSYSTICK_vInit()
{
    MSYSTICK_Reg->MSYSTICK_STK_CTRL |= MSYSTICK_CLKSOURCE_AHB_MASK;
    MSYSTICK_Reg->MSYSTICK_STK_VAL = 0;
    MSYSTICK_Reg->MSYSTICK_STK_CTRL |= MSYSTICK_INTEN_MASK;
    MSYSTICK_Reg->MSYSTICK_STK_LOAD = 84000;   
}

MSYSTICK_enuErrorStatus_t MSYSTICK_enuSetCyclicCbf(MSYSTICK_cbf_t Addr_voidPtr, uint32_t Copy_u32CyclicDelayMs)
{
    MSYSTICK_enuErrorStatus_t Loc_enuErrorStatus = MSYSTICK_enuErrorStatus_OK;
    if (Addr_voidPtr == NULL)
    {
        Loc_enuErrorStatus = MSYSTICK_enuErrorStatus_NULL_POINTER;
    }
    else
    {
        MSYSTICK_Callback = Addr_voidPtr;
        Global_u32LoadValue = Copy_u32CyclicDelayMs;
    }
    return Loc_enuErrorStatus;
}

MSYSTICK_enuErrorStatus_t MSYSTICK_enuDelayMs(uint32_t delayMs)
{
    MSYSTICK_enuErrorStatus_t Loc_enuErrorStatus = MSYSTICK_enuErrorStatus_OK;

    return Loc_enuErrorStatus;
}

void MSYSTICK_vStart()
{
    MSYSTICK_Reg->MSYSTICK_STK_CTRL |= MSYSTICK_EN_MASK;
}

void MSYSTICK_vStop()
{
    MSYSTICK_Reg->MSYSTICK_STK_CTRL &= ~MSYSTICK_EN_MASK;
}

void SysTick_Handler(void)
{
    Global_u32Counter++;
    if (Global_u32Counter == Global_u32LoadValue)
    {
        MSYSTICK_Callback();
        Global_u32Counter = 0;
    }
}