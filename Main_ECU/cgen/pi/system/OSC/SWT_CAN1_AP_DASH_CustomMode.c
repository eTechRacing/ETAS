#define NO_OSEKLIB
#include "SWT_CAN1_AP_DASH_CustomMode.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_11_0(void);
extern void rtioHook_11_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_DASH_CustomMode, thread10);

TASK(SWT_CAN1_AP_DASH_CustomMode)
{
	START_TASK_HOOK(SWT_CAN1_AP_DASH_CustomMode);

	sgHook(11);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(11);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_DASH_CustomMode
    XCP_STIM_SWT_CAN1_AP_DASH_CustomMode
#endif
#endif
	crossbarHook_11_0();
	rtioHook_11_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_DASH_CustomMode
    XCP_DAQ_SWT_CAN1_AP_DASH_CustomMode
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_DASH_CustomMode);

	TerminateTask();
}
