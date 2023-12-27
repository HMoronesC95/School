#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int main()

  {float x=0,h=0,a=15000,b=0;
  cout<<"Realizaremos el calculo para la hipoteca con base al tiempo en anios que llevas trabajando en la empresa actual.";
   cout<<"\nIngresa el numero de anios trabajando en la empresa dentro de un rango de 0 y 20 anios: ";
   cin>>x;

{   if(x>=0 && x<3){
    cout<<"\nSu sueldo base correspondiente es: "<<a;

     if(x==0){
     b=0;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
    }
     else if(x==1){
     b=a/2;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
    }
     else if(x==2){
     b=a*0.6;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
    }
    }
  else if(x>=3 && x<6){
        a=a+a*0.25;
     cout<<"\nSu sueldo base correspondiente es: "<<a;
     if(x==3){
      b=a*0.7;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
   }
     else if(x==4){
     b=a*0.8;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
   }
     else if(x==5){
     b=a*0.9;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
   }
   }
   else if(x>=6 && x<9){
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base correspondiente es: "<<a;
    if(x==6){
      b=a;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
    }
     else if(x==7){
     b=a*1.1;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
   }
     else if(x==8){
     b=a*1.2;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
   }
   }
   else if(x>=9 && x<12){
     a=a+a*0.25;
     a=a+a*0.25;
     a=a+a*0.25;
     cout<<"\nSu sueldo base corespondiente es: "<<a;
     if(x==9){
     b=a*1.3;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     }
     else if(x==10){
     b=a*1.4;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     }
     else if(x==11){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
   }
   else if(x>=12 && x<15){
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base corespondiente es: "<<a;
    if(x==12){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==13){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==14){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
    }
    else if(x>=15 && x<18){
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    a=a+a*0.25;
    cout<<"\nSu sueldo base corespondiente es: "<<a;
    if(x==15){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==16){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==17){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
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
    cout<<"\nSu sueldo base corespondiente es: "<<a;
    if(x==18){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==19){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
     else if(x==20){
     b=a*1.5;
     cout<<"\nSu aginaldo correspondiente es: "<<b;
     cout<<"\nSu aginaldo ha alcansado el tope de 45 dias.";
     }
    }

    else
        cout<<"\nEl valor ingresado "<<x<<" esta fuera de rango.";
}

  if (x>=4 && x<=20){
      h=x*12*(a+b)/2;
    cout<<"\nEl valor de su hipoteca es de: "<<h;

  }
   else
        cout<<"\nEl valor ingresado "<<x<<" esta fuera de rango ara calcular la hipoteca.";

  }//final

