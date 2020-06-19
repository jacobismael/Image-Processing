#include <opencv2/opencv.hpp>
#include <iostream>
#include <image.hpp>
using namespace std;
using namespace cv;

// @param filepath - path to image
Image::Image(string filepath)
{
    this->image = imread(filepath, 1);
    this->filepath = filepath;
    image.copyTo(scratch);

    image.copyTo(r);
    image.copyTo(g);
    image.copyTo(b);

    binaryMat = Mat(image.size(), CV_8U);

    // Create grayscale image from normal image
    Mat temp = imread(filepath, IMREAD_GRAYSCALE);

    // for DCT, image dimensions must be multiples of 2:
    int w = temp.cols;
    int h = temp.rows;
    int w2, h2;
    w2 = (w % 2 == 0) ? w : w + 1;
    h2 = (h % 2 == 0) ? h : h + 1;

    // extending the input image with a border if its original width and height
    // are not multiples of 2:
    copyMakeBorder(temp, grayscale, 0, h2 - h, 0, w2 - w, BORDER_REPLICATE);

    // Converting Grayscale image's 8bits per pixel to float values as required by dct():
    Mat temp2 = Mat(grayscale.rows, grayscale.cols, CV_64F);
    grayscale.convertTo(temp2, CV_64F);
    dct(temp2, freqMap);

    for (int i = 0; i < b.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            b.at<Vec3b>(i, j)[1] = 0;
            b.at<Vec3b>(i, j)[2] = 0;
        }
    }

    for (int i = 0; i < g.rows; i++)
    {
        for (int j = 0; j < g.cols; j++)
        {
            g.at<Vec3b>(i, j)[0] = 0;
            g.at<Vec3b>(i, j)[2] = 0;
        }
    }

    for (int i = 0; i < r.rows; i++)
    {
        for (int j = 0; j < r.cols; j++)
        {
            r.at<Vec3b>(i, j)[0] = 0;
            r.at<Vec3b>(i, j)[1] = 0;
        }
    }
}

Mat Image::getImage()
{
    return image;
}

Mat Image::getScratch()
{
    return scratch;
}

Mat Image::getBinaryMat()
{
    return binaryMat;
}

Mat Image::getGrayScale()
{
    return grayscale;
}

Mat Image::getFrequencyMap()
{
    return freqMap;
}

void Image::setImage(string filepath)
{
       this->image = imread(filepath, 1);
    image.copyTo(scratch);

    image.copyTo(r);
    image.copyTo(g);
    image.copyTo(b);

    binaryMat = Mat(image.size(), CV_8U);

    // Create grayscale image from normal image
    Mat temp = imread(filepath, IMREAD_GRAYSCALE);

    // for DCT, image dimensions must be multiples of 2:
    int w = temp.cols;
    int h = temp.rows;
    int w2, h2;
    w2 = (w % 2 == 0) ? w : w + 1;
    h2 = (h % 2 == 0) ? h : h + 1;

    // extending the input image with a border if its original width and height
    // are not multiples of 2:
    copyMakeBorder(temp, grayscale, 0, h2 - h, 0, w2 - w, BORDER_REPLICATE);

    // Converting Grayscale image's 8bits per pixel to float values as required by dct():
    Mat temp2 = Mat(grayscale.rows, grayscale.cols, CV_64F);
    grayscale.convertTo(temp2, CV_64F);
    dct(temp2, freqMap);

    for (int i = 0; i < b.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            b.at<Vec3b>(i, j)[1] = 0;
            b.at<Vec3b>(i, j)[2] = 0;
        }
    }

    for (int i = 0; i < g.rows; i++)
    {
        for (int j = 0; j < g.cols; j++)
        {
            g.at<Vec3b>(i, j)[0] = 0;
            g.at<Vec3b>(i, j)[2] = 0;
        }
    }

    for (int i = 0; i < r.rows; i++)
    {
        for (int j = 0; j < r.cols; j++)
        {
            r.at<Vec3b>(i, j)[0] = 0;
            r.at<Vec3b>(i, j)[1] = 0;
        }
    }
}

// pixel[0] <-blue
// pixel[1] <-green
// pixel[2] <-red

Mat Image::getDCT(Mat src) {
    // Create grayscale image from normal image
    Mat temp = imread(filepath, IMREAD_GRAYSCALE);

    // for DCT, image dimensions must be multiples of 2:
    int w = temp.cols;
    int h = temp.rows;
    int w2, h2;
    w2 = (w % 2 == 0) ? w : w + 1;
    h2 = (h % 2 == 0) ? h : h + 1;

    Mat tempgray;

    // extending the input image with a border if its original width and height
    // are not multiples of 2:
    copyMakeBorder(temp, tempgray, 0, h2 - h, 0, w2 - w, BORDER_REPLICATE);

    // Converting Grayscale image's 8bits per pixel to float values as required by dct():
    Mat temp2 = Mat(tempgray.rows, tempgray.cols, CV_64F);
    tempgray.convertTo(temp2, CV_64F);
    dct(temp2, src);

    // Mat filteredScratch;

    // dct(src, filteredScratch, DCT_INVERSE);

    // filteredScratch.convertTo(src, CV_8UC1);

    return src;
}

