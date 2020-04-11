#include <opencv2/opencv.hpp>
#include <iostream>
#include <box.hpp>

using namespace std;
using namespace cv;

Box::Box(Mat image, int mini, int minj, int maxi, int maxj) {
    this->mini = mini;
    this->minj = minj;
    this->maxi = maxi;
    this->maxj = maxj;
    this->roi = Mat(image, Rect(minj+1, mini+1, maxj-minj-1, maxi-mini-1));
}

int Box::getMinI() {
    return this->mini;
}

int Box::getMinJ() {
    return this->minj;
}

int Box::getMaxI() {
    return this->maxi;
}

int Box::getMaxJ() {
    return this->maxj;
}

Mat Box::getROI() {
    return this->roi;
}