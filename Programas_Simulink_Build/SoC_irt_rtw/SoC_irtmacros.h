/*
 * File    : SoC_irtmacros.h
 *
 * Abstract:
 *      This file provide some ETAS specific defines
 */

/* The simulink assert is mapped to an debug output */
extern void asdWriteUserDebug(char *s, ...);
extern void asdWriteUserError(char *s, ...);

#ifndef utAssert
#define utAssert(_exp)                 if(!(_exp)){ asdWriteUserDebug("IRT RTI: ** Simulink assertblock shows assertion failed. The expression was: '" #_exp "' **\n"); rtmSetStopRequestedFlag(SoC_M, 1); asdWriteUserDebug("IRT RTI: ** Simulation halted! **\n");}
#endif

/* EOF: SoC_irtmacros.h */
