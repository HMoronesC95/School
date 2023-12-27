#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include<string>
#define IN "Imagen de Entrada"

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread( "C:/imagenes/figuras_bmp/ejemplo25_bitmap.bmp",
                     CV_LOAD_IMAGE_GRAYSCALE);
    threshold(img, img, 50, 255, THRESH_BINARY);
    imshow(IN, img);
    Mat img2;
    img.convertTo(img2, CV_8U);
    // Encuentra contornos
    vector<vector<Point> > contours;
    findContours(img2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    // Se crea un arreglo para almacenar la curva de aproximacion
    vector<Point> approx;

    vector<vector<Point> >::iterator itc;
    static int label=0;
    itc= contours.begin();
    int j=0;
    string num;
    while (itc!=contours.end())
    {
        // compute all moments
        Moments mom= moments(Mat(*itc++));
        // Dibuja centro (centroide)
        int x=mom.m10/mom.m00;
        int y=mom.m01/mom.m00;
        cout<< "Centro figura " <<label<<" = "<<x <<","<<y<<endl;
        circle(img,Point(x,y),3,128,-1,LINE_8);
        num = to_string(label);
        putText(img,num,Point(x,y),1,2,Scalar(0,0,255),1,LINE_8,false);
        label++;// Incrementa el numero usado para la etiqueta
        // Aproxima el contorno
        approxPolyDP( Mat(contours[j]), approx, arcLength(Mat(contours[j]),
        true) * 0.02, true);
        // No considera objetos muy pequeños
        if (fabs(contourArea(contours[j])) < 100 || !isContourConvex(approx)) continue;
        if (approx.size() == 3)
            cout<<"Poligono Tres lados"<<endl;    // Triangulos
        else if (approx.size() == 4)
        {
             cout<<"Poligono con 4 lados"<<endl;
        }
        else
        {
            // Suponemos son circulos
            double area = contourArea(contours[j]);
            Rect r = boundingRect(contours[j]);
            int radius = r.width / 2;

            if (abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                abs(1 - (area / (CV_PI * pow(radius, 2)))) <= 0.2)
            {
                cout<<"Potencial Circulo"<<endl;
            }
        }
        //calcula los momentos de hu
        double huMoments[7];
        HuMoments(mom,huMoments);
        //log10 scale humoments
        for(int i=0; i<7; i++)
        {
            huMoments[i] = -1*copysign(1.0,huMoments[i])*log10(abs(huMoments[i]));
        }
        cout<<huMoments[0]<<"\n"<<huMoments[1]<<"\n"<<huMoments[2]<<"\n"
        <<huMoments[3]<<"\n"<<huMoments[4]<<"\n"<<huMoments[5]<<"\n"<<huMoments[6];
        cout<<"\n\n";
        j++;
    }
    imshow(IN, img);
    cout << "Presiona cualquier tecla para salir..." << endl;
    waitKey();
    return 0;
}
/*
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

static double angulo(Point pt1, Point pt2, Point pt0)
{
     double dx1 = pt1.x - pt0.x;
     double dy1 = pt1.y - pt0.y;
     double dx2 = pt2.x - pt0.x;
     double dy2 = pt2.y - pt0.y;
     return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

int main()
{
     Mat src = imread( "C:/imagenes/ejemplo25_bitmap.bmp",CV_LOAD_IMAGE_GRAYSCALE);
     Mat bw;
     imshow("src", src);
     src.convertTo(bw, CV_8U);
     threshold(src, src, 128, 255, THRESH_BINARY);
     // Encuentra contornos
     vector<vector<Point> > contours;
     findContours(bw.clone(), contours, CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE);
     // Se crea un arreglo para almacenar la curva de aproximacion
     vector<Point> approx;
     vector<vector<Point> >::iterator itc;
     itc= contours.begin();
     for (int i = 0; i < contours.size(); i++)
     {

        // calcula los momentos
        Moments mom= moments(Mat(*itc++));

        //calcula los momentos de hu
        double huMoments[7];
        HuMoments(mom,huMoments);

        //log10 scale humoments
        for(int i=0; i<7; i++)
        {
            huMoments[i] = -1*copysign(1.0,huMoments[i])*log10(abs(huMoments[i]));
        }
        cout<<"\n"<<huMoments[0]<<"\n"<<huMoments[1]<<"\n"<<huMoments[2]<<"\n"
        <<huMoments[3]<<"\n"<<huMoments[4]<<"\n"<<huMoments[5]<<"\n"<<huMoments[6];

        cout<<"\n\n";






         // Aproxima el contorno
         approxPolyDP( Mat(contours[i]), approx, arcLength(Mat(contours[i]),
         true) * 0.02, true);
         // No considera objetos muy pequeños
         if (fabs(contourArea(contours[i])) < 100 ||
         !isContourConvex(approx)) continue;
         if (approx.size() == 3)
             cout<<"Triangulo"<<endl;    // Triangulos
         else if (approx.size() == 4)
         {
             // Numero de vertices en la curva poligonal
             int vtc = approx.size();
             // Obtiene los angulos (coseno) de todas las esquinas encontradas
             vector<double> cos;
             for (int j = 2; j < vtc+1; j++)
             {
                 cos.push_back(angulo(approx[j%vtc], approx[j-2], approx[j-1]));
             }
             // Ordena en forma ascendente los angulos
             sort(cos.begin(), cos.end());
             // Obtiene el angulo mas pequeño y el mas grande
             double mincos = cos.front();
             double maxcos = cos.back();
             if( mincos >= -0.1 && maxcos <= 0.3)
             {
                 cout<<"Poligono con cuatro lados y angulos rectos (90º)"<<endl;
             }
         }
         else
         {
             // Detecta circulos
             double area = contourArea(contours[i]);
             Rect r = boundingRect(contours[i]);
             int radius = r.width / 2;
             if (abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                 abs(1 - (area / (CV_PI * pow(radius, 2)))) <= 0.2)
             {
                 cout<<"Candidato a Circulo"<<endl;
             }
         }
     }
     waitKey(0);
     return 0;
}
*/
