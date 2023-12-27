/// Harris Detección Bordes
///*
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OUT "Bordes (Harris)"

using namespace cv;
using namespace std;

int thresh = 100;

int main( )
{
    Mat src, gray;
    // Load source image and convert it to gray
    src = imread ("C:/imagenes/circulos.jpg");
    cvtColor( src, gray, CV_BGR2GRAY );
    Mat dst, dst_norm, dst_norm_scaled;
    dst = Mat::zeros( src.size(), CV_32FC1 );

    // Detecting corners
    cornerHarris( gray, dst, 3, 11, 0.04, BORDER_DEFAULT );

    // Normalizing
    normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
    convertScaleAbs( dst_norm, dst_norm_scaled );

    // Drawing a circle around corners
    for( int j = 0; j < dst_norm.rows ; j++ )
    {
        for( int i = 0; i < dst_norm.cols; i++ )
        {
            if( (int) dst_norm.at<float>(j,i) > thresh )
            {
                circle( src, Point( i, j ), 5,  Scalar(0,255,0), 2, 8, 0 );
            }
        }
    }


    // Showing the result
    namedWindow(OUT, CV_WINDOW_AUTOSIZE );
    imshow(OUT, src );

    waitKey(0);
    return(0);
}
//*/
/*
/// shaytomasi8 Detección Bordes
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
using namespace std;
using namespace cv;
Mat image, image_gray;

int main()
{
    image = imread ("C:/imagenes/ejemplo23.jpg");
    cvtColor(image, image_gray, CV_RGB2GRAY);
    namedWindow("Corners");
    vector<Point2d> corners;
    goodFeaturesToTrack(image_gray, corners, 20, 0.01, 10);
    // Draw the corners as little circles
    Mat image_corners = image.clone();
    for(int i = 0; i < corners.size(); i++)
    {
        circle(image_corners, corners[i], 4, CV_RGB(255, 0, 0), -1);
    }
    imshow("Corners", image_corners);
    waitKey(0);

    return 0;
}
*/
