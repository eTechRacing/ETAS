/*****************************************************************************
 *
 * Synchronism_instances.h
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
/* Model initialization function prototype */
extern struct RTWTop_Synchronism_Obj *initModel_RTWTop_Synchronism(void);
/* Level 1 class object declaration */
extern struct RTWTop_Synchronism_Class RTWTop_Synchronism_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Synchronism(struct RTWTop_Synchronism_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Synchronism_Obj *initInstance_RTWTop_Synchronism(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Synchronism(void);
/* Definition of the class structure */
struct RTWTop_Synchronism_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Synchronism_DW_counter_Ptr;
    scalarWrapper_Obj *RTWWrapper_Synchronism_P_Constant1_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Synchronism_P_Constant_Value_Ptr;
    scalarWrapper_Obj *RTWWrapper_Synchronism_P_Constant_Value_e_Ptr;
    scalarWrapper_Obj *RTWWrapper_Synchronism_P_DataStoreMemory_InitialValue_Ptr;
    scalarWrapper_Obj *RTWWrapper_Synchronism_Y_Sync_CAN1_Ptr;
    scalarWrapper_Obj *RTWWrapper_Synchronism_Y_Sync_CAN2_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Synchronism_Obj
{
    ASDObjectHeader objectHeader;
};
