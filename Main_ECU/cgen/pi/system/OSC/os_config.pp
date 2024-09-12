

# 8 "os_config.stc"

# 9 "os_config.stc"
kernel {
# 10 "os_config.stc"
	version "v5.01" interface "RTArchitect";
# 10 "os_config.stc"

# 11 "os_config.stc"
	target "ES900";
# 11 "os_config.stc"

# 12 "os_config.stc"
	build level = "standard";
# 12 "os_config.stc"

# 13 "os_config.stc"
	static interface disabled;
# 13 "os_config.stc"

# 14 "os_config.stc"
	set "Project"="os_config";
# 14 "os_config.stc"

# 15 "os_config.stc"
	set "LastEdit"="unknown";
# 15 "os_config.stc"

# 16 "os_config.stc"
	set "Variant"="ES900";
# 16 "os_config.stc"

# 17 "os_config.stc"
	set "DestDir_asm"="c:\users\joser\onedrive\documentos\github\etas\main_ecu\cgen\pi\system\OSC\";
# 17 "os_config.stc"

# 18 "os_config.stc"
	set "DestDir_c"="c:\users\joser\onedrive\documentos\github\etas\main_ecu\cgen\pi\system\OSC\";
# 18 "os_config.stc"

# 19 "os_config.stc"
	set "DestDir_h"="c:\users\joser\onedrive\documentos\github\etas\main_ecu\cgen\pi\system\OSC\";
# 19 "os_config.stc"

# 20 "os_config.stc"
	set "DestDir_obj"="c:\users\joser\onedrive\documentos\github\etas\main_ecu\cgen\pi\system\OSC\";
# 20 "os_config.stc"

# 21 "os_config.stc"
	set "DestDir_app"="c:\users\joser\onedrive\documentos\github\etas\main_ecu\cgen\pi\system\OSC\";
# 21 "os_config.stc"

# 22 "os_config.stc"
	set "DestDir_tmp"="c:\users\joser\onedrive\documentos\github\etas\main_ecu\cgen\pi\system\OSC\";
# 22 "os_config.stc"

# 23 "os_config.stc"
	set "RTAOSEK_LICENSE_FILE"="C:\ETAS\Compiler\INTECRIO5.0\RTA-OSEK-V5.0\bin\rta.lic?C:/ETAS/Compiler/INTECRIO5.0/RTA-OSEK-V5.0\license\rta.lic";
# 23 "os_config.stc"

# 24 "os_config.stc"
}


# 24 "os_config.stc"

# 25 "os_config.stc"

# 26 "os_config.stc"
timing correction {
# 27 "os_config.stc"
	0;
# 27 "os_config.stc"
 0;
# 27 "os_config.stc"
 0;
# 27 "os_config.stc"
 0;
# 27 "os_config.stc"
 0;
# 27 "os_config.stc"
 0;
# 27 "os_config.stc"
 0;
# 27 "os_config.stc"

# 28 "os_config.stc"
	0;
# 28 "os_config.stc"
 0;
# 28 "os_config.stc"
 0;
# 28 "os_config.stc"
 0;
# 28 "os_config.stc"
 0;
# 28 "os_config.stc"
 0;
# 28 "os_config.stc"
 0;
# 28 "os_config.stc"

# 29 "os_config.stc"
}


# 29 "os_config.stc"

# 30 "os_config.stc"

# 31 "os_config.stc"
resource osek_resource_RES_SCHEDULER;


# 31 "os_config.stc"

# 32 "os_config.stc"

# 33 "os_config.stc"
timebase sys_timebase {
# 34 "os_config.stc"
	stopwatch;
# 34 "os_config.stc"

# 35 "os_config.stc"
	units cycles { define 600000.000000 as 50000.000000 ticks;
# 35 "os_config.stc"
 }
# 35 "os_config.stc"

# 36 "os_config.stc"
	units stopwatch_ticks { define 1.000000 as 1.000000 ticks;
# 36 "os_config.stc"
 }
# 36 "os_config.stc"

# 37 "os_config.stc"
	units s { define 1.000000 as 50000000.000000 ticks;
# 37 "os_config.stc"
 }
# 37 "os_config.stc"

# 38 "os_config.stc"
	units ms { define 1000.000000 as 1.000000 s;
# 38 "os_config.stc"
 }
# 38 "os_config.stc"

# 39 "os_config.stc"
	units us { define 1000.000000 as 1.000000 ms;
# 39 "os_config.stc"
 }
# 39 "os_config.stc"

# 40 "os_config.stc"
	units ns { define 1000.000000 as 1.000000 us;
# 40 "os_config.stc"
 }
# 40 "os_config.stc"

# 41 "os_config.stc"
	units min { define 1.000000 as 60.000000 s;
# 41 "os_config.stc"
 }
# 41 "os_config.stc"

# 42 "os_config.stc"
	max_value 4294967295 ticks;
# 42 "os_config.stc"

# 43 "os_config.stc"
	constant ticks_per_s is 50000000.000000 ticks as float;
# 43 "os_config.stc"

# 44 "os_config.stc"
}


# 44 "os_config.stc"

# 45 "os_config.stc"
timebase cpu_clock {
# 46 "os_config.stc"
	units cycles { define 1.000000 as 1.000000 ticks;
# 46 "os_config.stc"
 }
# 46 "os_config.stc"

# 47 "os_config.stc"
	units kCycles { define 1.000000 as 1000.000000 cycles;
# 47 "os_config.stc"
 }
# 47 "os_config.stc"

# 48 "os_config.stc"
	units MCycles { define 1.000000 as 1000.000000 kCycles;
# 48 "os_config.stc"
 }
# 48 "os_config.stc"

# 49 "os_config.stc"
	units StopwatchTicks { define 50000.000000 as 600000.000000 ticks;
# 49 "os_config.stc"
 }
# 49 "os_config.stc"

# 50 "os_config.stc"
	max_value 4294967295 ticks;
# 50 "os_config.stc"

# 51 "os_config.stc"
}


