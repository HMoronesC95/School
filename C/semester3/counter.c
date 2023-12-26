#include<18f4550.h>
#device ADC = 10
#use delay(clock=4000000)
#fuses xt,nowdt,noprotect,noput
int var=0,i=0,dc=0,u=0;
int un=0,dec=0;// un= unidades. dec= decenas.
int vector[10]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};//definicion de los numero (0-9)
int vector2[1]={0x3f};//vector con solo el valor cero, que se colocara en el reset


void display1(int a, int b)//funcion para manual para automatico
{
   output_high(pin_c0);//mantiende ENCENDIDO el primer display, que sale del pin A1
   output_low(pin_c1);//mantiende APAGADO el primer display, que sale del pin A0
   output_B(vector[a]);//manda los datos del vector a los pines B
   delay_ms(10);//da un tiempo determinado de 10 mili segundos
   
   output_high(pin_c1);//mantiende APAGADO el primer display, que sale del pin A0
   output_low(pin_c0);//mantiende ENCENDIDO el primer display, que sale del pin A1
   output_B(vector[b]);//manda los datos del vector a los pines B
   delay_ms(10);//da un tiempo determinado de 10 mili segundos
}
void display2(int a, int b) //funcion para reset
{
   output_high(pin_c0);//mantiende ENCENDIDO el primer display, que sale del pin A1
   output_low(pin_c1);//mantiende APAGADO el primer display, que sale del pin A0
   output_B(vector2[a]);//manda los datos del vector a los pines B
   delay_ms(10);//da un tiempo determinado de 10 mili segundos
   
   output_high(pin_c1);//mantiende APAGADO el primer display, que sale del pin A0
   output_low(pin_c0);//mantiende ENCENDIDO el primer display, que sale del pin A1
   output_B(vector2[b]);//manda los datos del vector a los pines B
   delay_ms(10);//da un tiempo determinado de 10 mili segundos
}
void main()
{
   setup_adc(ADC_CLOCK_DIV_2);
   setup_adc_ports(AN0);
   set_tris_a(0x01);
   set_tris_b(0x00);
   set_tris_d(0xff);
   set_adc_channel(0);
   delay_us(10);

   
  while(true)//MIENTRAS SEA VERDADERO VA A ENTRAL CICLO INFINITO
  {
     /*if(input(PIN_d0)==1)//BOTON MANUAL SEA =1
     {
      var=1;
     } */
     if ((input(PIN_d1)==1))//BOTON AUTOMATICO SEA =2
     {
       var=2;
     }
     /*else if ((input(PIN_d2)==1))//BOTON RESET SEA =3
     {
       var=3;
     }*/
     
     switch(var)//escoge dependiendo de que boton fue presionado
     {

       
case 2://**BOTON AUTOMATICO**
{
      dc=dec;
      u=un;
      int16 adc1=0;
      int i=0;
 
       for(dec=dc; dec<10; dec++)//ciclo pra las decenas
       {
         
         for(un=u; un<10; un++)//ciclo para las unidades
         {
               
               
            for( i = 0;i <15; i++)//ciclo del tiempo
            {
               display1(dec,un);
               
           }//CIERRA FOR DE i
        
       }//CIERRA FOR DE UNIDADES
         u=0;//regresa el valor cero a las unidades despues del cambio de manual a automatico
         if(dec==9)
         {
         var=2;//vuelve a realizar el ciclo automatico
         dec=-1;//coloca el contador del automatico en 0 despues de realizar un ciclo (0-99)
         }
         
      }//CIERRA FOR DE DECENAs
   
break;
}//cierra case 2:
     
     }//cierra el switch
  
  }//termina el while(true)
 
}//termina main



