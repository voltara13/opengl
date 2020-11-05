#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "stb_image.h"

GLint Width = 400, Height = 400;


void Display(void)
{
	GLint w = Width, h = Height;
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	int width, height, nrChannels;
	unsigned char *data = stbi_load("cat.jpg", &width, &height, &nrChannels, 0);
	glRasterPos2i(0, 0);
	glPixelZoom(-1, -1);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

	glFinish();
}


void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-6, 6, -6, 6);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("lw5");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}