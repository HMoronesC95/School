#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
//int pasos[4]={0b1100,0b0110,0b0011,0b1001};
//int pasos[4]={0b1010,0b1001,0b0101,0b0110};
int pasos[4]={0b1000,0b0100,0b0010,0b0001};
void main(){
set_tris_b(0xff);
while(true){
for(int i=0; i<4; i++){
  output_b(pasos[i]);
  delay_ms(30);
}
}
}
//*/

//*/

