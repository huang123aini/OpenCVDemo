#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
    
    VideoCapture cap("test.mp4");
    if (cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    String window_name_of_original_video = "Original Video";
    String window_name_of_video_blurred_with_5x5_kernel = "Video Blurred with 5 x 5 Gaussian Kernel";

    namedWindow(window_name_of_original_video, WINDOW_NORMAL);
    namedWindow(window_name_of_video_blurred_with_5x5_kernel, WINDOW_NORMAL);

    while (true) {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        //Blur the frame with 5x5 Gaussian kernel
        Mat frame_blurred_with_5x5_kernel;
        GaussianBlur(frame, frame_blurred_with_5x5_kernel, Size(5, 5), 0);

        //show the frames in the created windows
        imshow(window_name_of_original_video, frame);
        imshow(window_name_of_video_blurred_with_5x5_kernel, frame_blurred_with_5x5_kernel);

        if (waitKey(10) == 27) {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;

}
