//HOUGH (LINES) PROBABILISTIC
/*
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int LowTh = 0, HighTh = 100, Amplitude = 3, Ksize = 0, thresh = 30, minline = 30, maxline = 25;
float Sigma = 0.02;
Mat img, img_gray, imgBlurred, imgCanny, imgHough, filtros;
string IN_img = "Imagen", IN_filtros = "Filtros";

void on_trackbar_LowTh(int pos, void *)
{
    LowTh = pos;
}

void on_trackbar_HIghTh(int pos, void *)
{
    HighTh = pos;
}

void on_trackbar_Amp(int pos, void *)
{
    switch (pos)
    {
        case 0 : Amplitude = 1; break;
        case 1 : Amplitude = 3; break;
        case 2 : Amplitude = 5; break;
        case 3 : Amplitude = 7; break;
        default : Amplitude = 3; break;
    }
}

void on_trackbar_Ksize(int pos, void *)
{
    switch (pos)
    {
        case 0 : Ksize = 1; break;
        case 1 : Ksize = 3; break;
        case 2 : Ksize = 5; break;
        case 3 : Ksize = 7; break;
        default : Ksize = 5; break;
    }
}
void on_trackbar_Sigma(int pos, void *)
{
    Sigma = 0.02 * pos;
}

void on_trackbar_thresh(int pos, void *)
{
    thresh = pos;
}

void on_trackbar_minline(int pos, void *)
{
    minline = pos;
}

void on_trackbar_maxline(int pos, void *)
{
    maxline = pos;
}

int main( )
{
    VideoCapture capWebcam(0);

     if (capWebcam.isOpened() == false)
     {
        cout << "error: Webcam connect unsuccessful\n";
        return(0);
     }

    char charCheckForEscKey = 0;

    int slider_HighTh = 100, slider_LowTh = 0, slider_Amp = 0, slider_Ksize = 0, slider_Sigma = 0,
                            slider_thresh = 0, slider_minline = 0, slider_maxline = 100;
    int slider_max_HighTh = 100, slider_max_LowTh = 100, slider_max_Amp = 3,slider_max_Ksize = 5,
     slider_max_Sigma = 100,slider_max_thresh = 255,slider_max_minline=255,slider_max_maxline = 255;

    imgHough.create(500,600,CV_8UC3);

    filtros.create(200,400, CV_8UC1);
    filtros.setTo(255);
    namedWindow(IN_filtros);
    imshow(IN_filtros, filtros);

    createTrackbar("KSIZE <->",IN_filtros, &slider_Ksize, slider_max_Ksize, on_trackbar_Ksize);
    createTrackbar("SIGMA <->",IN_filtros, &slider_Sigma, slider_max_Sigma, on_trackbar_Sigma);

    createTrackbar("LOWTH <->",IN_filtros, &slider_LowTh, slider_max_LowTh, on_trackbar_LowTh);
    createTrackbar("HIGHTH <->",IN_filtros, &slider_HighTh, slider_max_HighTh, on_trackbar_HIghTh);
    createTrackbar("AMP <->",IN_filtros, &slider_Amp, slider_max_Amp, on_trackbar_Amp);

    createTrackbar("THRESH <->",IN_filtros, &slider_thresh, slider_max_thresh, on_trackbar_thresh);
    createTrackbar("MINLINE <->",IN_filtros, &slider_minline, slider_max_minline, on_trackbar_minline);
    createTrackbar("MAXLINE <->",IN_filtros, &slider_maxline, slider_max_maxline, on_trackbar_maxline);

    while (charCheckForEscKey != 27 && capWebcam.isOpened())
    {
        bool blnFrameReadSuccessfully = capWebcam.read(img);
        if (!blnFrameReadSuccessfully || img.empty())
        {
            cout << "error: frame can't read \n";
            break;
        }
        cvtColor(img, img_gray, CV_BGR2GRAY);
        GaussianBlur(img_gray,imgBlurred,Size(Ksize, Ksize),Sigma);
        Canny(imgBlurred,imgCanny,LowTh,HighTh,Amplitude);
        vector<Vec4i> lines;
        HoughLinesP(imgCanny, lines, 1, CV_PI/180, thresh, minline, maxline);
        imgHough.setTo(Scalar(0,0,0));
        for( size_t i = 0; i < lines.size(); i++ )
        {
            Vec4i l = lines[i];
            line(imgHough, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 1, CV_AA);
        }
        namedWindow(IN_img, CV_WINDOW_NORMAL);
        namedWindow("imgCanny", CV_WINDOW_NORMAL);
        namedWindow("imgHough", CV_WINDOW_AUTOSIZE);
        imshow(IN_img, img);
        imshow("imgCanny", imgCanny);
        imshow("imgHough", imgHough);
        charCheckForEscKey = waitKey(1);
    }
}
*/

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

unsigned int upperTh = 100, centerTh = 30, minR = 0, maxR = 0;
Mat img, img_gray, imgBlurred, imgCanny, imgHough, filtros;
string IN_img = "Imagen", IN_filtros = "Filtros";

void actualizacion()
{
    img = imread ("C:/imagenes/circulos.jpg");
    cvtColor(img, img_gray, CV_BGR2GRAY);
    GaussianBlur(img_gray,imgBlurred,Size(5, 5),1.8);
    Canny(imgBlurred,imgCanny,50,150,3);
    vector<Vec3f> circles;
    HoughCircles( img_gray, circles, CV_HOUGH_GRADIENT, 1, img_gray.rows/8,
                  upperTh, centerTh, minR, maxR);
    imgHough.setTo(Scalar(0,0,0));
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        Point center = Point(c[0], c[1]);
        circle( img, center, 1, Scalar(0,100,100), 2, LINE_AA);
        int radius = c[2];
        circle( img, center, radius, Scalar(255,0,255), 1, LINE_AA);
    }
    namedWindow(IN_img, CV_WINDOW_NORMAL);
    imshow(IN_img, img);
}

void on_trackbar_upperTh(int pos, void *)
{
    upperTh = pos + 1;
    actualizacion();
}

void on_trackbar_centerTh(int pos, void *)
{
    centerTh = pos + 1;
    actualizacion();
}

void on_trackbar_minR(int pos, void *)
{
    minR = pos + 1;
    actualizacion();
}

void on_trackbar_maxR(int pos, void *)
{
    maxR = pos + 1;
    actualizacion();
}

int main( )
{
    int slider_upperTh = 100, slider_centerTh = 30, slider_minR = 0, slider_maxR = 0;
    int slider_max_upperTh = 200, slider_max_centerTh = 100, slider_max_minR = 20,
                slider_max_maxR = 20;

    imgHough.create(500,600,CV_8UC3);

    filtros.create(200,400, CV_8UC1);
    filtros.setTo(255);
    namedWindow(IN_filtros);
    imshow(IN_filtros, filtros);

    createTrackbar("UPPERTH <->",IN_filtros, &slider_upperTh, slider_max_upperTh,
                    on_trackbar_upperTh);
    createTrackbar("CENTERTH <->",IN_filtros, &slider_centerTh, slider_max_centerTh,
                    on_trackbar_centerTh);
    createTrackbar("MINR <->",IN_filtros, &slider_minR, slider_max_minR, on_trackbar_minR);
    createTrackbar("MAXR <->",IN_filtros, &slider_maxR, slider_max_maxR, on_trackbar_maxR);
    actualizacion();
    waitKey();

}
