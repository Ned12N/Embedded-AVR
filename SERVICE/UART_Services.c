#include "StdTypes.h"
#include "UART.h"
#include "UART_Services.h"

// synch Function 
void UART_SendString(u8* str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
}

// synch Function works as a buffer for the data 
void UART_ReceiveString(u8* str)
{
	 
	 u8 i=0;
	 str[i]=UART_Receive();
	 if (str[i]==0x0A)
	 {
		 
	 }
	 else
	 {
		 for(;(str[i]!=0x0D);)
		 {
			 i++;
			 str[i]=UART_Receive();
		 }
		 
		 //assign Null to the end of string
		 str[i]='\0'; 
	 }
}

#define END_MARK '\0'
u8 string_compare(u8 *str1,u8 *str2)
{
	{
		while (*str1 != END_MARK || *str2 != '\0') 
		{ // Loop through both strings
			if (*str1 != *str2) 
				{ // Compare current characters
					return 0; // Strings are not equal
				}
			str1++; // Move to next character in str1
			str2++; // Move to next character in str2
		}
		return 1;
	}
}

void UART_SendNumber(u32 num)
{
	u8* ptr=&num;
	UART_Send(ptr[0]);
	UART_Send(ptr[1]);
	UART_Send(ptr[2]);
	UART_Send(ptr[3]);
}

void UART_ReceiveNumber(u32* pnum)
{
	u32 num=0;
	u8* ptr=&num;
	ptr[0]=UART_Receive();
	ptr[1]=UART_Receive();
	ptr[2]=UART_Receive();
	ptr[3]=UART_Receive();
}
#define LITTLE 1
#define BIG 0
/*********************************************************************************/
u8 endian_check(void)
{
	u32 x=1;
	u8* p=&x;
	if(*p==1)	
	{
		return LITTLE;
	}
	else
	{
		return BIG;
	}
}

u32 endian_convert(u32 num)
{
	return (num<<24) | (num>>24) | ((num>8)&(0x0000ff00)) | ((num<<8)&(0x00ff0000)) ;
}

u16 endian_convert_2(u16 num)
{
	return (num<<8) | (num>>8);
}
/* This function sends a string of characters over the UART interface with a checksum byte
   that is calculated as the sum of all the characters in the string. The string length and
   checksum are sent after the data. */

void UART_SendStringCheckSum(u8* str)
{
    u8 len = 0;         // Variable to hold the length of the string
    u16 sum = 0;        // Variable to hold the checksum

    // Find the length of the string
    for (len = 0; str[len]; len++)
    {
        // Do nothing, just counting the characters
    }

    // Send the length of the string
    UART_Send(len);

    // Send the characters in the string and accumulate the checksum
    for (u8 i = 0; i < len; i++)
    {
        UART_Send(str[i]);
        sum = sum + str[i];
    }

    // Send the checksum as two bytes
    UART_Send((u8)sum);                 // Send the low byte of the checksum
    UART_Send((u8)(sum >> 8));          // Send the high byte of the checksum
}

/* This function receives a string of characters over the UART interface with a checksum byte
   that is calculated as the sum of all the characters in the string. The function returns 1
   if the checksum is correct, and 0 otherwise. */

u8 UART_ReceiveStringCheckSum(u8* str)
{
    u8 len, i;          // Variables to hold the length of the string and the loop index
    u16 sum_cal = 0;    // Variable to hold the calculated checksum
    u16 sum_rec = 0;    // Variable to hold the received checksum as a 16-bit value
    u8 b0, b1;          // Variables to hold the low and high bytes of the received checksum

    // Get the length of the string
    len = UART_Receive();

    // Receive the characters in the string and calculate the checksum
    for (i = 0; i < len; i++)
    {
        str[i] = UART_Receive();
        sum_cal = sum_cal + str[i];
    }

    // Add a null terminator to the string
    str[i] = '\0';

    // Receive the checksum as two bytes
    b0 = UART_Receive();
    b1 = UART_Receive();

    // Combine the two bytes to form the 16-bit checksum value
    sum_rec = (u16)b0 | (u16)(b1 << 8);

    // Check if the received checksum matches the calculated checksum
    if (sum_rec == sum_cal)
    {
        // Checksum is correct, return 1 to indicate success
        return 1;
    }
    else
    {
        // Checksum is incorrect, return 0 to indicate failure
        return 0;
    }
}


u8*TX_Str;
void func_tx(void)
{
	static u8 i=1;
	if (TX_Str[i])
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
	}
}

void UART_SendStringAshync(u8*str)
{
	UART_TX_SetCallBack(func_tx);
	UART_TX_InterruptEnable();
	UART_SendNoBlock(str[0]);
	TX_Str=str;
}