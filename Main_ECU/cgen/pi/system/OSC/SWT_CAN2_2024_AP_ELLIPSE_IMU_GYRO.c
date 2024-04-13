#define NO_OSEKLIB
#include "SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_20_0(void);
extern void rtioHook_20_0(void);


TASK_MONITOR_DEF(SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO, thread23);

TASK(SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO)
{
	START_TASK_HOOK(SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO);

	sgHook(20);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(20);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
    XCP_STIM_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
#endif
#endif
	crossbarHook_20_0();
	rtioHook_20_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
    XCP_DAQ_SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO);

	TerminateTask();
}
