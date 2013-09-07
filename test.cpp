/*
 *     This file is part of VINV.
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
#include <GL/glfw.h>
#include <GL/gl.h>
#include <cstdlib>
#include "VideoRecorder.hpp"

double Uniform() { return rand()/(double)RAND_MAX;}

int main() {

	int width = 600;
	int height = 600;

	//Setup GLFW window
	bool isOk = true;
	isOk |= glfwInit();
	isOk |= glfwOpenWindow( width, height, 0,0,0,0,0,0, GLFW_WINDOW );
	glfwSetWindowTitle("GLFW Basic Window");

	//Check whether the window is open
	if (!isOk) {
		std::cerr << "Could not open GLFW Window!" << std::endl;
	}

	//Set openGL representation. It is a window centred in (0,0), going from (-1,-1) to (1,1)
	glMatrixMode(GL_PROJECTION);
	glOrtho (-1, 1, -1, 1, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Create our video recorder. The video generated will be named "output.avi"
	VideoRecorder videoMKV("output.mkv", "PIM1", 20, width, height);
	VideoRecorder videoAVI("output.avi", "MJPG", 20, width, height);

	//Runs a hundred frames of random colours
	for (int i=0; i<100; i++) {
		glColor3f(Uniform(), Uniform(), Uniform());

		glBegin(GL_QUADS);
			glVertex2f(-100, -100);
			glVertex2f(100, -100);
			glVertex2f(100, 100);
			glVertex2f(-100, 100);
		glEnd();
		glfwSwapBuffers();

		videoAVI.GetFrame();
		videoMKV.GetFrame();
	}
}

