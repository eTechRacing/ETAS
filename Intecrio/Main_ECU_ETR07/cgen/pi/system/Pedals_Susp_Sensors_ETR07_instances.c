/*****************************************************************************
 *
 * Pedals_Susp_Sensors_ETR07_instances.c
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
#define bool RTW_bool
#include "Pedals_Susp_Sensors_ETR07.h"
#include "Pedals_Susp_Sensors_ETR07_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Pedals_Susp_Sensors_ETR07_instances.h"
extern    P_Pedals_Susp_Sensors_ETR07_T Pedals_Susp_Sensors_ETR07_P;
extern    ExtU_Pedals_Susp_Sensors_ETR0_T Pedals_Susp_Sensors_ETR07_U;
extern    ExtY_Pedals_Susp_Sensors_ETR0_T Pedals_Susp_Sensors_ETR07_Y;
/* Initialization of Simulink model */
struct RTWTop_Pedals_Susp_Sensors_ETR07_Obj *initModel_RTWTop_Pedals_Susp_Sensors_ETR07(void)
{
    struct RTWTop_Pedals_Susp_Sensors_ETR07_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Pedals_Susp_Sensors_ETR07 (&RTWTop_Pedals_Susp_Sensors_ETR07_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Pedals_Susp_Sensors_ETR07();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Pedals_Susp_Sensors_ETR07(struct RTWTop_Pedals_Susp_Sensors_ETR07_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Brake_Light_Threshold_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Brake_Light_Threshold_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ctemuelles_Gain_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ctemuelles_Gain_e_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain_e, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ctemuelles_Gain_f_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain_f, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ctemuelles_Gain_j_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ctemuelles_Gain_j, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Experimental_Zero_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Experimental_Zero_Value_a_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value_a, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Experimental_Zero_Value_e_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value_e, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Experimental_Zero_Value_f_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Experimental_Zero_Value_f, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ltotal_Gain_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ltotal_Gain_c_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain_c, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ltotal_Gain_d_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain_d, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Ltotal_Gain_e_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Ltotal_Gain_e, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_ON_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.ON_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_Off_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.Off_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_bitsmax_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.bitsmax_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_bitsmax_Value_e_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.bitsmax_Value_e, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_bitsmax_Value_g_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.bitsmax_Value_g, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_bitsmax_Value_n_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.bitsmax_Value_n, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_max_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.max_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_max_Value_a_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.max_Value_a, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_max_Value_f_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.max_Value_f, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_min_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.min_Value, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_min_Value_a_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.min_Value_a, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_P_min_Value_g_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_P.min_Value_g, sizeof(double), (uint32)ASD_PARAMETER);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_APPS1_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.APPS1_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_APPS2_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.APPS2_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_BrakeSensor_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.BrakeSensor_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_Susp_F_L_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.Susp_F_L_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_Susp_F_R_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.Susp_F_R_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_Susp_R_L_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.Susp_R_L_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_U_Susp_R_R_Bits_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_U.Susp_R_R_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_APPS1_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.APPS1_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_APPS2_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.APPS2_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_BrakeLight_Control_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.BrakeLight_Control, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_BrakeSensor_Value_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.BrakeSensor_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_SUSP_F_L_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.SUSP_F_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_SUSP_F_R_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.SUSP_F_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_SUSP_R_L_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.SUSP_R_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Pedals_Susp_Sensors_ETR07_Y_SUSP_R_R_Ptr = initInstance_scalarWrapper((uint32)&Pedals_Susp_Sensors_ETR07_Y.SUSP_R_R, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Pedals_Susp_Sensors_ETR07(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Pedals_Susp_Sensors_ETR07_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Pedals_Susp_Sensors_ETR07
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Pedals_Susp_Sensors_ETR07_ClassHeader =
    {0, 1, 0, 40 + 0, (MethodList *)0, (MethodList *)&RTWTop_Pedals_Susp_Sensors_ETR07_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Pedals_Susp_Sensors_ETR07_Class RTWTop_Pedals_Susp_Sensors_ETR07_ClassObj = {{1, {&RTWTop_Pedals_Susp_Sensors_ETR07_ClassHeader}, {0}}
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
struct RTWTop_Pedals_Susp_Sensors_ETR07_Obj *initInstance_RTWTop_Pedals_Susp_Sensors_ETR07(void)
{
    struct RTWTop_Pedals_Susp_Sensors_ETR07_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Pedals_Susp_Sensors_ETR07);
    return self;
}
void setDeltaT_Pedals_Susp_Sensors_ETR07(void)
{
}
