#define NO_OSEKLIB
#include "SWT_CAN1_AP_DASH_EnableDrive.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_10_0(void);
extern void rtioHook_10_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_DASH_EnableDrive, thread17);

TASK(SWT_CAN1_AP_DASH_EnableDrive)
{
	START_TASK_HOOK(SWT_CAN1_AP_DASH_EnableDrive);

	sgHook(10);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(10);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_DASH_EnableDrive
    XCP_STIM_SWT_CAN1_AP_DASH_EnableDrive
#endif
#endif
	crossbarHook_10_0();
	rtioHook_10_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_DASH_EnableDrive
    XCP_DAQ_SWT_CAN1_AP_DASH_EnableDrive
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_DASH_EnableDrive);

	TerminateTask();
}
