/* Patched in by the INTECRIO IRT target */
/* PATCH BEGIN */
#include "Torque_Control_ETR07_irtmacros.h"
/* PATCH END */

/*
 * Torque_Control_ETR07.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control_ETR07".
 *
 * Model version              : 1.21
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sat Jun 18 14:41:15 2022
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_Control_ETR07_h_
#define RTW_HEADER_Torque_Control_ETR07_h_
#include <math.h>
#include <string.h>
#ifndef Torque_Control_ETR07_COMMON_INCLUDES_
# define Torque_Control_ETR07_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* Torque_Control_ETR07_COMMON_INCLUDES_ */

#include "Torque_Control_ETR07_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVDRMdlRefTiming
# define rtmGetVDRMdlRefTiming(rtm)    ()
#endif

#ifndef rtmSetVDRMdlRefTiming
# define rtmSetVDRMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetVDRMdlRefTimingPtr
# define rtmGetVDRMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetVDRMdlRefTimingPtr
# define rtmSetVDRMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetVDRNumTicksToNextHit
# define rtmGetVDRNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetVDRNumTicksToNextHit
# define rtmSetVDRNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Torque_Control_ETR07_rtModel   RT_MODEL_Torque_Control_ETR07_T

/* Block signals for system '<S107>/minimum value' */
typedef struct {
  real_T min;                          /* '<S107>/minimum value' */
} B_minimumvalue_Torque_Control_T;

/* Block signals for system '<S107>/minimum value1' */
typedef struct {
  real_T min;                          /* '<S107>/minimum value1' */
} B_minimumvalue1_Torque_Contro_T;

/* Block signals for system '<S97>/Accelerator behaviour ' */
typedef struct {
  real_T throttle;                     /* '<S97>/Accelerator behaviour ' */
} B_Acceleratorbehaviour_Torque_T;

/* Block signals for system '<S68>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S68>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Cont_T;

/* Block signals for system '<S104>/MATLAB Function' */
typedef struct {
  real_T RPM;                          /* '<S104>/MATLAB Function' */
} B_MATLABFunction_Torque_Contr_T;

