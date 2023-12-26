#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
void main(){
set_tris_b(0x00001111);
//int vecA[4]={0x01,0x02,0x04,0x08}; //vector para definir el avanzar
int vecA[4]={0b0001,0b0010,0b0100,0b1000};
while(true){
if(input(pin_b4)==1){
while(true){
 for(int i=0; i<4; i++)
 {
 output_b(vecA[i]);
 delay_ms(90);
 }
}
}
}
}
