/* Patched in by the INTECRIO IRT target */
/* PATCH BEGIN */
#include "Racing_Mode_irtmacros.h"
/* PATCH END */

/*
 * Racing_Mode.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Racing_Mode".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Mar 29 13:00:07 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Racing_Mode_h_
#define RTW_HEADER_Racing_Mode_h_
#include <math.h>
#include <string.h>
#ifndef Racing_Mode_COMMON_INCLUDES_
# define Racing_Mode_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* Racing_Mode_COMMON_INCLUDES_ */

#include "Racing_Mode_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
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
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
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
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
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
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
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
#define Racing_Mode_rtModel            RT_MODEL_Racing_Mode_T

/* Block signals for system '<S2>/SKF_Initial' */
typedef struct {
  real_T Gain;                         /* '<S17>/Gain' */
} B_SKF_Initial_Racing_Mode_T;

/* Block signals for system '<S2>/Max_Regenerative_Torque' */
typedef struct {
  real_T In1;                          /* '<S15>/In1' */
} B_Max_Regenerative_Torque_Rac_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Merge[10];                    /* '<Root>/Merge' */
  B_SKF_Initial_Racing_Mode_T K_Reduction_Temperature;/* '<S2>/K_Reduction_Temperature' */
  B_SKF_Initial_Racing_Mode_T K_Reduction_P;/* '<S2>/K_Reduction_P' */
  B_Max_Regenerative_Torque_Rac_T Power_Limit;/* '<S2>/Power_Limit' */
  B_Max_Regenerative_Torque_Rac_T Max_Regenerative_Torque;/* '<S2>/Max_Regenerative_Torque' */
  B_SKF_Initial_Racing_Mode_T Apps_Sat_Up;/* '<S2>/Apps_Sat_Up' */
  B_SKF_Initial_Racing_Mode_T Apps_Sat_Dwn;/* '<S2>/Apps_Sat_Dwn' */
  B_SKF_Initial_Racing_Mode_T Cte_CKF; /* '<S2>/Cte_CKF' */
  B_SKF_Initial_Racing_Mode_T Cte_SKF; /* '<S2>/Cte_SKF' */
  B_SKF_Initial_Racing_Mode_T CKF_Initial;/* '<S2>/CKF_Initial' */
  B_SKF_Initial_Racing_Mode_T SKF_Initial;/* '<S2>/SKF_Initial' */
} B_Racing_Mode_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint8_T RacingMode;                  /* '<Root>/RacingMode' */
  real_T CustomMode_Data;              /* '<Root>/CustomMode_Data' */
  real_T CustomMode_Identifier;        /* '<Root>/CustomMode_Identifier' */
} ExtU_Racing_Mode_T;

/* External outputs (root outports fed by signals with auto storage) */
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
  boolean_T Workshop_Mode_Enable;      /* '<Root>/Workshop_Mode_Enable' */
} ExtY_Racing_Mode_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Racing_Mode_B
#define BlockIO                        B_Racing_Mode_T
#define rtU                            Racing_Mode_U
#define ExternalInputs                 ExtU_Racing_Mode_T
#define rtY                            Racing_Mode_Y
#define ExternalOutputs                ExtY_Racing_Mode_T
#define rtP                            Racing_Mode_P
#define Parameters                     P_Racing_Mode_T

