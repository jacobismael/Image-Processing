#include <opencv2/opencv.hpp>
#include <iostream>
#include <image.hpp>
#include <sstream>
#include <box.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    if (argc != 7)
    {
        if (argc == 2)
        {
            Image image(argv[1]);

            image.median();

            Mat img = image.getScratch();
            namedWindow("Display Image", WINDOW_AUTOSIZE);
            imshow("Display Image", img);

            waitKey(0);

            return 0;
        }
        cout << "usage: DisplayImage.out <Image_Path>" << endl;
        return -1;
    }

    Image image(argv[6]);

    if (!image.getImage().data)
    {
        cout << "No image data " << endl;
        return -1;
    }

    stringstream strx(argv[1]);
    int x = 0;
    strx >> x;

    for (int i = 0; i < x; i++)
    {
        image.lowfilter();
    }
    stringstream strx2(argv[2]);
    x = 0;
    strx2 >> x;
    if(x > 0){
        image.threshold(x);
    }
    stringstream strx3(argv[3]);
    double y = 0;
    strx3 >> y;
    if(y > 0) {
        image.highfilter(y);
    }
    image.fillBinaryMat();

    stringstream strx4(argv[5]);
    x = 0;
    strx4 >> x;
    if(x > 0) {
        image.median();
    }

    stringstream strx5(argv[6]);
    x = 0;
    strx5 >> x;
    Mat img = image.getImage();

    if (x == 1)
    {
        img = image.getImage();
    }
    else if (x == 2)
    {
        img = image.getScratch();
    }
    else if (x == 3)
    {
        img = image.getBinaryMat();
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", img);

    waitKey(0);

    return 0;
}