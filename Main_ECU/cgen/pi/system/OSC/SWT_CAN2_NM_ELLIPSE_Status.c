#define NO_OSEKLIB
#include "SWT_CAN2_NM_ELLIPSE_Status.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_27_0(void);
extern void rtioHook_27_0(void);


TASK_MONITOR_DEF(SWT_CAN2_NM_ELLIPSE_Status, thread22);

TASK(SWT_CAN2_NM_ELLIPSE_Status)
{
	START_TASK_HOOK(SWT_CAN2_NM_ELLIPSE_Status);

	sgHook(27);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(27);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_NM_ELLIPSE_Status
    XCP_STIM_SWT_CAN2_NM_ELLIPSE_Status
#endif
#endif
	crossbarHook_27_0();
	rtioHook_27_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_NM_ELLIPSE_Status
    XCP_DAQ_SWT_CAN2_NM_ELLIPSE_Status
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_NM_ELLIPSE_Status);

	TerminateTask();
}
