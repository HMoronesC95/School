/*///////THRESHOLD
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables

int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat src, src_gray, dst;
char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Value";

/// Function headers
void Threshold_Demo( int, void* );


 // @function main

int main()
{
  /// Load an image
  src = imread("C:/imagenes/ejemplo15.jpg");

  /// Convert the image to Gray
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// Create a window to display results
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  /// Create Trackbar to choose type of Threshold
  createTrackbar( trackbar_type,
                  window_name, &threshold_type,
                  max_type, Threshold_Demo );

  createTrackbar( trackbar_value,
                  window_name, &threshold_value,
                  max_value, Threshold_Demo );

  /// Call the function to initialize
  Threshold_Demo( 0, 0 );

  /// Wait until user finishes program
  while(true)
  {
    int c;
    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }

}



 //* @function Threshold_Demo

void Threshold_Demo( int, void* )
{
  // 0: Binary
  // 1: Binary Inverted
  // 2: Threshold Truncated
  // 3: Threshold to Zero
  // 4: Threshold to Zero Inverted


  threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );

  imshow( window_name, dst );
}
*///////
//*///////POSTERIZACION
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    int mask=0b00000000,x ;

   while(mask==0b00000000)
   {
        cout<<"\n\nIngrese el numero de tonos:\n";
        cin>>x;
        switch (x)
        {
            case 2 : mask = 0b10000000; break;
            case 4 : mask = 0b11000000; break;
            case 8 : mask = 0b11100000; break;
            case 16 : mask = 0b11110000; break;
            case 32 : mask = 0b11111000; break;
            case 64 : mask = 0b11111100; break;
            case 128 : mask = 0b11111110; break;
            case 256 : mask = 0b11111111; break;
            default : cout <<"\n\nValor de mascara invalido, solo potencias de 2\n\n";
            waitKey();
        }
   }

    Mat img = imread("C:/imagenes/ejemplo15.jpg",CV_LOAD_IMAGE_UNCHANGED);
    namedWindow("Original");
    imshow("Original", img);

    int col = img.cols, row = img.rows;

    if(img.type() == 0)
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                img.at<uchar>(i,j) = img.at<uchar>(i,j) & mask;
            }

        }
        imshow("Posterizada", img);
    }
    else if(img.type() == 16)
    {
        Mat merged;
        vector<Mat> Bands(3);
        split(img, Bands);

        vector<Mat> channels = {Bands[0],Bands[1],Bands[2]};

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                for(int k =0; k<3; k++)
                {
                    img.at<Vec3b>(i,j)[k] = img.at<Vec3b>(i,j)[k] & mask;
                }
            }
        }
        merge(channels,merged);
        imshow("merged",merged);
        imshow("Posterizada",img);
    }
  /// Wait until user finishes program
  while(true)
  {
    int c;
    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }

}
/*/////////UMBRALIZACION
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;


Mat img,out;
int lowerb = 0, upperb = 0;
string IN_ejemplo = "EJEMPLO";

void on_trackbar_lowerb(int pos, void *)
{
    lowerb = pos;
    imshow("EJEMPLO", out);

}

void on_trackbar_upperb(int pos, void *)
{
    upperb = pos;
    imshow("EJEMPLO", out);

}


int main()
{
    int slider_lowerb = 0,slider_upperb = 0;
    int slider_max_lowerb = 255, slider_max_upperb = 255;


    Mat img = imread("C:/imagenes/ejemplo15.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    namedWindow("Dibujos");
    imshow("Dibujos", img);

    out.create(img.rows,img.cols, CV_8UC1);


   inRange(img, Scalar(lowerb), Scalar(upperb), out);


    imshow("EJEMPLO", img);


    createTrackbar("LOWERB <->",IN_ejemplo, &slider_lowerb, slider_max_lowerb,on_trackbar_lowerb);
    createTrackbar("UPPERB <->",IN_ejemplo, &slider_upperb, slider_max_upperb,on_trackbar_upperb);



  /// Wait until user finishes program
  while(true)
  {
    int c;
    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }

}
*////


