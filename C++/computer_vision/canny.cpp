//Canny
//*
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int upperTh = 0, centerTh = 100, Amplitude = 3, Ksize = 0;
float Sigma = 0.02;
Mat img, img_gray, imgBlurred, imgCanny, filtros;
string IN_img = "Imagen", IN_filtros = "Filtros";

void on_trackbar_upperTh(int pos, void *)
{
    upperTh = pos;
}

void on_trackbar_HIghTh(int pos, void *)
{
    centerTh = pos;
}

void on_trackbar_Amp(int pos, void *)
{
    switch (pos)
    {
        case 0 : Amplitude = 1; break;
        case 1 : Amplitude = 3; break;
        case 2 : Amplitude = 5; break;
        case 3 : Amplitude = 7; break;
        default : Amplitude = 3; break;
    }
}

void on_trackbar_Ksize(int pos, void *)
{
    switch (pos)
    {
        case 0 : Ksize = 1; break;
        case 1 : Ksize = 3; break;
        case 2 : Ksize = 5; break;
        case 3 : Ksize = 7; break;
        default : Ksize = 5; break;
    }
}

void on_trackbar_Sigma(int pos, void *)
{
    Sigma = 0.02 * pos;
}


int main( )
{
    VideoCapture capWebcam(0);

     if (capWebcam.isOpened() == false)
     {
        cout << "error: Webcam connect unsuccessful\n";
        return(0);
     }

    char charCheckForEscKey = 0;

    int slider_HighTh = 100, slider_LowTh = 0, slider_Amp = 0, slider_Ksize = 0,
                                        slider_Sigma = 0;
    int slider_max_HighTh = 100, slider_max_LowTh = 100, slider_max_Amp = 3,
                                    slider_max_Ksize = 5, slider_max_Sigma = 100;

    filtros.create(200,400, CV_8UC1);
    filtros.setTo(255);
    namedWindow(IN_filtros);
    imshow(IN_filtros, filtros);

    createTrackbar("KSIZE <->",IN_filtros, &slider_Ksize, slider_max_Ksize, on_trackbar_Ksize);
    createTrackbar("SIGMA <->",IN_filtros, &slider_Sigma, slider_max_Sigma, on_trackbar_Sigma);

    createTrackbar("LOWTH <->",IN_filtros, &slider_LowTh, slider_max_LowTh, on_trackbar_upperTh);
    createTrackbar("HIGHTH <->",IN_filtros, &slider_HighTh, slider_max_HighTh, on_trackbar_HIghTh);
    createTrackbar("AMP <->",IN_filtros, &slider_Amp, slider_max_Amp, on_trackbar_Amp);

    while (charCheckForEscKey != 27 && capWebcam.isOpened())
    {
        bool blnFrameReadSuccessfully = capWebcam.read(img);
        if (!blnFrameReadSuccessfully || img.empty())
        {
            cout << "error: frame can't read \n";
            break;
        }
        cvtColor(img, img_gray, CV_BGR2GRAY);
        GaussianBlur(img_gray,imgBlurred,Size(Ksize, Ksize),Sigma);
        Canny(imgBlurred,imgCanny,upperTh,centerTh,Amplitude);
        namedWindow(IN_img, CV_WINDOW_NORMAL);
        namedWindow("imgCanny", CV_WINDOW_NORMAL);
        imshow(IN_img, img);
        imshow("imgCanny", imgCanny);
        charCheckForEscKey = waitKey(1);
    }
}

//*/
/*
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>

int main() {
 cv::VideoCapture capWebcam(0);   // declare a VideoCapture object to associate webcam, 0 means use 1st (default) webcam

 if (capWebcam.isOpened() == false)  //  To check if object was associated to webcam successfully
 {
  std::cout << "error: Webcam connect unsuccessful\n"; // if not then print error message
  return(0);            // and exit program
 }

 cv::Mat imgOriginal;        // input image
 cv::Mat imgGrayscale;       // grayscale image
 cv::Mat imgBlurred;         // blured image
 cv::Mat imgCanny;           // Canny edge image

 char charCheckForEscKey = 0;
 int lowTh = 45;
 int highTh = 90;

 while (charCheckForEscKey != 27 && capWebcam.isOpened()) {            // until the Esc key is pressed or webcam connection is lost
  bool blnFrameReadSuccessfully = capWebcam.read(imgOriginal);   // get next frame

  if (!blnFrameReadSuccessfully || imgOriginal.empty()) {    // if frame read unsuccessfully
   std::cout << "error: frame can't read \n";      // print error message
   break;
  }

  cv::cvtColor(imgOriginal, imgGrayscale, CV_BGR2GRAY);                   // convert to grayscale

  cv::GaussianBlur(imgGrayscale,imgBlurred,cv::Size(5, 5),1.8);           // Blur Effect

  cv::Canny(imgBlurred,imgCanny,lowTh,highTh);       // Canny Edge Image

  //declare windows
  cv::namedWindow("imgOriginal", CV_WINDOW_NORMAL);
  cv::namedWindow("imgCanny", CV_WINDOW_NORMAL);
  //declare trackbar
  cv::createTrackbar("LowTh", "imgCanny", &lowTh, 100);
  cv::createTrackbar("HighTh", "imgCanny", &highTh, 100);
  // show windows
  cv::imshow("imgOriginal", imgOriginal);
  cv::imshow("imgCanny", imgCanny);

  charCheckForEscKey = cv::waitKey(1);        // delay and get key press
 }

 return(0);
}
*/
