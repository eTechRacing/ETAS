#define NO_OSEKLIB
#include "SWT_CAN2_2024_MEAS_FECU_SDC.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_25_0(void);
extern void rtioHook_25_0(void);


TASK_MONITOR_DEF(SWT_CAN2_2024_MEAS_FECU_SDC, thread17);

TASK(SWT_CAN2_2024_MEAS_FECU_SDC)
{
	START_TASK_HOOK(SWT_CAN2_2024_MEAS_FECU_SDC);

	sgHook(25);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(25);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_2024_MEAS_FECU_SDC
    XCP_STIM_SWT_CAN2_2024_MEAS_FECU_SDC
#endif
#endif
	crossbarHook_25_0();
	rtioHook_25_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_2024_MEAS_FECU_SDC
    XCP_DAQ_SWT_CAN2_2024_MEAS_FECU_SDC
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_2024_MEAS_FECU_SDC);

	TerminateTask();
}
