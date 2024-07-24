#define NO_OSEKLIB
#include "Timer_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_32_0(void);
extern void crossbarHook_32_1(void);
extern void irt_OneStep_Car_State(void);
extern void crossbarHook_32_2(void);
extern void crossbarHook_32_3(void);
extern void irt_OneStep_Disconnections(void);
extern void crossbarHook_32_4(void);
extern void crossbarHook_32_5(void);
extern void irt_OneStep_Ellipse(void);
extern void crossbarHook_32_6(void);
extern void crossbarHook_32_7(void);
extern void irt_OneStep_Power_Control(void);
extern void crossbarHook_32_8(void);
extern void crossbarHook_32_9(void);
extern void irt_OneStep_Sensors(void);
extern void crossbarHook_32_10(void);
extern void crossbarHook_32_11(void);
extern void irt_OneStep_VDC(void);
extern void crossbarHook_32_12(void);
extern void crossbarHook_32_13(void);
extern void rtioHook_32_0(void);


TASK_MONITOR_DEF(Timer_25ms, thread0);

TASK(Timer_25ms)
{
	START_TASK_HOOK(Timer_25ms);

	sgHook(32);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(32);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_25ms
    XCP_STIM_Timer_25ms
#endif
#endif
	crossbarHook_32_0();
	crossbarHook_32_1();
	irt_OneStep_Car_State();
	crossbarHook_32_2();
	crossbarHook_32_3();
	irt_OneStep_Disconnections();
	crossbarHook_32_4();
	crossbarHook_32_5();
	irt_OneStep_Ellipse();
	crossbarHook_32_6();
	crossbarHook_32_7();
	irt_OneStep_Power_Control();
	crossbarHook_32_8();
	crossbarHook_32_9();
	irt_OneStep_Sensors();
	crossbarHook_32_10();
	crossbarHook_32_11();
	irt_OneStep_VDC();
	crossbarHook_32_12();
	crossbarHook_32_13();
	rtioHook_32_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_25ms
    XCP_DAQ_Timer_25ms
#endif
#endif
	END_TASK_HOOK(Timer_25ms);

	TerminateTask();
}
