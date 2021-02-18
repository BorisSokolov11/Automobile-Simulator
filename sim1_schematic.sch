EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Leonardo A?
U 1 1 602ACA74
P 5800 3300
F 0 "A?" V 5400 4350 50  0001 L CNN
F 1 "Arduino_Leonardo" V 5800 2850 50  0000 L CNN
F 2 "Module:Arduino_UNO_R3" H 5800 3300 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/ArduinoBoardLeonardo" H 5800 3300 50  0001 C CNN
	1    5800 3300
	0    1    1    0   
$EndComp
$Comp
L test:POT_1 Accel
U 1 1 602CBC70
P 6300 4650
F 0 "Accel" V 5700 4550 50  0000 R CNN
F 1 "POT_1" V 5800 4550 50  0000 R CNN
F 2 "" H 6300 4650 50  0001 C CNN
F 3 "" H 6300 4650 50  0001 C CNN
	1    6300 4650
	0    -1   -1   0   
$EndComp
$Comp
L test:POT_1 Brake
U 1 1 602CD87E
P 5850 4650
F 0 "Brake" V 5250 4550 50  0000 R CNN
F 1 "POT_2" V 5350 4550 50  0000 R CNN
F 2 "" H 5850 4650 50  0001 C CNN
F 3 "" H 5850 4650 50  0001 C CNN
	1    5850 4650
	0    -1   -1   0   
$EndComp
$Comp
L test:POT_1 Clutch
U 1 1 602D0536
P 5400 4650
F 0 "Clutch" V 4800 4550 50  0000 R CNN
F 1 "POT_3" V 4900 4550 50  0000 R CNN
F 2 "" H 5400 4650 50  0001 C CNN
F 3 "" H 5400 4650 50  0001 C CNN
	1    5400 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 4400 5600 3800
Wire Wire Line
	6050 4400 6050 4000
Wire Wire Line
	6050 4000 5700 4000
Wire Wire Line
	5700 4000 5700 3800
Wire Wire Line
	6500 4400 6500 3900
Wire Wire Line
	6500 3900 5800 3900
Wire Wire Line
	5800 3900 5800 3800
$Comp
L Motor:Motor_DC 12V
U 1 1 602DCE05
P 9100 3500
F 0 "12V" H 9258 3496 50  0000 L CNN
F 1 "Motor_DC" H 9258 3405 50  0000 L CNN
F 2 "" H 9100 3410 50  0001 C CNN
F 3 "~" H 9100 3410 50  0001 C CNN
	1    9100 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3600 8700 3800
Wire Wire Line
	8700 3800 9100 3800
Wire Wire Line
	8700 3300 9100 3300
$Comp
L test:BTS7960B_Motor_Driver U?
U 1 1 602E0748
P 8200 2850
F 0 "U?" H 8225 2965 50  0001 C CNN
F 1 "BTS7960B_Motor_Driver" H 8225 2873 50  0000 C CNN
F 2 "" H 8200 2850 50  0001 C CNN
F 3 "" H 8200 2850 50  0001 C CNN
	1    8200 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3300 8700 3500
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602E3A2C
P 4000 2650
F 0 "Shifter" H 4000 2917 50  0000 C CNN
F 1 "SW_Gear_1" H 4000 2826 50  0000 C CNN
F 2 "" H 4000 2650 50  0001 C CNN
F 3 "~" H 4000 2650 50  0001 C CNN
	1    4000 2650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602E64E1
P 4000 3100
F 0 "Shifter" H 4000 3367 50  0000 C CNN
F 1 "SW_Gear_3" H 4000 3276 50  0000 C CNN
F 2 "" H 4000 3100 50  0001 C CNN
F 3 "~" H 4000 3100 50  0001 C CNN
	1    4000 3100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602E754F
P 4000 3550
F 0 "Shifter" H 4000 3817 50  0000 C CNN
F 1 "SW_Gear_5" H 4000 3726 50  0000 C CNN
F 2 "" H 4000 3550 50  0001 C CNN
F 3 "~" H 4000 3550 50  0001 C CNN
	1    4000 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602E7D43
