#include<18f4550.h>
#device ADC = 10
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC
#use delay(clock=8M)
#use rs232(rcv=pin_c7,xmit=pin_c6,baud=9600,bits=8,parity=n)

void main()
{
char opp,op1,x;
int y;
int16 adc,ad;
setup_timer_2(t2_div_by_4,250,4);
setup_ccp1(CCP_PWM);
while(true)
{
salir1:
salir2:
y=0;
printf("a>Tipo para regular el foco\r\na>Serialmente\r\nb>Potenciometro\r\n");
opp=getch();
switch(opp)
{
case 'a'://SERIAL
while(true){
  
printf("a\r\nSeleccione la intencidad de la bomnilla\r\n");
printf("a>intensidad 1\r\nb>intensidad 2\r\nc>intensidad 3\r\nd>intensidad 4\r\ne>intensidad 5\r\nf>intensidad 6\r\n");
printf("g>intensidad 7\r\nh>intensidad 8\r\ni>intensidad 9\r\nj>Apagar\r\nk>para salir\r\n");
op1=getch();
switch(op1){

case 'a'://intensidad 1
printf("\n\ra>Intensidad de 11 porciento\r\n\n\r");
set_pwm1_duty(20);
break;

case 'b':
printf("\n\rb>Intensidad de 22 porciento\r\n\n\r");
set_pwm1_duty(41);
break;

case 'c':
printf("\n\rc>Intensidad de 44 porciento\r\n\n\r");
set_pwm1_duty(100);
break;

case 'd':
printf("\n\rd>Intensidad de 55 porciento\r\n\n\r");
set_pwm1_duty(452);
break;

case 'e':
printf("\n\re>Intensidad de 66 porciento\r\n\n\r");
set_pwm1_duty(565);
break;

case 'f':
printf("\n\rf>Intensidad de 77 porciento\r\n\n\r");
set_pwm1_duty(678);
break;

case 'g':
printf("\n\rg>Intensidad de 88 porciento\r\n\n\r");
set_pwm1_duty(791);
break;

case 'h':
printf("\n\rh>Intensidad de 99 porciento\r\n\n\r");
set_pwm1_duty(904);
break;

case 'i':
printf("\n\ri>Intensidad de 100 porciento\\r\n\n\r");
set_pwm1_duty(1023);
break;

case 'j':
printf("\n\r**APAGADO**\n\n\r");
set_pwm1_duty(0);
break;

case 'k':
printf("\n\rk\r\n");
if(op1 == 'k'){
goto salir1;
}
break;

default:
printf("\n\r\n\r**ERROR NO EXISTE LA OBCION**\r\n\n\r");
break;
}//cierra switch op1
}//cierra while true del caso a serial


break;
case 'b'://POTENCIOMETRO
printf("Presione 'z' para salir\r\n");
while(true)
{
if(y==1){goto salir2;}
//printf("Presione 'z' para salir\r\n");
setup_adc(adc_clock_div_2);
  setup_adc_ports(AN0);
  setup_timer_2(t2_div_by_4,250,4);
  setup_ccp1(CCP_PWM );
  setup_adc_ports(AN0);
  setup_adc(adc_clock_internal);
while(true){
if(opp == 'b'){
do{

if(kbhit()){
 x=getch();
 y=1;
 }
   
    else 
    {
   set_adc_channel (0);    
  delay_us (100);
  adc = read_adc (); 
  set_pwm1_duty(adc );
  ad=adc;
  printf("LA LECTURA ES: %ld\r\n", ad);
  printf("presione 'z' para salir\r\n");
  delay_ms(1000);
    }

}while(x != 'z');//cierra do
  break;
}//cierra if opp b
}//cierra while true b potenciometro
}//cierra while de la opcion b
break;

default:
printf("\r\n\r\n**ERROR NO ES OPCION**\r\n\r\n");
break;
}//cierra switch

}//cierra 1er while true
}//cierra main
