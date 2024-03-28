#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_SLIP_CURV.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_21_0(void);
extern void rtioHook_21_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_SLIP_CURV, thread24);

TASK(SWT_CAN2_AP_ELLIPSE_SLIP_CURV)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_SLIP_CURV);

	sgHook(21);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(21);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_SLIP_CURV
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_SLIP_CURV
#endif
#endif
	crossbarHook_21_0();
	rtioHook_21_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_SLIP_CURV
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_SLIP_CURV
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_SLIP_CURV);

	TerminateTask();
}
