#include <18f4550.h>
#fuses INTRC_IO, HS, NOPROTECT
#USE delay(cloclk=8M)
#define trig pin_B0
#define echo input(pin_B1)


//funcion para la distancia 
int16 mide_distancia(void)
{
   int16 centimetros;
   output_high(trig);
   delay_us(50);
   output_low(trig)
   while(echo==0);
   while(echo==1)
      {
      centimetros++;
      delay_us(58);
      }
   delay_ms(50);
   return(centimetros);
}
void main()
{
   int16 distancia;
   while (true)
   {
      distancia=mide_distancia();
      if (distancia>500)
      output_low(pin_c0);
      else
      output_high(pin_c0);
   }
}

