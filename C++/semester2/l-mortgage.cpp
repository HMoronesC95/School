#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()

  {int x=0,z=0,h=0,a=15000,b=0;
  char A;
  cout<<"El calculo de su hipoteca es respecto al salario base y tiempo en anios que lleva trabajando en la empresa actual con las siguientes condiciones:";
  cout<<"\n\n1.- Se realizaran pagos mensuales teniendo en cuenta que el ultimo mes de pago de cada anio se efectuara un adelanto de $15000.";
  cout<<"\n2.- Por el punto anterior su solicitud debe ser mayor a $15000 anuales.";
  cout<<"\n3.- El tope de la hipoteca sera el 50% del salario base anual.";
  cout<<"\n4.- El plazo maximo sera de 20 anios.";
  cout<<"\n\nDeseas continuar s/n: ";
  cin>>A;
  if(A==115 || A==83){
   cout<<"\nIngresa el numero de anios trabajando en la empresa dentro de un rango de 1 y 20 anios: ";
   cin>>x;

{   if(x>=1 && x<3){
    cout<<"\nSu sueldo base correspondiente es: $"<<a;

     if(x==1){
     b=a/2;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
    }
     else if(x==2){
     b=a*0.6;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
    }
    }
  else if(x>=3 && x<6){
        a=a+a*0.25;
     cout<<"\nSu sueldo base correspondiente es: $"<<a;
     if(x==3){
      b=a*0.7;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
   }
     else if(x==4){
     b=a*0.8;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
   }
     else if(x==5){
     b=a*0.9;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
   }
   }
   else if(x>=6 && x<9){
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base correspondiente es: $"<<a;
    if(x==6){
      b=a;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
    }
     else if(x==7){
     b=a*1.1;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
   }
     else if(x==8){
     b=a*1.2;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
   }
   }
   else if(x>=9 && x<12){
     a=a+a*0.25;
     a=a+a*0.25;
     a=a+a*0.25;
     cout<<"\nSu sueldo base corespondiente es: $"<<a;
     if(x==9){
     b=a*1.3;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     }
     else if(x==10){
     b=a*1.4;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     }
     else if(x==11){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
   }
   else if(x>=12 && x<15){
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base corespondiente es: $"<<a;
    if(x==12){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==13){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==14){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
    }
    else if(x>=15 && x<18){
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base corespondiente es: $"<<a;
    if(x==15){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==16){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==17){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
    }
    else if(x>=18 && x<21){
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base corespondiente es: $"<<a;
    if(x==18){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==19){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==20){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: $"<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
    }

    else
        cout<<"\nEl valor ingresado "<<x<<" esta fuera de rango.";
}

  if (x>0 && x<=20){
      h=a*6;
    cout<<"\n\nEl valor maximo de su hipoteca es de: $"<<h;
    cout<<"\n\nSi desea una cantidad diferente eliga una de las siguientes opciones.";
    a=h*0.75;
    b=h*0.5;
    x=h*0.25;
    if (h>=15000){
    cout<<"\n\nOpcion 1: $"<<h;
      if(a>=15000){
    cout<<"\nOpcion 2: $"<<a;
       if(b>=15000){
    cout<<"\nOpcion 3: $"<<b;
        if(x>=15000){
    cout<<"\nOpcion 4: $"<<x;
             }}}}else cout<<"\n\nLo sentimos no cumples con los requisitos.\n";

    cout<<"\n\nIngrese la opcion que mas le convenga: ";cin>>z;

    system("cls");
if(z==1){
    cout<<"Ya que ha seleccionado la opcion de $"<<h<<" ingresa dentro de las opciones el plazo, teniendo en cuenta que en el ultimo mes de pago de cada anio se realizara un adelanto de $15000.";
    cout<<"\n\nOpcion 1: 12 meses.";
    cout<<"\nOpcion 2: 24 meses.";
    cout<<"\nOpcion 3: 60 meses.";
    cout<<"\nOpcion 4: 120 meses.";
    cout<<"\nOpcion 5: 240 meses.                    Opcion deseada 1, 2, 3, 4, 5: ";cin>>x;

    if(x==1){
       if((h-15000)/12>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 12 meses realizando un pago de $"<<(h-15000)/12<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==2){
        if((h-30000)/24>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 24 meses realizando un pago de $"<<(h-30000)/24<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==3){
        if((h-75000)/60>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 60 meses realizando un pago de $"<<(h-75000)/60<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==4){
        if((h-150000)/120>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 120 meses realizando un pago de $"<<(h-150000)/120<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==5){
        if((h-300000)/240>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 240 meses realizando un pago de $"<<(h-300000)/240<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else cout<<"\nEl valor ingresado de "<<x<<" es incorrecto.\n";}

else if(z==2){
    cout<<"Ya que ha seleccionado la opcion de $"<<a<<" ingresa dentro de las opciones el plazo, teniendo en cuenta que en el ultimo mes de pago de cada anio se realizara un adelanto de $15,000.";
    cout<<"\n\nOpcion 1: 12 meses.";
    cout<<"\nOpcion 2: 24 meses.";
    cout<<"\nOpcion 3: 60 meses.";
    cout<<"\nOpcion 4: 120 meses.";
    cout<<"\nOpcion 5: 240 meses.                    Opcion deseada 1, 2, 3, 4, 5: ";cin>>x;

    if(x==1){
       if((a-15000)/12>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 12 meses realizando un pago de $"<<(a-15000)/12<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==2){
        if((a-30000)/24>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 24 meses realizando un pago de $"<<(a-30000)/24<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==3){
        if((a-75000)/60>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 60 meses realizando un pago de $"<<(a-75000)/60<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==4){
        if((a-150000)/120>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 120 meses realizando un pago de $"<<(a-150000)/120<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==5){
        if((a-300000)/240>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 240 meses realizando un pago de $"<<(a-300000)/240<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else cout<<"\nEl valor ingresado de "<<x<<" es incorrecto.\n";}

else if(z==3){
    cout<<"Ya que ha seleccionado la opcion de $"<<b<<" ingresa dentro de las opciones el plazo, teniendo en cuenta que en el ultimo mes de pago de cada anio se realizara un adelanto de $15,000.";
    cout<<"\n\nOpcion 1: 12 meses.";
    cout<<"\nOpcion 2: 24 meses.";
    cout<<"\nOpcion 3: 60 meses.";
    cout<<"\nOpcion 4: 120 meses.";
    cout<<"\nOpcion 5: 240 meses.                    Opcion deseada 1, 2, 3, 4, 5: ";cin>>x;

    if(x==1){
        if((b-15000)/12>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 12 meses realizando un pago de $"<<(b-15000)/12<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==2){
        if((b-30000)/24>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 24 meses realizando un pago de $"<<(b-30000)/24<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==3){
        if((b-75000)/60>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 60 meses realizando un pago de $"<<(b-75000)/60<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==4){
        if((b-150000)/120>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 120 meses realizando un pago de $"<<(b-150000)/120<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==5){
        if((b-300000)/240>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 240 meses realizando un pago de $"<<(b-300000)/240<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else cout<<"\nEl valor ingresado de "<<x<<" es incorrecto.\n";}

else if(z==4){
    cout<<"Ya que ha seleccionado la opcion de $"<<x<<" ingresa dentro de las opciones el plazo, teniendo en cuenta que en el ultimo mes de pago de cada anio se realizara un adelanto de $15,000.";
    cout<<"\n\nOpcion 1: 12 meses.";
    cout<<"\nOpcion 2: 24 meses.";
    cout<<"\nOpcion 3: 60 meses.";
    cout<<"\nOpcion 4: 120 meses.";
    cout<<"\nOpcion 5: 240 meses.                    Opcion deseada 1, 2, 3, 4, 5: ";
    a=x;
    cin>>x;
    if(x==1){
        if((a-15000)/12>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 12 meses realizando un pago de $"<<(a-15000)/12<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==2){
        if((a-30000)/24>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 24 meses realizando un pago de $"<<(a-30000)/24<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==3){
        if((a-75000)/60>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 60 meses realizando un pago de $"<<(a-75000)/60<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==4){
        if((a-150000)/120>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 120 meses realizando un pago de $"<<(a-150000)/120<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else if(x==5){
        if((a-300000)/240>=0){
        cout<<"\nFelicitaciones, su hipoteca sera de 240 meses realizando un pago de $"<<(a-300000)/240<<" mensual mas $15000 anuales.\n";
        }else cout<<"\nLo sentimos, la cantidad en el plazo solicitado es muy pequenia.\n";
    }else cout<<"\nEl valor ingresado de "<<x<<" es incorrecto.\n";}


   else
        cout<<"\nEl valor ingresado "<<z<<" es incorrecto.";
  }

  }
  else if(A==110 || A==78){
    cout<<"\nGracias, adios.\n";
  }
  else cout<<"\ns para SI, n para NO\n";

  }//final
