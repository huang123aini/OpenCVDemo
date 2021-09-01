#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main( int argc, const char** argv ) {
    /**
     *打开MP4文件
     */
    VideoCapture cap("test.mp4");

    if (cap.isOpened() == false) {
     cout << "Cannot open the video file" << endl;
     cin.get(); //wait for any key press
     return -1;
    }

    /**
     *获取帧率
     */
    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frames per seconds : " << fps << endl;

    String window_name = "FirstVideo";
    
    /**
     *创建一个窗口
     */
    namedWindow(window_name, WINDOW_NORMAL);

    while (true) {
     Mat frame;
     /**
      *读取视频帧
      */
     bool bSuccess = cap.read(frame);

     /**
      *视频帧读取结束
      */
     if (bSuccess == false) {
      cout << "Found the end of the video" << endl;
      break;
     }

     /**
      *在窗口展示视频帧
      */
     imshow(window_name, frame);

     if (waitKey(10) == 27) {
      cout << "Esc key is pressed by user. Stoppig the video" << endl;
      break;
     }
    }
	return 0;
}
