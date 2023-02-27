#define NO_OSEKLIB
#include "SWT_CAN1_AP_SHUTDOWN_State.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_18_0(void);
extern void rtioHook_18_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_SHUTDOWN_State, thread17);

TASK(SWT_CAN1_AP_SHUTDOWN_State)
{
	START_TASK_HOOK(SWT_CAN1_AP_SHUTDOWN_State);

	sgHook(18);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(18);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_SHUTDOWN_State
    XCP_STIM_SWT_CAN1_AP_SHUTDOWN_State
#endif
#endif
	crossbarHook_18_0();
	rtioHook_18_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_SHUTDOWN_State
    XCP_DAQ_SWT_CAN1_AP_SHUTDOWN_State
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_SHUTDOWN_State);

	TerminateTask();
}
