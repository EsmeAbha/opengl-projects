#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glLineWidth(11);
	glBegin(GL_LINES);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2f(-0.6f, 0.85f);
	glVertex2f(0.6f, 0.85f);

	glVertex2f(0.6f,0.85f);
	glVertex2f(0.9f,0.34f);

	glVertex2f(0.9f, 0.34f);
	glVertex2f(0.9f, -0.34f);

	glVertex2f(0.9f,-0.34f);
	glVertex2f(0.6f,-0.85f);

	glVertex2f(0.6f, -0.85f);
	glVertex2f(-0.6f, -0.85f);

	glVertex2f(-0.6f,-0.85f);
	glVertex2f(-0.9f,-0.34f);

	glVertex2f(-0.9f, -0.34f);
	glVertex2f(-0.9f, 0.34f);

	glVertex2f(-0.6f,0.85f);
	glVertex2f(0.9f,0.34f);

    glVertex2f(-0.9f,0.34f);
    glVertex2f(-0.6f, 0.85f);


	glEnd();

	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.6f, 0.85f);
	glVertex2f(0.6f, 0.85f);
	glVertex2f(0.9f, 0.34f);
	glVertex2f(0.9f, -0.34f);

	glVertex2f(0.6f, -0.85f);
	glVertex2f(-0.6f, -0.85f);
	glVertex2f(-0.9f, -0.34f);
	glVertex2f(-0.9f, 0.34f);

	glEnd();

	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Batman");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}
