#define NO_OSEKLIB
#include "SWT_CAN2_MEAS_RECU_SDC.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_26_0(void);
extern void rtioHook_26_0(void);


TASK_MONITOR_DEF(SWT_CAN2_MEAS_RECU_SDC, thread16);

TASK(SWT_CAN2_MEAS_RECU_SDC)
{
	START_TASK_HOOK(SWT_CAN2_MEAS_RECU_SDC);

	sgHook(26);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(26);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_MEAS_RECU_SDC
    XCP_STIM_SWT_CAN2_MEAS_RECU_SDC
#endif
#endif
	crossbarHook_26_0();
	rtioHook_26_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_MEAS_RECU_SDC
    XCP_DAQ_SWT_CAN2_MEAS_RECU_SDC
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_MEAS_RECU_SDC);

	TerminateTask();
}
