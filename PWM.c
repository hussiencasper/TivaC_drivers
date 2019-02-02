#include "tm4c123gh6pm.h" 
#include <stdint.h>
#include "Types.h"
#include "DIO.h"
 void PWM1K_50per(void)
 {
    SYSCTL_RCGCPWM_R |= 2;
    DIO_PortInit(PortF,Pin3,0);
	  SYSCTL_RCC_R &= ~0x00100000;
	  DIO_PortDirection(PortF,Pin3,DIO_OUTPUT);
  
		GPIO_PORTF_AFSEL_R =  8;        
		GPIO_PORTF_PCTL_R &= ~0x0000F000;
    GPIO_PORTF_PCTL_R |=  0x00005000;         
		GPIO_PORTF_DEN_R  |=  8;
	 
	  PWM1_3_CTL_R  = 0;
  	PWM1_3_GENB_R = 0x0000008C;
	  PWM1_3_LOAD_R = 1600;//1khz
	  PWM1_3_CMPA_R = 8000;
    PWM1_3_CTL_R  = 1;
    PWM1_ENABLE_R = 0x80;
	 for(;;)
	 {}
	 
 
 
 
 }