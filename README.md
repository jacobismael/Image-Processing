# Face Detection
![Github Repo Size](https://img.shields.io/github/repo-size/jacobismael/CV-Detect?style=for-the-badge)
![Github Code Size](https://img.shields.io/github/languages/code-size/jacobismael/CV-Detect?style=for-the-badge)
![Github Top Language](https://img.shields.io/github/languages/top/jacobismael/CV-Detect?color=%23f34b7d&style=for-the-badge)
![Github Language Count](https://img.shields.io/github/languages/count/jacobismael/CV-Detect?style=for-the-badge&color=success)
- - -
A C++ and Python program that uses OpenCV image processing to find faces and recognize them in a scene.

Looking to implement optimizations so that it runs smoothly for videos and then the neural network to recognize the face

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
./main <filepath> <blur> <threshold> <median> <edge> <image-return>
```
- blur: threshold value for range of frequencies

- threshold: level of which any pixel value lower than it drops to 0

- median: any number greater than 1 takes a region of pixel values and sets them to the median

- edge: threshold value for range of frequencies

- image-return:
    1. original image
    2. scratch copy of original with all processes run on it
    3. A binary image that represents all non-black values
    4. A frequency Map of the image 

- - -

Or,
```bash
./main <filepath>
```

Which by default, the program will run based on what is put in this section of main.cpp:

```cpp
// Get the current time
auto start = chrono::steady_clock::now();
if (argc != 8)
{
    if (argc == 2)
    {
        Image image(argv[1]);

        // Do the specified stuff here

        Mat img = image.getImage();
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
    cout << "usage: DisplayImage.out <Image_Path>" << endl;
    return -1;
}
```

- - -

![OpenCV](https://avatars1.githubusercontent.com/u/5009934?s=200&v=4)

This project was built using [OpenCV](https://opencv.org/):
