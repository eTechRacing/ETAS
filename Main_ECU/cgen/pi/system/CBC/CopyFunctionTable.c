/* Default includes */
#include "..\a_basdef.h"

copyFuncTableEntry crossbarCopyFuncTable[14] ={
	&copyPlainToFloat,
	&copySatToFloat,
	&copyScalToFloat,
	&copyScalSatToFloat,
	&copyPlainFromFloat,
	&copySatFromFloat,
	&copyScalFromFloat,
	&copyScalSatFromFloat,
	&copyBoolSatFromFloat,
	&copyByte,
	&copyShort,
	&copyInt,
	&copyDouble,
	&copyScalFromValidFloat
};
