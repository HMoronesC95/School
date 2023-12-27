#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/*/Problema 1---------------------------------------------------------------
int main()
{
    int aux=0,j=0,k;

     cout<<"Numero de letras a ingresar: ";
     cin>>j;
     char palabra[j];
     cout<<"Ingrese la palabra para encontrar el numero de vocales: ";
     cin>>palabra;


     for(int i=0;i<j;i++){
           k=palabra[i];
            switch(k){

                case 65: aux++;
                         break;
                case 69: aux++;
                         break;
                case 73: aux++;
                         break;
                case 79: aux++;
                         break;
                case 85: aux++;
                         break;
                case 97: aux++;
                         break;
                case 101: aux++;
                          break;
                case 105: aux++;
                          break;
                case 111: aux++;
                          break;
                case 117: aux++;
                          break;

            }
     }
    cout<<"\n\nLa palabra "<<palabra<<" tiene "<<aux<<" vocales.\n\n";

}
*/


/*/Problema 2--------------------------------------------------------------------------------
int main()
{
    int x,i=0;

    cout<<"Ingresa un numero para descomponerlo en factores primos: "; cin>>x;

    cout<<"\n\n"<<x<<" = ";
    do{

        if(x%2==0){
            cout<<"2 x ";
            x=x/2;
        }else if(x%3==0){
            cout<<"3 x ";
            x=x/3;
        }else if(x%5==0){
            cout<<"5 x ";
            x=x/5;
        }else if(x%2!=0 && x%3!=0 && x%5!=0){
            cout<<" "<<x<<" ";
            i=1;
        }

        else {cout<<" 1"; i=1;}

    }while (i==0);
 cout<<"\n\n";
}
*/

/*/Problema 3--------------------------------------------------------------------------------
int main()
{
    int x=0;

    do{
      cout<<"\nIngrese la opcion de la variable para conocer su tamanio en bytes: ";
      cout<<"\n1.-Char\n2.-Int\n3.-Float\n4.-Double\n5.-Long\n6.-Const\n7.-Salir\n  Opcion: ";
      cin>>x;

         switch (x){
            case 1: cout<<"\nEl tamanio de un variable tipo Char es de "<<sizeof(char)<<" bytes.";
                    break;
            case 2: cout<<"\nEl tamanio de un variable tipo Int es de "<<sizeof(int)<<" bytes.";
                    break;
            case 3: cout<<"\nEl tamanio de un variable tipo Float es de "<<sizeof(float)<<" bytes.";
                    break;
            case 4: cout<<"\nEl tamanio de un variable tipo Double es de "<<sizeof(double)<<" bytes.";
                    break;
            case 5: cout<<"\nEl tamanio de un variable tipo Long es de "<<sizeof(long)<<" bytes.";
                    break;
            case 6: cout<<"\nEl tamanio de un variable tipo Const es de "<<sizeof(const)<<" bytes.";
                    break;
            case 7: x=0;
                    break;
            default :{cout<<"Valor fuera de rano.";}
         }cout<<"\n\n";
    system("pause");
    system("cls");

    }while (x!=0);

    cout<<"\n\nADIOS.....\n\n";


}
*/

/*/Problema 4--------------------------------------------------------------------------------
int main()
{
  int x=0,aux=0,loop;;
  float y=0;
  char aux_c[1],a;

  while(aux==0)
  {
      loop:
  x=0;
  cout<<"Ingrese un numero entero positivo: ";
  cin>>aux_c[0];

  if(aux_c[0] >= 48 && aux_c[0] <= 57)
  {
      do{
    cin>>a;
    cout<<"\n";
    system("cls");
      }while (a==13);

    cout<<"\nPara confirmar vuelva a ingresar el numero: ";
    cin>>y;
    cout<<"\n";
    x=y;
    if(y<=0){
        cout<<"\nValor ingresado invalido, debe ser un numero  positivo.\n";
        goto loop;
    }else if(x==y){
      aux=1;


    for(int i=1;i<=x;i++)
    {
      for(int j=1;j<=i;j++)
      {
        cout<<j<<", ";
      }
      cout<<"\n";
    }}

  }else{
    cout<<"\nValor ingresado invalido.\n\n";
      goto loop;

      }
  }}
*/


