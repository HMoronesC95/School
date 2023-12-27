//*// DIBUJAR HISTOGRAMA v1 (GRIS)
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main()
{
     int histSize = 255;
     Mat hist, gris;
     //Leer Imagen original
     Mat img = imread( "C:/imagenes/ejemplo15.jpg");
     //Convert color image to gray level image
     cvtColor(img, gris, CV_RGB2GRAY);
     //Crea 3 ventanas de trabajo
     namedWindow("Imagen Original");
     namedWindow("Imagen en Niveles de Gris");
     namedWindow("Histograma");
     imshow("Imagen Original", img);
     imshow("Imagen en Niveles de Gris", gris);
     calcHist(&gris, 1, 0, Mat(), hist, 1, &histSize, 0);
     Mat histImage = Mat::ones(255, 255, CV_8U)*255;
     normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);
     int binW = cvRound((double)histImage.cols/histSize);
     for( int i = 0; i < histSize; i++ )
     {
        rectangle( histImage, Point(i*binW, histImage.rows),
        Point((i+1)*binW, histImage.rows-cvRound(hist.at<float>(i))),
        Scalar::all(0), -1, 8, 0);
     }
     imshow("Histograma", histImage);
     cout << "Presiona cuaquier tecla para salir...\n";
     waitKey(); // Wait for key press
     return 0;
}
//*/////
/*// DIBUJAR HISTOGRAMA v2 (GRIS con lineas)

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;
int main()
{
     Mat src;
     Mat img = imread( "C:/imagenes/ejemplo15.jpg");
     //Convert color image to gray level image
     cvtColor(img, src, CV_RGB2GRAY);
     Mat dst;
     int histSize = 256;
     Mat hist;
     /// Compute the histograms:
     calcHist( &src, 1, 0, Mat(), hist, 1, &histSize, 0);

     Mat histImage = Mat::ones(255, 255, CV_8U)*255;
     normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);
     histImage = Scalar::all(255);
     int binW = cvRound((double)histImage.cols/histSize);

     for( int i = 1; i < histSize; i++ )
     {
         line( histImage, Point( binW*(i-1), histImage.rows -
        cvRound(hist.at<float>(i-1)) ) ,
         Point( binW*(i), histImage.rows - cvRound(hist.at<float>(i)) ),
         Scalar( 0, 0, 0), 2, 8, 0  );
     }
     /// Display
     namedWindow("Original Image", CV_WINDOW_AUTOSIZE );
     imshow("Original Image", src);
     namedWindow("Histograma", CV_WINDOW_AUTOSIZE );
     imshow("Histograma", histImage );
     waitKey(0);
     return 0;
}
/*////
