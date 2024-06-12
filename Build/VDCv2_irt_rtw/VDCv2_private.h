/*
 * VDCv2_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "VDCv2".
 *
 * Model version              : 4.93
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Sat Jun  8 15:15:34 2024
 *
 * Target selection: irt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_VDCv2_private_h_
#define RTW_HEADER_VDCv2_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "VDCv2.h"
#include "VDCv2_types.h"

extern const real_T rtCP_pooled_OiY3MRzyvx26[157];
extern const real_T rtCP_pooled_t8tfN5Vo0MrJ[157];

#define rtCP_SoCCurrent_tableData      rtCP_pooled_OiY3MRzyvx26  /* Expression: [99.8638515373959;99.8261032164556;99.787078895957;99.7464496412943;99.7031623399186;99.6569399822743;99.6085457240994;99.5583542992092;99.5063175156323;99.4531242547042;99.3996199106189;99.3457555385114;99.2916196918623;99.236840468825;99.1815776579033;99.1261581819638;99.0704600282389;99.0145621384686;98.9579862041378;98.9007649443125;98.8435709856118;98.7866964363398;98.7294309904695;98.6720632124312;98.6150692116673;98.5583262081729;98.5016459402354;98.4450485815784;98.3886324537531;98.3323113111552;98.2760370231491;98.219889318764;98.1640621452933;98.1086506246766;98.0534368997348;97.9982819285613;97.9430609511937;97.8873777779768;97.8316006765195;97.7756093847174;97.7196164319235;97.6636145234219;97.6074949919914;97.5512806941619;97.4949079148039;97.4386383393529;97.3824957659839;97.3265205156682;97.2707949766523;97.2152161070864;97.1597722415201;97.1042534409084;97.0487976906826;96.9934428687166;96.9382597426796;96.8831834289612;96.8282192088546;96.7734442056342;96.7189107658621;96.6645220082209;96.6101480019029;96.5557548375112;96.5011588175642;96.4465366275317;96.3919193515209;96.3373265852361;96.2827271967385;96.2284708305744;96.1743003814294;96.1202272122311;96.0662507872358;96.0124620565115;95.9587960858038;95.9054190254676;95.8523021379409;95.7996353499439;95.7473738162933;95.6954428515415;95.6440855591069;95.5931379659417;95.542675825155;95.4925898155832;95.4427621694762;95.3932593338181;95.3439201852395;95.2945061423096;95.2453155323362;95.1967449588083;95.1483471741501;95.1006171187692;95.05309426103;95.0060982834647;94.9596397012176;94.9136340068524;94.8681131899029;94.8228748176359;94.7773623572551;94.7323289961706;94.6877507845258;94.6438926674393;94.6005330360533;94.5579519678426;94.5157187867765;94.4736889382833;94.4318130425109;94.3900803949631;94.3486100596819;94.3072893708641;94.2662109590131;94.2257873041514;94.1857638071793;94.1462094608166;94.1070508764276;94.0683633537351;94.0297036137025;93.991181303978;93.9530103965701;93.9150714405644;93.8775886864698;93.840470618768;93.8039440022059;93.7678066751737;93.732300190504;93.6974844310299;93.6632820753455;93.6298210766945;93.5968199450375;93.5642570674136;93.5321287740758;93.5005594977202;93.4694689466742;93.4389330496507;93.4087179396065;93.3791648078586;93.3504222584188;93.3220395833837;93.2930881546744;93.2647696405904;93.2369762454977;93.2098304380767;93.1829890047197;93.156614414508;93.1307021213018;93.1049104059305;93.0794093899284;93.0544610934045;93.0299137147753;93.0061930132338;92.9829950868456;92.9601547660346;92.9377957962841;92.9158579087248;92.8941701658703;92.8727117435597;92.851501872486;92.8305232504108;92.8100674242247]
                                                                  * Referenced by: '<S32>/SoC // Current'
                                                                  */
#define rtCP_SoCCurrent_bp01Data       rtCP_pooled_t8tfN5Vo0MrJ  /* Expression: [0.5;0.625;0.75;0.875;1;1.125;1.25;1.375;1.5;1.625;1.75;1.875;2;2.125;2.25;2.375;2.5;2.625;2.75;2.875;3;3.125;3.25;3.375;3.5;3.625;3.75;3.875;4;4.125;4.25;4.375;4.5;4.625;4.75;4.875;5;5.125;5.25;5.375;5.5;5.625;5.75;5.875;6;6.125;6.25;6.375;6.5;6.625;6.75;6.875;7;7.125;7.25;7.375;7.5;7.625;7.75;7.875;8;8.125;8.25;8.375;8.5;8.625;8.75;8.875;9;9.125;9.25;9.375;9.5;9.625;9.75;9.875;10;10.125;10.25;10.375;10.5;10.625;10.75;10.875;11;11.125;11.25;11.375;11.5;11.625;11.75;11.875;12;12.125;12.25;12.375;12.5;12.625;12.75;12.875;13;13.125;13.25;13.375;13.5;13.625;13.75;13.875;14;14.125;14.25;14.375;14.5;14.625;14.75;14.875;15;15.125;15.25;15.375;15.5;15.625;15.75;15.875;16;16.125;16.25;16.375;16.5;16.625;16.75;16.875;17;17.125;17.25;17.375;17.5;17.625;17.75;17.875;18;18.125;18.25;18.375;18.5;18.625;18.75;18.875;19;19.125;19.25;19.375;19.5;19.625;19.75;19.875;20]
                                                                  * Referenced by: '<S32>/SoC // Current'
                                                                  */

extern void VDCv2_LimitReached(real_T *rty_Out);
extern void VDCv2_RigidAxlewithTC2024_Init(DW_RigidAxlewithTC2024_VDCv2_T
  *localDW);
extern void VDCv2_RigidAxlewithTC2024(real_T rtu_MAX_SLR, real_T
  rtu_Throttle_Torque_R, real_T rtu_Throttle_Torque_L, real_T rtu_el_Vel_X,
  real_T rtu_Vel_ms_wheel_RR, real_T rtu_Vel_ms_wheel_RL,
  B_RigidAxlewithTC2024_VDCv2_T *localB, DW_RigidAxlewithTC2024_VDCv2_T *localDW);
extern void VDCv2_RIGIDAXLE(real_T rtu_Throttle_TorqueNm, real_T
  *rty_Tq_RR_FM4Nm0inf, real_T *rty_Tq_RL_FM4Nm0inf, real_T *rty_tv_mode);
extern void VDCv2_Torquedemandedbythedriver(real_T rtu_AP, real_T
  rtu_pedal_sat_down, real_T rtu_pedal_sat_up, real_T rtu_max_torque,
  B_Torquedemandedbythedriver_V_T *localB);
extern void VDCv2_RIGIDAXLEWITHTC_Init(DW_RIGIDAXLEWITHTC_VDCv2_T *localDW);
extern void VDCv2_RIGIDAXLEWITHTC(real_T rtu_RR_Vel_ms_Wheelms, real_T
  rtu_RL_Vel_ms_Wheelms, real_T rtu_Throttle_TorqueNm, real_T rtu_MAX_SLR,
  real_T rtu_el_Vel_Xms, real_T *rty_Tq_RR_FM2Nm0inf, real_T
  *rty_Tq_RL_FM2Nm0inf, real_T *rty_tv_mode, DW_RIGIDAXLEWITHTC_VDCv2_T *localDW);

#endif                                 /* RTW_HEADER_VDCv2_private_h_ */
