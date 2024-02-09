

#include <windows.h>
#include <GL/glut.h>
#include<math.h>>
#include <mmsystem.h>
# define PI           3.14159265358979323846

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}



void car()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0f,1.0f,1.0f);
    glVertex2f(8.1270371463359, 2.4572647995186);
glVertex2f(6.1287994339456, 1.6444223402412);
glVertex2f(4.6385882586036, 2.1976067916939);
glVertex2f(5.2820885388649, 2.525001671125);
glVertex2f(5.7562466401101, 2.7169228073434);
glVertex2f(6.1626678697488, 2.8523965505563);
glVertex2f(6.5916680565896, 2.9314229007638);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3f(0.0f,1.0f,1.0f);
    glEnd();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("City View Scenario");
	glutInitWindowSize(320, 320);

	   init();
    car();



	glutMainLoop();
	return 0;
}
