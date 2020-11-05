#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>


GLint Width = 400, Height = 400;
const int num = 6;

void Cube(double x, double y, double size)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(x + size / 2, y + size / 2);
	glVertex2f(x - size / 2, y + size / 2);
	glVertex2f(x - size / 2, y - size / 2);
	glVertex2f(x + size / 2, y - size / 2);
	glEnd();
}


void Draw(int n, double x = 0, double y = 0, double size = double(Width / 4), int vertex = 0) /* рекурсивно */
{
	int drawNum = n;
	if (!drawNum) return;
	drawNum--;
	if (vertex != 1) Cube(x - size, y - size, size), Draw(drawNum, x - size, y - size, size / 2, 3);
	if (vertex != 2) Cube(x + size, y - size, size), Draw(drawNum, x + size, y - size, size / 2, 4);
	if (vertex != 3) Cube(x + size, y + size, size), Draw(drawNum, x + size, y + size, size / 2, 1);
	if (vertex != 4) Cube(x - size, y + size, size), Draw(drawNum, x - size, y + size, size / 2, 2);
}


void Display(void)
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	Cube(0, 0, Width / 2);
	Draw(num);
	glFinish();
}


void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(- w / 2, w / 2, - h / 2, h / 2);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("rgz1");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}