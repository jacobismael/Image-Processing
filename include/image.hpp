#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Image
{
    private:
    Mat image;
    Mat scratch;
    Mat binaryMat;

    public:
    Image(string filepath);

    // blur
    void lowfilter();
    void lowfilter(int times);

    // threshold
    void threshold();
    void threshold(int threshold);

    // median filtering
    void median();

    // edge detection    
    void highfilter(double p);
    
    void bleach();

    void smidge(int x);

    int* findObjecto();
    int* findObject();

    bool isBlack(Vec3b pixel);

    Mat getImage();
    Mat getScratch();
    Mat getBinaryMat();
    void setImage(string filepath);

    void fillBinaryMat();
};
