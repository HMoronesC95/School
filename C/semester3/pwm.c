#include <18F4550.h>
#device adc=8
#fuses XT,NOWDT,NOPROTECT
#use delay(clock=4000000)

int8 data_adc0, data_adc1;
void config_PWM();
void main ()
{
  setup_adc (ADC_CLOCK_INTERNAL);   
  setup_adc_ports (AN0_TO_AN1 | VSS_VDD);
  config_PWM();
  while(true)
  {
 
  set_adc_channel (0);    
  delay_us (100);
  data_adc0 = read_adc ();    
  set_adc_channel(1);
  delay_us(100);
  data_adc1 = read_adc ();
  set_pwm1_duty(data_adc0 );//MOTOR
  set_pwm2_duty(data_adc1 );//LED
  

  }
}

void config_PWM()
{
   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   setup_timer_2(T2_DIV_BY_16,749,4); 
}
