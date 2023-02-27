#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_Current_SOC_SOH1.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_6_0(void);
extern void rtioHook_6_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_Current_SOC_SOH1, thread32);

TASK(SWT_CAN1_AP_BMS_Current_SOC_SOH1)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_Current_SOC_SOH1);

	sgHook(6);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(6);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_Current_SOC_SOH1
    XCP_STIM_SWT_CAN1_AP_BMS_Current_SOC_SOH1
#endif
#endif
	crossbarHook_6_0();
	rtioHook_6_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_Current_SOC_SOH1
    XCP_DAQ_SWT_CAN1_AP_BMS_Current_SOC_SOH1
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_Current_SOC_SOH1);

	TerminateTask();
}
