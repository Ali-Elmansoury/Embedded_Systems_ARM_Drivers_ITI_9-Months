#include "MNVIC.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define MMNVIC_BASE_ADDRESS (0xE000E100)

#define MSCB_AIRCR_ADDRESS (0xE000ED0C)

typedef struct
{
    volatile uint32_t MNVIC_ISER[8];
    uint32_t MNVIC_reserved0[24];
    volatile uint32_t MNVIC_ICER[8];
    uint32_t MNVIC_reserved1[24];
    volatile uint32_t MNVIC_ISPR[8];
    uint32_t MNVIC_reserved2[24];
    volatile uint32_t MNVIC_ICPR[8];
    uint32_t MNVIC_reserved3[24];
    volatile uint32_t MNVIC_IABR[8];
    uint32_t MNVIC_reserved4[56];
    volatile uint8_t MNVIC_IPR[240];
    uint32_t MNVIC_reserved5[644];
    volatile uint32_t MNVIC_STIR;
} MMNVIC_strReg_t;

volatile MMNVIC_strReg_t *MNVIC_Reg = ((volatile MMNVIC_strReg_t *)MMNVIC_BASE_ADDRESS);

#define MSCB_AIRCR_REG (*(volatile uint32_t *)MSCB_AIRCR_ADDRESS)

MNVIC_enuErrorStatus_t MNVIC_enuEnableIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else
    {
        uint32_t regIndex = Copy_u32IRQn / 32;    // Determine the ISER register index
        uint32_t bitPosition = Copy_u32IRQn % 32; // Determine the bit position within the register

        // Set the corresponding bit in the ISER register
        MNVIC_Reg->MNVIC_ISER[regIndex] |= (1UL << bitPosition);
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuDisableIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else
    {
        uint32_t regIndex = Copy_u32IRQn / 32;
        uint32_t bitPosition = Copy_u32IRQn % 32;
        MNVIC_Reg->MNVIC_ICER[regIndex] |= (1UL << bitPosition);
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuSetPendingIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else
    {
        uint32_t regIndex = Copy_u32IRQn / 32;
        uint32_t bitPosition = Copy_u32IRQn % 32;
        MNVIC_Reg->MNVIC_ISPR[regIndex] |= (1UL << bitPosition);
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuClearPendingIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else
    {
        uint32_t regIndex = Copy_u32IRQn / 32;
        uint32_t bitPosition = Copy_u32IRQn % 32;
        MNVIC_Reg->MNVIC_ICPR[regIndex] |= (1UL << bitPosition);
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuGetPendingIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t *Addr_u32PendingIRQ)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else if (Addr_u32PendingIRQ == NULL)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_NULL_POINTER;
    }
    else
    {
        uint32_t regIndex = Copy_u32IRQn / 32;
        uint32_t bitPosition = Copy_u32IRQn % 32;
        *Addr_u32PendingIRQ = GET_BIT(MNVIC_Reg->MNVIC_ICPR[regIndex], bitPosition);
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuSetPriority(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t priority)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    // Check if the priority value is within the valid range (0-15 for 4-bit priority)
    else if (priority > 0xF)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_PRIORITY;
    }
    else
    {
        uint8_t shiftedPriority = (uint8_t)((priority << 4) & 0xF0); // Clear lower 4 bits

        MNVIC_Reg->MNVIC_IPR[Copy_u32IRQn] = shiftedPriority;
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuGetPriority(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t *Addr_u32Priority)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else if (Addr_u32Priority == NULL)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_NULL_POINTER;
    }
    else
    {
        *Addr_u32Priority = GET_HIGH_NIB(MNVIC_Reg->MNVIC_IPR[Copy_u32IRQn]);
        if (*Addr_u32Priority > 0xF)
        {
            Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_PRIORITY;
        }
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityGrouping(uint32_t priority_grouping)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (priority_grouping > PRIGROUP_MAX_VALUE)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_PRIORITY_GROUPING;
    }
    else
    {
        uint32_t tempReg = (AIRCR_VECTKEY | (priority_grouping << PRIGROUP_SHIFT));
        MSCB_AIRCR_REG = tempReg;
    }
    return Loc_enuErrorStatus;
}

MNVIC_enuErrorStatus_t MNVIC_enuGetActive(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t *Addr_u32Active)
{
    MNVIC_enuErrorStatus_t Loc_enuErrorStatus = MNVIC_enuErrorStatus_OK;
    if (Copy_u32IRQn > NVIC_MAX_IRQN)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_INVALID_IRQn;
    }
    else if (Addr_u32Active == NULL)
    {
        Loc_enuErrorStatus = MNVIC_enuErrorStatus_NULL_POINTER;
    }
    else
    {
        uint32_t regIndex = Copy_u32IRQn / 32;
        uint32_t bitPosition = Copy_u32IRQn % 32;
        *Addr_u32Active = GET_BIT(MNVIC_Reg->MNVIC_IABR[regIndex], bitPosition);
    }
    return Loc_enuErrorStatus;
}

void MNVIC_vSystemReset(void)
{
    uint32_t tempReg = 0;
    tempReg = (SYS_RESET_REQ_MASK | AIRCR_VECTKEY);
    MSCB_AIRCR_REG = tempReg;
}