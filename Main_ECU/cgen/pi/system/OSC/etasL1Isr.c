#define NO_OSEKLIB
#include "etasL1Isr.h"
#include "../a_basdef.h"

ISR_MONITOR_DEF(etasL1Isr, threadEtasIsr);

ISR (etasL1Isr)
{
	START_ISR_HOOK(etasL1Isr);

	ActivateTask(etasL1Task);

	END_ISR_HOOK(etasL1Isr);
}
