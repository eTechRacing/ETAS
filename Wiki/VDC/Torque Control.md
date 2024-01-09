==Small description==

# Safety Block

![[Media/Safety Block Image.png]]

Block responsible for safety of the car (this in image footer).

Inputs:

- `TorqueEnable` [[Boolean type|bool]]: Message Dashboard send to the ETAS when car is ready to drive.

- `CriticalDisconection` [[Boolean type|bool]] (System critical signals): Extra signal that check that all the signals are working (Pedals, FrontECU, Dash and Brake).

- `CarState` [[Integer type|int]]: The State (from state machine) the ETAS passes to tell the car that is ready to go (15 means is ready to go).

- `APPS1_Value` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]]: Acceleration pedal sensor 1 (0-1).

- `APPS2_Value` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]]: Acceleration pedal sensor 2 (0-1).

- `Shutdown_PackageIntck` [[Boolean type|bool]]: Low voltage circuit that verifies that the relays can work on HV.

Outputs:

- `TorqueOK` [[Boolean type|bool]]: Car is fine and the car will respond to the pedals.

- `APPS_Implausibility` [[Boolean type|bool]]: Signal that check if both APPS# signals are correct.

# Accumulator Power 

![[Media/Accumulator Power Block Image.png]]

Block responsible for calculates the power in real time

Inputs:

- `Accumulator_Voltge` [[Floating Point type|float]] \[3 decimal resolution]: Voltage of the ACU (sum of cells).

- `Accumulator_Current` [[Floating Point type|float]] \[3 decimal resolution]: Intensity of the ACU (sum of cells).

Outputs:

- `Power` [[Integer type|int]]: Power deploys the ACU.

- `PowerLimitedReached` [[Integer type|int]]: tells if we are above maximum power

- `PowerMean500ms` [[Integer type|int]]: Average power 500ms.

# Power Limitation Temperature Block

![[Media/Power Limitation Temperature Block Image.png]]

Block responsible to limit the power, from different variables that limits over critical values: like temperature from components (for safety and performance).

> **_NOTE:_**  The resolution for temperature is enough with 2 decimals.

Inputs:

- `Temp_Motors` [[Floating Point type|float]] \[5 decimal resolution]: give the temperature of the motor (the peak temperature in Celsius).

- `Temp_IGBT`  [[Floating Point type|float]] \[5 decimal resolution] (Isolated Gate Bipolar Transistor): give the temperature the transistors of the inverters (the peak temperature in Celsius).

- `Temp_Cell` [[Floating Point type|float]] \[5 decimal resolution]: give the temperature of the cells for the battery/accumulator (the peak temperature in Celsius).

- `SOC_Low` [[Floating Point type|float]] \[5 decimal resolution] (State of Charge): give the percentage (from 0 to 1) from the lowest cell.

- `SOC_High` [[Floating Point type|float]] \[5 decimal resolution] (State of Charge): give the percentage (from 0 to 1) from the lowest cell.

- `Motor_Tq_R` [[Floating Point type|float]] \[5 decimal resolution]: value that give the current torque to the right wheel.

- `Motor_Tq_L` [[Floating Point type|float]] \[5 decimal resolution]: value that give the current torque to the left wheel: float

- `Braking` [[Boolean type|bool]]: flag that tells the driver is braking (1).

Output:

- `Accu_Temperature_Limitation_Flag` [[Boolean type|bool]]: flag that displays that temperature has exceeded.

- `Inverters_Temperature_Limitation_Flag` [[Boolean type|bool]]: flag that displays that temperature has exceeded.

- `Motors_Temperature_Limitation_Flag` [[Boolean type|bool]]: flag that displays that temperature has exceeded.

- `SOP_Discharge`  [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]] (State of Power): give the percentage (0-1) that you can extract from the battery (implementation with lookup tables).

- `SOP_Regen`  [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]] (State of Power): give the percentage (0-1) that you can supply to the battery (implementation with lookup tables).

## Temperature SOP Block

![[Media/Temperature SOP Block Image.png]]

