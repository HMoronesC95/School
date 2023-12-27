#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()
{
   float a,b,c,d,m,hipotenusa,catetox,catetoy;
   cout<<"Dadas dos coordenadas P y Q en un plano, encontraremos la distancia y la pendiente entre ellas, asi como el valor de sus componentes."<<"\n";
   system("pause");
   cout<<"Ingresa el valor x de la coordenada P:"<<"\n";
   cin>>a;
   cout<<"Ingresa el valor y de la coordenada P:"<<"\n";
   cin>>b;
   cout<<"Ingresa el valor x de la coordenada Q:"<<"\n";
   cin>>c;
   cout<<"Ingresa el valor y de la coordenada Q:"<<"\n";
   cin>>d;
   system("pause");
    system("cls");

    catetox=c-a,catetoy=d-b,hipotenusa=sqrt(catetox*catetox+catetoy*catetoy),m=catetoy/catetox;
    cout<<"La distancia entre las coordenadas es:"<<hipotenusa<<"\n";
    cout<<"La pendiente es:"<<m<<"\n";
    cout<<"La componente en x es:"<<catetox<<"\n";
    cout<<"La componente en y es:"<<catetoy<<"\n";

}
