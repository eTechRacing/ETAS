#define NO_OSEKLIB
#include "SWT_CAN1_NM_SHUTDOWN_Keep_Alive.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_18_0(void);
extern void rtioHook_18_0(void);


TASK_MONITOR_DEF(SWT_CAN1_NM_SHUTDOWN_Keep_Alive, thread18);

TASK(SWT_CAN1_NM_SHUTDOWN_Keep_Alive)
{
	START_TASK_HOOK(SWT_CAN1_NM_SHUTDOWN_Keep_Alive);

	sgHook(18);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(18);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_NM_SHUTDOWN_Keep_Alive
    XCP_STIM_SWT_CAN1_NM_SHUTDOWN_Keep_Alive
#endif
#endif
	crossbarHook_18_0();
	rtioHook_18_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_NM_SHUTDOWN_Keep_Alive
    XCP_DAQ_SWT_CAN1_NM_SHUTDOWN_Keep_Alive
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_NM_SHUTDOWN_Keep_Alive);

	TerminateTask();
}
