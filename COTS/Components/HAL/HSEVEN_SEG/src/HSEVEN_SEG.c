#include "HSEVEN_SEG.h"
#include "HSEVEN_SEG_cfg.h"
#include "MGPIO.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

HSEVEN_SEG_enuSevenSegNums_t HSEVEN_SEG_enuSevenSegNums[10] = {
    HSEVEN_SEG_NUM_0,
    HSEVEN_SEG_NUM_1,
    HSEVEN_SEG_NUM_2,
    HSEVEN_SEG_NUM_3,
    HSEVEN_SEG_NUM_4,
    HSEVEN_SEG_NUM_5,
    HSEVEN_SEG_NUM_6,
    HSEVEN_SEG_NUM_7,
    HSEVEN_SEG_NUM_8,
    HSEVEN_SEG_NUM_9};

extern HSEVEN_SEG_strSevenSegCfg_t HSEVEN_SEG_strSevenSegCfg[HSEVEN_SEG_NUM_OF_SEVEN_SEG];

HSEVENSEG_enuErrorStatus_t HSEVENSEG_vInit(void)
{
    HSEVENSEG_enuErrorStatus_t Loc_enuErrorStatus = HSEVEN_SEG_enuErrorStatus_OK;
    uint8_t Loc_currentPortPin = 0;
    for (uint8_t iteratorSevenSeg = 0; iteratorSevenSeg < HSEVEN_SEG_NUM_OF_SEVEN_SEG; iteratorSevenSeg++)
    {
        for (uint8_t iteratorPins = 0; iteratorPins < HSEVEN_SEG_NUM_OF_SEVEN_SEG_PINS; iteratorPins++)
        {
            Loc_currentPortPin = HSEVEN_SEG_strSevenSegCfg[iteratorSevenSeg].HSEVEN_SEG_strSevenSegPins.HSEVEN_SEG_PINS[iteratorPins];
            MGPIO_enuPorts_t Loc_u32port = GET_HIGH_NIB(Loc_currentPortPin);
            MGPIO_enuPins_t Loc_u32Pin = GET_LOW_NIB(Loc_currentPortPin);
            MGPIO_strPinCfg_t Loc_strPinCfg = {
                .MGPIO_Mode = MGPIO_enuPinMode_GENERAL_PURPOSE_OUTPUT,
                .MGPIO_PinPullType = MGPIO_enuPinPullType_NO_PULL,
                .MGPIO_PinAltFunction = MGPIO_enuPinAltFunction_AF0_SYSTEM,
                .MGPIO_PinSpeed = MGPIO_enuPinSpeed_LOW,
                .MGPIO_Port = Loc_u32port,
                .MGPIO_Pin = Loc_u32Pin,
                .MGPIO_OutputType = MGPIO_enuPinOutputType_PUSH_PULL
            };
            Loc_enuErrorStatus = MGPIO_enuConfigPin(&Loc_strPinCfg);
        }
    }
    return Loc_enuErrorStatus;
}

HSEVENSEG_enuErrorStatus_t HSEVENSEG_vSetValue(uint8_t Copy_enuSevenSegNum, uint8_t Copy_u8Value)
{
    uint8_t Loc_currentPortPin = 0;
    uint8_t Loc_currentPortNum = 0;
    uint8_t Loc_currentPinNum = 0;
    uint8_t Loc_currentSevenSegConnection = 0;
    uint8_t Loc_segPattern = 0;
    HSEVENSEG_enuErrorStatus_t Loc_enuErrorStatus = HSEVEN_SEG_enuErrorStatus_OK;
    if (Copy_enuSevenSegNum >= HSEVEN_SEG_NUM_OF_SEVEN_SEG || Copy_u8Value > HSEVEN_SEG_MAX_NUM_TO_DISPLAY)
    {
        Loc_enuErrorStatus = HSEVEN_SEG_enuError_INVALID_SEVEN_SEG_CONFIG;
    }
    else
    {
        Loc_currentSevenSegConnection = HSEVEN_SEG_strSevenSegCfg[Copy_enuSevenSegNum].HSEVEN_SEG_enuSevenSegConnection;
        Loc_segPattern = HSEVEN_SEG_enuSevenSegNums[Copy_u8Value];
        for (uint8_t iteratorSevenSegPin = 0; iteratorSevenSegPin < HSEVEN_SEG_NUM_OF_SEVEN_SEG_PINS; iteratorSevenSegPin++)
        {

            Loc_currentPortPin = HSEVEN_SEG_strSevenSegCfg[Copy_enuSevenSegNum].HSEVEN_SEG_strSevenSegPins.HSEVEN_SEG_PINS[iteratorSevenSegPin];
            Loc_currentPortNum = GET_HIGH_NIB(Loc_currentPortPin);
            Loc_currentPinNum = GET_LOW_NIB(Loc_currentPortPin);
            uint8_t Loc_pinState = (Loc_segPattern & (1 << iteratorSevenSegPin)) ? MGPIO_enuPinState_HIGH : MGPIO_enuPinSpeed_LOW;
            if (Loc_currentSevenSegConnection == HSEVEN_SEG_enuCommon_Anode)
            {
                Loc_pinState = (Loc_pinState == MGPIO_enuPinState_HIGH) ? MGPIO_enuPinSpeed_LOW : MGPIO_enuPinState_HIGH;
            }
            MGPIO_enuSetPinState(Loc_currentPortNum, Loc_currentPinNum, Loc_pinState);
        }
    }
    return Loc_enuErrorStatus;
}

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(uint16_t Copy_u16Value)
{
    uint8_t Loc_currentDigit = 0;
    uint8_t Loc_numDigits = 0;
    uint16_t Loc_tempValue = Copy_u16Value;
    HSEVENSEG_enuErrorStatus_t Ret_enuErrorStatus = HSEVEN_SEG_enuErrorStatus_NOK;

    // Calculate the number of digits in the given number
    do
    {
        Loc_numDigits++;
        Loc_tempValue /= 10;
    } while (Loc_tempValue != 0);

    // Check if the number of digits exceeds the available seven-segment displays
    if (Loc_numDigits > HSEVEN_SEG_NUM_OF_SEVEN_SEG)
    {
        return HSEVEN_SEG_enuError_INVALID_NUM_OF_SEVEN_SEG;
    }
    else
    {
        Ret_enuErrorStatus = HSEVEN_SEG_enuErrorStatus_OK;

        // Loop through all the displays
        for (uint8_t Loc_iteratorSevenSeg = 0; Loc_iteratorSevenSeg < HSEVEN_SEG_NUM_OF_SEVEN_SEG; Loc_iteratorSevenSeg++)
        {
            if (Loc_iteratorSevenSeg < Loc_numDigits)
            {
                // Extract the least significant digit
                Loc_currentDigit = Copy_u16Value % 10;

                // Set the value on the corresponding seven-segment display
                HSEVENSEG_vSetValue((Loc_numDigits - Loc_iteratorSevenSeg - 1), Loc_currentDigit);

                // Remove the processed digit
                Copy_u16Value /= 10;
            }
            else
            {
                // Clear remaining displays
                HSEVENSEG_vSetValue(Loc_iteratorSevenSeg, 0);
            }
        }
    }
    return Ret_enuErrorStatus;
}