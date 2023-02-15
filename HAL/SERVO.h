/*
 * SERVO.h
 *
 * Created: 2/9/2023 2:01:28 PM
 *  Author: mohamed
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "StdTypes.h"
#include "MemMap.h"


#define SERVO_PIN OCR1B

 
#define Timer_MODE    FASTPWM
#define OC_MODE     NON_INVERTING


void servo(u8 angle);
 


#endif /* SERVO_H_ */