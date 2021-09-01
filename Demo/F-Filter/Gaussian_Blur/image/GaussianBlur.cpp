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

    //Blur the image with 3x3 Gaussian kernel
    Mat image_blurred_with_3x3_kernel;
    GaussianBlur(image, image_blurred_with_3x3_kernel, Size(3, 3), 0);

    //Blur the image with 5x5 Gaussian kernel
    Mat image_blurred_with_5x5_kernel;
    GaussianBlur(image, image_blurred_with_5x5_kernel, Size(5, 5), 0);

    String window_name = "Lotus";
    String window_name_blurred_with_3x3_kernel = "Lotus Blurred with 3 x 3 Gaussian Kernel";
    String window_name_blurred_with_5x5_kernel = "Lotus Blurred with 5 x 5 Gaussian Kernel";

    // Create windows with above names
    namedWindow(window_name);
    namedWindow(window_name_blurred_with_3x3_kernel);
    namedWindow(window_name_blurred_with_5x5_kernel);

    imshow(window_name, image);
    imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
    imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

    waitKey(0);

    destroyAllWindows();

    return 0;
}
