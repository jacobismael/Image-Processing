# OpenCV Object Detection
![Github Repo Size](https://img.shields.io/github/repo-size/jacobismael/CV-Detect?style=for-the-badge)
![Github Code Size](https://img.shields.io/github/languages/code-size/jacobismael/CV-Detect?style=for-the-badge)
![Github Top Language](https://img.shields.io/github/languages/top/jacobismael/CV-Detect?color=%23f34b7d&style=for-the-badge)
![Github Language Count](https://img.shields.io/github/languages/count/jacobismael/CV-Detect?style=for-the-badge&color=success)
- - -
A C++ program that uses OpenCV image processing to find objects in a scene.

Looking to implement optimizations so that it runs smoothly for videos

# Running the Project
Type the following command in the Terminal:
```bash
./main <filepath> [<blur> <threshold> <median> <edge> <image-return>]
```
blur: # of times

threshold: level of which any pixel value lower than it drops to 0

median: any number greater than 1 takes a region of pixel values and sets them to the median

edge: % of allowance

Or,
```bash
./main <filepath>
```

Which by default, the program will run based on what is put in this section of main.cpp:

```cpp
if (argc != 8)
    {
        if (argc == 2)
        {
            Image image(argv[1]);

            // Do the specified stuff here

            Mat img = image.getImage();
            namedWindow("Display Image", WINDOW_AUTOSIZE);
            imshow("Display Image", img);

            waitKey(0);

            return 0;
        }
        cout << "usage: DisplayImage.out <Image_Path>" << endl;
        return -1;
    }
```
![OpenCV](https://opencv.org/wp-content/uploads/2019/02/opencv-logo-1.png)

This project was built using [OpenCV](https://opencv.org/):