/* Block signals for system '<S150>/MATLAB Function' */
typedef struct {
  real_T SKF_act1;                     /* '<S150>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_d_T;

/* Block signals for system '<S149>/MATLAB Function' */
typedef struct {
  real_T SKF_act0;                     /* '<S149>/MATLAB Function' */
} B_MATLABFunction_Torque_Co_ds_T;

/* Block signals for system '<S146>/MATLAB Function' */
typedef struct {
  real_T CKF_act1;                     /* '<S146>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_k_T;

/* Block signals for system '<S142>/Spin ' */
typedef struct {
  real_T Constant;                     /* '<S146>/Constant' */
  B_MATLABFunction_Torque_Con_k_T sf_MATLABFunction;/* '<S146>/MATLAB Function' */
} B_Spin_Torque_Control_ETR07_T;

/* Block signals for system '<S145>/MATLAB Function' */
typedef struct {
  real_T CKF_act0;                     /* '<S145>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_n_T;

/* Block signals for system '<S142>/No spin' */
typedef struct {
  B_MATLABFunction_Torque_Con_n_T sf_MATLABFunction;/* '<S145>/MATLAB Function' */
} B_Nospin_Torque_Control_ETR07_T;

/* Block signals for system '<S101>/MATLAB Function' */
typedef struct {
  real_T value;                        /* '<S101>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_h_T;

/* Block signals for system '<S106>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S106>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_d_T;

/* Block signals (auto storage) */
typedef struct {
  real_T kamm_data[544];
  real_T Merge5;                       /* '<S30>/Merge5' */
  real_T Constant;                     /* '<S31>/Constant' */
  real_T Constant_h;                   /* '<Root>/Constant' */
  real_T Constant_l;                   /* '<S7>/Constant' */
  real_T Constant_n;                   /* '<S25>/Constant' */
  real_T Constant_i;                   /* '<S24>/Constant' */
  real_T Abs;                          /* '<S7>/Abs' */
  real_T Constant_m;                   /* '<S197>/Constant' */
  real_T Merge;                        /* '<S53>/Merge' */
  real_T Merge1;                       /* '<S53>/Merge1' */
  real_T Merge2;                       /* '<S53>/Merge2' */
  real_T Merge3;                       /* '<S53>/Merge3' */
  real_T BRAKE_THRESHOLD;              /* '<S52>/BRAKE_THRESHOLD' */
  real_T Zero;                         /* '<S52>/Zero ' */
  real_T Merge_d;                      /* '<S52>/Merge' */
  real_T Constant_o;                   /* '<S52>/Constant' */
  real_T Merge1_a;                     /* '<S52>/Merge1' */
  real_T Merge_h;                      /* '<S58>/Merge' */
  real_T LimitTemperatureIGBTC;        /* '<S54>/Limit Temperature IGBT [ºC]' */
  real_T LimitTemperatureMotorC;       /* '<S54>/Limit Temperature Motor [ºC]' */
  real_T LimitTemperatureCeldasC;      /* '<S54>/Limit Temperature Celdas[ºC]' */
  real_T Gain;                         /* '<S54>/Gain' */
  real_T SteeringWheelSaturationpersited;/* '<S54>/Steering Wheel Saturation (per site) [deg] ' */
  real_T Merge_c;                      /* '<S54>/Merge' */
  real_T Merge1_m;                     /* '<S54>/Merge1' */
  real_T Merge2_l;                     /* '<S54>/Merge2' */
  real_T Merge3_c;                     /* '<S54>/Merge3' */
  real_T Torque_RLNm;                  /* '<S66>/Torque_RL [Nm]' */
  real_T Torque_RRNm;                  /* '<S66>/Torque_RR [Nm]' */
  real_T SteeringWheelMaximumAngle;    /* '<S84>/Steering Wheel Maximum Angle' */
  real_T SteeringWheelMaximumAngle_m;  /* '<S67>/Steering Wheel Maximum Angle' */
  real_T Tq_maxNm;                     /* '<S67>/Tq_max [Nm]' */
  real_T Tq_diff_maxNm;                /* '<S67>/Tq_diff_max [Nm]' */
  real_T Merge_k;                      /* '<S85>/Merge' */
  real_T Saturation;                   /* '<S85>/Saturation' */
  real_T Constant_ob;                  /* '<S89>/Constant' */
  real_T Merge_kj;                     /* '<S87>/Merge' */
  real_T Saturation_k;                 /* '<S87>/Saturation' */
  real_T Constant_d;                   /* '<S93>/Constant' */
  real_T Merge_g;                      /* '<S187>/Merge' */
  real_T MaximumTorqueperengineNm;     /* '<S159>/Maximum Torque per engine [Nm]' */
  real_T MaximumTransmissionTorqueDynami;/* '<S159>/Maximum Transmission Torque Dynamic [Nm]' */
  real_T MaximumTransmissionTorqueStatic;/* '<S159>/Maximum Transmission Torque Static [Nm]' */
  real_T Constant_e;                   /* '<S164>/Constant' */
  real_T Constant1;                    /* '<S160>/Constant1' */
  real_T udifference;                  /* '<S159>/3% difference' */
  real_T TransmisionRatio;             /* '<S159>/Transmision Ratio[-]' */
  real_T Constant1_k;                  /* '<S164>/Constant1' */
  real_T Constant_dd;                  /* '<S160>/Constant' */
  real_T Merge_l;                      /* '<S158>/Merge' */
  real_T Merge1_l;                     /* '<S158>/Merge1' */
  real_T approx2095;                   /* '<S165>/Gain' */
  real_T Merge2_o;                     /* '<S165>/Merge2' */
  real_T SteeringWheelMaximumAngle_p;  /* '<S141>/Steering Wheel Maximum Angle' */
  real_T Constant_p;                   /* '<S68>/Constant' */
  real_T MaximumTorqueperengineNm_m;   /* '<S99>/Maximum Torque per engine [Nm]' */
  real_T MaximumTransmissionTorqueDyna_b;/* '<S99>/Maximum Transmission Torque Dynamic [Nm]' */
  real_T MaximumTransmissionTorqueStat_b;/* '<S99>/Maximum Transmission Torque Static [Nm]' */
  real_T Constant1_i;                  /* '<S106>/Constant1' */
  real_T Constant1_j;                  /* '<S99>/Constant1' */
  real_T Merge2_lx;                    /* '<S68>/Merge2' */
  real_T udifference_l;                /* '<S99>/3% difference' */
  real_T TransmisionRatio_b;           /* '<S99>/Transmision Ratio[-]' */
  real_T Divide;                       /* '<S154>/Divide' */
  real_T Constant_b;                   /* '<S106>/Constant' */
  real_T Merge3_e;                     /* '<S68>/Merge3' */
  real_T Divide_i;                     /* '<S153>/Divide' */
  real_T Tq_diff_Max;                  /* '<S99>/Tq_diff_Max' */
  real_T Merge_kt;                     /* '<S97>/Merge' */
  real_T Merge1_b;                     /* '<S97>/Merge1' */
  real_T Merge_m;                      /* '<S68>/Merge' */
  real_T Merge1_n;                     /* '<S68>/Merge1' */
  real_T Merge4;                       /* '<S68>/Merge4' */
  real_T Merge5_e;                     /* '<S68>/Merge5' */
  real_T Merge6;                       /* '<S68>/Merge6' */
  real_T Merge7;                       /* '<S68>/Merge7' */
  real_T OutportBufferForFlags_num5[5];/* '<S68>/Flags' */
  real_T Constant3;                    /* '<S100>/Constant3' */
  real_T Constant4;                    /* '<S100>/Constant4' */
  real_T Steering_Ratio;               /* '<S130>/Steering_Ratio [-]' */
  real_T Constant8;                    /* '<S130>/Constant8' */
  real_T Constant7;                    /* '<S130>/Constant7' */
  real_T Wheelbasem;                   /* '<S130>/Wheelbase [m]' */
  real_T u602pi;                       /* '<S130>/360//(2*pi)' */
  real_T u602pi_e;                     /* '<S130>/360//(2pi)' */
  real_T Yaw_Inertiakgm3;              /* '<S100>/Yaw_Inertia [kg//m^3]' */
  real_T Divide1;                      /* '<S132>/Divide1' */
  real_T Constant_mf;                  /* '<S101>/Constant' */
  real_T Constant3_e;                  /* '<S101>/Constant3' */
  real_T Constant4_m;                  /* '<S101>/Constant4' */
  real_T Merge_cu;                     /* '<S142>/Merge' */
  real_T Saturation_i;                 /* '<S142>/Saturation' */
  real_T Merge_i;                      /* '<S144>/Merge' */
  real_T Saturation_f;                 /* '<S144>/Saturation' */
  real_T Constant_k;                   /* '<S150>/Constant' */
  real_T Throttle;                     /* '<S120>/Throttle' */
  real_T approx2095_h;                 /* '<S107>/Gain' */
  real_T Merge2_j;                     /* '<S107>/Merge2' */
  real_T Merge3_h;                     /* '<S107>/Merge3' */
  real_T Merge4_b;                     /* '<S107>/Merge4' */
  real_T exptcycletau1;                /* '<S41>/exp(-tcycle//tau)1' */
  real_T Subtract;                     /* '<S41>/Subtract' */
  real_T A1;                           /* '<S15>/A1' */
  real_T C1;                           /* '<S15>/C1' */
  real_T B1;                           /* '<S15>/B1' */
  real_T Zero_p;                       /* '<S15>/Zero' */
  real_T A;                            /* '<S14>/A' */
  real_T C;                            /* '<S14>/C' */
  real_T B;                            /* '<S14>/B' */
  real_T Zero_m;                       /* '<S14>/Zero' */
  real_T Merge_a;                      /* '<S14>/Merge' */
  real_T Merge1_a0;                    /* '<Root>/Merge1' */
  real_T Merge2_e;                     /* '<Root>/Merge2' */
  real_T Merge1_k;                     /* '<S58>/Merge1' */
  real_T Merge1_i;                     /* '<S15>/Merge1' */
  real_T Merge2_g;                     /* '<S15>/Merge2' */
  real_T Merge1_lz;                    /* '<S14>/Merge1' */
  real_T Merge2_b;                     /* '<S14>/Merge2' */
  boolean_T LogicalOperator1;          /* '<S30>/Logical Operator1' */
  boolean_T Merge_j;                   /* '<S29>/Merge' */
  boolean_T LogicalOperator;           /* '<S5>/Logical Operator' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_o;/* '<S70>/Accelerator behaviour ' */
  B_MATLABFunction_Torque_Con_n_T sf_MATLABFunction_k2;/* '<S88>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_k_T sf_MATLABFunction_k;/* '<S89>/MATLAB Function' */
  B_MATLABFunction_Torque_Co_ds_T sf_MATLABFunction_fq;/* '<S92>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_p;/* '<S93>/MATLAB Function' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction_a;/* '<S77>/MATLAB Function' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_f;/* '<S72>/Accelerator behaviour ' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_m;/* '<S164>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_gm;/* '<S164>/MATLAB Function1' */
  B_Nospin_Torque_Control_ETR07_T Nospin_m;/* '<S187>/No spin' */
  B_Spin_Torque_Control_ETR07_T Spin_nb;/* '<S187>/Spin ' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction_fa;/* '<S162>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_b;/* '<S160>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_f;/* '<S160>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_b;/* '<S177>/Accelerator behaviour ' */
  B_minimumvalue1_Torque_Contro_T sf_minimumvalue1_k;/* '<S165>/minimum value1' */
  B_minimumvalue_Torque_Control_T sf_minimumvalue_o;/* '<S165>/minimum value' */
  B_MATLABFunction1_Torque_Co_d_T sf_MATLABFunction2;/* '<S106>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Co_d_T sf_MATLABFunction1_m;/* '<S106>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_e;/* '<S100>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_mk;/* '<S100>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_g;/* '<S101>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction_d1;/* '<S101>/MATLAB Function' */
  B_Nospin_Torque_Control_ETR07_T Nospin_k;/* '<S142>/No spin' */
  B_Spin_Torque_Control_ETR07_T Spin_n;/* '<S142>/Spin ' */
  B_MATLABFunction_Torque_Co_ds_T sf_MATLABFunction_d;/* '<S149>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_m;/* '<S150>/MATLAB Function' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction;/* '<S104>/MATLAB Function' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction2_l;/* '<S68>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction1_n;/* '<S68>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour;/* '<S97>/Accelerator behaviour ' */
  B_minimumvalue1_Torque_Contro_T sf_minimumvalue1;/* '<S107>/minimum value1' */
  B_minimumvalue_Torque_Control_T sf_minimumvalue;/* '<S107>/minimum value' */
} B_Torque_Control_ETR07_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T R;                            /* '<S52>/Data Store Memory' */
  real_T TimeStampA;                   /* '<S77>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S77>/Derivative' */
  real_T TimeStampB;                   /* '<S77>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S77>/Derivative' */
  real_T A;                            /* '<S77>/Data Store Memory' */
  real_T B;                            /* '<S77>/Data Store Memory1' */
  real_T TimeStampA_b;                 /* '<S162>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<S162>/Derivative' */
  real_T TimeStampB_e;                 /* '<S162>/Derivative' */
  real_T LastUAtTimeB_o;               /* '<S162>/Derivative' */
  real_T B_k;                          /* '<S162>/Data Store Memory1' */
  real_T TimeStampA_g;                 /* '<S104>/Derivative' */
  real_T LastUAtTimeA_c;               /* '<S104>/Derivative' */
  real_T TimeStampB_c;                 /* '<S104>/Derivative' */
  real_T LastUAtTimeB_f;               /* '<S104>/Derivative' */
  real_T A_b;                          /* '<S104>/Data Store Memory' */
  real_T B_i;                          /* '<S104>/Data Store Memory1' */
  real_T Previous_IN;                  /* '<S41>/Data Store Memory' */
  real_T Previous_OUT;                 /* '<S41>/Data Store Memory1' */
  real_T A_i;                          /* '<S9>/Data Store Memory10' */
  int8_T If2_ActiveSubsystem;          /* '<S30>/If2' */
  int8_T If3_ActiveSubsystem;          /* '<S30>/If3' */
  int8_T MEMO1_ActiveSubsystem;        /* '<S30>/MEMO1' */
  int8_T If_ActiveSubsystem;           /* '<S29>/If' */
  int8_T If_ActiveSubsystem_k;         /* '<S7>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S4>/If' */
  int8_T If1_ActiveSubsystem;          /* '<Root>/If1' */
  int8_T If_ActiveSubsystem_e;         /* '<S55>/If' */
  int8_T If_ActiveSubsystem_a;         /* '<S53>/If' */
  int8_T If1_ActiveSubsystem_b;        /* '<S52>/If1' */
  int8_T If_ActiveSubsystem_o;         /* '<S52>/If' */
  int8_T If1_ActiveSubsystem_i;        /* '<S58>/If1' */
  int8_T If_ActiveSubsystem_i;         /* '<S58>/If' */
  int8_T FAILUREMODE_ActiveSubsystem;  /* '<S54>/FAILURE MODE' */
  int8_T SKForCKF_ActiveSubsystem;     /* '<S84>/SKF or CKF' */
  int8_T If_ActiveSubsystem_ds;        /* '<S67>/If' */
  int8_T If_ActiveSubsystem_b;         /* '<S73>/If' */
  int8_T If1_ActiveSubsystem_c;        /* '<S85>/If1' */
  int8_T If_ActiveSubsystem_j;         /* '<S87>/If' */
  int8_T If1_ActiveSubsystem_a;        /* '<S187>/If1' */
  int8_T BrakingConditions_ActiveSubsyst;/* '<S158>/Braking Conditions' */
  int8_T If_ActiveSubsystem_h;         /* '<S157>/If' */
  int8_T If1_ActiveSubsystem_bf;       /* '<S165>/If1' */
  int8_T If2_ActiveSubsystem_i;        /* '<S165>/If2' */
  int8_T SKForCKF_ActiveSubsystem_o;   /* '<S141>/SKF or CKF' */
  int8_T Steer_angisinSteer_SatrangeLong;/* '<S68>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  int8_T BrakingConditions_ActiveSubsy_b;/* '<S97>/Braking Conditions' */
  int8_T If_ActiveSubsystem_aq;        /* '<S96>/If' */
  int8_T If1_ActiveSubsystem_o;        /* '<S142>/If1' */
  int8_T If_ActiveSubsystem_ha;        /* '<S144>/If' */
  int8_T If1_ActiveSubsystem_bn;       /* '<S107>/If1' */
  int8_T If_ActiveSubsystem_f;         /* '<S107>/If' */
  int8_T If1_ActiveSubsystem_k;        /* '<S15>/If1' */
  int8_T If_ActiveSubsystem_p;         /* '<S15>/If' */
  int8_T If1_ActiveSubsystem_n;        /* '<S14>/If1' */
  int8_T If_ActiveSubsystem_k2;        /* '<S14>/If' */
  boolean_T AA;                        /* '<S30>/Data Store Memory1' */
} DW_Torque_Control_ETR07_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S100>/Integrator' */
} X_Torque_Control_ETR07_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S100>/Integrator' */
} XDot_Torque_Control_ETR07_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S100>/Integrator' */
} XDis_Torque_Control_ETR07_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T VDC_SKF_Initial;              /* '<Root>/VDC_SKF_Initial' */
  real_T VDC_CKF_Initial;              /* '<Root>/VDC_CKF_Initial' */
  real_T VDC_Cte_SKF;                  /* '<Root>/VDC_Cte_SKF' */
  real_T VDC_Cte_CKF;                  /* '<Root>/VDC_Cte_CKF' */
  real_T VDC_Apps_Sat_Down;            /* '<Root>/VDC_Apps_Sat_Down' */
  real_T VDC_Apps_Sat_Up;              /* '<Root>/VDC_Apps_Sat_Up' */
  real_T VDC_Max_Regenerative_Torque;  /* '<Root>/VDC_Max_Regenerative_Torque' */
  real_T VDC_Power_Limit;              /* '<Root>/VDC_Power_Limit' */
  real_T VDC_K_Reduction_P;            /* '<Root>/VDC_K_Reduction_P' */
  real_T VDC_K_Reduction_Temperature;  /* '<Root>/VDC_K_Reduction_Temperature' */
  real_T Workshop_Mode_Enable;         /* '<Root>/Workshop_Mode_Enable' */
  boolean_T TorqueEnable;              /* '<Root>/TorqueEnable' */
  real_T TV_Mode;                      /* '<Root>/TV_Mode' */
  real_T SteeringSensor_Bits;          /* '<Root>/SteeringSensor_Bits' */
  real_T Highest_CellTemp;             /* '<Root>/Highest_CellTemp' */
  boolean_T CriticalDisconnection;     /* '<Root>/CriticalDisconnection' */
  boolean_T ShutdownClosed;            /* '<Root>/ShutdownClosed' */
  real_T ACCEL_R_X_SI;                 /* '<Root>/ACCEL_R_X_SI' */
  real_T ACCEL_R_Y_SI;                 /* '<Root>/ACCEL_R_Y_SI' */
  real_T ACCEL_R_Z_SI;                 /* '<Root>/ACCEL_R_Z_SI' */
  real_T ACCEL_F_X_SI;                 /* '<Root>/ACCEL_F_X_SI' */
  real_T ACCEL_F_Y_SI;                 /* '<Root>/ACCEL_F_Y_SI' */
  real_T ACCEL_F_Z_SI;                 /* '<Root>/ACCEL_F_Z_SI' */
  real_T Accumulator_Voltage;          /* '<Root>/Accumulator_Voltage' */
  real_T Accumulator_Current;          /* '<Root>/Accumulator_Current' */
  real_T APPS2_Value;                  /* '<Root>/APPS2_Value' */
  real_T APPS1_Value;                  /* '<Root>/APPS1_Value' */
  real_T BrakeSensor_Value;            /* '<Root>/BrakeSensor_Value' */
  real_T Susp_F_L;                     /* '<Root>/Susp_F_L' */
  real_T Susp_F_R;                     /* '<Root>/Susp_F_R' */
  real_T Susp_R_L;                     /* '<Root>/Susp_R_L' */
  real_T Susp_R_R;                     /* '<Root>/Susp_R_R' */
  real_T Vel_RL_kmh;                   /* '<Root>/Vel_RL_kmh' */
  real_T Vel_RR_kmh;                   /* '<Root>/Vel_RR_kmh' */
  real_T RL_rads;                      /* '<Root>/RL_rads' */
  real_T RR_rads;                      /* '<Root>/RR_rads' */
  real_T Temp_Motors;                  /* '<Root>/Temp_Motors' */
  real_T Temp_IGBT;                    /* '<Root>/Temp_IGBT' */
  real_T Gyro_F_Z_Deg;                 /* '<Root>/Gyro_F_Z_Deg' */
  real_T Car_State;                    /* '<Root>/Car_State' */
} ExtU_Torque_Control_ETR07_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Torque_RRwc;                  /* '<Root>/Torque_RRwc' */
  real_T Torque_RLwc;                  /* '<Root>/Torque_RLwc' */
  real_T Max_Torque_RR;                /* '<Root>/Max_Torque_RR' */
  real_T Max_Torque_RL;                /* '<Root>/Max_Torque_RL' */
  real_T Max_Fx_RR;                    /* '<Root>/Max_Fx_RR' */
  real_T Max_Fx_RL;                    /* '<Root>/Max_Fx_RL' */
  real_T Throttle;                     /* '<Root>/Throttle' */
  real_T Fy_R;                         /* '<Root>/Fy_R' */
  real_T Mass;                         /* '<Root>/Mass' */
  real_T Handling;                     /* '<Root>/Handling' */
  real_T SKF_actual;                   /* '<Root>/SKF_actual' */
  real_T CKF_actual;                   /* '<Root>/CKF_actual' */
  real_T SteeringSensor_Value;         /* '<Root>/SteeringSensor_Value' */
  boolean_T APPS_Implausibility;       /* '<Root>/APPS_Implausibility' */
  boolean_T Brake_Implausibility;      /* '<Root>/Brake_Implausibility' */
  real_T TV_Flag_WheelSpinRR;          /* '<Root>/TV_Flag_WheelSpinRR' */
  real_T TV_Flag_WheelSpinRL;          /* '<Root>/TV_Flag_WheelSpinRL' */
  real_T TV_Flag_Temperature;          /* '<Root>/TV_Flag_Temperature' */
  real_T TV_Flag_Power;                /* '<Root>/TV_Flag_Power' */
  real_T TV_Flag_CarBehaviour;         /* '<Root>/TV_Flag_CarBehaviour' */
  real_T Power;                        /* '<Root>/Power' */
  real_T PowerLimitReached;            /* '<Root>/PowerLimitReached' */
  real_T PowerMean500ms;               /* '<Root>/PowerMean500ms' */
  boolean_T Torque_OK;                 /* '<Root>/Torque_OK' */
  real_T Regenerative_Enable;          /* '<Root>/Regenerative_Enable' */
  real_T Dash_Speed;                   /* '<Root>/Dash_Speed' */
  real_T Pumps_Control;                /* '<Root>/Pumps_Control' */
  real_T MeasVDCTorque_L;              /* '<Root>/Meas VDC Torque_L' */
  real_T MeasVDCTorque_R;              /* '<Root>/Meas VDC Torque_R' */
  real_T Torque_L;                     /* '<Root>/Torque_L' */
  real_T Torque_R;                     /* '<Root>/Torque_R' */
  real_T current_L;                    /* '<Root>/current_L' */
  real_T current_R;                    /* '<Root>/current_R' */
} ExtY_Torque_Control_ETR07_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Torque_Control_ETR07_B
#define BlockIO                        B_Torque_Control_ETR07_T
#define rtU                            Torque_Control_ETR07_U
#define ExternalInputs                 ExtU_Torque_Control_ETR07_T
#define rtX                            Torque_Control_ETR07_X
#define ContinuousStates               X_Torque_Control_ETR07_T
#define rtXdot                         Torque_Control_ETR07_XDot
#define StateDerivatives               XDot_Torque_Control_ETR07_T
#define tXdis                          Torque_Control_ETR07_XDis
#define StateDisabled                  XDis_Torque_Control_ETR07_T
#define rtY                            Torque_Control_ETR07_Y
#define ExternalOutputs                ExtY_Torque_Control_ETR07_T
#define rtP                            Torque_Control_ETR07_P
#define Parameters                     P_Torque_Control_ETR07_T
#define rtDWork                        Torque_Control_ETR07_DW
#define D_Work                         DW_Torque_Control_ETR07_T

