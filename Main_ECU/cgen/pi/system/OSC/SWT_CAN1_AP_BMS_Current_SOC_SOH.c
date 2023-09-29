#define NO_OSEKLIB
#include "SWT_CAN1_AP_BMS_Current_SOC_SOH.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_4_0(void);
extern void rtioHook_4_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_BMS_Current_SOC_SOH, thread1);

TASK(SWT_CAN1_AP_BMS_Current_SOC_SOH)
{
	START_TASK_HOOK(SWT_CAN1_AP_BMS_Current_SOC_SOH);

	sgHook(4);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(4);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_BMS_Current_SOC_SOH
    XCP_STIM_SWT_CAN1_AP_BMS_Current_SOC_SOH
#endif
#endif
	crossbarHook_4_0();
	rtioHook_4_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_BMS_Current_SOC_SOH
    XCP_DAQ_SWT_CAN1_AP_BMS_Current_SOC_SOH
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_BMS_Current_SOC_SOH);

	TerminateTask();
}
