#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 0.1f;
bool animationPaused = false;

void dis();
void display();
void update(int value);

void pauseAnimation() {
    animationPaused = true;
}


void update(int value) {
    if (animationPaused) {

        if (position1 < -1.5)
            position1 = 1.0f;
        position1 -= speed;

        if (position2 < -1.5)
            position2 = 1.0f;
        position2 -= speed;

        glutPostRedisplay();
        glutTimerFunc(100, update, 0);
    }
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void disback(int val) {
    glutDisplayFunc(display);
}

void display4(int val) {
    glutDisplayFunc(display);
}

void Rectangle(float x, float y, float height, float width, float r=1.0, float g=1.0, float b=1.0)
{
    glBegin(GL_QUADS);
    glColor3f(r,g,b); // Orange
    glVertex2f(x,y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x, y+height);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glLoadIdentity();
    // Orange box
    glPushMatrix();
    glTranslatef(position2, 0.0f, 0.0f);
    Rectangle(-0.2,-0.2, 0.4,0.4,0.75f, 0.3f, 0.10f);
    glPopMatrix();
    glutTimerFunc(1500, disback, 0);
    glFlush();
    // Pink box
    glPushMatrix();
    glTranslatef(0.0f, -position1, 0.0f);
     Rectangle(0.2,0.2, 0.4,0.4,0.80f, 0.5f, 0.55f);
    glPopMatrix();
    // Lavender box
    glPushMatrix();
    glTranslatef(-position2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.50f, 0.80f); // Lavender
    glVertex2f(-0.2f, 0.8);
    glVertex2f(0.2f, 0.8f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(-0.2f, 0.4f);
    glEnd();
    glPopMatrix();
    glutTimerFunc(1500, display4, 0);
    // Green box
    glPushMatrix();
    glTranslatef(0.0f, position1, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.40f, 0.80f, 0.40f); // Green
    glVertex2f(-0.2f, -0.0f);
    glVertex2f(0.2f, -0.0f);
    glVertex2f(0.2f, -0.4f);
    glVertex2f(-0.2f, -0.4f);
    glEnd();
    glPopMatrix();

    glutTimerFunc(1500, display4, 0);
    glFlush();
}

void dis() {
    glutDisplayFunc(display);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{	position2 += 0.05f;
			}
if (button == GLUT_RIGHT_BUTTON)
	{position1 -= 0.05f;   }

glutPostRedisplay();}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(820, 820);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Mouse interaction animation");
   glutDisplayFunc(display);
   glutTimerFunc(100, update, 0);
   glutMouseFunc(handleMouse);
   glutMainLoop();
   return 0;
}



