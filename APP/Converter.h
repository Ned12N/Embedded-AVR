
#ifndef CONVERTER_H_
#define CONVERTER_H_
#include "StdTypes.h"
#include "LCD.h"

/******************** Declrations *********************/
void DecimalToHex(void);
void DecimalToBinary(void);
void CLEAR_Decimal(void);
void Decimal_Operation(void);

void BinaryToHex(void);
void BinaryToDecimal(void);
void CLEAR_Binary(void);
void Binary_Operation(void);

void HexToBinary(void);
void HexToDecimal(void);
void CLEAR_Hex(void);
void Hex_Operation(void);
/******************** Globals *********************/
#define DECIMAL   '1'
#define HEXA      '2'
#define BINARY    '3'
#define NO_KEY    'T'
#define DELAY_ERROR 2000
#define MENU_DELAY 600

#define ERROR() LCD_Clear();\
				LCD_GoTo_WriteString(0,0,"Error Number");\
				LCD_GoTo_WriteString(1,0,"Number isn't 1-Byte");\
				_delay_ms(DELAY_ERROR)\

extern u8 Enter_flag;
extern u8 k ;

#endif /* CONVERTER_H_ */