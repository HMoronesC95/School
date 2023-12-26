#include <18f4550.h>
#device ADC = 10 //conveciones a 10 bits
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
#INT_EXT
ext_isr()
{
 output_toggle(pin_B7);
}
void main()
{
 set_tris_b(0x01);
 output_bit(PIN_B7,0);
 port_b_pullups(TRUE);
 enable_interrupts(int_ext);
 ext_int_edge(L_TO_H);
 enable_interrupts(GLOBAL);
 while(1)
 {
 }
} 
