#ifndef TIME_H
#define TIME_H
//#include "timer_conf.h"
//#include "gpio.h"
//#include "systick.h"
//#include "uart.h"
#define Timer0_16_32_base      ((unsigned long) 0x40030000)
#define Timer1_16_32_base      ((unsigned long) 0x40031000)
#define Timer2_16_32_base      ((unsigned long) 0x40032000)
#define Timer3_16_32_base      ((unsigned long) 0x40033000)
#define Timer4_16_32_base      ((unsigned long) 0x40034000)
#define Timer5_16_32_base      ((unsigned long) 0x40035000)	
#define Timern_16_32_base(N) 	 ((unsigned long) (0x40030000|(N<<12)))	

#define Timer0_32_64_WIDE_base ((unsigned long) 0x40036000)
#define Timer1_32_64_WIDE_base ((unsigned long) 0x40037000)
#define Timer2_32_64_WIDE_base ((unsigned long) 0x4004C000)
#define Timer3_32_64_WIDE_base ((unsigned long) 0x4004D000)
#define Timer4_32_64_WIDE_base ((unsigned long) 0x4004E000)
#define Timer5_32_64_WIDE_base ((unsigned long) 0x4004F000)	

#define GPTMCFG_GPTM_CONFIGURATION            ((unsigned long)0x000)
#define GPTMTAMR_TIMER_A_MODE                 ((unsigned long)0x004)
#define GPTMTBMR_TIMER_B_MODE                 ((unsigned long)0x008)
#define GPTMCTL_GPT_CONTROL                   ((unsigned long)0x00C)
#define GPTMIMR_INTERRUPT_MASK                ((unsigned long)0x018)
#define GPTMRIS_INTERRUPT_STATUS              ((unsigned long)0x01C)
#define GPTMMIS_MASKED_INTERRUPT_STATUS       ((unsigned long)0x020)
#define GPTMICR_INRERUPT_CLEAR_ACKNOWLEDGE    ((unsigned long)0x024)	
#define GPTMTAILR_T_A_INTERVAL_LOAD           ((unsigned long)0x028)
#define GPTMTBILR_T_B_INTERVAL_LOAD           ((unsigned long)0x02C)	
#define GPTMTAMATCHR_T_A_MATCH                ((unsigned long)0x030)
#define GPTMTBMATCHR_T_B_MATCH                ((unsigned long)0x034)	
#define GPTMTAPR_T_A_PRESCALER                ((unsigned long)0x038)	
#define GPTMTBPR_T_B_PRESCALER                ((unsigned long)0x03C)		
#define GPTMTAPMR_T_A_PRESCALER_MATCH         ((unsigned long)0x040)
#define GPTMTBPMR_T_B_PRESCALER_MATCH         ((unsigned long)0x044)	
#define GPTMTAR_T_A_READ_ONLY                 ((unsigned long)0x048)
#define GPTMTBR_T_B_READ_ONLY                 ((unsigned long)0x04C)
#define GPTMTAV_T_A_VALUE_READ_WRITE          ((unsigned long)0x050)
#define GPTMTBV_T_B_VALUE_READ_WRITE          ((unsigned long)0x054)	
#define GPTMTAPS_T_A_PRESCALE_SNAPSHOT        ((unsigned long)0x05C)
#define GPTMTBPS_T_B_PRESCALE_SNAPSHOT        ((unsigned long)0x060)	
#define GPTMTAPV_T_A_PRESCALE_VALUE           ((unsigned long)0x064)
#define GPTMTBPV_T_B_PRESCALE_VALUE           ((unsigned long)0x068)
	
#define TIMER_0_A_IRQ_INTERRUPT_NO       19
#define TIMER_0_B_IRQ_INTERRUPT_NO       20
#define TIMER_1_A_IRQ_INTERRUPT_NO       21
#define TIMER_1_B_IRQ_INTERRUPT_NO       22
#define TIMER_2_A_IRQ_INTERRUPT_NO       23
#define RCGCTIMER_16_32_TIMER   (*((volatile unsigned long *)0x400FE604))
#define RCGCWTIMER_32_64_TIMER  (*((volatile unsigned long *)0x400FE65C))
#define EN0_INTERRUPT_ENABLE    (*((volatile unsigned long *)0xE000E100))	
#define DIS0_INTERRUPT_DISABLE  (*((volatile unsigned long *)0xE000E180))	
#define PRI4_INTERRUPT_PRIORITY (*((volatile unsigned long *)0xE000E410))     	/* for timer 0_A field 29 t0 31*/
#define PRI5_INTERRUPT_PRIORITY (*((volatile unsigned long *)0xE000E414))     	/* for timer 1_A field13 t0 15*/	

