#define NO_OSEKLIB
#include "etasL1Task.h"
#include "../a_basdef.h"

extern void etasL1Process(void);

TASK_MONITOR_DEF(etasL1Task, threadEtasL1Task);

TASK(etasL1Task)
{
	START_TASK_HOOK(etasL1Task);

	etasL1Process();

	END_TASK_HOOK(etasL1Task);

	TerminateTask();
}
