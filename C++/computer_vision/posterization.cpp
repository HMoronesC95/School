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

    Mat img = imread("C:/imagenes/rostros/ejemplo15.jpg",CV_LOAD_IMAGE_UNCHANGED);
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