/* Parameters for system: '<S9>/LimitReached' */
struct P_LimitReached_Torque_Control_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
};

/* Parameters for system: '<S14>/Negative' */
struct P_Negative_Torque_Control_ETR_T_ {
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S19>/Gain1'
                                        */
};

/* Parameters for system: '<S29>/Imp' */
struct P_Imp_Torque_Control_ETR07_T_ {
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S33>/Constant'
                                        */
};

/* Parameters for system: '<S30>/If Action Subsystem2' */
struct P_IfActionSubsystem2_Torque_C_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
};

/* Parameters for system: '<S107>/Control de Temperatura' */
struct P_ControldeTemperatura_Torque_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S110>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S110>/Constant1'
                                        */
};

/* Parameters for system: '<S97>/Mech_Braking' */
struct P_Mech_Braking_Torque_Control_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S123>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S123>/Constant1'
                                        */
};

/* Parameters for system: '<S142>/Spin ' */
struct P_Spin_Torque_Control_ETR07_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S146>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.9
                                        * Referenced by: '<S146>/Switch'
                                        */
};

/* Parameters for system: '<S142>/No spin' */
struct P_Nospin_Torque_Control_ETR07_T_ {
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S145>/Switch'
                                        */
};

/* Parameters for system: '<S58>/Temp_LIMIT' */
struct P_Temp_LIMIT_Torque_Control_E_T_ {
  real_T TEMP_LIMIT_Value;             /* Expression: 0
                                        * Referenced by: '<S61>/TEMP_LIMIT'
                                        */
};

