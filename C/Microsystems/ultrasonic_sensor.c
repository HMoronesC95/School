#include  <18f4550.h>
#FUSES    NOWDT,NOPROTECT,INTRC       
#use      delay(clock=8000000)
#define LCD_ENABLE_PIN  PIN_E0                                    ////
#define LCD_RS_PIN      PIN_E1                                    ////
#define LCD_RW_PIN      PIN_E2                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7 
#include <lcd.c>

unsigned int16 i;
int8 distancia_deseada=18,distancia_sensor=0;
float distance=0;

void main()
{
   lcd_init();
   
   setup_ccp1(ccp_pwm);
   setup_ccp2(ccp_pwm);
   setup_timer_2(T2_DIV_BY_1,255,1);   

   
   setup_timer_1 (T1_INTERNAL | T1_DIV_BY_2);
   set_timer1(0);

   while(TRUE)
   {   
          output_high(PIN_D0);
          delay_us(10);
          output_low(PIN_D0);
          set_timer1(0);
           i=0;
          while(!input(PIN_D1) && (get_timer1() < 1000));        
          while(input(PIN_D1) && (i < 25000)) 
          {i = get_timer1();}
    //      if(i < 24990)// fuera de rango 
          distance = 0.0171*i-8.0196;   
          distancia_sensor=distance;
          
          if(distance<=3)
            distance=3;
          else if(distance>=50)
            distance=50;
      
      if(distancia_deseada>distancia_sensor)
         {
          set_pwm1_duty(1023);
          set_pwm2_duty(255);   
  
          output_high(pin_d3);  
         }
      else if(distancia_deseada<distancia_sensor)
         {
         output_high(pin_d3); 
         }
      else 
         output_low(pin_d3);
      
      printf(lcd_putc,"\fhola\n%.0f",distance);   
      
      delay_ms(100);
      
   }//fin del ciclo infinito
}//fin del main
