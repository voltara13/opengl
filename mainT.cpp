//#include <iostream>
//#include <windows.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include "stb_image.h"
//
//
//GLint Width = 400, Height = 400;
//double angPhi = 0, angOm = 0;
//
//GLfloat vertices[][3] = {
//	{-1.0,-1.0,-1.0},
//	{1.0,-1.0,-1.0},
//	{1.0,1.0,-1.0},
//	{-1.0,1.0,-1.0},
//	{-1.0,-1.0,1.0},
//	{1.0,-1.0,1.0},
//	{1.0,1.0,1.0},
//	{-1.0,1.0,1.0}
//};
//
//void polygon(int a, int b, int c, int d)
//{
//	glBegin(GL_POLYGON);
//	glTexCoord2d(1, 1); glVertex3fv(vertices[a]);
//	glTexCoord2d(1, 0); glVertex3fv(vertices[b]);
//	glTexCoord2d(0, 0); glVertex3fv(vertices[c]);
//	glTexCoord2d(0, 1); glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//
//void colorcube()
//{
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
//}
//
//
//void Display(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
//
//	double x = cos(angPhi) * cos(angOm);
//	double y = sin(angOm);
//	double z = sin(angPhi) * cos(angOm);
//	gluLookAt(x, y, z, 0, 0, 0, 0, 1, 0);
//	colorcube();
//
//	glFinish();
//}
//
//
//void processNormalKeys(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 52:
//		angPhi += 0.1;
//		break;
//	case 54:
//		angPhi -= 0.1;
//		break;
//	case 56:
//		angOm += 0.1;
//		break;
//	case 50:
//		angOm -= 0.1;
//		break;
//	}
//	glutPostRedisplay();
//}
//
//
//void Reshape(GLint w, GLint h)
//{
//	Width = w;
//	Height = h;
//	glViewport(0, 0, w, h);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_TEXTURE_2D);
//	float ambient[] = { 0.7, 0.7, 0.7, 1 };
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
//	int width, height, nrChannels;
//	unsigned char *data = stbi_load("cat.jpg", &width, &height, &nrChannels, 0);
//	static GLuint texName;
//	gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
//		width,
//		height,
//		GL_RGB, GL_UNSIGNED_BYTE,
//		data);
//}
//
//
//int main(int argc, char *argv[])
//{
//	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(Width, Height);
//	glutCreateWindow("lw5_camera");
//	glutReshapeFunc(Reshape);
//	glutDisplayFunc(Display);
//	glutKeyboardFunc(processNormalKeys);
//	glutMainLoop();
//	return 0;
//}