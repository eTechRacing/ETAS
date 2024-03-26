/*****************************************************************************
 *
 * ROOT_instances.h
 *
 * Part of INTECRIO Simulation Interface for generated software modules
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2007 ETAS (ETAS GmbH)
 *
 *****************************************************************************/
/* Instance tree initialization */
extern ASDObject *initializeYukonModel(void);
/* Static delta T variable */
static real64 staticDT;
/* Function for grabbing the INTECRIO version */
const uint32 getIntecrioVersionNumber(void);
/* Functions for identifying the application which created this model */
enum { MODEL_TYPE_INTECRIO = 1 };
uint32 getBuildEnvironment(void);
uint32 getBuildEnvironmentVersion(void);
const char* getModelIdentificationString();
/* Definition of the class structure */
struct INTECRIOTop_ROOT_Class
{
    ASDObjectHeader objectHeader;
    struct RTWTop_Sensors_Obj *RTWTop_Sensors_Ptr;
    struct RTWTop_Synchronism_Obj *RTWTop_Synchronism_Ptr;
    struct RTWTop_APPS_Implausibility_Obj *RTWTop_APPS_Implausibility_Ptr;
};
/* Definition of the class object structure */
struct INTECRIOTop_ROOT_Obj
{
    ASDObjectHeader objectHeader;
};
