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
    Mat freqMap;

    public:
    Image(string filepath);

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

    int* findObjecto();
    int* findObject();

    bool isBlack(Vec3b pixel);

    void resetDCT(string filepath);

    Mat getImage();
    Mat getScratch();
    Mat getBinaryMat();
    Mat getGrayScale();
    Mat getFrequencyMap();
    void setImage(string filepath);

    void fillBinaryMat();
};
