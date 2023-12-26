#include <18F4550.h>
#fuses NOWDT,NOPROTECT,INTRC
#use delay(clock=8000000)
#use spi(SLAVE, DI=PIN_B0, DO=PIN_C7, CLK=PIN_B1, FORCE_HW, BITS=8)
//#use spi(SLAVE, FORCE_HW, BAUD=1000000, MSB_FIRST, BITS=8)

int8 data=0, aux=0, i=0;
void main()
{

   for(int i=0;i<15;i++)
   {
output_toggle(pin_a1);
delay_ms(200);
   }
output_low(pin_a1);
   while(true){ 

      if(spi_data_is_in()) 
         {           
            data = spi_read(); 
            
            if(data == '9')
               {
               output_high(PIN_A1);
               delay_ms(1000);
               output_low(PIN_A1);
               }
            else
               output_low(PIN_A1); 
          }
    }
} 
