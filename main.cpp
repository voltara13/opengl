#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION  
#include "stb_image.h"

#define Rc 2  //составл€юща€ радиуса поверхности
#define H 7 //высота поверхности

int winSize = 400;
int x_center = 0;
int y_center = -1;
int z_center = -10;
int light_x = 10;
int light_y = 10;
int light_z = -40;
float dh = 0.05;
int dl = 1;
bool wire_flag = 0;
bool texture_flag = 0;
bool light_flag = 0;
bool material_flag = 1;
bool projection_flag = 0;

int width, height, nrChannels;
unsigned char* image;
static GLuint texName;

typedef struct _Vert {
	float x;
	float y;
	float z;
}Vert;

void keyDisplay(unsigned char key, int x, int y)
{
	switch (key) {
		//перемещение фигуры:
	case 'd':  //право
		x_center++;
		break;
	case 'a':  //лево
		x_center--;
		break;
	case 'w':  //верх
		y_center++;
		break;
	case 's':  //низ
		y_center--;
		break;
	case '+':  //+
		z_center++;
		break;
	case '-':  //-
		z_center--;
		break;
		//перемещение освещени€:
	case '6':  //право
		light_x++;
		break;
	case '4':  //лево
		light_x--;
		break;
	case '8':  //верх
		light_y++;
		break;
	case '5':  //низ
		light_y--;
		break;
	case '*':  //+
		light_z++;
		break;
	case '/':  //-
		light_z--;
		break;
	case 'c':  //carcass Ч каркас / сплошна€ поверхность
		wire_flag ? wire_flag = 0 : wire_flag = 1;
		break;
	case 'l':  //light Ч включение / выключение освещени€ и материала
		if (light_flag) {
			light_flag = 0;
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
		}
		else {
			light_flag = 1;
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
		}
		break;
	case 't':  //texture Ч включение / выключение текстуры
		texture_flag ? texture_flag = 0 : texture_flag = 1;
		break;
	case 'p':  //projection Ч аксонометрическа€ / перспективна€ проекци€
		projection_flag ? projection_flag = 0 : projection_flag = 1;
		break;
	case 27:  //esc Ч завершение работы программы
		exit(0);
	default:
		break;
	}

	glutPostRedisplay();
}

void light()
{
	GLfloat light_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { light_x, light_y, light_z, 10.0 };
	GLfloat global_ambient_light[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat material_ambient[] = { 0.1, 0.0, 0.0, 1.0 };
	GLfloat material_diffuse[] = { 0.3, 0.4, 0.7, 1.0 };
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	//освещение:
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);  //источник света
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_light);

	//свойства материала:
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambient);  //фонова€ составл€юща€
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);  //диффузорна€ составл€юща€
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);  //зеркальна€ составл€юща€
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 40);  //резкость бликов
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(0.1, 0.1, 0.1);
	glLineWidth(1);

	if (projection_flag) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-5, 5, -5, 5, 7, 40);
		gluLookAt(0, 0.1, 1, 0, 0, 0, 0, 1, 0);
		glMatrixMode(GL_MODELVIEW);
	}
	else {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-5, 5, -5, 5, -10, 20);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, 0.1, 1, 0, 0, 0, 0, 1, 0);
	}

	light();

	std::vector<Vert> vertices(4);

	float tex_width_vert = -0.5;
	float tex_height_vert = 0;
	float d_tex_width = dl / 360;
	float d_tex_height = dh;

	if (texture_flag) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texName);
	}

	for (float h = -0.5; h <= 0.5; h += dh, tex_height_vert += d_tex_height) {
		for (int l = 0; l < 360; l += dl, tex_width_vert += d_tex_width) {


			vertices[0].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * h))) * sin(l);
			vertices[0].y = y_center + H * h;
			vertices[0].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * h))) * cos(l);

			vertices[1].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * h))) * sin(l + dl);
			vertices[1].y = y_center + H * h;
			vertices[1].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * h))) * cos(l + dl);

			vertices[2].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh)))) * sin(l + dl);
			vertices[2].y = y_center + H * (h + dh);
			vertices[2].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh)))) * cos(l + dl);

			vertices[3].x = x_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh)))) * sin(l);
			vertices[3].y = y_center + H * (h + dh);
			vertices[3].z = z_center + Rc * (1 + abs(sin(2 * 3.14 * (h + dh)))) * cos(l);

			if (texture_flag) {

				if (wire_flag) glBegin(GL_LINE_STRIP); else glBegin(GL_POLYGON); //GL_LINE_STRIP - каркас, GL_POLYGON - закрашенный
				glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
				glTexCoord2d(tex_height_vert, tex_width_vert);
				glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
				glTexCoord2d(tex_height_vert, tex_width_vert + d_tex_width);
				glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
				glTexCoord2d(tex_height_vert + d_tex_height, tex_width_vert + d_tex_width);
				glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
				glTexCoord2d(tex_height_vert + d_tex_height, tex_width_vert);
				glEnd();

			}
			else {
				if (wire_flag) glBegin(GL_LINE_STRIP); else glBegin(GL_POLYGON); //GL_LINE_STRIP - каркас, GL_POLYGON - закрашенный
				glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
				glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
				glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
				glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
				glEnd();
			}
		}
	}

	if (texture_flag) glDisable(GL_TEXTURE_2D);

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0.05, 1, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winSize, winSize);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("rgz2");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyDisplay);

	image = stbi_load("texture1.jpg", &width, &height, &nrChannels, 4);

	stbi_set_flip_vertically_on_load(true);

	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	stbi_image_free(image);

	glutMainLoop();
	return 0;
}

