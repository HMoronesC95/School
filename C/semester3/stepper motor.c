#include<18f4550.h>
#device ADC = 10
#fuses xt,nowdt,noprotect,noput

#use delay(clock=4000000)

int vecA[4]={0x01,0x02,0x04,0x08}; //vector para definir el avanzar
int vecR[4]={0x08,0x04,0x02,0x01}; //vector para definir el regreso
void main()

{
int32 v=0,i,vel=0;

   
   for(;;)
   {
   setup_adc(ADC_CLOCK_DIV_2);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   delay_us(50);
   v =read_adc();
    delay_us(10);
   setup_adc_ports(AN0_TO_AN1);
   set_adc_channel(1);
   delay_us(50);
   vel =read_adc();
   
   if(v < 400)
   {
   for(i=0;i<4;i++)
   {
   output_b(vecR[i]);
   delay_ms(vel*2+500);
   }
   }
   else if(v>400 && v< 800)
   {
   output_d(0x00);
   }
   else if(v>800 )
   {
   for(i=0;i<4;i++)
   {
   output_b(vecA[i]);
   delay_ms(vel*2+500);
   }
   }
   
   
   }//true
   
   
   
   
}



      


