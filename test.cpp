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
	VideoRecorder video("output.avi", width, height);

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

		video.GetFrame();
	}
}

