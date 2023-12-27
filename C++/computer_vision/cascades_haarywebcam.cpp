/*
//CASCADAS DE HAAR
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#define IN "Imagen"
#define OUT "Deteccion"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat img_proc, gray;
    Mat image,img;
    image = imread("C:/imagenes/rostros/ejemplo15.jpg");
    namedWindow( IN, 1);
    imshow(IN, image);

    // Load Face cascade (.xml file)
    CascadeClassifier face_cascade;
    face_cascade.load("C:/Users/Homer/Desktop/UAQ/8_octavo semestre/vision_computadora/haarcascades/haarcascade_frontalface_alt.xml" );

	cvtColor(image, gray, CV_BGR2GRAY);
	equalizeHist(gray, img_proc);

    vector<Rect> faces;
    face_cascade.detectMultiScale(img_proc, faces, 1.2, 2, 0|CV_HAAR_SCALE_IMAGE, Size(50, 50 ));

	if(faces.size() != 0)
	{
            Point esq1(faces[0].x, faces[0].y);
            Point esq2(faces[0].x + faces[0].width, faces[0].y + faces[0].height);
            rectangle(image, esq1, esq2, CV_RGB(255,0,0), 2);
            imshow(OUT, image);
       }
      else
      {
              return 1;
      }

	waitKey();
}
*/
//CASCADAS CON WEBCAM
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#define IN "Imagen"
#define OUT "Detected Face"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat frame, frame_threshold;
    VideoCapture cap(0);
    namedWindow(IN, WINDOW_NORMAL);
    while((char)waitKey(1)!=27) // Tecla escape para salir
    {
        cap>>frame;
        if(frame.empty())
            break;
        // Load Face cascade (.xml file)
        CascadeClassifier face_cascade;
        face_cascade.load("C:/Users/Homer/Desktop/UAQ/8_octavo semestre/vision_computadora/haarcascades/haarcascade_frontalface_alt.xml" );
        // Detect faces
        vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.2, 2, 0|CV_HAAR_SCALE_IMAGE, Size(50, 50) );

        for( int i = 0; i < faces.size(); i++ )
        {
            Point esq1(faces[i].x, faces[i].y);
            Point esq2(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            rectangle(frame, esq1, esq2, CV_RGB(255,0,0), 2);
        }

        imshow(IN, frame);
    }
    return 0;
}
