#define NO_OSEKLIB
#include "SWT_CAN2_2024_AP_FECU_Data2.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_23_0(void);
extern void rtioHook_23_0(void);


TASK_MONITOR_DEF(SWT_CAN2_2024_AP_FECU_Data2, thread28);

TASK(SWT_CAN2_2024_AP_FECU_Data2)
{
	START_TASK_HOOK(SWT_CAN2_2024_AP_FECU_Data2);

	sgHook(23);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(23);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_2024_AP_FECU_Data2
    XCP_STIM_SWT_CAN2_2024_AP_FECU_Data2
#endif
#endif
	crossbarHook_23_0();
	rtioHook_23_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_2024_AP_FECU_Data2
    XCP_DAQ_SWT_CAN2_2024_AP_FECU_Data2
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_2024_AP_FECU_Data2);

	TerminateTask();
}