P 3200 3550
F 0 "Shifter" H 3200 3283 50  0000 C CNN
F 1 "SW_Gear_6" H 3200 3374 50  0000 C CNN
F 2 "" H 3200 3550 50  0001 C CNN
F 3 "~" H 3200 3550 50  0001 C CNN
	1    3200 3550
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602E9BBC
P 3200 3100
F 0 "Shifter" H 3200 2833 50  0000 C CNN
F 1 "SW_Gear_4" H 3200 2924 50  0000 C CNN
F 2 "" H 3200 3100 50  0001 C CNN
F 3 "~" H 3200 3100 50  0001 C CNN
	1    3200 3100
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602EA540
P 3200 2650
F 0 "Shifter" H 3200 2383 50  0000 C CNN
F 1 "SW_Gear_2" H 3200 2474 50  0000 C CNN
F 2 "" H 3200 2650 50  0001 C CNN
F 3 "~" H 3200 2650 50  0001 C CNN
	1    3200 2650
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_DIP_x01 Shifter
U 1 1 602EB04E
P 3200 4000
F 0 "Shifter" H 3200 3733 50  0000 C CNN
F 1 "SW_Reverse" H 3200 3824 50  0000 C CNN
F 2 "" H 3200 4000 50  0001 C CNN
F 3 "~" H 3200 4000 50  0001 C CNN
	1    3200 4000
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_DIP_x01 Handbrake
U 1 1 602EBA8E
P 4000 4000
F 0 "Handbrake" H 4000 4267 50  0001 C CNN
F 1 "SW_Handbrake" H 4000 4175 50  0000 C CNN
F 2 "" H 4000 4000 50  0001 C CNN
F 3 "~" H 4000 4000 50  0001 C CNN
	1    4000 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3100 7000 3500
Wire Wire Line
	7000 3500 6800 3500
Wire Wire Line
	5550 4400 5550 4200
Wire Wire Line
	5550 4200 6000 4200
Wire Wire Line
	7000 4200 7000 3500
Connection ~ 7000 3500
Wire Wire Line
	6000 4400 6000 4200
Connection ~ 6000 4200
Wire Wire Line
	6000 4200 6450 4200
Wire Wire Line
	6450 4400 6450 4200
Connection ~ 6450 4200
Wire Wire Line
	6450 4200 7000 4200
Wire Wire Line
	7000 3100 7350 3100
Wire Wire Line
	7250 2050 7350 2050
Wire Wire Line
	7350 2050 7350 2300
Connection ~ 7350 3100
Wire Wire Line
	6300 2800 6300 2500
Wire Wire Line
	6300 2150 6750 2150
Wire Wire Line
	6400 2800 6400 2300
Wire Wire Line
	6400 2050 6750 2050
$Comp
L test:Rotary_encoder E??
U 1 1 602F2191
P 7000 1900
F 0 "E??" H 7000 2015 50  0001 C CNN
F 1 "Rotary_encoder" H 7000 1923 50  0000 C CNN
F 2 "" H 7000 1900 50  0001 C CNN
F 3 "" H 7000 1900 50  0001 C CNN
	1    7000 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 602F7EAD
P 6700 2500
F 0 "R?" V 6493 2500 50  0001 C CNN
F 1 "1K" V 6585 2500 50  0000 C CNN
F 2 "1K" V 6630 2500 39  0001 C CNN
F 3 "~" H 6700 2500 50  0001 C CNN
	1    6700 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R
U 1 1 602F6EBD
P 6700 2300
F 0 "R" V 6493 2300 50  0001 C CNN
F 1 "1K" V 6600 2300 50  0000 C CNN
F 2 "" V 6630 2300 50  0001 C CNN
F 3 "~" H 6700 2300 50  0001 C CNN
	1    6700 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 2300 6400 2300
Connection ~ 6400 2300
Wire Wire Line
	6400 2300 6400 2050
Wire Wire Line
	6850 2300 7350 2300
