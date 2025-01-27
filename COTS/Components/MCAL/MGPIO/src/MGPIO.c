#include "MGPIO.h"

#define MGPIOA_BASE_ADDRESS (0x40020000UL)
#define MGPIOB_BASE_ADDRESS (0x40020400UL)
#define MGPIOC_BASE_ADDRESS (0x40020800UL)
#define MGPIOD_BASE_ADDRESS (0x40020C00UL)
#define MGPIOE_BASE_ADDRESS (0x40021000UL)
#define MGPIOH_BASE_ADDRESS (0x40021C00UL)

typedef struct
{
    volatile uint32_t MGPIO_MODER_REG;
    volatile uint32_t MGPIO_OTYPER_REG;
    volatile uint32_t MGPIO_OSPEEDR_REG;
    volatile uint32_t MGPIO_PUPDR_REG;
    volatile uint32_t MGPIO_IDR_REG;
    volatile uint32_t MGPIO_ODR_REG;
    volatile uint32_t MGPIO_BSRR_REG;
    volatile uint32_t MGPIO_LCKR_REG;
    volatile uint32_t MGPIO_AFRL_REG;
    volatile uint32_t MGPIO_AFRH_REG;
} MGPIO_structReg_t;

volatile MGPIO_structReg_t *MGPIOA_REG = ((volatile MGPIO_structReg_t *)MGPIOA_BASE_ADDRESS);

volatile MGPIO_structReg_t *MGPIOB_REG = ((volatile MGPIO_structReg_t *)MGPIOB_BASE_ADDRESS);

volatile MGPIO_structReg_t *MGPIOC_REG = ((volatile MGPIO_structReg_t *)MGPIOC_BASE_ADDRESS);

volatile MGPIO_structReg_t *MGPIOD_REG = ((volatile MGPIO_structReg_t *)MGPIOD_BASE_ADDRESS);

volatile MGPIO_structReg_t *MGPIOE_REG = ((volatile MGPIO_structReg_t *)MGPIOE_BASE_ADDRESS);

volatile MGPIO_structReg_t *MGPIOH_REG = ((volatile MGPIO_structReg_t *)MGPIOH_BASE_ADDRESS);

