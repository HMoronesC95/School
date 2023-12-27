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

int x=0,y=0,a=0;

    cout<<"HALLAR LA MATRIZ INVERSA DE UNA MATRIZ nxn UTILIZANDO EL METODO DE GAUSS-JORDAN\n";
    cout<<"recordatorio: Para poder utilizar este metodo LA MATRIZ DEBE SER CUADRADA, esto es que el numero de renglones sea igual al numero de columnas\n";
	cout<<"\nIntroduzca la dimension de la MATRIZ A: ";
	cin >> x;
	y=x;

	int inversa[x][2*y];

    system("cls");
    cout<<"MATRIZ A DE "<<x<<" x "<<y<<".\n";
	for (int i = 0;i < x;i++) {
		for (int j = 0;j < y;j++) {
			cout << "Introduzca el valor en la posicion del renglon "<<i+1<<" columna "<<j+1<<": ";
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
      cout<<"MATRIZ A\n";
      for(int i=0;i<x;i++){
         for(int j=0;j<2*y;j++){
               cout<<inversa[i][j]<<" ";
            }
               cout<<"\n";
            }
    system("pause");

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){

            if(i==j){
                a=inversa[i][j];
                for(int k=0;k<2*y;k++){
                    inversa[i][k]=inversa[i][k]/a;
                }
                for(int ii=0;ii<x;ii++){
                    for(int jj=0;jj<2*y;jj++){

                      if(ii!=i){
                          while(inversa[ii][j]!=0){

                            if(ii!=i)
                                  inversa[ii][jj]=inversa[ii][jj]-inversa[i][j];

                          }
                      }
                    }
                }
            }
        }
    }


    cout<<"\n\nMATRIZ A\n";
      for(int i=0;i<x;i++){
         for(int j=0;j<2*y;j++){
               cout<<inversa[i][j]<<" ";
            }
               cout<<"\n";
            }
    system("pause");

}

