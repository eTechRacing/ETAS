/* Generated by INTECRIO OS Configurator Plugin */
/* (c) 2004 ETAS (ETAS GmbH) */

#include "../a_basdef.h"

/*********** rtio hooks ***************/

/* entries for rtio task table */

/* rtio hook in task 0 etasConfigTask */
rtioHookTableEntry rtioHookTable0[1] = {NULL};

/* rtio hook in task 1 SWT_CAN1_AP_BMS_AIRs_State */
rtioHookTableEntry rtioHookTable1[1] = {NULL};

/* rtio hook in task 2 SWT_CAN1_AP_BMS_BatteryTemperatures */
rtioHookTableEntry rtioHookTable2[1] = {NULL};

/* rtio hook in task 3 SWT_CAN1_AP_BMS_ChargerParameters */
rtioHookTableEntry rtioHookTable3[1] = {NULL};

/* rtio hook in task 6 SWT_CAN1_AP_BMS_Current_SOC_SOH1 */
rtioHookTableEntry rtioHookTable6[1] = {NULL};

/* rtio hook in task 8 SWT_CAN1_AP_BMS_OnBoardTemperatures1 */
rtioHookTableEntry rtioHookTable8[1] = {NULL};

/* rtio hook in task 9 SWT_CAN1_AP_BMS_StateAndFailReport */
rtioHookTableEntry rtioHookTable9[1] = {NULL};

/* rtio hook in task 10 SWT_CAN1_AP_BMS_Voltages */
rtioHookTableEntry rtioHookTable10[1] = {NULL};

/* rtio hook in task 11 SWT_CAN1_AP_DASH_CustomMode */
rtioHookTableEntry rtioHookTable11[1] = {NULL};

/* rtio hook in task 12 SWT_CAN1_AP_DASH_EnableDrive */
rtioHookTableEntry rtioHookTable12[1] = {NULL};

/* rtio hook in task 13 SWT_CAN1_AP_DASH_Mode */
rtioHookTableEntry rtioHookTable13[1] = {NULL};

/* rtio hook in task 14 SWT_CAN1_AP_DASH_PrechargeRequest */
rtioHookTableEntry rtioHookTable14[1] = {NULL};

/* rtio hook in task 15 SWT_CAN1_AP_DASH_TorqueLockOn */
rtioHookTableEntry rtioHookTable15[1] = {NULL};

/* rtio hook in task 16 SWT_CAN1_AP_Inverter_L_Tx */
rtioHookTableEntry rtioHookTable16[1] = {NULL};

/* rtio hook in task 17 SWT_CAN1_AP_Inverter_R_Tx */
rtioHookTableEntry rtioHookTable17[1] = {NULL};

/* rtio hook in task 18 SWT_CAN1_AP_SHUTDOWN_State */
rtioHookTableEntry rtioHookTable18[1] = {NULL};

/* rtio hook in task 19 SWT_CAN1_NM_BMS_Keep_Alive */
rtioHookTableEntry rtioHookTable19[1] = {NULL};

/* rtio hook in task 20 SWT_CAN1_NM_DASH_Keep_Alive */
rtioHookTableEntry rtioHookTable20[1] = {NULL};

/* rtio hook in task 21 SWT_CAN1_NM_SHUTDOWN_Keep_Alive */
rtioHookTableEntry rtioHookTable21[1] = {NULL};

/* rtio hook in task 22 SWT_CAN2_AP_ACCEL_F_Data */
rtioHookTableEntry rtioHookTable22[1] = {NULL};

/* rtio hook in task 23 SWT_CAN2_AP_ACCEL_R_Data */
rtioHookTableEntry rtioHookTable23[1] = {NULL};

/* rtio hook in task 24 SWT_CAN2_AP_ACCEL_R_Data2 */
rtioHookTableEntry rtioHookTable24[1] = {NULL};

/* rtio hook in task 25 SWT_CAN2_AP_ADCAN_Data1 */
rtioHookTableEntry rtioHookTable25[1] = {NULL};

/* rtio hook in task 26 SWT_CAN2_AP_ADCAN_Data2 */
rtioHookTableEntry rtioHookTable26[1] = {NULL};

/* rtio hook in task 30 SWT_CAN2_NM_ACCEL_F_Keep_Alive */
rtioHookTableEntry rtioHookTable30[1] = {NULL};

/* rtio hook in task 31 SWT_CAN2_NM_ACCEL_R_Keep_Alive */
rtioHookTableEntry rtioHookTable31[1] = {NULL};

/* rtio hook in task 32 SWT_CAN2_NM_ADCAN_Keep_Alive */
rtioHookTableEntry rtioHookTable32[1] = {NULL};

/* rtio hook in task 34 Sync_25ms */
rtioHookTableEntry rtioHookTable34[2] = {NULL, NULL};

/* rtio hook in task 35 Timer_1000ms */
rtioHookTableEntry rtioHookTable35[1] = {NULL};

/* rtio hook in task 36 Timer_100ms */
rtioHookTableEntry rtioHookTable36[1] = {NULL};

/* rtio hook in task 37 Timer_25ms */
rtioHookTableEntry rtioHookTable37[2] = {NULL, NULL};

/* rtio hook in task 38 Timer_Inv */
rtioHookTableEntry rtioHookTable38[1] = {NULL};

/* rtio hook in task 39 NewISR */
rtioHookTableEntry rtioHookTable39[1] = {NULL};

