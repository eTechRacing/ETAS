/*****************************************************************************
 *
 * Ellipse_instances.h
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
extern struct RTWTop_Ellipse_Obj *initModel_RTWTop_Ellipse(void);
/* Level 1 class object declaration */
extern struct RTWTop_Ellipse_Class RTWTop_Ellipse_ClassObj;
/* Level 1 class initialization function prototype */
extern void initClass_RTWTop_Ellipse(struct RTWTop_Ellipse_Class *class);
/* Level 1 object instantiation function prototype */
extern struct RTWTop_Ellipse_Obj *initInstance_RTWTop_Ellipse(void);
/* Function prototype for module specific setDeltaT() */
void setDeltaT_Ellipse(void);
/* Definition of the class structure */
struct RTWTop_Ellipse_Class
{
    ASDObjectHeader objectHeader;
    scalarWrapper_Obj *RTWWrapper_Ellipse_U_el_AUTO_STATUS_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_U_el_AngleTrack_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_U_el_CurvatureRadius_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_U_el_LATITUDE_EKF_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_U_el_LONGITUDE_EKF_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_Y_CurvRadius_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_Y_Lat_EKF_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_Y_Long_EKF_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_Y_Status_Auto_Ptr;
    scalarWrapper_Obj *RTWWrapper_Ellipse_Y_TrackAngle_Ptr;
};
/* Definition of the class object structure */
struct RTWTop_Ellipse_Obj
{
    ASDObjectHeader objectHeader;
};
