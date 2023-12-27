#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()

  {int x=0;
  cout<<"Introduce un anio para determinar si es bisiesto o no.";
  cout<<"\nAnio:";
  cin>>x;
  if(x%400==0){
    cout<<"\n\nEl anio "<<x<<" es bisiesto.";
  }
  else{
    if(x%4==0){
     if(x%100!=0){
            cout<<"\n\nEl anio "<<x<<" es bisiesto.";
        }}}
  //-------------------------------
    if(x%4!=0){
            cout<<"\n\nEl anio "<<x<<" no es bisiesto.";
      }
  }

