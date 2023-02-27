#define NO_OSEKLIB
#include "Sync_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_34_0(void);
extern void crossbarHook_34_3(void);
extern void rtioHook_34_0(void);
extern void crossbarHook_34_1(void);
extern void irt_OneStep_Synchronism_ETR07(void);
extern void crossbarHook_34_2(void);
extern void crossbarHook_34_4(void);
extern void rtioHook_34_1(void);


TASK_MONITOR_DEF(Sync_25ms, thread0);

TASK(Sync_25ms)
{
	START_TASK_HOOK(Sync_25ms);

	sgHook(34);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(34);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Sync_25ms
    XCP_STIM_Sync_25ms
#endif
#endif
	crossbarHook_34_0();
	crossbarHook_34_3();
	rtioHook_34_0();
	crossbarHook_34_1();
	irt_OneStep_Synchronism_ETR07();
	crossbarHook_34_2();
	crossbarHook_34_4();
	rtioHook_34_1();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Sync_25ms
    XCP_DAQ_Sync_25ms
#endif
#endif
	END_TASK_HOOK(Sync_25ms);

	TerminateTask();
}