Connection ~ 7350 2300
Wire Wire Line
	7350 2300 7350 2500
Wire Wire Line
	6850 2500 7350 2500
Connection ~ 7350 2500
Wire Wire Line
	7350 2500 7350 3100
Wire Wire Line
	6550 2500 6300 2500
Connection ~ 6300 2500
Wire Wire Line
	6300 2500 6300 2150
Wire Wire Line
	7750 3000 7650 3000
Wire Wire Line
	7650 3000 7650 4300
Wire Wire Line
	7650 4300 6550 4300
Wire Wire Line
	5650 4400 5650 4300
Connection ~ 5650 4300
Wire Wire Line
	5650 4300 4700 4300
Wire Wire Line
	6100 4400 6100 4300
Connection ~ 6100 4300
Wire Wire Line
	6100 4300 5650 4300
Wire Wire Line
	6550 4400 6550 4300
Connection ~ 6550 4300
Wire Wire Line
	6550 4300 6100 4300
Wire Wire Line
	4600 4300 4600 3400
Wire Wire Line
	4600 3400 4700 3400
$Comp
L Switch:SW_DIP_x01 Paddle
U 1 1 60314E32
P 3200 4700
F 0 "Paddle" H 3200 4433 50  0000 C CNN
F 1 "SW_Gear_up" H 3200 4524 50  0000 C CNN
F 2 "" H 3200 4700 50  0001 C CNN
F 3 "~" H 3200 4700 50  0001 C CNN
	1    3200 4700
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_DIP_x01 Paddle
U 1 1 60315A9B
P 4000 4700
F 0 "Paddle" H 4000 4967 50  0000 C CNN
F 1 "SW_Gear_Down" H 4000 4876 50  0000 C CNN
F 2 "" H 4000 4700 50  0001 C CNN
F 3 "~" H 4000 4700 50  0001 C CNN
	1    4000 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2650 3600 3100
Wire Wire Line
	3500 2650 3600 2650
Wire Wire Line
	3700 2650 3600 2650
Connection ~ 3600 2650
Wire Wire Line
	3700 3100 3600 3100
Connection ~ 3600 3100
Wire Wire Line
	3600 3100 3600 3550
Wire Wire Line
	3500 3100 3600 3100
Connection ~ 3600 3550
Wire Wire Line
	3600 3550 3600 4000
Wire Wire Line
	3600 3550 3700 3550
Wire Wire Line
	3500 3550 3600 3550
Wire Wire Line
	3500 4000 3600 4000
Connection ~ 3600 4000
Wire Wire Line
	3600 4000 3600 4350
Wire Wire Line
	3700 4000 3600 4000
Wire Wire Line
	4550 4350 4550 3300
Wire Wire Line
	4550 3300 4700 3300
Wire Wire Line
	3600 4350 4550 4350
Wire Wire Line
	3600 4700 3600 4950
Wire Wire Line
	3600 4950 4700 4950
Wire Wire Line
	4700 4950 4700 4300
Connection ~ 4700 4300
Wire Wire Line
	4700 4300 4600 4300
Wire Wire Line
	2900 5100 4950 5100
Wire Wire Line
	4950 5100 4950 4100
Wire Wire Line
	4950 4100 5400 4100
Wire Wire Line
	5400 4100 5400 3800
Wire Wire Line
	4300 4700 4850 4700
Wire Wire Line
	4850 4700 4850 4000
Wire Wire Line
	4850 4000 5300 4000
Wire Wire Line
	5300 4000 5300 3800
Wire Wire Line
	3600 4700 3700 4700
Wire Wire Line
	3500 4700 3600 4700
Connection ~ 3600 4700
Wire Wire Line
	2900 4700 2900 5100
Wire Wire Line
	4300 4000 4450 4000
Wire Wire Line
	4450 4000 4450 2700
Wire Wire Line
	4450 2700 5100 2700
Wire Wire Line
	5100 2700 5100 2800
Wire Wire Line
	4300 3550 4400 3550
