#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double l1 = 20, l2 = 10, px = 15, py = 10, u = 625, v = -600, w = -400;
    double theta_1[360], theta_2[360], p_x[360],p_y[360];


    for(int i = 0; i < 360; i++)
    {

        p_x[i] = 20 + 5*cos(i + 180);
        p_y[i] = 10 + 5*sin(i + 180);

        theta_1[i] = 2*atan((-2.*w + sqrt(4*pow(w,2) - 4*(u-v)*(u+v)))/(2.*(u-v)));
        theta_2[i] = atan((p_y[i]-l1*sin(theta_1[i]))/(p_x[i]-l1*cos(theta_1[i])));
       // theta_2[i] = atan(45.567/56.567);
       // theta[i] =

       // cout<<"\n"<<p_x[i];
    }
    cout<<"\n\n\nPX";
    for(int i = 0; i < 360; i++)
    {
        cout<<"\n"<<p_x[i];
    }
    cout<<"\n\n\nPY";
    for(int i = 0; i < 360; i++)
    {
        cout<<"\n"<<p_y[i];
    }
    cout<<"\n\n\nTHETA_1";
    for(int i = 0; i < 360; i++)
    {
        cout<<"\n"<<theta_1[i];
    }
    cout<<"\n\n\nTHETA_2";
    for(int i = 0; i < 360; i++)
    {
        cout<<"\n"<<theta_2[i];
    }


}
