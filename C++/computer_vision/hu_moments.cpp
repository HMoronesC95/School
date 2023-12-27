//*MOMENTOS
//*
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <iostream>
#define IN "Imagen de Entrada"

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread( "C:/imagenes/figuras_bmp/ejemplo19_bitmap.bmp",
                      CV_LOAD_IMAGE_GRAYSCALE);

    vector<vector<Point> > contours;

    findContours(img, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    vector<vector<Point> >::iterator itc;
    static int label=0;
    itc= contours.begin();
    while (itc!=contours.end())
    {
        // calcula los momentos
        Moments mom= moments(Mat(*itc++));
        // Dibuja centro (centroide)
        int x=mom.m10/mom.m00;
        int y=mom.m01/mom.m00;

        float excentricidad =((pow(mom.nu20-mom.nu02,2))+4*(pow(mom.nu11,2)))/
                                        (pow(mom.nu20+mom.nu02,2));
        float teta = (1.0/2.0)*atan((2.0*mom.nu11)/(mom.nu20-mom.nu02));
        float angulo = teta*180.0/M_PI;

        cout<< "Centro figura " <<label<<" = "<<x <<","<<y<<endl;
        label++;// Incrementa el numero usado para la etiqueta
        circle(img,{x,y},3,0,4,CV_AA,0);

        char strgLabel[] = "Etiqueta XX";
        sprintf(strgLabel, "%d", label);
        putText(img, strgLabel, Point(x,y+40), 6, 1,Scalar(100,100,255),2,8,0);
        cout<<excentricidad<<endl<<angulo<<endl;

        //calcula los momentos de hu
        double huMoments[7];
        HuMoments(mom,huMoments);
        //log10 scale humoments
        for(int i=0; i<7; i++)
        {
            huMoments[i] = -1*copysign(1.0,huMoments[i])*log10(abs(huMoments[i]));
        }
        cout<<"\n"<<huMoments[0]<<"\n"<<huMoments[1]<<"\n"<<huMoments[2]<<"\n"
        <<huMoments[3]<<"\n"<<huMoments[4]<<"\n"<<huMoments[5]<<"\n"<<huMoments[6];

        cout<<"\n\n";

    }
    namedWindow("Salida");
    imshow( "Salida", img );
    waitKey();
    return 0;
}

//*/
/*
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread( "C:/imagenes/figuras_bn/ejemplo25.jpg", CV_LOAD_IMAGE_GRAYSCALE);
                                            //mp/ejemplo24_bitmap.bmp
    vector<vector<Point> > contours;
    //findContours(img2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    findContours(img, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    vector<vector<Point> >::iterator itc;
    static int label=0;
    itc= contours.begin();
    while (itc!=contours.end())
    {
        *itc++;
        label++;// Incrementa el numero usado para la etiqueta
    }

    cout << "Tu imagen tiene " <<label<< " figuras"<< endl;
    cout << "Presiona cualquier tecla para salir..." << endl;
    waitKey();
    return 0;
}
/*/
/*
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <iostream>
#define IN "Imagen de Entrada"

using namespace std;
using namespace cv;

float excen;
float teta;
float ang;

int main()
{
    //Mat img = imread( "D:/Downloads/oct1.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    Mat img = imread( "C:/imagenes/figuras_bmp/ejemplo24_bitmap.bmp", CV_LOAD_IMAGE_GRAYSCALE);

    vector<vector<Point> > contours;
    //findContours(img2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    findContours(img, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    vector<vector<Point> >::iterator itc;
    static int label=0;
    itc= contours.begin();
    while (itc!=contours.end())
    {
        // calcula los momentos
        Moments mom= moments(Mat(*itc++));

        // Dibuja centro (centroide)
        int x=mom.m10/mom.m00;
        int y=mom.m01/mom.m00;

        excen =((pow(mom.nu20-mom.nu02,2))+4*(pow(mom.nu11,2)))/(pow(mom.nu20+mom.nu02,2));
        teta = (1.0/2.0)*atan((2.0*mom.nu11)/(mom.nu20-mom.nu02));
        ang= teta*180.0/M_PI;

        cout<< "Centro figura " <<label<<" = "<<x <<","<<y<<endl;
        label++;// Incrementa el numero usado para la etiqueta
        circle(img,{x,y},3,0,4,CV_AA,0);

        char strgLabel[] = "Etiqueta xx";
        sprintf(strgLabel, "Etiqueta %d", label);
        putText(img, strgLabel, Point(x,y+40), 6, 1,128,3,8,0);
        cout<<excen<<endl<<ang<<endl;
        //putText(img, "Figura "+cadena, Point (x,y+10), 4, 3, Scalar (128), 3, 8, 0);



    }

    cout << "Presiona cualquier tecla para salir..." << endl;
    namedWindow("2");
    imshow( "2", img );
    waitKey();
    return 0;
}
*/
