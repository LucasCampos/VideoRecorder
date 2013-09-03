#include <GL/glfw.h>
#include <GL/gl.h>
#include <cstdlib>
#include "VideoRecorder.hpp"

double Uniform() { return rand()/(double)RAND_MAX;}

int main() {

	bool isOk = true;
	isOk |= glfwInit();
	isOk |= glfwOpenWindow( 600,600, 0,0,0,0,0,0, GLFW_WINDOW );
	if (!isOk) {
		std::cerr << "Could not open GLFW Window!" << std::endl;
	}
	int width = 600;
	int height = 600;


	glfwSetWindowTitle("GLFW Basic Window");
	glMatrixMode(GL_PROJECTION);
	glOrtho (-1, 1, -1, 1, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	VideoRecorder video("output.avi", width, height);
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

