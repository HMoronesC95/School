/*
//DETECCION DE LINEA HOUGH
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#define IN "Imagen Original"
#define OUT "Líneas Detectadas"

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread ("C:/imagenes/instrumentos/ejemplo12.jpg", 0);

    Mat dst, canny_dst;
    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, canny_dst, CV_GRAY2BGR);

    vector<Vec2f> lines;
    // Aplica la Transformada Hough para encontrar líneas
    HoughLines(dst, lines, 1, CV_PI/180, 150, 0, 0 );

    // Dibuja las líneas detectadas
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line(canny_dst, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
    }

    // Resultados
    imshow(IN, src);
    imshow(OUT, canny_dst);

    waitKey();
    return 0;
}
*/
/*
//HOUGH (LINES) PROBABILISTIC
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#define IN "Imagen Original"
#define OUT2 "Líneas Detectadas (Probabilistic)"

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread ("C:/imagenes/instrumentos/ejemplo12.jpg", 0);

    Mat dst, canny_dst, canny_dst2;
    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, canny_dst, CV_GRAY2BGR);
    cvtColor(dst, canny_dst2, CV_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(dst, lines, 1, CV_PI/180, 30, 30, 25 );

    // Dibuja las líneas detectadas
    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        line(canny_dst2, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 2, CV_AA);
    }

    // Resultados
    imshow(IN, src);
    imshow(OUT2, canny_dst2);

    waitKey();
    return 0;
}
*/
//DETECCION DE CIRCULOS
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#define IN "Imagen Original"
#define OUT "Círculos Detectados"

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread ("C:/imagenes/circulos1.jpg");
    Mat src_gray;
    cvtColor( src, src_gray, CV_BGR2GRAY );

    vector<Vec3f> circles;
//Upper threshold for the internal Canny edge detector, Threshold for center detection, min_radius y max_radius
    // Aplica la Transformada Hough para encontrar círculos
    HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, 200, 100, 0, 0);

    // Dibuja los círculos detectados en src
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        // Dibujado de Círculos detectados
        circle( src, center, radius, Scalar(0,255,0), 3, 8, 0 );
    }

    // Resultados
    namedWindow(OUT, CV_WINDOW_AUTOSIZE );
    imshow(OUT, src );

    waitKey(0);
    return 0;
}
