#define NO_OSEKLIB
#include "etasStopOsIsr.h"
#include "../a_basdef.h"

ISR_MONITOR_DEF(etasStopOsIsr, threadEtasIsr);

ISR (etasStopOsIsr)
{
	START_ISR_HOOK(etasStopOsIsr);

	ETAS_STOP_OS();

	END_ISR_HOOK(etasStopOsIsr);
}
