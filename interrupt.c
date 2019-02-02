
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "Types.h"
#include "DIO.h"
#include "interrupt.h"

void GPIO_inter(uint32 port,uint32 pins )
{
	switch (port)
	{
	case PortA:
		
  GPIO_PORTA_IS_R   &= ~pins;
	GPIO_PORTA_IBE_R  = ~pins;
	GPIO_PORTA_IEV_R  = ~pins;
	GPIO_PORTA_ICR_R |= ~pins;
	GPIO_PORTA_IM_R  |=  pins;
	NVIC_EN0_R |=0x00000001;
	
		break;

	case PortB:
  GPIO_PORTB_IS_R   &= ~pins;
	GPIO_PORTB_IBE_R  = ~pins;
	GPIO_PORTB_IEV_R  = ~pins;
	GPIO_PORTB_ICR_R |= ~pins;
	GPIO_PORTB_IM_R  |=  pins;
	NVIC_EN0_R |=0x00000002;
		break;

	case PortC:
  GPIO_PORTB_IS_R   &= ~pins;
	GPIO_PORTB_IBE_R  = ~pins;
	GPIO_PORTB_IEV_R  = ~pins;
	GPIO_PORTB_ICR_R |= ~pins;
	GPIO_PORTB_IM_R  |=  pins;
	NVIC_EN0_R |=0x00000004;
		break;

	case PortD:
	GPIO_PORTB_IS_R   &= ~pins;
	GPIO_PORTB_IBE_R  = ~pins;
	GPIO_PORTB_IEV_R  = ~pins;
	GPIO_PORTB_ICR_R |= ~pins;
	GPIO_PORTB_IM_R  |=  pins;
	NVIC_EN0_R |=0x00000008;
		break;

	case PortE:
	GPIO_PORTB_IS_R   &= ~pins;
	GPIO_PORTB_IBE_R  = ~pins;
	GPIO_PORTB_IEV_R  = ~pins;
	GPIO_PORTB_ICR_R |= ~pins;
	GPIO_PORTB_IM_R  |=  pins;
	NVIC_EN0_R |=0x00000010;
		break;

	case PortF:
  GPIO_PORTF_IS_R   &= ~pins;
	GPIO_PORTF_IBE_R  = ~pins;
	GPIO_PORTF_IEV_R  = ~pins;
	GPIO_PORTF_ICR_R |= ~pins;
	GPIO_PORTF_IM_R  |=  pins;
  
  NVIC_EN0_R |=0x40000000;
	
	break;
	}
	__enable_irq;
}



/*
void GPIOPortA_Handler()
{
	
}
void GPIOPortB_Handler()
{
	
}
void GPIOPortC_Handler()
{
	
}
void GPIOPortD_Handler()
{
	
}
void GPIOPortE_Handler()
{
	
}
void GPIOPortF_Handler()
{
	
}*/
	