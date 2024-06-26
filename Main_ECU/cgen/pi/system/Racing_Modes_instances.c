/*****************************************************************************
 *
 * Racing_Modes_instances.c
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
#include "Racing_Modes.h"
#include "Racing_Modes_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "Racing_Modes_instances.h"
extern    B_Racing_Modes_T Racing_Modes_B;
extern    ExtU_Racing_Modes_T Racing_Modes_U;
extern    ExtY_Racing_Modes_T Racing_Modes_Y;
/* Initialization of Simulink model */
struct RTWTop_Racing_Modes_Obj *initModel_RTWTop_Racing_Modes(void)
{
    struct RTWTop_Racing_Modes_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_Racing_Modes (&RTWTop_Racing_Modes_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_Racing_Modes();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_Racing_Modes(struct RTWTop_Racing_Modes_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_Racing_Modes_B_Gain_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_B.Gain, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Modes_B_Merge_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_B.Merge, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Modes_U_CustomMode_Data_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_U.CustomMode_Data, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Modes_U_CustomMode_Identifier_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_U.CustomMode_Identifier, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Modes_U_RacingMode_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_U.RacingMode, sizeof(char), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Modes_Y_VDC_Max_Tyre_Slip_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_Y.VDC_Max_Tyre_Slip, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_Racing_Modes_Y_Workshop_Mode_Enable_Ptr = initInstance_scalarWrapper((void*)&Racing_Modes_Y.Workshop_Mode_Enable, sizeof(char), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_Racing_Modes(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_Racing_Modes_ClassMethodList =
{
    (MethodPtr)_L1_getPid_Racing_Modes
};
/* Definition of the class header */
static ASDClassHeader RTWTop_Racing_Modes_ClassHeader =
    {0, 1, 0, 7 + 0, (MethodList *)0, (MethodList *)&RTWTop_Racing_Modes_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_Racing_Modes_Class RTWTop_Racing_Modes_ClassObj = {{1, {&RTWTop_Racing_Modes_ClassHeader}, {0}}
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
    ,NULL
};
/* Object instantiation */
struct RTWTop_Racing_Modes_Obj *initInstance_RTWTop_Racing_Modes(void)
{
    struct RTWTop_Racing_Modes_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_Racing_Modes);
    return self;
}
void setDeltaT_Racing_Modes(void)
{
}
