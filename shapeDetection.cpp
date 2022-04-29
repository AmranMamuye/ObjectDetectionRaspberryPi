#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <wiringPi.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <map>

using namespace cv;
using namespace std;

#define LED     0


void getShape(Mat curr) {

  	Mat currGreyscale;
  	Mat currBlurry;
  	Mat currCanny;
  	Mat currDilate;
  	Mat currErode;
  	Mat morph;
  	vector<vector<Point>> points;
	vector<Vec4i> topology;
	string shape;

	float rectSquare;
	float perimeter;
	int corner;

  	int size = 3;
  	int lowThresh= 25;
  	int maxThresh= 75;
  	int x;
	int i = 0;

	// converting the image in the frame

	// function used to convert color image to grey scale
	cvtColor(curr, currGreyscale, COLOR_BGR2GRAY);

	// function used to blur the grey scale image, this is also known as filtering 
	GaussianBlur(currGreyscale, currBlurry, Size(size, size), size, 0);

	// this function finds edges in an image using the Canny algorithm 
	Canny(currBlurry, currCanny, lowThresh, maxThresh);

	// function used to apply  Morphological Transformation 
	// MORPH_RECT is a rectangular structuring element used in openCv
	morph = getStructuringElement(MORPH_RECT, Size(size, size));

	// function used to dilate an image
	dilate(currCanny, currDilate, morph);

	// this function finds contours in the dilated image, 
	findContours(currDilate, points, topology, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	int pointsSize = points.size();

	vector<vector<Point>> currShape(pointsSize);
	vector<Rect> boundRect(pointsSize);
	

	while(i < pointsSize)
	{
		// this calculates the area 
		x = contourArea(points[i]);
		
		if (x > 1000) 
		{
			//  this function calculate curve length or perimeter and the bool indicates is shape is closed or not
			perimeter = arcLength(points[i], true);

			approxPolyDP(points[i], currShape[i], 0.02 * perimeter, true);
			cout << currShape[i].size() << endl;
			cout << "HI"<< endl;	
			boundRect[i] = boundingRect(currShape[i]);
		
			corner = (int)currShape[i].size();

			if (corner == 3) { 
				shape = "Triangle"; 
				
				pinMode (LED, OUTPUT) ;

				digitalWrite (LED, 1) ;     // On
				delay (10) ;               // mS
				digitalWrite (LED, 0) ;     // Off
				delay (10) ;
				
				//system("omxplayer /home/project/Downloads/Circle.mp3")
				}
			else if (corner == 4)
			{ 
				rectSquare = (float)boundRect[i].width / (float)boundRect[i].height;
			
				if (rectSquare> 0.95 && rectSquare< 1.05){ 
					shape = "Square";   
				}
				else { 
					shape = "Rectangle";
				}
			}
			else if (corner == 5 ) 
			{ 
				shape = "pentagon"; 
		
			}
			else if (corner == 6 ) 
			
			{ 
				shape = "Hexagon";   
			}
			else if (corner > 8 ) 
			{ 
				shape = "Circle"; 
			}
	
			
			drawContours(curr, currShape, i, Scalar(255, 0, 255), 2);
			rectangle(curr, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(curr, shape, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN,1, Scalar(0, 69, 255), 2);
		}
	 i++;
	}
  cout<<"end"<<endl; 
  imshow("current", curr);
}


int main() {
 
    // initializing wiringPi which is a GPIO library
    wiringPiSetup () ;

  	//openCV class for capturing video files and camera
 	VideoCapture camera(0);


    if (!camera.isOpened())
    {
        cout << "Could not open video camera";
        return -1;
    }

    // Mat is n-dimensional dense array class
    Mat instance;
    while (camera.read(instance))
    {
        if (instance.empty())
        {
            cout << "Nothing is captured from the Pi camera";
            break;
        }

        getShape(instance);
	        if (waitKey(10) == 'q')
        {
            break; // Terminate program if q pressed
        }
    }

    // displays the screen until a button is pressed
	waitKey(0);
  return 0;
}
