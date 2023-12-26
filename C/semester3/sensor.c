#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
void main(){
set_tris_b(0b00000001);
while(true){
if (input(pin_b0)==1){
output_high(pin_b1);

}
if (input(pin_b0)==0){
output_low(pin_b1);

}
}
}
