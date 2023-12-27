#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

Mat img, copia, img_extraccion;
bool ldown = false;
int flag = 0, tamanio_img_x, tamanio_img_y;
int x_inicial, y_inicial, x_final, y_final, pmenor_r=255, pmayor_r=0,
 pmenor_g=255, pmayor_g=0, pmenor_b=255, pmayor_b=0;
float valorR,valorG,valorB;
int B, G, R, H, S, V;
string  IN_img = "Imagen", IN_imghsv = "Imagen hsv",
IN_img_informacion = "Extraccion de informacion";

void extraccion_informacion()
{
    pmenor_r = 255;
    pmayor_r = 0;

    pmenor_g = 255;
    pmayor_g = 0;

    pmenor_b = 255;
    pmayor_b = 0;

    for(int i=x_inicial; i<x_final; i++)
    {
        for(int j=y_inicial; j<y_final; j++)
        {
            img_extraccion.at<Vec3b>(j,i)[0] = img.at<Vec3b>(j,i)[0];
            img_extraccion.at<Vec3b>(j,i)[1] = img.at<Vec3b>(j,i)[1];
            img_extraccion.at<Vec3b>(j,i)[2] = img.at<Vec3b>(j,i)[2];
        }
    }

    for(int i=x_inicial; i<x_final; i++)
    {
        for(int j=y_inicial; j<y_final; j++)
        {
            if(img.at<Vec3b>(j,i)[0] < pmenor_b)
                pmenor_b = img.at<Vec3b>(j,i)[0];
            if(img.at<Vec3b>(j,i)[0] > pmayor_b)
                pmayor_b = img.at<Vec3b>(j,i)[0];

            if(img.at<Vec3b>(j,i)[1] < pmenor_g)
                pmenor_g = img.at<Vec3b>(j,i)[1];
            if(img.at<Vec3b>(j,i)[1] > pmayor_g)
                pmayor_g = img.at<Vec3b>(j,i)[1];

            if(img.at<Vec3b>(j,i)[2] < pmenor_r)
                pmenor_r = img.at<Vec3b>(j,i)[2];
            if(img.at<Vec3b>(j,i)[2] > pmayor_r)
                pmayor_r = img.at<Vec3b>(j,i)[2];
        }
    }
    inRange(img, Scalar(pmenor_b, pmenor_g, pmenor_r),
            Scalar(pmayor_b, pmayor_g, pmayor_r), img_extraccion);
    imshow(IN_img_informacion,img_extraccion);
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
        x_inicial = x;
        y_inicial = y;

        if (ldown == false)
        {
            img.copyTo(copia);
            ldown = true;
        }

        Mat img_hsv=img.clone();

        Vec3b rgb=img_hsv.at<Vec3b>(y,x);
        int B=rgb.val[0];
        int G=rgb.val[1];
        int R=rgb.val[2];

        Mat HSV;
        Mat RGB=img_hsv(Rect(x,y,1,1));
        cvtColor(RGB, HSV,CV_BGR2HSV);

        Vec3b hsv=HSV.at<Vec3b>(0,0);
        int H=hsv.val[0];
        int S=hsv.val[1];
        int V=hsv.val[2];

     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "\nRight button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "\nMiddle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_LBUTTONUP )
     {
        if (ldown == true)
        {
            ldown = false;
        }
          if(x < 0)
            x = 0;
          if(x > tamanio_img_x)
            x = tamanio_img_x;
          if(y < 0)
            y = 0;
          if(y > tamanio_img_y)
            y = tamanio_img_y;

        if (sqrt(abs(pow((y-y_inicial),2) + pow((x-x_inicial),2))) > 5)
        {
            x_final = x;
            y_final = y;
            imshow(IN_img, img);
            extraccion_informacion();
        }
        else
        {
            imshow(IN_img, img);
        }
     }
     else if (event == EVENT_MOUSEMOVE)
     {
         img.copyTo(copia);

         if(ldown == true)
         {
             rectangle(copia, Point(x_inicial, y_inicial),
                       Point(x, y), Scalar(B,G,R), 1, LINE_8, 0);
             imshow(IN_img, copia);
         }
     }
}

int main()
{
    img = imread("C:/imagenes/ejemplo20.jpg",CV_LOAD_IMAGE_UNCHANGED);
    namedWindow(IN_img);
    imshow(IN_img, img);

    tamanio_img_x = img.cols, tamanio_img_y = img.rows;

    img_extraccion.create(tamanio_img_y,tamanio_img_x, CV_8UC3);

    copia.create(tamanio_img_x,tamanio_img_y, CV_8UC3);
    img.copyTo(copia);

    setMouseCallback("Imagen", CallBackFunc, NULL);

  while(true)
  {
    int c;
    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }
}
//*/////
