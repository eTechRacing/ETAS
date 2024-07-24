#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_EKF_POS.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_15_0(void);
extern void rtioHook_15_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_EKF_POS, thread17);

TASK(SWT_CAN2_AP_ELLIPSE_EKF_POS)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_EKF_POS);

	sgHook(15);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(15);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_EKF_POS
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_EKF_POS
#endif
#endif
	crossbarHook_15_0();
	rtioHook_15_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_EKF_POS
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_EKF_POS
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_EKF_POS);

	TerminateTask();
}
