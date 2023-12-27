#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

Mat img, histImage, img_gamma, img_convert, img_ecu;
string IN_img = "IMG ORIGINAL", IN_imgh = "HIST ORIGINAL",
 IN_gamma = "IMG GAMMA", IN_gammah = "HIST GAMMA",
    IN_convert = "IMG CONVERT", IN_converth = "HIST CONVERT",
     IN_ecu = "IMG ECU", IN_ecuh = "HIST ECU";;

void func_histograma(Mat img_hist, string IN_window)
{
    if(img.type() == 16)
    {
        int histSize = 255;
        Mat hist,gris;
        //Leer Imagen original
        //Convert color image to gray level image
        cvtColor(img_hist, gris, CV_RGB2GRAY);
        calcHist(&gris, 1, 0, Mat(), hist, 1, &histSize, 0);
        histImage = Mat::ones(255, 255, CV_8U)*255;
        normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);
        int binW = cvRound((double)histImage.cols/histSize);
            for( int i = 0; i < histSize; i++ )
            {
                rectangle( histImage, Point(i*binW, histImage.rows),
                Point((i+1)*binW, histImage.rows-cvRound(hist.at<float>(i))),
                Scalar::all(0), -1, 8, 0);
            }
        imshow(IN_window, histImage);
    }
    else
    {
        int histSize = 255;
        Mat hist,gris;
        //Leer Imagen original
        //Convert color image to gray level image
        //cvtColor(img_hist, gris, CV_RGB2GRAY);
        img_hist.copyTo(gris);
        calcHist(&gris, 1, 0, Mat(), hist, 1, &histSize, 0);
        histImage = Mat::ones(255, 255, CV_8U)*255;
        normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);
        int binW = cvRound((double)histImage.cols/histSize);
            for( int i = 0; i < histSize; i++ )
            {
                rectangle( histImage, Point(i*binW, histImage.rows),
                Point((i+1)*binW, histImage.rows-cvRound(hist.at<float>(i))),
                Scalar::all(0), -1, 8, 0);
            }
        imshow(IN_window, histImage);
    }
}

void on_trackbar_gamma(int pos, void *)
{
    if(img_gamma.type() == 0)
    {
        int col = img_gamma.cols, row = img_gamma.rows;

        Mat img_converted_gamma;
        img_converted_gamma.create(row,col, CV_8UC1);

        for (int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                img_converted_gamma.at<uchar>(i,j) =
                saturate_cast<uchar>( pow(img_gamma.at<uchar>(i,j),
                                           1/(0.02*pos+.8) ));
            }
        }
        imshow(IN_gamma,img_converted_gamma);
        func_histograma(img_converted_gamma, IN_gammah);
    }
    else if(img_gamma.type() == 16)
    {
        int col = img_gamma.cols, row = img_gamma.rows;

        Mat img_converted_gamma;
        img_converted_gamma.create(row,col, CV_8UC3);

        for (int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                for(int k=0; k<3; k++)
                {
                    img_converted_gamma.at<Vec3b>(i,j)[k] =
                    saturate_cast<uchar>( pow(img_gamma.at<Vec3b>(i,j)[k],
                                               1/(0.02*pos+.8) ));
                }
            }
        }
        imshow(IN_gamma,img_converted_gamma);
        func_histograma(img_converted_gamma,IN_gammah);
    }
    else
        cout<<"wtf\n";
}

void on_trackbar_convert(int pos, void *)
{
    if(img.type() == 0)
    {
        int col = img_convert.cols, row = img_convert.rows;

        Mat img_converted_convert;
        img_converted_convert.create(row,col, CV_8UC1);

        img_convert.convertTo(img_converted_convert, -1, 1, pos*10-200);
        imshow(IN_convert,img_converted_convert);
        func_histograma(img_converted_convert, IN_converth);

    }
    else if(img_convert.type() == 16)
    {
        int col = img_convert.cols, row = img_convert.rows;

        Mat img_converted_convert,r,g,b;
        img_converted_convert.create(row,col, CV_8UC3);
        vector<Mat> rgbChannels(3);
        split(img_convert,rgbChannels);
        rgbChannels[0].convertTo(b, -1, 1, pos*10-200);
        rgbChannels[1].convertTo(g, -1, 1, pos*10-200);
        rgbChannels[2].convertTo(r, -1, 1, pos*10-200);
        b.copyTo(rgbChannels[0]);
        g.copyTo(rgbChannels[1]);
        r.copyTo(rgbChannels[2]);
        merge(rgbChannels,img_converted_convert);
        imshow(IN_convert,img_converted_convert);
        func_histograma(img_converted_convert, IN_converth);
    }
    else
        cout<<"wtf\n";
}

void on_trackbar_ecu(int pos, void *)
{
    if(img.type() == 0)
    {
        int col = img_ecu.cols, row = img_ecu.rows;
        Mat img_converted_ecu;
        img_converted_ecu.create(row,col, CV_8UC1);
        equalizeHist(img_ecu, img_converted_ecu);
        imshow(IN_ecu,img_converted_ecu);
        func_histograma(img_converted_ecu, IN_ecuh);
    }
    else if(img.type() == 16)
    {
        int col = img_ecu.cols, row = img_ecu.rows;
        Mat img_converted_ecu,r,g,b;
        img_converted_ecu.create(row,col, CV_8UC3);
        vector<Mat> rgbChannels(3);
        split(img_convert,rgbChannels);
        equalizeHist(rgbChannels[0], b);
        equalizeHist(rgbChannels[1], g);
        equalizeHist(rgbChannels[2], r);
        b.copyTo(rgbChannels[0]);
        g.copyTo(rgbChannels[1]);
        r.copyTo(rgbChannels[2]);
        merge(rgbChannels,img_converted_ecu);
        imshow(IN_ecu,img_converted_ecu);
        func_histograma(img_converted_ecu, IN_converth);
    }
    else
        cout<<"wtf\n";
}

int main()
{
    int slider_gamma = 10, slider_convert = 20, slider_ecu = 15;
    int slider_max_gamma = 30, slider_max_convert = 30, slider_max_ecu = 30;

    img = imread("C:/imagenes/paisajes/ejemplo3.jpg",CV_LOAD_IMAGE_UNCHANGED);
    imshow(IN_img, img);
    func_histograma(img,IN_imgh);

    img.copyTo(img_gamma);
    imshow(IN_gamma, img_gamma);
    func_histograma(img_gamma,IN_gammah);

    img.copyTo(img_convert);
    imshow(IN_convert, img_convert);
    func_histograma(img_convert,IN_converth);

    img.copyTo(img_ecu);
    imshow(IN_ecu, img_ecu);
    func_histograma(img_ecu,IN_ecuh);

    createTrackbar("GAMA <->",IN_gamma, &slider_gamma,
                   slider_max_gamma,on_trackbar_gamma);
    createTrackbar("CONVERT <->",IN_convert, &slider_convert,
                    slider_max_convert,on_trackbar_convert);
    createTrackbar("ECUALIZACION <->",IN_ecu, &slider_ecu,
                   slider_max_ecu,on_trackbar_ecu);

    waitKey(); // Wait for key press
    return 0;
}
