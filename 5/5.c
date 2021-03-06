/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
? Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 12/28/2021
Author  : Parsa vares
Company :     SRBIAU
Comments:      Task 5


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <stdlib.h>
#include <alcd.h>
#define   undefined 20
#define   reset         200

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here
unsigned char k=undefined,ragham=0,z=0,x=0,a=0;
float pasokh=0,num1=0,num2=0;

void disp(float c,unsigned char xx,unsigned char yy,unsigned char f);
char keypad();
char keypad()
{
PORTD.0=0;
        if(PIND.4==0)
              {
              k=7;  
              ragham++;
              while(PIND.4==0);
              } 
        if(PIND.5==0)
              {
              k=8;
              ragham++;
              while(PIND.5==0);
              }
        if(PIND.6==0)
              {
              k=9;
              ragham++;
              while(PIND.6==0);
              } 
        if(PIND.7==0)
              {  
              // symbol / 
              k=15;
              while(PIND.7==0);
              }
PORTD.0=1;
PORTD.1=0; 
        if(PIND.4==0)
              {
              k=4;
              ragham++;
              while(PIND.4==0);
              } 
        if(PIND.5==0)
              {    
              k=5;
              ragham++;
              while(PIND.5==0);
              }
        if(PIND.6==0)
              {
              k=6;
              ragham++;
              while(PIND.6==0);
              } 
        if(PIND.7==0)
              {  
              // * 
              k=14;
              while(PIND.7==0);
              } 
PORTD.1=1;
PORTD.2=0; 
        if(PIND.4==0)
              {
              k=1;
              ragham++;
              while(PIND.4==0);
              } 
        if(PIND.5==0)
              { 
              k=2; 
              ragham++;
              while(PIND.5==0);
              }
        if(PIND.6==0)
              {  
              k=3;
              ragham++;
              while(PIND.6==0);
              } 
        if(PIND.7==0)
              { 
              // symbol- 
              k=13;
              while(PIND.7==0);
              }
PORTD=0xff;
PORTD.3=0; 
        if(PIND.4==0)
              {  
              lcd_clear();
              PORTD.3=1;  
              return k=reset;
              while(PIND.4==0);
              } 
        if(PIND.5==0)
              {
              k=0;
              ragham++;
              while(PIND.5==0);
              }
            if(PIND.6==0)
              { 
              // symbol=
              k=12;            
              while(PIND.6==0);
              } 
            if(PIND.7==0)
              { 
              // symbol+ 
              k=11;
              while(PIND.7==0);
              }   
PORTD.3=1;  
return k;
}           
void disp(float c,unsigned char xx,unsigned char yy,unsigned char f)
{
unsigned char lcdbuff[16];
lcd_gotoxy(xx,yy);
ftoa(c,f,lcdbuff);
lcd_puts(lcdbuff);
}
void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 8
DDRD=0X0F;
PORTD=0XFF;
lcd_init(8);
while (1)
      while(1)               
    {
    start:
    x=0;   
    ragham=0;
        do{  
            num1=keypad();
             }
        while(ragham!=1);  
    lcd_clear(); 
    disp(num1,0,0,0);
    x++;
    k=undefined;
        do{
            keypad();  
            if(k==reset)goto start;   
            if( k<10)
              {  
              num1*=10;
              num1+=k;
              disp(num1,0,0,0);
              x++;   
              k=undefined;
              }
            }
        while(k!=11&k!=13&k!=14&k!=15); 
    switch (k)
    {
        case 11:lcd_gotoxy(x,0);lcd_putsf("+");z=1; break;
        case 13:lcd_gotoxy(x,0);lcd_putsf("-");z=2; break;
        case 14:lcd_gotoxy(x,0);lcd_putsf("*");z=3; break; 
        case 15:lcd_gotoxy(x,0);lcd_putsf("/");z=4; break; 
    } 
    ragham=1;
    x++;
        do{
            num2=keypad();
            if(k==reset)goto start;
            }   
        while(ragham!=2);  
    disp(num2,x,0,0);
    k=undefined;
    a=x;  
        do{
            keypad(); 
            if(k==reset)goto start;
            if( k<10)
              {  
              num2*=10;
              num2+=k;
              disp(num2,a,0,0);
              x++;
              k=undefined; 
              }                       
            } 
        while(k!=12);  
    x++;
    lcd_gotoxy(x,0);
    lcd_putsf("=");   
    if(z==1)       pasokh=num1+num2;
    else if(z==2)pasokh=num1-num2; 
    else if(z==3)pasokh=num1*num2;
    else if(z==4)pasokh=num1/num2; 
    disp(pasokh,0,1,3);   
    }
}