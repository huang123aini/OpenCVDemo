#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat image = imread("lena.jpg");

    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    Mat imageContrastHigh2;
    image.convertTo(imageContrastHigh2, -1, 2, 0); //increase the contrast by 2

    Mat imageContrastHigh4;
    image.convertTo(imageContrastHigh4, -1, 4, 0); //increase the contrast by 4

    Mat imageContrastLow0_5;
    image.convertTo(imageContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

    Mat imageContrastLow0_25;
    image.convertTo(imageContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25


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

    imshow(windowNameOriginalImage, image);
    imshow(windowNameContrastHigh2, imageContrastHigh2);
    imshow(windowNameContrastHigh4, imageContrastHigh4);
    imshow(windowNameContrastLow0_5, imageContrastLow0_5);
    imshow(windowNameContrastLow0_25, imageContrastLow0_25);

    waitKey(0);

    destroyAllWindows();

    return 0;
}
