#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;


/*/Problema 1---------------------------------------------------------------
int main()
{
    string cadena;

    cout<<"Ingresa una serie de caracteres para calcular su longitud: ";
    cin>>cadena;
    cout<<cadena;
    cout<<"\n\nLa cantidad de caracteres es: "<<cadena.size();
}
/*/


/*/Problema 2--------------------------------------------------------------------------------
int main()
{
    int limites[10],serie[10],menor=100000000,mayor=0,i=0;
    cout<<"Ingresa diez numeros distintos de cero.\n";

        for(i=0;i<10;i++)
        {
            cout<<"Valor "<<i+1<<": ";
            cin>>limites[i];

                if(limites[i]==0)
                {
                    i=15;
                    cout<<"\nValor fuera de rango....\n\n";
                }
                if(limites[i]>mayor)
                {
                    mayor=limites[i];
                }
                if(limites[i]<menor)
                {
                    menor=limites[i];
                }

        }
        if(i!=16)
        {
        system("cls");
        cout<<"Rango del "<<menor<<" al "<<mayor<<".";
        cout<<"\nIngresa otros diez enteros distintos de cero.\n";
        for(i=0;i<10;i++)
        {
            cout<<"Valor "<<i+1<<": ";
            cin>>serie[i];

                if(serie[i]==0)
                {
                    i=15;
                }
                else if(serie[i]>mayor || serie[i]<menor)
                {
                    i=15;
                }
        }
        if(i!=16)
        {
            cout<<"\nTodos los valores se encuentran dentro del rango.\n\n";
        }
        else cout<<"\nValor fuera de rango....\n\n";

        }
}
/*/



