/*MOMENTOS
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#define IN "Imagen de Entrada"

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread( "C:/imagenes/ejemplo19_bitmap.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    threshold(img, img, 50, 255, THRESH_BINARY);
    imshow(IN, img);
    Mat img2;
    img.convertTo(img2, CV_8U);

    vector<vector<Point> > contours;
    findContours(img2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    vector<vector<Point> >::iterator itc;
    static int label=0;
    itc= contours.begin();
    while (itc!=contours.end())
    {

        // compute all moments
        Moments mom= moments(Mat(*itc++));

        // Dibuja centro (centroide)
        int x=mom.m10/mom.m00;
        int y=mom.m01/mom.m00;
        cout<< "Centro figura " <<label<<" = "<<x <<","<<y<<endl;
        label++;// Incrementa el numero usado para la etiqueta

    }

    cout << "Presiona cualquier tecla para salir..." << endl;
    waitKey();
    return 0;
}
*/
/*/////CONTEO FIGURAS
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread( "C:/imagenes/ejemplo19_bitmap.bmp", CV_LOAD_IMAGE_GRAYSCALE);
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
*/
////CONTEO Y ETIQUETADO
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#define IN "Imagen de Entrada"
#define IN2 "Imagen de Entrada (RGB)"

using namespace std;
using namespace cv;
Mat img, rgb;

int main() {
    Mat img;
    img = imread("C:/imagenes/ejemplo19_bitmap.bmp");
    cvtColor(img, img, CV_RGB2GRAY);
    imshow( "img", img );
    RNG rng(12345);
    Mat drawing = Mat::zeros( img.size(), CV_8UC3 );
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( img, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE,Point(0, 0));

    Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    drawContours( drawing, contours, 0, color, 2, 8, hierarchy ,0, Point() );
    imshow( "1", drawing );
    color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    drawContours( drawing, contours, 1, color, 2, 8, hierarchy, 0, Point() );
    imshow( "2", drawing );
    color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    drawContours( drawing, contours, 2, color, 2, 8, hierarchy, 0, Point() );
    imshow( "3", drawing );
    color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    drawContours( drawing, contours, 3, color, 2, 8, hierarchy, 0, Point() );
    imshow( "4", drawing );
    waitKey();
}
