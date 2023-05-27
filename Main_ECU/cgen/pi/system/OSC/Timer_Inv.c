#define NO_OSEKLIB
#include "Timer_Inv.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_33_0(void);
extern void crossbarHook_33_1(void);
extern void irt_OneStep_Inverters_Action(void);
extern void crossbarHook_33_2(void);
extern void crossbarHook_33_3(void);
extern void irt_OneStep_Inverters_Data(void);
extern void crossbarHook_33_4(void);
extern void crossbarHook_33_5(void);
extern void rtioHook_33_0(void);


TASK_MONITOR_DEF(Timer_Inv, thread0);

TASK(Timer_Inv)
{
	START_TASK_HOOK(Timer_Inv);

	sgHook(33);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(33);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_Inv
    XCP_STIM_Timer_Inv
#endif
#endif
	crossbarHook_33_0();
	crossbarHook_33_1();
	irt_OneStep_Inverters_Action();
	crossbarHook_33_2();
	crossbarHook_33_3();
	irt_OneStep_Inverters_Data();
	crossbarHook_33_4();
	crossbarHook_33_5();
	rtioHook_33_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_Inv
    XCP_DAQ_Timer_Inv
#endif
#endif
	END_TASK_HOOK(Timer_Inv);

	TerminateTask();
}