#ifndef MSYSTICK_H
#define MSYSTICK_H

#include "STD_TYPES.h"

typedef void (*MSYSTICK_cbf_t) (void);

#define MSYSTICK_EN_MASK                (0x1)
#define MSYSTICK_INTEN_MASK             (0x2)
#define MSYSTICK_CLKSOURCE_AHB_8_MASK   (0x0)
#define MSYSTICK_CLKSOURCE_AHB_MASK     (0x4)   
//#define MSYSTICK_CURRENT_VALUE_MASK    (0x00FFFFFF)

typedef enum
{
    MSYSTICK_enuErrorStatus_NOK,
    MSYSTICK_enuErrorStatus_OK,
    MSYSTICK_enuErrorStatus_NULL_POINTER,
    MSYSTICK_enuErrorStatus_INVALID_SYSCLK
}MSYSTICK_enuErrorStatus_t;

void MSYSTICK_vInit();
MSYSTICK_enuErrorStatus_t MSYSTICK_enuSetCyclicCbf(MSYSTICK_cbf_t Addr_voidPtr, uint32_t Copy_u32CyclicDelayMs);
MSYSTICK_enuErrorStatus_t MSYSTICK_enuDelayMs(uint32_t delayMs); 
void MSYSTICK_vStart();  
void MSYSTICK_vStop();


#endif  //MSYSTICK_H