#define REG(BASE,OFFSET)   (*((volatile unsigned long *)(BASE+OFFSET)))
#define ENABLE_TIMER_16A(TIMER_NO) (REG(Timern_16_32_base(TIMER_NO),GPTMCTL_GPT_CONTROL)|=(1<<TAEN))
#define ENABLE_TIMER_16B(TIMER_NO) (REG(Timern_16_32_base(TIMER_NO),GPTMCTL_GPT_CONTROL)|=(1<<TBEN))
#define DISABLE_TIMER_16A(TIMER_NO) (REG(Timern_16_32_base(TIMER_NO),GPTMCTL_GPT_CONTROL)&=~(1<<TAEN))
#define DISABLE_TIMER_16B(TIMER_NO) (REG(Timern_16_32_base(TIMER_NO),GPTMCTL_GPT_CONTROL)&=~(1<<TBEN))

typedef enum {DUTY_CYCLE_NORMAL = 0,DUTY_CYCLE_INVERTED = 1}DutyCycle;
typedef enum {COUNT_DOWN = 0,COUNTUP = 1}Direction;
typedef enum {TIMER0,TIMER1,TIMER2,TIMER3,TIMER4,TIMER5}TIMER_NAMES;
typedef enum {GPTMCFG = 0}GPTMCFG_bits;
typedef enum {MODE_CANCATONATED_for_16_32_OR_32_64T = 0X0,MODE_CANCATONATED_32_64_RTC = 0X1,MODE_INDIVIDUAL16_32T = 0X4}GPTMCFG_modes;
typedef enum {GTAPLO=11, TAMRSU=10, TAPWMIE=9, TAILD=8, TASNAPS=7, TAWOT=6, TAMIE=5, TACDIR=4, TAAMS =3, TACMR=2, TAMR=0}GPTMTAMR_bits;
typedef enum {MODE_ONE_SHOT = 0X1,MODE_PERIODIC= 0X2,MODE_CAPTURE = 0X3}TAMR_Or_TBMR_modes;
typedef enum {TBPWML=14, TBOTE=13, TBEVENT=10, TBSTALL=9, TBEN=8, TAPWML=6, TAOTE=5, RTCEN=4, TAEVENT=2, TASTALL=1, TAEN=0}GPTMCTL_bits;
typedef enum {TBMIM = 11, CBEIM = 10, CBMIM=9, TBTOIM=8, TAMIM=4, RTCIM=3, CAEIM=2, CAMIM=1, TATOIM=0}GPTMIMR_bits;
typedef enum {TBMRIS= 11, CBERIS= 10, CBMRIS=9, TBTORIS=8, TAMRIS=4, RTCRIS=3, CAERIS=2, CAMRIS=1, TATORIS=0}GPTMRIS_bits;	
typedef enum {TBMMIS= 11, CBEMIS= 10, CBMMIS=9, TBTOMIS=8, TAMMIS=4, RTCMIS=3, CAEMIS=2, CAMMIS=1, TATOMIS=0}GPTMMIS_bits;	
typedef enum {TTBMCINT= 11, CBECINT= 10, CBMCINT=9, TBTOCINT=8, TAMCINT=4, RTCCINT=3, CAECINT=2, CAMCINT=1, TATOCINT=0}GPTMICR_bits;
typedef enum {POSITIVE_EDGE = 0X0,NEGATIVE_EDGE= 0X1,BOTH_EDGES = 0X3}CAPTURE_EVENT_modes_TnEVENT;
typedef enum {Edge_Count_mode= 0X0,Edge_Time_mode= 0X1,}EDGE_COUNT_EDGE_TIME_TACMR;

typedef struct
{
	Direction countDirection;
	CAPTURE_EVENT_modes_TnEVENT edgeEvent;
	
}CAPTURE_TIME_TIMER0_16;	

typedef struct
{
	unsigned char period_in_ms; //max 209 ms
	unsigned char duty_cycle; //0 to 100
}PWM_CONF;

void timer_intitialization(void);
void timer_polling(void);
void timer0_B_polling(void);
void timer1_polling(void);
void INPUT_EGDE_COUNT_polling(void);
void timer_match_polling(void);
void INPUT_EGDE_TIME_polling(void);

void TIMER_0_A_ISR(void);
void TIMER_1_A_ISR(void);
void TIMER_0_B_ISR(void);
void TIMER_2_A_ISR(void);

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
extern void init_Capture(void);
#endif