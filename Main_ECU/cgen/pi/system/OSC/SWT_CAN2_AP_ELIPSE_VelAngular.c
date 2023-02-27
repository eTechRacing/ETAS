#define NO_OSEKLIB
#include "SWT_CAN2_AP_ELIPSE_VelAngular.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void crossbarHook_27_0(void);


TASK_MONITOR_DEF(SWT_CAN2_AP_ELIPSE_VelAngular, thread29);

TASK(SWT_CAN2_AP_ELIPSE_VelAngular)
{
	START_TASK_HOOK(SWT_CAN2_AP_ELIPSE_VelAngular);

	sgHook(27);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(27);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_SWT_CAN2_AP_ELIPSE_VelAngular
    XCP_STIM_SWT_CAN2_AP_ELIPSE_VelAngular
#endif
#endif
	crossbarHook_27_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_SWT_CAN2_AP_ELIPSE_VelAngular
    XCP_DAQ_SWT_CAN2_AP_ELIPSE_VelAngular
#endif
#endif
	END_TASK_HOOK(SWT_CAN2_AP_ELIPSE_VelAngular);

	TerminateTask();
}