# 51 "os_config.stc"

# 52 "os_config.stc"
timebase real_time {
# 53 "os_config.stc"
	units s { define 1.000000 as 50000000.000000 ticks;
# 53 "os_config.stc"
 }
# 53 "os_config.stc"

# 54 "os_config.stc"
	units min { define 1.000000 as 60.000000 s;
# 54 "os_config.stc"
 }
# 54 "os_config.stc"

# 55 "os_config.stc"
	units ms { define 1000.000000 as 1.000000 s;
# 55 "os_config.stc"
 }
# 55 "os_config.stc"

# 56 "os_config.stc"
	units us { define 1000.000000 as 1.000000 ms;
# 56 "os_config.stc"
 }
# 56 "os_config.stc"

# 57 "os_config.stc"
	units ns { define 1000.000000 as 1.000000 us;
# 57 "os_config.stc"
 }
# 57 "os_config.stc"

# 58 "os_config.stc"
	max_value 4294967295 ticks;
# 58 "os_config.stc"

# 59 "os_config.stc"
}


# 59 "os_config.stc"

# 60 "os_config.stc"
timebase ts_etasCounter {
# 61 "os_config.stc"
	max_value 4294967295 ticks;
# 61 "os_config.stc"

# 62 "os_config.stc"
}


# 62 "os_config.stc"

# 63 "os_config.stc"

# 64 "os_config.stc"
stopwatch conversion {
# 65 "os_config.stc"
	on cpu_clock 1.000000 cycles is at worst 1.000000 cycles;
# 65 "os_config.stc"

# 66 "os_config.stc"
	on real_time 1.000000 s is at worst 50000000.000000 ticks;
# 66 "os_config.stc"

# 67 "os_config.stc"
	on ts_etasCounter 1.000000 ticks is at worst 50000.000000 ticks;
# 67 "os_config.stc"

# 68 "os_config.stc"
}


# 448 "os_config.stc"

# 449 "os_config.stc"
idle task {
# 450 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 450 "os_config.stc"

# 451 "os_config.stc"
	profile default_profile {
# 452 "os_config.stc"
		this priority duration undefined;
# 452 "os_config.stc"

# 453 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 453 "os_config.stc"

# 454 "os_config.stc"
	}
# 454 "os_config.stc"

# 455 "os_config.stc"
}


# 68 "os_config.stc"

# 69 "os_config.stc"

# 70 "os_config.stc"
task osek_task_SWT_CAN2_AP_FECU_Data1 {
# 71 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_FECU_Data1;
# 71 "os_config.stc"

# 72 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 72 "os_config.stc"

# 73 "os_config.stc"
	profile default_profile {
# 74 "os_config.stc"
		this priority duration undefined;
# 74 "os_config.stc"

# 75 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 75 "os_config.stc"

# 76 "os_config.stc"
	}
# 76 "os_config.stc"

# 77 "os_config.stc"
}


# 77 "os_config.stc"

# 78 "os_config.stc"

# 79 "os_config.stc"
task osek_task_SWT_CAN2_AP_FECU_Data2 {
# 80 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_FECU_Data2;
# 80 "os_config.stc"

# 81 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 81 "os_config.stc"

# 82 "os_config.stc"
	profile default_profile {
# 83 "os_config.stc"
		this priority duration undefined;
# 83 "os_config.stc"

# 84 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 84 "os_config.stc"

# 85 "os_config.stc"
	}
# 85 "os_config.stc"

# 86 "os_config.stc"
}


# 86 "os_config.stc"

# 87 "os_config.stc"

# 88 "os_config.stc"
task osek_task_SWT_CAN2_NM_RECU_Keep_Alive {
# 89 "os_config.stc"
	entry osek_task_e_SWT_CAN2_NM_RECU_Keep_Alive;
# 89 "os_config.stc"

# 90 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 90 "os_config.stc"

# 91 "os_config.stc"
	profile default_profile {
# 92 "os_config.stc"
		this priority duration undefined;
# 92 "os_config.stc"

# 93 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 93 "os_config.stc"

# 94 "os_config.stc"
	}
# 94 "os_config.stc"

# 95 "os_config.stc"
}


# 95 "os_config.stc"

# 96 "os_config.stc"

# 97 "os_config.stc"
task osek_task_SWT_CAN2_NM_FECU_Keep_Alive {
# 98 "os_config.stc"
	entry osek_task_e_SWT_CAN2_NM_FECU_Keep_Alive;
# 98 "os_config.stc"

# 99 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 99 "os_config.stc"

# 100 "os_config.stc"
	profile default_profile {
# 101 "os_config.stc"
		this priority duration undefined;
# 101 "os_config.stc"

# 102 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 102 "os_config.stc"

# 103 "os_config.stc"
	}
# 103 "os_config.stc"

# 104 "os_config.stc"
}


# 104 "os_config.stc"

# 105 "os_config.stc"

# 106 "os_config.stc"
task osek_task_SWT_CAN2_AP_RECU_Data {
# 107 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_RECU_Data;
# 107 "os_config.stc"

# 108 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 108 "os_config.stc"

# 109 "os_config.stc"
	profile default_profile {
# 110 "os_config.stc"
		this priority duration undefined;
# 110 "os_config.stc"

# 111 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 111 "os_config.stc"

# 112 "os_config.stc"
	}
# 112 "os_config.stc"

# 113 "os_config.stc"
}


