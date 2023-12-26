#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
#use standard_io(B)
int v1[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
   //           0    1    2   3     4    5    6    7    8   9
int contador,retraso=100;
int cont=0;
#int_TIMER0
void TIMER0_isr(void)
{
  output_b(v1[contador]);
  set_timer0 (0x1B);
  contador ++;
  if(input(pin_c0)==1)
  {
  //retraso= retraso+400;
  cont++;
  if(cont==0){retraso = 100;}
  if(cont==1){retraso = 500;}
  if(cont==2){retraso = 100; cont = 0;}
  }
  if(contador==10){contador=0;}
  delay_ms(retraso);
}
void main()
{
  setup_timer_0(RTCC_INTERNAL | RTCC_DIV_2);
  set_timer0 (0x1b);
  enable_interrupts(INT_TIMER0);
  enable_interrupts(global);
  while(true){}
}
