#include <18f4550.h>
#device ADC = 10 //conveciones a 10 bits
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)

void main(){
set_tris_b(0xff);
  setup_adc(adc_clock_div_2);
  setup_adc_ports(AN0);
  setup_adc(adc_clock_internal);
  int16 adc, result, faltantes;
while(true){

  set_adc_channel (0);    
  delay_us (100); 
  adc = read_adc ();
  result = adc;
  faltantes = result>>8;
  output_b(result);
  output_c(faltantes);
  delay_ms(50);
  
}//true
}//main
