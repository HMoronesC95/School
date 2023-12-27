//*///*//TAREA 4 PAINT CON CTRL+Z

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;

Mat opciones, lienzo, buffer, lienzo_inicial;
double tamanio_letra = 0.6;
int flag = 0;
int x, y, x_inicial, y_inicial, figura, r=0,g=0,b=0, grosor = 1;
string IN_opciones = "Opciones", IN_lienzo = "Lienzo";

void on_trackbar_figura(int pos, void *)
{
    rectangle(opciones, Point(0, 40), Point(200, 0),
               Scalar(255,255,255), -1, LINE_8, 0);
    imshow(IN_opciones, opciones);

    switch (pos)
    {
        case 0 : figura = 0;
            putText(opciones, "Dibujo libre", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        case 1 : figura = 1;
            putText(opciones, "Circulo", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        case 2 : figura = 2;
            putText(opciones, "Linea", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        case 3 : figura = 3;
            putText(opciones, "Linea con flecha", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        case 4 : figura = 4;
            putText(opciones, "Rectangulo", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        case 5 : figura = 5;
            putText(opciones, "Elipse", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        case 6 : figura = 6;
            putText(opciones, "Goma", Point(0,30), FONT_HERSHEY_COMPLEX,
                     tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
            imshow(IN_opciones, opciones);
            break;
        default : cout<<"wtf\n";
    }
}

void on_trackbar_R(int pos, void *)
{
    r = pos;
}

void on_trackbar_G(int pos, void *)
{
    g = pos;
}

void on_trackbar_B(int pos, void *)
{
    b = pos;
}

void on_trackbar_grosor(int pos, void *)
{
    grosor = pos + 1;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{

    //lienzo_inicial = lienzo;



     if  ( event == EVENT_LBUTTONDOWN )
     {
        x_inicial = x;
        y_inicial = y;

        lienzo_inicial = lienzo;


        cout << "Left button of the mouse is clcked - position (" << x << ", " << y << ")" << endl;

          if(figura == 0)//dibujo libre
              flag = 1;
          else if(figura == 1)
              flag = 2;
          else if(figura == 2)
              flag = 3;
          else if(figura == 3)
              flag = 4;
          else if(figura == 4)
              flag = 5;
          else if(figura == 5)
              flag = 6;
          else if(figura == 6) //goma
              flag = 7;

     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_LBUTTONUP )
     {
          cout << "Left button of the mouse is released - position (" << x << ", " << y << ")" << endl;
          flag = 0;

          if(figura == 1)
          {   //  lienzo.setTo(Scalar(255,255,255));
              //imshow(IN_lienzo, lienzo_inicial);
              circle(lienzo, Point(x_inicial, y_inicial), sqrt(abs(pow((y-y_inicial),2) + pow((x-x_inicial),2))), Scalar(b,g,r), grosor, LINE_8);
              imshow(IN_lienzo, lienzo);
          }
          else if(figura == 2)
          {
              line(lienzo, Point(x_inicial,y_inicial), Point(x,y), Scalar(b,g,r), grosor);
              imshow(IN_lienzo, lienzo);
          }
          else if(figura == 3)
          {
              arrowedLine(lienzo, Point(x_inicial, y_inicial), Point(x, y), Scalar(b,g,r), grosor, LINE_8,  0, 0.1);
              imshow(IN_lienzo, lienzo);
          }
          else if(figura == 4)
          {
              rectangle(lienzo, Point(x_inicial, y_inicial), Point(x, y), Scalar(b,g,r), grosor, LINE_8, 0);
              imshow(IN_lienzo, lienzo);
          }
          else if(figura == 5)
          {
              ellipse(lienzo, Point(x_inicial, y_inicial), Size(sqrt(abs(pow((y-y_inicial),2) + pow((x-x_inicial),2))),sqrt(abs(pow((y-y_inicial),2) + pow((x-x_inicial),2)))*.6), 0, 0, 360, Scalar(b,g,r), grosor, LINE_8, 0);
              imshow(IN_lienzo, lienzo);
          }
          else cout<<"wtf\n";

     }
     else if (event == EVENT_MOUSEMOVE)
     {

         //lienzo_inicial = lienzo;
        // buffer = lienzo_inicial;
         //imshow(IN_lienzo, lienzo_buffer);

         if (flag == 1)
         {
             circle(lienzo, Point(x, y), grosor, Scalar(b,g,r), -1, LINE_8);
             imshow(IN_lienzo, lienzo);
         }
         else if (flag == 2)
         {
             // buffer = lienzo_inicial;
             // imshow(IN_lienzo, lienzo_inicial);
              circle(buffer, Point(x_inicial, y_inicial), sqrt(abs(pow((y-y_inicial),2) + pow((x-x_inicial),2))), Scalar(b,g,r), grosor, LINE_8);
              imshow(IN_lienzo, lienzo);
              //imshow(IN_lienzo, lienzo);
              //buffer = lienzo_inicial;
              cout<<"wtf\n";
         }
         else if (flag == 7)
         {
             circle(lienzo, Point(x, y), grosor, Scalar(255,255,255), -1, LINE_8);
             imshow(IN_lienzo, lienzo);
         }
         // cout<<"yea\n";
     }
}

int main()
{
    int slider_figura = 0, slider_R = 0, slider_G = 0, slider_B = 0, slider_grosor = 0;
    int slider_max_figura = 6, slider_max_R = 255, slider_max_G = 255, slider_max_B = 255, slider_max_grosor = 50;

    opciones.create(200,400, CV_8UC1);
    opciones.setTo(255);
    putText(opciones, "Dibujo libre", Point(0,30), FONT_HERSHEY_COMPLEX, tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
    namedWindow(IN_opciones);
    imshow(IN_opciones, opciones);

    lienzo.create(600,600, CV_8UC3);
    lienzo.setTo(Scalar(255,255,255));
    buffer.create(600,600, CV_8UC3);
    buffer.setTo(Scalar(255,255,255));
    lienzo_inicial.create(600,600, CV_8UC3);
    lienzo_inicial.setTo(Scalar(255,255,255));

    namedWindow(IN_lienzo);
    imshow(IN_lienzo, lienzo);

    createTrackbar("FIGURA <->",IN_opciones, &slider_figura, slider_max_figura, on_trackbar_figura);
    createTrackbar("R <->",IN_opciones, &slider_R, slider_max_R, on_trackbar_R);
    createTrackbar("G <->",IN_opciones, &slider_G, slider_max_G, on_trackbar_G);
    createTrackbar("B <->",IN_opciones, &slider_B, slider_max_B, on_trackbar_B);
    createTrackbar("GROSOR <->",IN_opciones, &slider_grosor, slider_max_grosor, on_trackbar_grosor);

    setMouseCallback("Lienzo", CallBackFunc, NULL);



/*
    waitKey(); // Wait for key press

    circle(img, Point(50, 100), 4, Scalar(0,0,255), 1, 8);

    arrowedLine(img, Point(200, 50), Point(50, 100), Scalar(0,255,0), 1, 8,  0, 0.1);

    rectangle(img, Point(200, 100), Point(50, 200), Scalar(255,0,0), 1, 8, 0);

    putText(img, "hola mundo", Point(50,100), FONT_HERSHEY_SCRIPT_COMPLEX, 0.6, Scalar(100,100,0), 1, LINE_8, false);

    ellipse(img, Point(50, 100), Size(100,50), 0, 45, 315, Scalar(255,0,0), 1, LINE_8, 0);

    imshow("Dibujos", img);
*/
    waitKey(); // Wait for key press
    return 0;
}
//*/////
