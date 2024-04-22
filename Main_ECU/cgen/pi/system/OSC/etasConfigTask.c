#define NO_OSEKLIB
#include "etasConfigTask.h"
#include "../a_basdef.h"
#include "osc_dyn.h"

extern void rtioHook_0_0(void);


TASK_MONITOR_DEF(etasConfigTask, threadEtasConfigTask);

TASK(etasConfigTask)
{
	START_TASK_HOOK(etasConfigTask);

	sgHook(0);

#ifdef FEATURE_LABCAR_SG
    labcar_sgHook(0);
#endif
    
#ifdef XCP_SLAVE
#if defined XCP_STIM_etasConfigTask
    XCP_STIM_etasConfigTask
#endif
#endif
	rtioHook_0_0();
	
#ifdef XCP_SLAVE
#if defined XCP_DAQ_etasConfigTask
    XCP_DAQ_etasConfigTask
#endif
#endif
	END_TASK_HOOK(etasConfigTask);

	TerminateTask();
}
