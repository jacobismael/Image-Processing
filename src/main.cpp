#include <opencv2/opencv.hpp>
#include <iostream>
#include <image.hpp>
#include <sstream>
#include <chrono>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    // Get the current time
    auto start = chrono::steady_clock::now();
    if (argc != 8)
    {
        if (argc == 2)
        {
            Image image(argv[1]);

            // Do the specified stuff here

            image.lowfilter(100);
            // image.highfilter(100);

            Mat img = image.getScratch();

            namedWindow("Display Image" , WINDOW_AUTOSIZE);
            imshow("Display Image", img);
            
            // Get the current time again
            auto end = chrono::steady_clock::now();
            // Calculate the difference between the start and the end and print the result
            auto elapsed = (chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9 );

            cout << "Finished in " << elapsed << "s" << endl;

            waitKey(0);

            return 0;
        }
        cout << "usage: DisplayImage.out <Image_Path>" << endl;
        cout << "Error: 2 or 8 parameters required" << endl;
        return -1;
    }

    Image image(argv[1]);

    if (!image.getImage().data)
    {
        cout << "No image data " << endl;
        return -1;
    }

    stringstream strx(argv[2]);
    int x = 0;
    strx >> x;

    for (int i = 0; i < x; i++)
    {
        image.lowfilter(x);
    }

    stringstream strx2(argv[3]);
    x = 0;
    strx2 >> x;
    if(x > 0){
        image.threshold(x);
    }
    stringstream strx3(argv[4]);
    int y = 0;
    strx3 >> y;
    if(y > 0) {
        image.highfilter(y);
    }
    image.fillBinaryMat();

    stringstream strx4(argv[5]);
    x = 0;
    strx4 >> x;
    for(int i = 0; i < x; i++) {
        image.median();
    }

    stringstream strx5(argv[6]);
    x = 0;
    strx5 >> x;
    if(x > 0) {
        image.smidge(x);
    }

    image.findObject();

    stringstream strx6(argv[7]);
    x = 0;
    strx6 >> x;
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
    // Get the current time again
    auto end = chrono::steady_clock::now();
     // Calculate the difference between the start and the end and print the result
    auto elapsed = (chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9 );
    cout << "Finished in " << elapsed << "s" << endl;

    waitKey(0);

    return 0;
}