MGPIO_enuErrorStatus_t MGPIO_enuConfigPin(MGPIO_strPinCfg_t *Addr_PinCfg)
{
    MGPIO_enuErrorStatus_t Loc_enuErrorStatus = MGPIO_enuErrorStatus_OK;
    if (Addr_PinCfg == NULL)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_NULLPTR;
    }
    else if (Addr_PinCfg->MGPIO_Port > MGPIO_enuPORT_H || Addr_PinCfg->MGPIO_Port < MGPIO_enuPORT_A)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PORT;
    }
    else if (Addr_PinCfg->MGPIO_Pin > MGPIO_enuPIN_15 || Addr_PinCfg->MGPIO_Pin < MGPIO_enuPIN_0)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN;
    }
    else if (Addr_PinCfg->MGPIO_Mode > MGPIO_enuPinMode_ANALOG || Addr_PinCfg->MGPIO_Mode < MGPIO_enuPinMode_INPUT)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_MODE;
    }
    else if (Addr_PinCfg->MGPIO_OutputType > MGPIO_enuPinOutputType_OPEN_DRAIN || Addr_PinCfg->MGPIO_OutputType < MGPIO_enuPinOutputType_PUSH_PULL)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_OUTPUT_TYPE;
    }
    else if (Addr_PinCfg->MGPIO_PinPullType > MGPIO_enuPinPullType_PULL_DOWN || Addr_PinCfg->MGPIO_PinPullType < MGPIO_enuPinPullType_NO_PULL)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_PULL_TYPE;
    }
    else if (Addr_PinCfg->MGPIO_PinSpeed > MGPIO_enuPinSpeed_VERY_HIGH || Addr_PinCfg->MGPIO_PinSpeed < MGPIO_enuPinSpeed_LOW)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_SPEED;
    }
    else if (Addr_PinCfg->MGPIO_PinAltFunction > MGPIO_enuPinAltFunction_AF15_EVENTOUT || Addr_PinCfg->MGPIO_PinAltFunction < MGPIO_enuPinAltFunction_AF0_SYSTEM)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_ALT_FUNCTION;
    }
    else
    {
        switch (Addr_PinCfg->MGPIO_Port)
        {
        case MGPIO_enuPORT_A:
            MGPIOA_REG->MGPIO_MODER_REG |= (Addr_PinCfg->MGPIO_Mode << (Addr_PinCfg->MGPIO_Pin * 2)); 
            MGPIOA_REG->MGPIO_OTYPER_REG |= (Addr_PinCfg->MGPIO_OutputType << Addr_PinCfg->MGPIO_Pin);
            MGPIOA_REG->MGPIO_OSPEEDR_REG |= (Addr_PinCfg->MGPIO_PinSpeed << (Addr_PinCfg->MGPIO_Pin * 2));
            MGPIOA_REG->MGPIO_PUPDR_REG |= (Addr_PinCfg->MGPIO_PinPullType << ((Addr_PinCfg->MGPIO_Pin * 2)));
            if (Addr_PinCfg->MGPIO_Pin < 8)
            {
                MGPIOA_REG->MGPIO_AFRL_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            else
            {
                MGPIOA_REG->MGPIO_AFRH_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            break;

        case MGPIO_enuPORT_B:
            MGPIOB_REG->MGPIO_MODER_REG |= (Addr_PinCfg->MGPIO_Mode << (Addr_PinCfg->MGPIO_Pin * 2)); 
            MGPIOB_REG->MGPIO_OTYPER_REG |= (Addr_PinCfg->MGPIO_OutputType << Addr_PinCfg->MGPIO_Pin);
            MGPIOB_REG->MGPIO_OSPEEDR_REG |= (Addr_PinCfg->MGPIO_PinSpeed << (Addr_PinCfg->MGPIO_Pin * 2));
            MGPIOB_REG->MGPIO_PUPDR_REG |= (Addr_PinCfg->MGPIO_PinPullType << ((Addr_PinCfg->MGPIO_Pin * 2)));
            if (Addr_PinCfg->MGPIO_Pin < 8)
            {
                MGPIOB_REG->MGPIO_AFRL_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            else
            {
                MGPIOB_REG->MGPIO_AFRH_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            break;

        case MGPIO_enuPORT_C:
            MGPIOC_REG->MGPIO_MODER_REG |= (Addr_PinCfg->MGPIO_Mode << (Addr_PinCfg->MGPIO_Pin * 2)); 
            MGPIOC_REG->MGPIO_OTYPER_REG |= (Addr_PinCfg->MGPIO_OutputType << Addr_PinCfg->MGPIO_Pin);
            MGPIOC_REG->MGPIO_OSPEEDR_REG |= (Addr_PinCfg->MGPIO_PinSpeed << (Addr_PinCfg->MGPIO_Pin * 2));
            MGPIOC_REG->MGPIO_PUPDR_REG |= (Addr_PinCfg->MGPIO_PinPullType << ((Addr_PinCfg->MGPIO_Pin * 2)));
            if (Addr_PinCfg->MGPIO_Pin < 8)
            {
                MGPIOC_REG->MGPIO_AFRL_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            else
            {
                MGPIOC_REG->MGPIO_AFRH_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            break;

        case MGPIO_enuPORT_D:
            MGPIOD_REG->MGPIO_MODER_REG |= (Addr_PinCfg->MGPIO_Mode << (Addr_PinCfg->MGPIO_Pin * 2)); 
            MGPIOD_REG->MGPIO_OTYPER_REG |= (Addr_PinCfg->MGPIO_OutputType << Addr_PinCfg->MGPIO_Pin);
            MGPIOD_REG->MGPIO_OSPEEDR_REG |= (Addr_PinCfg->MGPIO_PinSpeed << (Addr_PinCfg->MGPIO_Pin * 2));
            MGPIOD_REG->MGPIO_PUPDR_REG |= (Addr_PinCfg->MGPIO_PinPullType << ((Addr_PinCfg->MGPIO_Pin * 2)));
            if (Addr_PinCfg->MGPIO_Pin < 8)
            {
                MGPIOD_REG->MGPIO_AFRL_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            else
            {
                MGPIOD_REG->MGPIO_AFRH_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            break;

        case MGPIO_enuPORT_E:
            MGPIOE_REG->MGPIO_MODER_REG |= (Addr_PinCfg->MGPIO_Mode << (Addr_PinCfg->MGPIO_Pin * 2)); 
            MGPIOE_REG->MGPIO_OTYPER_REG |= (Addr_PinCfg->MGPIO_OutputType << Addr_PinCfg->MGPIO_Pin);
            MGPIOE_REG->MGPIO_OSPEEDR_REG |= (Addr_PinCfg->MGPIO_PinSpeed << (Addr_PinCfg->MGPIO_Pin * 2));
            MGPIOE_REG->MGPIO_PUPDR_REG |= (Addr_PinCfg->MGPIO_PinPullType << ((Addr_PinCfg->MGPIO_Pin * 2)));
            if (Addr_PinCfg->MGPIO_Pin < 8)
            {
                MGPIOE_REG->MGPIO_AFRL_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            else
            {
                MGPIOE_REG->MGPIO_AFRH_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            break;

        case MGPIO_enuPORT_H:
            MGPIOH_REG->MGPIO_MODER_REG |= (Addr_PinCfg->MGPIO_Mode << (Addr_PinCfg->MGPIO_Pin * 2)); 
            MGPIOH_REG->MGPIO_OTYPER_REG |= (Addr_PinCfg->MGPIO_OutputType << Addr_PinCfg->MGPIO_Pin);
            MGPIOH_REG->MGPIO_OSPEEDR_REG |= (Addr_PinCfg->MGPIO_PinSpeed << (Addr_PinCfg->MGPIO_Pin * 2));
            MGPIOH_REG->MGPIO_PUPDR_REG |= (Addr_PinCfg->MGPIO_PinPullType << ((Addr_PinCfg->MGPIO_Pin * 2)));
            if (Addr_PinCfg->MGPIO_Pin < 8)
            {
                MGPIOH_REG->MGPIO_AFRL_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            else
            {
                MGPIOH_REG->MGPIO_AFRH_REG |= (Addr_PinCfg->MGPIO_PinAltFunction << (Addr_PinCfg->MGPIO_Pin * 4));
            }
            break;            
        default:
            Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_CFG;
            break;
        }
    }
    return Loc_enuErrorStatus;
}

MGPIO_enuErrorStatus_t MGPIO_enuSetPinState(MGPIO_enuPorts_t Copy_u32Port, MGPIO_enuPins_t Copy_u32Pin, MGPIO_enuPinState_t Copy_u32PinState)
{
    MGPIO_enuErrorStatus_t Loc_enuErrorStatus = MGPIO_enuErrorStatus_OK;
    if (Copy_u32Port > MGPIO_enuPORT_H || Copy_u32Port < MGPIO_enuPORT_A)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PORT;
    }
    else if (Copy_u32Pin > MGPIO_enuPIN_15 || Copy_u32Pin < MGPIO_enuPIN_0)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN;
    }
    else if (Copy_u32PinState > MGPIO_enuPinState_HIGH || Copy_u32PinState < MGPIO_enuPinState_LOW)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_STATE;
    }
    else
    {
        switch (Copy_u32Port)
        {
        case MGPIO_enuPORT_A:
            if (Copy_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOA_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            else
            {
                MGPIOA_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            break;

        case MGPIO_enuPORT_B:
            if (Copy_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOB_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            else
            {
                MGPIOB_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            break;

        case MGPIO_enuPORT_C:
            if (Copy_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOC_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            else
            {
                MGPIOC_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            break;

        case MGPIO_enuPORT_D:
            if (Copy_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOD_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            else
            {
                MGPIOD_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            break;

        case MGPIO_enuPORT_E:
            if (Copy_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOE_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            else
            {
                MGPIOE_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            break;

        case MGPIO_enuPORT_H:
            if (Copy_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOH_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            else
            {
                MGPIOH_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            break;

        default:
            Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_CFG;
            break;
        }
    }
    return Loc_enuErrorStatus;
}

MGPIO_enuErrorStatus_t MGPIO_enuTogglePinState(MGPIO_enuPorts_t Copy_u32Port, MGPIO_enuPins_t Copy_u32Pin)
{
    MGPIO_enuErrorStatus_t Loc_enuErrorStatus = MGPIO_enuErrorStatus_OK;
    uint32_t Loc_u32PinState = 0;
    Loc_enuErrorStatus = MGPIO_enuGetPinState(Copy_u32Port, Copy_u32Pin, &Loc_u32PinState);
    if (Copy_u32Port > MGPIO_enuPORT_H || Copy_u32Port < MGPIO_enuPORT_A)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PORT;
    }
    else if (Copy_u32Pin > MGPIO_enuPIN_15 || Copy_u32Pin < MGPIO_enuPIN_0)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN;
    }
    else if (Loc_u32PinState > MGPIO_enuPinState_HIGH || Loc_u32PinState < MGPIO_enuPinState_LOW)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_STATE;
    }
    else
    {
        switch (Copy_u32Port)
        {
        case MGPIO_enuPORT_A:
            if (Loc_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOA_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            else
            {
                MGPIOA_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            break;

        case MGPIO_enuPORT_B:
            if (Loc_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOB_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            else
            {
                MGPIOB_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            break;

        case MGPIO_enuPORT_C:
            if (Loc_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOC_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            else
            {
                MGPIOC_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            break;

        case MGPIO_enuPORT_D:
            if (Loc_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOD_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            else
            {
                MGPIOD_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            break;

        case MGPIO_enuPORT_E:
            if (Loc_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOE_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            else
            {
                MGPIOE_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            break;

        case MGPIO_enuPORT_H:
            if (Loc_u32PinState == MGPIO_enuPinState_HIGH)
            {
                MGPIOH_REG->MGPIO_BSRR_REG = (1 << (Copy_u32Pin + 16));
            }
            else
            {
                MGPIOH_REG->MGPIO_BSRR_REG = (1 << Copy_u32Pin);
            }
            break;
                        
        default:
            Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_CFG;
            break;
        }
    }
    return Loc_enuErrorStatus;
}

MGPIO_enuErrorStatus_t MGPIO_enuGetPinState(MGPIO_enuPorts_t Copy_u32Port, MGPIO_enuPins_t Copy_u32Pin, uint32_t *Addr_PinState)
{
    MGPIO_enuErrorStatus_t Loc_enuErrorStatus = MGPIO_enuErrorStatus_OK;
    if (Addr_PinState == NULL)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_NULLPTR;
    }
    else if (Copy_u32Port > MGPIO_enuPORT_H || Copy_u32Port < MGPIO_enuPORT_A)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PORT;
    }
    else if (Copy_u32Pin > MGPIO_enuPIN_15 || Copy_u32Pin < MGPIO_enuPIN_0)
    {
        Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN;
    }
    else
    {
        switch (Copy_u32Port)
        {
        case MGPIO_enuPORT_A:
            *Addr_PinState = ((MGPIOA_REG->MGPIO_IDR_REG >> Copy_u32Pin) & 1);
            break;

        case MGPIO_enuPORT_B:
            *Addr_PinState = ((MGPIOB_REG->MGPIO_IDR_REG >> Copy_u32Pin) & 1);
            break;

        case MGPIO_enuPORT_C:
            *Addr_PinState = ((MGPIOC_REG->MGPIO_IDR_REG >> Copy_u32Pin) & 1);
            break;

        case MGPIO_enuPORT_D:
            *Addr_PinState = ((MGPIOD_REG->MGPIO_IDR_REG >> Copy_u32Pin) & 1);
            break;

        case MGPIO_enuPORT_E:
            *Addr_PinState = ((MGPIOE_REG->MGPIO_IDR_REG >> Copy_u32Pin) & 1);
            break;

        case MGPIO_enuPORT_H:
            *Addr_PinState = ((MGPIOH_REG->MGPIO_IDR_REG >> Copy_u32Pin) & 1);
            break;
                        
        default:
            Loc_enuErrorStatus = MGPIO_enuErrorStatus_INVALID_PIN_CFG;
            break;
        }
    }
    return Loc_enuErrorStatus;
}