#define NO_OSEKLIB
#include "Timer_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_35_0(void);
extern void crossbarHook_35_1(void);
extern void rtioHook_35_0(void);


TASK_MONITOR_DEF(Timer_25ms, thread0);

TASK(Timer_25ms)
{
	START_TASK_HOOK(Timer_25ms);

	sgHook(35);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(35);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_25ms
    XCP_STIM_Timer_25ms
#endif
#endif
	crossbarHook_35_0();
	crossbarHook_35_1();
	rtioHook_35_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_25ms
    XCP_DAQ_Timer_25ms
#endif
#endif
	END_TASK_HOOK(Timer_25ms);

	TerminateTask();
}
