#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_MAG_1.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_32_0(void);
extern void rtioHook_32_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_MAG_1, thread24);

TASK(SWT_CAN2_AP_ELLIPSE_MAG_1)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_MAG_1);

	sgHook(32);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(32);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_MAG_1
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_MAG_1
#endif
#endif
	crossbarHook_32_0();
	rtioHook_32_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_MAG_1
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_MAG_1
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_MAG_1);

	TerminateTask();
}
