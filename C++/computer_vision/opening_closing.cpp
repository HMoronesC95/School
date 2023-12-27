#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
    Mat img,imgout;
    img = imread("C:/imagenes/ejemplo25_bitmap.bmp");
    imshow("original", img);

    erode(img,imgout,Mat());
    imshow("salida",imgout);
    dilate(imgout,imgout,Mat());
   //imshow("salida",imgout);


    morphologyEx(img,imgout,MORPH_CLOSE,Mat());
    imshow("salida",imgout);
  //  morphologyEx(bw,op,MORPH_OPEN,Mat());



    waitKey();
    return 0;
}
