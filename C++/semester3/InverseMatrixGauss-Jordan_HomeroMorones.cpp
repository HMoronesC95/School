#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;
//Problema 1---------------------------------------------------------------
int main()
{

 int x=0,y=0;

    cout<<"HALLAR LA MATRIZ INVERSA DE UNA MATRIZ nxn UTILIZANDO EL METODO DE GAUSS-JORDAN\n";
    cout<<"recordatorio: Para poder utilizar este metodo LA MATRIZ DEBE SER CUADRADA, esto es que el numero de renglones sea igual al numero de columnas\n";
	cout<<"\nIntroduzca la dimension de la MATRIZ A: ";
	cin >> x;
	y=x;

	float inversa[x][2*y];
	float a=0;

    system("cls");
    cout<<"MATRIZ A DE "<<x<<" x "<<y<<".\n";
	for (int i = 0;i < x;i++) {
		for (int j = 0;j < y;j++) {
			cout << "Introduzca el valor en la posicion A["<<i+1<<"]"<<"["<<j+1<<"]: ";
			cin >> inversa[i][j];
		}}
    for(int i=0;i<x;i++){
        for(int j=y;j<2*y;j++){
            if((i+y)==j)
                inversa[i][j]=1;
            else inversa[i][j]=0;
        }
    }

      system("cls");
      cout<<"MATRIZ A CON SU MATRIZ IDENTIDAD.\n";
      for(int i=0;i<x;i++){
        int aux=0;
         for(int j=0;j<2*y;j++){
               cout<<inversa[i][j]<<" ";
               aux++;
               if(aux==y)
                  cout<<"          ";
            }
               cout<<"\n";
            }

    system("pause");

    for(int i=0;i<x;i++){
        for(int j=0;j<2*y;j++){
            if(i==j){
                a=inversa[i][j];
                for(int k=0;k<2*y;k++){
                    inversa[i][k]=inversa[i][k]/a;
                }
                    for(int ii=0;ii<x;ii++){
                         if(ii!=i){
                            float aux=inversa[ii][j];
                                for(int jj=0;jj<2*y;jj++){
                                    inversa[ii][jj]=inversa[ii][jj]-aux*inversa[i][jj];
                                }
                          }
                     }
            }
        }
    }

    cout<<"\n\nMATRIZ A TRANSFORMADA A LA MATRIZ IDENTIDAD CON SU MATRIZ INVERSA.\n\n";

      for(int i=0;i<x;i++){
       int aux=0;
         for(int j=0;j<2*y;j++){
               cout<<inversa[i][j]<<" ";
               aux++;
               if(aux==y)
                  cout<<"          ";
            }
               cout<<"\n";
            }
    cout<<"\n\n";
    getch();
}
