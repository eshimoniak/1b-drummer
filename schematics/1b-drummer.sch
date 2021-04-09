EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "1-Bit Drum Machine"
Date "2021-04-04"
Rev "1.0.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Author: Evan Shimoniak"
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U2
U 1 1 606B8577
P 6050 4000
F 0 "U2" H 5406 4046 50  0000 R CNN
F 1 "ATmega328P-PU" H 5406 3955 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6050 4000 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 6050 4000 50  0001 C CNN
	1    6050 4000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR07
U 1 1 606B935F
P 6050 2300
F 0 "#PWR07" H 6050 2150 50  0001 C CNN
F 1 "+3V3" H 6065 2473 50  0000 C CNN
F 2 "" H 6050 2300 50  0001 C CNN
F 3 "" H 6050 2300 50  0001 C CNN
	1    6050 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2300 6050 2400
Wire Wire Line
	6150 2500 6150 2400
Wire Wire Line
	6150 2400 6050 2400
Connection ~ 6050 2400
Wire Wire Line
	6050 2400 6050 2500
$Comp
L power:GND #PWR08
U 1 1 606BAB67
P 6050 5600
F 0 "#PWR08" H 6050 5350 50  0001 C CNN
F 1 "GND" H 6055 5427 50  0000 C CNN
F 2 "" H 6050 5600 50  0001 C CNN
F 3 "" H 6050 5600 50  0001 C CNN
	1    6050 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 5600 6050 5500
$Comp
L power:+3V3 #PWR09
U 1 1 606BC039
P 6750 4300
F 0 "#PWR09" H 6750 4150 50  0001 C CNN
F 1 "+3V3" H 6765 4473 50  0000 C CNN
F 2 "" H 6750 4300 50  0001 C CNN
F 3 "" H 6750 4300 50  0001 C CNN
	1    6750 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4300 6750 4300
$Comp
L Device:Speaker LS1
U 1 1 606BEBA7
P 8300 3050
F 0 "LS1" H 8470 3046 50  0000 L CNN
F 1 "Speaker" H 8470 2955 50  0000 L CNN
F 2 "" H 8300 2850 50  0001 C CNN
F 3 "~" H 8290 3000 50  0001 C CNN
	1    8300 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 606BFF90
P 8000 3250
F 0 "#PWR012" H 8000 3000 50  0001 C CNN
F 1 "GND" H 8005 3077 50  0000 C CNN
F 2 "" H 8000 3250 50  0001 C CNN
F 3 "" H 8000 3250 50  0001 C CNN
	1    8000 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 3250 8000 3150
Wire Wire Line
	8000 3150 8100 3150
$Comp
L Transistor_BJT:PN2222A Q1
U 1 1 606C0874
P 7800 2950
F 0 "Q1" V 8035 2950 50  0000 C CNN
F 1 "PN2222A" V 8126 2950 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8000 2875 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/PN/PN2222A.pdf" H 7800 2950 50  0001 L CNN
	1    7800 2950
	0    -1   1    0   
$EndComp
Wire Wire Line
	8000 3050 8100 3050
$Comp
L power:+3V3 #PWR010
U 1 1 606C27A5
P 7500 2950
F 0 "#PWR010" H 7500 2800 50  0001 C CNN
F 1 "+3V3" H 7515 3123 50  0000 C CNN
F 2 "" H 7500 2950 50  0001 C CNN
F 3 "" H 7500 2950 50  0001 C CNN
	1    7500 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2950 7500 3050
Wire Wire Line
	7500 3050 7600 3050
Text Label 7800 2650 0    50   ~ 0
AUDIO
Wire Wire Line
	7800 2650 7800 2750
Text Label 6750 2800 0    50   ~ 0
AUDIO
Wire Wire Line
	6650 2800 6750 2800
