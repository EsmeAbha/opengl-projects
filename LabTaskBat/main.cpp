
#include <windows.h>
#include <GL/glut.h>




void initGL() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void display2() {
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.467f, 0.534f);
	glVertex2f(0.467f, 0.534f);
	glVertex2f(0.834f, 0.178f);
	glVertex2f(0.834f, -0.178f);
	glVertex2f(0.467f, -0.534f);
	glVertex2f(-0.467f, -0.534f);
    glVertex2f(-0.834f, -0.178f);
	glVertex2f(-0.834f, 0.178f);
	glEnd();



    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.0f, 0.534f);
	glVertex2f(0.467f, 0.534f);


	glVertex2f(0.834f, 0.178f);
	glVertex2f(0.834f, 0.0f);


    glVertex2f(0.834f, -0.178f);
	glVertex2f(0.834f, 0.0f);


	glVertex2f(-0.0f, -0.534f);
	glVertex2f(0.467f, -0.534f);


	glVertex2f(0.0f, -0.534f);
	glVertex2f(-0.467f, -0.534f);


	glVertex2f(-0.834f, 0.178f);
	glVertex2f(-0.834f, 0.0f);


    glVertex2f(-0.834f, -0.178f);
	glVertex2f(-0.834f, 0.0f);


	glVertex2f(0.0f, 0.534f);
	glVertex2f(-0.467f, 0.534f);
	glEnd();



glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(0.5f, 0.467f);
	glVertex2f(0.567f, 0.40f);
	glVertex2f(0.634f, 0.34f);
	glVertex2f(0.70f, 0.276f);
	glVertex2f(0.767f, 0.21f);


	glVertex2f(-0.5f, 0.467f);
	glVertex2f(-0.567f, 0.40f);
	glVertex2f(-0.634f, 0.34f);
	glVertex2f(-0.70f, 0.276f);
	glVertex2f(-0.767f, 0.21f);


	glVertex2f(0.5f, -0.467f);
	glVertex2f(0.567f, -0.40f);
	glVertex2f(0.634f, -0.34f);
	glVertex2f(0.70f, -0.276f);
	glVertex2f(0.767f, -0.21f);


	glVertex2f(-0.5f, -0.467f);
	glVertex2f(-0.567f, -0.40f);
	glVertex2f(-0.634f, -0.34f);
	glVertex2f(-0.70f, -0.276f);
	glVertex2f(-0.767f, -0.21f);


	glVertex2f(0.25f, -0.257f);
    glVertex2f(0.31f, 0.33f);


    glVertex2f(-0.25f, -0.257f);
    glVertex2f(-0.32f, 0.33f);


	glVertex2f(0.0f, -0.4f);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.367f);
	glVertex2f(0.067f, 0.367f);
	glVertex2f(0.067f, -0.387f);
	glVertex2f(0.0f, -0.387f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.067f, 0.433f);
	glVertex2f(0.133f, 0.433f);
	glVertex2f(0.133f, -0.295f);
	glVertex2f(0.067f, -0.295f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.18f, 0.167f);
	glVertex2f(0.133f, 0.167f);
	glVertex2f(0.133f, -0.2f);
	glVertex2f(0.18f, -0.2f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.28f, 0.133f);
	glVertex2f(0.133f, 0.133f);
	glVertex2f(0.133f, -0.231f);
	glVertex2f(0.28f, -0.231f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.346f, 0.167f);
	glVertex2f(0.28f, 0.167f);
	glVertex2f(0.28f, -0.433f);
	glVertex2f(0.346f, -0.433f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.446f, 0.367f);
	glVertex2f(0.346f, 0.367f);
	glVertex2f(0.346f, -0.37f);
	glVertex2f(0.446f, -0.37f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.446f, 0.334f);
	glVertex2f(0.513f, 0.334f);
	glVertex2f(0.513f, -0.334f);
	glVertex2f(0.446f, -0.334f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.513f, 0.267f);
	glVertex2f(0.58f, 0.267f);
	glVertex2f(0.58f, -0.267f);
	glVertex2f(0.513f, -0.267f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.58f, 0.2f);
	glVertex2f(0.647f, 0.2f);
	glVertex2f(0.647f, -0.2f);
	glVertex2f(0.58f, -0.2f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(0.647f, 0.135f);
	glVertex2f(0.715f, 0.135);
	glVertex2f(0.715f, -0.135f);
	glVertex2f(0.647f, -0.135f);
    glEnd();







    glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.367f);
	glVertex2f(-0.067f, 0.367f);
	glVertex2f(-0.067f, -0.387f);
	glVertex2f(0.0f, -0.387f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.067f, 0.433f);
	glVertex2f(-0.133f, 0.433f);
	glVertex2f(-0.133f, -0.295f);
	glVertex2f(-0.067f, -0.295f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.18f, 0.167f);
	glVertex2f(-0.133f, 0.167f);
	glVertex2f(-0.133f, -0.2f);
	glVertex2f(-0.18f, -0.2f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.28f, 0.133f);
	glVertex2f(-0.133f, 0.133f);
	glVertex2f(-0.133f, -0.231f);
	glVertex2f(-0.28f, -0.231f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.346f, 0.167f);
	glVertex2f(-0.28f, 0.167f);
	glVertex2f(-0.28f, -0.433f);
	glVertex2f(-0.346f, -0.433f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.446f, 0.367f);
	glVertex2f(-0.346f, 0.367f);
	glVertex2f(-0.346f, -0.37f);
	glVertex2f(-0.446f, -0.37f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.446f, 0.334f);
	glVertex2f(-0.513f, 0.334f);
	glVertex2f(-0.513f, -0.334f);
	glVertex2f(-0.446f, -0.334f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.513f, 0.267f);
	glVertex2f(-0.58f, 0.267f);
	glVertex2f(-0.58f, -0.267f);
	glVertex2f(-0.513f, -0.267f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.58f, 0.2f);
	glVertex2f(-0.647f, 0.2f);
	glVertex2f(-0.647f, -0.2f);
	glVertex2f(-0.58f, -0.2f);
    glEnd();



    glBegin(GL_POLYGON);
	glVertex2f(-0.647f, 0.135f);
	glVertex2f(-0.715f, 0.135);
	glVertex2f(-0.715f, -0.135f);
	glVertex2f(-0.647f, -0.135f);
    glEnd();





	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Batman Logo");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display2);
	initGL();
	glutMainLoop();
	return 0;
}

