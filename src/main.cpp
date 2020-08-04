#include <opencv2/opencv.hpp>
#include <iostream>
#include <image.hpp>
#include <sstream>
#include <chrono>

using namespace std;
using namespace cv;

static void help(char **argv)
{
    cout
        << "./main: runs the webcam to access video stream. \n"
           "./main <filepath> runs the dev sandbox with the image at that location \n"
           "./main <filepath> dev: runs your own code at the specified location "
        << endl;
}

int main(int argc, char **argv)
{
    CommandLineParser parser(argc, argv, "{help h||}");
    if (parser.has("help"))
    {
        help(argv);
        return 0;
    }
    // Get the current time
    auto start = chrono::steady_clock::now();
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

        int hthresh, lthresh = 0;
        int thresh = 0;

        namedWindow("Stream", WINDOW_AUTOSIZE);
        createTrackbar("HPF:", "Stream", &hthresh, 100, 0);
        createTrackbar("LPF:", "Stream", &lthresh, 100, 0);
        createTrackbar("Threshold:", "Stream", &thresh, 255, 0);

        while (1)
        {
            Mat frame;
            bool bSuccess = cap.read(frame); // read a new frame from video
            Mat result;
            double scale = float(dWidth) / frame.size().width;
            resize(frame, result, cv::Size(dWidth / 3, dHeight / 3), scale, scale);
            img.changeImage(result);
            if (hthresh > 0)
            {
                img.highfilter(hthresh);
            }
            if (lthresh > 0)
            {
                img.lowfilter(lthresh);
            }

            img.threshold(thresh);

            if (!bSuccess) //if not success, break loop
            {
                cout << "Cannot read a frame from video stream" << endl;
                break;
            }

            imshow("Stream", img.getImage());

            if (waitKey(30) == 27)
            {
                break;
            }
        }
        return 0;
    }
    else if (argc == 3)
    {
        string three = argv[2];
        if (three.compare("dev") == 0)
        {
            cout << "Dev mode" << endl;

            Image image(argv[1]);

            // Do the specified stuff here

            image.findObjecto();

            Mat img = image.getImage();
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
    }
    Image image(argv[1]);
    Mat img;
    int x = 1;
    int thresh = 0;
    int hthresh, lthresh = 0;

    namedWindow("Dev Panel", WINDOW_AUTOSIZE);
    createTrackbar("LPF:", "Dev Panel", &lthresh, 100, 0);
    createTrackbar("Threshold:", "Dev Panel", &thresh, 255, 0);
    // createTrackbar("Median:", "Dev Panel", &median, 8, 0);
    createTrackbar("HPF:", "Dev Panel", &hthresh, 100, 0);
    createTrackbar("Image Return:", "Dev Panel", &x, 2, 0);

    if (!image.getImage().data)
    {
        cout << "No image data " << endl;
        return -1;
    }
    while (1)
    {
        Image image(argv[1]);
        Mat img;

        if (hthresh > 0)
        {
            image.highfilter(hthresh);
        }

        if (lthresh > 0)
        {
            image.highfilter(lthresh);
        }

        image.threshold(thresh);

        // image.median();

        if ((x + 1) == 1)
        {
            img = image.getImage();
        }
        else if ((x + 1) == 2)
        {
            img = image.getScratch();
        }
        else if ((x + 1) == 3)
        {
            img = image.getBinaryMat();
        }
        imshow("Dev Panel", img);
        if (waitKey(30) == 27)
        {
            break;
        };
    }
    // Get the current time again
    auto end = chrono::steady_clock::now();
    // Calculate the difference between the start and the end and print the result
    auto elapsed = (chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e9);
    cout << "Finished in " << elapsed << "s" << endl;
    return 0;
}
