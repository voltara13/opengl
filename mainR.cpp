//#include <GL/glut.h>
//#include <cstdlib>
//#include <ctime>
//
//
//static int ax = 0, ay = 0;
//
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPushMatrix();
//	glTranslatef(ax, ay, 0);
//	glBegin(GL_POLYGON);
//	glVertex2f(-1.0, -1.0);
//	glVertex2f(1.0, -1.0);
//	glVertex2f(1.0, 1.0);
//	glVertex2f(-1.0, 1.0);
//	glEnd();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//
//void processNormalKeys(unsigned char key, int x, int y)
//{
//	if (key == 27) exit(0);
//}
//
//
//void moveObject()
//{
//	srand(time(0));
//	ax = -50 + rand() % 100;
//	ay = -50 + rand() % 100;
//	glColor3f(rand() / (float(RAND_MAX) + 1), rand() / (float(RAND_MAX) + 1), rand() / (float(RAND_MAX) + 1));
//	glutPostRedisplay();
//}
//
//
//void processMouseKeys(int key, int state, int x, int y)
//{
//	switch (key)
//	{
//	case GLUT_RIGHT_BUTTON:
//		moveObject();
//		break;
//	}
//}
//
//
//void reshape(int w, int h)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//	glColor3f(1.0, 1.0, 1.0);
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
//}
//
//
//int main(int argc, char **argv)
//{
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("lw3_random");
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(processNormalKeys);
//	glutMouseFunc(processMouseKeys);
//	glutMainLoop();
//	return 0;
//}