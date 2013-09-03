VideoRecorder
=============

VideoRecorder generate a video from several OpenGL screens. It uses OpenGL and OpenCV to achieve this objective. The kind of output is defined be the codec used.

The full list of codecs may be found here: http://www.fourcc.org/codecs.php
To be sure, one should restricted oneself to codecs listed here: http://opencv.willowgarage.com/wiki/documentation/cpp/highgui/VideoWriter

#Usage

To use VideoRecorder, simply include the VideoRecorder.hpp header and make a instance of VideoRecoder. Do notice that some combinations of width and height might not acceptable, due to codec restrictions.

```C++
VideoRecorder(std::string name, std::string codec, int frameRate, int width_, int height_): width(width_), height(height_){
```

Then, after drawing an OpenGL screen, call the GetFrame() method.

#Compiling

VideoRecorder depends on both, OpenGL and OpenCV, and both should be installed on your computer. However, it does not depend on any toolkit. Thus, it should work with GLUT, GLFW, etc.

To link OpenCV and OpenGL on Debian-based linux distros, one can use

```bash
g++ sourceCode.cpp -lopencv_highgui -lopencv_core -lGL
```

To compile the example, GLFW is required.

#Restrictions

Currently, VideoRecorder does not cope with size-changing windows. Therefore, it is healthy to draw a few OpenGL windows before starting VideoRecorder. This will should give enough interactions to let your window manager settle the window size. Another option, although not recommended, is to force the size of the window.
