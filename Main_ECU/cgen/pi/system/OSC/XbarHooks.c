/* Generated by INTECRIO OS Configurator Plugin */
/* (c) 2004 ETAS (ETAS GmbH) */

#include "../a_basdef.h"

/*********** crossbar hooks ***************/

/* entries for crossbar task table */

/* crossbar hook in task 1 SWT_CAN1_AP_BMS_AIRs_State */
crossbarHookTableEntry crossbarHookTable1[1] = {NULL};

/* crossbar hook in task 2 SWT_CAN1_AP_BMS_BatteryTemperatures */
crossbarHookTableEntry crossbarHookTable2[1] = {NULL};

/* crossbar hook in task 3 SWT_CAN1_AP_BMS_ChargerParameters */
crossbarHookTableEntry crossbarHookTable3[1] = {NULL};

/* crossbar hook in task 4 SWT_CAN1_AP_BMS_Current_SOC_SOH */
crossbarHookTableEntry crossbarHookTable4[1] = {NULL};

/* crossbar hook in task 5 SWT_CAN1_AP_BMS_OnBoardTemperatures */
crossbarHookTableEntry crossbarHookTable5[1] = {NULL};

/* crossbar hook in task 6 SWT_CAN1_AP_BMS_StateAndFailReport */
crossbarHookTableEntry crossbarHookTable6[1] = {NULL};

/* crossbar hook in task 7 SWT_CAN1_AP_BMS_Voltages */
crossbarHookTableEntry crossbarHookTable7[1] = {NULL};

/* crossbar hook in task 8 SWT_CAN1_AP_DASH_CustomMode */
crossbarHookTableEntry crossbarHookTable8[1] = {NULL};

/* crossbar hook in task 9 SWT_CAN1_AP_DASH_EnableDrive */
crossbarHookTableEntry crossbarHookTable9[1] = {NULL};

/* crossbar hook in task 10 SWT_CAN1_AP_DASH_Mode */
crossbarHookTableEntry crossbarHookTable10[1] = {NULL};

/* crossbar hook in task 11 SWT_CAN1_AP_DASH_PrechargeRequest */
crossbarHookTableEntry crossbarHookTable11[1] = {NULL};

/* crossbar hook in task 12 SWT_CAN1_AP_DASH_TorqueLockOn */
crossbarHookTableEntry crossbarHookTable12[1] = {NULL};

/* crossbar hook in task 13 SWT_CAN1_AP_Inverter_L_Tx */
crossbarHookTableEntry crossbarHookTable13[1] = {NULL};

/* crossbar hook in task 14 SWT_CAN1_AP_Inverter_R_Tx */
crossbarHookTableEntry crossbarHookTable14[1] = {NULL};

/* crossbar hook in task 15 SWT_CAN1_AP_SHUTDOWN_State */
crossbarHookTableEntry crossbarHookTable15[1] = {NULL};

/* crossbar hook in task 16 SWT_CAN1_NM_BMS_Keep_Alive */
crossbarHookTableEntry crossbarHookTable16[1] = {NULL};

/* crossbar hook in task 17 SWT_CAN1_NM_DASH_Keep_Alive */
crossbarHookTableEntry crossbarHookTable17[1] = {NULL};

/* crossbar hook in task 18 SWT_CAN1_NM_SHUTDOWN_Keep_Alive */
crossbarHookTableEntry crossbarHookTable18[1] = {NULL};

/* crossbar hook in task 19 SWT_CAN2_AP_ACCEL_F_Data */
crossbarHookTableEntry crossbarHookTable19[1] = {NULL};

/* crossbar hook in task 20 SWT_CAN2_AP_ACCEL_R_Data */
crossbarHookTableEntry crossbarHookTable20[1] = {NULL};

/* crossbar hook in task 21 SWT_CAN2_AP_ACCEL_R_Data2 */
crossbarHookTableEntry crossbarHookTable21[1] = {NULL};

/* crossbar hook in task 22 SWT_CAN2_AP_ADCAN_Data1 */
crossbarHookTableEntry crossbarHookTable22[1] = {NULL};

/* crossbar hook in task 23 SWT_CAN2_AP_ADCAN_Data2 */
crossbarHookTableEntry crossbarHookTable23[1] = {NULL};

/* crossbar hook in task 24 SWT_CAN2_AP_LV_Derivation_LVData */
crossbarHookTableEntry crossbarHookTable24[1] = {NULL};

/* crossbar hook in task 25 SWT_CAN2_NM_ACCEL_F_Keep_Alive */
crossbarHookTableEntry crossbarHookTable25[1] = {NULL};

