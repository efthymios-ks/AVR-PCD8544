#ifndef PCD8544_SETTINGS_H_INCLUDED
#define PCD8544_SETTINGS_H_INCLUDED
/*
||
||  Filename:	 		PCD8544_Settings.h
||  Title: 			    PCD8544 Driver Settings
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:
||	Settings for the PCD8544 (Nokia 5110) driver. 
||
*/

//----- Configuration -------------//
//GLCD pins			PORT, PIN
#define GLCD_SCE	A, 0
#define GLCD_RST	A, 1
#define GLCD_DC		A, 2
#define GLCD_DIN	A, 3
#define GLCD_SCLK	A, 4
//---------------------------------//
#endif