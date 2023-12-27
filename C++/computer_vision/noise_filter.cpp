#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <time.h>

using namespace cv;
using namespace std;
void salt(Mat image, int n)
{
     int i,j,i_pepper,j_pepper;
     for (int k=0; k<n; k++)
     {
         // rand() is the random number generator
         i= rand()%image.cols;
         j= rand()%image.rows;
         i_pepper= rand()%image.cols;
         j_pepper= rand()%image.rows;
         if (image.type() == CV_8UC1)
         { // gray-level image
             image.at<uchar>(j,i)= 255;

             image.at<uchar>(j_pepper,i_pepper)= 0;
         }
         else if (image.type() == CV_8UC3)
         { // color image
             image.at<Vec3b>(j,i)[0]= 255;
             image.at<Vec3b>(j,i)[1]= 255;
             image.at<Vec3b>(j,i)[2]= 255;

             image.at<Vec3b>(j_pepper,i_pepper)[0]= 0;
             image.at<Vec3b>(j_pepper,i_pepper)[1]= 0;
             image.at<Vec3b>(j_pepper,i_pepper)[2]= 0;
         }
     }
}
int main()
{
     // open the image
     Mat image = imread("C:/imagenes/ejemplo18.jpg");

     srand(time(NULL));

     salt(image,5000);
     // display image
     namedWindow("Image");
     imshow("Image",image);
     imwrite("C:/imagenes/ejemplo18_sal.jpg", image);
     Mat image_median, image_blur;
     medianBlur(image, image_median, 3);
     imshow("median", image_median);
     blur(image,image_blur, Size(10,10),Point(-1,-1));
     imshow("blur", image_blur);

     waitKey(); // Wait for key press
     return 0;
}
