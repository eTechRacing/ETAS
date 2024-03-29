#define NO_OSEKLIB
#include "SWT_CAN2_AP_ACCEL_F_Data.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_22_0(void);
extern void rtioHook_22_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ACCEL_F_Data, thread22);

TASK(SWT_CAN2_AP_ACCEL_F_Data)
{
	START_TASK_HOOK(SWT_CAN2_AP_ACCEL_F_Data);

	sgHook(22);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(22);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ACCEL_F_Data
    XCP_STIM_SWT_CAN2_AP_ACCEL_F_Data
#endif
#endif
	crossbarHook_22_0();
	rtioHook_22_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ACCEL_F_Data
    XCP_DAQ_SWT_CAN2_AP_ACCEL_F_Data
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ACCEL_F_Data);

	TerminateTask();
}
