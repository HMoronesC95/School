#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int f_d=0,f_e=0,f_o=0,f_c=0,f_s=0;
Mat opciones,img,img_gray,img_gray1,img_d,img_e,img_o,img_c,binary, mfblur;
string IN_img = "Imagen", IN_opciones = "Opciones";

void on_trackbar_dilation(int pos,void *)
{
    f_d=pos;
    if (f_d==1)
        {
          Mat element1 = getStructuringElement(0,Size(11,11),Point(5,5));
          dilate(img,img_d,element1);
          namedWindow( IN_img, CV_WINDOW_AUTOSIZE );
          imshow( IN_img, img);
          namedWindow( "Image Dilation", CV_WINDOW_AUTOSIZE );
          imshow( "Image Dilation", img_d);
        }
     if (f_d==0)
        {
          destroyWindow("Image Dilation");
        }
}

void on_trackbar_erosion(int pos,void *)
{
    f_e=pos;
    if (f_e==1)
        {
          Mat element2 = getStructuringElement(0,Size(11,11),Point(5,5));
          erode(img,img_e,element2);
          namedWindow( IN_img, CV_WINDOW_AUTOSIZE );
          imshow( IN_img, img);
          namedWindow( "Image Erosion", CV_WINDOW_AUTOSIZE );
          imshow( "Image Erosion", img_e);
        }
    if (f_e==0)
        {
          destroyWindow("Image Erosion");
        }
}

void on_trackbar_open(int pos,void *)
{
    f_o=pos;
    if (f_o==1)
        {
          Mat element3 = getStructuringElement(0,Size(11,11),Point(5,5));
          morphologyEx(img,img_o,MORPH_OPEN, element3);
          namedWindow( IN_img, CV_WINDOW_AUTOSIZE );
          imshow( IN_img, img);
          namedWindow( "Image Open", CV_WINDOW_AUTOSIZE );
          imshow( "Image Open", img_o);
        }
    if (f_o==0)
        {
          destroyWindow("Image Open");
        }
}

void on_trackbar_close(int pos,void *)
{
    f_c=pos;
    if (f_c==1)
        {
          Mat element4 = getStructuringElement(0,Size(11,11),Point(5,5));
          morphologyEx(img,img_c,MORPH_CLOSE, element4);
          namedWindow( IN_img, CV_WINDOW_AUTOSIZE );
          imshow( IN_img, img);
          namedWindow( "Image Close", CV_WINDOW_AUTOSIZE );
          imshow( "Image Close", img_c);
        }
    if (f_c==0)
        {
          destroyWindow("Image Close");
        }
}

void on_trackbar_skeletonization(int pos,void *)
{
    f_s=pos;
    if (f_s==1)
        {
             threshold(img, binary, 70, 255, CV_THRESH_BINARY);
             medianBlur(binary, mfblur, 1);
             Mat skel(mfblur.size(), CV_8UC1, Scalar(0));
             Mat temp;
             Mat eroded;
             Mat element5 = getStructuringElement(MORPH_CROSS, Size(3,3));
             bool done;
             int iterations=0;

             do
             {
               erode(mfblur, eroded, element5);
               dilate(eroded, temp, element5);
               subtract(mfblur, temp, temp);
               bitwise_or(skel, temp, skel);
               eroded.copyTo(mfblur);

               done = (countNonZero(mfblur) == 0);
               iterations++;

             }
              while (!done && (iterations < 100));
             imshow(IN_img, img);
             imshow("skeleton", skel);
             waitKey();
        }

    if (f_s==0)
        {
          destroyWindow("skeleton");
        }
}

int main()
{
    int slider_dilation=1,slider_erosion=1,slider_open=1,slider_close=1,slider_skel=1;
    int slider = 0;

    int slider_filtros = 0, slider_max_filtros = 5;

    opciones.create(50,400, CV_8UC1);
    opciones.setTo(255);
    putText(opciones, IN_img, Point(0,30), FONT_HERSHEY_COMPLEX,
             2, Scalar(0,0,0), 1, LINE_8, false);

    img = imread( "C:/imagenes/instrumentos/ejemplo8.jpg",1 );
    cvtColor( img, img, CV_BGR2GRAY );
    namedWindow(IN_opciones);

    createTrackbar("Dilatation",IN_opciones, &slider, slider_dilation, on_trackbar_dilation);
    createTrackbar("Erosion",IN_opciones, &slider, slider_erosion, on_trackbar_erosion);
    createTrackbar("Open",IN_opciones, &slider, slider_open, on_trackbar_open);
    createTrackbar("Close",IN_opciones, &slider, slider_close, on_trackbar_close);
    createTrackbar("Skeletonization",IN_opciones, &slider, slider_skel, on_trackbar_skeletonization);

    waitKey(0);
    return 0;
}

