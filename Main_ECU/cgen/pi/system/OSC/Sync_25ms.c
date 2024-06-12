#define NO_OSEKLIB
#include "Sync_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_28_0(void);
extern void crossbarHook_28_1(void);
extern void irt_OneStep_Synchronism(void);
extern void crossbarHook_28_2(void);
extern void crossbarHook_28_3(void);
extern void rtioHook_28_0(void);


TASK_MONITOR_DEF(Sync_25ms, thread0);

TASK(Sync_25ms)
{
	START_TASK_HOOK(Sync_25ms);

	sgHook(28);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(28);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Sync_25ms
    XCP_STIM_Sync_25ms
#endif
#endif
	crossbarHook_28_0();
	crossbarHook_28_1();
	irt_OneStep_Synchronism();
	crossbarHook_28_2();
	crossbarHook_28_3();
	rtioHook_28_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Sync_25ms
    XCP_DAQ_Sync_25ms
#endif
#endif
	END_TASK_HOOK(Sync_25ms);

	TerminateTask();
}
