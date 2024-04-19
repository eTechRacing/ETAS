/*****************************************************************************
 *
 * Inverters_Action_instances.c
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2024 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
  /* use void* as instance tree wrapper object pointer type */
 #define Y_PRIMIT_VOID_PTR_FOR_ADDR
#define bool RTW_bool
#include "Inverters_Action.h"
#include "Inverters_Action_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Inverters_Action_instances.h"
extern    B_Inverters_Action_T Inverters_Action_B;
extern    ConstB_Inverters_Action_T Inverters_Action_ConstB;
extern    DW_Inverters_Action_T Inverters_Action_DW;
extern    ExtU_Inverters_Action_T Inverters_Action_U;
extern    ExtY_Inverters_Action_T Inverters_Action_Y;
/* Initialization of Simulink model */
struct RTWTop_Inverters_Action_Obj *initModel_RTWTop_Inverters_Action(void)
{
    struct RTWTop_Inverters_Action_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Inverters_Action (&RTWTop_Inverters_Action_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Inverters_Action();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Inverters_Action(struct RTWTop_Inverters_Action_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Inverters_Action_B_Merge_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_B.Merge, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_B_Merge2_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_B.Merge2, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_B_Merge2_p_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_B.Merge2_p, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_B_subscribed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_B.subscribed, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_B_subscribed_b_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_B.subscribed_b, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand_Divide_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand.Divide, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_BitwiseOperator1_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0.BitwiseOperator1, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_Current0to65535_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0.Current0to65535, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_Divide_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0.Divide, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_ShiftArithmetic_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0.ShiftArithmetic, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_b7tob0_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0.b7tob0, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_BitwiseOperator1_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0_g.BitwiseOperator1, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_Current0to65535_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0_g.Current0to65535, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_Divide_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0_g.Divide, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_ShiftArithmetic_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0_g.ShiftArithmetic, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand0_g_b7tob0_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand0_g.b7tob0, sizeof(short), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_ConstB_TorqueCommand_m_Divide_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_ConstB.TorqueCommand_m.Divide, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_DW_EnumerationCounter_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_DW.EnumerationCounter, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_DW_EnumerationCounter_m_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_DW.EnumerationCounter_m, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_DW_LastAction_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_DW.LastAction, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_DW_LastAction_k_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_DW.LastAction_k, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_U_InvertersAction_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_U.InvertersAction, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_U_current_L_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_U.current_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_U_current_R_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_U.current_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_Inverter_L_RegID_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.Inverter_L_RegID, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_Inverter_L_b15tob8_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.Inverter_L_b15tob8, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_Inverter_L_b7tob0_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.Inverter_L_b7tob0, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_Inverter_R_RegID_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.Inverter_R_RegID, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_Inverter_R_b15tob8_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.Inverter_R_b15tob8, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_Inverter_R_b7tob0_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.Inverter_R_b7tob0, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Inverters_Action_Y_InvertersSubscribed_Ptr = initInstance_scalarWrapper((void*)&Inverters_Action_Y.InvertersSubscribed, sizeof(char), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Inverters_Action(ASDObjectPtr self, uint8 *buffer)
{
    uint8 definedFlg = true;
    uint32 programIdentifier = 0;
    if(definedFlg == true)
    {
        addScalar(buffer, (uint8*)&programIdentifier, sizeof(programIdentifier));
    }
    addScalar(buffer, (uint8*)&definedFlg, sizeof(definedFlg));
    return(buffer);
}
/* Class method list */
static MethodList RTWTop_Inverters_Action_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Inverters_Action
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Inverters_Action_ClassHeader =
    {0, 1, 0, 31 + 0, (MethodList *)0, (MethodList *)&RTWTop_Inverters_Action_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Inverters_Action_Class RTWTop_Inverters_Action_ClassObj = {{1, {&RTWTop_Inverters_Action_ClassHeader}, {0}}
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
};
/* Object instantiation */
struct RTWTop_Inverters_Action_Obj *initInstance_RTWTop_Inverters_Action(void)
{
    struct RTWTop_Inverters_Action_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Inverters_Action);
    return self;
}
void setDeltaT_Inverters_Action(void)
{
}