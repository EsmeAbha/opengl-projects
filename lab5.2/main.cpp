
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;
float angle1 = 0.0f;
float angle2 = 0.0f;
void floor()
{
     glBegin(GL_POLYGON);
    glColor3d(0.75,0.85,1.0);
        glVertex2f(-25.0f, -10.0f);
        glVertex2f(25.0f, -10.0f);
        glVertex2f(25.0f, -20.0f);
        glVertex2f(-25.0f, -20.0f);
        glEnd();
}


void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    floor();
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
    glOrtho(-25.0, 25.0, -20.0, 20.0,1.0,1.0); // Set the coordinate system
    glutMainLoop();
    return 0;
}