# 113 "os_config.stc"

# 114 "os_config.stc"

# 115 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_VEL_Valid {
# 116 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_VEL_Valid;
# 116 "os_config.stc"

# 117 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 117 "os_config.stc"

# 118 "os_config.stc"
	profile default_profile {
# 119 "os_config.stc"
		this priority duration undefined;
# 119 "os_config.stc"

# 120 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 120 "os_config.stc"

# 121 "os_config.stc"
	}
# 121 "os_config.stc"

# 122 "os_config.stc"
}


# 122 "os_config.stc"

# 123 "os_config.stc"

# 124 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_IMU_GYRO {
# 125 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_IMU_GYRO;
# 125 "os_config.stc"

# 126 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 126 "os_config.stc"

# 127 "os_config.stc"
	profile default_profile {
# 128 "os_config.stc"
		this priority duration undefined;
# 128 "os_config.stc"

# 129 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 129 "os_config.stc"

# 130 "os_config.stc"
	}
# 130 "os_config.stc"

# 131 "os_config.stc"
}


# 131 "os_config.stc"

# 132 "os_config.stc"

# 133 "os_config.stc"
task osek_task_SWT_CAN2_NM_ELLIPSE_Status {
# 134 "os_config.stc"
	entry osek_task_e_SWT_CAN2_NM_ELLIPSE_Status;
# 134 "os_config.stc"

# 135 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 135 "os_config.stc"

# 136 "os_config.stc"
	profile default_profile {
# 137 "os_config.stc"
		this priority duration undefined;
# 137 "os_config.stc"

# 138 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 138 "os_config.stc"

# 139 "os_config.stc"
	}
# 139 "os_config.stc"

# 140 "os_config.stc"
}


# 140 "os_config.stc"

# 141 "os_config.stc"

# 142 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_VEL {
# 143 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_EKF_VEL;
# 143 "os_config.stc"

# 144 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 144 "os_config.stc"

# 145 "os_config.stc"
	profile default_profile {
# 146 "os_config.stc"
		this priority duration undefined;
# 146 "os_config.stc"

# 147 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 147 "os_config.stc"

# 148 "os_config.stc"
	}
# 148 "os_config.stc"

# 149 "os_config.stc"
}


# 149 "os_config.stc"

# 150 "os_config.stc"

# 151 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_EULER {
# 152 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_EKF_EULER;
# 152 "os_config.stc"

# 153 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 153 "os_config.stc"

# 154 "os_config.stc"
	profile default_profile {
# 155 "os_config.stc"
		this priority duration undefined;
# 155 "os_config.stc"

# 156 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 156 "os_config.stc"

# 157 "os_config.stc"
	}
# 157 "os_config.stc"

# 158 "os_config.stc"
}


# 158 "os_config.stc"

# 159 "os_config.stc"

# 160 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL {
# 161 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL;
# 161 "os_config.stc"

# 162 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 162 "os_config.stc"

# 163 "os_config.stc"
	profile default_profile {
# 164 "os_config.stc"
		this priority duration undefined;
# 164 "os_config.stc"

# 165 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 165 "os_config.stc"

# 166 "os_config.stc"
	}
# 166 "os_config.stc"

# 167 "os_config.stc"
}


# 167 "os_config.stc"

# 168 "os_config.stc"

# 169 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_POS {
# 170 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_EKF_POS;
# 170 "os_config.stc"

# 171 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 171 "os_config.stc"

# 172 "os_config.stc"
	profile default_profile {
# 173 "os_config.stc"
		this priority duration undefined;
# 173 "os_config.stc"

# 174 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 174 "os_config.stc"

# 175 "os_config.stc"
	}
# 175 "os_config.stc"

# 176 "os_config.stc"
}


# 176 "os_config.stc"

# 177 "os_config.stc"

# 178 "os_config.stc"
task osek_task_SWT_CAN2_MEAS_RECU_SDC {
# 179 "os_config.stc"
	entry osek_task_e_SWT_CAN2_MEAS_RECU_SDC;
# 179 "os_config.stc"

# 180 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 180 "os_config.stc"

# 181 "os_config.stc"
	profile default_profile {
# 182 "os_config.stc"
		this priority duration undefined;
# 182 "os_config.stc"

# 183 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 183 "os_config.stc"

# 184 "os_config.stc"
	}
# 184 "os_config.stc"

# 185 "os_config.stc"
}


# 185 "os_config.stc"

# 186 "os_config.stc"

# 187 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_GPS_VEL {
# 188 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_GPS_VEL;
# 188 "os_config.stc"

# 189 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 189 "os_config.stc"

# 190 "os_config.stc"
	profile default_profile {
# 191 "os_config.stc"
		this priority duration undefined;
# 191 "os_config.stc"

# 192 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 192 "os_config.stc"

# 193 "os_config.stc"
	}
# 193 "os_config.stc"

# 194 "os_config.stc"
}


# 194 "os_config.stc"

# 195 "os_config.stc"

# 196 "os_config.stc"
task osek_task_SWT_CAN2_AP_ELLIPSE_AUTO {
# 197 "os_config.stc"
	entry osek_task_e_SWT_CAN2_AP_ELLIPSE_AUTO;
# 197 "os_config.stc"

# 198 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 198 "os_config.stc"

# 199 "os_config.stc"
	profile default_profile {
# 200 "os_config.stc"
		this priority duration undefined;
# 200 "os_config.stc"

# 201 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 201 "os_config.stc"

# 202 "os_config.stc"
	}
# 202 "os_config.stc"

# 203 "os_config.stc"
}


