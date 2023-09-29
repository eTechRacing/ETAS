#define NO_OSEKLIB
#include "Timer_100ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_39_0(void);
extern void crossbarHook_39_1(void);
extern void rtioHook_39_0(void);


TASK_MONITOR_DEF(Timer_100ms, thread0);

TASK(Timer_100ms)
{
	START_TASK_HOOK(Timer_100ms);

	sgHook(39);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(39);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_100ms
    XCP_STIM_Timer_100ms
#endif
#endif
	crossbarHook_39_0();
	crossbarHook_39_1();
	rtioHook_39_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_100ms
    XCP_DAQ_Timer_100ms
#endif
#endif
	END_TASK_HOOK(Timer_100ms);

	TerminateTask();
}