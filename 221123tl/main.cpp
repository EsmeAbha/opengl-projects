
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;
float angle1 = 0.0f;

float _move = 0.2f;

void ball(float x, float _move, float z) {
    glPushMatrix();
    glTranslatef(x, _move, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);

    for (int i = 0; i < 200; ++i) {
        float pi=3.1416;
        float radian=(i*2*pi)/200;
        float wheelX = 0.05 * cos(radian);
        float wheelY = 0.05 * sin(radian);
        glVertex2f(wheelX, wheelY);
    }
    glEnd();
    glPopMatrix();

}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_LINES);
    glLineWidth(5.5);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0,0.0);
    glEnd();


    glPushMatrix();
    glTranslatef(0.2, -_move, 0.0);
    ball(0., - 0.0);
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {

    _move += .02;
    if(_move > 1.5)
    {
        _move = -0.8;
        _move = -0.8;
    }


    glutPostRedisplay();
    glutTimerFunc(30, update, 0); // 60 frames per second
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rotating Wheels");
    glutDisplayFunc(drawScene);
    glutTimerFunc(0, update, 0);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
    glutMainLoop();
    return 0;
}


