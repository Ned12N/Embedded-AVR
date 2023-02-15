 #include "Sensors.h"
 
 
 u16 LM35_GetTemp(void)
 {
	 u16 temp;
	 u16 volt = ADC_GetVolt(LM35_CH); // gives mV --> millivolt
	 temp = volt;
	 return temp;
	 
 }
 
  u16 un_GetTemp(void)
  {
	  u16 temp;
	  u16 adc = ADC_Read(LM35_CH); // gives mV --> millivolt
	  temp = ((u32)adc-674)/1024-180;
	  return temp;
	  
  }
  
 u16 POT_GetPercent(void)
 {
	 u16 milli_volt = ADC_GetVolt(POT_CH);
	 u16 per = ((u32)milli_volt*100/5000);
	 
	 return per;
 }
 
 u32 MPX_GetPressure(void)
 {
	 u16 milli_volt = ADC_Read(MPX4115);
	 u32 volt = ( ( (u32)1000*(milli_volt-40))/943 ) + 150;
	 return volt;
 }