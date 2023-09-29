#define NO_OSEKLIB
#include "Timer_Inv.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_41_0(void);
extern void crossbarHook_41_1(void);
extern void irt_OneStep_Inverters_Action(void);
extern void crossbarHook_41_2(void);
extern void crossbarHook_41_3(void);
extern void irt_OneStep_Inverters_Data(void);
extern void crossbarHook_41_4(void);
extern void crossbarHook_41_5(void);
extern void rtioHook_41_0(void);


TASK_MONITOR_DEF(Timer_Inv, thread0);

TASK(Timer_Inv)
{
	START_TASK_HOOK(Timer_Inv);

	sgHook(41);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(41);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_Inv
    XCP_STIM_Timer_Inv
#endif
#endif
	crossbarHook_41_0();
	crossbarHook_41_1();
	irt_OneStep_Inverters_Action();
	crossbarHook_41_2();
	crossbarHook_41_3();
	irt_OneStep_Inverters_Data();
	crossbarHook_41_4();
	crossbarHook_41_5();
	rtioHook_41_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_Inv
    XCP_DAQ_Timer_Inv
#endif
#endif
	END_TASK_HOOK(Timer_Inv);

	TerminateTask();
}
