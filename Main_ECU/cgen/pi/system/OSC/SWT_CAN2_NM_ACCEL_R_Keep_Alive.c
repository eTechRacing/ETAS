#define NO_OSEKLIB
#include "SWT_CAN2_NM_ACCEL_R_Keep_Alive.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_26_0(void);
extern void rtioHook_26_0(void);


TASK_MONITOR_DEF(SWT_CAN2_NM_ACCEL_R_Keep_Alive, thread24);

TASK(SWT_CAN2_NM_ACCEL_R_Keep_Alive)
{
	START_TASK_HOOK(SWT_CAN2_NM_ACCEL_R_Keep_Alive);

	sgHook(26);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(26);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_NM_ACCEL_R_Keep_Alive
    XCP_STIM_SWT_CAN2_NM_ACCEL_R_Keep_Alive
#endif
#endif
	crossbarHook_26_0();
	rtioHook_26_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_NM_ACCEL_R_Keep_Alive
    XCP_DAQ_SWT_CAN2_NM_ACCEL_R_Keep_Alive
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_NM_ACCEL_R_Keep_Alive);

	TerminateTask();
}
