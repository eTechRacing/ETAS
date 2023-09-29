#define NO_OSEKLIB
#include "Timer_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_40_0(void);
extern void crossbarHook_40_1(void);
extern void irt_OneStep_Accel_Data(void);
extern void crossbarHook_40_2(void);
extern void crossbarHook_40_3(void);
extern void irt_OneStep_Car_State(void);
extern void crossbarHook_40_4(void);
extern void crossbarHook_40_5(void);
extern void irt_OneStep_Disconnections(void);
extern void crossbarHook_40_6(void);
extern void crossbarHook_40_7(void);
extern void irt_OneStep_Ellipse(void);
extern void crossbarHook_40_8(void);
extern void crossbarHook_40_9(void);
extern void irt_OneStep_LVD_Data(void);
extern void crossbarHook_40_10(void);
extern void crossbarHook_40_11(void);
extern void irt_OneStep_Pedals_Susp_Sensors(void);
extern void crossbarHook_40_12(void);
extern void crossbarHook_40_13(void);
extern void irt_OneStep_Racing_Mode(void);
extern void crossbarHook_40_14(void);
extern void crossbarHook_40_15(void);
extern void irt_OneStep_SoC(void);
extern void crossbarHook_40_16(void);
extern void crossbarHook_40_17(void);
extern void irt_OneStep_Torque_Control(void);
extern void crossbarHook_40_18(void);
extern void crossbarHook_40_19(void);
extern void rtioHook_40_0(void);


TASK_MONITOR_DEF(Timer_25ms, thread0);

TASK(Timer_25ms)
{
	START_TASK_HOOK(Timer_25ms);

	sgHook(40);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(40);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_25ms
    XCP_STIM_Timer_25ms
#endif
#endif
	crossbarHook_40_0();
	crossbarHook_40_1();
	irt_OneStep_Accel_Data();
	crossbarHook_40_2();
	crossbarHook_40_3();
	irt_OneStep_Car_State();
	crossbarHook_40_4();
	crossbarHook_40_5();
	irt_OneStep_Disconnections();
	crossbarHook_40_6();
	crossbarHook_40_7();
	irt_OneStep_Ellipse();
	crossbarHook_40_8();
	crossbarHook_40_9();
	irt_OneStep_LVD_Data();
	crossbarHook_40_10();
	crossbarHook_40_11();
	irt_OneStep_Pedals_Susp_Sensors();
	crossbarHook_40_12();
	crossbarHook_40_13();
	irt_OneStep_Racing_Mode();
	crossbarHook_40_14();
	crossbarHook_40_15();
	irt_OneStep_SoC();
	crossbarHook_40_16();
	crossbarHook_40_17();
	irt_OneStep_Torque_Control();
	crossbarHook_40_18();
	crossbarHook_40_19();
	rtioHook_40_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_25ms
    XCP_DAQ_Timer_25ms
#endif
#endif
	END_TASK_HOOK(Timer_25ms);

	TerminateTask();
}