Block responsible limit the power for all temperature defines the power factor.

Inputs:

- `max_motor_temp` [[Floating Point type|float]] \[5 decimal resolution]: give the temperature of the motor (the peak temperature in Celsius).

- `max_inverter_temp` [[Floating Point type|float]] \[5 decimal resolution]: give the temperature the transistors of the inverters (the peak temperature in Celsius).

- `max_cell_temp` [[Floating Point type|float]] \[5 decimal resolution]: give the temperature of the cells for the battery/accumulator (the peak temperature in Celsius).

- `initial_limitation` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]]: factor that is multiplied in order decrease exponentially the temperature (0-1).

Outputs:

- `SOP` [[Boolean type|bool]] (State of Power): flag that tells is if limited by temperature.

- `Accu_Temperature_Limitation_Flag` [[Boolean type|bool]]: flag that displays that temperature has exceeded.

- `Inverters_Temperature_Limitation_Flag`[[Boolean type|bool]]: flag that displays that temperature has exceeded.

- `Motors_Temperature_Limitation_Flag` [[Boolean type|bool]]: flag that displays that temperature has exceeded.

## SOC SOP Block

![[Media/SOC SOP Block Image.png]]

Block responsible limit the power for SOC overcharge and undercharge.

Inputs:

- `SOC_Low` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]] (State of Charge): give the percentage (0-1) from the lowest cell.

- `SOC_High` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]] (State of Charge): give the percentage (0-1) from the lowest cell.

- `SoP_Temperature` [[Floating Point type|float]] (State of Power): flag that tells is if limited by temperature.

- `max_cell_temp` [[Floating Point type|float]] \[5 decimal resolution]: give the temperature of the cells for the battery/accumulator (the peak temperature in Celsius).

Outputs:

-  `SOP_Discharge` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]] (State of Power): give the percentage (0-1) that you can extract from the battery (implementation with lookup tables).

- `SOP_Regen` [[Floating Point type#Ranged Float|ranged]] [[Floating Point type|float]] (State of Power): give the percentage (0-1) that you can supply to the battery (implementation with lookup tables).

## Torque Limitation Temperature Controller Block

==**This Block needs total rewrite, further information will be added**==

# Power Limitation Torque Block

![[Media/Power Limitation Torque Block Imagen.png]]

Block responsible for limit the torque from wheels.

Input:

- `Tq_R_Motor` [[Floating Point type|float]]: The torque that generates the right motor in NM.

- `Tq_L_Motor` [[Floating Point type|float]]: The torque that generates the left motor in NM.

- `Rev_R_Wheel` [[Floating Point type|float]]: The torque that generates the right wheel in rad/s.

- `Rev_L_Wheel` [[Floating Point type|float]]: The torque that generates the left wheel in rad/s.

- `Braking` [[Boolean type|bool]]: flag that tells the driver is braking (1). 

Output:

- `Tq_R_lim` [[Floating Point type|float]]: The torque that generates the right motor limited in NM.

- `Tq_L_lim` [[Floating Point type|float]]: The torque that generates the left motor limited in NM:.

# Calculate Current Conversion Block

![[Media/Constant Torque Current Block Image.png]]

Block responsible for taking a torque and convert to current.

Input:

- `Torque_R_motor` [[Floating Point type|float]]: The torque that generates the right motor limited in NM.

- `Torque_L_motor` [[Floating Point type|float]]: The torque that generates the left motor limited in NM.

Output:

- `Current R` [[Floating Point type|float]]: The current that is generated to power the right motor in A.

- `Current L` [[Floating Point type|float]]: The current that is generated to power the light motor in A.

# Constant Torque Current Block

![[Media/Pasted image 20240109224100.png]]

Block responsible to deactivate the output of something fails.

Output:

- `Current R` [[Floating Point type|float]] \[that is 0 if torque is not ok (**_safety mode_**)]: The current that is generated to power the right motor in A.

- `Current L` [[Floating Point type|float]] \[that is 0 if torque is not ok (**_safety mode_**)]: The current that is generated to power the light motor in A.