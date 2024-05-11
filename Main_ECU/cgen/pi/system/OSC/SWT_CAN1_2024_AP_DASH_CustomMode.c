#define NO_OSEKLIB
#include "SWT_CAN1_2024_AP_DASH_CustomMode.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_7_0(void);
extern void rtioHook_7_0(void);


TASK_MONITOR_DEF(SWT_CAN1_2024_AP_DASH_CustomMode, thread8);

TASK(SWT_CAN1_2024_AP_DASH_CustomMode)
{
	START_TASK_HOOK(SWT_CAN1_2024_AP_DASH_CustomMode);

	sgHook(7);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(7);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_2024_AP_DASH_CustomMode
    XCP_STIM_SWT_CAN1_2024_AP_DASH_CustomMode
#endif
#endif
	crossbarHook_7_0();
	rtioHook_7_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_2024_AP_DASH_CustomMode
    XCP_DAQ_SWT_CAN1_2024_AP_DASH_CustomMode
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_2024_AP_DASH_CustomMode);

	TerminateTask();
}
