/* Patched in by the INTECRIO IRT target */
/* PATCH BEGIN */
#include "Torque_Control_irtmacros.h"
/* PATCH END */

/*
 * Torque_Control.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Torque_Control".
 *
 * Model version              : 10.1
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Fri Nov 17 17:17:31 2023
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Torque_Control_h_
#define RTW_HEADER_Torque_Control_h_
#ifndef Torque_Control_COMMON_INCLUDES_
#define Torque_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* Torque_Control_COMMON_INCLUDES_ */

#include "Torque_Control_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include "rt_defines.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Torque_Control_rtModel         RT_MODEL_Torque_Control_T

/* Block signals for system '<S127>/MATLAB Function' */
typedef struct {
  real_T RegTq_RR;                     /* '<S127>/MATLAB Function' */
  real_T RegTq_RL;                     /* '<S127>/MATLAB Function' */
} B_MATLABFunction_Torque_Contr_T;

/* Block signals for system '<S115>/Braking with Regenerative' */
typedef struct {
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction;/* '<S127>/MATLAB Function' */
} B_BrakingwithRegenerative_Tor_T;

/* Block signals for system '<S116>/Accelerator behaviour ' */
typedef struct {
  real_T throttle;                     /* '<S116>/Accelerator behaviour ' */
} B_Acceleratorbehaviour_Torque_T;

