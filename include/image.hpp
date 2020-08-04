#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Image
{
    private:
    Mat image;
    Mat scratch;
    Mat binaryMat;
    Mat grayscale;

    string filepath;

    public:
    Image();
    Image(string filepath);

    Mat getDCT(Mat image);
    Mat merge(Mat r, Mat g, Mat b);

    void changeImage(Mat img);

    // blur
    void lowfilter(int threshold);

    // threshold
    void threshold();
    void threshold(int threshold);

    // median filtering
    void median();

    // edge detection    
    void highfilter(int threshold);
    
    void bleach();

    void smidge(int x);

    void findObjecto();
    void findObject();

    bool isBlack(Vec3b pixel);

    Mat getImage();
    Mat getScratch();
    Mat getBinaryMat();
    Mat getGrayScale();

    void fillBinaryMat();
};