/* Parameters for system: '<Root>/Workshop Test (01)' */
struct P_WorkshopTest01_Racing_Mode_T_ {
  real_T Apps_Sat_Dwn_Value;           /* Expression: 0.2
                                        * Referenced by: '<S7>/Apps_Sat_Dwn'
                                        */
  real_T Apps_Sat_Up_Value;            /* Expression: 0.8
                                        * Referenced by: '<S7>/Apps_Sat_Up'
                                        */
  real_T CKF_Initial_Value;            /* Expression: 0.9
                                        * Referenced by: '<S7>/CKF_Initial'
                                        */
  real_T Cte_CKF_Value;                /* Expression: 0.98
                                        * Referenced by: '<S7>/Cte_CKF'
                                        */
  real_T Cte_SKF_Value;                /* Expression: 0.98
                                        * Referenced by: '<S7>/Cte_SKF'
                                        */
  real_T K_Reduction_P_Value;          /* Expression: 0.5
                                        * Referenced by: '<S7>/K_Reduction_P'
                                        */
  real_T K_Reduction_Temperature_Value;/* Expression: 0.6
                                        * Referenced by: '<S7>/K_Reduction_Temperature'
                                        */
  real_T Max_Regenerative_Torque_Value;/* Expression: 10
                                        * Referenced by: '<S7>/Max_Regenerative_Torque'
                                        */
  real_T SKF_Initial_Value;            /* Expression: 0.9
                                        * Referenced by: '<S7>/SKF_Initial'
                                        */
  real_T Power_Limit_Value;            /* Expression: 1
                                        * Referenced by: '<S7>/Power_Limit'
                                        */
};

/* Parameters for system: '<S2>/SKF_Initial' */
struct P_SKF_Initial_Racing_Mode_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S17>/Out1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S17>/Gain'
                                        */
};

/* Parameters for system: '<S2>/Max_Regenerative_Torque' */
struct P_Max_Regenerative_Torque_Rac_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S15>/Out1'
                                        */
};

