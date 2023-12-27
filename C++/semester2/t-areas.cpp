#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()
{
    int x=0;
    int d,f,z;
	float lado=0;
	float ac,pc;
	float base,altura;
	float baset,ladoa,ladob;
	float radio;
	float largo,ancho;
	cout<<"introdusca la medida de un lado del el cuadrado:";
	cin>>lado;
	ac=lado*lado;
	pc=lado*4;
	cout<<"el area del cuadrado es:"<<ac<<"\n";
	cout<<"el perimetro del cuadrado es:"<<pc<<"\n";
	system("pause");
	system("cls");

	cout<<"introdusca la base del rectangulo:";
	cin>>base;
	cout<<"introdusca la altura del rectangulo:";
	cin>>altura;
	cout<<"el area del rectangulo es:"<<base*altura<<"\n";
	cout<<"el perimetro del rectangulo es:"<<2*base+2*altura<<"\n";
	system("pause");
	system("cls");

	cout<<"ingresa la base del triangulo:";
	cin>>baset;
	cout<<"introdusca un lado del triangulo:";
	cin>>ladoa;
	cout<<"introdusca el otro lado del triangulo:";
	cin>>ladob;
	cout<<"el perimetro del triangulo es:"<<baset+ladoa+ladob<<"\n";
	system("pause");
	system("cls");

	cout<<"ingresa el radio del circulo:";
	cin>>radio;
	cout<<"el area del circulo es:"<<radio*radio*3.1416<<"\n";
	cout<<"el perimetro del circulo es:"<<3.1416*(radio+radio);


}