// void Image::merge() {
//     for(int i = 0; i < scratch.rows; i++) {
//         for(int j = 0; j < scratch.cols; j++) {
//             Vec3b pixel = {b.at<Vec3b>(i, j)[0], g.at<Vec3b>(i, j)[1], r.at<Vec3b>(i, j)[2]};
//             scratch.at<Vec3b>(i, j) = pixel;
//         }
//     }
// }

void Image::lowfilter(int threshold)
{

    Mat freqScratch;
    freqMap.copyTo(freqScratch);

    // The following is a low pass filter on the DCT
    for (auto i = 0; i < freqScratch.rows; i++)
    {
        for (auto j = 0; j < freqScratch.cols; j++)
        {
            if ((i > threshold) || (j > threshold))
            {
                freqScratch.at<double>(i, j) = 0.0;
            }
        }
    }

    Mat tempr;
    r.copyTo(tempr);
    Mat fr = getDCT(tempr);

    // The following is a low pass filter on the DCT
    for (auto i = 0; i < fr.rows; i++)
    {
        for (auto j = 0; j < fr.cols; j++)
        {
            if ((i > threshold) || (j > threshold))
            {
                fr.at<double>(i, j) = 0.0;
            }
        }
    }

    Mat filteredScratchr;

    dct(fr, filteredScratchr, DCT_INVERSE);

    filteredScratchr.convertTo(r, CV_8UC1);

    Mat tempg;
    g.copyTo(tempg);
    Mat fg = getDCT(tempg);

    // The following is a low pass filter on the DCT
    for (auto i = 0; i < fg.rows; i++)
    {
        for (auto j = 0; j < fg.cols; j++)
        {
            if ((i > threshold) || (j > threshold))
            {
                fg.at<double>(i, j) = 0.0;
            }
        }
    }

    Mat filteredScratchg;

    dct(fg, filteredScratchg, DCT_INVERSE);

    filteredScratchg.convertTo(g, CV_8UC1);

    Mat tempb;
    b.copyTo(tempb);
    Mat fb = getDCT(tempb);

    // The following is a low pass filter on the DCT
    for (auto i = 0; i < fb.rows; i++)
    {
        for (auto j = 0; j < fb.cols; j++)
        {
            if ((i > threshold) || (j > threshold))
            {
                fb.at<double>(i, j) = 0.0;
            }
        }
    }

    Mat filteredScratchb;

    dct(fb, filteredScratchb, DCT_INVERSE);

    filteredScratchb.convertTo(b, CV_8UC1);
    // merge();
}

void Image::resetDCT(string filepath)
{
    // Create grayscale image from normal image
    Mat temp = imread(filepath, IMREAD_GRAYSCALE);

    // for DCT, image dimensions must be multiples of 2:
    int w = temp.cols;
    int h = temp.rows;
    int w2, h2;
    w2 = (w % 2 == 0) ? w : w + 1;
    h2 = (h % 2 == 0) ? h : h + 1;

    // extending the input image with a border if its original width and height
    // are not multiples of 2:
    copyMakeBorder(temp, grayscale, 0, h2 - h, 0, w2 - w, BORDER_REPLICATE);

    // Converting Grayscale image's 8bits per pixel to float values as required by dct():
    Mat temp2 = Mat(grayscale.rows, grayscale.cols, CV_64F);
    grayscale.convertTo(temp2, CV_64F);
    dct(temp2, freqMap);
}

void Image::threshold()
{
    int t = 230;

    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {

            Vec3b pixel = scratch.at<Vec3b>(i, j);

            for (int s = 0; s < 3; s++)
            {
                if (pixel[s] < t)
                {
                    pixel[s] = 0;
                }
            }

            scratch.at<Vec3b>(i, j) = pixel;
        }
    }
}

void Image::threshold(int threshold)
{
    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {

            Vec3b pixel = scratch.at<Vec3b>(i, j);

            for (int s = 0; s < 3; s++)
            {
                if (pixel[s] < threshold)
                {
                    pixel[s] = 0;
                }
            }

            scratch.at<Vec3b>(i, j) = pixel;
        }
    }
}

