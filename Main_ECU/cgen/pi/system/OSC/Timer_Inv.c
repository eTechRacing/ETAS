#define NO_OSEKLIB
#include "Timer_Inv.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_32_0(void);
extern void crossbarHook_32_1(void);
extern void rtioHook_32_0(void);


TASK_MONITOR_DEF(Timer_Inv, thread0);

TASK(Timer_Inv)
{
	START_TASK_HOOK(Timer_Inv);

	sgHook(32);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(32);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_Inv
    XCP_STIM_Timer_Inv
#endif
#endif
	crossbarHook_32_0();
	crossbarHook_32_1();
	rtioHook_32_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_Inv
    XCP_DAQ_Timer_Inv
#endif
#endif
	END_TASK_HOOK(Timer_Inv);

	TerminateTask();
}