/* rtio hook in task 40 NewISR1 */
rtioHookTableEntry rtioHookTable40[1] = {NULL};

/* rtio hook in task 41 Init */
rtioHookTableEntry rtioHookTable41[1] = {NULL};

/* rtio hook in task 42 Exit */
rtioHookTableEntry rtioHookTable42[1] = {NULL};


/* rtio task table */
rtioTaskTableEntry rtioTaskTable[43] =
{
	{&rtioHookTable0[0]},
	{&rtioHookTable1[0]},
	{&rtioHookTable2[0]},
	{&rtioHookTable3[0]},
	{NULL},
	{NULL},
	{&rtioHookTable6[0]},
	{NULL},
	{&rtioHookTable8[0]},
	{&rtioHookTable9[0]},
	{&rtioHookTable10[0]},
	{&rtioHookTable11[0]},
	{&rtioHookTable12[0]},
	{&rtioHookTable13[0]},
	{&rtioHookTable14[0]},
	{&rtioHookTable15[0]},
	{&rtioHookTable16[0]},
	{&rtioHookTable17[0]},
	{&rtioHookTable18[0]},
	{&rtioHookTable19[0]},
	{&rtioHookTable20[0]},
	{&rtioHookTable21[0]},
	{&rtioHookTable22[0]},
	{&rtioHookTable23[0]},
	{&rtioHookTable24[0]},
	{&rtioHookTable25[0]},
	{&rtioHookTable26[0]},
	{NULL},
	{NULL},
	{NULL},
	{&rtioHookTable30[0]},
	{&rtioHookTable31[0]},
	{&rtioHookTable32[0]},
	{NULL},
	{&rtioHookTable34[0]},
	{&rtioHookTable35[0]},
	{&rtioHookTable36[0]},
	{&rtioHookTable37[0]},
	{&rtioHookTable38[0]},
	{&rtioHookTable39[0]},
	{&rtioHookTable40[0]},
	{&rtioHookTable41[0]},
	{&rtioHookTable42[0]}
};

/* rtio hook processes */
void rtioHook_0_0(void)
{
	rtioHook(0,0);
	return;
}

void rtioHook_1_0(void)
{
	rtioHook(1,0);
	return;
}

void rtioHook_2_0(void)
{
	rtioHook(2,0);
	return;
}

void rtioHook_3_0(void)
{
	rtioHook(3,0);
	return;
}

void rtioHook_6_0(void)
{
	rtioHook(6,0);
	return;
}

void rtioHook_8_0(void)
{
	rtioHook(8,0);
	return;
}

void rtioHook_9_0(void)
{
	rtioHook(9,0);
	return;
}

void rtioHook_10_0(void)
{
	rtioHook(10,0);
	return;
}

void rtioHook_11_0(void)
{
	rtioHook(11,0);
	return;
}

void rtioHook_12_0(void)
{
	rtioHook(12,0);
	return;
}

void rtioHook_13_0(void)
{
	rtioHook(13,0);
	return;
}

void rtioHook_14_0(void)
{
	rtioHook(14,0);
	return;
}

void rtioHook_15_0(void)
{
	rtioHook(15,0);
	return;
}

void rtioHook_16_0(void)
{
	rtioHook(16,0);
	return;
}

void rtioHook_17_0(void)
{
	rtioHook(17,0);
	return;
}

void rtioHook_18_0(void)
{
	rtioHook(18,0);
	return;
}

void rtioHook_19_0(void)
{
	rtioHook(19,0);
	return;
}

void rtioHook_20_0(void)
{
	rtioHook(20,0);
	return;
}

void rtioHook_21_0(void)
{
	rtioHook(21,0);
	return;
}

void rtioHook_22_0(void)
{
	rtioHook(22,0);
	return;
}

void rtioHook_23_0(void)
{
	rtioHook(23,0);
	return;
}

void rtioHook_24_0(void)
{
	rtioHook(24,0);
	return;
}

void rtioHook_25_0(void)
{
	rtioHook(25,0);
	return;
}

void rtioHook_26_0(void)
{
	rtioHook(26,0);
	return;
}

void rtioHook_30_0(void)
{
	rtioHook(30,0);
	return;
}

void rtioHook_31_0(void)
{
	rtioHook(31,0);
	return;
}

void rtioHook_32_0(void)
{
	rtioHook(32,0);
	return;
}

void rtioHook_34_0(void)
{
	rtioHook(34,0);
	return;
}

void rtioHook_34_1(void)
{
	rtioHook(34,1);
	return;
}

void rtioHook_35_0(void)
{
	rtioHook(35,0);
	return;
}

void rtioHook_36_0(void)
{
	rtioHook(36,0);
	return;
}

void rtioHook_37_0(void)
{
	rtioHook(37,0);
	return;
}

void rtioHook_37_1(void)
{
	rtioHook(37,1);
	return;
}

void rtioHook_38_0(void)
{
	rtioHook(38,0);
	return;
}

void rtioHook_39_0(void)
{
	rtioHook(39,0);
	return;
}

void rtioHook_40_0(void)
{
	rtioHook(40,0);
	return;
}

void rtioHook_41_0(void)
{
	rtioHook(41,0);
	INIT_EXIT_FW_HOOK
	return;
}

void rtioHook_42_0(void)
{
	rtioHook(42,0);
	INIT_EXIT_FW_HOOK
	return;
}


