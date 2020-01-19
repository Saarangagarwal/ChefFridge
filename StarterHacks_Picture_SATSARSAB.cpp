#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include<string>
#include <ctime> 

using namespace cv;


bool takePicture() {
	VideoCapture cap(0);
	if (!cap.isOpened()) return false;
	/*
	---Takes Picture---
	*/
	Mat frame; //Creates image container
	for (int i = 0; i < 20; i++) {
		cap >> frame;
	}
	cap >> frame; //Read next frame

	std::string file_path = ("C:\\Users\\Major League Hacking\\Desktop\\image.png");
	imwrite(file_path, frame);
	/*
	//char file_path[] = "C:\\Users\\Sabeeh Malik\\Desktop\\image";
	imwrite("C:\\Users\\Sabeeh Malik\\Desktop\\image", frame);
	*/
	cap.release();
	return true;
}
bool checksSignal() {
	std::string filename = "C:\\Users\\Major League Hacking\\Desktop\\signal.txt";
	std::ifstream checkFile;
	checkFile.open(filename);
	char c;
	checkFile.seekg(-3, std::ios_base::end);
	checkFile >> c;
	if (c == '1') {
		return true;
	}
	return false;	
}

int main()
{
	bool runner = true;
	while (true) {
		if (checksSignal() ) {
			if (runner) {
				takePicture();
			}
			runner = false;
		}
		else {
			runner = true;
		}

	}
}
