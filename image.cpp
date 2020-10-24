#include<iostream>
#include<stdio.h>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
	Mat image;
	image = imread("example.jpg");
	if (image.empty()) {
		printf("No image to load");
		return - 1;
	}
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("MY_image", image);
	waitKey(0);
	image.release();
	return 0;
}