# 203 "os_config.stc"

# 204 "os_config.stc"

# 205 "os_config.stc"
task osek_task_SWT_CAN1_AP_DASH_EnableDrive {
# 206 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_DASH_EnableDrive;
# 206 "os_config.stc"

# 207 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 207 "os_config.stc"

# 208 "os_config.stc"
	profile default_profile {
# 209 "os_config.stc"
		this priority duration undefined;
# 209 "os_config.stc"

# 210 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 210 "os_config.stc"

# 211 "os_config.stc"
	}
# 211 "os_config.stc"

# 212 "os_config.stc"
}


# 212 "os_config.stc"

# 213 "os_config.stc"

# 214 "os_config.stc"
task osek_task_SWT_CAN1_AP_DASH_PrechargeRequest {
# 215 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_DASH_PrechargeRequest;
# 215 "os_config.stc"

# 216 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 216 "os_config.stc"

# 217 "os_config.stc"
	profile default_profile {
# 218 "os_config.stc"
		this priority duration undefined;
# 218 "os_config.stc"

# 219 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 219 "os_config.stc"

# 220 "os_config.stc"
	}
# 220 "os_config.stc"

# 221 "os_config.stc"
}


# 221 "os_config.stc"

# 222 "os_config.stc"

# 223 "os_config.stc"
task osek_task_SWT_CAN1_NM_DASH_Keep_Alive {
# 224 "os_config.stc"
	entry osek_task_e_SWT_CAN1_NM_DASH_Keep_Alive;
# 224 "os_config.stc"

# 225 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 225 "os_config.stc"

# 226 "os_config.stc"
	profile default_profile {
# 227 "os_config.stc"
		this priority duration undefined;
# 227 "os_config.stc"

# 228 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 228 "os_config.stc"

# 229 "os_config.stc"
	}
# 229 "os_config.stc"

# 230 "os_config.stc"
}


# 230 "os_config.stc"

# 231 "os_config.stc"

# 232 "os_config.stc"
task osek_task_SWT_CAN1_AP_BMS_AIRs_State {
# 233 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_BMS_AIRs_State;
# 233 "os_config.stc"

# 234 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 234 "os_config.stc"

# 235 "os_config.stc"
	profile default_profile {
# 236 "os_config.stc"
		this priority duration undefined;
# 236 "os_config.stc"

# 237 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 237 "os_config.stc"

# 238 "os_config.stc"
	}
# 238 "os_config.stc"

# 239 "os_config.stc"
}


# 239 "os_config.stc"

# 240 "os_config.stc"

# 241 "os_config.stc"
task osek_task_SWT_CAN1_NM_BMS_Keep_Alive {
# 242 "os_config.stc"
	entry osek_task_e_SWT_CAN1_NM_BMS_Keep_Alive;
# 242 "os_config.stc"

# 243 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 243 "os_config.stc"

# 244 "os_config.stc"
	profile default_profile {
# 245 "os_config.stc"
		this priority duration undefined;
# 245 "os_config.stc"

# 246 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 246 "os_config.stc"

# 247 "os_config.stc"
	}
# 247 "os_config.stc"

# 248 "os_config.stc"
}


# 248 "os_config.stc"

# 249 "os_config.stc"

# 250 "os_config.stc"
task osek_task_SWT_CAN1_AP_DASH_Mode {
# 251 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_DASH_Mode;
# 251 "os_config.stc"

# 252 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 252 "os_config.stc"

# 253 "os_config.stc"
	profile default_profile {
# 254 "os_config.stc"
		this priority duration undefined;
# 254 "os_config.stc"

# 255 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 255 "os_config.stc"

# 256 "os_config.stc"
	}
# 256 "os_config.stc"

# 257 "os_config.stc"
}


# 257 "os_config.stc"

# 258 "os_config.stc"

# 259 "os_config.stc"
task osek_task_SWT_CAN1_AP_Inverter_L_Tx {
# 260 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_Inverter_L_Tx;
# 260 "os_config.stc"

# 261 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 261 "os_config.stc"

# 262 "os_config.stc"
	profile default_profile {
# 263 "os_config.stc"
		this priority duration undefined;
# 263 "os_config.stc"

# 264 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 264 "os_config.stc"

# 265 "os_config.stc"
	}
# 265 "os_config.stc"

# 266 "os_config.stc"
}


# 266 "os_config.stc"

# 267 "os_config.stc"

# 268 "os_config.stc"
task osek_task_SWT_CAN1_AP_Inverter_R_Tx {
# 269 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_Inverter_R_Tx;
# 269 "os_config.stc"

# 270 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 270 "os_config.stc"

# 271 "os_config.stc"
	profile default_profile {
# 272 "os_config.stc"
		this priority duration undefined;
# 272 "os_config.stc"

# 273 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 273 "os_config.stc"

# 274 "os_config.stc"
	}
# 274 "os_config.stc"

# 275 "os_config.stc"
}


# 275 "os_config.stc"

# 276 "os_config.stc"

# 277 "os_config.stc"
task osek_task_SWT_CAN1_AP_BMS_Temperatures {
# 278 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_BMS_Temperatures;
# 278 "os_config.stc"

# 279 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 279 "os_config.stc"

# 280 "os_config.stc"
	profile default_profile {
# 281 "os_config.stc"
		this priority duration undefined;
# 281 "os_config.stc"

# 282 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 282 "os_config.stc"

# 283 "os_config.stc"
	}
# 283 "os_config.stc"

# 284 "os_config.stc"
}


# 284 "os_config.stc"

# 285 "os_config.stc"

