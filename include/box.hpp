#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class Box {
    private:
    int mini, minj, maxi, maxj;
    Mat roi;

    public:
    Box(Mat image, int mini, int minj, int maxi, int maxj);

    int getMinI();
    int getMinJ();
    int getMaxI();
    int getMaxJ();

    Mat getROI();
};