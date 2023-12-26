#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
//#use standar_io(b)
int v1[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
   //           0    1    2   3     4    5    6    7    8   9
int v2[10] = {0x88,0xAF1,0x44,0x60,0x39,0x22,0x02,0xB8,0x00,0x30};
//             0     1     2   3    4    5    6    7    8    9

int us=0,ds=0,um=0,dm=0;
#int_TIMER1
void templs(void)
{ 
//output_c(0x77);
//*/
  output_c(v2[dm]);
  output_a(v1[um]);
  output_e(v1[um]>>6);
  output_b(v1[ds]);
  output_d(v1[us]);
  us= us+1 ;
  if(us==10){us=0; ds++;}
  if(ds==6){ds=0; us = 0; um++;}
  if(um==10){um=0; dm++;}
  if(dm == 6){dm=0; um=0; ds=0; us=0;}
  delay_ms(530);
  //*/
 
}

void main(){
setup_timer_1 (T1_INTERNAL | T1_DIV_BY_8);
set_timer1 (3036);
enable_interrupts (INT_TIMER1);
enable_interrupts(global); //interrupcion global
while (true){

}
}//cierra main