# 286 "os_config.stc"
task osek_task_SWT_CAN1_AP_BMS_ChargerParameters {
# 287 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_BMS_ChargerParameters;
# 287 "os_config.stc"

# 288 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 288 "os_config.stc"

# 289 "os_config.stc"
	profile default_profile {
# 290 "os_config.stc"
		this priority duration undefined;
# 290 "os_config.stc"

# 291 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 291 "os_config.stc"

# 292 "os_config.stc"
	}
# 292 "os_config.stc"

# 293 "os_config.stc"
}


# 293 "os_config.stc"

# 294 "os_config.stc"

# 295 "os_config.stc"
task osek_task_SWT_CAN1_AP_BMS_Voltages {
# 296 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_BMS_Voltages;
# 296 "os_config.stc"

# 297 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 297 "os_config.stc"

# 298 "os_config.stc"
	profile default_profile {
# 299 "os_config.stc"
		this priority duration undefined;
# 299 "os_config.stc"

# 300 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 300 "os_config.stc"

# 301 "os_config.stc"
	}
# 301 "os_config.stc"

# 302 "os_config.stc"
}


# 302 "os_config.stc"

# 303 "os_config.stc"

# 304 "os_config.stc"
task osek_task_SWT_CAN1_AP_CurrentSensor {
# 305 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_CurrentSensor;
# 305 "os_config.stc"

# 306 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 306 "os_config.stc"

# 307 "os_config.stc"
	profile default_profile {
# 308 "os_config.stc"
		this priority duration undefined;
# 308 "os_config.stc"

# 309 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 309 "os_config.stc"

# 310 "os_config.stc"
	}
# 310 "os_config.stc"

# 311 "os_config.stc"
}


# 311 "os_config.stc"

# 312 "os_config.stc"

# 313 "os_config.stc"
task osek_task_SWT_CAN1_AP_BMS_SDC {
# 314 "os_config.stc"
	entry osek_task_e_SWT_CAN1_AP_BMS_SDC;
# 314 "os_config.stc"

# 315 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 315 "os_config.stc"

# 316 "os_config.stc"
	profile default_profile {
# 317 "os_config.stc"
		this priority duration undefined;
# 317 "os_config.stc"

# 318 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 318 "os_config.stc"

# 319 "os_config.stc"
	}
# 319 "os_config.stc"

# 320 "os_config.stc"
}


# 320 "os_config.stc"

# 321 "os_config.stc"

# 322 "os_config.stc"
task osek_task_Timer_1000ms {
# 323 "os_config.stc"
	entry osek_task_e_Timer_1000ms;
# 323 "os_config.stc"

# 324 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 324 "os_config.stc"

# 325 "os_config.stc"
	profile default_profile {
# 326 "os_config.stc"
		this priority duration undefined;
# 326 "os_config.stc"

# 327 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 327 "os_config.stc"

# 328 "os_config.stc"
		 
# 329 "os_config.stc"
	}
# 329 "os_config.stc"

# 330 "os_config.stc"
}


# 330 "os_config.stc"

# 331 "os_config.stc"

# 332 "os_config.stc"
task osek_task_Timer_100ms {
# 333 "os_config.stc"
	entry osek_task_e_Timer_100ms;
# 333 "os_config.stc"

# 334 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 334 "os_config.stc"

# 335 "os_config.stc"
	profile default_profile {
# 336 "os_config.stc"
		this priority duration undefined;
# 336 "os_config.stc"

# 337 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 337 "os_config.stc"

# 338 "os_config.stc"
		 
# 339 "os_config.stc"
	}
# 339 "os_config.stc"

# 340 "os_config.stc"
}


# 340 "os_config.stc"

# 341 "os_config.stc"

# 342 "os_config.stc"
task osek_task_Timer_25ms {
# 343 "os_config.stc"
	entry osek_task_e_Timer_25ms;
# 343 "os_config.stc"

# 344 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 344 "os_config.stc"

# 345 "os_config.stc"
	profile default_profile {
# 346 "os_config.stc"
		this priority duration undefined;
# 346 "os_config.stc"

# 347 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 347 "os_config.stc"

# 348 "os_config.stc"
		 
# 349 "os_config.stc"
	}
# 349 "os_config.stc"

# 350 "os_config.stc"
}


# 350 "os_config.stc"

# 351 "os_config.stc"

# 352 "os_config.stc"
task osek_task_Timer_Inv {
# 353 "os_config.stc"
	entry osek_task_e_Timer_Inv;
# 353 "os_config.stc"

# 354 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 354 "os_config.stc"

# 355 "os_config.stc"
	profile default_profile {
# 356 "os_config.stc"
		this priority duration undefined;
# 356 "os_config.stc"

# 357 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 357 "os_config.stc"

# 358 "os_config.stc"
		 
# 359 "os_config.stc"
	}
# 359 "os_config.stc"

# 360 "os_config.stc"
}


# 360 "os_config.stc"

# 361 "os_config.stc"

# 362 "os_config.stc"
task osek_task_Timer_Sync {
# 363 "os_config.stc"
	entry osek_task_e_Timer_Sync;
# 363 "os_config.stc"

# 364 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 364 "os_config.stc"

# 365 "os_config.stc"
	profile default_profile {
# 366 "os_config.stc"
		this priority duration undefined;
# 366 "os_config.stc"

# 367 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 367 "os_config.stc"

# 368 "os_config.stc"
		 
# 369 "os_config.stc"
	}
# 369 "os_config.stc"

# 370 "os_config.stc"
}


# 370 "os_config.stc"

# 371 "os_config.stc"

