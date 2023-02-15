/*

 // function to blink LEDS in ROW
 void led_1()
 {
	 for(i=1;i<255;i=i*2)
	 {
		 PORTA = i;
		 _delay_ms(500);
	 }
	 
 }
 // Function to Blink LEDs in different orders
 void led_2()
 {
	 while(1)
	 {
		 PORTA = 0x0f;
		 _delay_ms(500);
		 PORTA = 0xf0;
		 _delay_ms(500);
		 PORTA = 0x55;
		 _delay_ms(500);
		 PORTA = 0xAA;
		 _delay_ms(500);
	 }
 }
 // Function to power 8 LEDs using only 5 Pins
 void power8Led_5PINS()
 {   int BITNum=0;
	 int i=0;
	 for(i=1;i<=16&&BITNum!=4;(i=i<<1))
	 {
		 DDRA = 0b00011111;
		 PORTA =i; // power the ( 1 ,3 ,5,7) LEDS
		 _delay_ms(500);

		 PORTA =0x1f&(~(1<<BITNum)); // power the ( 2 ,4 ,6,8) LEDS
		 _delay_ms(500);
		 BITNum++;
	 }
 }

 void LedBlink_UpDown_5pins()
 {   int BITNum=0;
	 int i=0;
	 for(i=1;i<=16&&BITNum!=4;(i=i<<1))
	 {
		 DDRA = 0b00011111;
		 PORTA =i; // power the ( 1 ,3 ,5,7) LEDS
		 _delay_ms(500);

		 PORTA =0x1f&(~(1<<BITNum)); // power the ( 2 ,4 ,6,8) LEDS
		 _delay_ms(500);
		 BITNum++;
	 }
 }

 void LedBlink_DownUp_5pins()
 {   char BITNum=3;
	 DDRA = 0b00011111;
	 for(i=8;i>0&&BITNum>=0;(i=i>>1))
	 {
		 PORTA =0x1f&(~(1<<BITNum)); // power the ( 2 ,4 ,6,8) LEDS
		 _delay_ms(500);
		 BITNum--;
		 PORTA =i; // power the ( 1 ,3 ,5,7) LEDS
		 _delay_ms(500);
	 }
 }

 // Task 1
 // Function to Blink LEDs every time you press the first button and reverse Blink LEDs if you press the second button
 void BlinkLeds_Using2Buttons()
 {
	 DDRC=0; // PORTC Direction = 0
	 PORTC=0;
	 DDRA=0xff; // PORTA Direction = 1
	 
	 if((READ_BIT(PINC,1))) // ( Pull Down resistor) if i click the second button enter here
	 {
		 
		 if(i==0)
		 {
			 i=128;
			 PORTA=i;
			 flag2=1;
		 }
		 if(flag2==0)
		 {
			 
			 i = i>>1;
			 PORTA = i;
			 flag2=1;
			 
		 }
	 }
	 else
	 {
		 flag2=0;
	 }
	 // going from up to bottom
	 if(!(READ_BIT(PINC,0))) // ( Pull Up resistor) if i click the button enter here
	 {
		 if(flag1==0)
		 {
			 PORTA = i;
			 i = i*2;
			 flag1=1;
			 
		 }
		 if(i==0)
		 {
			 i=1;
			 flag1=1;
		 }
	 }
	 else
	 {
		 flag1=0;
	 }
	 
 }
 // Task 2
 // Function --> Hold the Button To Blink the LEDs in-order -- release the Button and the Blinking will stop at the current LED
 //              Hold the second Button to Blind LEDs in reverse order starting from the last LED
 void StopLeds_Using2Buttons()
 {
	 DDRC=0; // PORTC Direction = 0
	 PORTC=0;
	 DDRA=0xff; // PORTA Direction = 0
	 if(!(READ_BIT(PINC,0))) // (Pull Up resistor) Hold the first to button enter here
	 {
		 if(flag1==0)// flag to maintain the synchronization
		 {
			 for(;!(READ_BIT(PINC,0));i=i<<1)// keep looping until you release the button
			 {
				 if(i==0) // ---------Corner Case--------- if we reached the last LED (number 8)
				 {
					 i=1;
					 PORTA = i;
					 _delay_ms(500);
				 }
				 PORTA = i;      // --------- main loop ---------
				 _delay_ms(500); // --------- main loop ---------
			 }
			 flag1=1;
		 }
	 }
	 else  // if you didn't press the button skip the (if) and enter (else)
	 {
		 flag1=0;
	 }
	 
	 
	 if((READ_BIT(PINC,1))) // (Pull Down resistor) Hold the second to button enter here
	 {
		 if(flag2==0) // flag to maintain the synchronization     -_- instead of using Busy Wait or while() -_-
		 {
			 for(; (READ_BIT(PINC,1)) ;) // keep looping until you release the button
			 {
				 
				 i=i>>1; // --------- main loop ---------
				 if(i<=0) // ---------Corner Case--------- when we subtract until (i < 0) we set (i = last pin) which is ( 128 = 1000 000 )
				 {
					 i=128; // set i
					 PORTA = i; // display it
					 flag2=1;
					 _delay_ms(500);
					 i=i>>1;  // subtract the next number
				 }
				 PORTA = i; // --------- main loop ---------
				 _delay_ms(500); // --------- main loop ---------
			 }
			 flag1=1;
		 }
	 }
	 else
	 {
		 flag2=0;
	 }
	 
 }
 // Task 3
 // Function to Reverse the continuous Blinking of LEDS when we press the Button
 void RverseContinuLED_1Button()
 {
	 
	 DDRC=0; // PORTC Direction = 0
	 PORTC=0;
	 DDRA=0xff; // PORTA Direction = 0
	 if(flag1==0)
	 {
		 for(;(READ_BIT(PINC,0));i=i<<1)// keep looping until you press the button
		 {
			 if(i==0) // ---------Corner Case--------- if we reached the last LED (number 8)
			 {
				 i=1;
				 PORTA = i;
				 _delay_ms(150);
			 }
			 PORTA = i;      // --------- main loop ---------
			 _delay_ms(150); // --------- main loop ---------
		 }
		 flag1=1;
	 }
	 else
	 {
		 flag1=0;
	 }
	 
	 
	 
	 if(flag2==0) // flag to maintain the synchronization  -_- instead of using Busy Wait or while() -_-
	 {
		 for(; (READ_BIT(PINC,0)) ;) // keep looping until you release the button
		 {
			 
			 if(!(READ_BIT(PINC,0)))
			 {
				 //_delay_ms(150);
				 break;
			 }
			 i=i>>1; // --------- main loop ---------
			 if(i<=0) // ---------Corner Case--------- when we subtract until (i < 0) we set (i = last pin) which is ( 128 = 1000 000 )
			 {
				 i=128; // set i
				 PORTA = i; // display it
				 flag2=1;
				 _delay_ms(150);
				 i=i>>1;  // subtract the next number
			 }
			 PORTA = i; // --------- main loop ---------
			 _delay_ms(150); // --------- main loop ---------
		 }
		 flag2=1;
	 }
	 else
	 {
		 flag2=0;
	 }
 }
 
 // Task 5
 // Clear the bit first then use ( bitwise OR )  to SET_BIT by shifting value by BIT and OR it with PORT
 #define  TaskSET_BIT(PORT,BIT,VALUE)  (  PORT=( PORT &(~(1<<BIT)) ) | (VALUE<<BIT)  )*/