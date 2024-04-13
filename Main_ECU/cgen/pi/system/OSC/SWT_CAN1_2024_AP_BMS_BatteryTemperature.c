#define NO_OSEKLIB
#include "SWT_CAN1_2024_AP_BMS_BatteryTemperature.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_2_0(void);
extern void rtioHook_2_0(void);


TASK_MONITOR_DEF(SWT_CAN1_2024_AP_BMS_BatteryTemperature, thread5);

TASK(SWT_CAN1_2024_AP_BMS_BatteryTemperature)
{
	START_TASK_HOOK(SWT_CAN1_2024_AP_BMS_BatteryTemperature);

	sgHook(2);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(2);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_2024_AP_BMS_BatteryTemperature
    XCP_STIM_SWT_CAN1_2024_AP_BMS_BatteryTemperature
#endif
#endif
	crossbarHook_2_0();
	rtioHook_2_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_2024_AP_BMS_BatteryTemperature
    XCP_DAQ_SWT_CAN1_2024_AP_BMS_BatteryTemperature
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_2024_AP_BMS_BatteryTemperature);

	TerminateTask();
}
