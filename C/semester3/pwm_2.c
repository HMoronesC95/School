#include<18f4550.h>
#device ADC = 10
#fuses xt,nowdt,noprotect,noput
#use delay(clock=4M)
int16 adcA=0;
void main()
{//
  setup_adc(adc_clock_div_2);
  setup_adc_ports(AN0);
  setup_timer_2(t2_div_by_4,250,4);
  setup_ccp1(CCP_PWM | CCP_PWM_HALF_BRIDGE);
  setup_adc_ports(AN0);
  setup_adc(adc_clock_internal);
  
  for(;;)
  {
  set_adc_channel (0);    
  delay_us (100);
  adcA = read_adc (); 
  set_pwm1_duty(adcA );

  
  }
}//C.void main


