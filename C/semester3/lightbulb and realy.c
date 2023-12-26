#include <18F4550.h> 
//#fuses NOPROTECT, NOWDT,  NOFCMEN, PLL1, CPUDIV1, USBDIV
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)

void main(){
   int1 A; 
   while(true)
   {  
      A=input(pin_d0);
      if(A==1)
      {
         output_high(pin_d1);

      }
   }
}
