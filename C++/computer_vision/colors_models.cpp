#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
//#include <stdlib.h>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{

    Mat img = imread("C:/imagenes/ejemplo18.jpg",CV_LOAD_IMAGE_UNCHANGED), img_out;
    imshow("Original", img);

//    cvtColor(MatrizOriginal, MatrizDestino, CódigoColor, Canales);

    cvtColor(img, img_out, CV_BGR2Luv, 3);
    imshow("CV_BGR2Luv", img_out);

    cvtColor(img, img_out, CV_RGB2GRAY, 3);
    imshow("CV_RGB2GRAY", img_out);

    cvtColor(img, img_out, CV_BGR2HSV, 3);
    imshow("CV_BGR2HSV", img_out);

    cvtColor(img, img_out, CV_RGB2HSV, 3);
    imshow("CV_RGB2HSV", img_out);

    cvtColor(img, img_out, CV_HSV2BGR, 3);
    imshow("CV_HSV2BGR", img_out);
/*
    cvtColor(img, img_out, CV_HSV2RGB, 3);
    imshow("CV_HSV2RGB", img_out);

    cvtColor(img, img_out, CV_BGR2HLS, 3);
    imshow("CV_BGR2HLS", img_out);

    cvtColor(img, img_out, CV_RGB2HLS, 3);
    imshow("CV_RGB2HLS", img_out);

    cvtColor(img, img_out, CV_HLS2BGR, 3);
    imshow("CV_HLS2BGR", img_out);

    cvtColor(img, img_out, CV_HLS2RGB, 3);
    imshow("CV_HLS2RGB", img_out);

    cvtColor(img, img_out, CV_BGR2Lab, 3);
    imshow("CV_BGR2Lab", img_out);

    cvtColor(img, img_out, CV_RGB2Lab, 3);
    imshow("CV_RGB2Lab", img_out);

    cvtColor(img, img_out, CV_Lab2BGR, 3);
    imshow("CV_Lab2BGR", img_out);

    cvtColor(img, img_out, CV_Lab2BGR, 3);
    imshow("CV_Lab2BGR", img_out);

    cvtColor(img, img_out, CV_Lab2RGB, 3);
    imshow("CV_Lab2RGB", img_out);

    cvtColor(img, img_out, CV_BGR2Luv, 3);
    imshow("CV_BGR2Luv", img_out);

    cvtColor(img, img_out, CV_RGB2Luv, 3);
    imshow("CV_RGB2Luv", img_out);

    cvtColor(img, img_out, CV_Luv2BGR, 3);
    imshow("CV_Luv2BGR", img_out);

    cvtColor(img, img_out, CV_Luv2RGB, 3);
    imshow("CV_Luv2RGB", img_out);

    cvtColor(img, img_out, CV_BayerBG2BGR, 3);
    imshow("CV_BayerBG2BGR", img_out);

    cvtColor(img, img_out, CV_BayerGB2BGR, 3);
    imshow("CV_BayerGB2BGR", img_out);

    cvtColor(img, img_out, CV_BayerRG2BGR, 3);
    imshow("CV_BayerRG2BGR", img_out);

    cvtColor(img, img_out, CV_BayerGR2BGR, 3);
    imshow("CV_BayerGR2BGR", img_out);

    cvtColor(img, img_out, CV_BayerBG2RGB, 3);
    imshow("CV_BayerBG2RGB", img_out);

    cvtColor(img, img_out, CV_BayerGB2RGB, 3);
    imshow("CV_BayerGB2RGB", img_out);

    cvtColor(img, img_out, CV_BayerRG2RGB, 3);
    imshow("CV_BayerRG2RGB", img_out);

    cvtColor(img, img_out, CV_BayerGR2RGB, 3);
    imshow("CV_BayerGR2RGB", img_out);

*/



    while(char(waitKey(1)) != 27)
        waitKey();
    return 0;
}
