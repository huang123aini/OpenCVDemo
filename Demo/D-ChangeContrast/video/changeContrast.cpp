#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    VideoCapture cap("test.mp4");
   
    if (cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrast Increased by 2";
    String windowNameContrastHigh4 = "Contrast Increased by 4";
    String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    while (true) {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video

         //Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameContrastHigh2;
        frame.convertTo(frameContrastHigh2, -1, 2, 0); //increase the contrast by 2

        Mat frameContrastHigh4;
        frame.convertTo(frameContrastHigh4, -1, 4, 0); //increase the contrast by 4

        Mat frameContrastLow0_5;
        frame.convertTo(frameContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

        Mat frameContrastLow0_25;
        frame.convertTo(frameContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25

        imshow(windowNameOriginalImage, frame);
        imshow(windowNameContrastHigh2, frameContrastHigh2);
        imshow(windowNameContrastHigh4, frameContrastHigh4);
        imshow(windowNameContrastLow0_5, frameContrastLow0_5);
        imshow(windowNameContrastLow0_25, frameContrastLow0_25);

        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}
