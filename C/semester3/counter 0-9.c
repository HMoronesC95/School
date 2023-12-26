#include <18F4550.h> 
//#fuses NOPROTECT, NOWDT,  NOFCMEN, PLL1, CPUDIV1, USBDIV
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)

void main(){
set_tris_c(0b00000001);
//if(input(pin_c0)){
while (true){
output_high(pin_b0);
output_high(pin_b5);
output_high(pin_b4);
output_high(pin_b3);
output_high(pin_b2);
output_high(pin_b1);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b5);
output_low(pin_b4);
output_low(pin_b3);
output_low(pin_b2);
output_low(pin_b1);
//1
output_high(pin_b1);
output_high(pin_b2);
delay_ms(500);
output_low(pin_b1);
output_low(pin_b2);

output_high(pin_b0);
output_high(pin_b1);
output_high(pin_b6);
output_high(pin_b4);
output_high(pin_b3);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b1);
output_low(pin_b6);
output_low(pin_b4);
output_low(pin_b3);

output_high(pin_b0);
output_high(pin_b1);
output_high(pin_b6);
output_high(pin_b2);
output_high(pin_b3);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b1);
output_low(pin_b6);
output_low(pin_b2);
output_low(pin_b3);

output_high(pin_b5);
output_high(pin_b6);
output_high(pin_b1);
output_high(pin_b2);
delay_ms(500);
output_low(pin_b5);
output_low(pin_b6);
output_low(pin_b1);
output_low(pin_b2);

output_high(pin_b0);
output_high(pin_b5);
output_high(pin_b6);
output_high(pin_b2);
output_high(pin_b3);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b5);
output_low(pin_b6);
output_low(pin_b2);
output_low(pin_b3);

output_high(pin_b0);
output_high(pin_b5);
output_high(pin_b6);
output_high(pin_b2);
output_high(pin_b3);
output_high(pin_b4);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b5);
output_low(pin_b6);
output_low(pin_b2);
output_low(pin_b3);
output_low(pin_b4);

output_high(pin_b0);
output_high(pin_b1);
output_high(pin_b2);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b1);
output_low(pin_b2);

output_high(pin_b0);
output_high(pin_b1);
output_high(pin_b2);
output_high(pin_b3);
output_high(pin_b4);
output_high(pin_b5);
output_high(pin_b6);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b1);
output_low(pin_b2);
output_low(pin_b3);
output_low(pin_b4);
output_low(pin_b5);
output_low(pin_b6);

output_high(pin_b0);
output_high(pin_b5);
output_high(pin_b6);
output_high(pin_b1);
output_high(pin_b2);
delay_ms(500);
output_low(pin_b0);
output_low(pin_b5);
output_low(pin_b6);
output_low(pin_b1);
output_low(pin_b2);
}//true
//}
}//mian
