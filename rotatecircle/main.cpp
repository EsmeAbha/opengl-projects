#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
using namespace std;


float _move = 0.0f;
void drawScene() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);


glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
glRotatef(200,0.0f, 0.0f, 1.0f);
glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.20;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

    //glVertex2f(0.3f,0.4f);
    //glVertex2f(0.1f,0.4f);

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
glutCreateWindow("Transformation");
glutDisplayFunc(drawScene);
gluOrtho2D(-2,2,-2,2);
glutTimerFunc(20, update, 0); //Add a timer
glutMainLoop();
return 0;
}
