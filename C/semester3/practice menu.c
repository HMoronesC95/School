#include<18f4550.h>
#device ADC = 10
#fuses XT,NOWDT,NOPROTECT,NOLVP,CPUDIV1,PLL5,INTRC
#use delay(clock=8M)
#use rs232(rcv=pin_c7,xmit=pin_c6,baud=9600,bits=8,parity=n)

void main()
{
char n, o, m, m1, opc;
int u, d, u1, d1, t;
int16 adcA;
while(true)
{
printf("\r\ningrese la opcion:\r\nDISPLAY 'a': \r\nMOTOR 'b'\r\nADC 'c'\r\n");
n=getch();
switch(n){
case 'a':

 output_high(pin_a1);
 output_B(0x3f);
 delay_ms(10);
 output_high(pin_a2);
 output_D(0x3f);
 delay_ms(10);
 
 while (true){//abre while true
printf("a\r\n");
printf("INGRESE DECENA: ");
u=getch();
printf("\r\n");
printf("INGRESE UNIDAD: ");
d=getch();
printf("\r\n");
//printf("el valor en unidad es: %d",u);

if(u == 48){
u1=0x3f;
}
if(d == 48){
d1=0x3f;
}
if(u == 49){
u1=0x06;
}
if(d == 49){
d1=0x06;
}
if(u == 50){
u1=0x5B;
}
if(d == 50){
d1=0x5B;
}
if(u == 51){
u1=0x4F;
}
if(d == 51){
d1=0x4F;
}
if(u == 52){
u1=0x66;
}
if(d == 52){
d1=0x66;
}
if(u == 53){
u1=0x6D;
}
if(d == 53){
d1=0x6D;
}
if(u == 54){
u1=0x7D;
}
if(d == 54){
d1=0x7D;
}
if(u == 55){
u1=0x07;
}
if(d == 55){
d1=0x07;
}
if(u == 56){
u1=0x7F;
}
if(d == 56){
d1=0x7F;
}
if(u == 57){
u1=0x67;
}
if(d == 57){
d1=0x67;
}

 output_high(pin_a1);
 output_B(d1);
 delay_ms(10);
 output_high(pin_a2);
 output_D(u1);
 delay_ms(10);
 
 
 printf("\r\n 'a'= MENU PRINCIPAL:\r\nOTRA TECLA PARA CONTINUAR\r\n");
 o=getch();
 if( o == 'a'){
 output_low(pin_b0);
 delay_ms(1);
 output_low(pin_b1);
 delay_ms(1);
 output_low(pin_b2);
 delay_ms(1);
 output_low(pin_b3);
 delay_ms(1);
 output_low(pin_b4);
 delay_ms(1);
 output_low(pin_b5);
 delay_ms(1);
 output_low(pin_b6);
 delay_ms(1);
 //output_low(pin_b7);
 //delay_ms(1);
 
 output_low(pin_d0);
 delay_ms(1);
 output_low(pin_d1);
 delay_ms(1);
 output_low(pin_d2);
 delay_ms(1);
 output_low(pin_d3);
 delay_ms(1);
 output_low(pin_d4);
 delay_ms(1);
 output_low(pin_d5);
 delay_ms(1);
 output_low(pin_d6);
 delay_ms(1);
 //output_low(pin_d7);
 //delay_ms(1);
 
 break;
 }

 }//CIERRA while true
 
 break;
 
 case 'b': //caso del motor
 printf("'b'\r\n");
 printf("MOTOR\r\n");
 salirm:
 m='l';
 printf("'a'.-GIRO DERECHA BAJO\r\n'b'.-GIRO DERECHA ALTO\r\n'c'.-GIRO IZQUIERDA BAJO\r\n'd'.-GIRO IZQUIERDA ALTO\r\n");
 m=getch();
 switch(m){
 
 case 'a'://GIRO DERECHA BAJO
 printf("'a'\r\n");
  setup_timer_2(t2_div_by_4,250,4);
  setup_ccp2(CCP_PWM );
  while(true){//abre while true
  set_pwm2_duty(50);
  printf("s = menu principal\r\n'z' = menu del motor\r\n");
  m1=getch();
  if(m1 == 's'){
  printf("'s'\r\n");
  CCP_2_LOW = getenv("SFR:CCPR2L") ;//apaga motor
   break;
  }
  if(m1 == 'z'){
   printf("'z'\r\n");
  CCP_2_LOW = getenv("SFR:CCPR2L") ;//apaga motor
  goto salirm;
  }
  }//cierra while true
 break;
 
 case 'b'://GIRO DERECHA ALTO
 printf("'b'\r\n");
 setup_timer_2(t2_div_by_4,125,4);
  setup_ccp2(CCP_PWM );
  while(true){//abre while true
  set_pwm2_duty(10);
  printf("s = menu principal\r\n'z' = menu del motor\r\n");
  m1=getch();
  if(m1 == 's'){
  printf("'s'\r\n");
  CCP_2_LOW = getenv("SFR:CCPR2L") ;//apaga motor
   break;
  }
  if(m1 == 'z'){
   printf("'z'\r\n");
  CCP_2_LOW = getenv("SFR:CCPR2L") ;//apaga motor
  goto salirm;
  }
  }//cierra while true
 break;
 
 case 'c'://GIRO IZQUIERDA BAJO
 printf("'c'\r\n");
 setup_timer_2(t2_div_by_4,125,4);
  setup_ccp1(CCP_PWM );
  while(true){//abre while true
  set_pwm1_duty(50);
  printf("s = menu principal\r\n'z' = menu del motor\r\n");
  m1=getch();
  if(m1 == 's'){
  printf("'s'\r\n");
  CCP_1_LOW = getenv("SFR:CCPR2L") ;//apaga motor
   break;
  }
  if(m1 == 'z'){
   printf("'z'\r\n");
  CCP_1_LOW = getenv("SFR:CCPR2L") ;//apaga motor
  goto salirm;
  }
  }//cierra while true
 break;
 
 case 'd'://GIRO IZQUIERDA ALTO
 printf("'d'\r\n");
 setup_timer_2(t2_div_by_4,125,4);
  setup_ccp1(CCP_PWM );
  while(true){//abre while true
  set_pwm1_duty(10);
  printf("s = menu principal\r\n'z' = menu del motor\r\n");
  m1=getch();
  if(m1 == 's'){
  printf("'s'\r\n");
  CCP_1_LOW = getenv("SFR:CCPR2L") ;//apaga motor
   break;
  }
  if(m1 == 'z'){
   printf("'z'\r\n");
  CCP_1_LOW = getenv("SFR:CCPR2L") ;//apaga motor
  goto salirm;
  }
  }//cierra while true
 break;
 
 default:
 printf("NO EXISTE LA OBCION\r\n");
 break;
 }//cierra switch()
 
 break;
case 'c':
printf("'c'\r\n");
printf("ADC\r\n");
printf("1 = 49 hasta 9 = 57\r\n");
printf("para salir oprima 'z'\r\n");
printf("INGRESE EL INTERVALO DE TIEMPO en mili-segundos DE 1 - 9\r\n");
t=getch();//recordando que el valor obtenido es ascii*/
printf("tiempo de %d x 4 n",t);
//printf("SALIR AL MENU DEL ADC: 's'\r\nSALIR AL MENU PRINCIPAL: 'z'");
  setup_adc(adc_clock_div_2);
  setup_adc_ports(AN0);
  setup_adc(adc_clock_internal);
  int16 ad;
  opc=0;
while(true){
    if(n == 'c'){
   do{
   
   if(kbhit()){
    opc=getch();}
          
         else{
   set_adc_channel (0);    
  delay_us (100); 
  adcA = read_adc ();
  ad=adcA;
  printf("LA LECTURA ES: %ld\r\n", ad);
  delay_ms(t*5);
          }
   }while(opc != 'z');
   break;
    }//cierra if n==c
  
}

break;
 
 default: printf("NO EXISTE LA OBCION\r\n");
 break;
}//cierra switch(n)

}//cierra true
}//cierra main
