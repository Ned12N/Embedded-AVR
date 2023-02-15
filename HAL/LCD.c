#include "LCD.h"

#if LCD_MODE==_8_BIT

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW); // RS = LOW ---> we can send commands 
	DIO_WritePort(LCD_PORT,command);
		
	// trigger
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	// trigger
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);  // -------- 2 Line  , 5*7 ------
	LCD_WriteCommand(0x0c);  // Cursor , 0x0c , 0x0f , 0x0e
	LCD_WriteCommand(0x1);  // Clear
	_delay_ms(1);
	LCD_WriteCommand(0x6);  // increase ddram address , no Set
}


#elif LCD_MODE==_4_BIT
static void LCD_WriteCommand(u8 command)
{
		DIO_WritePin(RS,LOW); // RS = LOW ---> we can send commands
		
		// write the higher 4 bits from my command to the LCD PINs
		DIO_WritePin(D7,READ_BIT(command,7));
		DIO_WritePin(D6,READ_BIT(command,6));
		DIO_WritePin(D5,READ_BIT(command,5));
		DIO_WritePin(D4,READ_BIT(command,4));
		
		// trigger
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
		
		// write the higher 4 bits from my command to the LCD PINs
		DIO_WritePin(D7,READ_BIT(command,3));
		DIO_WritePin(D6,READ_BIT(command,2));
		DIO_WritePin(D5,READ_BIT(command,1));
		DIO_WritePin(D4,READ_BIT(command,0));
		
		// trigger
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);

	// write the higher 4 bits from my command to the LCD PINs
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));

	// trigger
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);

	// write the higher 4 bits from my command to the LCD PINs
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));

	// trigger
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);

}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);  // -------- 2 Line  , 5*7 ------
	LCD_WriteCommand(0x0c);  // Cursor , 0x0c , 0x0f , 0x0e
	LCD_WriteCommand(0x1);  // Clear
	_delay_ms(1);
	LCD_WriteCommand(0x6);  // increase ddram address , no Set
}

#endif


/********************************************************************/
const char hexChars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x1);
}

void LCD_WriteString(u8* str)
{
	u32 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

void LCD_WriteNumber(s32 num)
{	 u8 i;
	s32 temp;
	u16 num_digits = 0;
	s32 reversed_num = 0;
	s32 num_copy = num;
// handle negative numbers
	if(num<0)
	{
		LCD_WriteData('-');
		num=num*(-1);
	}
// handle zero 
	if (num == 0) {
		LCD_WriteData('0');
		return;
	}
// Calculate the number of digits in the number
  while (num_copy > 0)
  {
	  num_copy /= 10;
	  num_digits++;
  }
/**********reverse number in order to see it in the right order in LCD *************/
  for (i=1;i<=num_digits;i++)
  {
	  temp=num%10;
	  reversed_num = reversed_num * 10 + temp;
	  num=num/10;
  }

/************************Print the number digits by digit**************************/
  for (i=1;i<=num_digits;i++)
  {
	  temp=reversed_num%10;
	  temp=ASCI_LCD_0 | (temp);
	  LCD_WriteData(temp);
	  reversed_num=reversed_num/10;
	}
}

void LCD_WriteHEXToDecimal(u16 num)
{
	u16 right =num%10;
	u16 left =num/10;
	num = (left<<4) | (right);
	LCD_WriteNumber(num);
}

void LCD_WriteBinary(u8 num)
{
	s8 i,flag=0;
	
	for(i=7;i>=0;i--)
	{	
		if((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;	
		}		
		else
		{
			if(flag==1)
			{
				LCD_WriteChar('0');
			}
		}
	}	
}


void LCD_WriteBinaryToDecimal(u32 num)
{
	u32 base=1;
	u32 decimal=0;
	u32 reminder=0;

	while(num>0)
	{
		reminder=num%10;
		num=num/10;
		decimal=decimal + (reminder*base);
		base=base*2;	
	}
	LCD_WriteNumber(decimal);
}

void LCD_WriteBinaryToHex(u32 num)
{
	
	/************** convert binary to decimal **********************/
	u32 base=1;
	u32 decimal=0;
	u32 reminder=0;

	while(num>0)
	{
		reminder=num%10;
		num=num/10;
		decimal=decimal + (reminder*base);
		base=base*2;
	}
		/************** convert decimal to Hexa **********************/

	// an array to store the hexadecimal characters
	const char hexChars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	LCD_WriteChar('0'); // writes the character '0' on the LCD
	LCD_WriteChar('X'); // writes the character 'X' on the LCD
	// writes the upper nibble of the input number as a hexadecimal character
	LCD_WriteChar(hexChars[(decimal & 0xF0) >> 4]);
	// writes the lower nibble of the input number as a hexadecimal character
	LCD_WriteChar(hexChars[decimal & 0x0F]);
}




void LCD_WriteHEX(u8 num)
{
	// an array to store the hexadecimal characters
	const char hexChars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; 

	LCD_WriteChar('0'); // writes the character '0' on the LCD
	LCD_WriteChar('X'); // writes the character 'X' on the LCD
	
	 // writes the upper nibble of the input number as a hexadecimal character
	LCD_WriteChar(hexChars[(num & 0xF0) >> 4]);
	// writes the lower nibble of the input number as a hexadecimal character
	LCD_WriteChar(hexChars[num & 0x0F]); 
}

void LCD_GoTo(u8 Line,u8 cell)
{
	if (Line==0)
	{
		LCD_WriteCommand(0x80+cell);
	} 
	else if(Line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
}

void LCD_WriteNumber_4Digit(u16 num) // 8452
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_GoTo_Clear(u8 Line,u8 cell,u8 NumOfCells)
{
	u8 i;
	LCD_GoTo(Line,cell);
	for (i=0;i<NumOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
}

void LCD_GoTo_WriteString(u8 Line,u8 cell,u8 *str)
{
	LCD_GoTo(Line,cell);
	LCD_WriteString(str);
}

void LCD_GoTo_WriteNumber(u8 Line,u8 cell,s32 num)
{
	LCD_GoTo(Line,cell);
	LCD_WriteNumber(num);
}

void LCD_GoTo_WriteChar(u8 Line,u8 cell,u8 ch)
{
	LCD_GoTo(Line,cell);
	LCD_WriteChar(ch);
}

void LCD_CreatePattern(u8 * pattern , u8 address)
{
	/* Each character is stored in an 8-byte block, so to write to a specific character, 
	 the address must be multiplied by 8 to specify the correct location in CGRAM  */
	
	LCD_WriteCommand(0x40+(address*8)); // 0x40 from data sheet its CGRAM address
	u8 i=0;
	for (i=0;i<8;i++)
	{
		LCD_WriteData(pattern[i]); // pass each bit to CG RAM 
	}
}

void LCD_WriteHEXToBinary(u8 num)
{
		const char hexChars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	// convert hex num to decimal
	u8 right =num%10;
	u8 left =num/10;
	num = (left<<4) | (right);
	
	
	// write the binary representation of the input number
	for(u16 i = (1 << 7); i > 0; i >>= 1)
	{
		if(num & i)
		{
			LCD_WriteData('1');
		}
		else
		{
			LCD_WriteData('0');
		}
	}
}