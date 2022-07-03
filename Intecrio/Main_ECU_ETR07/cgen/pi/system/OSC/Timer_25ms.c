#define NO_OSEKLIB
#include "Timer_25ms.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_37_0(void);
extern void crossbarHook_37_13(void);
extern void rtioHook_37_0(void);
extern void crossbarHook_37_1(void);
extern void irt_OneStep_Racing_Mode_ETR07(void);
extern void crossbarHook_37_2(void);
extern void crossbarHook_37_3(void);
extern void irt_OneStep_Torque_Control_ETR07(void);
extern void crossbarHook_37_4(void);
extern void crossbarHook_37_5(void);
extern void irt_OneStep_Disconnections_ETR07(void);
extern void crossbarHook_37_6(void);
extern void crossbarHook_37_7(void);
extern void irt_OneStep_Accel_Data_ETR07(void);
extern void crossbarHook_37_8(void);
extern void crossbarHook_37_9(void);
extern void irt_OneStep_Car_State_ETR07(void);
extern void crossbarHook_37_10(void);
extern void crossbarHook_37_11(void);
extern void irt_OneStep_Pedals_Susp_Sensors_ETR07(void);
extern void crossbarHook_37_12(void);
extern void crossbarHook_37_14(void);
extern void rtioHook_37_1(void);


TASK_MONITOR_DEF(Timer_25ms, thread0);

TASK(Timer_25ms)
{
	START_TASK_HOOK(Timer_25ms);

	sgHook(37);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(37);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_Timer_25ms
    XCP_STIM_Timer_25ms
#endif
#endif
	crossbarHook_37_0();
	crossbarHook_37_13();
	rtioHook_37_0();
	crossbarHook_37_1();
	irt_OneStep_Racing_Mode_ETR07();
	crossbarHook_37_2();
	crossbarHook_37_3();
	irt_OneStep_Torque_Control_ETR07();
	crossbarHook_37_4();
	crossbarHook_37_5();
	irt_OneStep_Disconnections_ETR07();
	crossbarHook_37_6();
	crossbarHook_37_7();
	irt_OneStep_Accel_Data_ETR07();
	crossbarHook_37_8();
	crossbarHook_37_9();
	irt_OneStep_Car_State_ETR07();
	crossbarHook_37_10();
	crossbarHook_37_11();
	irt_OneStep_Pedals_Susp_Sensors_ETR07();
	crossbarHook_37_12();
	crossbarHook_37_14();
	rtioHook_37_1();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_Timer_25ms
    XCP_DAQ_Timer_25ms
#endif
#endif
	END_TASK_HOOK(Timer_25ms);

	TerminateTask();
}