/* Block signals for system '<S83>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S83>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Cont_T;

/* Block signals for system '<S123>/MATLAB Function' */
typedef struct {
  real_T RPM;                          /* '<S123>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_d_T;

/* Block signals for system '<S166>/MATLAB Function' */
typedef struct {
  real_T SKF_act0;                     /* '<S166>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_i_T;

/* Block signals for system '<S163>/MATLAB Function' */
typedef struct {
  real_T CKF_act1;                     /* '<S163>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_k_T;

/* Block signals for system '<S162>/MATLAB Function1' */
typedef struct {
  real_T CKF_act0;                     /* '<S162>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_m_T;

/* Block signals for system '<S120>/MATLAB Function' */
typedef struct {
  real_T value;                        /* '<S120>/MATLAB Function' */
} B_MATLABFunction_Torque_Con_h_T;

/* Block signals for system '<S125>/MATLAB Function1' */
typedef struct {
  real_T value;                        /* '<S125>/MATLAB Function1' */
} B_MATLABFunction1_Torque_Co_d_T;

/* Block signals (default storage) */
typedef struct {
  real_T kamm_data[544];
  real_T Abs2;                         /* '<Root>/Abs2' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Probe[2];                     /* '<S223>/Probe' */
  real_T Add2;                         /* '<S218>/Add2' */
  real_T Integrator;                   /* '<S228>/Integrator' */
  real_T Probe_d[2];                   /* '<S231>/Probe' */
  real_T Add2_c;                       /* '<S219>/Add2' */
  real_T Integrator_k;                 /* '<S236>/Integrator' */
  real_T Probe_j[2];                   /* '<S239>/Probe' */
  real_T Add2_e;                       /* '<S220>/Add2' */
  real_T Integrator_a;                 /* '<S244>/Integrator' */
  real_T Min;                          /* '<S214>/Min' */
  real_T Merge3;                       /* '<Root>/Merge3' */
  real_T Merge;                        /* '<Root>/Merge' */
  real_T Abs;                          /* '<S12>/Abs' */
  real_T AvoidDividebyZero;            /* '<S223>/Avoid Divide by Zero' */
  real_T uT;                           /* '<S221>/1//T' */
  real_T AvoidDividebyZero_l;          /* '<S231>/Avoid Divide by Zero' */
  real_T uT_i;                         /* '<S229>/1//T' */
  real_T AvoidDividebyZero_f;          /* '<S239>/Avoid Divide by Zero' */
  real_T uT_p;                         /* '<S237>/1//T' */
  real_T Merge_b;                      /* '<S71>/Merge' */
  real_T Merge1;                       /* '<S71>/Merge1' */
  real_T Merge2;                       /* '<S71>/Merge2' */
  real_T Merge3_b;                     /* '<S71>/Merge3' */
  real_T Merge1_a;                     /* '<S70>/Merge1' */
  real_T Merge_l;                      /* '<S72>/Merge' */
  real_T Gain_n;                       /* '<S72>/Gain' */
  real_T MergeTq_RL;                   /* '<S72>/Merge Tq_RL' */
  real_T MergeTq_RR;                   /* '<S72>/Merge Tq_RR' */
  real_T Merge2_l;                     /* '<S72>/Merge2' */
  real_T Merge3_c;                     /* '<S72>/Merge3' */
  real_T Saturation;                   /* '<S93>/Saturation' */
  real_T Switch;                       /* '<S93>/Switch' */
  real_T SignalGenerator;              /* '<S93>/Signal Generator' */
  real_T SineWave;                     /* '<S93>/Sine Wave' */
  real_T Merge_d;                      /* '<S87>/Merge' */
  real_T Merge1_p;                     /* '<S87>/Merge1' */
  real_T Merge_k;                      /* '<S104>/Merge' */
  real_T Saturation_c;                 /* '<S104>/Saturation' */
  real_T Switch1;                      /* '<S108>/Switch1' */
  real_T Merge_kj;                     /* '<S106>/Merge' */
  real_T Saturation_k;                 /* '<S106>/Saturation' */
  real_T Merge_g;                      /* '<S206>/Merge' */
  real_T Merge_li;                     /* '<S175>/Merge' */
  real_T Merge1_l;                     /* '<S175>/Merge1' */
  real_T Merge2_o;                     /* '<S182>/Merge2' */
  real_T Saturation_j;                 /* '<S123>/Saturation' */
  real_T Switch_p;                     /* '<S123>/Switch' */
  real_T Merge2_lx;                    /* '<S83>/Merge2' */
  real_T Divide;                       /* '<S171>/Divide' */
  real_T Merge3_e;                     /* '<S83>/Merge3' */
  real_T Divide_i;                     /* '<S170>/Divide' */
  real_T Merge_kt;                     /* '<S116>/Merge' */
  real_T Merge1_b;                     /* '<S116>/Merge1' */
  real_T Merge_m;                      /* '<S83>/Merge' */
  real_T Merge1_n;                     /* '<S83>/Merge1' */
  real_T Merge4;                       /* '<S83>/Merge4' */
  real_T Merge5;                       /* '<S83>/Merge5' */
  real_T Merge6;                       /* '<S83>/Merge6' */
  real_T Merge7;                       /* '<S83>/Merge7' */
  real_T OutportBufferForFlags_num5[4];/* '<S83>/Flags' */
  real_T Sum3;                         /* '<S119>/Sum3' */
  real_T Divide_a;                     /* '<S150>/Divide' */
  real_T Gain1_c;                      /* '<S147>/Gain1' */
  real_T Gain4;                        /* '<S147>/Gain4' */
  real_T Gain3;                        /* '<S147>/Gain3' */
  real_T Gain2;                        /* '<S147>/Gain2' */
  real_T Gain_p;                       /* '<S147>/Gain' */
  real_T radius;                       /* '<S147>/Bicycle Model' */
  real_T yf;                           /* '<S147>/Bicycle Model' */
  real_T yr;                           /* '<S147>/Bicycle Model' */
  real_T Merge_c;                      /* '<S159>/Merge' */
  real_T Saturation_i;                 /* '<S159>/Saturation' */
  real_T Merge_i;                      /* '<S161>/Merge' */
  real_T Saturation_f;                 /* '<S161>/Saturation' */
  real_T Throttle;                     /* '<S136>/Throttle' */
  real_T Merge2_j;                     /* '<S126>/Merge2' */
  real_T OutportBufferForFlag_Power;   /* '<S126>/Constant' */
  real_T Braking; /* '<Root>/SoP selection and sum of max WHEEL Tq available' */
  real_T Probe_a[2];                   /* '<S33>/Probe' */
  real_T Probe_o[2];                   /* '<S41>/Probe' */
  real_T Probe_n[2];                   /* '<S49>/Probe' */
  real_T uT_l;                         /* '<S31>/1//T' */
  real_T uT_io;                        /* '<S39>/1//T' */
  real_T uT_m;                         /* '<S47>/1//T' */
  real_T Merge1_pg;                    /* '<S15>/Merge1' */
  real_T Merge1_a0;                    /* '<Root>/Merge1' */
  real_T Merge2_e;                     /* '<Root>/Merge2' */
  boolean_T Merge_j;                   /* '<S56>/Merge' */
  boolean_T LogicalOperator;           /* '<S10>/Logical Operator' */
  boolean_T Compare;                   /* '<S226>/Compare' */
  boolean_T Compare_c;                 /* '<S234>/Compare' */
  boolean_T Compare_i;                 /* '<S242>/Compare' */
  boolean_T Compare_b;                 /* '<S36>/Compare' */
  boolean_T Compare_n;                 /* '<S44>/Compare' */
  boolean_T Compare_e;                 /* '<S52>/Compare' */
  boolean_T Compare_f;                 /* '<S25>/Compare' */
  boolean_T Compare_d;                 /* '<S26>/Compare' */
  boolean_T Compare_g;                 /* '<S27>/Compare' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_o;/* '<S85>/Accelerator behaviour ' */
  B_MATLABFunction1_Torque_Co_m_T sf_MATLABFunction_k2;/* '<S107>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_i_T sf_MATLABFunction_fq;/* '<S111>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_ab;/* '<S93>/MATLAB Function' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_br;/* '<S82>/Accelerator behaviour' */
  B_MATLABFunction_Torque_Contr_T sf_MATLABFunction1_h;/* '<S99>/MATLAB Function1' */
  B_MATLABFunction1_Torque_Co_m_T sf_MATLABFunction_a;/* '<S207>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_k_T sf_MATLABFunction_i;/* '<S208>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_fa;/* '<S180>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_b;/* '<S178>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_f;/* '<S178>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_m;/* '<S176>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_gm;/* '<S176>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour_b;/* '<S191>/Accelerator behaviour ' */
  B_BrakingwithRegenerative_Tor_T BrakingwithRegenerative_b;/* '<S174>/Braking with Regenerative' */
  B_MATLABFunction1_Torque_Co_d_T sf_MATLABFunction2_k;/* '<S125>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Co_d_T sf_MATLABFunction1_m;/* '<S125>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction2_e;/* '<S119>/MATLAB Function2' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_mk;/* '<S119>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction1_g;/* '<S120>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_h_T sf_MATLABFunction_d;/* '<S120>/MATLAB Function' */
  B_MATLABFunction1_Torque_Co_m_T sf_MATLABFunction1_b;/* '<S162>/MATLAB Function1' */
  B_MATLABFunction_Torque_Con_k_T sf_MATLABFunction_mt;/* '<S163>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_i_T sf_MATLABFunction_ed;/* '<S166>/MATLAB Function' */
  B_MATLABFunction_Torque_Con_d_T sf_MATLABFunction_n;/* '<S123>/MATLAB Function' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction2;/* '<S83>/MATLAB Function2' */
  B_MATLABFunction1_Torque_Cont_T sf_MATLABFunction1_n;/* '<S83>/MATLAB Function1' */
  B_Acceleratorbehaviour_Torque_T sf_Acceleratorbehaviour;/* '<S116>/Accelerator behaviour ' */
  B_BrakingwithRegenerative_Tor_T BrakingwithRegenerative;/* '<S115>/Braking with Regenerative' */
} B_Torque_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S228>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S236>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S244>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S38>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S46>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S54>/Integrator' */
  real_T TimeStampA;                   /* '<S93>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S93>/Derivative' */
  real_T TimeStampB;                   /* '<S93>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S93>/Derivative' */
  real_T A;                            /* '<S93>/Data Store Memory' */
  real_T B;                            /* '<S93>/Data Store Memory1' */
  real_T TimeStampA_b;                 /* '<S180>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<S180>/Derivative' */
  real_T TimeStampB_e;                 /* '<S180>/Derivative' */
  real_T LastUAtTimeB_o;               /* '<S180>/Derivative' */
  real_T B_k;                          /* '<S180>/Data Store Memory1' */
  real_T TimeStampA_g;                 /* '<S123>/Derivative' */
  real_T LastUAtTimeA_c;               /* '<S123>/Derivative' */
  real_T TimeStampB_c;                 /* '<S123>/Derivative' */
  real_T LastUAtTimeB_f;               /* '<S123>/Derivative' */
  real_T A_b;                          /* '<S123>/Data Store Memory' */
  real_T B_i;                          /* '<S123>/Data Store Memory1' */
  real_T A_i;                          /* '<S15>/Data Store Memory10' */
  int8_T If_ActiveSubsystem;           /* '<S56>/If' */
  int8_T If_ActiveSubsystem_k;         /* '<S12>/If' */
  int8_T Integrator_PrevResetState;    /* '<S228>/Integrator' */
  int8_T Integrator_PrevResetState_h;  /* '<S236>/Integrator' */
  int8_T Integrator_PrevResetState_c;  /* '<S244>/Integrator' */
  int8_T If_ActiveSubsystem_e;         /* '<Root>/If' */
  int8_T If1_ActiveSubsystem;          /* '<Root>/If1' */
  int8_T If_ActiveSubsystem_ed;        /* '<S73>/If' */
  int8_T If_ActiveSubsystem_a;         /* '<S71>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S70>/If' */
  int8_T If_ActiveSubsystem_j;         /* '<S72>/If' */
  int8_T FAILUREMODE_ActiveSubsystem;  /* '<S72>/FAILURE MODE' */
  int8_T SKForCKF_ActiveSubsystem;     /* '<S103>/SKF or CKF' */
  int8_T If1_ActiveSubsystem_c;        /* '<S82>/If1' */
  int8_T If_ActiveSubsystem_d;         /* '<S82>/If' */
  int8_T BrakingConditions_ActiveSubsyst;/* '<S87>/Braking Conditions' */
  int8_T If1_ActiveSubsystem_ca;       /* '<S104>/If1' */
  int8_T If_ActiveSubsystem_jm;        /* '<S106>/If' */
  int8_T If1_ActiveSubsystem_a;        /* '<S206>/If1' */
  int8_T BrakingConditions_ActiveSubsy_c;/* '<S175>/Braking Conditions' */
  int8_T If_ActiveSubsystem_h;         /* '<S174>/If' */
  int8_T If1_ActiveSubsystem_b;        /* '<S182>/If1' */
  int8_T SKForCKF_ActiveSubsystem_o;   /* '<S158>/SKF or CKF' */
  int8_T Steer_angisinSteer_SatrangeLong;
  /* '<S83>/Steer_ang is in Steer_Sat range ---> Long Steer_ang is not in Steer_Sat range -> Lat ' */
  int8_T BrakingConditions_ActiveSubsy_b;/* '<S116>/Braking Conditions' */
  int8_T If_ActiveSubsystem_aq;        /* '<S115>/If' */
  int8_T If1_ActiveSubsystem_o;        /* '<S159>/If1' */
  int8_T If_ActiveSubsystem_ha;        /* '<S161>/If' */
  int8_T If1_ActiveSubsystem_bn;       /* '<S126>/If1' */
  int8_T Integrator_PrevResetState_b;  /* '<S38>/Integrator' */
  int8_T Integrator_PrevResetState_f;  /* '<S46>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S54>/Integrator' */
  int8_T If_ActiveSubsystem_kl;        /* '<S15>/If' */
  int8_T If_ActiveSubsystem_c;         /* '<S17>/If' */
  uint8_T Integrator_IC_LOADING;       /* '<S228>/Integrator' */
  uint8_T Integrator_IC_LOADING_m;     /* '<S236>/Integrator' */
  uint8_T Integrator_IC_LOADING_b;     /* '<S244>/Integrator' */
  uint8_T Integrator_IC_LOADING_g;     /* '<S38>/Integrator' */
  uint8_T Integrator_IC_LOADING_k;     /* '<S46>/Integrator' */
  uint8_T Integrator_IC_LOADING_e;     /* '<S54>/Integrator' */
} DW_Torque_Control_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S119>/Integrator' */
} X_Torque_Control_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S119>/Integrator' */
} XDot_Torque_Control_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S119>/Integrator' */
} XDis_Torque_Control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T RT_L;                   /* '<S81>/RT_L' */
  const real_T RT_R;                   /* '<S81>/RT_R' */
  const real_T Product;                /* '<S177>/Product' */
  const real_T DiametertoRadius;       /* '<S177>/Diameter to Radius' */
  const real_T inchtom;                /* '<S177>/inch to m' */
  const real_T udifference;            /* '<S177>/3% difference' */
  const real_T approx2095;             /* '<S182>/Gain' */
  const real_T TowheelTqdynamic;       /* '<S182>/To wheel Tq (dynamic)' */
  const real_T TowheelTqstatic;        /* '<S182>/To wheel Tq (static)' */
  const real_T DiametertoRadius_j;     /* '<S118>/Diameter to Radius' */
  const real_T inchtom1;               /* '<S118>/inch to m1' */
  const real_T udifference1;           /* '<S118>/3% difference1' */
  const real_T Divide1;                /* '<S149>/Divide1' */
  const real_T u602pi;                 /* '<S147>/360//(2*pi)' */
  const real_T u602pi_e;               /* '<S147>/360//(2pi)' */
  const real_T approx2095_h;           /* '<S126>/Gain' */
  const real_T Constant;               /* '<S126>/Constant' */
} ConstB_Torque_Control_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T VDC_SKF_Initial;              /* '<Root>/VDC_SKF_Initial' */
  real_T VDC_CKF_Initial;              /* '<Root>/VDC_CKF_Initial' */
  real_T VDC_Cte_SKF;                  /* '<Root>/VDC_Cte_SKF' */
  real_T VDC_Cte_CKF;                  /* '<Root>/VDC_Cte_CKF' */
  real_T VDC_Apps_Sat_Down;            /* '<Root>/VDC_Apps_Sat_Down' */
  real_T VDC_Apps_Sat_Up;              /* '<Root>/VDC_Apps_Sat_Up' */
  real_T VDC_Max_Regenerative_Torque; /* '<Root>/VDC_Max_Regenerative_Torque' */
  real_T VDC_Power_Limit;              /* '<Root>/VDC_Power_Limit' */
  real_T VDC_K_Reduction_P;            /* '<Root>/VDC_K_Reduction_P' */
  real_T VDC_K_Reduction_Temperature; /* '<Root>/VDC_K_Reduction_Temperature' */
  real_T Workshop_Mode_Enable;         /* '<Root>/Workshop_Mode_Enable' */
  boolean_T TorqueEnable;              /* '<Root>/TorqueEnable' */
  real_T TV_Mode;                      /* '<Root>/TV_Mode' */
  real_T Highest_CellTemp;             /* '<Root>/Highest_CellTemp' */
  boolean_T CriticalDisconnection;     /* '<Root>/CriticalDisconnection' */
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
  real_T SoC_Low;                      /* '<Root>/SoC_Low' */
  real_T SoC_High;                     /* '<Root>/SoC_High' */
  real_T SteeringSensor_Value;         /* '<Root>/SteeringSensor_Value' */
  boolean_T Shutdown_OK;               /* '<Root>/Shutdown_OK' */
} ExtU_Torque_Control_T;

