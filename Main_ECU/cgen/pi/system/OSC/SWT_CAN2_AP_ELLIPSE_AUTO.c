#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_AUTO.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_14_0(void);
extern void rtioHook_14_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_AUTO, thread14);

TASK(SWT_CAN2_AP_ELLIPSE_AUTO)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_AUTO);

	sgHook(14);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(14);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_AUTO
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_AUTO
#endif
#endif
	crossbarHook_14_0();
	rtioHook_14_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_AUTO
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_AUTO
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_AUTO);

	TerminateTask();
}
