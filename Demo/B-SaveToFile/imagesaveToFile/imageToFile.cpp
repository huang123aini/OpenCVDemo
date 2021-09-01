#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
 // Read the image file
 Mat image = imread("aaa.png");

 if (image.empty()) {
  cout << "Could not open or find the image" << endl;
  cin.get(); //wait for any key press
  return -1;
 }

 /*
 Make changes to the image as necessary
 e.g.
  1. Change brightness/contrast of the image
  2. Smooth/Blur image
  3. Crop the image
  4. Rotate the image
  5. Draw shapes on the image
 */

 bool isSuccess = imwrite("MyImage.jpg", image);
 if (isSuccess == false)
 {
  cout << "Failed to save the image" << endl;
  cin.get(); //wait for a key press
  return -1;
 }

 cout << "Image is succusfully saved to a file" << endl;

 std::string windowName = "SavedImage";
 namedWindow(windowName);
 imshow(windowName, image);

 waitKey(0);

 destroyWindow(windowName);
 return 0;
}
