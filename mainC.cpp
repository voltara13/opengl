//#include <iostream>
//#include <windows.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
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
//GLfloat colors[][3] = {
//	{1.0,0.0,0.0},
//	{1.0,1.0,0.0},
//	{0.0,1.0,0.0},
//	{0.0,0.0,1.0},
//	{1.0,0.0,1.0},
//	{1.0,1.0,1.0}
//};
//
//void polygon(int a, int b, int c, int d, int color)
//{
//	glColor3fv(colors[color]);
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertices[a]);
//	glVertex3fv(vertices[b]);
//	glVertex3fv(vertices[c]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//
//void colorcube()
//{
//	polygon(0, 3, 2, 1, 0);
//	polygon(2, 3, 7, 6, 1);
//	polygon(0, 4, 7, 3, 2);
//	polygon(1, 2, 6, 5, 3);
//	polygon(4, 5, 6, 7, 4);
//	polygon(0, 1, 5, 4, 5);
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
//	float ambient[] = { 0.7, 0.7, 0.7, 1 };
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
//}
//
//
//int main(int argc, char *argv[])
//{
//	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(Width, Height);
//	glutCreateWindow("lw4_camera");
//	glutReshapeFunc(Reshape);
//	glutDisplayFunc(Display);
//	glutKeyboardFunc(processNormalKeys);
//	glutMainLoop();
//	return 0;
//}