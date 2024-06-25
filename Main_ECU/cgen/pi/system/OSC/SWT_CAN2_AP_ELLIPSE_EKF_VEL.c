#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_EKF_VEL.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_16_0(void);
extern void rtioHook_16_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_EKF_VEL, thread19);

TASK(SWT_CAN2_AP_ELLIPSE_EKF_VEL)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_EKF_VEL);

	sgHook(16);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(16);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_EKF_VEL
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_EKF_VEL
#endif
#endif
	crossbarHook_16_0();
	rtioHook_16_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_EKF_VEL
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_EKF_VEL
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_EKF_VEL);

	TerminateTask();
}