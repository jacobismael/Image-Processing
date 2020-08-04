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
        if (argc == 1)
        {
            VideoCapture cap(0); // open the video camera no. 0

            Image img;

            if (!cap.isOpened()) // if not success, exit program
            {
                cout << "Cannot open the video cam" << endl;
                return -1;
            }

            double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);   //get the width of frames of the video
            double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

            cout << "Frame size : " << dWidth << " x " << dHeight << endl;

            namedWindow("Stream", WINDOW_AUTOSIZE);

            while (1)
            {
                Mat frame;
                bool bSuccess = cap.read(frame); // read a new frame from video
                Mat result;
                double scale = float(dWidth)/frame.size().width;
                resize(frame, result, cv::Size(dWidth/3, dHeight/3), scale, scale);
                img.changeImage(result);
                // img.highfilter(100);
                if (!bSuccess) //if not success, break loop
                {
                    cout << "Cannot read a frame from video stream" << endl;
                    break;
                }

                imshow("Stream", img.getScratch());

                if (waitKey(30) == 27)
                {
                    break;
                }
            }
            return 0;
        }
        else if (argc == 2)
        {
            // Image image(argv[1]);

            // Do the specified stuff here

            // Mat img = image.getScratch();

            // Mat image = imread(argv[1], 1);

            // namedWindow("Display Image" , WINDOW_AUTOSIZE);
            // imshow("Display Image", img);

            // Get the current time again
            auto end = chrono::steady_clock::now();
            // Calculate the difference between the start and the end and print the result
            auto elapsed = (chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9);

            cout << "Finished in " << elapsed << "s" << endl;

            // waitKey(0);

            return 0;
        }
        else
        {
            cout << "usage: DisplayImage.out <Image_Path>" << endl;
            cout << "Error: 2 or 8 parameters required" << endl;
            return -1;
        }
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
    if (x > 0)
    {
        image.threshold(x);
    }
    stringstream strx3(argv[4]);
    int y = 0;
    strx3 >> y;
    if (y > 0)
    {
        image.highfilter(y);
    }
    image.fillBinaryMat();

    stringstream strx4(argv[5]);
    x = 0;
    strx4 >> x;
    for (int i = 0; i < x; i++)
    {
        image.median();
    }

    stringstream strx5(argv[6]);
    x = 0;
    strx5 >> x;
    if (x > 0)
    {
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
    auto elapsed = (chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9);
    cout << "Finished in " << elapsed << "s" << endl;

    waitKey(0);

    return 0;
}
