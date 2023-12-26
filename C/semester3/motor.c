#include <18F4550.h> 
//#fuses NOPROTECT, NOWDT,  NOFCMEN, PLL1, CPUDIV1, USBDIV
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC
#use delay(clock = 4M)

void main(){
SET_TRIS_C(0x01);
while(true){
if(input(pin_c1)==1){
output_high(pin_c0);
}
if(input(pin_c2)){
output_low(pin_c0);
}


}//cierra true
}//cierra main


