# Object Detection with RaspberryPi

<img src="https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/main/images/CV.png" width="100%" height="30%">

**_Amran Mamuye, Chandler Mason, Diana Omomehin_   - _Section B, Spring 2022_**

##### Table of Contents  
 Demo
 Introduction
 Description
 Building the Project
 Shape Detection code
 Compiling and Running the Project
 Project Extension Object Detection
 Conclusion
 Future Direction
 
Below is a video demonstration of the final project:

[![Watch the video](https://user-images.githubusercontent.com/64986514/166131917-5a5da3ba-f33a-4629-8f60-37880d6ac2cc.png)](https://www.youtube.com/embed/ssYNCzPAYsY)

  
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

To download and openCV, please follow the steps on this [website](https://solarianprogrammer.com/2019/09/17/install-opencv-raspberry-pi-raspbian-cpp-python-development/).   
 <br>
  
**wiringPi**

To use the Raspberry PI GPIO, install wiringPI.

`wget https://project-downloads.drogon.net/wiringpi-latest.deb`
`sudo dpkg -i wiringpi-latest.deb`

To check:
`gpio -v`

Version should be 2.52.
 
 <br>

**Raspberry PI**

Set up the raspberryPi and the Pi camera as shown in the image:


 <br>
 
*Wiring Diagram*

Add a LED to a breadboard. The longer lead on the LED (+) goes to the GPIO bit 17 and the other LED lead (-) connects to a series resistor (around 100-300 ohms) that is connected to ground any gnd pin on Pi.
<img src="https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/main/images/Raspberry-Pi-GPIO-Header-with-Photo.png" width="50%" height="30%">

<br>

### **Shape Detection code** 

The code for shape detection is written in C++. The code is heavily dependent on the OpenCV library. It reads an image from the RaspberryPi camera, processes the image, then counts the number of corners to categorize the shape of the image captured by the Pi camera. 

Firstly, imported necessary libraries using include statements:
https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L1-L12

Created namespaces and defined LED pin: 
https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L14-L17

  <br>
 
 ***Functions***

  
 *main()*

The code begins execution in the main() function: 
  
  Within the main, the camera and wiringPi is setup:
  
  https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L138-L142
  
  <br>
  
  Checks if image is captured by camera, either calls the getShape() function or prints out an error:
  
  https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L145-L166
  
 

 <br>
 
*getShape(Mat image)*


 This function is where the image/frame captured is processed by converting the image to easily read pixels to count the number of corner to classify                the shape of the object captured by the Pi camera.
 
 Variables are defined:
 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L21-L41
 
 <br>
 
 The image/frame captured is manipulated until the image is contoured.  Image contouring is outlining the object in the image so that the shape of the objects is identified. The image contouring processing:

 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L42-L61
 
 <br>

 Vectors initialized to store pixels:
 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L63-L66
 
 <br>
 
 Iterates through image to calculate the shapes' area and finds possible shapes. Then classifies the shapes based on the number of corners the shapes contain. The LED blinks when a triangle is detected.
 https://github.com/AmranMamuye/ObjectDetectionRaspberryPi/blob/f54efdbbea628c96bbd80a2a6a55f47993d61071/shapeDetection.cpp#L69-L133
###   
  
 

**Compiling and Running the Project** 
--------------------------------------

To complile the project, locate the file and run the following command in terminal. The command `-lwiringPi` runs wiringPi and `pkg-config --cflags --libs opencv` runs openCV.

<pre><code class="language-plaintext">user$ g++ shapeDetection.cpp -o outputFile -lwiringPi `pkg-config --cflags --libs opencv`</code></pre>

To run the file:

`./outputFile`

A "current" window for the image caputure from the Pi camera will pop up.


**Testing the Project**
-----------------------

Once the "current" window pops up, the code will start detecting shapes captured by the Pi camera. 
https://youtu.be/ssYNCzPAYsY
<img width="161" alt="image" src="https://user-images.githubusercontent.com/103142185/166123989-43b281b8-188c-4a5d-989d-595106294db3.png">

**Project Extension: Object Detection in Python**
----------------------------------------------------
Setting up TensorFlow Lite on the Raspberry Pi is much easier than regular TensorFlow! These are the steps needed to set up TensorFlow Lite:

1. Update the Raspberry Pi
<pre><code class="language-plaintext">sudo apt-get update
sudo apt-get dist-upgrade</code></pre>


2. Download this repository and create virtual environment
<pre><code class="language-plaintext">git clone https://github.com/AmranMamuye/ObjectDetectionRaspberryPi</code></pre>

Then cd into the directory on your terminal
Install virtualenv
<pre><code class="language-plaintext">sudo pip3 install virtualenv</code></pre>

Create virtualenv
<pre><code class="language-plaintext">python3 -m venv tflite</code></pre>

Finally activate the virtual environment
<pre><code class="language-plaintext">source tflite/bin/activate</code></pre>


3. Install TensorFlow Lite dependencies and OpenCV

I have created a bash script to install the dependencies. 
Run:
<pre><code class="language-plaintext">bash requirements.sh</code></pre>


4. Set up TensorFlow Lite detection model
<pre><code class="language-plaintext">wget https://storage.googleapis.com/download.tensorflow.org/models/tflite/coco_ssd_mobilenet_v1_1.0_quant_2018_06_29.zip</code></pre>

Unzip the downloaded model
<pre><code class="language-plaintext">unzip coco_ssd_mobilenet_v1_1.0_quant_2018_06_29.zip -d model</code></pre>

5. Run TensorFlow Lite model!
<pre><code class="language-plaintext">python3 ObjectReal.py --modeldir=model</code></pre>

**Conclusion**
--------------
Our group was able to detect various shapes such as triangles, squares, circles, and rectangles along with various everyday objects such as a cup or phone with the Raspberry Pi camera.

![image](https://user-images.githubusercontent.com/103142185/166087960-69dff0a1-05c0-4120-b813-0f716b5a875d.jpeg)

**Future Direction**
--------------------
For our future direction, we want to undergo more training so that we can expand the amount of shapes and objects our device can detect. We also plan to make its detection more accurate, so for example it won't momentarily make simple mistakes like detecting a circle for a pentagon. We also want to provide voice feedback in which the object being detected is said verbally spoken through the Pi audio, allowing the user to quickly tell what object is detected. Lastly, we want to do more work on everyday object detection to increase the frames per second and maybe introduce facial recognition.  

Helpful Links/Resources
-----------------------
\- [Installing openCV on RaspberryPi](https://solarianprogrammer.com/2019/09/17/install-opencv-raspberry-pi-raspbian-cpp-python-development/)   
\- [Installing wiringPi](http://wiringpi.com/wiringpi-updated-to-2-52-for-the-raspberry-pi-4b/)   
\- [OpenCv Documentation](https://docs.opencv.org/3.4/index.html)   
\- [TensorFlow Documentation](https://docs.opencv.org/3.4/index.html)
