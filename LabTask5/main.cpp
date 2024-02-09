

#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;

float _move = 0.0f;
float _move2 = 0.0f;
void display() {

glClear(GL_COLOR_BUFFER_BIT);
glColor3d(1,0.8,0.9);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move,-0.5f, 0.0f);
glBegin(GL_QUADS);

glVertex2f(0.1f, 0.0f);
glVertex2f(0.8f, 0.0f);
glVertex2f(0.8f, 0.3f);
glVertex2f(0.1f, 0.3f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-_move, 0.2f, 0.0f);
glBegin(GL_QUADS);

glColor3d(0.7,0.5,0.6);
glVertex2f(0.1f, 0.7f);
glVertex2f(0.8f, 0.7f);
glVertex2f(0.8f, 0.4f);
glVertex2f(0.1f, 0.4f);
glEnd();
glPopMatrix();
glutSwapBuffers();
}



void update(int value) {
_move += .02;
if(_move > 1.3)
{
_move = -1.0;
}
glutPostRedisplay();
glutTimerFunc(20, update, 0);
}



int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 800);
glutCreateWindow("Box moving in opposite direction");
glutDisplayFunc(display);
gluOrtho2D(-2,2,-2,2);
glutTimerFunc(20, update, 0); //Add a timer
glutMainLoop();
return 0;
}