/* External outputs (root outports fed by signals with default storage) */
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
  boolean_T APPS_Implausibility;       /* '<Root>/APPS_Implausibility' */
  real_T TV_Flag_WheelSpinRR;          /* '<Root>/TV_Flag_WheelSpinRR' */
  real_T TV_Flag_WheelSpinRL;          /* '<Root>/TV_Flag_WheelSpinRL' */
  real_T TV_Flag_Power;                /* '<Root>/TV_Flag_Power' */
  real_T TV_Flag_CarBehaviour;         /* '<Root>/TV_Flag_CarBehaviour' */
  real_T Power;                        /* '<Root>/Power' */
  real_T PowerLimitReached;            /* '<Root>/PowerLimitReached' */
  real_T PowerMean500ms;               /* '<Root>/PowerMean500ms' */
  boolean_T Torque_OK;                 /* '<Root>/Torque_OK' */
  real_T Regenerative_Enable;          /* '<Root>/Regenerative_Enable' */
  real_T MeasVDCTorque_L;              /* '<Root>/Meas VDC Torque_L' */
  real_T MeasVDCTorque_R;              /* '<Root>/Meas VDC Torque_R' */
  real_T Torque_L;                     /* '<Root>/Torque_L' */
  real_T Torque_R;                     /* '<Root>/Torque_R' */
  real_T current_L;                    /* '<Root>/current_L' */
  real_T current_R;                    /* '<Root>/current_R' */
  real_T TV_Flag_Temperature;          /* '<Root>/TV_Flag_Temperature' */
} ExtY_Torque_Control_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Torque_Control_B
#define BlockIO                        B_Torque_Control_T
#define rtU                            Torque_Control_U
#define ExternalInputs                 ExtU_Torque_Control_T
#define rtX                            Torque_Control_X
#define ContinuousStates               X_Torque_Control_T
#define rtXdot                         Torque_Control_XDot
#define StateDerivatives               XDot_Torque_Control_T
#define tXdis                          Torque_Control_XDis
#define StateDisabled                  XDis_Torque_Control_T
#define rtY                            Torque_Control_Y
#define ExternalOutputs                ExtY_Torque_Control_T
#define rtDWork                        Torque_Control_DW
#define D_Work                         DW_Torque_Control_T
#define tConstBlockIOType              ConstB_Torque_Control_T
#define rtC                            Torque_Control_ConstB

