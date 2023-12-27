#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;


//Problema 1---------------------------------------------------------------
int doble(int);
int cuadrado(int);

int main()
{ int x;
    cout<<"Introduzca un numero para calcular su doble y su cuadrado: ";
    cin>>x;
    cout<<"\nEl doble de "<<x<<" es "<<doble(x);
    cout<<"\nEl cuadrado de "<<x<<" es "<<cuadrado(x)<<"\n\n";
}
doble(int a)
{
    a=2*a;
 return a;
}
cuadrado(int a)
{
    a=a*a;
 return a;
}
//


/*/Problema 2--------------------------------------------------------------------------------
int isdigit(char);
int main()
{
    char x;
     cout<<"Introduzca un numero o un caracter: ";
     cin>>x;
     if(isdigit(x)==1)
        cout<<x<<" es un numero.\n\n";
     else if(isdigit(x)==0)
        cout<<x<<" es un caracter.\n\n";
}
isdigit(char a)
{
    if(a>=48 && a<=57)
        return 1;
    else return 0;
}
/*/


/*/Problema 3--------------------------------------------------------------------------------
int mayor(int,int,int);
int menor(int,int,int);
int main()
{ int x=0,y=0,z=0;

        cout<<"Ingresa un numero: ";
        cin>>x;
        cout<<"Ingresa un segundo numero: ";
        cin>>y;
        cout<<"Ingresa un tercer numero: ";
        cin>>z;
   cout<<"\nEl numero mayor es "<<mayor(x,y,z);
   cout<<"\nEl numero menor es "<<menor(x,y,z)<<"\n\n";;
}
mayor(int x,int y,int z)
{
    if(x>y && x>z)
        return x;
    else if(y>x && y>z)
        return y;
    else return z;
}
menor(int x,int y,int z)
{
    if(x<y && x<z)
        return x;
    else if(y<x && y<z)
        return y;
    else return z;
}
/*/


/*/Problema 4--------------------------------------------------------------------------------
int main()
{ int x,aux=0,i=1,j=0;
    cout<<"Ingresa un numero: ";
    cin>>x;

    while(x/i!=0)
    {   aux++;
        i=10*i;
    }
    j=aux;
    aux=1;
   for(i=1;i<j;i++){
      aux=10*aux;
   }
   i=1;
   while(x/i!=0)
   {
     cout<<x/aux<<"\n";
     x=x-(x/aux)*aux;
     aux=aux/10;
   }
}
/*/

