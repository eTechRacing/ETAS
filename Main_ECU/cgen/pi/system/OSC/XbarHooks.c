/* Generated by INTECRIO OS Configurator Plugin */
/* (c) 2004 ETAS (ETAS GmbH) */

#include "../a_basdef.h"

/*********** crossbar hooks ***************/

/* entries for crossbar task table */

/* crossbar hook in task 1 SWT_CAN1_2024_AP_BMS_AIRs_State */
crossbarHookTableEntry crossbarHookTable1[1] = {NULL};

/* crossbar hook in task 2 SWT_CAN1_2024_AP_BMS_ChargerParameters */
crossbarHookTableEntry crossbarHookTable2[1] = {NULL};

/* crossbar hook in task 3 SWT_CAN1_2024_AP_BMS_SDC */
crossbarHookTableEntry crossbarHookTable3[1] = {NULL};

/* crossbar hook in task 4 SWT_CAN1_2024_AP_BMS_Temperatures */
crossbarHookTableEntry crossbarHookTable4[1] = {NULL};

/* crossbar hook in task 5 SWT_CAN1_2024_AP_BMS_Voltages */
crossbarHookTableEntry crossbarHookTable5[1] = {NULL};

/* crossbar hook in task 6 SWT_CAN1_2024_AP_CurrentSensor */
crossbarHookTableEntry crossbarHookTable6[1] = {NULL};

/* crossbar hook in task 7 SWT_CAN1_2024_AP_DASH_CustomMode */
crossbarHookTableEntry crossbarHookTable7[1] = {NULL};

/* crossbar hook in task 8 SWT_CAN1_2024_AP_DASH_EnableDrive */
crossbarHookTableEntry crossbarHookTable8[1] = {NULL};

/* crossbar hook in task 9 SWT_CAN1_2024_AP_DASH_Mode */
crossbarHookTableEntry crossbarHookTable9[1] = {NULL};

/* crossbar hook in task 10 SWT_CAN1_2024_AP_DASH_PrechargeRequest */
crossbarHookTableEntry crossbarHookTable10[1] = {NULL};

/* crossbar hook in task 11 SWT_CAN1_2024_AP_DASH_TorqueLockOn */
crossbarHookTableEntry crossbarHookTable11[1] = {NULL};

/* crossbar hook in task 12 SWT_CAN1_2024_AP_Inverter_L_Tx */
crossbarHookTableEntry crossbarHookTable12[1] = {NULL};

/* crossbar hook in task 13 SWT_CAN1_2024_AP_Inverter_R_Tx */
crossbarHookTableEntry crossbarHookTable13[1] = {NULL};

/* crossbar hook in task 14 SWT_CAN1_2024_NM_BMS_Keep_Alive */
crossbarHookTableEntry crossbarHookTable14[1] = {NULL};

/* crossbar hook in task 15 SWT_CAN1_2024_NM_DASH_Keep_Alive */
crossbarHookTableEntry crossbarHookTable15[1] = {NULL};

/* crossbar hook in task 16 SWT_CAN2_2024_AP_ELLIPSE_EKF_EULER */
crossbarHookTableEntry crossbarHookTable16[1] = {NULL};

/* crossbar hook in task 17 SWT_CAN2_2024_AP_ELLIPSE_EKF_POS */
crossbarHookTableEntry crossbarHookTable17[1] = {NULL};

/* crossbar hook in task 18 SWT_CAN2_2024_AP_ELLIPSE_EKF_VEL */
crossbarHookTableEntry crossbarHookTable18[1] = {NULL};

/* crossbar hook in task 19 SWT_CAN2_2024_AP_ELLIPSE_IMU_ACCEL */
crossbarHookTableEntry crossbarHookTable19[1] = {NULL};

/* crossbar hook in task 20 SWT_CAN2_2024_AP_ELLIPSE_IMU_GYRO */
crossbarHookTableEntry crossbarHookTable20[1] = {NULL};

/* crossbar hook in task 21 SWT_CAN2_2024_AP_ELLIPSE_SLIP_CURV */
crossbarHookTableEntry crossbarHookTable21[1] = {NULL};

