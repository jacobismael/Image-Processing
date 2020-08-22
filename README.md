# Image Processing
![Github Repo Size](https://img.shields.io/github/repo-size/jacobismael/CV-Detect?style=for-the-badge)
![Github Code Size](https://img.shields.io/github/languages/code-size/jacobismael/CV-Detect?style=for-the-badge)
![Github Top Language](https://img.shields.io/github/languages/top/jacobismael/CV-Detect?color=%23f34b7d&style=for-the-badge)
![Language](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
![Github Language Count](https://img.shields.io/github/languages/count/jacobismael/CV-Detect?style=for-the-badge&color=success)
- - -
A C++ program that uses OpenCV basic tools to create image processing tools.

Looking to implement optimizations so that it runs smoothly for videos.


![OpenCV](https://avatars1.githubusercontent.com/u/5009934?s=200&v=4)

This project was built using [OpenCV](https://opencv.org/)

- - -

# Installing the Project
When you clone the repository, create a new directory called build using the following command:

```bash
mkdir build
```

After that, use this command in the build directory to build the cmake files:

```bash
cmake ..
```

> It is critical that you perform this command in the build directory

# Running the Project
Use the following command to use make to create the executable:
```bash
make
```

Type the following command in the Terminal:
```bash
./main <filepath>
```

Which should open the dev gui where you can manipulate the image using the filter sliders.
- - -

Or,
```bash
./main <filepath>
```

Which by default, the program will run based on what is put in this section of main.cpp:

```cpp
else if (argc == 3)
    {
        string three = argv[2];
        if (three.compare("dev") == 0)
        {
            cout << "Dev mode" << endl;

            Image image(argv[1]);

            // Do the specified stuff here

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
```

- - -

Or lastly,
```bash
./main
```

Which then returns a video stream from whatever camera the program can locate. (It looks at the default camera at index 0). It will run this section where you can manipulate the frames 

```cpp
if (argc == 1) {
        VideoCapture cap(0); // open the video camera no. 0

        Image img;

        if (!cap.isOpened()) {
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

        while (1) {
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
```
