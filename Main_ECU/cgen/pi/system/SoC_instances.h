/*****************************************************************************
 *
 * SoC_instances.h
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2024 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
/* Model initialization function prototype */
extern struct RTWTop_SoC_Obj *initModel_RTWTop_SoC(void);
/* Level 1 class object declaration */
extern struct RTWTop_SoC_Class RTWTop_SoC_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_SoC(struct RTWTop_SoC_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_SoC_Obj *initInstance_RTWTop_SoC(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_SoC(void);
/* Definition of the class structure */
struct RTWTop_SoC_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_SoC_B_AccuOCVtoSOC2024_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_B_CellOCVtoSOC2024H_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_B_CellOCVtoSOC2024L_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_CoreSubsys_0__Probe_Ptr;
    matrixWrapper_Obj *RTWWrapper_SoC_B_CoreSubsys_0__Product8_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_CoreSubsys_0__Sum_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_CoreSubsys_0__TmpSignalConversionAtDelayInpor_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_H_0__CoreSubsys_Probe_Ptr;
    matrixWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_H_0__CoreSubsys_Product8_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_H_0__CoreSubsys_Sum_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_H_0__CoreSubsys_TmpSignalConversionAtDelayInpor_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_L_0__CoreSubsys_Probe_Ptr;
    matrixWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_L_0__CoreSubsys_Product8_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_L_0__CoreSubsys_Sum_Ptr;
    vectorWrapper_Obj *RTWWrapper_SoC_B_uRC_Cell_L_0__CoreSubsys_TmpSignalConversionAtDelayInpor_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_U_Accumulator_Current_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_U_Accumulator_Voltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_U_Average_CellTemp_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_U_Highest_CellVoltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_U_Lowest_CellVoltage_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_Y_SoC_Avg_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_Y_SoC_High_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_Y_SoC_KF_Ptr;
    scalarWrapper_Obj *RTWWrapper_SoC_Y_SoC_Low_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_SoC_Obj
{
    ASDObjectHeader objectHeader;
};
