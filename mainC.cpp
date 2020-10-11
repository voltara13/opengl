//#include <iostream>
//#include <Windows.h>
//#include <gl/GLU.h>
//#include <GL/glut.h>
//#include <cmath>
//
//
//GLint Width = 400, Height = 400;
//
//
//void Display(void)
//{
//	glClearColor(0, 0, 0, 1);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	int count = 0;
//	const double r = 3;
//	std::cin >> count;
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glColor3f(1, 0, 0);
//	glBegin(GL_TRIANGLE_FAN);
//	glVertex2f(0, 0);
//	for (int i = 0; i <= count; i++)
//		glVertex2f((r * cos(i * acos(-1.0) * 2 / count)), (r * sin(i * acos(-1.0) * 2 / count)));
//	glEnd();
//
//
//	glFinish();
//}
//
//
//void Reshape(GLint w, GLint h)
//{
//	Width = w;
//	Height = h;
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluOrtho2D(-6, 6, -6, 6);
//}
//
//
//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB);
//	glutInitWindowSize(Width, Height);
//	glutCreateWindow("lw2_circle");
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape);
//	glutMainLoop();
//}
