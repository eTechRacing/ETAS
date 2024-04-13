#define NO_OSEKLIB
#include "SWT_CAN2_2024_NM_RECU_Keep_Alive.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_29_0(void);
extern void rtioHook_29_0(void);


TASK_MONITOR_DEF(SWT_CAN2_2024_NM_RECU_Keep_Alive, thread27);

TASK(SWT_CAN2_2024_NM_RECU_Keep_Alive)
{
	START_TASK_HOOK(SWT_CAN2_2024_NM_RECU_Keep_Alive);

	sgHook(29);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(29);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_2024_NM_RECU_Keep_Alive
    XCP_STIM_SWT_CAN2_2024_NM_RECU_Keep_Alive
#endif
#endif
	crossbarHook_29_0();
	rtioHook_29_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_2024_NM_RECU_Keep_Alive
    XCP_DAQ_SWT_CAN2_2024_NM_RECU_Keep_Alive
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_2024_NM_RECU_Keep_Alive);

	TerminateTask();
}
