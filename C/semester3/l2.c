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
     if(input(PIN_d0)==1)//BOTON MANUAL SEA =1
     {
      var=1;
     } 
     else if ((input(PIN_d1)==1))//BOTON AUTOMATICO SEA =2
     {
       var=2;
     }
     else if ((input(PIN_d2)==1))//BOTON RESET SEA =3
     {
       var=3;
     }
     
     switch(var)//escoge dependiendo de que boton fue presionado
     {
case 1://**BOTON MANUAL** 
{
   
    if(input(PIN_d0))
     {
         if(un<9)//si el numero sigue siendo menor de 9 aumentaran las unidades de 1 en 1    
            un++;
         else//cuando ya no cumpla las unidades tomaran el valor 0
          {
           un=0;
         if(dec<9)//si el numero sigue siendo menor de 9 aumentaran las decenas de 1 en 1
            dec++;
         else//cuando ya no cumplan las unidades tomaran el valor de 0
            dec=0;
          }
         
     
     
         while(input(pin_d0)==0);//mientras siga el boton presionado no abra ningun cambio
         {
         while(input(pin_d0)==1)
         {
          display1(dec,un);
         }
         }
}
 
         if(input(PIN_d1))/* si se oprime el pin d1 se mandara el caso 2 donde
         los numeros correran automaticamnete*/
         {
            var=2;
         }
         else if(input(PIN_d2))/* si se oprime el pin d2 se mandara el caso 3 donde
         los numeros llegaran al reset y solo se mostraran los 0s*/
         {
            var=3;
         }
         display1(dec,un);
break;//cierra el caso 1  
 
}//cierra case 1:
   
       
case 2://**BOTON AUTOMATICO**
{
      dc=dec;
      u=un;
      int16 adc1=0;
      int i=0;
      int32 V=0;
   
       
       
      
       for(dec=dc; dec<10; dec++)//ciclo pra las decenas
       {
         
         for(un=u; un<10; un++)//ciclo para las unidades
         {
               set_adc_channel(0);  // se manda llamar al adc;
               delay_us(10);  // 
               adc1=read_adc(); //se guarda el valor del ADC en la variable volt
                  // yo le puse este incremento a la velocidad pero puedes poer vel=vol;
               if((adc1>=0)&&(adc1<250))
               {
                  V=5;   
               }
               else if((adc1>250)&&(adc1<500))
               {
                   V=10;
               }
               else if((adc1>750)&&(adc1<1024))
               {
                   V=15;
               }
               
         
         
         
            for( i = 0;i <V; i++)//ciclo del tiempo
            {
               display1(dec,un);
               
        if(input(PIN_d0))/*si se oprime el pin d0 se mandara el caso 1 donde
         los numeros regrearan a ser controlados manualmente*/
        {
            var=1;         
        }
        if(input(pin_d2))/* si se oprime el pin d2 se mandara el caso 3 donde
         los numeros llegaran al reset y solo se mostraran los 0s*/
        {
           var=3;
        }
        
                 
           }//CIERRA FOR DE i
         if(var==1 || var==3)/*verifica ambos casos y si lguno de los dos se cumple 
         se saldra del ciclo de las unidades*/
         {
                 break;
         }
         }//CIERRA FOR DE UNIDADES
         if(var==1 || var==3)/*verifica ambos casos y si lguno de los dos se cumple 
         se saldra del ciclo de las decenas*/
         {
                 break;
         }
         u=0;//regresa el valor cero a las unidades despues del cambio de manual a automatico
         if(dec==9)
         {
         var=2;//vuelve a realizar el ciclo automatico
         dec=-1;//coloca el contador del automatico en 0 despues de realizar un ciclo (0-99)
         }
         
      }//CIERRA FOR DE DECENAs
   
break;
}//cierra case 2:
     
case 3://**BOTON RESET**
{
     if(input(PIN_d2))
       display2(dec,un);//muestra los ceros despues de resionar automatico
       un=0;//regresa el valor 0 a las unidades
       dec=0;//regresa el valor 0 a las decenas
              
      if(input(PIN_d0))//regresa al manual
      {
      var=1;
      un=0;
      dec=0;
      }
      
      else if(input(PIN_d1))//regresa al automatico
      {
      var=2;
      un=0;
      dec=0;
      }
      display1(dec,un);
     break;
}//cierra el case 3
     
     }//cierra el switch
  
  }//termina el while(true)
 
}//termina main
