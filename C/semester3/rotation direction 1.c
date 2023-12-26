#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
void main(){
set_tris_b(0b11111100);

while (true){
 if(input(pin_b0))
 { 
 output_low(pin_b3);
 delay_ms(20);
 output_high(pin_b2);
 }
 if(input(pin_b1))
 {
  output_low(pin_b2);
  delay_ms(20);
  output_high(pin_b3);
 }
}
}
