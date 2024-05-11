#define NO_OSEKLIB
#include "etasActivateTaskIsr.h"
#include "..\a_basdef.h"

ISR_MONITOR_DEF(etasActivateTaskIsr, threadEtasIsr);

ISR (etasActivateTaskIsr)
{
	START_ISR_HOOK(etasActivateTaskIsr);

	ETAS_ACTIVATE_TASK();

	END_ISR_HOOK(etasActivateTaskIsr);
}
