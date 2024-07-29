/*****************************************************************************
 *
 * Sensors_instances.c
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
#include "Sensors.h"
#include "Sensors_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Sensors_instances.h"
extern    ConstB_Sensors_T Sensors_ConstB;
extern    DW_Sensors_T Sensors_DW;
extern    ExtU_Sensors_T Sensors_U;
extern    ExtY_Sensors_T Sensors_Y;
/* Initialization of Simulink model */
struct RTWTop_Sensors_Obj *initModel_RTWTop_Sensors(void)
{
    struct RTWTop_Sensors_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Sensors (&RTWTop_Sensors_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Sensors();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Sensors(struct RTWTop_Sensors_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Sensors_ConstB_Subtract_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Subtract, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Subtract_a_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Subtract_a, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Subtract_e_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Subtract_e, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Subtract_n_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Subtract_n, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Subtract_p_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Subtract_p, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Sum1_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Sum1, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Sum1_c_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Sum1_c, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_ConstB_Sum1_d_Ptr = initInstance_scalarWrapper((void*)&Sensors_ConstB.Sum1_d, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_DW_Previous_IN_Ptr = initInstance_scalarWrapper((void*)&Sensors_DW.Previous_IN, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_DW_Previous_OUT_Ptr = initInstance_scalarWrapper((void*)&Sensors_DW.Previous_OUT, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_APPS1_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.APPS1_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_APPS2_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.APPS2_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_BrakePedal_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.BrakePedal_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_Disconnection_APPS1_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.Disconnection_APPS1, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_Disconnection_APPS2_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.Disconnection_APPS2, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_SteeringSensor_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.SteeringSensor_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_Susp_F_L_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.Susp_F_L_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_Susp_F_R_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.Susp_F_R_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_Susp_R_L_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.Susp_R_L_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_U_Susp_R_R_Bits_Ptr = initInstance_scalarWrapper((void*)&Sensors_U.Susp_R_R_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_APPS1_Value_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.APPS1_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_APPS2_Value_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.APPS2_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_BrakePedal_Value_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.BrakePedal_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_SUSP_F_L_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.SUSP_F_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_SUSP_F_R_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.SUSP_F_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_SUSP_R_L_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.SUSP_R_L, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_SUSP_R_R_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.SUSP_R_R, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Sensors_Y_SteeringSensor_Value_Ptr = initInstance_scalarWrapper((void*)&Sensors_Y.SteeringSensor_Value, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Sensors(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Sensors_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Sensors
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Sensors_ClassHeader =
    {0, 1, 0, 28 + 0, (MethodList *)0, (MethodList *)&RTWTop_Sensors_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Sensors_Class RTWTop_Sensors_ClassObj = {{1, {&RTWTop_Sensors_ClassHeader}, {0}}
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
struct RTWTop_Sensors_Obj *initInstance_RTWTop_Sensors(void)
{
    struct RTWTop_Sensors_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Sensors);
    return self;
}
void setDeltaT_Sensors(void)
{
}
