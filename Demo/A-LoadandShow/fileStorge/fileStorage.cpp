#include "opencv2/opencv.hpp"
using namespace cv;

int main(int, char** argv)
{
	/**
     *创建存储文件
     */
    FileStorage fs("test.txt", FileStorage::WRITE);
    /**
     *保存数据
     */
    int fps= 5;
    fs << "fps" << fps;
    // Create some mat sample
    Mat m1= Mat::eye(2,3, CV_32F);
	Mat m2= Mat::ones(3,2, CV_32F);
	Mat result= (m1+1).mul(m1+3);
	/**
     *输出文件内容
     */
    fs << "Result" << result;
    /**
     *释放文件句柄
     */
    fs.release();
   
    /**
     *读取文件内容
     */
    FileStorage fs2("test.txt", FileStorage::READ);

    Mat r;
    fs2["Result"] >> r;
    std::cout << r << std::endl;

    fs2.release();

    return 0;
}
