#include <windows.h>
#include <GL/glut.h>
#include <cmath>

GLfloat ctrlPoints[5][5] = { {4.0, 4.0}, {-2.0, 2.0}, {0.0, 0.0}, {2.0, -2.0}, {-4.0, -4.0} };
GLfloat resolution = 0.01;  // Resolution of the curve

void drawQuadraticBezierCurve() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Set color to red

    glBegin(GL_LINE_STRIP);
    for (GLfloat t = 0; t <= 1; t += resolution) {
        GLfloat x = pow(1 - t, 4) * ctrlPoints[0][0] + 4 * pow(1 - t, 3) * t * ctrlPoints[1][0] +
                    6 * pow(1 - t, 2) * pow(t, 2) * ctrlPoints[2][0] + 4 * (1 - t) * pow(t, 3) * ctrlPoints[3][0] +
                    pow(t, 4) * ctrlPoints[4][0];

        GLfloat y = pow(1 - t, 4) * ctrlPoints[0][1] + 4 * pow(1 - t, 3) * t * ctrlPoints[1][1] +
                    6 * pow(1 - t, 2) * pow(t, 2) * ctrlPoints[2][1] + 4 * (1 - t) * pow(t, 3) * ctrlPoints[3][1] +
                    pow(t, 4) * ctrlPoints[4][1];

        glVertex2f(x, y);
    }
    glEnd();

    glPointSize(5.0);
    glColor3f(0.0, 0.0, 1.0); // Set color to blue
    glBegin(GL_POINTS);
    for (int i = 0; i < 5; ++i) {
        glVertex2f(ctrlPoints[i][0], ctrlPoints[i][1]);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("OpenGL Bezier Curve with 5 Control Points");
    glutDisplayFunc(drawQuadraticBezierCurve);

    init();

    glutMainLoop();
    return 0;
}
