#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

static GLfloat spin = 0.0;
static int ax = 0, ay = 0;

void spinDisplay(void)
{
	spin = spin + 5;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(ax, ay, 0);
	glRotatef(spin, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-1.0, -1.0);
	glVertex2f(1.0, -1.0);
	glVertex2f(1.0, 1.0);
	glVertex2f(-1.0, 1.0);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
	case 88:
		glutIdleFunc(display);
		break;
	case 120:
		glutIdleFunc(spinDisplay);
		break;
	}
}


void processMouseKeys(int key, int state, int x, int y)
{
	switch (key)
	{
	case GLUT_RIGHT_BUTTON:
		glutIdleFunc(display);
		break;
	case GLUT_LEFT_BUTTON:
		glutIdleFunc(spinDisplay);
		break;
	}
}


void moveObject(int x, int y)
{
	srand(time(0));
	ax = (x - 250) / 5;
	ay = (250 - y) / 5;
	glColor3f(rand() / (float(RAND_MAX) + 1), rand() / (float(RAND_MAX) + 1), rand() / (float(RAND_MAX) + 1));
	glutPostRedisplay();
}


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glColor3f(1.0, 1.0, 1.0);
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
}


int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(processMouseKeys);
	glutMotionFunc(moveObject);
	glutMainLoop();
	return 0;
}
