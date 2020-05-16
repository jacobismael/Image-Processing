# cv_obj_detect

A C++ program that uses OpenCV image processing to find objects in a scene.

Looking to implement optimizations so that it runs smoothly for videos

# Running the Project
In the Terminal:

./main filepath blur(intensity) threshold(level) median(1/0) edge(%) image-return

blur: # of times

threshold: level of which any pixel value lower than it drops to 0

median: any number greater than 1 takes a region of pixel values and sets them to the median

edge: % of allowance