void Image::median() // sorting needs work
{

    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {
            Vec3b pixel = scratch.at<Vec3b>(i, j);

            if (i - 1 < 0)
            {
                scratch.at<Vec3b>(i - 1, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i - 1, j) = {0, 0, 0};
                scratch.at<Vec3b>(i - 1, j + 1) = {0, 0, 0};
            }

            if (i + 1 > scratch.rows - 1)
            {
                scratch.at<Vec3b>(i + 1, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j + 1) = {0, 0, 0};
            }

            if (j - 1 < 0)
            {
                scratch.at<Vec3b>(i - 1, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j - 1) = {0, 0, 0};
            }

            if (j + 1 > scratch.cols - 1)
            {
                scratch.at<Vec3b>(i - 1, j + 1) = {0, 0, 0};
                scratch.at<Vec3b>(i, j + 1) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j + 1) = {0, 0, 0};
            }

            int b[9] = {scratch.at<Vec3b>(i - 1, j - 1)[0], scratch.at<Vec3b>(i - 1, j)[0], scratch.at<Vec3b>(i - 1, j + 1)[0], scratch.at<Vec3b>(i, j - 1)[0], scratch.at<Vec3b>(i, j)[0], scratch.at<Vec3b>(i, j + 1)[0], scratch.at<Vec3b>(i + 1, j - 1)[0], scratch.at<Vec3b>(i + 1, j)[0], scratch.at<Vec3b>(i + 1, j + 1)[0]};
            int g[9] = {scratch.at<Vec3b>(i - 1, j - 1)[1], scratch.at<Vec3b>(i - 1, j)[1], scratch.at<Vec3b>(i - 1, j + 1)[1], scratch.at<Vec3b>(i, j - 1)[1], scratch.at<Vec3b>(i, j)[1], scratch.at<Vec3b>(i, j + 1)[1], scratch.at<Vec3b>(i + 1, j - 1)[1], scratch.at<Vec3b>(i + 1, j)[1], scratch.at<Vec3b>(i + 1, j + 1)[1]};
            int r[9] = {scratch.at<Vec3b>(i - 1, j - 1)[2], scratch.at<Vec3b>(i - 1, j)[2], scratch.at<Vec3b>(i - 1, j + 1)[2], scratch.at<Vec3b>(i, j - 1)[2], scratch.at<Vec3b>(i, j)[2], scratch.at<Vec3b>(i, j + 1)[2], scratch.at<Vec3b>(i + 1, j - 1)[2], scratch.at<Vec3b>(i + 1, j)[2], scratch.at<Vec3b>(i + 1, j + 1)[2]};

            for (int r = 0; r < 9; r++)
            {
                for (int c = 0; c < 9; c++)
                {
                    if (b[r] < b[c])
                    {
                        int t = b[r];
                        b[r] = b[c];
                        b[c] = t;
                    }
                }
            }

            for (int r = 0; r < 9; r++)
            {
                for (int c = 0; c < 9; c++)
                {
                    if (g[r] < g[c])
                    {
                        int t = g[r];
                        g[r] = g[c];
                        g[c] = t;
                    }
                }
            }

            for (int l = 0; l < 9; l++)
            {
                for (int c = 0; c < 9; c++)
                {
                    if (r[l] < r[c])
                    {
                        int t = r[l];
                        r[l] = r[c];
                        r[c] = t;
                    }
                }
            }

            pixel[0] = b[5];
            pixel[1] = g[5];
            pixel[2] = r[5];

            scratch.at<Vec3b>(i, j) = pixel;
        }
    }
}

void Image::smidge(int x)
{
    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {
            Vec3b pixel = scratch.at<Vec3b>(i, j);

            if (i - 1 < 0)
            {
                scratch.at<Vec3b>(i - 1, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i - 1, j) = {0, 0, 0};
                scratch.at<Vec3b>(i - 1, j + 1) = {0, 0, 0};
            }

            if (i + 1 > scratch.rows - 1)
            {
                scratch.at<Vec3b>(i + 1, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j + 1) = {0, 0, 0};
            }

            if (j - 1 < 0)
            {
                scratch.at<Vec3b>(i - 1, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i, j - 1) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j - 1) = {0, 0, 0};
            }

            if (j + 1 > scratch.cols - 1)
            {
                scratch.at<Vec3b>(i - 1, j + 1) = {0, 0, 0};
                scratch.at<Vec3b>(i, j + 1) = {0, 0, 0};
                scratch.at<Vec3b>(i + 1, j + 1) = {0, 0, 0};
            }

            Vec3b b[9] = {scratch.at<Vec3b>(i - 1, j - 1), scratch.at<Vec3b>(i - 1, j), scratch.at<Vec3b>(i - 1, j + 1), scratch.at<Vec3b>(i, j - 1), scratch.at<Vec3b>(i, j), scratch.at<Vec3b>(i, j + 1), scratch.at<Vec3b>(i + 1, j - 1), scratch.at<Vec3b>(i + 1, j), scratch.at<Vec3b>(i + 1, j + 1)};

            int count = 0;

            for (int i = 0; i < 9; i++)
            {
                if ((b[i])[0] == 0 && (b[i])[2] == 0 && (b[i])[2] == 0)
                {
                    count++;
                }
            }

            if (count > x)
            {
                pixel = {0, 0, 0};
            }

            scratch.at<Vec3b>(i, j) = pixel;
        }
    }
}

