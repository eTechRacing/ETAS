#define NO_OSEKLIB
#include "SWT_CAN1_AP_Inverter_L_Tx.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_16_0(void);
extern void rtioHook_16_0(void);


TASK_MONITOR_DEF(SWT_CAN1_AP_Inverter_L_Tx, thread9);

TASK(SWT_CAN1_AP_Inverter_L_Tx)
{
	START_TASK_HOOK(SWT_CAN1_AP_Inverter_L_Tx);

	sgHook(16);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(16);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN1_AP_Inverter_L_Tx
    XCP_STIM_SWT_CAN1_AP_Inverter_L_Tx
#endif
#endif
	crossbarHook_16_0();
	rtioHook_16_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN1_AP_Inverter_L_Tx
    XCP_DAQ_SWT_CAN1_AP_Inverter_L_Tx
#endif
#endif
	END_TASK_HOOK(SWT_CAN1_AP_Inverter_L_Tx);

	TerminateTask();
}