/* crossbar hook in task 22 SWT_CAN2_2024_AP_FECU_Data1 */
crossbarHookTableEntry crossbarHookTable22[1] = {NULL};

/* crossbar hook in task 23 SWT_CAN2_2024_AP_FECU_Data2 */
crossbarHookTableEntry crossbarHookTable23[1] = {NULL};

/* crossbar hook in task 24 SWT_CAN2_2024_AP_RECU_Data */
crossbarHookTableEntry crossbarHookTable24[1] = {NULL};

/* crossbar hook in task 25 SWT_CAN2_2024_MEAS_FECU_SDC */
crossbarHookTableEntry crossbarHookTable25[1] = {NULL};

/* crossbar hook in task 26 SWT_CAN2_2024_MEAS_RECU_SDC */
crossbarHookTableEntry crossbarHookTable26[1] = {NULL};

/* crossbar hook in task 27 SWT_CAN2_2024_NM_ELLIPSE_Status */
crossbarHookTableEntry crossbarHookTable27[1] = {NULL};

/* crossbar hook in task 28 SWT_CAN2_2024_NM_FECU_Keep_Alive */
crossbarHookTableEntry crossbarHookTable28[1] = {NULL};

/* crossbar hook in task 29 SWT_CAN2_2024_NM_RECU_Keep_Alive */
crossbarHookTableEntry crossbarHookTable29[1] = {NULL};

/* crossbar hook in task 30 Sync_25ms */
crossbarHookTableEntry crossbarHookTable30[4] = {NULL, NULL, NULL, NULL};

/* crossbar hook in task 31 Timer_1000ms */
crossbarHookTableEntry crossbarHookTable31[2] = {NULL, NULL};

/* crossbar hook in task 32 Timer_100ms */
crossbarHookTableEntry crossbarHookTable32[2] = {NULL, NULL};

/* crossbar hook in task 33 Timer_25ms */
crossbarHookTableEntry crossbarHookTable33[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/* crossbar hook in task 34 Timer_Inv */
crossbarHookTableEntry crossbarHookTable34[6] = {NULL, NULL, NULL, NULL, NULL, NULL};

/* crossbar hook in task 35 ISR_CAN1_2024 */
crossbarHookTableEntry crossbarHookTable35[1] = {NULL};

/* crossbar hook in task 36 ISR_CAN2_2024 */
crossbarHookTableEntry crossbarHookTable36[1] = {NULL};

/* crossbar hook in task 37 Init */
crossbarHookTableEntry crossbarHookTable37[20] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/* crossbar hook in task 38 Exit */
crossbarHookTableEntry crossbarHookTable38[20] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};


/* crossbar task table */
crossbarTaskTableEntry crossbarTaskTable[39] =
{
	{NULL},
	{&crossbarHookTable1[0]},
	{&crossbarHookTable2[0]},
	{&crossbarHookTable3[0]},
	{&crossbarHookTable4[0]},
	{&crossbarHookTable5[0]},
	{&crossbarHookTable6[0]},
	{&crossbarHookTable7[0]},
	{&crossbarHookTable8[0]},
	{&crossbarHookTable9[0]},
	{&crossbarHookTable10[0]},
	{&crossbarHookTable11[0]},
	{&crossbarHookTable12[0]},
	{&crossbarHookTable13[0]},
	{&crossbarHookTable14[0]},
	{&crossbarHookTable15[0]},
	{&crossbarHookTable16[0]},
	{&crossbarHookTable17[0]},
	{&crossbarHookTable18[0]},
	{&crossbarHookTable19[0]},
	{&crossbarHookTable20[0]},
	{&crossbarHookTable21[0]},
	{&crossbarHookTable22[0]},
	{&crossbarHookTable23[0]},
	{&crossbarHookTable24[0]},
	{&crossbarHookTable25[0]},
	{&crossbarHookTable26[0]},
	{&crossbarHookTable27[0]},
	{&crossbarHookTable28[0]},
	{&crossbarHookTable29[0]},
	{&crossbarHookTable30[0]},
	{&crossbarHookTable31[0]},
	{&crossbarHookTable32[0]},
	{&crossbarHookTable33[0]},
	{&crossbarHookTable34[0]},
	{&crossbarHookTable35[0]},
	{&crossbarHookTable36[0]},
	{&crossbarHookTable37[0]},
	{&crossbarHookTable38[0]}
};

