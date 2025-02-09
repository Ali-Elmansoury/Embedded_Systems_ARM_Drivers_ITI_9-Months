#ifndef MMNVIC_H
#define MMNVIC_H

#include "STD_TYPES.h"

#define NVIC_MAX_IRQN                   240

#define SYS_RESET_REQ_MASK              (0x02)
#define AIRCR_VECTKEY                   (0x5FA << 16) // Key required to write to AIRCR

#define PRIGROUP_SHIFT                   8            // PRIGROUP field starts at bit 8
#define PRIGROUP_MAX_VALUE               7

typedef enum{
    MNVIC_enuErrorStatus_NOK,
    MNVIC_enuErrorStatus_OK,
    MNVIC_enuErrorStatus_NULL_POINTER,
    MNVIC_enuErrorStatus_INVALID_PRIORITY,
    MNVIC_enuErrorStatus_INVALID_IRQn,
    MNVIC_enuErrorStatus_INVALID_PRIORITY_GROUPING

}MNVIC_enuErrorStatus_t;

typedef enum {
    MSYSTICK_PRIGROUP_16GROUPS_0SUB = 0b000, // 16 group priorities, 0 subpriorities
    MSYSTICK_PRIGROUP_8GROUPS_2SUB  = 0b100, // 8 group priorities, 2 subpriorities
    MSYSTICK_PRIGROUP_4GROUPS_4SUB  = 0b101, // 4 group priorities, 4 subpriorities
    MSYSTICK_PRIGROUP_2GROUPS_8SUB  = 0b110, // 2 group priorities, 8 subpriorities
    MSYSTICK_PRIGROUP_0GROUPS_16SUB = 0b111  // 0 group priorities, 16 subpriorities
} MSYSTICK_PRIGROUP_t;

typedef enum {
    MNVIC_enuWWDG,
    MNVIC_enuEXTI16_PVD,
    MNVIC_enuEXTI21_TAMP_STAMP,
    MNVIC_enuEXTI22_RTC_WKUP,
    MNVIC_enuFLASH,
    MNVIC_enuRCC,
    MNVIC_enuEXTI0,
    MNVIC_enuEXTI1,
    MNVIC_enuEXTI2,
    MNVIC_enuEXTI3,
    MNVIC_enuEXTI4,
    MNVIC_enuDMA1_Stream0,
    MNVIC_enuDMA1_Stream1,
    MNVIC_enuDMA1_Stream2,
    MNVIC_enuDMA1_Stream3,
    MNVIC_enuDMA1_Stream4,
    MNVIC_enuDMA1_Stream5,
    MNVIC_enuDMA1_Stream6,
    MNVIC_enuADC ,
    MNVIC_enuEXTI9_5=23,
    MNVIC_enuTIM1_BRK_TIM9,
    MNVIC_enuTIM1_UP_TIM10,
    MNVIC_enuTIM1_TRG_COM_TIM11,
    MNVIC_enuTIM1_CC,
    MNVIC_enuTIM2,
    MNVIC_enuTIM3,
    MNVIC_enuTIM4,
    MNVIC_enuI2C1_EV,
    MNVIC_enuI2C1_ER,
    MNVIC_enuI2C2_EV,
    MNVIC_enuI2C2_ER,
    MNVIC_enuSPI1,
    MNVIC_enuSPI2,
    MNVIC_enuUSART1,
    MNVIC_enuUSART2,
    MNVIC_enuEXTI15_10=40,
    MNVIC_enuEXTI17_RTC_Alarm,
    MNVIC_enuEXTI18_OTG_FS_WKUP,
    MNVIC_enuDMA1_Stream7=47,
    MNVIC_enuSDIO=49,
    MNVIC_enuTIM5,
    MNVIC_enuSPI3,
    MNVIC_enuDMA2_Stream0=56,
    MNVIC_enuDMA2_Stream1,
    MNVIC_enuDMA2_Stream2,
    MNVIC_enuDMA2_Stream3,
    MNVIC_enuDMA2_Stream4,
    MNVIC_enuOTG_FS=67,
    MNVIC_enuDMA2_Stream5,
    MNVIC_enuDMA2_Stream6,
    MNVIC_enuDMA2_Stream7,
    MNVIC_enuUSART6,
    MNVIC_enuI2C3_EV ,
    MNVIC_enuI2C3_ER,
    MNVIC_enuFPU=81,
    MNVIC_enuSPI4=84 
} MMNVIC_enuIRQn_t;


MNVIC_enuErrorStatus_t MNVIC_enuEnableIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn); 
MNVIC_enuErrorStatus_t MNVIC_enuDisableIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn); 
MNVIC_enuErrorStatus_t MNVIC_enuSetPendingIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn);
MNVIC_enuErrorStatus_t MNVIC_enuClearPendingIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn);
MNVIC_enuErrorStatus_t MNVIC_enuGetPendingIRQ(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t* Addr_u32PendingIRQ);
MNVIC_enuErrorStatus_t MNVIC_enuSetPriority(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t priority);
MNVIC_enuErrorStatus_t MNVIC_enuGetPriority(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t* Addr_u32Priority);
MNVIC_enuErrorStatus_t MNVIC_enuSetPriorityGrouping(uint32_t priority_grouping);
MNVIC_enuErrorStatus_t MNVIC_enuGetActive(MMNVIC_enuIRQn_t Copy_u32IRQn, uint32_t* Addr_u32Active);
void MNVIC_vSystemReset(void);

#endif //MMNVIC_H