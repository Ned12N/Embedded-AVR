
#ifndef UART_H_
#define UART_H_

#define UART_BUFFER UDR

void UART_Init(void);

void UART_Send(u8 data);
u8 UART_Receive(void);

u8 UART_ReceivePerodic(u8* pdata);

void UART_SendString(u8* str);

#endif /* UART_H_ */