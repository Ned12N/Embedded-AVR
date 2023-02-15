
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

typedef enum{
	M1,
	M2,
	NUMBER_MOTORS	
	}MOTOR_type;
	
Erorr_type MOTOR_Stop(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor); // clock wise
void MOTOR_CCW(MOTOR_type motor); // counter clock wise

/************* speed from 0 to 100% ********************/
void MOTOR_Speed(MOTOR_type motor,u8 speed);








#endif /* MOTOR_INTERFACE_H_ */