Text Label 6750 3700 0    50   ~ 0
BTN_KICK
Text Label 6750 3800 0    50   ~ 0
BTN_SNARE
Text Label 6750 3900 0    50   ~ 0
BTN_HI_HAT
Text Label 6750 4600 0    50   ~ 0
BTN_PLAY
Text Label 6750 4500 0    50   ~ 0
BTN_RECORD
Wire Wire Line
	6650 3700 6750 3700
Wire Wire Line
	6650 3800 6750 3800
Wire Wire Line
	6650 3900 6750 3900
Wire Wire Line
	6650 4500 6750 4500
Wire Wire Line
	6650 4600 6750 4600
Text Label 6750 5100 0    50   ~ 0
LED_RECORD
Text Label 6750 5200 0    50   ~ 0
LED_PLAY
Wire Wire Line
	6650 5100 6750 5100
Wire Wire Line
	6750 5200 6650 5200
$Comp
L power:+3V3 #PWR06
U 1 1 606CEB28
P 5350 2700
F 0 "#PWR06" H 5350 2550 50  0001 C CNN
F 1 "+3V3" H 5365 2873 50  0000 C CNN
F 2 "" H 5350 2700 50  0001 C CNN
F 3 "" H 5350 2700 50  0001 C CNN
	1    5350 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2800 5450 2800
Wire Wire Line
	5350 2700 5350 2800
NoConn ~ 6650 5000
NoConn ~ 6650 4900
NoConn ~ 6650 4800
NoConn ~ 6650 4700
NoConn ~ 6650 4100
NoConn ~ 6650 4200
NoConn ~ 6650 4000
NoConn ~ 6650 3500
NoConn ~ 6650 3400
NoConn ~ 6650 3300
NoConn ~ 6650 3200
NoConn ~ 6650 3100
NoConn ~ 6650 3000
NoConn ~ 6650 2900
$Comp
L misc-custom:LD1117V33 U1
U 1 1 606D6ED9
P 2950 3200
F 0 "U1" H 3008 3915 50  0000 C CNN
F 1 "LD1117V33" H 3008 3824 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2950 3200 50  0001 C CNN
F 3 "" H 2950 3200 50  0001 C CNN
	1    2950 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR02
U 1 1 606D8C60
P 4150 2500
F 0 "#PWR02" H 4150 2350 50  0001 C CNN
F 1 "+3V3" H 4165 2673 50  0000 C CNN
F 2 "" H 4150 2500 50  0001 C CNN
F 3 "" H 4150 2500 50  0001 C CNN
	1    4150 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3200 4850 3100
Wire Wire Line
	3300 3100 3550 3100
Connection ~ 4850 3100
Wire Wire Line
	4850 3100 4850 3000
Wire Wire Line
	3300 3000 3950 3000
$Comp
L Device:C C1
U 1 1 606E444B
P 3550 2750
F 0 "C1" H 3665 2796 50  0000 L CNN
F 1 "100nF" H 3665 2705 50  0000 L CNN
F 2 "" H 3588 2600 50  0001 C CNN
F 3 "~" H 3550 2750 50  0001 C CNN
	1    3550 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 606E4974
P 4150 2850
F 0 "C2" H 4268 2896 50  0000 L CNN
F 1 "10uF" H 4268 2805 50  0000 L CNN
F 2 "" H 4188 2700 50  0001 C CNN
F 3 "~" H 4150 2850 50  0001 C CNN
	1    4150 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 606DC80A
P 4850 3200
F 0 "#PWR04" H 4850 2950 50  0001 C CNN
F 1 "GND" H 4855 3027 50  0000 C CNN
F 2 "" H 4850 3200 50  0001 C CNN
F 3 "" H 4850 3200 50  0001 C CNN
	1    4850 3200
	1    0    0    -1  
$EndComp
$Comp
L power:-BATT #PWR03
U 1 1 606D9709
P 4850 3000
F 0 "#PWR03" H 4850 2850 50  0001 C CNN
F 1 "-BATT" H 4865 3173 50  0000 C CNN
F 2 "" H 4850 3000 50  0001 C CNN
F 3 "" H 4850 3000 50  0001 C CNN
	1    4850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3000 4150 3100
