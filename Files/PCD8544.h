#ifndef PCD8544_H_INCLUDED
#define PCD8544_H_INCLUDED
/*
||
||  Filename:	 		PCD8544.h
||  Title: 			    PCD8544 Driver
||  Author: 			Efthymios Koktsidis
||	Email:				efthymios.ks@gmail.com
||  Compiler:		 	AVR-GCC
||	Description:
||	This library can drive KS0108 based GLCD.
||
*/

//----- Headers ------------//
#include <inttypes.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "IO_Macros.h"
#include "PCD8544_Settings.h"
//--------------------------//

//----- Auxiliary data ---------------------------//
#define __GLCD_Pulse_SCLK						1

//Basic or Extended Instruction Set (H=0 or 1)
#define __GLCD_Command_NOP						0x00
#define __GLCD_Command_Function_Set				0x20
//Basic Instruction Set (H=0)
#define __GLCD_Command_Display_Control			0x08
#define __GLCD_Command_Set_Y_Address			0x40
#define __GLCD_Command_Set_X_Address			0x80
//Extended Instruction Set (H=1)
#define __GLCD_Command_Temperature_Control		0x04
#define __GLCD_Command_Bias_System				0x10
#define __GLCD_Command_Set_Top					0x80

//Basic or Extended Instruction Set (H=0 or 1)
#define __GLCD_Command_On						0x00
#define __GLCD_Command_Chip_Off					0x04

#define __GLCD_Command_Horizontal_Addressing	0x00
#define __GLCD_Command_Vertical_Addressing		0x02

#define __GLCD_Command_Basic_Instruction_Set	0x00
#define __GLCD_Command_Extented_Instruction_Set	0x01

//Basic Instruction Set (H=0)
#define __GLCD_Command_Display_Blank			0x00
#define __GLCD_Command_Normal_Mode				0x04
#define __GLCD_Command_All_Display_Segments_On	0x01
#define __GLCD_Command_Inverse_Video_Mode		0x05

//Extended Instruction Set (H=1)
#define __GLCD_Command_VLCD_Temperature_Coefficient_0	0x00
#define __GLCD_Command_VLCD_Temperature_Coefficient_1	0x01
#define __GLCD_Command_VLCD_Temperature_Coefficient_2	0x02
#define __GLCD_Command_VLCD_Temperature_Coefficient_3	0x03

#define __GLCD_Command_MUX_Rate_1_100			0x00
#define __GLCD_Command_MUX_Rate_1_80			0x01
#define __GLCD_Command_MUX_Rate_1_65			0x02
#define __GLCD_Command_MUX_Rate_1_48			0x03
#define __GLCD_Command_MUX_Rate_1_40_34			0x04
#define __GLCD_Command_MUX_Rate_1_24			0x05
#define __GLCD_Command_MUX_Rate_1_18_16			0x06
#define __GLCD_Command_MUX_Rate_1_10_9_8		0x07

#define __GLCD_Screen_Width          			84
#define __GLCD_Screen_Height         			48
#define	__GLCD_Screen_Line_Height				8
#define __GLCD_Screen_Lines						(__GLCD_Screen_Height/__GLCD_Screen_Line_Height)

enum OperatingMode_t
{
	GLCD_Inverted,
	GLCD_Non_Inverted
};
enum PrintMode_t
{
	GLCD_Overwrite,
	GLCD_Merge
};
enum Color_t
{
	GLCD_White = 0x00,
	GLCD_Black = 0xFF
};

typedef struct
{
	uint8_t *Name;
	uint8_t Width;
	uint8_t Height;
	uint8_t Lines;
	enum PrintMode_t Mode;
}Font_t;

typedef struct
{
	uint8_t X;
	uint8_t Y;
	enum OperatingMode_t Mode;
	Font_t Font;
}GLCD_t;
//------------------------------------------------//

//----- Prototypes ------------------------------------------------------------//
void GLCD_SendCommand(const uint8_t Command);
void GLCD_Data(const uint8_t Data);
void GLCD_Setup(void);
void GLCD_Render(void);
void GLCD_InvertMode(void);

void GLCD_Clear(void);
void GLCD_ClearLine(const uint8_t Line);
void GLCD_GotoX(const uint8_t X);
void GLCD_GotoY(const uint8_t Y);
void GLCD_GotoXY(const uint8_t X, const uint8_t Y);
void GLCD_GotoLine(const uint8_t line);
uint8_t GLCD_GetX(void);
uint8_t GLCD_GetY(void);
uint8_t GLCD_GetLine(void);

void GLCD_SetPixel(const uint8_t X, const uint8_t Y, enum Color_t Color);
void GLCD_SetPixels(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, enum Color_t Color);

void GLCD_DrawBitmap(const uint8_t *Bitmap, uint8_t Width, const uint8_t Height, enum PrintMode_t Mode);
void GLCD_DrawLine(const uint8_t X1, const uint8_t Y1, const uint8_t X2, const uint8_t Y2, enum Color_t Color);
void GLCD_DrawRectangle(const uint8_t X1, const uint8_t Y1, const uint8_t X2, const uint8_t Y2, enum Color_t Color);
void GLCD_DrawRoundRectangle(const uint8_t X1, const uint8_t Y1, const uint8_t X2, const uint8_t Y2, const uint8_t Radius, enum Color_t Color);
void GLCD_DrawTriangle(const uint8_t X1, const uint8_t Y1, const uint8_t X2, const uint8_t Y2, const uint8_t X3, const uint8_t Y3, enum Color_t Color);
void GLCD_DrawCircle(const uint8_t CenterX, const uint8_t CenterY, uint8_t Radius, enum Color_t Color);

void GLCD_FillScreen(enum Color_t Color);
void GLCD_FillRectangle(const uint8_t X1, const uint8_t Y1, const uint8_t X2, const uint8_t Y2, enum Color_t Color);
void GLCD_FillRoundRectangle(const uint8_t X1, const uint8_t Y1, const uint8_t X2, const uint8_t Y2, const uint8_t Radius, enum Color_t Color);
void GLCD_FillTriangle(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t X3, uint8_t Y3, enum Color_t Color);
void GLCD_FillCircle(const uint8_t CenterX, const uint8_t CenterY, const uint8_t Radius, enum Color_t Color);

void GLCD_InvertScreen(void);
void GLCD_InvertRect(uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2);

void GLCD_SetFont(const uint8_t *Name, const uint8_t Width, const uint8_t Height, enum PrintMode_t Mode);
uint8_t GLCD_GetWidthChar(const char Character);
uint16_t GLCD_GetWidthString(const char *Text);
uint16_t GLCD_GetWidthString_P(const char *Text);
void GLCD_PrintChar(char Character);
void GLCD_PrintString(const char *Text);
void GLCD_PrintString_P(const char *Text);
void GLCD_PrintInteger(const int32_t Value);
void GLCD_PrintDouble(double Value, const uint32_t Tens);
//-----------------------------------------------------------------------------//
#endif