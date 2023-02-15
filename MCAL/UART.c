#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "UART.h"

void UART_Init(void)
{
	// baud rate
	UBRRL=51;
	
	// Normal Speed
	CLR_BIT(UCSRA,U2X);
	
	// frame data bit , parity , stop 
	// 8 data , no parity , 1 stop ---> defualt 
	
	// enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}



void UART_Send(u8 data)
{
	//check the flag -- busy wait
	while(!READ_BIT(UCSRA,UDRE));
	
	UART_BUFFER=data;
	
}

u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));

	return UART_BUFFER;
}

u8 UART_ReceivePerodic(u8* pdata)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*pdata=UART_BUFFER;
		return 1;		
	}
		return 0;
}

