#include <18F4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock=4000000)
//#use spi(SLAVE, DI=PIN_B0, DO=PIN_C7, CLK=PIN_B1, FORCE_HW, BITS=8)
#use spi(SLAVE, FORCE_HW, BAUD=1000000, MSB_FIRST, BITS=8)
#include <lcd.c>
#include <stdlib.h>

int8 data=0, aux=0, i=0;
void main()
{

   while(true){   

      if(spi_data_is_in()) 
         {           
            data = spi_read(); 
            output_d(data);
            
            if(data == '2')
               {
               output_high(PIN_A1);
               //aux=0x05<<1;
               spi_write(i);
               i++;
               //while(!spi_data_is_in());
               //data = spi_read();
               }
            else
               output_low(PIN_A1); 
          }
    }
} 

