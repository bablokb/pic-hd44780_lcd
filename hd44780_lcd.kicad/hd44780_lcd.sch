EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PIC12F675 with HD44780 LCD"
Date "2020-03-21"
Rev "3"
Comp "Bernhard Bablok"
Comment1 "https://github.com/bablokb/pic-toolchain/src/hd44780_lcd"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_PIC12:PIC12F675-IP U1
U 1 1 5E74E87F
P 2800 2950
F 0 "U1" H 2800 2169 50  0000 C CNN
F 1 "PIC12F675-IP" H 2800 2260 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 3400 3600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/41190G.pdf" H 2800 2950 50  0001 C CNN
	1    2800 2950
	-1   0    0    1   
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 5E74F99F
P 4450 3150
F 0 "U2" H 4450 3931 50  0000 C CNN
F 1 "74HC595" H 4450 3840 50  0000 C CNN
F 2 "" H 4450 3150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4450 3150 50  0001 C CNN
	1    4450 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2950 3900 2950
Wire Wire Line
	3400 2850 3400 2750
Wire Wire Line
	3400 2750 4050 2750
Wire Wire Line
	4050 3250 3900 3250
Wire Wire Line
	3900 3250 3900 2950
Connection ~ 3900 2950
Wire Wire Line
	3900 2950 4050 2950
NoConn ~ 4850 3450
NoConn ~ 4850 3650
NoConn ~ 2200 3050
NoConn ~ 2200 2950
NoConn ~ 2200 2850
$Comp
L power:+5V #PWR02
U 1 1 5E75C959
P 2800 4750
F 0 "#PWR02" H 2800 4600 50  0001 C CNN
F 1 "+5V" H 2815 4923 50  0000 C CNN
F 2 "" H 2800 4750 50  0001 C CNN
F 3 "" H 2800 4750 50  0001 C CNN
	1    2800 4750
	-1   0    0    1   
$EndComp
Wire Wire Line
	2800 3550 2800 4050
Connection ~ 2800 4050
$Comp
L power:GND #PWR05
U 1 1 5E75FCDB
P 5700 5100
F 0 "#PWR05" H 5700 4850 50  0001 C CNN
F 1 "GND" H 5705 4927 50  0000 C CNN
F 2 "" H 5700 5100 50  0001 C CNN
F 3 "" H 5700 5100 50  0001 C CNN
	1    5700 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E761A03
P 2100 2350
F 0 "#PWR01" H 2100 2100 50  0001 C CNN
F 1 "GND" H 2105 2177 50  0000 C CNN
F 2 "" H 2100 2350 50  0001 C CNN
F 3 "" H 2100 2350 50  0001 C CNN
	1    2100 2350
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5E762FBF
P 2400 1900
F 0 "#FLG02" H 2400 1975 50  0001 C CNN
F 1 "PWR_FLAG" H 2400 2073 50  0000 C CNN
F 2 "" H 2400 1900 50  0001 C CNN
F 3 "~" H 2400 1900 50  0001 C CNN
	1    2400 1900
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5E7638B3
P 2350 4050
F 0 "#FLG01" H 2350 4125 50  0001 C CNN
F 1 "PWR_FLAG" H 2350 4223 50  0000 C CNN
F 2 "" H 2350 4050 50  0001 C CNN
F 3 "~" H 2350 4050 50  0001 C CNN
	1    2350 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 1900 2400 2350
Wire Wire Line
	2100 2350 2400 2350
Connection ~ 2400 2350
Wire Wire Line
	2400 2350 2800 2350
Wire Wire Line
	2350 4050 2800 4050
NoConn ~ 4850 2750
NoConn ~ 4850 2850
$Comp
L power:+5V #PWR04
U 1 1 5E76D739
P 5100 2250
F 0 "#PWR04" H 5100 2100 50  0001 C CNN
F 1 "+5V" H 5115 2423 50  0000 C CNN
F 2 "" H 5100 2250 50  0001 C CNN
F 3 "" H 5100 2250 50  0001 C CNN
	1    5100 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2550 5100 2550
Wire Wire Line
	5100 2550 5100 2250
Wire Wire Line
	2800 4050 3600 4050
$Comp
L power:GND #PWR03
U 1 1 5E7705B3
P 3900 3600
F 0 "#PWR03" H 3900 3350 50  0001 C CNN
F 1 "GND" V 3905 3472 50  0000 R CNN
F 2 "" H 3900 3600 50  0001 C CNN
F 3 "" H 3900 3600 50  0001 C CNN
	1    3900 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 3350 3900 3350
Wire Wire Line
	3900 3350 3900 3600
Wire Wire Line
	4050 3050 3600 3050
Wire Wire Line
	3600 3050 3600 4050
$Comp
L Display_Character:WC1602A DS1
U 1 1 5E75E076
P 4900 4500
F 0 "DS1" V 4854 3656 50  0000 R CNN
F 1 "WC1602A" V 4945 3656 50  0000 R CNN
F 2 "Display:WC1602A" H 4900 3600 50  0001 C CIN
F 3 "http://www.wincomlcd.com/pdf/WC1602A-SFYLYHTC06.pdf" H 5600 4500 50  0001 C CNN
	1    4900 4500
	0    -1   1    0   
$EndComp
Wire Wire Line
	2800 4050 2800 4500
Connection ~ 2800 4500
Wire Wire Line
	2800 4500 2800 4750
Wire Wire Line
	3400 3050 3400 3950
Wire Wire Line
	3400 3950 4300 3950
Wire Wire Line
	4300 3950 4300 4100
Wire Wire Line
	4450 3850 4400 3850
Wire Wire Line
	3900 3850 3900 3600
Connection ~ 3900 3600
Wire Wire Line
	4850 3350 5200 3350
Wire Wire Line
	5200 3350 5200 4100
Wire Wire Line
	4850 3250 5300 3250
Wire Wire Line
	5300 3250 5300 4100
Wire Wire Line
	4850 3150 5400 3150
Wire Wire Line
	5400 3150 5400 4100
Wire Wire Line
	4850 3050 5500 3050
Wire Wire Line
	5500 3050 5500 4100
Wire Wire Line
	4850 2950 5050 2950
Wire Wire Line
	5050 2950 5050 3950
Wire Wire Line
	5050 3950 4500 3950
Wire Wire Line
	4500 3950 4500 4100
NoConn ~ 5100 4100
NoConn ~ 5000 4100
NoConn ~ 4900 4100
NoConn ~ 4800 4100
NoConn ~ 4700 4900
NoConn ~ 4600 4900
Wire Wire Line
	4400 4100 4400 3850
Connection ~ 4400 3850
Wire Wire Line
	4400 3850 3900 3850
Wire Wire Line
	2800 4500 4100 4500
Wire Wire Line
	5700 4500 5700 5050
Wire Wire Line
	4300 5050 5700 5050
Wire Wire Line
	4300 4900 4300 5050
Connection ~ 5700 5050
Wire Wire Line
	5700 5050 5700 5100
$EndSCHEMATC
