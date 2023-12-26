#include <18F4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock=4000000)
//#use spi(MASTER, DI=PIN_B0, DO=PIN_C7, CLK=PIN_B1, ENABLE=PIN_B2, FORCE_HW, BAUD=1000000, BITS=8)
#use spi(ENABLE=PIN_B2, FORCE_HW, BAUD=1000000, MSB_FIRST, BITS=8)
#define LCD_DATA_PORT getenv("SFR:PORTD")
#include <lcd.c>
int8 receivedData=0;
void main()
{

   while(true){   
            lcd_init();
            output_low(PIN_B2); 
            //delay_ms(500);
            spi_write('2'); 
            while(!spi_data_is_in());
            receivedData = spi_read();
            output_high(PIN_B2); 
            //delay_ms(500);
            printf(lcd_putc,"\fData: %d",receivedData);
            delay_ms(200);
  

   }
}


            
