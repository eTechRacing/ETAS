#define NO_OSEKLIB
#include "Timer_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_31_0(void);
extern void crossbarHook_31_1(void);
extern void irt_OneStep_Car_State(void);
extern void crossbarHook_31_2(void);
extern void crossbarHook_31_3(void);
extern void irt_OneStep_Disconnections(void);
extern void crossbarHook_31_4(void);
extern void crossbarHook_31_5(void);
extern void irt_OneStep_Ellipse(void);
extern void crossbarHook_31_6(void);
extern void crossbarHook_31_7(void);
extern void irt_OneStep_Sensors(void);
extern void crossbarHook_31_8(void);
extern void crossbarHook_31_9(void);
extern void irt_OneStep_VDCv2mk2(void);
extern void crossbarHook_31_10(void);
extern void crossbarHook_31_11(void);
extern void irt_OneStep_Power_Control(void);
extern void crossbarHook_31_12(void);
extern void crossbarHook_31_13(void);
extern void rtioHook_31_0(void);


TASK_MONITOR_DEF(Timer_25ms, thread0);

TASK(Timer_25ms)
{
	START_TASK_HOOK(Timer_25ms);

	sgHook(31);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(31);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_25ms
    XCP_STIM_Timer_25ms
#endif
#endif
	crossbarHook_31_0();
	crossbarHook_31_1();
	irt_OneStep_Car_State();
	crossbarHook_31_2();
	crossbarHook_31_3();
	irt_OneStep_Disconnections();
	crossbarHook_31_4();
	crossbarHook_31_5();
	irt_OneStep_Ellipse();
	crossbarHook_31_6();
	crossbarHook_31_7();
	irt_OneStep_Sensors();
	crossbarHook_31_8();
	crossbarHook_31_9();
	irt_OneStep_VDCv2mk2();
	crossbarHook_31_10();
	crossbarHook_31_11();
	irt_OneStep_Power_Control();
	crossbarHook_31_12();
	crossbarHook_31_13();
	rtioHook_31_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_25ms
    XCP_DAQ_Timer_25ms
#endif
#endif
	END_TASK_HOOK(Timer_25ms);

	TerminateTask();
}