/* crossbar hook processes */
void crossbarHook_1_0(void)
{
	crossbarHook(1,0);
	return;
}

void crossbarHook_2_0(void)
{
	crossbarHook(2,0);
	return;
}

void crossbarHook_3_0(void)
{
	crossbarHook(3,0);
	return;
}

void crossbarHook_4_0(void)
{
	crossbarHook(4,0);
	return;
}

void crossbarHook_5_0(void)
{
	crossbarHook(5,0);
	return;
}

void crossbarHook_6_0(void)
{
	crossbarHook(6,0);
	return;
}

void crossbarHook_7_0(void)
{
	crossbarHook(7,0);
	return;
}

void crossbarHook_8_0(void)
{
	crossbarHook(8,0);
	return;
}

void crossbarHook_9_0(void)
{
	crossbarHook(9,0);
	return;
}

void crossbarHook_10_0(void)
{
	crossbarHook(10,0);
	return;
}

void crossbarHook_11_0(void)
{
	crossbarHook(11,0);
	return;
}

void crossbarHook_12_0(void)
{
	crossbarHook(12,0);
	return;
}

void crossbarHook_13_0(void)
{
	crossbarHook(13,0);
	return;
}

void crossbarHook_14_0(void)
{
	crossbarHook(14,0);
	return;
}

void crossbarHook_15_0(void)
{
	crossbarHook(15,0);
	return;
}

void crossbarHook_16_0(void)
{
	crossbarHook(16,0);
	return;
}

void crossbarHook_17_0(void)
{
	crossbarHook(17,0);
	return;
}

void crossbarHook_18_0(void)
{
	crossbarHook(18,0);
	return;
}

void crossbarHook_19_0(void)
{
	crossbarHook(19,0);
	return;
}

void crossbarHook_20_0(void)
{
	crossbarHook(20,0);
	return;
}

void crossbarHook_21_0(void)
{
	crossbarHook(21,0);
	return;
}

void crossbarHook_22_0(void)
{
	crossbarHook(22,0);
	return;
}

void crossbarHook_23_0(void)
{
	crossbarHook(23,0);
	return;
}

void crossbarHook_24_0(void)
{
	crossbarHook(24,0);
	return;
}

void crossbarHook_25_0(void)
{
	crossbarHook(25,0);
	return;
}

void crossbarHook_26_0(void)
{
	crossbarHook(26,0);
	return;
}

void crossbarHook_27_0(void)
{
	crossbarHook(27,0);
	return;
}

void crossbarHook_28_0(void)
{
	crossbarHook(28,0);
	return;
}

void crossbarHook_29_0(void)
{
	crossbarHook(29,0);
	return;
}

void crossbarHook_30_0(void)
{
	crossbarHook(30,0);
	return;
}

void crossbarHook_30_1(void)
{
	crossbarHook(30,1);
	return;
}

void crossbarHook_30_2(void)
{
	crossbarHook(30,2);
	return;
}

void crossbarHook_30_3(void)
{
	crossbarHook(30,3);
	return;
}

void crossbarHook_31_0(void)
{
	crossbarHook(31,0);
	return;
}

void crossbarHook_31_1(void)
{
	crossbarHook(31,1);
	return;
}

void crossbarHook_32_0(void)
{
	crossbarHook(32,0);
	return;
}

void crossbarHook_32_1(void)
{
	crossbarHook(32,1);
	return;
}

void crossbarHook_33_0(void)
{
	crossbarHook(33,0);
	return;
}

void crossbarHook_33_1(void)
{
	crossbarHook(33,1);
	return;
}

void crossbarHook_33_2(void)
{
	crossbarHook(33,2);
	return;
}

void crossbarHook_33_3(void)
{
	crossbarHook(33,3);
	return;
}