Wire Wire Line
	4400 3550 4400 2650
Wire Wire Line
	4400 2650 5200 2650
Wire Wire Line
	5200 2650 5200 2800
Wire Wire Line
	4300 2650 4300 2550
Wire Wire Line
	7100 3700 7100 2750
Wire Wire Line
	7100 2750 5400 2750
Wire Wire Line
	5400 2750 5400 2800
Wire Wire Line
	7100 3700 7750 3700
Wire Wire Line
	7750 3600 7150 3600
Wire Wire Line
	7150 3600 7150 2700
Wire Wire Line
	7150 2700 5300 2700
Wire Wire Line
	5300 2700 5300 2800
Wire Wire Line
	7350 3100 7550 3100
Wire Wire Line
	7750 3500 7600 3500
Wire Wire Line
	7750 3400 7600 3400
Wire Wire Line
	7600 3400 7600 3450
Wire Wire Line
	7600 3450 7550 3450
Wire Wire Line
	7550 3450 7550 3100
Connection ~ 7600 3450
Wire Wire Line
	7600 3450 7600 3500
Connection ~ 7550 3100
Wire Wire Line
	7550 3100 7750 3100
$Comp
L Switch:SW_DIP_x01 SW?
U 1 1 6036EF14
P 5800 2000
F 0 "SW?" H 5800 2267 50  0001 C CNN
F 1 "Switch/Z phaze" H 5800 2175 50  0000 C CNN
F 2 "" H 5800 2000 50  0001 C CNN
F 3 "~" H 5800 2000 50  0001 C CNN
	1    5800 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3200 4600 3200
Wire Wire Line
	4600 1750 5400 1750
Wire Wire Line
	7500 1750 7500 2150
Wire Wire Line
	7500 2150 7250 2150
Wire Wire Line
	4300 3100 4350 3100
Wire Wire Line
	4350 3100 4350 2600
Wire Wire Line
	4350 2600 5500 2600
Wire Wire Line
	5500 2600 5500 2800
Wire Wire Line
	4300 2550 5600 2550
Wire Wire Line
	5600 2550 5600 2800
Wire Wire Line
	2900 2650 2800 2650
Wire Wire Line
	2800 2650 2800 2300
Wire Wire Line
	2800 2300 5700 2300
Wire Wire Line
	5700 2300 5700 2800
Wire Wire Line
	2900 3100 2750 3100
Wire Wire Line
	2750 3100 2750 2250
Wire Wire Line
	2750 2250 5800 2250
Wire Wire Line
	2900 3550 2700 3550
Wire Wire Line
	2700 3550 2700 2200
Wire Wire Line
	2700 2200 5900 2200
Wire Wire Line
	5800 2800 5800 2250
Wire Wire Line
	5900 2800 5900 2200
Wire Wire Line
	2900 4000 2650 4000
Wire Wire Line
	2650 4000 2650 2150
Wire Wire Line
	2650 2150 6000 2150
Wire Wire Line
	6000 2150 6000 2800
Wire Wire Line
	6100 2000 6100 2800
Wire Wire Line
	4600 1750 4600 3200
Wire Wire Line
	5500 2000 5400 2000
Wire Wire Line
	5400 2000 5400 1750
Connection ~ 5400 1750
Wire Wire Line
	5400 1750 7500 1750
Text Notes 7050 4700 0    50   ~ 0
Микроконтролера е свързан към компютър, посредством micro USB порта. \nОт там идват 5v, нужни за захранването на ел. компонентите.
Wire Wire Line
	8700 3200 8950 3200
Wire Wire Line
	8700 3100 8950 3100
$Comp
L Connector:Screw_Terminal_01x02 12V_PSU
U 1 1 602F112B
P 9150 3100
F 0 "12V_PSU" H 9230 3092 50  0000 L CNN
F 1 "Screw_Terminal" H 9230 3001 50  0000 L CNN
F 2 "" H 9150 3100 50  0001 C CNN
F 3 "~" H 9150 3100 50  0001 C CNN
	1    9150 3100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
