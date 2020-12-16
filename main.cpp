//#include <GL/glut.h>
//#include <stdlib.h>
//
//void init(void) //Ѕела€ сфера: источник света - цветной
//{
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = { 50.0 };
//    GLfloat global_ambient[] = { 0.1, 0.1, 0.3, 1.0 };
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glShadeModel(GL_SMOOTH);
//
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//	
//
//	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //‘оновое освещение
//
//    //GLfloat light_position[] = { 1.0, 1.0, 1.0, 1.0 }; //“очечное освещение
//    //glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
//    //glLightfv(GL_LIGHT0, GL_AMBIENT, global_ambient);
//
//    //GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; //”даленное освещение
//    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    //glLightfv(GL_LIGHT0, GL_AMBIENT, global_ambient);
//
//    //GLfloat light_position[] = { -2.0, 2.0, 1.0, 1.0 }; //ѕрожекторное освещение
//    //GLfloat light_spot_direction[] = { -1.0, -2.0, -1.0, 1.0 };
//    //glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
//    //glLightfv(GL_LIGHT0, GL_AMBIENT, global_ambient);
//    //glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_spot_direction);
//    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90);
//
//
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_COLOR_MATERIAL);
//}
//
////void init(void) //»сточник - белый свет: —войство материала - хром
////{
////	GLfloat mat_ambient[] = {0.25, 0.25, 0.25, 1.0};
////	GLfloat mat_diffuse[] = {0.4, 0.4, 0.4, 1.0};
////	GLfloat mat_specular[] = {0.774597, 0.774597, 0.774597, 1.0};
////	GLfloat mat_shininess = 76.8;
////	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
////
////	glClearColor(0.0, 0.0, 0.0, 0.0);
////	glShadeModel(GL_SMOOTH);
////
////	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
////	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
////	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
////	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
////	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
////
////	glEnable(GL_LIGHTING);
////	glEnable(GL_LIGHT0);
////	glEnable(GL_DEPTH_TEST);
////}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glutSolidSphere(1.0, 100, 16);
//	glFlush();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-1.5, 1.5, -1.5 * static_cast<GLfloat>(h) / static_cast<GLfloat>(w),
//		        1.5 * static_cast<GLfloat>(h) / static_cast<GLfloat>(w), -10.0, 10.0);
//	else
//		glOrtho(-1.5 * static_cast<GLfloat>(w) / static_cast<GLfloat>(h),
//		        1.5 * static_cast<GLfloat>(w) / static_cast<GLfloat>(h), -1.5, 1.5, -10.0, 10.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 27:
//		exit(0);
//	}
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}


#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION  
#include "stb_image.h"

#define Rc 2
#define H 5

int winSize = 400;
int x_center = 0;
int y_center = 0;
int z_center = 0;
float dh = 0.2;
int dl = 5;
bool wire = 1;

int width, height, nrChannels;
unsigned char* texture;

typedef struct _Vert {
	float x;
	float y;
	float z;
}Vert;

void keyDisplay(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		//std::cout << "d pressed" << std::endl;
		x_center++;
		break;
	case 'a':
		x_center--;
		break;
	case 'w':
		y_center++;
		break;
	case 's':
		y_center--;
		break;
	case '+':
		z_center++;
		break;
	case '-':
		z_center--;
		break;
	case '0':
		wire = 0;
		break;
	case '1':
		wire = 1;
		break;
	case 27:  //esc
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void light() {
	/*
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 3.0, 2.0, 0.0 };
	GLfloat global_ambient_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat local_view[] = { 0.0 };

	GLfloat material_ambient[] = { 0.19125, 0.0735, 0.0225, 1.0 };
	GLfloat material_diffuse[] = { 0.7038, 0.27048, 0.40828, 1.0 };
	GLfloat material_specular[] = { 0.256777, 0.137622, 0.086014, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	//освещение:
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);  //источниксвета
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_light);  //глобальноефоновоеосвещение
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);  //

	//свойстваматериала:
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);  //фонова€составл€юща€
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);  //диффузорна€составл€юща€
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);  //зеркальна€составл€юща€
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 12.8);  //резкостьбликов


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	*/
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1, 0, 1);
	glLineWidth(1);

	light();

	std::vector<Vert> vertices(4);

	for (float h = -0.5; h <= 0.5; h += dh) {
		for (int l = 0; l < 360; l += dl) {

			//R = Rc * (1 + abs(sin(2 * 3.14 * h + 0.5 * l)));

			vertices[0].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * h + 0.5 * l))) * sin(l);
			vertices[0].y = y_center + H * h;
			vertices[0].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * h + 0.5 * l))) * cos(l);

			vertices[1].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * h + 0.5 * (l + dl)))) * sin(l + dl);
			vertices[1].y = y_center + H * h;
			vertices[1].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * h + 0.5 * (l + dl)))) * cos(l + dl);

			vertices[2].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh) + 0.5 * (l + dl)))) * sin(l + dl);
			vertices[2].y = y_center + H * (h + dh);
			vertices[2].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh) + 0.5 * (l + dl)))) * cos(l + dl);

			vertices[3].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh) + 0.5 * l))) * sin(l);
			vertices[3].y = y_center + H * (h + dh);
			vertices[3].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh) + 0.5 * l))) * cos(l);

			if (wire) glBegin(GL_LINE_STRIP); else glBegin(GL_POLYGON); //GL_LINE_STRIP - каркас, GL_POLYGON - закрашенный
			glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
			glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
			glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
			glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
			glEnd();
		}
	}

	glFlush();
}

void init(void)
{
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 3.0, 2.0, 0.0 };
	GLfloat global_ambient_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat local_view[] = { 0.0 };

	GLfloat ambient[] = { 0.19125, 0.0735, 0.0225, 1.0 };
	GLfloat diffuse[] = { 0.7038, 0.27048, 0.40828, 1.0 };
	GLfloat specular[] = { 0.256777, 0.137622, 0.086014, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	//освещение:
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);  //источниксвета
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_light);  //глобальноефоновоеосвещение
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);  //

	//свойстваматериала:
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);  //фонова€составл€юща€
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);  //диффузорна€составл€юща€
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);  //зеркальна€составл€юща€
	glMaterialf(GL_FRONT, GL_SHININESS, 12.8);  //резкостьбликов


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(1, 0.05, 0.5, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winSize, winSize);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("RGR_18_Sologubova");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDisplay);

	texture = stbi_load("texture.jpg", &width, &height, &nrChannels, 0);

	glutMainLoop();
	return 0;
}

