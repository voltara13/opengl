#include <GL/glut.h>
#include <stdlib.h>

//void init(void) //Белая сфера: источник света - цветной
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
//	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //Фоновое освещение
//
//    //GLfloat light_position[] = { 1.0, 1.0, 1.0, 1.0 }; //Точечное освещение
//    //glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
//    //glLightfv(GL_LIGHT0, GL_AMBIENT, global_ambient);
//
//    //GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; //Удаленное освещение
//    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    //glLightfv(GL_LIGHT0, GL_AMBIENT, global_ambient);
//
//    //GLfloat light_position[] = { -2.0, 2.0, 1.0, 1.0 }; //Прожекторное освещение
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

void init(void) //Источник - белый свет: свойство материала - хром
{
    GLfloat ambient[] = { 0.25, 0.25, 0.25, 1.0 };
    GLfloat diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat specular[] = { 0.774597, 0.774597, 0.774597, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
	
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 76.8);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(1.0, 100, 16);
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
            1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
            1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
