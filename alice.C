#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <sstream>

// openCV
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace std;
using namespace cv;

void doSelecting(Mat fhsv, Mat fsel);

int main ( int argc, char** argv )
{
	cout<<"Hello"<<endl;

    VideoCapture cap(0);

	Mat frame;
	Mat fhsv;

    while(true)
    {
		cap>>frame;
		
		imshow("test", frame);

		cvtColor(frame, fhsv, COLOR_BGR2HSV);
		imshow("HSV", fhsv);

		Mat fselected(frame.rows, frame.cols, frame.type(), Scalar::all(0));

		//cout<<fselected.rows<<" "<<fselected.cols<<endl;
		doSelecting(fhsv, fselected);
		imshow("blue", fselected);


		waitKey(1);
	}

    return 0;
}

void doSelecting(Mat fhsv, Mat fsel)
{
	for(int i=0; i<fhsv.rows; i++)
	for(int j=0; j<fhsv.cols; j++)
	{
		int h = (int)fhsv.at<Vec3b>(i,j).val[0];
		int s = (int)fhsv.at<Vec3b>(i,j).val[1];
		int v = (int)fhsv.at<Vec3b>(i,j).val[2];
		//cout<<h<<endl;

		if(h>100&&h<124)
		if(s>43&&s<255)
		if(v>46&&v<255)
		{
			fsel.at<Vec3b>(i,j).val[0] = fhsv.at<Vec3b>(i,j).val[0];
			fsel.at<Vec3b>(i,j).val[1] = fhsv.at<Vec3b>(i,j).val[1];
			fsel.at<Vec3b>(i,j).val[2] = fhsv.at<Vec3b>(i,j).val[2];
		}
	}

}