/* Parameters (auto storage) */
struct P_Torque_Control_ETR07_T_ {
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T CompareToConstant_const_p;    /* Mask Parameter: CompareToConstant_const_p
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<S9>/Data Store Memory10'
                                         */
  real_T A_Value;                      /* Expression: 0.002359
                                        * Referenced by: '<S14>/A'
                                        */
  real_T C_Value;                      /* Expression: 6.363
                                        * Referenced by: '<S14>/C'
                                        */
  real_T B_Value;                      /* Expression: 1.0396
                                        * Referenced by: '<S14>/B'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S14>/Zero'
                                        */
  real_T A1_Value;                     /* Expression: 0.0030128
                                        * Referenced by: '<S15>/A1'
                                        */
  real_T C1_Value;                     /* Expression: 6.5613
                                        * Referenced by: '<S15>/C1'
                                        */
  real_T B1_Value;                     /* Expression: 1.0388
                                        * Referenced by: '<S15>/B1'
                                        */
  real_T Zero_Value_p;                 /* Expression: 0
                                        * Referenced by: '<S15>/Zero'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T ct_Value;                     /* Expression: 1
                                        * Referenced by: '<S41>/ct'
                                        */
  real_T exptcycletau1_Value;          /* Expression: 0.905
                                        * Referenced by: '<S41>/exp(-tcycle//tau)1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<S41>/Data Store Memory'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<S41>/Data Store Memory1'
                                        */
  real_T Gain_Gain_l;                  /* Expression: -1
                                        * Referenced by: '<S108>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S108>/Gain1'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S115>/Constant1'
                                        */
  real_T rpm_Value;                    /* Expression: 200
                                        * Referenced by: '<S107>/rpm'
                                        */
  real_T Gain_Gain_co;                 /* Expression: 3.141592/30
                                        * Referenced by: '<S107>/Gain'
                                        */
  real_T Merge3_InitialOutput;         /* Computed Parameter: Merge3_InitialOutput
                                        * Referenced by: '<S107>/Merge3'
                                        */
  real_T Merge4_InitialOutput;         /* Computed Parameter: Merge4_InitialOutput
                                        * Referenced by: '<S107>/Merge4'
                                        */
  real_T Out_Throttle_Y0;              /* Computed Parameter: Out_Throttle_Y0
                                        * Referenced by: '<S120>/Out_Throttle'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S150>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.9
                                        * Referenced by: '<S150>/Switch'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S149>/Switch'
                                        */
  real_T SKF_act_Y0;                   /* Computed Parameter: SKF_act_Y0
                                        * Referenced by: '<S144>/SKF_act'
                                        */
  real_T Merge_InitialOutput;          /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<S144>/Merge'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S144>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.3
                                        * Referenced by: '<S144>/Saturation'
                                        */
  real_T CKF_act_Y0;                   /* Computed Parameter: CKF_act_Y0
                                        * Referenced by: '<S142>/CKF_act '
                                        */
  real_T Merge_InitialOutput_j;        /* Computed Parameter: Merge_InitialOutput_j
                                        * Referenced by: '<S142>/Merge'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 1
                                        * Referenced by: '<S142>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: 0.3
                                        * Referenced by: '<S142>/Saturation'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S101>/Constant2'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: -1
                                        * Referenced by: '<S101>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -1
                                        * Referenced by: '<S101>/Constant4'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1/9.81
                                        * Referenced by: '<S101>/Gain'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S101>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S101>/Constant6'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S100>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S100>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: -1
                                        * Referenced by: '<S100>/Constant3'
                                        */
  real_T Constant4_Value_p;            /* Expression: -1
                                        * Referenced by: '<S100>/Constant4'
                                        */
  real_T Steering_Ratio_Value;         /* Expression: 3.72
                                        * Referenced by: '<S130>/Steering_Ratio [-]'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S100>/Integrator'
                                        */
  real_T Constant8_Value;              /* Expression: 360
                                        * Referenced by: '<S130>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: 0.92
                                        * Referenced by: '<S130>/Constant7'
                                        */
  real_T Wheelbasem_Value;             /* Expression: 1.53
                                        * Referenced by: '<S130>/Wheelbase [m]'
                                        */
  real_T Cornering_Stiffness_FN_Value; /* Expression: -700
                                        * Referenced by: '<S130>/Cornering_Stiffness_F[N//º]'
                                        */
  real_T u602pi_Gain;                  /* Expression: 360/(2*pi)
                                        * Referenced by: '<S130>/360//(2*pi)'
                                        */
  real_T Cornering_Stiffness_RN_Value; /* Expression: -1000
                                        * Referenced by: '<S130>/Cornering_Stiffness_R[N//º]'
                                        */
  real_T u602pi_Gain_g;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S130>/360//(2pi)'
                                        */
  real_T Yaw_Inertiakgm3_Value;        /* Expression: 43.21
                                        * Referenced by: '<S100>/Yaw_Inertia [kg//m^3]'
                                        */
  real_T Rear_Trackwidthm_Value;       /* Expression: 1.15
                                        * Referenced by: '<S100>/Rear_Trackwidth [m] '
                                        */
  real_T Constant_Value_ad;            /* Expression: 2
                                        * Referenced by: '<S132>/Constant'
                                        */
  real_T Gravity_Gain;                 /* Expression: 1/9.81
                                        * Referenced by: '<S100>/Gravity'
                                        */
  real_T Fyperwheel_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S100>/Fy per wheel'
                                        */
  real_T Gravity1_Gain;                /* Expression: 1/9.81
                                        * Referenced by: '<S100>/Gravity1'
                                        */
  real_T Constant6_Value_p;            /* Expression: 1
                                        * Referenced by: '<S100>/Constant6'
                                        */
  real_T MaxTq_RRNm0inf_Y0;            /* Computed Parameter: MaxTq_RRNm0inf_Y0
                                        * Referenced by: '<S68>/MaxTq_RR [Nm] (0,inf)'
                                        */
  real_T MaxTq_RLNm0inf_Y0;            /* Computed Parameter: MaxTq_RLNm0inf_Y0
                                        * Referenced by: '<S68>/MaxTq_RL [Nm] (0,inf)'
                                        */
  real_T Flags_num5_Y0;                /* Computed Parameter: Flags_num5_Y0
                                        * Referenced by: '<S68>/Flags_[num5]'
                                        */
  real_T SteeringWheelMaximumAngle_Value;/* Expression: 100
                                          * Referenced by: '<S141>/Steering Wheel Maximum Angle'
                                          */
  real_T DataStoreMemory_InitialValue_c;/* Expression: 0
                                         * Referenced by: '<S104>/Data Store Memory'
                                         */
  real_T DataStoreMemory1_InitialValue_i;/* Expression: 0
                                          * Referenced by: '<S104>/Data Store Memory1'
                                          */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T MaximumTorqueperengineNm_Value;/* Expression: 140
                                         * Referenced by: '<S99>/Maximum Torque per engine [Nm]'
                                         */
  real_T MaximumTransmissionTorqueDynami;/* Expression: 140
                                          * Referenced by: '<S99>/Maximum Transmission Torque Dynamic [Nm]'
                                          */
  real_T MaximumTransmissionTorqueStatic;/* Expression: 130
                                          * Referenced by: '<S99>/Maximum Transmission Torque Static [Nm]'
                                          */
  real_T Constant1_Value_ab;           /* Expression: 0
                                        * Referenced by: '<S106>/Constant1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0.025
                                        * Referenced by: '<S99>/Constant1'
                                        */
  real_T Merge2_InitialOutput;         /* Computed Parameter: Merge2_InitialOutput
                                        * Referenced by: '<S68>/Merge2'
                                        */
  real_T EffectiveRollingRadiusinch_Valu;/* Expression: 13
                                          * Referenced by: '<S99>/Effective Rolling Radius[inch]'
                                          */
  real_T inchtom_Gain;                 /* Expression: 0.0254
                                        * Referenced by: '<S99>/inch to m'
                                        */
  real_T udifference_Gain;             /* Expression: 0.97
                                        * Referenced by: '<S99>/3% difference'
                                        */
  real_T TransmisionRatio_Value;       /* Expression: 4
                                        * Referenced by: '<S99>/Transmision Ratio[-]'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S106>/Constant'
                                        */
  real_T Merge3_InitialOutput_j;       /* Computed Parameter: Merge3_InitialOutput_j
                                        * Referenced by: '<S68>/Merge3'
                                        */
  real_T Tq_diff_Max_Value;            /* Expression: 100
                                        * Referenced by: '<S99>/Tq_diff_Max'
                                        */
  real_T Merge_InitialOutput_i;        /* Computed Parameter: Merge_InitialOutput_i
                                        * Referenced by: '<S97>/Merge'
                                        */
  real_T Merge1_InitialOutput;         /* Computed Parameter: Merge1_InitialOutput
                                        * Referenced by: '<S97>/Merge1'
                                        */
  real_T Merge4_InitialOutput_d;       /* Computed Parameter: Merge4_InitialOutput_d
                                        * Referenced by: '<S68>/Merge4'
                                        */
  real_T Merge5_InitialOutput;         /* Computed Parameter: Merge5_InitialOutput
                                        * Referenced by: '<S68>/Merge5'
                                        */
  real_T Merge6_InitialOutput;         /* Computed Parameter: Merge6_InitialOutput
                                        * Referenced by: '<S68>/Merge6'
                                        */
  real_T Merge7_InitialOutput;         /* Computed Parameter: Merge7_InitialOutput
                                        * Referenced by: '<S68>/Merge7'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S166>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: -1
                                        * Referenced by: '<S166>/Gain1'
                                        */
  real_T rpm_Value_k;                  /* Expression: 200
                                        * Referenced by: '<S165>/rpm'
                                        */
  real_T Gain_Gain_cv;                 /* Expression: 3.141592/30
                                        * Referenced by: '<S165>/Gain'
                                        */
  real_T Out_Throttle_Y0_a;            /* Computed Parameter: Out_Throttle_Y0_a
                                        * Referenced by: '<S177>/Out_Throttle'
                                        */
  real_T MaxTq_RRNm0inf_Y0_o;          /* Computed Parameter: MaxTq_RRNm0inf_Y0_o
                                        * Referenced by: '<S69>/MaxTq_RR [Nm] (0,inf)'
                                        */
  real_T MaxTq_RLNm0inf_Y0_d;          /* Computed Parameter: MaxTq_RLNm0inf_Y0_d
                                        * Referenced by: '<S69>/MaxTq_RL [Nm] (0,inf)'
                                        */
  real_T MaxFx_RRN0inf_Y0;             /* Computed Parameter: MaxFx_RRN0inf_Y0
                                        * Referenced by: '<S69>/MaxFx_RR [N] (0,inf)'
                                        */
  real_T MaxFx_RLN0inf_Y0;             /* Computed Parameter: MaxFx_RLN0inf_Y0
                                        * Referenced by: '<S69>/MaxFx_RL [N] (0,inf)'
                                        */
  real_T Fy_RN0inf_Y0;                 /* Computed Parameter: Fy_RN0inf_Y0
                                        * Referenced by: '<S69>/Fy_R [N] (0,inf)'
                                        */
  real_T Masskg0inf_Y0;                /* Computed Parameter: Masskg0inf_Y0
                                        * Referenced by: '<S69>/Mass [kg] (0,inf)'
                                        */
  real_T Handlinginfinf_Y0;            /* Computed Parameter: Handlinginfinf_Y0
                                        * Referenced by: '<S69>/Handling [-] (-inf,inf)'
                                        */
  real_T Merge_InitialOutput_h;        /* Computed Parameter: Merge_InitialOutput_h
                                        * Referenced by: '<S187>/Merge'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1
                                        * Referenced by: '<S187>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0.3
                                        * Referenced by: '<S187>/Saturation'
                                        */
  real_T DataStoreMemory1_InitialValue_m;/* Expression: 0
                                          * Referenced by: '<S162>/Data Store Memory1'
                                          */
  real_T MaximumTorqueperengineNm_Valu_b;/* Expression: 140
                                          * Referenced by: '<S159>/Maximum Torque per engine [Nm]'
                                          */
  real_T MaximumTransmissionTorqueDyna_a;/* Expression: 140
                                          * Referenced by: '<S159>/Maximum Transmission Torque Dynamic [Nm]'
                                          */
  real_T MaximumTransmissionTorqueStat_n;/* Expression: 130
                                          * Referenced by: '<S159>/Maximum Transmission Torque Static [Nm]'
                                          */
  real_T Constant_Value_ib;            /* Expression: 0
                                        * Referenced by: '<S164>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: -1
                                        * Referenced by: '<S160>/Constant1'
                                        */
  real_T Gravity1_Gain_g;              /* Expression: 1/9.81
                                        * Referenced by: '<S161>/Gravity1'
                                        */
  real_T Fyperwheel_Gain_e;            /* Expression: 1/2
                                        * Referenced by: '<S161>/Fy per wheel'
                                        */
  real_T EffectiveRollingRadiusinch_Va_b;/* Expression: 13
                                          * Referenced by: '<S159>/Effective Rolling Radius[inch]'
                                          */
  real_T inchtom_Gain_g;               /* Expression: 0.0254
                                        * Referenced by: '<S159>/inch to m'
                                        */
  real_T udifference_Gain_d;           /* Expression: 0.97
                                        * Referenced by: '<S159>/3% difference'
                                        */
  real_T TransmisionRatio_Value_j;     /* Expression: 4
                                        * Referenced by: '<S159>/Transmision Ratio[-]'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S164>/Constant1'
                                        */
  real_T Constant_Value_ae;            /* Expression: -1
                                        * Referenced by: '<S160>/Constant'
                                        */
  real_T Merge_InitialOutput_l;        /* Computed Parameter: Merge_InitialOutput_l
                                        * Referenced by: '<S158>/Merge'
                                        */
  real_T Merge1_InitialOutput_k;       /* Computed Parameter: Merge1_InitialOutput_k
                                        * Referenced by: '<S158>/Merge1'
                                        */
  real_T Constant_Value_n5;            /* Expression: 1
                                        * Referenced by: '<S93>/Constant'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0.9
                                        * Referenced by: '<S93>/Switch'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S92>/Switch'
                                        */
  real_T SKF_act_Y0_l;                 /* Computed Parameter: SKF_act_Y0_l
                                        * Referenced by: '<S87>/SKF_act'
                                        */
  real_T Merge_InitialOutput_p;        /* Computed Parameter: Merge_InitialOutput_p
                                        * Referenced by: '<S87>/Merge'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 1
                                        * Referenced by: '<S87>/Saturation'
                                        */
  real_T Saturation_LowerSat_f3;       /* Expression: 0.3
                                        * Referenced by: '<S87>/Saturation'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0.9
                                        * Referenced by: '<S89>/Switch'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0
                                        * Referenced by: '<S88>/Switch'
                                        */
  real_T CKF_act_Y0_j;                 /* Computed Parameter: CKF_act_Y0_j
                                        * Referenced by: '<S85>/CKF_act '
                                        */
  real_T Merge_InitialOutput_a;        /* Computed Parameter: Merge_InitialOutput_a
                                        * Referenced by: '<S85>/Merge'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 1
                                        * Referenced by: '<S85>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0.3
                                        * Referenced by: '<S85>/Saturation'
                                        */
  real_T SteeringWheelMaximumAngle_Val_o;/* Expression: 100
                                          * Referenced by: '<S84>/Steering Wheel Maximum Angle'
                                          */
  real_T DataStoreMemory_InitialValue_m;/* Expression: 0
                                         * Referenced by: '<S77>/Data Store Memory'
                                         */
  real_T DataStoreMemory1_InitialValue_f;/* Expression: 0
                                          * Referenced by: '<S77>/Data Store Memory1'
                                          */
  real_T SteeringWheelMaximumAngle_Val_i;/* Expression: 140
                                          * Referenced by: '<S67>/Steering Wheel Maximum Angle'
                                          */
  real_T Tq_maxNm_Value;               /* Expression: 130
                                        * Referenced by: '<S67>/Tq_max [Nm]'
                                        */
  real_T Tq_diff_maxNm_Value;          /* Expression: 100
                                        * Referenced by: '<S67>/Tq_diff_max [Nm]'
                                        */
  real_T Torque_RLNm_Value;            /* Expression: 60
                                        * Referenced by: '<S66>/Torque_RL [Nm]'
                                        */
  real_T Torque_RRNm_Value;            /* Expression: 60
                                        * Referenced by: '<S66>/Torque_RR [Nm]'
                                        */
  real_T LimitTemperatureIGBTC_Value;  /* Expression: 60
                                        * Referenced by: '<S54>/Limit Temperature IGBT [ºC]'
                                        */
  real_T LimitTemperatureMotorC_Value; /* Expression: 110
                                        * Referenced by: '<S54>/Limit Temperature Motor [ºC]'
                                        */
  real_T LimitTemperatureCeldasC_Value;/* Expression: 45
                                        * Referenced by: '<S54>/Limit Temperature Celdas[ºC]'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T SteeringWheelSaturationpersited;/* Expression: 10
                                          * Referenced by: '<S54>/Steering Wheel Saturation (per site) [deg] '
                                          */
  real_T Merge_InitialOutput_pp;       /* Computed Parameter: Merge_InitialOutput_pp
                                        * Referenced by: '<S54>/Merge'
                                        */
  real_T Merge1_InitialOutput_f;       /* Computed Parameter: Merge1_InitialOutput_f
                                        * Referenced by: '<S54>/Merge1'
                                        */
  real_T Merge2_InitialOutput_o;       /* Computed Parameter: Merge2_InitialOutput_o
                                        * Referenced by: '<S54>/Merge2'
                                        */
  real_T Merge3_InitialOutput_n;       /* Computed Parameter: Merge3_InitialOutput_n
                                        * Referenced by: '<S54>/Merge3'
                                        */
  real_T TEMP_LIMIT_UPPER_Value;       /* Expression: 50
                                        * Referenced by: '<S63>/TEMP_LIMIT_UPPER'
                                        */
  real_T TEMP_LIMIT_LOWER_Value;       /* Expression: 45
                                        * Referenced by: '<S60>/TEMP_LIMIT_LOWER'
                                        */
  real_T Not_Braking_Value;            /* Expression: 0
                                        * Referenced by: '<S58>/Not_Braking'
                                        */
  real_T Merge_InitialOutput_jq;       /* Computed Parameter: Merge_InitialOutput_jq
                                        * Referenced by: '<S58>/Merge'
                                        */
  real_T BRAKE_THRESHOLD_Value;        /* Expression: 0.2
                                        * Referenced by: '<S52>/BRAKE_THRESHOLD'
                                        */
  real_T Zero_Value_c;                 /* Expression: 0
                                        * Referenced by: '<S52>/Zero '
                                        */
  real_T Constant_Value_m;             /* Expression: 2
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T DataStoreMemory_InitialValue_j;/* Expression: 0
                                         * Referenced by: '<S52>/Data Store Memory'
                                         */
  real_T Constant_Value_k;             /* Expression: 800
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T Constant1_Value_ln;           /* Expression: 800
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real_T Constant2_Value_g1;           /* Expression: 800
                                        * Referenced by: '<S65>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: 800
                                        * Referenced by: '<S65>/Constant3'
                                        */
  real_T Constant_Value_dm;            /* Expression: 15
                                        * Referenced by: '<S197>/Constant'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 10
                                        * Referenced by: '<S197>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -10
                                        * Referenced by: '<S197>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 10
                                        * Referenced by: '<S197>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -10
                                        * Referenced by: '<S197>/Saturation1'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 145
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation_LowerSat_fi;       /* Expression: -70
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation1_UpperSat_m;       /* Expression: 145
                                        * Referenced by: '<S55>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -70
                                        * Referenced by: '<S55>/Saturation1'
                                        */
  real_T zero_Value;                   /* Expression: 570
                                        * Referenced by: '<S6>/zero'
                                        */
  real_T halfrange_Value;              /* Expression: 2
                                        * Referenced by: '<S6>/half range'
                                        */
  real_T range_Value;                  /* Expression: 1000
                                        * Referenced by: '<S6>/range'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 115
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value_h;             /* Expression: 50
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_f3;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 100
                                        * Referenced by: '<S7>/Gain1'
                                        */
  boolean_T DataStoreMemory1_InitialValu_fl;/* Computed Parameter: DataStoreMemory1_InitialValu_fl
                                             * Referenced by: '<S30>/Data Store Memory1'
                                             */
  P_Temp_LIMIT_Torque_Control_E_T Temp_OK;/* '<S58>/Temp_OK' */
  P_Temp_LIMIT_Torque_Control_E_T Temp_LIMIT;/* '<S58>/Temp_LIMIT' */
  P_Nospin_Torque_Control_ETR07_T Nospin_m;/* '<S187>/No spin' */
  P_Spin_Torque_Control_ETR07_T Spin_nb;/* '<S187>/Spin ' */
  P_Mech_Braking_Torque_Control_T InertiaBraking_b;/* '<S158>/Inertia Braking' */
  P_Mech_Braking_Torque_Control_T Mech_Braking_h;/* '<S158>/Mech_Braking' */
  P_Nospin_Torque_Control_ETR07_T Nospin_k;/* '<S142>/No spin' */
  P_Spin_Torque_Control_ETR07_T Spin_n;/* '<S142>/Spin ' */
  P_Mech_Braking_Torque_Control_T InertiaBraking;/* '<S97>/Inertia Braking' */
  P_Mech_Braking_Torque_Control_T Mech_Braking;/* '<S97>/Mech_Braking' */
  P_ControldeTemperatura_Torque_T ControldePotencia;/* '<S107>/Control de Potencia ' */
  P_ControldeTemperatura_Torque_T ControldeTemperatura;/* '<S107>/Control de Temperatura' */
  P_Imp_Torque_Control_ETR07_T NotImpMemo1;/* '<S30>/Not Imp Memo1' */
  P_Imp_Torque_Control_ETR07_T ImpMemo1;/* '<S30>/Imp Memo1' */
  P_IfActionSubsystem2_Torque_C_T IfActionSubsystem3;/* '<S30>/If Action Subsystem3' */
  P_IfActionSubsystem2_Torque_C_T IfActionSubsystem2;/* '<S30>/If Action Subsystem2' */
  P_Imp_Torque_Control_ETR07_T NotImp1;/* '<S30>/Not Imp1' */
  P_Imp_Torque_Control_ETR07_T Imp1;   /* '<S30>/Imp1' */
  P_Imp_Torque_Control_ETR07_T NotImp; /* '<S29>/Not Imp' */
  P_Imp_Torque_Control_ETR07_T Imp;    /* '<S29>/Imp' */
  P_Negative_Torque_Control_ETR_T Negative_k;/* '<S15>/Negative' */
  P_Negative_Torque_Control_ETR_T Negative;/* '<S14>/Negative' */
  P_LimitReached_Torque_Control_T OK;  /* '<S11>/OK' */
  P_LimitReached_Torque_Control_T LatchedError;/* '<S11>/Latched Error' */
  P_LimitReached_Torque_Control_T LimitReached;/* '<S9>/LimitReached' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Torque_Control_ETR07_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Torque_Control_ETR07_T Torque_Control_ETR07_P;

/* Block signals (auto storage) */
extern B_Torque_Control_ETR07_T Torque_Control_ETR07_B;

/* Continuous states (auto storage) */
extern X_Torque_Control_ETR07_T Torque_Control_ETR07_X;

/* Block states (auto storage) */
extern DW_Torque_Control_ETR07_T Torque_Control_ETR07_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Torque_Control_ETR07_T Torque_Control_ETR07_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Torque_Control_ETR07_T Torque_Control_ETR07_Y;

/* Model entry point functions */
extern void Torque_Control_ETR07_initialize(void);
extern void Torque_Control_ETR07_output(void);
extern void Torque_Control_ETR07_update(void);
extern void Torque_Control_ETR07_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Torque_Control_ETR07_rtModel *Torque_Control_ETR07(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Torque_Control_ETR07_T *const Torque_Control_ETR07_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Torque_Control_ETR07'
 * '<S1>'   : 'Torque_Control_ETR07/Accumulator Power'
 * '<S2>'   : 'Torque_Control_ETR07/Calculate Current Conversion'
 * '<S3>'   : 'Torque_Control_ETR07/Current 0'
 * '<S4>'   : 'Torque_Control_ETR07/Pumps_Controller'
 * '<S5>'   : 'Torque_Control_ETR07/SAFETY BLOCK'
 * '<S6>'   : 'Torque_Control_ETR07/Steering Data Conv'
 * '<S7>'   : 'Torque_Control_ETR07/VDC'
 * '<S8>'   : 'Torque_Control_ETR07/W to kW'
 * '<S9>'   : 'Torque_Control_ETR07/Accumulator Power/PowerLimitDetection'
 * '<S10>'  : 'Torque_Control_ETR07/Accumulator Power/PowerLimitDetection/LimitReached'
 * '<S11>'  : 'Torque_Control_ETR07/Accumulator Power/PowerLimitDetection/OK_OrLatch'
 * '<S12>'  : 'Torque_Control_ETR07/Accumulator Power/PowerLimitDetection/OK_OrLatch/Latched Error'
 * '<S13>'  : 'Torque_Control_ETR07/Accumulator Power/PowerLimitDetection/OK_OrLatch/OK'
 * '<S14>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_L_TORKY'
 * '<S15>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_R_EMY'
 * '<S16>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_L_TORKY/Bypass'
 * '<S17>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_L_TORKY/Bypass_Torque'
 * '<S18>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_L_TORKY/Is_Zero'
 * '<S19>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_L_TORKY/Negative'
 * '<S20>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_R_EMY/Bypass'
 * '<S21>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_R_EMY/Bypass_Torque'
 * '<S22>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_R_EMY/Is_Zero'
 * '<S23>'  : 'Torque_Control_ETR07/Calculate Current Conversion/KT_R_EMY/Negative'
 * '<S24>'  : 'Torque_Control_ETR07/Pumps_Controller/Compare To Constant'
 * '<S25>'  : 'Torque_Control_ETR07/Pumps_Controller/Compare To Constant1'
 * '<S26>'  : 'Torque_Control_ETR07/Pumps_Controller/DocBlock1'
 * '<S27>'  : 'Torque_Control_ETR07/Pumps_Controller/Pumps_Control_OFF'
 * '<S28>'  : 'Torque_Control_ETR07/Pumps_Controller/Pumps_Control_ON'
 * '<S29>'  : 'Torque_Control_ETR07/SAFETY BLOCK/APPS_IMPLAUSIBILITY'
 * '<S30>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY'
 * '<S31>'  : 'Torque_Control_ETR07/SAFETY BLOCK/Compare To Constant'
 * '<S32>'  : 'Torque_Control_ETR07/SAFETY BLOCK/Power is under 100kW '
 * '<S33>'  : 'Torque_Control_ETR07/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Imp'
 * '<S34>'  : 'Torque_Control_ETR07/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Not Imp'
 * '<S35>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/If Action Subsystem2'
 * '<S36>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/If Action Subsystem3'
 * '<S37>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Imp Memo1'
 * '<S38>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Imp1'
 * '<S39>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Not Imp Memo1'
 * '<S40>'  : 'Torque_Control_ETR07/SAFETY BLOCK/BRAKE_IMPLAUSIBILITY/Not Imp1'
 * '<S41>'  : 'Torque_Control_ETR07/Steering Data Conv/Low Pass'
 * '<S42>'  : 'Torque_Control_ETR07/VDC/DocBlock'
 * '<S43>'  : 'Torque_Control_ETR07/VDC/DocBlock1'
 * '<S44>'  : 'Torque_Control_ETR07/VDC/DocBlock10'
 * '<S45>'  : 'Torque_Control_ETR07/VDC/DocBlock2'
 * '<S46>'  : 'Torque_Control_ETR07/VDC/DocBlock4'
 * '<S47>'  : 'Torque_Control_ETR07/VDC/DocBlock5'
 * '<S48>'  : 'Torque_Control_ETR07/VDC/DocBlock6'
 * '<S49>'  : 'Torque_Control_ETR07/VDC/DocBlock7'
 * '<S50>'  : 'Torque_Control_ETR07/VDC/DocBlock8'
 * '<S51>'  : 'Torque_Control_ETR07/VDC/DocBlock9'
 * '<S52>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable'
 * '<S53>'  : 'Torque_Control_ETR07/VDC/TEST_MODE_IN'
 * '<S54>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018'
 * '<S55>'  : 'Torque_Control_ETR07/VDC/WORKSHOP_MODE_RESTRICTIONS'
 * '<S56>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/Braking'
 * '<S57>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/BypassDecision '
 * '<S58>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/Not-Braking'
 * '<S59>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/NotEnabled'
 * '<S60>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/Not-Braking/Low_Threshold'
 * '<S61>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/Not-Braking/Temp_LIMIT'
 * '<S62>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/Not-Braking/Temp_OK'
 * '<S63>'  : 'Torque_Control_ETR07/VDC/Regeneration_Enable/Not-Braking/Upper_Threshold'
 * '<S64>'  : 'Torque_Control_ETR07/VDC/TEST_MODE_IN/BYPASS'
 * '<S65>'  : 'Torque_Control_ETR07/VDC/TEST_MODE_IN/TEST_CONSTANTS'
 * '<S66>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Rigid Axle'
 * '<S67>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC'
 * '<S68>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete'
 * '<S69>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal'
 * '<S70>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Rigid Axle/Accelerating'
 * '<S71>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Rigid Axle/Accelerating/Accelerator behaviour '
 * '<S72>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Accelerating'
 * '<S73>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Constraints'
 * '<S74>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Lateral Dynamics'
 * '<S75>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Longitudinal Dynamics'
 * '<S76>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/MATLAB Function1'
 * '<S77>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF'
 * '<S78>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Steering TV 2017 without TC'
 * '<S79>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Accelerating/Accelerator behaviour '
 * '<S80>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Constraints/Control de Potencia '
 * '<S81>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Constraints/Control de Temperatura'
 * '<S82>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Constraints/else'
 * '<S83>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/MATLAB Function'
 * '<S84>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  '
 * '<S85>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S86>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S87>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S88>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S89>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S90>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S91>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S92>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S93>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S94>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S95>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/Steering TV 2017 with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S96>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints'
 * '<S97>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Driver // CarBehaviours'
 * '<S98>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Flags'
 * '<S99>'  : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/In_Numbers'
 * '<S100>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics'
 * '<S101>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Longitudinal Dynamics'
 * '<S102>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/MATLAB Function1'
 * '<S103>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/MATLAB Function2'
 * '<S104>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF'
 * '<S105>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Sensor_DATA'
 * '<S106>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Wheel_to_engine'
 * '<S107>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative'
 * '<S108>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Braking with Regenerative'
 * '<S109>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/Control de Potencia '
 * '<S110>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/Control de Temperatura'
 * '<S111>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/If Action 1'
 * '<S112>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/If Action 2'
 * '<S113>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/MATLAB Function'
 * '<S114>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S115>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/else'
 * '<S116>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/minimum value'
 * '<S117>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/minimum value1'
 * '<S118>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S119>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Constraints/Braking with Regenerative/MATLAB Function'
 * '<S120>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Driver // CarBehaviours/Accelerating'
 * '<S121>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Driver // CarBehaviours/Accelerator behaviour '
 * '<S122>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Driver // CarBehaviours/Inertia Braking'
 * '<S123>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Driver // CarBehaviours/Mech_Braking'
 * '<S124>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S125>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Force Difference with  Max. Tire Forces'
 * '<S126>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Kamm_Circle'
 * '<S127>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/MATLAB Function1'
 * '<S128>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/MATLAB Function2'
 * '<S129>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Tire Longitudinal  Force Difference'
 * '<S130>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Yaw_Rate_Reference'
 * '<S131>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S132>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/ Momentum_Z to Longitudinal Force Difference'
 * '<S133>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/Momentum respect to Z-axis to correct the error'
 * '<S134>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Lateral Dynamics/Yaw_Rate_Reference/Bicycle Model'
 * '<S135>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Longitudinal Dynamics/Kamm_Circle'
 * '<S136>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Longitudinal Dynamics/MATLAB Function'
 * '<S137>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Longitudinal Dynamics/MATLAB Function1'
 * '<S138>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Longitudinal Dynamics/minimum value'
 * '<S139>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Longitudinal Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S140>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/MATLAB Function'
 * '<S141>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  '
 * '<S142>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S143>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S144>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S145>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S146>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S147>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S148>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S149>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S150>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S151>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S152>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S153>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Wheel_to_engine/Fx_to_engineTqRL'
 * '<S154>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Wheel_to_engine/Fx_to_engineTqRR'
 * '<S155>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Wheel_to_engine/MATLAB Function1'
 * '<S156>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 Complete/Wheel_to_engine/MATLAB Function2'
 * '<S157>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints'
 * '<S158>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Driver // CarBehaviours'
 * '<S159>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/In_Numbers'
 * '<S160>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Kamm Circle Lateral'
 * '<S161>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Lateral Dynamics'
 * '<S162>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF'
 * '<S163>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Sensor_DATA'
 * '<S164>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Wheel_to_engine'
 * '<S165>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative'
 * '<S166>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Braking with Regenerative'
 * '<S167>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/Control de Potencia 1'
 * '<S168>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/Control de Temperatura1'
 * '<S169>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 1'
 * '<S170>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 2'
 * '<S171>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S172>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/else1'
 * '<S173>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value'
 * '<S174>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value1'
 * '<S175>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S176>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Constraints/Braking with Regenerative/MATLAB Function'
 * '<S177>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Driver // CarBehaviours/Accelerating'
 * '<S178>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Driver // CarBehaviours/Inertia Braking'
 * '<S179>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Driver // CarBehaviours/Mech_Braking'
 * '<S180>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S181>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Driver // CarBehaviours/Accelerating/Accelerator behaviour '
 * '<S182>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Kamm Circle Lateral/Kamm_Circle LatD'
 * '<S183>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Kamm Circle Lateral/MATLAB Function1'
 * '<S184>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Kamm Circle Lateral/MATLAB Function2'
 * '<S185>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/MATLAB Function'
 * '<S186>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/Subsystem  '
 * '<S187>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S188>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S189>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S190>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S191>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S192>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Wheel_to_engine/Fx_to_engineTqRL'
 * '<S193>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Wheel_to_engine/Fx_to_engineTqRR'
 * '<S194>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Wheel_to_engine/MATLAB Function1'
 * '<S195>' : 'Torque_Control_ETR07/VDC/Vehicle Dynamics Control 2018/VDC 2018 without Longitudinal/Wheel_to_engine/MATLAB Function2'
 * '<S196>' : 'Torque_Control_ETR07/VDC/WORKSHOP_MODE_RESTRICTIONS/BYPASS'
 * '<S197>' : 'Torque_Control_ETR07/VDC/WORKSHOP_MODE_RESTRICTIONS/Torque_Reduction '
 */
#endif                                 /* RTW_HEADER_Torque_Control_ETR07_h_ */
