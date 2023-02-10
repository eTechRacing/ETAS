#define NO_OSEKLIB
#include "Timer_Inv.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_38_0(void);
extern void crossbarHook_38_1(void);
extern void irt_OneStep_inverters_action_ETR07(void);
extern void crossbarHook_38_2(void);
extern void crossbarHook_38_3(void);
extern void irt_OneStep_Inverters_Data_ETR07(void);
extern void crossbarHook_38_4(void);
extern void crossbarHook_38_5(void);
extern void rtioHook_38_0(void);


TASK_MONITOR_DEF(Timer_Inv, thread0);

TASK(Timer_Inv)
{
	START_TASK_HOOK(Timer_Inv);

	sgHook(38);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(38);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_Inv
    XCP_STIM_Timer_Inv
#endif
#endif
	crossbarHook_38_0();
	crossbarHook_38_1();
	irt_OneStep_inverters_action_ETR07();
	crossbarHook_38_2();
	crossbarHook_38_3();
	irt_OneStep_Inverters_Data_ETR07();
	crossbarHook_38_4();
	crossbarHook_38_5();
	rtioHook_38_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_Inv
    XCP_DAQ_Timer_Inv
#endif
#endif
	END_TASK_HOOK(Timer_Inv);

	TerminateTask();
}
