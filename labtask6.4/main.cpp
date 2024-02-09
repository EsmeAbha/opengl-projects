#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

bool dayBackground = false; // Declare a global variable to track day/night background

void Grass() {
    glColor3f(0.0f, 0.8f, 0.0f); // Green color for grass
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void Tree() {
    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(-0.1f, -0.2f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for tree leaves
    glPushMatrix();
    glTranslatef(-0.2f, -0.18f, 0.0f);
    glutSolidSphere(0.1f, 100, 100);
    glTranslatef(0.2f, 0.1f, 0.0f);
    glutSolidSphere(0.15f, 100, 100);
    glTranslatef(0.2f, -0.1f, 0.0f);
    glutSolidSphere(0.12f, 100, 100);
    glPopMatrix();
    glEnd();
}

void Cloud() {
    glColor3f(1.0f, 1.0f, 1.0f); // White color for cloud
    glPushMatrix();
    glTranslatef(0.5f, 0.7f, 0.0f); // Position of the cloud
    glutSolidSphere(0.1f, 100, 100);
    glTranslatef(0.2f, 0.1f, 0.0f);
    glutSolidSphere(0.15f, 100, 100);
    glTranslatef(0.2f, -0.1f, 0.0f);
    glutSolidSphere(0.12f, 100, 100);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (dayBackground) {
        glClearColor(0.0, 0.0, 0.35, 1.0); // Night background
    } else {
        glClearColor(0.9, 0.9, 1.0, 1.0); // Day background
    }

    Grass();
    Tree();
    Cloud();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'd':
            dayBackground = false;
            break;
        case 'n':
            dayBackground = true;
            break;
    }
    glutPostRedisplay();
}

void display(int value) {
    glutPostRedisplay();
    glutTimerFunc(200, display, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Background changing animation with keyboard");
    glutDisplayFunc(display);
    glutTimerFunc(20, display, 0);
    glutKeyboardFunc(keyboard); // Register the keyboard callback
    glutMainLoop();

    return 0;
}
