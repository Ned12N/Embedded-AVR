
#ifndef SENSORS_H_
#define SENSORS_H_
 
 #include "ADC.h"
 #include "StdTypes.h"
 
 
 #define LM35_CH CH_7
 #define POT_CH CH_7
 #define MPX4115 CH_7
 
 u16 LM35_GetTemp(void);
 
 
 // ?????? ?????? 
 u16 POT_GetPercent(void);
 
 u32 MPX_GetPressure(void);




#endif /* SENSORS_H_ */