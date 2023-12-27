#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()

  {
  	float x=0,y=0,z=0,w=0,v=0;
	int a;
  	cout<<"Indique la figura la cual quiere calcular su area y perimetro ingresando unicamente el numero correspondiente.";
  	cout<<"\n       1=cuadrado     2=rectangulo     3=circulo       4=triangulo: ";
  	cin>>a;
  	system ("cls");
  	if (a==1){
  	cout<<"Introdusca la medida de un lado del el cuadrado:";
	cin>>x;
	y=x*x;
	z=x*4;
	cout<<"El area del cuadrado es:"<<y<<"\n";
	cout<<"El perimetro del cuadrado es:"<<z<<"\n";
  	}
  	else if (a==2){
  	cout<<"Introdusca la base del rectangulo:";
	cin>>w;
	cout<<"Introdusca la altura del rectangulo:";
	cin>>z;
	cout<<"El area del rectangulo es:"<<w*z<<"\n";
	cout<<"El perimetro del rectangulo es:"<<2*w+2*z<<"\n";
  	}
  	else if (a==3){
  	cout<<"Ingresa el radio del circulo:";
	cin>>x;
	cout<<"El area del circulo es:"<<x*x*3.1416<<"\n";
	cout<<"El perimetro del circulo es:"<<3.1416*(x+x);
  	}
  	else if (a==4){
  	cout<<"Ingresa la base del triangulo:";
	cin>>x;
	cout<<"Introdusca un lado del triangulo:";
	cin>>y;
	cout<<"Introdusca el otro lado del triangulo:";
	cin>>z;
	cout<<"Introdusca la altura del triangulo respecto a la base:";
	cin>>w;
	cout<<"El area del triangulo es:"<<(x*w)/2<<"\n";
	cout<<"El perimetro del triangulo es:"<<x+y+z<<"\n";
  	}
  	else
  	cout<<"Valor ingresado no valido";



  }

