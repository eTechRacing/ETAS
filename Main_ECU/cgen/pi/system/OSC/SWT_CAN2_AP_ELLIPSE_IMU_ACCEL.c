#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELLIPSE_IMU_ACCEL.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_19_0(void);
extern void rtioHook_19_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL, thread18);

TASK(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL);

	sgHook(19);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(19);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL
    XCP_STIM_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL
#endif
#endif
	crossbarHook_19_0();
	rtioHook_19_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL
    XCP_DAQ_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELLIPSE_IMU_ACCEL);

	TerminateTask();
}
