#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat opciones, lienzo, copia;
int tamanio_lienzo_x = 600, tamanio_lienzo_y = 600, figura_xinicial = tamanio_lienzo_x/2 - 30,
            figura_xfinal = tamanio_lienzo_x/2 + 30, figura_yinicial = tamanio_lienzo_y/2 - 30,
             figura_yfinal = tamanio_lienzo_y/2 + 30;
int x, y, x_inicial, y_inicial,ladox=60,ladoy=60;
string IN_opciones = "Opciones", IN_lienzo = "Lienzo";

void on_trackbar_traslacionx(int pos, void *)
{
    lienzo.setTo(Scalar(0,0,0));

    figura_xinicial =  pos * lienzo.cols/10;
    figura_xfinal = figura_xinicial + ladox;

    figura_yfinal = figura_yinicial + ladoy;

    rectangle(lienzo, Point(figura_xinicial, figura_yinicial),
              Point(figura_xfinal, figura_yfinal), Scalar(255,255,255), -1, LINE_8, 0);

    imshow(IN_lienzo, lienzo);
}

void on_trackbar_traslaciony(int pos, void *)
{
    lienzo.setTo(Scalar(0,0,0));

    figura_yinicial =  pos * lienzo.rows/10;
    figura_yfinal = figura_yinicial + ladoy;

    figura_xfinal = figura_xinicial + ladox;

    rectangle(lienzo, Point(figura_xinicial, figura_yinicial),
               Point(figura_xfinal, figura_yfinal), Scalar(255,255,255), -1, LINE_8, 0);

    imshow(IN_lienzo, lienzo);
}

void on_trackbar_rotacion(int pos, void *)
{
    Mat img;
    vector<vector<Point> > contours;
    findContours(lienzo, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    vector<vector<Point> >::iterator itc;
    static int label=0;
    itc= contours.begin();
    while (itc!=contours.end())
    {
        if(pos<9)
            pos = -18;
        else
            pos = 18;
        // compute all moments
        Moments mom= moments(Mat(*itc++));
        // Dibuja centro (centroide)
        int x=mom.m10/mom.m00;
        int y=mom.m01/mom.m00;
        cout<< "Centro figura " <<label<<" = "<<x <<","<<y<<endl;
        label++;// Incrementa el numero usado para la etiqueta
        warpAffine(lienzo,lienzo,getRotationMatrix2D(Point2f(x,y), pos, 1),
                   lienzo.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
        imshow(IN_lienzo, lienzo);
    }
}

void on_trackbar_escala(int pos, void *)
{
    if(pos<5)
    {
        Mat img_resized(lienzo.rows*0.9, lienzo.cols*0.9, CV_8U);
        ladox=ladox*0.9;
        ladoy=ladoy*0.9;

        Size sz = img_resized.size();

        resize(lienzo,img_resized,sz,0.0f,0.0f,INTER_LINEAR);
        img_resized.copyTo(lienzo);
    }
    else
    {
        Mat img_resized(lienzo.rows*1.1, lienzo.cols*1.1, CV_8U);
        ladox=ladox*1.1;
        ladoy=ladoy*1.1;

        Size sz = img_resized.size();

        resize(lienzo,img_resized,sz,0.0f,0.0f,INTER_LINEAR);
        img_resized.copyTo(lienzo);
    }

    imshow(IN_lienzo, lienzo);
}

int main()
{
    int slider_traslacionx = 5, slider_traslaciony = 5,
                slider_rotacion = 10, slider_escala = 5;
    int slider_max_traslacionx = 9, slider_max_traslaciony = 9,
                slider_max_rotacion = 19, slider_max_escala = 9;

    opciones.create(200,400, CV_8U);
    opciones.setTo(255);
    namedWindow(IN_opciones);
    imshow(IN_opciones, opciones);

    lienzo.create(tamanio_lienzo_y,tamanio_lienzo_x, CV_8U);
    lienzo.setTo(Scalar(0,0,0));
    copia.create(tamanio_lienzo_y,tamanio_lienzo_x, CV_8U);
    lienzo.copyTo(copia);

    rectangle(lienzo, Point(figura_yinicial, figura_xinicial), Point(figura_yfinal, figura_xfinal),
               Scalar(255,255,255), -1, LINE_8, 0);

    namedWindow(IN_lienzo);
    imshow(IN_lienzo, lienzo);

    createTrackbar("X <->",IN_opciones, &slider_traslacionx, slider_max_traslacionx, on_trackbar_traslacionx);
    createTrackbar("Y <->",IN_opciones, &slider_traslaciony, slider_max_traslaciony, on_trackbar_traslaciony);
    createTrackbar("ROTACION <->",IN_opciones, &slider_rotacion, slider_max_rotacion, on_trackbar_rotacion);
    createTrackbar("ESCALA <->",IN_opciones, &slider_escala, slider_max_escala, on_trackbar_escala);

    while(char(waitKey(1)) != 27)
    waitKey();

    return 0;
}
