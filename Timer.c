#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "Types.h"
#include "DIO.h"
#include "Timer.h"
 unsigned long int d_lay;
 void Systick_init(void)
 {
		NVIC_ST_CTRL_R =0;
    NVIC_ST_RELOAD_R=16000000-1;
	  NVIC_ST_CURRENT_R=0; 
    NVIC_ST_CTRL_R =5;
 }
 
 void Timer_func(void)//test function
 {
 if(NVIC_ST_CTRL_COUNT)
   {
    DIO_PortWrite(PortF,RED,DIO_HIGH);
   }
   else{	 
	     DIO_PortWrite(PortF,RED,DIO_LOW);
	      }
 }
 void delay_systick( uint32 counter,uint32 time)
 {
	 int i;
	 for(i=0;i<time;i++)
	 {
      NVIC_ST_CTRL_R =0;
      NVIC_ST_RELOAD_R= counter-1;
	    NVIC_ST_CURRENT_R=0; 
	    NVIC_ST_CTRL_R =5;
	 while(NVIC_ST_CTRL_COUNT == 0)
	 {
	  
	 }
    
 }
 }
 void Timer0_Init(void)//periodic downcount 32
 {
	 
   SYSCTL_RCGCTIMER_R |= 0x01;
   TIMER0_CTL_R &= ~0x01;	 
   TIMER0_CFG_R  =0x00000000;	 
	 TIMER0_TAMR_R |=  0x02;	 
	 TIMER0_TAMR_R &= ~0x00000010;	 
	 TIMER0_TAILR_R = 80000000-1; 
	 TIMER0_CTL_R |=  0x00000001;
	 
 }
 void delay_1second(uint32 multi)
 {
	 int i;
  SYSCTL_RCGCTIMER_R |= 0x01;
   TIMER0_CTL_R &= ~0x01;	 
   TIMER0_CFG_R  =0x00000000;	 
	 TIMER0_TAMR_R |=  0x02;	 
	 TIMER0_TAMR_R &= ~0x00000010;	 
	 TIMER0_TAILR_R = 80000000-1; 
	 TIMER0_CTL_R |=  0x00000001;
 
	for(i=0;i<multi;i++){
	 while((TIMER0_RIS_R &0x00000001)==0)
		{

		}	
	TIMER0_ICR_R  |=(1<<0);
 }
 }
 
 void delay_microseconds(uint32 multi) 
 {
	 int i;
  SYSCTL_RCGCTIMER_R |= 0x01;
   TIMER0_CTL_R &= ~0x01;	 
   TIMER0_CFG_R  =0x00000000;	 
	 TIMER0_TAMR_R |=  0x02;	 
	 TIMER0_TAMR_R &= ~0x00000010;	 
	 TIMER0_TAILR_R = 80-1; 
	 	TIMER0_ICR_R  |=(1<<0);
	 TIMER0_CTL_R |=  0x00000001;
	 for(i=0;i<multi;i++){
	 while((TIMER0_RIS_R &0x00000001)==0)
		{

		}	
	TIMER0_ICR_R  |=(1<<0);
 }
	 }
 void capturemode(void)
 {
       GPIO_PORTB_PCTL_R &= ~0x0F000000;
	     GPIO_PORTB_PCTL_R |= 0x07000000;
	     GPIO_PORTB_AFSEL_R |=0x01;
	
	     SYSCTL_RCGCTIMER_R |= 0x01;
       TIMER0_CTL_R  &= ~0x01;
	     TIMER0_CFG_R   =  0x00000000;
	     TIMER0_TAMR_R |=  0x00000017; 
	     
	     TIMER0_CTL_R |= 0x0C;
	     TIMER0_ICR_R  = 4;
	     TIMER0_CTL_R |=  0x00000001;
 }
 
 int capture(void)
 {
	   uint32 Lastedge,Thisedge;
     TIMER0_ICR_R  = 4;
	 while((TIMER0_RIS_R & 0x04) == 0)
	 { }
	   Lastedge=TIMER0_TAR_R;
	while((TIMER0_RIS_R & 0x04) == 0)
	 { }
	   Thisedge=TIMER0_TAR_R;
	 return (Thisedge-Lastedge) & 0x00FFFFFF;
 
 }
 void Timer0_1shot(void)
 {
 
    SYSCTL_RCGCTIMER_R |= 0x01;
	   d_lay=1;
     TIMER0_CTL_R   &= ~0x01;	 
     TIMER0_CFG_R    =0x00000000;	 
	   TIMER0_TAMR_R   =  0x00000001;
	   TIMER0_TAILR_R  = 80000000-1;
   	 TIMER0_ICR_R   |=(1<<0);
	   TIMER0_CTL_R   |=  0x00000001;
	
 
 }
 
 void _delay1shot(void)
 {
   while ((TIMER0_RIS_R & 0x1) == 0) ; 
 }
 
 void Timer0_Init16(void){ 									

	   SYSCTL_RCGCTIMER_R |= 0x01; 							
	   d_lay               = 1; 
	   TIMER0_CTL_R       &=~0x01;								
	   TIMER0_CFG_R       |= 0x04; 							
	   TIMER0_TAMR_R      |= 0x02; 							//Periodic Timer Mode, defualt count Down.
	   TIMER0_TAILR_R      = 16000000-1; 				
     TIMER0_CTL_R       |=  0x00000001;
 }
	
 /*int Timer0A_Handler(void)
	 {
	  uint32 Lastedge,Thisedge;
    TIMER0_ICR_R  = 4;
	 while((TIMER0_RIS_R & 0x04) == 0)
	 { }
	  Lastedge=TIMER0_TAR_R;
	while((TIMER0_RIS_R & 0x04) == 0)
	 { }
	  Thisedge=TIMER0_TAR_R;
	 return (Thisedge-Lastedge) & 0x00FFFFFF;
	 }*/
	 void Timer0Inter(void){
	 TIMER0_IMR_R 			 |=0x02; //capturemode																																  
	 TIMER0_CTL_R			 |= 0x01; 																																		
	 NVIC_EN0_R 				  = 1<<19;         						  																																																	      						  
	__enable_irq; 											
}