//cubica
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#define IN "Imagen de Entrada"

using namespace std;
using namespace cv;

int main()
{

    Mat img = imread( "C:/imagenes/ejemplo22_bitmap.bmp", CV_LOAD_IMAGE_UNCHANGED);
    Mat img_resized(img.rows, img.cols, CV_32F);
    img.copyTo(img_resized);
    Size sz;

   // for(int i=0;i<9;i++)
  //  {
        //img_resized(img.rows*1.1, img.cols*1.1, CV_32F);
        Mat img_resized0(img_resized.rows*1.1, img_resized.cols*1.1, CV_32F);
        sz = img_resized0.size();
        resize(img_resized,img_resized0,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized1(img_resized0.rows*1.1, img_resized0.cols*1.1, CV_32F);
        sz = img_resized1.size();
        resize(img_resized0,img_resized1,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized2(img_resized1.rows*1.1, img_resized1.cols*1.1, CV_32F);
        sz = img_resized2.size();
        resize(img_resized1,img_resized2,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized3(img_resized2.rows*1.1, img_resized2.cols*1.1, CV_32F);
        sz = img_resized3.size();
        resize(img_resized2,img_resized3,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized4(img_resized3.rows*1.1, img_resized3.cols*1.1, CV_32F);
        sz = img_resized4.size();
        resize(img_resized3,img_resized4,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized5(img_resized4.rows*1.1, img_resized4.cols*1.1, CV_32F);
        sz = img_resized5.size();
        resize(img_resized4,img_resized5,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized6(img_resized5.rows*1.1, img_resized5.cols*1.1, CV_32F);
        sz = img_resized6.size();
        resize(img_resized5,img_resized6,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized7(img_resized6.rows*1.1, img_resized6.cols*1.1, CV_32F);
        sz = img_resized7.size();
        resize(img_resized6,img_resized7,sz,0.0f,0.0f,INTER_CUBIC);

        Mat img_resized8(img_resized7.rows*1.1, img_resized7.cols*1.1, CV_32F);
        sz = img_resized8.size();
        resize(img_resized7,img_resized8,sz,0.0f,0.0f,INTER_CUBIC);


   // }


    Mat img_resized10(img.rows*2, img.cols*2, CV_32F);
    sz = img_resized10.size();
    resize(img,img_resized10,sz,0.0f,0.0f,INTER_CUBIC);



    imshow("Original",img);
    imshow("Cubica",img_resized10);
    imshow("Escalera",img_resized6);

    waitKey();
    return 0;
}
/*///////
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image=imread("C:\\vision\\trabajos\\Imagenes\\descarga.png");
    Mat img1,img2,img3,img4,img5;

    resize(image,img1,Size(400,394));
    namedWindow("BASICA");
    imshow("BASICA",img1);

    resize(image,img2,Size(600,400),0,0,INTER_LANCZOS4);
    namedWindow("LANCZOS");
    imshow("LANCZOS",img2);


resize(image,img3,Size(400,400),0,0,INTER_NEAREST);
    namedWindow("VECINO");
    imshow("VECINO",img3);


    resize(image,img4,Size(400,300),-1,-1,INTER_CUBIC);
    namedWindow("CUBICA");
    imshow("CUBICA",img4);


    resize(image,img5,Size(100,100),1,1,INTER_AREA);
    namedWindow("AREA");
    imshow("AREA",img5);

    imshow("ORIGINAL",image);
    waitKey(0);
    return 0;
}
*//////
