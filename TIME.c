 #include "TIME.h"
 #include "GPIO.h"
 #include "tm4c123gh6pm.h" 
 #include "stdint.h"
 #include "Types.h"
 #include "DIO.h"
 #include "interrupt.h"
 #include "Timer.h"
void init_Capture(void)
{
		volatile unsigned long int delay;
  RCGCTIMER_16_32_TIMER|= 0x01;
	DISABLE_TIMER_16A(0);
	REG(Timer0_16_32_base ,GPTMCFG_GPTM_CONFIGURATION)=(REG(Timer0_16_32_base ,GPTMCFG_GPTM_CONFIGURATION) &0xFFFFFFFC)+MODE_INDIVIDUAL16_32T;
	REG(Timer0_16_32_base,GPTMTAMR_TIMER_A_MODE)=(1<<TACDIR);	
	REG(Timer0_16_32_base,GPTMTAMR_TIMER_A_MODE)&=~(1<<TACMR);
	REG(Timer0_16_32_base,GPTMCTL_GPT_CONTROL)|=(POSITIVE_EDGE<<TAEVENT);
	REG(Timer0_16_32_base,GPTMTAPR_T_A_PRESCALER)=0xFF;
	REG(Timer0_16_32_base,GPTMTAILR_T_A_INTERVAL_LOAD)=0xFFFF;
	REG(Timer0_16_32_base,GPTMTAMATCHR_T_A_MATCH)=4;
	ENABLE_TIMER_16A(0);
	
	SYSCTL_RCGC2_R |= 0x0000002;
		delay = SYSCTL_RCGC2_R;
		GPIO_PORTB_CR_R |= Pin6;
	 DIO_PortDirection(PortB,Pin6,DIO_OUTPUT);
		GPIO_PORTB_AMSEL_R &= ~Pin6;
	 GPIO_PORTB_PCTL_R &=0xF0FFFFFF;
		GPIO_PORTB_PCTL_R =(0x7<<24);
		GPIO_PORTB_AFSEL_R =(1<<6) ;	
		GPIO_PORTB_DEN_R |= Pin6;
		DIO_PortInit(PortB,Pin0,0);
		DIO_PortDirection(PortB,Pin0,DIO_OUTPUT);
		 TIMER0_IMR_R 			 |=0x02; //capturemode		
    REG(Timer0_16_32_base,GPTMICR_INRERUPT_CLEAR_ACKNOWLEDGE) |=(1<<CAMRIS);		 
	   TIMER0_CTL_R			   |= 0x01; 																																		
	   NVIC_EN0_R 				  = 1<<19;         						  																																																	      						  
	__enable_irq; 								
   DIO_PortInit(PortF,Pin0,Pin0);
   DIO_PortDirection(PortF,Pin0,DIO_INPUT);
   GPIO_inter(PortF,Pin0);
}

void GPIOPortF_Handler(void)
{
	 TIMER0_ICR_R  = 0x00000010;
	DIO_PortWrite(PortB,Pin0,DIO_HIGH);
	delay_microseconds(20);
	DIO_PortWrite(PortB,Pin0,DIO_LOW);
	delay_microseconds(20);

	
}
void Timer0A_Handler(void)
	 {
	GPIO_PORTF_DATA_R=~RED;
	 }
