#include <18F4550.h> 
//#fuses NOPROTECT, NOWDT,  NOFCMEN, PLL1, CPUDIV1, USBDIV
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC
#use delay(clock = 4M)

void main(){
SET_TRIS_B(0X7F);
while(true){

if(input(pin_b0)==1)
{
while(input(pin_b0)==0){

output_high(pin_b1);
delay_ms(50);
output_low(pin_b1);
delay_ms(50);

output_high(pin_b2);
delay_ms(50);
output_low(pin_b2);
delay_ms(50);

output_high(pin_b3);
delay_ms(50);
output_low(pin_b3);
delay_ms(50);

output_high(pin_b4);
delay_ms(50);
output_low(pin_b4);
delay_ms(50);

output_high(pin_b5);
delay_ms(50);
output_low(pin_b5);
delay_ms(50);

output_high(pin_b6);
delay_ms(50);
output_low(pin_b6);
delay_ms(50);

output_high(pin_b6);
delay_ms(50);
output_low(pin_b6);
delay_ms(50);

output_high(pin_b5);
delay_ms(50);
output_low(pin_b5);
delay_ms(50);

output_high(pin_b4);
delay_ms(50);
output_low(pin_b4);
delay_ms(50);

output_high(pin_b3);
delay_ms(50);
output_low(pin_b3);
delay_ms(50);

output_high(pin_b2);
delay_ms(50);
output_low(pin_b2);
delay_ms(50);

output_high(pin_b1);
delay_ms(50);
output_low(pin_b1);
delay_ms(50);
}//==0
}//==1


}//cierra true
}//cierra main
