#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat speed = 0.1f;
void dis();
void display();

void update(int value) {
    if(position <-1.5)
        position = 1.0f;
    position -= speed;
	glutPostRedisplay();
	glutTimerFunc(100,update,0);
}


void update1(int value) {
    if(position1 >1.0)
        position1 = -1.0f;
    position1 += speed;
	glutPostRedisplay();
	glutTimerFunc(100,update1,0);
}

void init() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void disback(int val)
{
    glutDisplayFunc(display);
}
void display7()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(0.0f,0.0f, 0.0f);
    glBegin(GL_QUADS);
      glColor3f(0.80f, 0.20f, 1.0f);
      glVertex2f(-0.2f, -0.2f);
      glVertex2f( -0.6f, -0.2f);
      glVertex2f( -0.6f,  -0.6f);
      glVertex2f(-0.2f,  -0.6f);
   glEnd();
   glPopMatrix();
   glutTimerFunc(1500,disback,0);
   glFlush();

}

void display6(int val) {
    glutDisplayFunc(display7);
}
void display5()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPushMatrix();
glTranslatef(0.0f,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.7f, 0.75f);
       glVertex2f(0.2f, 0.2f);
      glVertex2f( 0.6f, 0.2f);
      glVertex2f( 0.6f,  0.6f);
      glVertex2f(0.2f,  0.6f);
   glEnd();
   glPopMatrix();
   glutTimerFunc(1500,display6,0);
   glFlush();

}

void display4(int val) {

    glutDisplayFunc(display5);

}



void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glPushMatrix();
glTranslatef(0.0f,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(0.7f, 0.70f, 1.0f);
      glVertex2f(-0.2f, 0.8);
      glVertex2f( 0.2f, 0.8f);
      glVertex2f( 0.2f,  0.4f);
      glVertex2f(-0.2f,  0.4f);
   glEnd();
   glPopMatrix();
   glutTimerFunc(1500,display4,0);
   glFlush();
}

void display2(int val) {
 glutDisplayFunc(display3);


}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
   glLoadIdentity();


glPushMatrix();
glTranslatef(0.0f,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(0.60f, 1.0f, 0.60f);
       glVertex2f(-0.2f, -0.8);
      glVertex2f( 0.2f, -0.8f);
      glVertex2f( 0.2f,  -0.4f);
      glVertex2f(-0.2f,  -0.4f);
   glEnd();


glPopMatrix();

glutTimerFunc(1500,display2,0);
glFlush();

}

void dis()
{
       glutDisplayFunc(display);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("4 object calling Animation");
   glutDisplayFunc(dis);
   init();

   glutTimerFunc(100, update, 0);
     glutTimerFunc(100, update1, 0);
   glutMainLoop();
   return 0;
}

