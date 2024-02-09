#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;

float angle1 = 0.0f;
float angle2 = 0.0f;
float _move = 0.0f;

void drawWheel(float x, float y, float angle1) {
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(-angle1, 0.002, 0.08, 0.87);
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
     glPushMatrix();
     glTranslatef(0.01,0.02,0);
        glRotatef(-angle1, 0.0f, 0.05f,1.0f);
        glLineWidth(9);
        glBegin(GL_LINES);
        glColor3d(0.28,0.98,0.8);
        glVertex2f(0.01f, 0.02f);
        glVertex2f(0.01f, 0.0f);
        glPopMatrix();
        glEnd();
    glPopMatrix();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    //car body
    glPushMatrix();
    glTranslatef(_move, 0.2f, 0.0f);

        glBegin(GL_POLYGON);
    glColor3d(0.9,0.65,0.72);
        glVertex2f(-0.1f, 0.05f);
        glVertex2f(0.15f, 0.05f);
        glVertex2f(0.2f, -0.1f);
        glVertex2f(-0.15f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3d(0.9,0.65,0.72);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(0.3f, -0.2f);
        glVertex2f(0.2f, -0.05f);
        glVertex2f(-0.2f, -0.05f);
        glEnd();

    glBegin(GL_POLYGON);
    glColor3d(0.75,0.85,1.0);
        glVertex2f(-0.08f, 0.035f);
        glVertex2f(0.13f, 0.035f);
        glVertex2f(0.15f, -0.04f);
        glVertex2f(-0.1f, -0.04f);
        glEnd();
    //rotating wheels
    drawWheel(-0.1, -0.2, angle1);
    drawWheel(0.1, -0.2, angle2);
    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    angle1 += 10.0f;
    angle2 += 10.0f;

    if (angle1 > 360.0) {
        angle1 -= 360.0;
    }

    if (angle2 > 360.0) {
        angle2 -= 360.0;
    }
    _move += .02f;
    if(_move > 1.3)
    {
    _move = -1.0;
    }
    glutPostRedisplay();
    glutTimerFunc(18, update, 0); // 60 frames per second
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rotating Wheels with moving car");
    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the coordinate system
    glutMainLoop();
    return 0;
}