/* crossbar hook in task 26 SWT_CAN2_NM_ACCEL_R_Keep_Alive */
crossbarHookTableEntry crossbarHookTable26[1] = {NULL};

/* crossbar hook in task 27 SWT_CAN2_NM_ADCAN_Keep_Alive */
crossbarHookTableEntry crossbarHookTable27[1] = {NULL};

/* crossbar hook in task 28 SWT_CAN2_NM_LV_Derivation_Keep_Alive */
crossbarHookTableEntry crossbarHookTable28[1] = {NULL};

/* crossbar hook in task 29 Sync_25ms */
crossbarHookTableEntry crossbarHookTable29[4] = {NULL, NULL, NULL, NULL};

/* crossbar hook in task 30 Timer_1000ms */
crossbarHookTableEntry crossbarHookTable30[2] = {NULL, NULL};

/* crossbar hook in task 31 Timer_100ms */
crossbarHookTableEntry crossbarHookTable31[2] = {NULL, NULL};

/* crossbar hook in task 32 Timer_25ms */
crossbarHookTableEntry crossbarHookTable32[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/* crossbar hook in task 33 Timer_Inv */
crossbarHookTableEntry crossbarHookTable33[6] = {NULL, NULL, NULL, NULL, NULL, NULL};

/* crossbar hook in task 34 ISR_CAN1 */
crossbarHookTableEntry crossbarHookTable34[1] = {NULL};

/* crossbar hook in task 35 ISR_CAN2 */
crossbarHookTableEntry crossbarHookTable35[1] = {NULL};

/* crossbar hook in task 36 Init */
crossbarHookTableEntry crossbarHookTable36[20] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

/* crossbar hook in task 37 Exit */
crossbarHookTableEntry crossbarHookTable37[20] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};


/* crossbar task table */
crossbarTaskTableEntry crossbarTaskTable[38] =
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
	{&crossbarHookTable37[0]}
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

void crossbarHook_29_1(void)
{
	crossbarHook(29,1);
	return;
}

void crossbarHook_29_2(void)
{
	crossbarHook(29,2);
	return;
}

void crossbarHook_29_3(void)
{
	crossbarHook(29,3);
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

void crossbarHook_32_2(void)
{
	crossbarHook(32,2);
	return;
}

void crossbarHook_32_3(void)
{
	crossbarHook(32,3);
	return;
}

void crossbarHook_32_4(void)
{
	crossbarHook(32,4);
	return;
}

void crossbarHook_32_5(void)
{
	crossbarHook(32,5);
	return;
}

void crossbarHook_32_6(void)
{
	crossbarHook(32,6);
	return;
}

void crossbarHook_32_7(void)
{
	crossbarHook(32,7);
	return;
}

void crossbarHook_32_8(void)
{
	crossbarHook(32,8);
	return;
}

void crossbarHook_32_9(void)
{
	crossbarHook(32,9);
	return;
}

void crossbarHook_32_10(void)
{
	crossbarHook(32,10);
	return;
}

void crossbarHook_32_11(void)
{
	crossbarHook(32,11);
	return;
}

void crossbarHook_32_12(void)
{
	crossbarHook(32,12);
	return;
}

void crossbarHook_32_13(void)
{
	crossbarHook(32,13);
	return;
}

void crossbarHook_32_14(void)
{
	crossbarHook(32,14);
	return;
}

void crossbarHook_32_15(void)
{
	crossbarHook(32,15);
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

void crossbarHook_34_0(void)
{
	crossbarHook(34,0);
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
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_1(void)
{
	crossbarHook(36,1);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_2(void)
{
	crossbarHook(36,2);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_3(void)
{
	crossbarHook(36,3);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_4(void)
{
	crossbarHook(36,4);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_5(void)
{
	crossbarHook(36,5);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_6(void)
{
	crossbarHook(36,6);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_7(void)
{
	crossbarHook(36,7);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_8(void)
{
	crossbarHook(36,8);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_9(void)
{
	crossbarHook(36,9);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_10(void)
{
	crossbarHook(36,10);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_11(void)
{
	crossbarHook(36,11);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_12(void)
{
	crossbarHook(36,12);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_13(void)
{
	crossbarHook(36,13);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_14(void)
{
	crossbarHook(36,14);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_15(void)
{
	crossbarHook(36,15);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_16(void)
{
	crossbarHook(36,16);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_17(void)
{
	crossbarHook(36,17);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_18(void)
{
	crossbarHook(36,18);
	INIT_EXIT_FW_HOOK
	return;
}

void crossbarHook_36_19(void)
{
	crossbarHook(36,19);
	INIT_EXIT_FW_HOOK
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


