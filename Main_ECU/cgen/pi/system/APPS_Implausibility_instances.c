/*****************************************************************************
 *
 * APPS_Implausibility_instances.c
 *
 * Part of INTECRIO Simulation Interface for Mathworks Matlab/Simulink
 * Real-Time Workshop and Embedded Coder
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
  /* use void* as instance tree wrapper object pointer type */
 #define Y_PRIMIT_VOID_PTR_FOR_ADDR
#define bool RTW_bool
#include "APPS_Implausibility.h"
#include "APPS_Implausibility_private.h"
#undef bool
#undef false
#undef true
#include "../a_basdef.h"
#include "APPS_Implausibility_instances.h"
extern    DW_APPS_Implausibility_T APPS_Implausibility_DW;
extern    ExtU_APPS_Implausibility_T APPS_Implausibility_U;
extern    ExtY_APPS_Implausibility_T APPS_Implausibility_Y;
/* Initialization of Simulink model */
struct RTWTop_APPS_Implausibility_Obj *initModel_RTWTop_APPS_Implausibility(void)
{
    struct RTWTop_APPS_Implausibility_Obj *model;
    /* Level 1 class initialization */
    initClass_RTWTop_APPS_Implausibility (&RTWTop_APPS_Implausibility_ClassObj);
    /* Level 1 object instantiation */
    model = initInstance_RTWTop_APPS_Implausibility();
    return(model);
}
/* Class initialization */
void initClass_RTWTop_APPS_Implausibility(struct RTWTop_APPS_Implausibility_Class *self)
{
    /* Level 1 class variables */
    self->RTWWrapper_APPS_Implausibility_DW_ERROR_Counter_Ptr = initInstance_scalarWrapper((void*)&APPS_Implausibility_DW.ERROR_Counter, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_APPS_Implausibility_U_APPS1_Value_Ptr = initInstance_scalarWrapper((void*)&APPS_Implausibility_U.APPS1_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_APPS_Implausibility_U_APPS2_Value_Ptr = initInstance_scalarWrapper((void*)&APPS_Implausibility_U.APPS2_Value, sizeof(double), (uint32)ASD_VARIABLE);
    self->RTWWrapper_APPS_Implausibility_Y_Disconnect_Fail_Ptr = initInstance_scalarWrapper((void*)&APPS_Implausibility_Y.Disconnect_Fail, sizeof(double), (uint32)ASD_VARIABLE);
    return;
}
static uint8 * _L1_getPid_APPS_Implausibility(ASDObjectPtr self, uint8 *buffer)
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
static MethodList RTWTop_APPS_Implausibility_ClassMethodList =
{
    (MethodPtr)_L1_getPid_APPS_Implausibility
};
/* Definition of the class header */
static ASDClassHeader RTWTop_APPS_Implausibility_ClassHeader =
    {0, 1, 0, 4 + 0, (MethodList *)0, (MethodList *)&RTWTop_APPS_Implausibility_ClassMethodList};
/* Definition and initialization of the class object */
struct RTWTop_APPS_Implausibility_Class RTWTop_APPS_Implausibility_ClassObj = {{1, {&RTWTop_APPS_Implausibility_ClassHeader}, {0}}
    ,NULL
    ,NULL
    ,NULL
    ,NULL
};
/* Object instantiation */
struct RTWTop_APPS_Implausibility_Obj *initInstance_RTWTop_APPS_Implausibility(void)
{
    struct RTWTop_APPS_Implausibility_Obj *self;
    /* Object instantiation / Implicit memory allocation */
    CREATE_OBJECT(self, RTWTop_APPS_Implausibility);
    return self;
}
void setDeltaT_APPS_Implausibility(void)
{
}