Connection ~ 4150 3100
Wire Wire Line
	4150 3100 4700 3100
Wire Wire Line
	4150 2500 4150 2600
Wire Wire Line
	4150 2600 3950 2600
Wire Wire Line
	3950 2600 3950 3000
Wire Wire Line
	4150 2700 4150 2600
Connection ~ 4150 2600
Wire Wire Line
	3550 2900 3550 3100
Connection ~ 3550 3100
Wire Wire Line
	3550 3100 4150 3100
Wire Wire Line
	3550 2500 3400 2500
Wire Wire Line
	3400 2500 3400 2900
Wire Wire Line
	3300 2900 3400 2900
Wire Wire Line
	3550 2500 3550 2600
$Comp
L Switch:SW_SPST SW2
U 1 1 607179E5
P 4150 3800
F 0 "SW2" H 4150 4035 50  0000 C CNN
F 1 "SW_SPST" H 4150 3944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 4150 3800 50  0001 C CNN
F 3 "~" H 4150 3800 50  0001 C CNN
	1    4150 3800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 60718D51
P 4150 4200
F 0 "SW3" H 4150 4435 50  0000 C CNN
F 1 "SW_SPST" H 4150 4344 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 4150 4200 50  0001 C CNN
F 3 "~" H 4150 4200 50  0001 C CNN
	1    4150 4200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW4
U 1 1 6071A5B5
P 4150 4600
F 0 "SW4" H 4150 4835 50  0000 C CNN
F 1 "SW_SPST" H 4150 4744 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 4150 4600 50  0001 C CNN
F 3 "~" H 4150 4600 50  0001 C CNN
	1    4150 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW5
U 1 1 6071A5BB
P 4150 5000
F 0 "SW5" H 4150 5235 50  0000 C CNN
F 1 "SW_SPST" H 4150 5144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 4150 5000 50  0001 C CNN
F 3 "~" H 4150 5000 50  0001 C CNN
	1    4150 5000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW6
U 1 1 6071E035
P 4150 5400
F 0 "SW6" H 4150 5635 50  0000 C CNN
F 1 "SW_SPST" H 4150 5544 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 4150 5400 50  0001 C CNN
F 3 "~" H 4150 5400 50  0001 C CNN
	1    4150 5400
	1    0    0    -1  
$EndComp
Text Label 3850 5000 2    50   ~ 0
BTN_RECORD
Text Label 3850 5400 2    50   ~ 0
BTN_PLAY
Text Label 3850 4600 2    50   ~ 0
BTN_HI_HAT
Text Label 3850 4200 2    50   ~ 0
BTN_SNARE
Text Label 3850 3800 2    50   ~ 0
BTN_KICK
Wire Wire Line
	3950 5400 3850 5400
Wire Wire Line
	3850 5000 3950 5000
Wire Wire Line
	3850 3800 3950 3800
Wire Wire Line
	3850 4200 3950 4200
Wire Wire Line
	3850 4600 3950 4600
Wire Wire Line
	4350 5400 4450 5400
Wire Wire Line
	4450 5400 4450 5000
Wire Wire Line
	4450 5000 4350 5000
Wire Wire Line
	4450 5000 4450 4600
Wire Wire Line
	4450 4600 4350 4600
Connection ~ 4450 5000
Wire Wire Line
	4450 4600 4450 4200
Wire Wire Line
	4450 4200 4350 4200
Connection ~ 4450 4600
Wire Wire Line
	4450 4200 4450 3800
Wire Wire Line
	4450 3800 4350 3800
Connection ~ 4450 4200
$Comp
L power:GND #PWR05
U 1 1 6074731D
P 4450 5500
F 0 "#PWR05" H 4450 5250 50  0001 C CNN
F 1 "GND" H 4455 5327 50  0000 C CNN
F 2 "" H 4450 5500 50  0001 C CNN
F 3 "" H 4450 5500 50  0001 C CNN
	1    4450 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 5500 4450 5400
