#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int x=0,a=500,b=200,c=100,d=50,e=10,f=5,g=2,h=1,A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0;

    cout<<"Ingresa una cantidad como maximo 5000 gramos.\n";
    cout<<"Cantidad:";
    cin>>x;
if(x>5000){system("cls");
    cout<<"El peso es mayor a 5000, vuelve a ingresar un valor menor o igual a 5000.\n";
    cout<<"Cantidad:";
    cin>>x;}
if(x>5000){system("cls");
    cout<<"El peso es mayor a 5000, vuelve a ingresar un valor menor o igual a 5000.\n";
    cout<<"Cantidad:";
    cin>>x;}
if(x>5000){system("cls");
    cout<<"El peso es mayor a 5000, vuelve a ingresar un valor menor o igual a 5000.\n";
    cout<<"Cantidad:";
    cin>>x;}
if(x>5000){system("cls");
    cout<<"Intentalo de nuevo.\n";
    system("pause");
}
    else{
    if(x%g==h)
        {
        x=x-1;
        x=x/2;
    A=x/a;
    x=x%a;
    B=x/b;
    x=x%b;
    C=x/c;
    x=x%c;
    D=x/d;
    x=x%d;
    E=x/e;
    x=x%e;
    F=x/f;
    x=x%f;
    G=x/g;
    x=x%g;
    H=x/h;
    cout<<"\nPara que el peso este equilibrado en cada balanza se deben de poner las siguientes pesas.";
    cout<<"\nNumero de pesas de 500g:"<<A;
    cout<<"\nNumero de pesas de 200g:"<<B;
    cout<<"\nNumero de pesas de 100g:"<<C;
    cout<<"\nNumero de pesas de 50g:"<<D;
    cout<<"\nNumero de pesas de 10g:"<<E;
    cout<<"\nNumero de pesas de 5g:"<<F;
    cout<<"\nNumero de pesas de 2g:"<<G;
    cout<<"\nNumero de pesas de 1g:"<<H;
    cout<<"\nEste programa no trabaja con numeros decimales por lo que faltaria 1 gramo que tendria que ser distribuido en las dos balanzas.";
    }
else{
    x=x/2;

    A=x/a;
    x=x%a;
    B=x/b;
    x=x%b;
    C=x/c;
    x=x%c;
    D=x/d;
    x=x%d;
    E=x/e;
    x=x%e;
    F=x/f;
    x=x%f;
    G=x/g;
    x=x%g;
    H=x/h;
    cout<<"\nPara que el peso este equilibrado en cada balanza se deben de poner las siguientes pesas.";
    cout<<"\nNumero de pesas de 500g:"<<A;
    cout<<"\nNumero de pesas de 200g:"<<B;
    cout<<"\nNumero de pesas de 100g:"<<C;
    cout<<"\nNumero de pesas de 50g:"<<D;
    cout<<"\nNumero de pesas de 10g:"<<E;
    cout<<"\nNumero de pesas de 5g:"<<F;
    cout<<"\nNumero de pesas de 2g:"<<G;
    cout<<"\nNumero de pesas de 1g:"<<H;

}
}}

