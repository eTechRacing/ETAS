#define NO_OSEKLIB
#include "SWT_CAN2_AP_ACCEL_R_Data.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_20_0(void);
extern void rtioHook_20_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ACCEL_R_Data, thread25);

TASK(SWT_CAN2_AP_ACCEL_R_Data)
{
	START_TASK_HOOK(SWT_CAN2_AP_ACCEL_R_Data);

	sgHook(20);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(20);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ACCEL_R_Data
    XCP_STIM_SWT_CAN2_AP_ACCEL_R_Data
#endif
#endif
	crossbarHook_20_0();
	rtioHook_20_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ACCEL_R_Data
    XCP_DAQ_SWT_CAN2_AP_ACCEL_R_Data
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ACCEL_R_Data);

	TerminateTask();
}