/* Real-time Model Data Structure */
struct tag_RTM_Torque_Control_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
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

/* Block signals (default storage) */
extern B_Torque_Control_T Torque_Control_B;

/* Continuous states (default storage) */
extern X_Torque_Control_T Torque_Control_X;

/* Block states (default storage) */
extern DW_Torque_Control_T Torque_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Torque_Control_T Torque_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Torque_Control_T Torque_Control_Y;
extern ConstB_Torque_Control_T Torque_Control_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Torque_Control_initialize(void);
extern void Torque_Control_output(void);
extern void Torque_Control_update(void);
extern void Torque_Control_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Torque_Control_rtModel *Torque_Control(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Torque_Control_T *const Torque_Control_M;

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
 * '<Root>' : 'Torque_Control'
 * '<S1>'   : 'Torque_Control/Accumulator Power'
 * '<S2>'   : 'Torque_Control/Calculate Current Conversion'
 * '<S3>'   : 'Torque_Control/Controls Temperature by limiting Torque'
 * '<S4>'   : 'Torque_Control/Current 0'
 * '<S5>'   : 'Torque_Control/Flag_Temp merged'
 * '<S6>'   : 'Torque_Control/If Action Subsystem'
 * '<S7>'   : 'Torque_Control/MATLAB Function'
 * '<S8>'   : 'Torque_Control/MATLAB Function1'
 * '<S9>'   : 'Torque_Control/Power limitation'
 * '<S10>'  : 'Torque_Control/SAFETY BLOCK'
 * '<S11>'  : 'Torque_Control/SoP selection and sum of max WHEEL Tq available'
 * '<S12>'  : 'Torque_Control/VDC'
 * '<S13>'  : 'Torque_Control/W to kW'
 * '<S14>'  : 'Torque_Control/power_limitation'
 * '<S15>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection'
 * '<S16>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/LimitReached'
 * '<S17>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch'
 * '<S18>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch/Latched Error'
 * '<S19>'  : 'Torque_Control/Accumulator Power/PowerLimitDetection/OK_OrLatch/OK'
 * '<S20>'  : 'Torque_Control/Calculate Current Conversion/KT_L_TORKY'
 * '<S21>'  : 'Torque_Control/Calculate Current Conversion/KT_R_EMY'
 * '<S22>'  : 'Torque_Control/Controls Temperature by limiting Torque/SoC_SoP'
 * '<S23>'  : 'Torque_Control/Controls Temperature by limiting Torque/Tq_limitation because of Temp'
 * '<S24>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP'
 * '<S25>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/Flag_Accu'
 * '<S26>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/Flag_Inv'
 * '<S27>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/Flag_Mot'
 * '<S28>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu'
 * '<S29>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters'
 * '<S30>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors'
 * '<S31>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1'
 * '<S32>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Temp higher than 50'
 * '<S33>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant'
 * '<S34>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Initialization'
 * '<S35>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
 * '<S36>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Zero'
 * '<S37>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Initialization/Init_u'
 * '<S38>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
 * '<S39>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)'
 * '<S40>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Temp higher than 50'
 * '<S41>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S42>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S43>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S44>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S45>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S46>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S47>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)'
 * '<S48>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Temp higher than 110'
 * '<S49>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S50>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S51>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S52>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S53>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S54>'  : 'Torque_Control/Controls Temperature by limiting Torque/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S55>'  : 'Torque_Control/Power limitation/MATLAB Function'
 * '<S56>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY'
 * '<S57>'  : 'Torque_Control/SAFETY BLOCK/Compare To Constant'
 * '<S58>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Imp'
 * '<S59>'  : 'Torque_Control/SAFETY BLOCK/APPS_IMPLAUSIBILITY/Not Imp'
 * '<S60>'  : 'Torque_Control/VDC/DocBlock'
 * '<S61>'  : 'Torque_Control/VDC/DocBlock1'
 * '<S62>'  : 'Torque_Control/VDC/DocBlock10'
 * '<S63>'  : 'Torque_Control/VDC/DocBlock2'
 * '<S64>'  : 'Torque_Control/VDC/DocBlock3'
 * '<S65>'  : 'Torque_Control/VDC/DocBlock4'
 * '<S66>'  : 'Torque_Control/VDC/DocBlock5'
 * '<S67>'  : 'Torque_Control/VDC/DocBlock6'
 * '<S68>'  : 'Torque_Control/VDC/DocBlock8'
 * '<S69>'  : 'Torque_Control/VDC/DocBlock9'
 * '<S70>'  : 'Torque_Control/VDC/Regeneration_Enable'
 * '<S71>'  : 'Torque_Control/VDC/TEST_MODE_IN'
 * '<S72>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes'
 * '<S73>'  : 'Torque_Control/VDC/WORKSHOP_MODE_RESTRICTIONS'
 * '<S74>'  : 'Torque_Control/VDC/Regeneration_Enable/Enabled '
 * '<S75>'  : 'Torque_Control/VDC/Regeneration_Enable/NotEnabled'
 * '<S76>'  : 'Torque_Control/VDC/TEST_MODE_IN/BYPASS'
 * '<S77>'  : 'Torque_Control/VDC/TEST_MODE_IN/TEST_CONSTANTS'
 * '<S78>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Automatic Failure Mode'
 * '<S79>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/If Action Subsystem'
 * '<S80>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Manual Failure Mode Selection'
 * '<S81>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Rigid Axle'
 * '<S82>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC'
 * '<S83>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete'
 * '<S84>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal'
 * '<S85>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Rigid Axle/Accelerating'
 * '<S86>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Rigid Axle/Accelerating/Accelerator behaviour '
 * '<S87>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking'
 * '<S88>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Inertia or Braking without Regen'
 * '<S89>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerator behaviour'
 * '<S90>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Lateral Dynamics'
 * '<S91>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Longitudinal Dynamics'
 * '<S92>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/MATLAB Function1'
 * '<S93>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF'
 * '<S94>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Regenerating'
 * '<S95>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Steering TV 2017 (without TC)'
 * '<S96>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Accelerating'
 * '<S97>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Inertia Braking'
 * '<S98>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Mech_Braking'
 * '<S99>'  : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking'
 * '<S100>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking/MATLAB Function'
 * '<S101>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Accelerating, Braking or Regen Braking/Regenerative+Mech Braking/MATLAB Function1'
 * '<S102>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/MATLAB Function'
 * '<S103>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  '
 * '<S104>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S105>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S106>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S107>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S108>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S109>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S110>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S111>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S112>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S113>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S114>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/Steering TV with TC/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S115>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq'
 * '<S116>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours'
 * '<S117>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Flags'
 * '<S118>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/In_Numbers'
 * '<S119>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics'
 * '<S120>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics'
 * '<S121>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/MATLAB Function1'
 * '<S122>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/MATLAB Function2'
 * '<S123>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF'
 * '<S124>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Sensor_DATA'
 * '<S125>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor'
 * '<S126>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative'
 * '<S127>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Braking with Regenerative'
 * '<S128>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/If Action 1'
 * '<S129>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/If Action 2'
 * '<S130>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/MATLAB Function'
 * '<S131>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S132>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/minimum value'
 * '<S133>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/minimum value1'
 * '<S134>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S135>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Constraints and motor to wheel Tq/Braking with Regenerative/MATLAB Function'
 * '<S136>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Accelerating'
 * '<S137>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Accelerator behaviour '
 * '<S138>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Inertia Braking'
 * '<S139>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Mech_Braking'
 * '<S140>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S141>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Driver // CarBehaviours/Regenerative+Mech Braking/MATLAB Function'
 * '<S142>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Force Difference with  Max. Tire Forces'
 * '<S143>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Kamm_Circle'
 * '<S144>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/MATLAB Function1'
 * '<S145>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/MATLAB Function2'
 * '<S146>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference'
 * '<S147>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Yaw_Rate_Reference'
 * '<S148>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S149>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/ Momentum_Z to Longitudinal Force Difference'
 * '<S150>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Tire Longitudinal  Force Difference/Momentum respect to Z-axis to correct the error'
 * '<S151>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Lateral Dynamics/Yaw_Rate_Reference/Bicycle Model'
 * '<S152>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/Kamm_Circle'
 * '<S153>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/MATLAB Function'
 * '<S154>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/MATLAB Function1'
 * '<S155>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/minimum value'
 * '<S156>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Longitudinal Dynamics/Kamm_Circle/Kamm_Circle LatD'
 * '<S157>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/MATLAB Function'
 * '<S158>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  '
 * '<S159>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S160>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /MATLAB Function1'
 * '<S161>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF'
 * '<S162>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S163>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S164>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function1'
 * '<S165>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S166>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin'
 * '<S167>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin'
 * '<S168>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/No spin/MATLAB Function'
 * '<S169>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Optimization SKF & CKF/Subsystem  /SKF/Spin/MATLAB Function'
 * '<S170>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/Fx_to_engineTqRL'
 * '<S171>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/Fx_to_engineTqRR'
 * '<S172>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/MATLAB Function1'
 * '<S173>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC Complete/Wheel_to_motor/MATLAB Function2'
 * '<S174>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints'
 * '<S175>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours'
 * '<S176>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq'
 * '<S177>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/In_Numbers'
 * '<S178>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral'
 * '<S179>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Lateral Dynamics'
 * '<S180>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF'
 * '<S181>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Sensor_DATA'
 * '<S182>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative'
 * '<S183>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Braking with Regenerative'
 * '<S184>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 1'
 * '<S185>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/If Action 2'
 * '<S186>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled'
 * '<S187>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value'
 * '<S188>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/minimum value1'
 * '<S189>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Acelerating and braking without Regenerative/Momentum Z scaled/MATLAB Function'
 * '<S190>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Constraints/Braking with Regenerative/MATLAB Function'
 * '<S191>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Accelerating'
 * '<S192>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Inertia Braking'
 * '<S193>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Mech_Braking'
 * '<S194>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking'
 * '<S195>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Accelerating/Accelerator behaviour '
 * '<S196>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Driver // CarBehaviours/Regenerative+Mech Braking/MATLAB Function'
 * '<S197>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/Fx_to_wheelTqRL'
 * '<S198>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/Fx_to_wheelTqRR'
 * '<S199>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/MATLAB Function1'
 * '<S200>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Force to Tq/MATLAB Function2'
 * '<S201>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/Kamm_Circle LatD'
 * '<S202>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/MATLAB Function1'
 * '<S203>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Kamm Circle Lateral/MATLAB Function2'
 * '<S204>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/MATLAB Function'
 * '<S205>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  '
 * '<S206>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF'
 * '<S207>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin'
 * '<S208>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin '
 * '<S209>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/No spin/MATLAB Function'
 * '<S210>' : 'Torque_Control/VDC/Vehicle Dynamics Control Modes/VDC without Longitudinal/Optimization SKF & CKF/Subsystem  /CKF/Spin /MATLAB Function'
 * '<S211>' : 'Torque_Control/VDC/WORKSHOP_MODE_RESTRICTIONS/BYPASS'
 * '<S212>' : 'Torque_Control/VDC/WORKSHOP_MODE_RESTRICTIONS/Torque_Reduction '
 * '<S213>' : 'Torque_Control/power_limitation/SoC_SoP'
 * '<S214>' : 'Torque_Control/power_limitation/temperature_SoP'
 * '<S215>' : 'Torque_Control/power_limitation/temperature_SoP/Flag_Accu'
 * '<S216>' : 'Torque_Control/power_limitation/temperature_SoP/Flag_Inv'
 * '<S217>' : 'Torque_Control/power_limitation/temperature_SoP/Flag_Mot'
 * '<S218>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu'
 * '<S219>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters'
 * '<S220>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors'
 * '<S221>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1'
 * '<S222>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Temp higher than 50'
 * '<S223>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant'
 * '<S224>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Initialization'
 * '<S225>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
 * '<S226>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Zero'
 * '<S227>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Initialization/Init_u'
 * '<S228>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Accu/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
 * '<S229>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)'
 * '<S230>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Temp higher than 50'
 * '<S231>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S232>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S233>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S234>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S235>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S236>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Inverters/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S237>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)'
 * '<S238>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Temp higher than 110'
 * '<S239>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
 * '<S240>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Initialization'
 * '<S241>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S242>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
 * '<S243>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Initialization/Init_u'
 * '<S244>' : 'Torque_Control/power_limitation/temperature_SoP/temperature_rise_limitator_Motors/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 */
#endif                                 /* RTW_HEADER_Torque_Control_h_ */
