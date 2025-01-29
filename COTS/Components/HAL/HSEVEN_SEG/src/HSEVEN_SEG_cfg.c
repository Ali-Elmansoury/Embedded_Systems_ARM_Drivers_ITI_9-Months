#include "HSEVEN_SEG.h"
#include "HSEVEN_SEG_cfg.h"
#include "MGPIO.h"

HSEVEN_SEG_strSevenSegCfg_t HSEVEN_SEG_strSevenSegCfg[HSEVEN_SEG_NUM_OF_SEVEN_SEG] = {
    [HSEVEN_SEG_SEVEN_SEG1] = {
        .HSEVEN_SEG_strSevenSegPins = {
            .HSEVEN_SEG_PIN_A = HSEVEN_SEG_PINA0,
            .HSEVEN_SEG_PIN_B = HSEVEN_SEG_PINA1,
            .HSEVEN_SEG_PIN_C = HSEVEN_SEG_PINA2,
            .HSEVEN_SEG_PIN_D = HSEVEN_SEG_PINA3,
            .HSEVEN_SEG_PIN_E = HSEVEN_SEG_PINA4,
            .HSEVEN_SEG_PIN_F = HSEVEN_SEG_PINA5,
            .HSEVEN_SEG_PIN_G = HSEVEN_SEG_PINA6,
            .HSEVEN_SEG_PIN_DP = HSEVEN_SEG_PINA7,
        },
        .HSEVEN_SEG_enuSevenSegConnection = HSEVEN_SEG_enuCommon_Cathode
    },
    [HSEVEN_SEG_SEVEN_SEG2] = {
        .HSEVEN_SEG_strSevenSegPins = {
            .HSEVEN_SEG_PIN_A = HSEVEN_SEG_PINB0,
            .HSEVEN_SEG_PIN_B = HSEVEN_SEG_PINB1,
            .HSEVEN_SEG_PIN_C = HSEVEN_SEG_PINB2,
            .HSEVEN_SEG_PIN_D = HSEVEN_SEG_PINB3,
            .HSEVEN_SEG_PIN_E = HSEVEN_SEG_PINB4,
            .HSEVEN_SEG_PIN_F = HSEVEN_SEG_PINB5,
            .HSEVEN_SEG_PIN_G = HSEVEN_SEG_PINB6,
            .HSEVEN_SEG_PIN_DP = HSEVEN_SEG_PINB7,
        },
        .HSEVEN_SEG_enuSevenSegConnection = HSEVEN_SEG_enuCommon_Anode
    },
    [HSEVEN_SEG_SEVEN_SEG3] = {
        .HSEVEN_SEG_strSevenSegPins = {
            .HSEVEN_SEG_PIN_A = HSEVEN_SEG_PINC0,
            .HSEVEN_SEG_PIN_B = HSEVEN_SEG_PINC1,
            .HSEVEN_SEG_PIN_C = HSEVEN_SEG_PINC2,
            .HSEVEN_SEG_PIN_D = HSEVEN_SEG_PINC3,
            .HSEVEN_SEG_PIN_E = HSEVEN_SEG_PINC4,
            .HSEVEN_SEG_PIN_F = HSEVEN_SEG_PINC5,
            .HSEVEN_SEG_PIN_G = HSEVEN_SEG_PINC6,
            .HSEVEN_SEG_PIN_DP = HSEVEN_SEG_PINC7,
        },
        .HSEVEN_SEG_enuSevenSegConnection = HSEVEN_SEG_enuCommon_Cathode
    },
    [HSEVEN_SEG_SEVEN_SEG4] = {
        .HSEVEN_SEG_strSevenSegPins = {
            .HSEVEN_SEG_PIN_A = HSEVEN_SEG_PIND0,
            .HSEVEN_SEG_PIN_B = HSEVEN_SEG_PIND1,
            .HSEVEN_SEG_PIN_C = HSEVEN_SEG_PIND2,
            .HSEVEN_SEG_PIN_D = HSEVEN_SEG_PIND3,
            .HSEVEN_SEG_PIN_E = HSEVEN_SEG_PIND4,
            .HSEVEN_SEG_PIN_F = HSEVEN_SEG_PIND5,
            .HSEVEN_SEG_PIN_G = HSEVEN_SEG_PIND6,
            .HSEVEN_SEG_PIN_DP = HSEVEN_SEG_PIND7,
        },
        .HSEVEN_SEG_enuSevenSegConnection = HSEVEN_SEG_enuCommon_Cathode
    }
};