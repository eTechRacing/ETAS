/*****************************************************************************
 *
 * ROOT_instances.c
 *
 * Part of INTECRIO Simulation Interface for generated software modules
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
#include "../a_basdef.h"
#include "./ROOT_instances.h"
#include "./Car_State_instances.h"
#include "./Accel_Data_instances.h"
#include "./Disconnections_instances.h"
#include "./Inverters_Action_instances.h"
#include "./Inverters_Data_instances.h"
#include "./LVD_Data_instances.h"
#include "./Pedals_Susp_Sensors_instances.h"
#include "./Racing_Mode_instances.h"
#include "./Synchronism_instances.h"
#include "./Torque_Control_instances.h"
/* Data structure for keeping the INTECRIO version (defines must be set) */
#ifdef INTECRIO_VERSION_NUMBER
static const uint32 intecrioVersionNumber = INTECRIO_VERSION_NUMBER;
const uint32 getIntecrioVersionNumber(void)
{
    return intecrioVersionNumber;
}
uint32 getBuildEnvironmentVersion(void)
{
    /* - The version number supplied by INTECRIO is AABBCCDD with
         AA: release, BB: update, CC: refresh, DD: patchlevel
       - This is bent into the appropriate shape (FFVVUURR) with
         FF: reserved, VV: major version, UU: update, RR: refresh */
    return (intecrioVersionNumber >> 8);
}
#else
#error "define INTECRIO_VERSION_NUMBER must be set!"
#endif
const char* modelIdentificationString = "INTECRIO";
const char* getModelIdentificationString()
{
    return modelIdentificationString;
}
uint32 getBuildEnvironment(void)
{
    return MODEL_TYPE_INTECRIO;
}
/* Program identifier (random number) */
/* uint32 programIdentifier = 0; */
/* Class initialization */
static void initClass_INTECRIOTop_ROOT(struct INTECRIOTop_ROOT_Class *self)
{
    /* Intialize top level class variables */
    self->RTWTop_Car_State_Ptr = (struct RTWTop_Car_State_Obj*)initModel_RTWTop_Car_State();
    self->RTWTop_Accel_Data_Ptr = (struct RTWTop_Accel_Data_Obj*)initModel_RTWTop_Accel_Data();
    self->RTWTop_Disconnections_Ptr = (struct RTWTop_Disconnections_Obj*)initModel_RTWTop_Disconnections();
    self->RTWTop_Inverters_Action_Ptr = (struct RTWTop_Inverters_Action_Obj*)initModel_RTWTop_Inverters_Action();
    self->RTWTop_Inverters_Data_Ptr = (struct RTWTop_Inverters_Data_Obj*)initModel_RTWTop_Inverters_Data();
    self->RTWTop_LVD_Data_Ptr = (struct RTWTop_LVD_Data_Obj*)initModel_RTWTop_LVD_Data();
    self->RTWTop_Pedals_Susp_Sensors_Ptr = (struct RTWTop_Pedals_Susp_Sensors_Obj*)initModel_RTWTop_Pedals_Susp_Sensors();
    self->RTWTop_Racing_Mode_Ptr = (struct RTWTop_Racing_Mode_Obj*)initModel_RTWTop_Racing_Mode();
    self->RTWTop_Synchronism_Ptr = (struct RTWTop_Synchronism_Obj*)initModel_RTWTop_Synchronism();
    self->RTWTop_Torque_Control_Ptr = (struct RTWTop_Torque_Control_Obj*)initModel_RTWTop_Torque_Control();
    return;
}
/* Definition of the class header */
static ASDClassHeader INTECRIOTop_ROOT_ClassHeader =
    {0, 0, 0, 10, (MethodList *)0, (MethodList *)0};
/* Definition and initialization of the class object */
static struct INTECRIOTop_ROOT_Class INTECRIOTop_ROOT_ClassObj = {{1, {&INTECRIOTop_ROOT_ClassHeader}, {0}}};
/* Object instantiation */
static struct INTECRIOTop_ROOT_Obj *initInstance_INTECRIOTop_ROOT(void)
{
    struct INTECRIOTop_ROOT_Obj *self;
    /* Object instantiation / implicit memory allocation */
    CREATE_OBJECT(self, INTECRIOTop_ROOT);
    return self;
}
/* Instance tree initialization */
ASDObject *initializeYukonModel (void)
{
    ASDObject *model;
    /* Top level class initialization */
    initClass_INTECRIOTop_ROOT(&INTECRIOTop_ROOT_ClassObj);
    /* Top Level object instantiation */
    model = (ASDObject *)initInstance_INTECRIOTop_ROOT();
    return(model);
}
/* Initialization of dT variables */
void os_setDeltaT (void)
{
    staticDT = ((real64) (SYSTEM_TICK_DURATION * os_dT) / 1.0e9);
    /* Set dT for each module */
    setDeltaT_Car_State();
    setDeltaT_Accel_Data();
    setDeltaT_Disconnections();
    setDeltaT_Inverters_Action();
    setDeltaT_Inverters_Data();
    setDeltaT_LVD_Data();
    setDeltaT_Pedals_Susp_Sensors();
    setDeltaT_Racing_Mode();
    setDeltaT_Synchronism();
    setDeltaT_Torque_Control();
}
/* Accessor for staticDT */
uint32 getDeltaT (void)
{
    return (uint32)(staticDT * 1000000.0);
}
/* Generic accessor for system time in seconds */
real64 getSystemTimeS (void)
{
    return ((real64)(SYSTEM_TICK_DURATION * (SYSTEM_TIME_LOW +
            (uint64)(SYSTEM_TIME_HIGH * 4294967296.0)))) / 1000000000;
}