# 372 "os_config.stc"
task osek_task_etasL1Task {
# 373 "os_config.stc"
	entry osek_task_e_etasL1Task;
# 373 "os_config.stc"

# 374 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 374 "os_config.stc"

# 375 "os_config.stc"
	profile default_profile {
# 376 "os_config.stc"
		this priority duration undefined;
# 376 "os_config.stc"

# 377 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 377 "os_config.stc"

# 378 "os_config.stc"
	}
# 378 "os_config.stc"

# 379 "os_config.stc"
}


# 379 "os_config.stc"

# 380 "os_config.stc"

# 381 "os_config.stc"
task osek_task_etasConfigTask {
# 382 "os_config.stc"
	entry osek_task_e_etasConfigTask;
# 382 "os_config.stc"

# 383 "os_config.stc"
	locks resource osek_resource_RES_SCHEDULER;
# 383 "os_config.stc"

# 384 "os_config.stc"
	profile default_profile {
# 385 "os_config.stc"
		this priority duration undefined;
# 385 "os_config.stc"

# 386 "os_config.stc"
		resource osek_resource_RES_SCHEDULER duration undefined;
# 386 "os_config.stc"

# 387 "os_config.stc"
	}
# 387 "os_config.stc"

# 388 "os_config.stc"
}


# 388 "os_config.stc"

# 389 "os_config.stc"

# 390 "os_config.stc"
taskset osek_bcc1_tasks {
# 391 "os_config.stc"
	label osek_bcc1_ts;
# 391 "os_config.stc"

# 392 "os_config.stc"
	task osek_task_SWT_CAN2_AP_FECU_Data1;
# 392 "os_config.stc"

# 393 "os_config.stc"
	task osek_task_SWT_CAN2_AP_FECU_Data2;
# 393 "os_config.stc"

# 394 "os_config.stc"
	task osek_task_SWT_CAN2_NM_RECU_Keep_Alive;
# 394 "os_config.stc"

# 395 "os_config.stc"
	task osek_task_SWT_CAN2_NM_FECU_Keep_Alive;
# 395 "os_config.stc"

# 396 "os_config.stc"
	task osek_task_SWT_CAN2_AP_RECU_Data;
# 396 "os_config.stc"

# 397 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_VEL_Valid;
# 397 "os_config.stc"

# 398 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_IMU_GYRO;
# 398 "os_config.stc"

# 399 "os_config.stc"
	task osek_task_SWT_CAN2_NM_ELLIPSE_Status;
# 399 "os_config.stc"

# 400 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_VEL;
# 400 "os_config.stc"

# 401 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_EULER;
# 401 "os_config.stc"

# 402 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL;
# 402 "os_config.stc"

# 403 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_POS;
# 403 "os_config.stc"

# 404 "os_config.stc"
	task osek_task_SWT_CAN2_MEAS_RECU_SDC;
# 404 "os_config.stc"

# 405 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_GPS_VEL;
# 405 "os_config.stc"

# 406 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_AUTO;
# 406 "os_config.stc"

# 407 "os_config.stc"
	task osek_task_SWT_CAN1_AP_DASH_EnableDrive;
# 407 "os_config.stc"

# 408 "os_config.stc"
	task osek_task_SWT_CAN1_AP_DASH_PrechargeRequest;
# 408 "os_config.stc"

# 409 "os_config.stc"
	task osek_task_SWT_CAN1_NM_DASH_Keep_Alive;
# 409 "os_config.stc"

# 410 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_AIRs_State;
# 410 "os_config.stc"

# 411 "os_config.stc"
	task osek_task_SWT_CAN1_NM_BMS_Keep_Alive;
# 411 "os_config.stc"

# 412 "os_config.stc"
	task osek_task_SWT_CAN1_AP_DASH_Mode;
# 412 "os_config.stc"

# 413 "os_config.stc"
	task osek_task_SWT_CAN1_AP_Inverter_L_Tx;
# 413 "os_config.stc"

# 414 "os_config.stc"
	task osek_task_SWT_CAN1_AP_Inverter_R_Tx;
# 414 "os_config.stc"

# 415 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_Temperatures;
# 415 "os_config.stc"

# 416 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_ChargerParameters;
# 416 "os_config.stc"

# 417 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_Voltages;
# 417 "os_config.stc"

# 418 "os_config.stc"
	task osek_task_SWT_CAN1_AP_CurrentSensor;
# 418 "os_config.stc"

# 419 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_SDC;
# 419 "os_config.stc"

# 420 "os_config.stc"
}


# 420 "os_config.stc"

# 421 "os_config.stc"

# 422 "os_config.stc"
taskset osek_cc2_tasks {
# 423 "os_config.stc"
	label osek_cc2_ts;
# 423 "os_config.stc"

# 424 "os_config.stc"
	task osek_task_Timer_1000ms;
# 424 "os_config.stc"

# 425 "os_config.stc"
	task osek_task_Timer_100ms;
# 425 "os_config.stc"

# 426 "os_config.stc"
	task osek_task_Timer_25ms;
# 426 "os_config.stc"

# 427 "os_config.stc"
	task osek_task_Timer_Inv;
# 427 "os_config.stc"

# 428 "os_config.stc"
	task osek_task_Timer_Sync;
# 428 "os_config.stc"

# 429 "os_config.stc"
	task osek_task_etasL1Task;
# 429 "os_config.stc"

# 430 "os_config.stc"
	task osek_task_etasConfigTask;
# 430 "os_config.stc"

# 431 "os_config.stc"
}


# 431 "os_config.stc"

# 432 "os_config.stc"

# 433 "os_config.stc"
taskset osek_ecc_tasks {
# 434 "os_config.stc"
	label osek_ecc_ts;
# 434 "os_config.stc"

# 435 "os_config.stc"
}


