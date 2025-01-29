#include "HSWITCH_cfg.h"
#include "HSWITCH.h"
#include "MGPIO.h"

HSWITCH_strSwitchCfg_t HSWITCH_strSwitchCfg[HSWITCH_NUM_OF_SWITCHS] = {
    [HSWITCH_SWITCH_START] = {
        .HSWITCH_enuSwitchPort = MGPIO_enuPORT_B,
        .HSWITCH_enuSwitchPin = MGPIO_enuPIN_0,
        .HSWITCH_enuSwitchConnection = HSWITCH_enuSwitch_INTERNAL_PULL_UP,
        .HSWITCH_enuSwitchDebounce = HSWITCH_enuSwitchDebounce_ON
    },
    [HSWITCH_SWITCH_STOP] = {
        .HSWITCH_enuSwitchPort = MGPIO_enuPORT_B,
        .HSWITCH_enuSwitchPin = MGPIO_enuPIN_1,
        .HSWITCH_enuSwitchConnection = HSWITCH_enuSwitch_INTERNAL_PULL_UP,
        .HSWITCH_enuSwitchDebounce = HSWITCH_enuSwitchDebounce_ON
    },
    [HSWITCH_SWITCH_ALERT] = {
        .HSWITCH_enuSwitchPort = MGPIO_enuPORT_B,
        .HSWITCH_enuSwitchPin = MGPIO_enuPIN_2,
        .HSWITCH_enuSwitchConnection = HSWITCH_enuSwitch_INTERNAL_PULL_UP,
        .HSWITCH_enuSwitchDebounce = HSWITCH_enuSwitchDebounce_ON
    }
};