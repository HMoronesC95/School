#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    float a1,a2,b1,b2,c1,c2,c3,d,dep,par,tar,proy,calif;
    cout<<"Calificacion final del 0 al 100:";


    cout<<"\nCalificacion del primer examen departamental:";
    cin>>a1;
    cout<<"\nCalificacion del segundo examen departamental:";
    cin>>a2;
    dep=(a1*0.4+a2*0.4)/2;
    cout<<"\nCalificacion del primer examen parcial:";
    cin>>b1;
    cout<<"\nCalificacion del segundo examen parcial:";
    cin>>b2;
    par=(b1*0.30+b2*0.30)/2;
    cout<<"\nCalificacion de tareas:";
    cin>>c1;
    cout<<"\nCalificacion de trabajos:";
    cin>>c2;
    cout<<"\nCalificacion de participacion:";
    cin>>c3;
    tar=(c1*0.2+c2*0.2+c3*0.2)/3;
    cout<<"\nCalificacion del proyecto:";
    cin>>d;
    proy=d*0.1;
    calif=dep+par+tar+proy;
    cout<<"\nCalificacion final:";
    cout<<calif<<"\n";
    system("pause");
}
