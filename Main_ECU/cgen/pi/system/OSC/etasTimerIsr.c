#define NO_OSEKLIB
#include "etasTimerIsr.h"
#include "../a_basdef.h"

ISR_MONITOR_DEF(etasTimerIsr, threadEtasIsr);



ISR (etasTimerIsr)
{
	
	START_ISR_HOOK(etasTimerIsr);

	Tick_etasCounter();
	

	END_ISR_HOOK(etasTimerIsr);
}