void Image::highfilter(int threshold)
{

    Mat freqScratch;
    freqMap.copyTo(freqScratch);

    // The following is a low pass filter on the DCT
    for (auto i = 0; i < freqScratch.rows; i++)
    {
        for (auto j = 0; j < freqScratch.cols; j++)
        {
            if ((i < threshold) && (j < threshold))
            {
                freqScratch.at<double>(i, j) = 0.0;
            }
        }
    }

    Mat filteredScratch;

    dct(freqScratch, filteredScratch, DCT_INVERSE);

    filteredScratch.convertTo(scratch, CV_8UC1);
}

void Image::bleach()
{

    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {
            Vec3b pixel = scratch.at<Vec3b>(i, j);

            if (!(pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0))
            {
                pixel[0] = 255;
                pixel[1] = 255;
                pixel[2] = 255;
                scratch.at<Vec3b>(i, j) = pixel;
            }
        }
    }
}

bool Image::isBlack(Vec3b pixel)
{
    int b = pixel[0];
    int g = pixel[1];
    int r = pixel[2];

    if (b == 0 && g == 0 && r == 0)
    {
        return true;
    }
    return false;
}

void Image::findObject()
{
    int mini = scratch.rows;
    int maxi = -1;
    int minj = scratch.cols;
    int maxj = -1;

    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {
            Vec3b pixel = scratch.at<Vec3b>(i, j);

            if (!(isBlack(pixel)))
            {
                if (i < mini)
                {
                    mini = i;
                }
                if (i > maxi)
                {
                    maxi = i;
                }

                if (j < minj)
                {
                    minj = j;
                }
                if (j > maxj)
                {
                    maxj = j;
                }
            }
        }
    }

    // cout << mini << " " << minj << " " << maxi << " " << maxj << endl;

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            if (
                (i >= mini && i <= maxi) && (j >= minj && j <= maxj) )
            {
                pixel[0] = (pixel[0]-125 < 0) ? 0 : pixel[0]-125;
                pixel[1] = (pixel[1]-125 < 0) ? 0 : pixel[1]-125;
            }

            image.at<Vec3b>(i, j) = pixel;
        }
    }

    // int bounds[4] = {mini, minj, maxi, maxj};
    // return bounds;
}

void Image::findObjecto()
{

    int WHITE_THRESHOLD = 230;
    int CLR_THRESHOLD = 5;

    int mini = scratch.rows;
    int maxi = -1;
    int minj = scratch.cols;
    int maxj = -1;

    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {
            Vec3b pixel = scratch.at<Vec3b>(i, j);

            if ((pixel[0] < 50 && pixel[1] < 50 && pixel[2] < 50) ||
                ((pixel[1] - pixel[0]) > CLR_THRESHOLD && (pixel[1] - pixel[2]) > CLR_THRESHOLD))
            {
                pixel[0] = pixel[1] = pixel[2] = 0;
            }

            if (pixel[0] > WHITE_THRESHOLD && pixel[1] > WHITE_THRESHOLD && pixel[2] > WHITE_THRESHOLD)
            {
                //white pixel
                if (i < mini)
                {
                    mini = i;
                }
                if (i > maxi)
                {
                    maxi = i;
                }

                if (j < minj)
                {
                    minj = j;
                }

                if (j > maxj)
                {
                    maxj = j;
                }
            }

            scratch.at<Vec3b>(i, j) = pixel;
        }
    }

    for (int i = 0; i < scratch.rows; i++)
    {
        for (int j = 0; j < scratch.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            if (
                (i >= mini && i <= maxi) && (j >= minj && j <= maxj) )
            {
                pixel[0] = (pixel[0]-125 < 0) ? 0 : pixel[0]-125;
                pixel[1] = (pixel[1]-125 < 0) ? 0 : pixel[1]-125;
            }

            image.at<Vec3b>(i, j) = pixel;
        }
    }

    // int bounds[4] = {mini, minj, maxi, maxj};
    // return bounds;
}

void Image::fillBinaryMat()
{

    int rows = image.rows;
    int cols = image.cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Vec3b pixel = scratch.at<Vec3b>(i, j);
            if (!(pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0))
            {
                binaryMat.at<uchar>(i, j) = 255;
            }
        }
    }
}