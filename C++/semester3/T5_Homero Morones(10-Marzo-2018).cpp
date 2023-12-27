#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;


//Problema 1---------------------------------------------------------------

union members
{
    int entero;
    double real;
    char string[16];

}object;

int main()
{
cout<<"Size and submembers of union:";
cout<<"\n\nSize of submember int entero: "<<sizeof(object.entero);
cout<<"\n\nSize of submember double real: "<<sizeof(object.real);
cout<<"\n\nSize of submember char string[16]: "<<sizeof(object.string);
cout<<"\n\nMaximum size of members: "<<sizeof(object);
cout<<"\n\n";
}


