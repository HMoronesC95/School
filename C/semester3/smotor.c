#include <18f4550.h>
#fuses xt,nowdt,noprotect,noput
#use delay(clock=4M)

void main()
{
   SET_TRIS_B(0B0000111);
   SET_TRIS_C(0B00000000);
   SET_TRIS_D(0B00000000);
   setup_timer_2(T2_DIV_BY_4,249,1);      

   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   while(TRUE)
   {
      //TODO: User Code
      
      if(input(pin_B1)==1  && input(pin_B2)==0 && input(pin_B3)==0){
      output_high(PIN_C1);
      set_pwm1_duty(500);
      output_high(PIN_C2);
      set_pwm2_duty(500);
      }
      
     else if(input(pin_B2)==1 && input(pin_B1)==0 && input(pin_B3)==0){
      output_high(PIN_C1);
      set_pwm1_duty(0);
      output_high(PIN_C2);
      set_pwm2_duty(0);
      }
      
      else if(input(pin_B3)==1 && input(pin_B1)==0 && input(pin_B2)==0){
      output_high(PIN_C1);
      set_pwm1_duty(1000);
      output_high(PIN_C2);
      set_pwm2_duty(1000);
      }
      
     
   }

}
