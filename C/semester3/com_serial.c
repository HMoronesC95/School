#include<18f4550.h>
#device ADC = 10
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC
#use delay(clock=8M)
#use rs232(rcv=pin_c7,xmit=pin_c6,baud=9600,bits=8,parity=n)
#INT_EXT
ext_isr()
{
int contador=1;
 printf("se presiono boton\n\r");
}
void main(){
//set_tris_b();
char n;

 port_b_pullups(TRUE);
 enable_interrupts(int_ext);
 ext_int_edge(L_TO_H);
 enable_interrupts(GLOBAL);
while(true){
printf("a) para encender led\r\nb) Para apagar led\r\n");

n=getch();
switch(n){
case 'a':
printf("encendido\r\n");
output_high(pin_b1);
break;
case 'b':
printf("apagado");
output_low(pin_b1);
break;
default:
printf("NO HAY OPCION\\n\r");
break;
}


}
}
