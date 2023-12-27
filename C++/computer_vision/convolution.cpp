#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat img, modificada, opciones, draw1, draw2;
double tamanio_letra = 0.6;
bool ldown = false;
int flag = 0, flag_ctrl = 0, tamanio_img_x = 600, tamanio_img_y = 600;
int x, y, x_inicial, y_inicial, figura, R=0,G=0,B=0, grosor = 1;
string IN_img = "Imagen", IN_opciones = "Opciones";

void on_trackbar_filtros(int pos, void *)
{
    if(pos == 0)
    {
        img.copyTo(modificada);
        imshow(IN_img,modificada);

        rectangle(opciones, Point(0, 0), Point(200, 50), Scalar(255,255,255),
                   -1, LINE_8, 0);
        putText(opciones, "Original", Point(0,30), FONT_HERSHEY_COMPLEX,
                 tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
        imshow(IN_opciones, opciones);
    }
    else if(pos == 1)
    {
        img.copyTo(modificada);
        Mat kernel(3,3,CV_32F,Scalar(0));
        kernel.at<float>(1,1)= 2.0/9.0;
        kernel.at<float>(0,0)= 1.0/9.0;
        kernel.at<float>(1,0)= 1.0/9.0;
        kernel.at<float>(2,0)= 1.0/9.0;
        kernel.at<float>(0,1)= 1.0/9.0;
        kernel.at<float>(2,1)= 1.0/9.0;
        kernel.at<float>(0,2)= 1.0/9.0;
        kernel.at<float>(1,2)= 1.0/9.0;
        kernel.at<float>(2,2)= 1.0/9.0;
        // Convolución
        filter2D(img,modificada,img.depth(),kernel);
        imshow(IN_img,modificada);

        rectangle(opciones, Point(0, 0), Point(200, 50), Scalar(255,255,255),
                   -1, LINE_8, 0);
        putText(opciones, "Paso bajo", Point(0,30), FONT_HERSHEY_COMPLEX,
                 tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
        imshow(IN_opciones, opciones);
    }
    else if(pos == 2)
    {
        img.copyTo(modificada);
        Mat kernel(3,3,CV_32F,Scalar(0));
        // asigna valores para máscara (kernel)
        kernel.at<float>(1,1)= 6.0/9.0;
        kernel.at<float>(0,0)= 1.0/9.0;
        kernel.at<float>(1,0)= 1.0/9.0;
        kernel.at<float>(2,0)= 1.0/9.0;
        kernel.at<float>(0,1)= 1.0/9.0;
        kernel.at<float>(2,1)= 1.0/9.0;
        kernel.at<float>(0,2)= 1.0/9.0;
        kernel.at<float>(1,2)= 1.0/9.0;
        kernel.at<float>(2,2)= 1.0/9.0;
        // Convolución
        filter2D(img,modificada,img.depth(),kernel);
        imshow(IN_img,modificada);

        rectangle(opciones, Point(0, 0), Point(200, 50), Scalar(255,255,255),
                   -1, LINE_8, 0);
        putText(opciones, "Paso alto", Point(0,30), FONT_HERSHEY_COMPLEX,
                 tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
        imshow(IN_opciones, opciones);
    }
    else if(pos == 3)
    {
        img.copyTo(modificada);
        Mat kernel(3,3,CV_32F,Scalar(0));
        kernel.at<float>(1,1)= 9.0;//9.0;
        kernel.at<float>(0,0)= -1.0;//9.0;
        kernel.at<float>(1,0)= -1.0;//9.0;
        kernel.at<float>(2,0)= -1.0;//9.0;
        kernel.at<float>(0,1)= -1.0;//9.0;
        kernel.at<float>(2,1)= -1.0;//9.0;
        kernel.at<float>(0,2)= -1.0;//9.0;
        kernel.at<float>(1,2)= -1.0;//9.0;
        kernel.at<float>(2,2)= -1.0;//9.0;
        // Convolución
        filter2D(img,modificada,img.depth(),kernel);
        imshow(IN_img,modificada);

        rectangle(opciones, Point(0, 0), Point(200, 50), Scalar(255,255,255),
                   -1, LINE_8, 0);
        putText(opciones, "Sharpen", Point(0,30), FONT_HERSHEY_COMPLEX,
                 tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
        imshow(IN_opciones, opciones);
    }
    else if(pos == 4)
    {
        destroyWindow("Sobel Filter X");
        destroyWindow("Sobel Filter Y");
        img.copyTo(modificada);
        Mat kernel(3,3,CV_32F,Scalar(0));
        kernel.at<float>(1,1)= 0.0;//9.0;
        kernel.at<float>(0,0)= 5.0;//9.0;
        kernel.at<float>(1,0)= -3.0;//9.0;
        kernel.at<float>(2,0)= -3.0;//9.0;
        kernel.at<float>(0,1)= 5.0;//9.0;
        kernel.at<float>(2,1)= -3.0;//9.0;
        kernel.at<float>(0,2)= 5.0;//9.0;
        kernel.at<float>(1,2)= -3.0;//9.0;
        kernel.at<float>(2,2)= -3.0;//9.0;
        // Convolución
        filter2D(img,modificada,img.depth(),kernel);
        imshow(IN_img,modificada);

        rectangle(opciones, Point(0, 0), Point(200, 50), Scalar(255,255,255),
                   -1, LINE_8, 0);
        putText(opciones, "Kirsch", Point(0,30), FONT_HERSHEY_COMPLEX,
                 tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
        imshow(IN_opciones, opciones);
    }
    else if(pos == 5)
    {
        Mat grey, sobelX, sobelY, sobel1;
        cvtColor(img, grey, CV_BGR2GRAY);
        Sobel(grey, sobelX, CV_32F, 1, 0);
        Sobel(grey, sobelY, CV_32F, 0, 1);
        double minVal1, maxVal1;
        minMaxLoc(sobelX, &minVal1, &maxVal1);
        draw1;
        sobelX.convertTo(draw1, CV_8U, 255.0/(maxVal1 - minVal1),
                          -minVal1 * 255.0/(maxVal1 - minVal1));
       // imshow("Sobel Filter X", draw1);
        double minVal2, maxVal2;
        minMaxLoc(sobelY, &minVal2, &maxVal2);
        draw2;
        sobelY.convertTo(draw2, CV_8U, 255.0/(maxVal2 - minVal2),
                          -minVal2 * 255.0/(maxVal2 - minVal2));
       // imshow("Sobel Filter Y", draw2);
        sobel1= abs(sobelX)+abs(sobelY);
        double minVal, maxVal;
        minMaxLoc(sobel1, &minVal, &maxVal);
        Mat draw;
        sobel1.convertTo(draw,CV_8U,-255./maxVal, 255);
        imshow(IN_img, draw2);
        rectangle(opciones, Point(0, 0), Point(200, 50), Scalar(255,255,255),
                   -1, LINE_8, 0);
        putText(opciones, "Sobel", Point(0,30), FONT_HERSHEY_COMPLEX,
                 tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
        imshow(IN_opciones, opciones);
    }
}



int main()
{
    int slider_filtros = 0;
    int slider_max_filtros = 5;
    img = imread("C:/imagenes/paisajes/ejemplo3.jpg");
    namedWindow(IN_img);
    imshow(IN_img,img);
    opciones.create(50,400, CV_8UC1);
    opciones.setTo(255);
    putText(opciones, "Original", Point(0,30), FONT_HERSHEY_COMPLEX,
             tamanio_letra, Scalar(0,0,0), 1, LINE_8, false);
    namedWindow(IN_opciones);
    imshow(IN_opciones, opciones);
    createTrackbar("FILTROS <->",IN_opciones, &slider_filtros,
                    slider_max_filtros, on_trackbar_filtros);
    waitKey();
    return 0;
}


/*// Ejemplo convolución (usando filter2D) - filtro paso alto

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("C:/imagenes/ejemplo15.jpg");
    imshow("Original",img);
    Mat img2;
    Mat kernel(3,3,CV_32F,Scalar(0));
    // asigna valores para máscara (kernel)
    kernel.at<float>(1,1)= 15.0/9.0;
    kernel.at<float>(0,1)= 1.0/9.0;
    kernel.at<float>(1,2)= 1.0/9.0;
    kernel.at<float>(2,1)= 1.0/9.0;
    kernel.at<float>(1,0)= 1.0/9.0;
    // Convolución
    filter2D(img,img2,img.depth(),kernel);
    imshow("Convolucion con kernel",img2);
    cout << "Presiona cualquier tecla para salir..." << endl;
    waitKey();
    return 0;
}
/*/
/*
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;

int main()
{
    Mat src = imread("C:/imagenes/ejemplo15.jpg");
    Mat grey, sobelX, sobelY, sobel1;
    cvtColor(src, grey, CV_BGR2GRAY);
    Sobel(grey, sobelX, CV_32F, 1, 0);
    Sobel(grey, sobelY, CV_32F, 0, 1);
    double minVal1, maxVal1;
    minMaxLoc(sobelX, &minVal1, &maxVal1);
    Mat draw1;
    sobelX.convertTo(draw1, CV_8U, 255.0/(maxVal1 - minVal1), -minVal1 * 255.0/(maxVal1 - minVal1));
    imshow("Sobel Filter X", draw1);
    double minVal2, maxVal2;
    minMaxLoc(sobelY, &minVal2, &maxVal2);
    Mat draw2;
    sobelY.convertTo(draw2, CV_8U, 255.0/(maxVal2 - minVal2), -minVal2 * 255.0/(maxVal2 - minVal2));
    imshow("Sobel Filter Y", draw2);

    sobel1= abs(sobelX)+abs(sobelY);
    double minVal, maxVal;
    minMaxLoc(sobel1, &minVal, &maxVal);
    Mat draw;
    sobel1.convertTo(draw,CV_8U,-255./maxVal, 255);
    imshow("Sobel Final", draw);
    waitKey(0);
    return 0;
}
*/
