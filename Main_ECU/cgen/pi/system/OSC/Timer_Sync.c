#define NO_OSEKLIB
#include "Timer_Sync.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_33_0(void);
extern void crossbarHook_33_1(void);
extern void irt_OneStep_Synchronism(void);
extern void crossbarHook_33_2(void);
extern void crossbarHook_33_3(void);
extern void rtioHook_33_0(void);


TASK_MONITOR_DEF(Timer_Sync, thread0);

TASK(Timer_Sync)
{
	START_TASK_HOOK(Timer_Sync);

	sgHook(33);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(33);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_Sync
    XCP_STIM_Timer_Sync
#endif
#endif
	crossbarHook_33_0();
	crossbarHook_33_1();
	irt_OneStep_Synchronism();
	crossbarHook_33_2();
	crossbarHook_33_3();
	rtioHook_33_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_Sync
    XCP_DAQ_Timer_Sync
#endif
#endif
	END_TASK_HOOK(Timer_Sync);

	TerminateTask();
}
