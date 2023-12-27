#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int videoCamera()
{
    VideoCapture capture(0);
    if(!capture.isOpened()) return 1;
    bool finish = false;
    Mat frame,copia;
    namedWindow("Original Image", CV_WINDOW_NORMAL);
    namedWindow("Copy Image", CV_WINDOW_NORMAL);

    if(!capture.read(frame)) return 1;
    while(!finish)
    {
        if(!capture.read(frame)) return 1;

        imshow("Original Image", frame);
        frame.copyTo(copia);
        cvtColor(copia, copia, CV_RGB2GRAY);
        imshow("Copy Image", copia);
        if(waitKey(1)==27) finish = true;
    }
    capture.release();
    return 0;
}


int main( )
{
    Mat img;
    img = imread("C:/imagenes/ejemplo23.jpg");
    imshow("asd", img);

    videoCamera();
}
