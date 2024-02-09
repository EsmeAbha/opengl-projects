#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;

float _angle1 = 0.0f;
float _angle2 = 0.2f;
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    //sky
    glBegin(GL_POLYGON);
    glColor3d(0.9,0.92,1.0);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, -1.0f);
        glEnd();
        //windmillbody
    glBegin(GL_POLYGON);
    glColor3d(0.7,0.7,0.7);
        glVertex2f(0.12f, 0.2f);
        glVertex2f(0.18f, 0.2f);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.1f, -0.4f);
        glEnd();

    glPushMatrix();
    glTranslatef(0.15,0.2,0);
    glRotatef(-_angle1, 0.1f, 0.07f,0.9f);
    glLineWidth(20);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.3,0.3,0.3);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glPopMatrix();
    glEnd();
    glPushMatrix();
     glTranslatef(0.01,0.02,0);
    glBegin(GL_LINES);

     glColor3f(0.3,0.3,0.3);
        glVertex2f(-0.01f, 0.28f);
        glVertex2f(-0.01f, -0.0f);

        glVertex2f(0.0f, -0.01f);
        glVertex2f(0.28f, -0.13f);

        glVertex2f(0.0f, -0.01f);
        glVertex2f(-0.28f, -0.13f);

        glPopMatrix();
        glEnd();


    glutSwapBuffers();
}



void update(int value) {

    _angle1+=15.0f;
    if(_angle1 > 360.0)
    {
        _angle1-=360;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(45, update, 0); //Notify GLUT to call update again in 25 milliseconds
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("WindMill Rotation");
    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);

    glutMainLoop();
    return 0;
}
