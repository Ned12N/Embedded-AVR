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


u8 string_compare_sheet(u8 *str1,u8 *str2)
{
	{
		while (*str1 != '\0' && *str2 != '\0') { // Loop through both strings
			if (*str1 != *str2) { // Compare current characters
				return 0; // Strings are not equal
			}
			str1++; // Move to next character in str1
			str2++; // Move to next character in str2
		}
		if (*str1 == '\0' && *str2 == '\0') { // Check if both strings ended at the same time
			return 1; // Strings are equal
			} else {
			return 0; // Strings are not equal
		}
	}
}