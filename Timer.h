#ifndef Timer_H
#define Timer_H

 extern void Systick_init(void);
 extern void delay_systick( uint32 counter,uint32 time) ;
 extern void Timer0_Init(void);
 extern void delay_1second(uint32 multi);
 extern void capturemode(void);
 extern int  capture(void);
 extern void Timer0_1shot(void);
 extern void _delay1shot(void);
 extern void Timer0_Init16(void);
 extern void Timer0Inter(void);
 extern void delay_microseconds(uint32 multi);
#endif