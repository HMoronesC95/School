#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC,noput
#use delay(clock = 4M)
#use fast_io(B)
int v1[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
   //           0    1    2   3     4    5    6    7    8   9
int v2[10] = {0x88,0xAF1,0x44,0x60,0x39,0x22,0x02,0xB8,0x00,0x30};//para c
//             0     1     2   3    4    5    6    7    8    9
int un=0,de=0,ce=0;
#INT_EXT 
ext_isr()
{   
  un++;
}
void main(){

 set_tris_b(0x01); 
 output_bit(PIN_B7,0);
 enable_interrupts(int_ext);
 ext_int_edge(H_TO_L);
 enable_interrupts(GLOBAL);
while (true){

output_d(v1[un]);
output_a(v1[de]);
output_e(v1[de]>>6);
output_c(v2[ce]);
if(un==10){de++; un=0;}
if(de==10) {ce++; de=0; un=0;}
if(ce==10){ce=0; de=0; un=0;}
}//cierra true
}//cierra main
