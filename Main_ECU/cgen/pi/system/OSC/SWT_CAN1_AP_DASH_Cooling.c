#define NO_OSEKLIB
#include "SWT_CAN1_AP_DASH_Cooling.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_8_0(void);
extern void rtioHook_8_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_DASH_Cooling, thread2);

TASK(SWT_CAN1_AP_DASH_Cooling)
{
	START_TASK_HOOK(SWT_CAN1_AP_DASH_Cooling);

	sgHook(8);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(8);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_DASH_Cooling
    XCP_STIM_SWT_CAN1_AP_DASH_Cooling
#endif
#endif
	crossbarHook_8_0();
	rtioHook_8_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_DASH_Cooling
    XCP_DAQ_SWT_CAN1_AP_DASH_Cooling
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_DASH_Cooling);

	TerminateTask();
}
