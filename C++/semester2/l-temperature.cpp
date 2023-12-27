#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()

  {int x=0;
    float y=0,z=0;
  cout<<"Conversion de grados Centigrados a grados Fahrenheit, o viceversa con decimales.\n";
  cout<<"Ingresa 1 para convertir Centigrados a Fahrenheit, 2 para convertir de Fahrenheit a Centigrados:";
  cin>>x;
  system("cls");
  if (x==1){
  cout<<"Ingresa la temperatura en Centigrados: ";
  cin>>y;
  z=y;
  y=y*1.8+32;
  cout<<"La temperatura "<<z<<" Centigrados son "<<y<<" Fahrenheit.";
  }
  else if(x==2){
  cout<<"Ingresa la temperatura en Fahrenheit: ";
  cin>>y;
  z=y;
  y=(y-32)*5/9;
  cout<<"La temperatura "<<z<<" Fahrenheit son "<<y<<" Centigrados.";
  }
  else
    cout<<"El valor ingresado no es valido.";
  }

