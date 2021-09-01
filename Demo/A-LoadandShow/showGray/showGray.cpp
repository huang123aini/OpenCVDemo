#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main( int argc, const char** argv ) {
	/**
     *读取图片
     */
	Mat color= imread("lena.jpg");
	Mat gray= imread("lena.jpg", IMREAD_GRAYSCALE);
	
	if(! color.data ) {
		cout << "Could not open or find the image" << std::endl ;
	 	return -1;
	}
	/**
     *写入图片
     */
	imwrite("lenaGray.jpg", gray);
	
	int myRow=color.cols-1;
	int myCol=color.rows-1;
	auto pixel= color.at<Vec3b>(myRow, myCol);
	cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
	
	/**
     *展示图片
     */
	imshow("Lena BGR", color);
	imshow("Lena Gray", gray);
    
	/**
     *按任意键退出
     */
	waitKey(0);
    
	return 0;
}