/* Parameters (auto storage) */
struct P_Racing_Mode_T_ {
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T CEE_SKF_Initial_Value;        /* Expression: 0
                                        * Referenced by: '<S6>/CEE_SKF_Initial'
                                        */
  real_T CEE_CKF_Initial_Value;        /* Expression: 0
                                        * Referenced by: '<S6>/CEE_CKF_Initial'
                                        */
  real_T CEE_Cte_SKF_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/CEE_Cte_SKF'
                                        */
  real_T CEE_Cte_CKF_Value;            /* Expression: 0
                                        * Referenced by: '<S6>/CEE_Cte_CKF'
                                        */
  real_T CEE_Apps_Sat_Dwn_Value;       /* Expression: 0
                                        * Referenced by: '<S6>/CEE_Apps_Sat_Dwn'
                                        */
  real_T CEE_Apps_Sat_Up_Value;        /* Expression: 0
                                        * Referenced by: '<S6>/CEE_Apps_Sat_Up'
                                        */
  real_T CEE_Max_Regenerative_Torque_Val;/* Expression: 0
                                          * Referenced by: '<S6>/CEE_Max_Regenerative_Torque'
                                          */
  real_T CEE_Power_Limit_Value;        /* Expression: 0
                                        * Referenced by: '<S6>/CEE_Power_Limit'
                                        */
  real_T CEE_K_Reduction_P_Value;      /* Expression: 0
                                        * Referenced by: '<S6>/CEE_K_Reduction_P'
                                        */
  real_T CEE_K_Reduction_Temperature_Val;/* Expression: 0
                                          * Referenced by: '<S6>/CEE_K_Reduction_Temperature'
                                          */
  real_T Merge_InitialOutput;          /* Computed Parameter: Merge_InitialOutput
                                        * Referenced by: '<Root>/Merge'
                                        */
  real_T SKF_InitialSaturation_UpperSat;/* Expression: 0.9
                                         * Referenced by: '<Root>/SKF_Initial Saturation'
                                         */
  real_T SKF_InitialSaturation_LowerSat;/* Expression: 0
                                         * Referenced by: '<Root>/SKF_Initial Saturation'
                                         */
  real_T CKF_InitialSaturation_UpperSat;/* Expression: 0.9
                                         * Referenced by: '<Root>/CKF_Initial Saturation'
                                         */
  real_T CKF_InitialSaturation_LowerSat;/* Expression: 0
                                         * Referenced by: '<Root>/CKF_Initial Saturation'
                                         */
  real_T Cte_SKFSaturation_UpperSat;   /* Expression: 1
                                        * Referenced by: '<Root>/Cte_SKF Saturation'
                                        */
  real_T Cte_SKFSaturation_LowerSat;   /* Expression: 0
                                        * Referenced by: '<Root>/Cte_SKF Saturation'
                                        */
  real_T Cte_CKFSaturation_UpperSat;   /* Expression: 1
                                        * Referenced by: '<Root>/Cte_CKF Saturation'
                                        */
  real_T Cte_CKFSaturation_LowerSat;   /* Expression: 0
                                        * Referenced by: '<Root>/Cte_CKF Saturation'
                                        */
  real_T Apps_Sat_DwnSaturation_UpperSat;/* Expression: 0.5
                                          * Referenced by: '<Root>/Apps_Sat_Dwn Saturation'
                                          */
  real_T Apps_Sat_DwnSaturation_LowerSat;/* Expression: 0
                                          * Referenced by: '<Root>/Apps_Sat_Dwn Saturation'
                                          */
  real_T Apps_Sat_UpSaturation_UpperSat;/* Expression: 1
                                         * Referenced by: '<Root>/Apps_Sat_Up Saturation'
                                         */
  real_T Apps_Sat_UpSaturation_LowerSat;/* Expression: 0
                                         * Referenced by: '<Root>/Apps_Sat_Up Saturation'
                                         */
  real_T Max_Regenerative_TorqueSaturati;/* Expression: 10
                                          * Referenced by: '<Root>/Max_Regenerative_Torque Saturation'
                                          */
  real_T Max_Regenerative_TorqueSatura_o;/* Expression: 0
                                          * Referenced by: '<Root>/Max_Regenerative_Torque Saturation'
                                          */
  real_T Power_LimitSaturation_UpperSat;/* Expression: 77
                                         * Referenced by: '<Root>/Power_Limit Saturation'
                                         */
  real_T Power_LimitSaturation_LowerSat;/* Expression: 0
                                         * Referenced by: '<Root>/Power_Limit Saturation'
                                         */
  real_T K_Reduction_PSaturation_UpperSa;/* Expression: 1
                                          * Referenced by: '<Root>/K_Reduction_P Saturation'
                                          */
  real_T K_Reduction_PSaturation_LowerSa;/* Expression: 0
                                          * Referenced by: '<Root>/K_Reduction_P Saturation'
                                          */
  real_T K_Reduction_TemperatureSaturati;/* Expression: 1
                                          * Referenced by: '<Root>/K_Reduction_Temperature Saturation'
                                          */
  real_T K_Reduction_TemperatureSatura_m;/* Expression: 0
                                          * Referenced by: '<Root>/K_Reduction_Temperature Saturation'
                                          */
  P_WorkshopTest01_Racing_Mode_T Endurance5Driver22;/* '<S5>/Endurance (5). Driver 2 (2)' */
  P_WorkshopTest01_Racing_Mode_T AutoX4Driver22;/* '<S5>/AutoX (4). Driver 2 (2)' */
  P_WorkshopTest01_Racing_Mode_T Skidpad3Driver22;/* '<S5>/Skidpad (3). Driver 2 (2)' */
  P_WorkshopTest01_Racing_Mode_T Acceleration2Driver22;/* '<S5>/Acceleration (2). Driver 2 (2) ' */
  P_WorkshopTest01_Racing_Mode_T Endurance5Driver11;/* '<S4>/Endurance (5). Driver 1 (1)' */
  P_WorkshopTest01_Racing_Mode_T AutoX4Driver11;/* '<S4>/AutoX (4). Driver 1 (1)' */
  P_WorkshopTest01_Racing_Mode_T Skidpad3Driver11;/* '<S4>/Skidpad (3). Driver 1 (1)' */
  P_WorkshopTest01_Racing_Mode_T Acceleration2Driver11;/* '<S4>/Acceleration (2). Driver 1 (1) ' */
  P_SKF_Initial_Racing_Mode_T K_Reduction_Temperature;/* '<S2>/K_Reduction_Temperature' */
  P_SKF_Initial_Racing_Mode_T K_Reduction_P;/* '<S2>/K_Reduction_P' */
  P_Max_Regenerative_Torque_Rac_T Power_Limit;/* '<S2>/Power_Limit' */
  P_Max_Regenerative_Torque_Rac_T Max_Regenerative_Torque;/* '<S2>/Max_Regenerative_Torque' */
  P_SKF_Initial_Racing_Mode_T Apps_Sat_Up;/* '<S2>/Apps_Sat_Up' */
  P_SKF_Initial_Racing_Mode_T Apps_Sat_Dwn;/* '<S2>/Apps_Sat_Dwn' */
  P_SKF_Initial_Racing_Mode_T Cte_CKF; /* '<S2>/Cte_CKF' */
  P_SKF_Initial_Racing_Mode_T Cte_SKF; /* '<S2>/Cte_SKF' */
  P_SKF_Initial_Racing_Mode_T CKF_Initial;/* '<S2>/CKF_Initial' */
  P_SKF_Initial_Racing_Mode_T SKF_Initial;/* '<S2>/SKF_Initial' */
  P_WorkshopTest01_Racing_Mode_T WorkshopTest01;/* '<Root>/Workshop Test (01)' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Racing_Mode_T {
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
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Racing_Mode_T Racing_Mode_P;

/* Block signals (auto storage) */
extern B_Racing_Mode_T Racing_Mode_B;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Racing_Mode_T Racing_Mode_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Racing_Mode_T Racing_Mode_Y;

/*====================*
 * External functions *
 *====================*/
extern Racing_Mode_rtModel *Racing_Mode(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Racing_Mode_T *const Racing_Mode_M;

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
 * '<Root>' : 'Racing_Mode'
 * '<S1>'   : 'Racing_Mode/Compare To Constant'
 * '<S2>'   : 'Racing_Mode/Custom Dash (11)'
 * '<S3>'   : 'Racing_Mode/Custom Experiment Environment (12)'
 * '<S4>'   : 'Racing_Mode/Driver 1 Modes (21,31,41,51)'
 * '<S5>'   : 'Racing_Mode/Driver 2 Modes (22,32,42,52)'
 * '<S6>'   : 'Racing_Mode/Tuning'
 * '<S7>'   : 'Racing_Mode/Workshop Test (01)'
 * '<S8>'   : 'Racing_Mode/Custom Dash (11)/Apps_Sat_Dwn'
 * '<S9>'   : 'Racing_Mode/Custom Dash (11)/Apps_Sat_Up'
 * '<S10>'  : 'Racing_Mode/Custom Dash (11)/CKF_Initial'
 * '<S11>'  : 'Racing_Mode/Custom Dash (11)/Cte_CKF'
 * '<S12>'  : 'Racing_Mode/Custom Dash (11)/Cte_SKF'
 * '<S13>'  : 'Racing_Mode/Custom Dash (11)/K_Reduction_P'
 * '<S14>'  : 'Racing_Mode/Custom Dash (11)/K_Reduction_Temperature'
 * '<S15>'  : 'Racing_Mode/Custom Dash (11)/Max_Regenerative_Torque'
 * '<S16>'  : 'Racing_Mode/Custom Dash (11)/Power_Limit'
 * '<S17>'  : 'Racing_Mode/Custom Dash (11)/SKF_Initial'
 * '<S18>'  : 'Racing_Mode/Driver 1 Modes (21,31,41,51)/Acceleration (2). Driver 1 (1) '
 * '<S19>'  : 'Racing_Mode/Driver 1 Modes (21,31,41,51)/AutoX (4). Driver 1 (1)'
 * '<S20>'  : 'Racing_Mode/Driver 1 Modes (21,31,41,51)/Endurance (5). Driver 1 (1)'
 * '<S21>'  : 'Racing_Mode/Driver 1 Modes (21,31,41,51)/Skidpad (3). Driver 1 (1)'
 * '<S22>'  : 'Racing_Mode/Driver 2 Modes (22,32,42,52)/Acceleration (2). Driver 2 (2) '
 * '<S23>'  : 'Racing_Mode/Driver 2 Modes (22,32,42,52)/AutoX (4). Driver 2 (2)'
 * '<S24>'  : 'Racing_Mode/Driver 2 Modes (22,32,42,52)/Endurance (5). Driver 2 (2)'
 * '<S25>'  : 'Racing_Mode/Driver 2 Modes (22,32,42,52)/Skidpad (3). Driver 2 (2)'
 */
#endif                                 /* RTW_HEADER_Racing_Mode_h_ */
