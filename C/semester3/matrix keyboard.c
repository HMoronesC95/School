#include <18f4550.h> //Archivo de definiciones del MCU
#FUSES NODEBUG,NOLVP,NOBROWNOUT,NOCPD,NOPROTECT,PUT,NOWDT,XT,NOWRT   //Debugger Mode - Desactivado
#use delay(clock=4000000) //Frecuencia del cristal para el c?lculo de los retardos
#define use_portb_kbd TRUE //Habilitamos la lectura del Teclado por el Puerto B
#include <KBD4x4.c> //Libreria para el manejo del teclado
 
#define Uno 0b00100001//0b11111001 //CARD
#define Dos 0b00001001//0b10100100 //NUMERAL
#define Tres 0b11000000//0b00110000 //CERO
#define CarA 0b00110110//0b00001000 //ASTERISCO
#define Cuatro 0b01000110//0b00011001 //CARC
#define Cinco 0b00011000//0b00010010 //NUEVE
#define Seis 0b00000000//0b00000010 //OCHO
#define CarB 0b01111000//0b00000011 //SIETE
#define Siete 0b00000011//0b01111000 //CARB
#define Ocho 0b00000010//0b00000000 //SEIS
#define Nueve 0b00010010//0b00011000 //CINCO
#define CarC 0b00011001//0b01000110 //CUATRO
#define Asterisco 0b00001000//0b00110110 //CARA
#define Cero 0b00110000//0b11000000 //TRES
#define Numeral 0b10100100//0b00001001 //DOS
#define CarD 0b11111001//0b00100001 //UNO
 
void Configura() { //Configura el microcontrolador para el hardware
   kbd_init();                    //Funcion para inicializar el uso del teclado
   port_b_pullups(TRUE); //Habilita las Resistecias Pull-up del Puerto B
   output_d(Tres);                //Limpia el puerto C
   set_tris_d(0x00);           //Puerto C como salidas
}
void main() {                    //Programa principal
char C, C2;                                    //Declaracion de la Variable "C" de tipo char
Configura();                    //Llama ala funcion Configura
output_c(Tres);
set_tris_c(0x00);
C = kbd_getc();
while(TRUE) {
           C2=C;
            switch ( C2 ) { //Selecciona y saca el valor de la tecla presionada
          case '0':
            output_c(Cero);
            break;
         case '1':
            output_c(Uno);
            break;
         case '2':
            output_c(Dos);
            break;
         case '3':
            output_c(Tres);
            break;
         case 'A':
            output_c(CarA); break;
         case '4':
            output_c(Cuatro); break;
         case '5':
            output_c(Cinco); break;
         case '6':
            output_c(Seis); break;
         case 'B':
            output_c(CarB); break;
         case '7':
            output_c(Siete); break;
         case '8':
            output_c(Ocho); break;
         case '9':
            output_c(Nueve); break;
         case 'C':
            output_c(CarC); break;
         case '*':
            output_c(Asterisco); break;
         case '#':
            output_c(Numeral); break;
         case 'D':
            output_c(CarD); break;
         default:
            break;} 
      C = kbd_getc();     //Escanea y regresa el valor de la tecla presionada, si ninguna tecla es presionada regresa un valor nulo ''
      switch ( C ) { //Selecciona y saca el valor de la tecla presionada
 
         case '0':
            output_d(Cero);
            break;
         case '1':
            output_d(Uno);
            break;
         case '2':
            output_d(Dos);
            break;
         case '3':
            output_d(Tres);
            break;
         case 'A':
            output_d(CarA); break;
         case '4':
            output_d(Cuatro); break;
         case '5':
            output_d(Cinco); break;
         case '6':
            output_d(Seis); break;
         case 'B':
            output_d(CarB); break;
         case '7':
            output_d(Siete); break;
         case '8':
            output_d(Ocho); break;
         case '9':
            output_d(Nueve); break;
         case 'C':
            output_d(CarC); break;
         case '*':
            output_d(Asterisco); break;
         case '#':
            output_d(Numeral); break;
         case 'D':
            output_d(CarD); break;
         default:
            break;}   
 }
} //Fin Programa principal

