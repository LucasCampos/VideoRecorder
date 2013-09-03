#ifndef VIDEORECORDER_HPP
#define VIDEORECORDER_HPP
#include <GL/gl.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>

class VideoRecorder {

	private:
		cv::VideoWriter video;
		int width;
		int height;
		cv::Mat colorsCV;
	public:
		VideoRecorder(std::string name, int width_, int height_): width(width_), height(height_){
			video.open(name, CV_FOURCC('M','J','P','G'), 20, cv::Size(width,width));
			colorsCV = cv::Mat(width, height, CV_8UC3);
		};

		void GetFrame() {

			glReadPixels(0,0,
					width,width, 
					GL_BGR,
					GL_UNSIGNED_BYTE,
					colorsCV.data);
			if (colorsCV.empty())
				std::cerr << "OpenGL returned no pixels to VideoRecorder" << std::endl;
			video.write(colorsCV);
		}
};





#endif
