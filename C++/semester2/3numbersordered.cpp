#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()

  { int menor,medio,mayor,a,b,c;
  cout<<"Ingresa un numero:";
  cin>>a;
  cout<<"\n""Ingresa un segundo numero:";
  cin>>b;
  cout<<"\n""Ingresa un tercer numero:";
  cin>>c;
      if(a>b && a>c){
      a=mayor;
      if(b>a && b>c)
      b=mayor;
      if(c>a && c>b)
      c=mayor;}
      if(a<b && a<c){
      a=menor;
      if(b<a && b<c)
      b=menor;
      if(c<a && c<b)
      c=menor;}
      if(a>b && a<c){
      a=medio;
      if(a<b && a>c)
      a=medio;
      if(b>a && b<c)
      b=medio;
      if(b>c && b<a)
      b=medio;
      if(c>a && c<b)
      c=medio;
      if(c>b && c<a)
      c=medio;}
    {cout<<menor<<"\n";
    cout<<medio<<"\n";
    cout<<mayor<<"\n";}
      }

