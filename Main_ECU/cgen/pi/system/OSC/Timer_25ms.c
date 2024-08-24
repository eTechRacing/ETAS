#define NO_OSEKLIB
#include "Timer_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_33_0(void);
extern void crossbarHook_33_1(void);
extern void irt_OneStep_Car_State(void);
extern void crossbarHook_33_2(void);
extern void crossbarHook_33_3(void);
extern void irt_OneStep_Disconnections(void);
extern void crossbarHook_33_4(void);
extern void crossbarHook_33_5(void);
extern void irt_OneStep_Ellipse(void);
extern void crossbarHook_33_6(void);
extern void crossbarHook_33_7(void);
extern void irt_OneStep_Power_Control(void);
extern void crossbarHook_33_8(void);
extern void crossbarHook_33_9(void);
extern void irt_OneStep_Sensors(void);
extern void crossbarHook_33_10(void);
extern void crossbarHook_33_11(void);
extern void irt_OneStep_SoC(void);
extern void crossbarHook_33_12(void);
extern void crossbarHook_33_13(void);
extern void irt_OneStep_VDC(void);
extern void crossbarHook_33_14(void);
extern void crossbarHook_33_15(void);
extern void rtioHook_33_0(void);


TASK_MONITOR_DEF(Timer_25ms, thread0);

TASK(Timer_25ms)
{
	START_TASK_HOOK(Timer_25ms);

	sgHook(33);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(33);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_25ms
    XCP_STIM_Timer_25ms
#endif
#endif
	crossbarHook_33_0();
	crossbarHook_33_1();
	irt_OneStep_Car_State();
	crossbarHook_33_2();
	crossbarHook_33_3();
	irt_OneStep_Disconnections();
	crossbarHook_33_4();
	crossbarHook_33_5();
	irt_OneStep_Ellipse();
	crossbarHook_33_6();
	crossbarHook_33_7();
	irt_OneStep_Power_Control();
	crossbarHook_33_8();
	crossbarHook_33_9();
	irt_OneStep_Sensors();
	crossbarHook_33_10();
	crossbarHook_33_11();
	irt_OneStep_SoC();
	crossbarHook_33_12();
	crossbarHook_33_13();
	irt_OneStep_VDC();
	crossbarHook_33_14();
	crossbarHook_33_15();
	rtioHook_33_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_25ms
    XCP_DAQ_Timer_25ms
#endif
#endif
	END_TASK_HOOK(Timer_25ms);

	TerminateTask();
}
