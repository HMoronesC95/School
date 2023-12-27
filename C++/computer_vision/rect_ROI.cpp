#include <iostream>
#include <opencv2/photo.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

Mat img,copia,tv;
string IN_img = "original";
int x_inicial, y_inicial, counter = 0;
bool ldown = false;
Point coor1, coor2;
stringstream file;

int videoCamera()
{
    tv = imread("C:/imagenes/ejemplo23.jpg");
    Point p;
    p.x = 98;
    p.y = 34;

    VideoCapture capture(0);
    if(!capture.isOpened()) return 1;
    bool finish = false;
    Mat frame,copia;

    if(!capture.read(frame)) return 1;
    while(!finish)
    {
        if(!capture.read(frame)) return 1;
        Mat src_mask = Mat::zeros(frame.rows, frame.cols, frame.depth());

        Point poly[1][4];
        poly[0][0] = Point(98, 34);
        poly[0][1] = Point(655, 35);
        poly[0][2] = Point(650,341);
        poly[0][3] = Point(104,346);
        const Point* polygons[1] = { poly[0] };
        int num_points[] = { 4 };

        fillPoly(src_mask, polygons, num_points, 1, Scalar(255,255,255));

        Point center(375,190);
        Mat output;
        seamlessClone(frame, tv, src_mask, center, output, NORMAL_CLONE);
        imshow("tv", output);

        if(waitKey(1)==27) finish = true;
    }
    capture.release();
    return 0;
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
     }
     else if  ( event == EVENT_LBUTTONUP )
     {
        if (ldown == true)
        {
            ldown = false;
        }
          if(x < 0)
            x = 0;
          if(x > img.cols)
            x = img.cols;
          if(y < 0)
            y = 0;
          if(y > img.rows)
            y = img.rows;

        if (sqrt(abs(pow((y-y_inicial),2) + pow((x-x_inicial),2))) > 5)
        {
            Mat r;
            coor1.x=x_inicial;
            coor1.y=y_inicial;
            coor2.x=x;
            coor2.y=y;
            r.setTo(Scalar(0,0,0));
            r = img(Rect(coor1, coor2)); // Establecer ROI marcada
            //roil.setTo(Scalar(0,0,0));
            file << "C:/imagenes/" << counter << ".jpg"; // file name
            imshow("ROI", r);
            imwrite(file.str(),r);
            //file.str()
            counter++; // increment the counter
        }
        else
        {
            imshow(IN_img, img);
        }
     }
     else if (event == EVENT_MOUSEMOVE)
     {
         if(ldown==true)
         {
            img.copyTo(copia);
            rectangle(copia, Point(x_inicial, y_inicial), Point(x, y),
                       Scalar(0,0,0), 1, LINE_8, 0);
            imshow(IN_img, copia);
         }
     }
}

int main()
{
    img = imread("C:/imagenes/rostros/ejemplo15.jpg");
    imshow(IN_img, img);
    setMouseCallback(IN_img, CallBackFunc, NULL);
    videoCamera();
    waitKey();
    return 0;
}
//*/