Connection ~ 4450 5400
$Comp
L Switch:SW_SPST SW1
U 1 1 60750E7C
P 3550 2200
F 0 "SW1" V 3504 2298 50  0000 L CNN
F 1 "SW_SPST" V 3595 2298 50  0000 L CNN
F 2 "" H 3550 2200 50  0001 C CNN
F 3 "~" H 3550 2200 50  0001 C CNN
	1    3550 2200
	0    1    1    0   
$EndComp
$Comp
L power:+BATT #PWR01
U 1 1 60752DB2
P 3550 1900
F 0 "#PWR01" H 3550 1750 50  0001 C CNN
F 1 "+BATT" H 3565 2073 50  0000 C CNN
F 2 "" H 3550 1900 50  0001 C CNN
F 3 "" H 3550 1900 50  0001 C CNN
	1    3550 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1900 3550 2000
Connection ~ 3550 2500
Wire Wire Line
	3550 2400 3550 2500
$Comp
L Device:LED D1
U 1 1 6075CEF9
P 4450 2600
F 0 "D1" H 4443 2345 50  0000 C CNN
F 1 "GREEN" H 4443 2436 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 4450 2600 50  0001 C CNN
F 3 "~" H 4450 2600 50  0001 C CNN
	1    4450 2600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 2600 4700 2600
Wire Wire Line
	4700 2600 4700 3100
Connection ~ 4700 3100
Wire Wire Line
	4700 3100 4850 3100
Wire Wire Line
	4150 2600 4300 2600
$Comp
L Device:LED D2
U 1 1 607748D6
P 7650 4850
F 0 "D2" V 7689 4732 50  0000 R CNN
F 1 "RED" V 7598 4732 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 7650 4850 50  0001 C CNN
F 3 "~" H 7650 4850 50  0001 C CNN
	1    7650 4850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7650 4600 7650 4700
$Comp
L power:GND #PWR011
U 1 1 6077BEEB
P 7650 5100
F 0 "#PWR011" H 7650 4850 50  0001 C CNN
F 1 "GND" H 7655 4927 50  0000 C CNN
F 2 "" H 7650 5100 50  0001 C CNN
F 3 "" H 7650 5100 50  0001 C CNN
	1    7650 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5100 7650 5000
$Comp
L Device:LED D3
U 1 1 6078EB3B
P 8000 4850
F 0 "D3" V 8039 4733 50  0000 R CNN
F 1 "BLUE" V 7948 4733 50  0000 R CNN
F 2 "LED_THT:LED_D3.0mm" H 8000 4850 50  0001 C CNN
F 3 "~" H 8000 4850 50  0001 C CNN
	1    8000 4850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8000 4600 8000 4700
Wire Wire Line
	8000 5100 8000 5000
$Comp
L power:GND #PWR013
U 1 1 60792F21
P 8000 5100
F 0 "#PWR013" H 8000 4850 50  0001 C CNN
F 1 "GND" H 8005 4927 50  0000 C CNN
F 2 "" H 8000 5100 50  0001 C CNN
F 3 "" H 8000 5100 50  0001 C CNN
	1    8000 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 60794436
P 7650 4450
F 0 "R1" H 7718 4496 50  0000 L CNN
F 1 "22R" H 7718 4405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7690 4440 50  0001 C CNN
F 3 "~" H 7650 4450 50  0001 C CNN
	1    7650 4450
	1    0    0    -1  
$EndComp
Text Label 7750 4200 0    50   ~ 0
LED_RECORD
Text Label 8100 4600 0    50   ~ 0
LED_PLAY
Wire Wire Line
	7650 4200 7750 4200
Wire Wire Line
	8100 4600 8000 4600
Wire Wire Line
	7650 4200 7650 4300
$EndSCHEMATC