/*/Problema 5--------------------------------------------------------------------------------
int main()
{ int matriz[5][5],i=0,j=0,ii=0,jj=0,aux=0,menor=1000;
    cout<<"Matriz de 5 x 5.\n\n";

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<"Ingrese el valor del renglon "<<i+1<<" columna "<<j+1<<": ";
            cin>>matriz[i][j];
        }
    }
     system("cls");
     cout<<"Matriz\n\n";
     for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<matriz[i][j]<<" ";
        }cout<<"\n";}
     cout<<"\n\n";
     for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            aux=matriz[i][j];
            if(menor>=aux){
                menor=aux;
                ii=i;
                jj=j;
            }
           }
          }
       cout<<"\nLa menor cifra es "<<menor<<" y se encuentra en el renglon "<<ii+1<<" columna "<<jj+1;

       cout<<"\nPuntos de silla: ";
       for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            aux=matriz[i][j];
              for(ii=0;ii<5;ii++){
                for(jj=0;jj<5;jj++){
                    if(aux<matriz[ii][jj]){
                        if(aux>matriz[jj][ii]){
                            cout<<aux<<", ";

                        }
                    }
                }
              }
        }
       }


     getch();
}
*/

/*/Problema 6--------------------------------------------------------------------------------
int main()
{
     int s=0,f=0,loop,op,aux=0;
     int x=0,y=0,x1=0,y1=0,x2=0,y2=0;
     loop:
    system("cls");
    cout<<"OPERACIONES CON 3 MATRICES DE nxm\n";
    cout<<"recordatorio: para la suma y resta las matrices tienen que tener la misma dimension.\npara la multiplicacion se debe cumplir lo siguiente:\n Una matriz A tiene una dimension de n renglones por m columnas y otra matriz B tiene una dimension de m renglones por p columnas, para poder realizar la multiplicaciones se debe cumplir A*B=nxm*mxp.\n";
	cout<<"\nIntroduzca el numero de renglones de la MATRIZ A: ";
	cin >> x;
	cout<<"Introduzca el numero de columnas de la MATRIZ A: ";
	cin >> y;

	int matrizA[x][y];

	for (int i = 0;i < x;i++) {
		for (int j = 0;j < y;j++) {
			cout << "Introduzca el valor en la posicion del renglon "<<i+1<<" columna "<<j+1<<".\n";
			cin >> matrizA[i][j];
		}}

	cout<<"\nIntroduzca el numero de renglones de la MATRIZ B: ";
	cin >> x1;
	cout<<"Introduzca el numero de columnas de la MATRIZ B: ";
	cin >> y1;

	int matrizB[x1][y1];

	for (int i = 0;i < x1;i++) {
		for (int j = 0;j < y1;j++) {
			cout << "Introduzca el valor en la posicion del renglon "<<i+1<<" columna "<<j+1<<".\n";
			cin >> matrizB[i][j];
		}}

	cout<<"\nIntroduzca el numero de renglones de la MATRIZ C: ";
	cin >> x2;
	cout<<"Introduzca el numero de columnas de la MATRIZ C: ";
	cin >> y2;

	int matrizC[x2][y2];

	for (int i = 0;i < x2;i++) {
		for (int j = 0;j < y2;j++) {
			cout << "Introduzca el valor en la posicion del renglon "<<i+1<<" columna "<<j+1<<".\n";
			cin >> matrizC[i][j];
		}}

   do{ op:

	cout<<"\n\nIngrese la opcion deseada: \n1.- SUMA\n2.- RESTA\n3.- MULTIPLICACION\n4.- SALIR\n        OPCION: ";
	cin>>s;
  system("cls");
  cout<<"Matriz A\n";
  for(int i=0;i<x;i++){
     for(int j=0;j<y;j++){
           cout<<matrizA[i][j]<<" ";
        }
           cout<<"\n";
        }
  cout<<"Matriz B\n";
  for(int i=0;i<x;i++){
     for(int j=0;j<y;j++){
           cout<<matrizB[i][j]<<" ";
        }
           cout<<"\n";
        }
  cout<<"Matriz C\n";
  for(int i=0;i<x;i++){
     for(int j=0;j<y;j++){
           cout<<matrizC[i][j]<<" ";
        }
           cout<<"\n";
        }


	    	switch(s){
	    	   case 1: cout<<"\nOperacion SUMA.\n";
	    	       if(x==x1 && x==x2 && y==y1 && y==y2){
	    	       cout<<"\nEl resultado de A+B+C= \n";
	    	            for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizA[i][j]+matrizB[i][j]+matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else if(x==x1 && y==y1 && (x!=x2 || y!=y2)){
                     cout<<"\nPor las dimensiones unicamente es posible A+B= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizA[i][j]+matrizB[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else if(x==x2 && y==y2 && (x!=x1 || y!=y1)){
                     cout<<"\nPor las dimensiones unicamente es posible A+C= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizA[i][j]+matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else if(x1==x2 && y1==y2 && (x!=x1 || y!=y1)){
                     cout<<"\nPor las dimensiones unicamente es posible B+C= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizB[i][j]+matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else {
                          cout<<"\nPor las dimensiones no puede ser efectuada la operacion SUMA.\n";
                          getch();
                       }
                       goto loop;
                       break;

               case 2: cout<<"\nOperacion RESTA.\n";
	    	       if(x==x1 && x==x2 && y==y1 && y==y2){
	    	       cout<<"\nEl resultado de A-B-C= \n";
	    	            for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizA[i][j]-matrizB[i][j]-matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();

	    	       cout<<"\nEl resultado de B-A-C= \n";
	    	            for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizB[i][j]-matrizA[i][j]-matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();

	    	       cout<<"\nEl resultado de C-A-B= \n";
	    	            for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizC[i][j]-matrizB[i][j]-matrizA[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else if(x==x1 && y==y1 && (x!=x2 || y!=y2)){
                     cout<<"\nPor las dimensiones unicamente es posible A-B= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizA[i][j]-matrizB[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();

                     cout<<"\nTambien es posible B-A= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizB[i][j]-matrizA[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else if(x==x2 && y==y2 && (x!=x1 || y!=y1)){
                     cout<<"\nPor las dimensiones unicamente es posible A-C= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizA[i][j]-matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();

                     cout<<"\nTambien es posible C-A= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizC[i][j]-matrizA[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else if(x1==x2 && y1==y2 && (x!=x1 || y!=y1)){
                     cout<<"\nPor las dimensiones unicamente es posible B-C= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizB[i][j]-matrizC[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();

                     cout<<"\nPor las dimensiones unicamente es posible C-B= \n";
                         for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<matrizC[i][j]-matrizB[i][j]<<" ";
                            }
                            cout<<"\n";
                            }
                            getch();
                    }else {
                          cout<<"\nPor las dimensiones no puede ser efectuada la operacion SUMA.\n";
                          getch();
                       }
                       goto loop;
                       break;



               case 3: cout<<"\nOperacion MULTIPLICACION.\n";
	    	       if(x==x1 && x==x2 && y==y1 && y==y2 && x==y){
	    	       cout<<"\nEl resultado de A*B*C= \n";
                   int resultado[x][y];
                   int ii=0,jj=0;


	    	            for(int i=0;i<x;i++){
	    	                    ii=i;
                                aux=0;
                            for(int j=0;j<y;j++){
                                jj=j;
                                aux=aux+matrizA[i][j]*matrizB[j][i];
                                }
                            resultado[ii][jj]=aux;
                            }


                        for(int i=0;i<x;i++){
                            ii=i;
                            aux=0;
                            for(int j=0;j<y;j++){
                                jj=j;
                                aux=aux+resultado[i][j]*matrizC[j][i];
                                }
                            resultado[ii][jj]=aux;
                            }



                        for(int i=0;i<x;i++){
                            for(int j=0;j<y;j++){
                                cout<<resultado[i][j]<<" ";
                            }
                            cout<<"\n";
                        }
	    	          getch();
                    }goto loop;break;

                case 4: f=1;break;
                default : {cout<<"\nOpcion invalida."; goto op;}

	    	}
   }while (f==0);
}
*/
