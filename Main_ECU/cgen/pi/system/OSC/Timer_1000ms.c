#define NO_OSEKLIB
#include "Timer_1000ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_29_0(void);
extern void crossbarHook_29_1(void);
extern void rtioHook_29_0(void);


TASK_MONITOR_DEF(Timer_1000ms, thread0);

TASK(Timer_1000ms)
{
	START_TASK_HOOK(Timer_1000ms);

	sgHook(29);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(29);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_1000ms
    XCP_STIM_Timer_1000ms
#endif
#endif
	crossbarHook_29_0();
	crossbarHook_29_1();
	rtioHook_29_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_1000ms
    XCP_DAQ_Timer_1000ms
#endif
#endif
	END_TASK_HOOK(Timer_1000ms);

	TerminateTask();
}