# 435 "os_config.stc"

# 436 "os_config.stc"

# 437 "os_config.stc"
nonpreemption group   {
# 438 "os_config.stc"
	task osek_task_etasL1Task;
# 438 "os_config.stc"

# 439 "os_config.stc"
	task osek_task_etasConfigTask;
# 439 "os_config.stc"

# 440 "os_config.stc"
}


# 440 "os_config.stc"

# 441 "os_config.stc"

# 442 "os_config.stc"
nonpreemption group   {
# 443 "os_config.stc"
	task osek_task_Timer_1000ms;
# 443 "os_config.stc"

# 444 "os_config.stc"
	task osek_task_Timer_100ms;
# 444 "os_config.stc"

# 445 "os_config.stc"
	task osek_task_Timer_25ms;
# 445 "os_config.stc"

# 446 "os_config.stc"
	task osek_task_Timer_Inv;
# 446 "os_config.stc"

# 447 "os_config.stc"
	task osek_task_Timer_Sync;
# 447 "os_config.stc"

# 448 "os_config.stc"
}


# 455 "os_config.stc"

# 456 "os_config.stc"

# 457 "os_config.stc"
interrupt osek_interrupt_etasTimerIsr {
# 458 "os_config.stc"
	entry osek_isr_e_etasTimerIsr;
# 458 "os_config.stc"

# 459 "os_config.stc"
	controlled;
# 459 "os_config.stc"

# 460 "os_config.stc"
	priority 10;
# 460 "os_config.stc"

# 461 "os_config.stc"
	vector 48;
# 461 "os_config.stc"

# 462 "os_config.stc"
	profile default_profile {
# 463 "os_config.stc"
		this priority duration undefined;
# 463 "os_config.stc"

# 464 "os_config.stc"
	}
# 464 "os_config.stc"

# 465 "os_config.stc"
}


# 465 "os_config.stc"

# 466 "os_config.stc"

# 467 "os_config.stc"
interrupt osek_interrupt_etasL1Isr {
# 468 "os_config.stc"
	entry osE_etasL1Isr;
# 468 "os_config.stc"

# 469 "os_config.stc"
	controlled;
# 469 "os_config.stc"

# 470 "os_config.stc"
	priority 1;
# 470 "os_config.stc"

# 471 "os_config.stc"
	vector 200;
# 471 "os_config.stc"

# 472 "os_config.stc"
	profile default_profile {
# 473 "os_config.stc"
		this priority duration undefined;
# 473 "os_config.stc"

# 474 "os_config.stc"
	}
# 474 "os_config.stc"

# 475 "os_config.stc"
}


# 475 "os_config.stc"

# 476 "os_config.stc"

# 477 "os_config.stc"
interrupt osek_interrupt_etasStopOsIsr {
# 478 "os_config.stc"
	entry osek_isr_e_etasStopOsIsr;
# 478 "os_config.stc"

# 479 "os_config.stc"
	controlled;
# 479 "os_config.stc"

# 480 "os_config.stc"
	priority 11;
# 480 "os_config.stc"

# 481 "os_config.stc"
	vector 203;
# 481 "os_config.stc"

# 482 "os_config.stc"
	profile default_profile {
# 483 "os_config.stc"
		this priority duration undefined;
# 483 "os_config.stc"

# 484 "os_config.stc"
	}
# 484 "os_config.stc"

# 485 "os_config.stc"
}


# 485 "os_config.stc"

# 486 "os_config.stc"

# 487 "os_config.stc"
interrupt osek_interrupt_etasActivateTaskIsr {
# 488 "os_config.stc"
	entry osek_isr_e_etasActivateTaskIsr;
# 488 "os_config.stc"

# 489 "os_config.stc"
	controlled;
# 489 "os_config.stc"

# 490 "os_config.stc"
	priority 10;
# 490 "os_config.stc"

# 491 "os_config.stc"
	vector 216;
# 491 "os_config.stc"

# 492 "os_config.stc"
	profile default_profile {
# 493 "os_config.stc"
		this priority duration undefined;
# 493 "os_config.stc"

# 494 "os_config.stc"
	}
# 494 "os_config.stc"

# 495 "os_config.stc"
}


# 495 "os_config.stc"

# 496 "os_config.stc"

# 497 "os_config.stc"
interrupt osek_interrupt_ISR_CAN1 {
# 498 "os_config.stc"
	entry osE_ISR_CAN1;
# 498 "os_config.stc"

# 499 "os_config.stc"
	controlled;
# 499 "os_config.stc"

# 500 "os_config.stc"
	priority 1;
# 500 "os_config.stc"

# 501 "os_config.stc"
	vector 205;
# 501 "os_config.stc"

# 502 "os_config.stc"
	profile default_profile {
# 503 "os_config.stc"
		this priority duration undefined;
# 503 "os_config.stc"

# 504 "os_config.stc"
	}
# 504 "os_config.stc"

# 505 "os_config.stc"
}


# 505 "os_config.stc"

# 506 "os_config.stc"

# 507 "os_config.stc"
interrupt osek_interrupt_ISR_CAN2 {
# 508 "os_config.stc"
	entry osE_ISR_CAN2;
# 508 "os_config.stc"

# 509 "os_config.stc"
	controlled;
# 509 "os_config.stc"

# 510 "os_config.stc"
	priority 1;
# 510 "os_config.stc"

# 511 "os_config.stc"
	vector 206;
# 511 "os_config.stc"

# 512 "os_config.stc"
	profile default_profile {
# 513 "os_config.stc"
		this priority duration undefined;
# 513 "os_config.stc"

# 514 "os_config.stc"
	}
# 514 "os_config.stc"

# 515 "os_config.stc"
}


