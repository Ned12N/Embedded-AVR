#include "Converter.h"

u8 k=NO_KEY ,flag=0;
u16 num=0;
u16 num2=0;

u8 Enter_flag=0;
u8 DB_flag=0;
u16 temp=0;
u8 HB_Flag=0;


/******************** Decimal Operation *********************/
void DecimalToHex(void)
{
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"D :                    ");
	LCD_GoTo_WriteString(1,0,"H :                    ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			
			num=num*10+(k-'0');
			if (num>255)
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Error Number");
				LCD_GoTo_WriteString(1,0,"Number isn't 1-Byte");
				_delay_ms(DELAY_ERROR);
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"2-H   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
			if(k=='C')
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"2-H   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
		}
		LCD_GoTo_WriteNumber(0,4,num);
		LCD_GoTo(1,4) ;
		LCD_WriteHEX(num);
	}
	
}
void DecimalToBinary(void)
{
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"D :                    ");
	LCD_GoTo_WriteString(1,0,"B :                    ");
	while (1)
	{
		if(DB_flag==0)
		{
			num=0;
			DB_flag=1;
		}
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			num=num*10+(k-'0');
			if(k=='C')
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"2-H   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
			else
			{
				
			}
			k=NO_KEY;
		}
		LCD_GoTo_WriteNumber(0,4,num);
		LCD_GoTo(1,4) ;
		LCD_WriteBinary(num);
		
		
	}
}
void CLEAR_Decimal(void)
{
	Enter_flag=0;
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"Convert From :");
	LCD_GoTo_WriteString(1,0,"1-D   2-H   3-B");
}
void Decimal_Operation(void)
{

	LCD_GoTo_WriteString(0,0,"Convert To :     ");
	LCD_GoTo_WriteString(1,0,"2-H   3-B             ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			if(k==HEXA) // if you want to Convert from Deci to Hexa
			{
				DecimalToHex();
				
			}
			if(k==BINARY) // Convert from Deci to Binary
			{
				DecimalToBinary();
			}
			if(k=='C') // reset
			{
				CLEAR_Decimal();
				break;
			}
		}
	}
}
/********************                  *********************/
/******************** Binary Operation *********************/
void BinaryToHex(void)
{
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"B :                    ");
	LCD_GoTo_WriteString(1,0,"H :                    ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			if(k=='1')
			{
				num=num*10+(k-'0');
			}
			if (k=='0')
			{
				num=num*10;
			}
			if(k=='C')
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"1-B   2-H             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
		}
		LCD_GoTo_WriteNumber(0,4,num);
		LCD_GoTo(1,4) ;
		LCD_WriteBinaryToHex(num);
	}
	
}
void BinaryToDecimal(void)
{
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"B :                    ");
	LCD_GoTo_WriteString(1,0,"D :                    ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			if(k=='1')
			{
				num=num*10+(k-'0');
			}
			if (k=='0')
			{
				num=num*10;
			}
			if(k=='C')
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"1-D   2-H             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
		}
		LCD_GoTo_WriteNumber(0,4,num);
		LCD_GoTo(1,4) ;
		LCD_WriteBinaryToDecimal(num);
		
		
	}
}
void CLEAR_Binary(void)
{
	Enter_flag=0;
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"Convert From :");
	LCD_GoTo_WriteString(1,0,"1-D   2-H   3-B");
}
void Binary_Operation(void)
{

	LCD_GoTo_WriteString(0,0,"Convert To :     ");
	LCD_GoTo_WriteString(1,0,"1-D   2-H             ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			if(k==DECIMAL) // if you want to Convert from Deci to Hexa
			{
				BinaryToDecimal();
				
			}
			if(k==HEXA) // Convert from Deci to Binary
			{
				BinaryToHex();
			}
			if(k=='C') // reset
			{
				CLEAR_Binary();
				break;
			}
		}
	}
}
/********************                  *********************/
/******************** Hexadecimal Operation *********************/
void HexToBinary(void)
{
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"H :0x                    ");
	LCD_GoTo_WriteString(1,0,"B :                    ");
	u8 j=0;
	while (1)
	{
		k = KEYPAD_GetKey();
		u8 str[2]={0};
		u8 str_index=0;
		if(k!=NO_KEY )
		{
			if(str_index<2)
			{
				str[str_index]=k;
				str_index++;
			}
			
			if (str_index == 2)
			{
				str[str_index] = '\0';
				
			}
			
			if (num>255)
			{
				ERROR();
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"1-D   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
			if(k=='C')
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"1-D   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
		}
		for (;str[0];j++)
		{
			LCD_GoTo_WriteChar(0,6+j,str[j]);
		}
		j=0;
		//LCD_GoTo_WriteNumber(0,6,num);
		LCD_GoTo(1,4) ;
		LCD_WriteHEXToBinary(num);
		
	}	
}
void HexToDecimal(void)
{
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"H :0x                  ");
	LCD_GoTo_WriteString(1,0,"D :                    ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			num=num*10+(k-'0');
			if (num>255)
			{
				 ERROR();
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"1-D   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
			if(k=='C')
			{
				LCD_Clear();
				LCD_GoTo_WriteString(0,0,"Convert To :     ");
				LCD_GoTo_WriteString(1,0,"1-D   3-B             ");
				num=0;
				k=NO_KEY;
				_delay_ms(MENU_DELAY);
				break;
			}
		}
		LCD_GoTo_WriteNumber(0,6,num);
		LCD_GoTo(1,4) ;
		LCD_WriteHEXToDecimal(num);
		
		
	}
}
void CLEAR_Hex(void)
{
	Enter_flag=0;
	LCD_Clear();
	LCD_GoTo_WriteString(0,0,"Convert From :");
	LCD_GoTo_WriteString(1,0,"1-D   2-H   3-B");
}
void Hex_Operation(void)
{

	LCD_GoTo_WriteString(0,0,"Convert To :     ");
	LCD_GoTo_WriteString(1,0,"1-D   3-B             ");
	while (1)
	{
		k = KEYPAD_GetKey();
		if(k!=NO_KEY )
		{
			if(k==BINARY) // if you want to Convert from Deci to Hexa
			{
				HexToBinary();
				
			}
			if(k==DECIMAL) // Convert from Deci to Binary
			{
				HexToDecimal();
			}
			if(k=='C') // reset
			{
				CLEAR_Hex();
				break;
			}
		}
	}
}
/********************                  *********************/
