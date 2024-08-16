/*****************************************************************************
 *
 * ROOT_instances.h
 *
 * Part of INTECRIO Simulation Interface for generated software modules
 *
 * Generated by INTECRIO Project Integrator, do not edit!
 *
 * Copyright 2024 ETAS (ETAS GmbH)
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
    struct RTWTop_Car_State_Obj *RTWTop_Car_State_Ptr;
    struct RTWTop_Disconnections_Obj *RTWTop_Disconnections_Ptr;
    struct RTWTop_Ellipse_Obj *RTWTop_Ellipse_Ptr;
    struct RTWTop_Inverters_Action_Obj *RTWTop_Inverters_Action_Ptr;
    struct RTWTop_Inverters_Data_Obj *RTWTop_Inverters_Data_Ptr;
    struct RTWTop_Power_Control_Obj *RTWTop_Power_Control_Ptr;
    struct RTWTop_Sensors_Obj *RTWTop_Sensors_Ptr;
    struct RTWTop_Synchronism_Obj *RTWTop_Synchronism_Ptr;
    struct RTWTop_VDC_Obj *RTWTop_VDC_Ptr;
    struct RTWTop_SoC_Obj *RTWTop_SoC_Ptr;
};
/* Definition of the class object structure */
struct INTECRIOTop_ROOT_Obj
{
    ASDObjectHeader objectHeader;
};
