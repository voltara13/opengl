#include <iostream>
#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>


GLint Width = 400, Height = 400;

GLfloat vertices[][3] = {
	{-1.0, -1.0, -1.0},
	{1.0, -1.0, -1.0},
	{1.0, 1.0, -1.0},
	{-1.0, 1.0, -1.0},
	{-1.0, -1.0, 1.0},
	{1.0, -1.0, 1.0},
	{1.0, 1.0, 1.0},
	{-1.0, 1.0, 1.0}
};

GLfloat colors[][3] = {
	{1.0, 0.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 0.0},
	{0.0, 0.0, 1.0},
	{1.0, 0.0, 1.0},
	{1.0, 1.0, 1.0}
};

void polygon(int a, int b, int c, int d, int color)
{
	glColor3fv(colors[color]);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}


void colorcube()
{
	polygon(0, 3, 2, 1, 0);
	polygon(2, 3, 7, 6, 1);
	polygon(0, 4, 7, 3, 2);
	polygon(1, 2, 6, 5, 3);
	polygon(4, 5, 6, 7, 4);
	polygon(0, 1, 5, 4, 5);
}


void Display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

	glPushMatrix();
	glViewport(0, Height / 2, Width / 2, Height / 2);
	colorcube();
	glPopMatrix();

	glPushMatrix();
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glRotatef(15, 1, 0, 0);
	glRotatef(-15, 0, 1, 0);
	colorcube();
	glPopMatrix();

	glPushMatrix();
	glViewport(0, 0, Width / 2, Height / 2);
	glRotatef(30, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	colorcube();
	glPopMatrix();

	glPushMatrix();
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	gluPerspective(30, 1, -0.1, 2);
	gluLookAt(3, 2, 2, 0, 0, 0, 0, 1, 0);
	colorcube();
	glPopMatrix();


	glFinish();
}


void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;
	glViewport(0, 0, w, h);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	float ambient[] = { 0.7, 0.7, 0.7, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
}


int main(int argc, char *argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("lw4");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
