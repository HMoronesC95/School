#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
//int vector[10]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}
                //0      1    2    3    4    5    6    7    8    9
void main(){
set_tris_b(0b11111111);
set_tris_a(0b00000000);
set_tris_d(0b11111111);
while (true){
  if(input(pin_a0)==1 && input(pin_a1)==1 && input(pin_a2)==1 && input(pin_a3)==1)//cero
  {
  output_b(0x3f);
  output_d(0x3f);
  }
  if(input(pin_a0)==1 && input(pin_a1)==1 && input(pin_a2)==1 && input(pin_a3)==0)//1
  {
  output_b(0x3f);
  output_d(0x06);
  }
  if(input(pin_a0)==1 && input(pin_a1)==1 && input(pin_a2)==0 && input(pin_a3)==0)//2
  {
  output_b(0x3f);
  output_d(0x5B);
  }
  if(input(pin_a0)==1 && input(pin_a1)==1 && input(pin_a2)==0 && input(pin_a3)==1)//3
  {
  output_b(0x3f);
  output_d(0x4F);
  }
  if(input(pin_a0)==1 && input(pin_a1)==0 && input(pin_a2)==0 && input(pin_a3)==1)//4
  {
  output_b(0x3f);
  output_d(0x66);
  }
  if(input(pin_a0)==1 && input(pin_a1)==0 && input(pin_a2)==0 && input(pin_a3)==0)//5
  {
  output_b(0x3f);
  output_d(0x6D);
  }
  if(input(pin_a0)==1 && input(pin_a1)==0 && input(pin_a2)==1 && input(pin_a3)==0)//6
  {
  output_b(0x3f);
  output_d(0x7D);
  }
   if(input(pin_a0)==1 && input(pin_a1)==0 && input(pin_a2)==1 && input(pin_a3)==1)//7
  {
  output_b(0x3f);
  output_d(0x07);
  }
   if(input(pin_a0)==0 && input(pin_a1)==0 && input(pin_a2)==1 && input(pin_a3)==1)//8
  {
  output_b(0x3f);
  output_d(0x7F);
  }
   if(input(pin_a0)==0 && input(pin_a1)==0 && input(pin_a2)==1 && input(pin_a3)==0)//9
  {
  output_b(0x3f);
  output_d(0x67);
  }
   if(input(pin_a0)==0 && input(pin_a1)==0 && input(pin_a2)==0 && input(pin_a3)==0)//10
  {
  output_b(0x06);
  output_d(0x3f);
  }
   if(input(pin_a0)==0 && input(pin_a1)==0 && input(pin_a2)==0 && input(pin_a3)==1)//11
  {
  output_b(0x06);
  output_d(0x06);
  }
   if(input(pin_a0)==0 && input(pin_a1)==1 && input(pin_a2)==0 && input(pin_a3)==1)//12
  {
  output_b(0x06);
  output_d(0x5B);
  }
   if(input(pin_a0)==0 && input(pin_a1)==1 && input(pin_a2)==0 && input(pin_a3)==0)//13
  {
  output_b(0x06);
  output_d(0x4F);
  }
   if(input(pin_a0)==0 && input(pin_a1)==1 && input(pin_a2)==1 && input(pin_a3)==0)//14
  {
  output_b(0x06);
  output_d(0x66);
  }
   if(input(pin_a0)==0 && input(pin_a1)==1 && input(pin_a2)==1 && input(pin_a3)==1)//cero
  {
  output_b(0x06);
  output_d(0x6D);
  }
}//cierra true
}//cierra main
