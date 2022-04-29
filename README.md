# Object Detection with RaspberryPi

<img src="https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/main/images/CV.png" width="100%" height="30%">

**_Amran Mamuye, Chandler Mason, Diana Omomehin_   - _Section B, Spring 2022_**

##### Table of Contents  
  
Below is a video demonstration of the final project:

<iframe width="560" height="315" src="https://www.youtube.com/embed/ssYNCzPAYsY" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

  
**Introduction**
-------------------

Object detection is a computer vision approach that identifies and locates items in an image or video. Object detection may be used to count items in a scene, determine and monitor their precise positions, and precisely label them using this type of identification and localization. Computer vision is an artificial intelligence area that trains computers to interpret and comprehend the visual environment. In recent years, there has been an exponential growth of computer vision applications in several industries. Some examples of computer vision applications are self-driving cars, facial recognition, robot perception, etc. APIs such as OpenCV and Tensorflow make it easy for programmers to easily process images, perform computer vision tasks, and train and deploy object detection models.


**Description**
---------------

As object detection can consist of a broad dataset, the team mainly focused on shape recognition using OpenCV on a raspberryPi. In addition, an LED light signals if a certain type of shape is detected by the raspberryPI camera. As a stretch goal for the project, the team implemented object detection for everyday objects using TensorFlow.

To implement this project, the team used:  
  - Platforms: RaspberryPi 4   
  - Hardware: RaspberryPi camera, HDMI Compatible Display
  - Programming languages: c++, python


**Building the Project**
------------------------

### **Installing Dependencies** 

####   
  
**OpenCV**  
  
**wiringPi**

Raspberry PI 

Wiring Diagram 

#### Shape Detection code

The code for shape detection is written in C++. The code is heavily dependent on the OpenCV library. It reads an image from the RaspberryPi camera, processes the image, then counts the number of corners to categorize the shape of the image captured by the Pi camera. 

Firstly, imported necessary libraries using include statements:
https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L1-L12

Created namespaces and defined LED pin: 
https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L14-L17

**functions**

**main()**

The code begins execution in the main() function: 
  
  Within the main, the camera and wiringPi is setup:
  
  https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L138-L142
  
  Checks if image is captured by camera, either calls the getShape() function or prints out an error:
  
  https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L145-L166
  
 
**getShape(Mat image)**

 This function is where the image/frame captured is processed by converting the image to reeasily read pixels to count the number of corner to classify                the shape of the object captured by the Pi camera
 
 Variables are defined:
 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L21-L41
 
 The image/frame captured is manipulate until the image is contoured.  Image contouring is outlining the object in the image so that the shape of the objects is identified. The image contouring processing:

 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L42-L61

 Vectors initialized to store pixels:
 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L63-L66
 
 
 
 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L69-L133
###   
  
 

**Compiling and Running the Project** 
--------------------------------------

**Testing the Project**
-----------------------

**Conclusion**
--------------

**Future Direction**
--------------------

Helpful Links/Resources
-----------------------
\- [Installing openCV on RaspberryPi](https://solarianprogrammer.com/2019/09/17/install-opencv-raspberry-pi-raspbian-cpp-python-development/)   
\- [Installing wiringPi](http://wiringpi.com/wiringpi-updated-to-2-52-for-the-raspberry-pi-4b/)   
\- [OpenCv Documentation](https://docs.opencv.org/3.4/index.html)   
\- [TensorFlow Documentation](https://docs.opencv.org/3.4/index.html)
