/*
 * Author:	Lucas Costa Campos
 * Email: 	Rmk236@gmail.com
 * Version:	0.02
 * License:	GNU General Public License
 * 		Copyright: 2013 Lucas Costa Campos
 * Website: 	https://github.com/LucasCampos/VideoRecorder
 */

/*
 *     This file is part of libepswriter.
 *
 *     libepswriter is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program; if not, write to the Free Software
 *     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 * */
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
		VideoRecorder(std::string name, std::string codec, int frameRate, int width_, int height_): width(width_), height(height_){
			video.open(name, CV_FOURCC(codec[0],codec[1],codec[2],codec[3]), frameRate, cv::Size(width,width));
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
