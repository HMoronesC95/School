#include <18F4550.h> 
#device adc=10 
#fuses NOPROTECT, NOWDT,  NOFCMEN, PLL1, CPUDIV1, USBDIV  
#use delay(internal) 

int8 q=0;

#INT_AD
void interrupt()
{
   q=read_adc();       
} 
 
void main() 
{  

   set_tris_b(0b00000001);
   set_tris_d(0b01111111);
   
   setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(12);
   
   enable_interrupts(INT_AD );    
   enable_interrupts(GLOBAL); 
   
  
   
    
   while(1) 
   { 
      output_d(q);
      delay_ms(500);
      output_d(q>>=1);
      delay_ms(500);
   }//fin del ciclo infinito
}//fin del main  