# 515 "os_config.stc"

# 516 "os_config.stc"

# 517 "os_config.stc"
arbitration order {
# 518 "os_config.stc"
	interrupt priority 11 {
# 519 "os_config.stc"
		interrupt osek_interrupt_etasStopOsIsr;
# 519 "os_config.stc"

# 520 "os_config.stc"
	}
# 520 "os_config.stc"

# 521 "os_config.stc"
	interrupt priority 10 {
# 522 "os_config.stc"
		interrupt osek_interrupt_etasTimerIsr;
# 522 "os_config.stc"

# 523 "os_config.stc"
		interrupt osek_interrupt_etasActivateTaskIsr;
# 523 "os_config.stc"

# 524 "os_config.stc"
	}
# 524 "os_config.stc"

# 525 "os_config.stc"
	interrupt priority 1 {
# 526 "os_config.stc"
		interrupt osek_interrupt_etasL1Isr;
# 526 "os_config.stc"

# 527 "os_config.stc"
		interrupt osek_interrupt_ISR_CAN1;
# 527 "os_config.stc"

# 528 "os_config.stc"
		interrupt osek_interrupt_ISR_CAN2;
# 528 "os_config.stc"

# 529 "os_config.stc"
	}
# 529 "os_config.stc"

# 530 "os_config.stc"
}


# 530 "os_config.stc"

# 531 "os_config.stc"

# 532 "os_config.stc"
system timings undefined;


# 532 "os_config.stc"

# 533 "os_config.stc"
interrupt recognition undefined;


# 533 "os_config.stc"

# 534 "os_config.stc"

# 535 "os_config.stc"
task priority order {
# 536 "os_config.stc"
	task osek_task_SWT_CAN2_AP_FECU_Data1;
# 536 "os_config.stc"

# 537 "os_config.stc"
	task osek_task_SWT_CAN2_AP_FECU_Data2;
# 537 "os_config.stc"

# 538 "os_config.stc"
	task osek_task_SWT_CAN2_NM_RECU_Keep_Alive;
# 538 "os_config.stc"

# 539 "os_config.stc"
	task osek_task_SWT_CAN2_NM_FECU_Keep_Alive;
# 539 "os_config.stc"

# 540 "os_config.stc"
	task osek_task_SWT_CAN2_AP_RECU_Data;
# 540 "os_config.stc"

# 541 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_VEL_Valid;
# 541 "os_config.stc"

# 542 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_IMU_GYRO;
# 542 "os_config.stc"

# 543 "os_config.stc"
	task osek_task_SWT_CAN2_NM_ELLIPSE_Status;
# 543 "os_config.stc"

# 544 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_VEL;
# 544 "os_config.stc"

# 545 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_EULER;
# 545 "os_config.stc"

# 546 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_IMU_ACCEL;
# 546 "os_config.stc"

# 547 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_EKF_POS;
# 547 "os_config.stc"

# 548 "os_config.stc"
	task osek_task_SWT_CAN2_MEAS_RECU_SDC;
# 548 "os_config.stc"

# 549 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_GPS_VEL;
# 549 "os_config.stc"

# 550 "os_config.stc"
	task osek_task_SWT_CAN2_AP_ELLIPSE_AUTO;
# 550 "os_config.stc"

# 551 "os_config.stc"
	task osek_task_SWT_CAN1_AP_DASH_EnableDrive;
# 551 "os_config.stc"

# 552 "os_config.stc"
	task osek_task_SWT_CAN1_AP_DASH_PrechargeRequest;
# 552 "os_config.stc"

# 553 "os_config.stc"
	task osek_task_SWT_CAN1_NM_DASH_Keep_Alive;
# 553 "os_config.stc"

# 554 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_AIRs_State;
# 554 "os_config.stc"

# 555 "os_config.stc"
	task osek_task_SWT_CAN1_NM_BMS_Keep_Alive;
# 555 "os_config.stc"

# 556 "os_config.stc"
	task osek_task_SWT_CAN1_AP_DASH_Mode;
# 556 "os_config.stc"

# 557 "os_config.stc"
	task osek_task_SWT_CAN1_AP_Inverter_L_Tx;
# 557 "os_config.stc"

# 558 "os_config.stc"
	task osek_task_SWT_CAN1_AP_Inverter_R_Tx;
# 558 "os_config.stc"

# 559 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_Temperatures;
# 559 "os_config.stc"

# 560 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_ChargerParameters;
# 560 "os_config.stc"

# 561 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_Voltages;
# 561 "os_config.stc"

# 562 "os_config.stc"
	task osek_task_SWT_CAN1_AP_CurrentSensor;
# 562 "os_config.stc"

# 563 "os_config.stc"
	task osek_task_SWT_CAN1_AP_BMS_SDC;
# 563 "os_config.stc"

# 564 "os_config.stc"
	task osek_task_Timer_1000ms;
# 564 "os_config.stc"

# 565 "os_config.stc"
	task osek_task_Timer_100ms;
# 565 "os_config.stc"

# 566 "os_config.stc"
	task osek_task_Timer_25ms;
# 566 "os_config.stc"

# 567 "os_config.stc"
	task osek_task_Timer_Inv;
# 567 "os_config.stc"

# 568 "os_config.stc"
	task osek_task_Timer_Sync;
# 568 "os_config.stc"

# 569 "os_config.stc"
	task osek_task_etasL1Task;
# 569 "os_config.stc"

# 570 "os_config.stc"
	task osek_task_etasConfigTask;
# 570 "os_config.stc"

# 571 "os_config.stc"
}
