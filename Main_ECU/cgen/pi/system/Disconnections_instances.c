/*****************************************************************************
 *
 * Disconnections_instances.c
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
#include "Disconnections.h"
#include "Disconnections_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Disconnections_instances.h"
extern    B_Disconnections_T Disconnections_B;
extern    DW_Disconnections_T Disconnections_DW;
extern    ExtU_Disconnections_T Disconnections_U;
extern    ExtY_Disconnections_T Disconnections_Y;
/* Initialization of Simulink model */
struct RTWTop_Disconnections_Obj *initModel_RTWTop_Disconnections(void)
{
    struct RTWTop_Disconnections_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Disconnections (&RTWTop_Disconnections_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Disconnections();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Disconnections(struct RTWTop_Disconnections_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Disconnections_B_Merge_Ptr = initInstance_scalarWrapper((void*)&Disconnections_B.Merge, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_B_Merge_d_Ptr = initInstance_scalarWrapper((void*)&Disconnections_B.Merge_d, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_B_Merge_g_Ptr = initInstance_scalarWrapper((void*)&Disconnections_B.Merge_g, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_B_Merge_j_Ptr = initInstance_scalarWrapper((void*)&Disconnections_B.Merge_j, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_B_Merge_m_Ptr = initInstance_scalarWrapper((void*)&Disconnections_B.Merge_m, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_A_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.A, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_e_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_e, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_g_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_g, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_n_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_n, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_n0_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_n0, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_o_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_o, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_p_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_p, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Last_alive_pb_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Last_alive_pb, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Tot_Errors_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Tot_Errors, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Tot_Errors_f_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Tot_Errors_f, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_DW_Tot_Errors_h_Ptr = initInstance_scalarWrapper((void*)&Disconnections_DW.Tot_Errors_h, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_APPS1_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.APPS1_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_APPS2_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.APPS2_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_BMS_Alive_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.BMS_Alive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_BrakePedal_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.BrakePedal_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Dash_Alive_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Dash_Alive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Ellipse_Alive_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Ellipse_Alive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Front_Alive_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Front_Alive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Rear_Alive_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Rear_Alive, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_SteeringSensor_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.SteeringSensor_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Susp_F_L_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Susp_F_L_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Susp_F_R_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Susp_F_R_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Susp_R_L_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Susp_R_L_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_U_Susp_R_R_Bits_Ptr = initInstance_scalarWrapper((void*)&Disconnections_U.Susp_R_R_Bits, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_CriticalDisconnection_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.CriticalDisconnection, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Critical_CAN_Disconnection_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Critical_CAN_Disconnection, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Critical_Signal_Disconnection_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Critical_Signal_Disconnection, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_APPS1_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_APPS1, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_APPS2_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_APPS2, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_BMS_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_BMS, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_BrakePedal_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_BrakePedal, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_DashBoard_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_DashBoard, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Ellipse_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Ellipse, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Front_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Front, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Mode_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Mode, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Rear_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Rear, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_SteeringSensor_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_SteeringSensor, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Susp_F_L_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Susp_F_L, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Susp_F_R_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Susp_F_R, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Susp_R_L_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Susp_R_L, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Disconnections_Y_Disconnection_Susp_R_R_Ptr = initInstance_scalarWrapper((void*)&Disconnections_Y.Disconnection_Susp_R_R, sizeof(char), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Disconnections(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Disconnections_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Disconnections
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Disconnections_ClassHeader =
    {0, 1, 0, 47 + 0, (MethodList *)0, (MethodList *)&RTWTop_Disconnections_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Disconnections_Class RTWTop_Disconnections_ClassObj = {{1, {&RTWTop_Disconnections_ClassHeader}, {0}}
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
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
};
/* Object instantiation */
struct RTWTop_Disconnections_Obj *initInstance_RTWTop_Disconnections(void)
{
    struct RTWTop_Disconnections_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Disconnections);
    return self;
}
void setDeltaT_Disconnections(void)
{
}
