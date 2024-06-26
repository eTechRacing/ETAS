#define NO_OSEKLIB
#include "SWT_CAN1_2024_AP_DASH_TorqueLockOn.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_11_0(void);
extern void rtioHook_11_0(void);


TASK_MONITOR_DEF(SWT_CAN1_2024_AP_DASH_TorqueLockOn, thread13);

TASK(SWT_CAN1_2024_AP_DASH_TorqueLockOn)
{
	START_TASK_HOOK(SWT_CAN1_2024_AP_DASH_TorqueLockOn);

	sgHook(11);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(11);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_2024_AP_DASH_TorqueLockOn
    XCP_STIM_SWT_CAN1_2024_AP_DASH_TorqueLockOn
#endif
#endif
	crossbarHook_11_0();
	rtioHook_11_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_2024_AP_DASH_TorqueLockOn
    XCP_DAQ_SWT_CAN1_2024_AP_DASH_TorqueLockOn
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_2024_AP_DASH_TorqueLockOn);

	TerminateTask();
}
