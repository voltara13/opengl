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

	int width = 200, height = 200, nrChannels = 255;
	unsigned char *data = stbi_load("cat.jpg", &width, &height, &nrChannels, 0);
	glRasterPos3d(0.0, 0.0, 0.0);
	glPixelZoom(1, 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glDrawPixels(width, height,GL_RGB, GL_UNSIGNED_BYTE, data);
	static GLuint texName;
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
		width,
		height,
		GL_RGB, GL_UNSIGNED_BYTE,
		data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	glColor3d(1, 1, 1);

	glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(-5, -5, -0.1);
	glTexCoord2d(0, 1); glVertex3d(-5, 5, -0.1);
	glTexCoord2d(1, 1); glVertex3d(5, 5, -0.1);
	glTexCoord2d(1, 0); glVertex3d(5, -5, -0.1);
	glEnd();

	glDisable(GL_TEXTURE_2D);

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