void crossbarHook_33_4(void)
{
	crossbarHook(33,4);
	return;
}

void crossbarHook_33_5(void)
{
	crossbarHook(33,5);
	return;
}

void crossbarHook_33_6(void)
{
	crossbarHook(33,6);
	return;
}

void crossbarHook_33_7(void)
{
	crossbarHook(33,7);
	return;
}

void crossbarHook_33_8(void)
{
	crossbarHook(33,8);
	return;
}

void crossbarHook_33_9(void)
{
	crossbarHook(33,9);
	return;
}

void crossbarHook_33_10(void)
{
	crossbarHook(33,10);
	return;
}

void crossbarHook_33_11(void)
{
	crossbarHook(33,11);
	return;
}

void crossbarHook_33_12(void)
{
	crossbarHook(33,12);
	return;
}

void crossbarHook_33_13(void)
{
	crossbarHook(33,13);
	return;
}

void crossbarHook_33_14(void)
{
	crossbarHook(33,14);
	return;
}

void crossbarHook_33_15(void)
{
	crossbarHook(33,15);
	return;
}

void crossbarHook_34_0(void)
{
	crossbarHook(34,0);
	return;
}

void crossbarHook_34_1(void)
{
	crossbarHook(34,1);
	return;
}

void crossbarHook_34_2(void)
{
	crossbarHook(34,2);
	return;
}

void crossbarHook_34_3(void)
{
	crossbarHook(34,3);
	return;
}

void crossbarHook_34_4(void)
{
	crossbarHook(34,4);
	return;
}

void crossbarHook_34_5(void)
{
	crossbarHook(34,5);
	return;
}

void crossbarHook_35_0(void)
{
	crossbarHook(35,0);
	return;
}

void crossbarHook_36_0(void)
{
	crossbarHook(36,0);
	return;
}

void crossbarHook_37_0(void)
{
	crossbarHook(37,0);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_1(void)
{
	crossbarHook(37,1);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_2(void)
{
	crossbarHook(37,2);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_3(void)
{
	crossbarHook(37,3);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_4(void)
{
	crossbarHook(37,4);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_5(void)
{
	crossbarHook(37,5);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_6(void)
{
	crossbarHook(37,6);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_7(void)
{
	crossbarHook(37,7);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_8(void)
{
	crossbarHook(37,8);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_9(void)
{
	crossbarHook(37,9);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_10(void)
{
	crossbarHook(37,10);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_11(void)
{
	crossbarHook(37,11);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_12(void)
{
	crossbarHook(37,12);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_13(void)
{
	crossbarHook(37,13);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_14(void)
{
	crossbarHook(37,14);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_15(void)
{
	crossbarHook(37,15);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_16(void)
{
	crossbarHook(37,16);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_17(void)
{
	crossbarHook(37,17);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_18(void)
{
	crossbarHook(37,18);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_37_19(void)
{
	crossbarHook(37,19);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_0(void)
{
	crossbarHook(38,0);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_1(void)
{
	crossbarHook(38,1);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_2(void)
{
	crossbarHook(38,2);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_3(void)
{
	crossbarHook(38,3);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_4(void)
{
	crossbarHook(38,4);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_5(void)
{
	crossbarHook(38,5);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_6(void)
{
	crossbarHook(38,6);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_7(void)
{
	crossbarHook(38,7);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_8(void)
{
	crossbarHook(38,8);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_9(void)
{
	crossbarHook(38,9);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_10(void)
{
	crossbarHook(38,10);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_11(void)
{
	crossbarHook(38,11);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_12(void)
{
	crossbarHook(38,12);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_13(void)
{
	crossbarHook(38,13);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_14(void)
{
	crossbarHook(38,14);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_15(void)
{
	crossbarHook(38,15);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_16(void)
{
	crossbarHook(38,16);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_17(void)
{
	crossbarHook(38,17);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_18(void)
{
	crossbarHook(38,18);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_38_19(void)
{
	crossbarHook(38,19);
	INIT_EXIT_FW_HOOK
	return;
}


