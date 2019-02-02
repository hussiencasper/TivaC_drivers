#ifndef interrupt_H
#define interrupt_H

#define PortA	0x00
#define PortB	0x01
#define PortC	0x02
#define PortD	0x03
#define PortE	0x04
#define PortF	0x05

#define RED  0x02
#define BLUE 0x04
#define GREEN 0x08
#define YELLOW 0x0A
#define CYAN 0x0C
#define WHITE 0x0E
#define PINK 0x06

#define DIO_INPUT 0
#define DIO_OUTPUT 0xFF

#define Pin0 0x01
#define Pin1 0x02
#define Pin2 0x04
#define Pin3 0x08
#define Pin4 0x10
#define Pin5 0x20
#define Pin6 0x40
#define Pin7 0x80

#define DIO_TRUE 1
#define DIO_FALSE 0

#define DIO_LOW 0
#define DIO_HIGH 0xFF

extern void GPIO_inter(uint32 ,uint32 );

#endif
