#include <windows.h> // for MS Windows

#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */

void initGL() {

// Set "clearing" or background color

glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black and opaque

}

/* Handler for window-repaint event. Call back when the window first appears and

whenever the window needs to be re-painted. */

void display() {

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color

glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(1.0f, 0.0f, 1.0f); // Yellow

glVertex2f(0.0f, 1.0f);

glVertex2f(1.0f, 1.0f);
glVertex2f(1.0f, 0.86f);
glVertex2f(0.0f, 0.86f);


glEnd();
glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(0.0f, 0.0f, 0.90f); // Yellow

glVertex2f(0.0f, 0.86f);

glVertex2f(1.0f, 0.86f);
glVertex2f(1.0f, 0.72f);
glVertex2f(0.0f, 0.72f);


glEnd();

glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(0.50f, 0.50f, 0.90f); // Yellow

glVertex2f(0.0f, 0.72f);

glVertex2f(1.0f, 0.72f);
glVertex2f(1.0f, 0.58f);
glVertex2f(0.0f, 0.58f);


glEnd();
glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(0.20f, 1.0f, 0.20f); // Yellow

glVertex2f(0.0f, 0.58f);

glVertex2f(1.0f, 0.58f);
glVertex2f(1.0f, 0.44f);
glVertex2f(0.0f, 0.44f);


glEnd();

glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(1.0f, 1.0f, 0.0f); // Yellow

glVertex2f(0.0f, 0.44f);

glVertex2f(1.0f, 0.44f);
glVertex2f(1.0f, 0.30f);
glVertex2f(0.0f, 0.30f);


glEnd();
glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(1.0f, 0.50f, 0.0f); // Yellow

glVertex2f(0.0f, 0.30f);

glVertex2f(1.0f, 0.30f);
glVertex2f(1.0f, 0.16f);
glVertex2f(0.0f, 0.16f);


glEnd();

glBegin(GL_POLYGON); // These vertices form a closed polygon

glColor3f(1.0f, 0.0f, 0.0f); // Yellow

glVertex2f(0.0f, 0.16f);

glVertex2f(1.0f, 0.16f);
glVertex2f(1.0f, 0.02f);
glVertex2f(0.0f, 0.02f);


glEnd();
glFlush(); // Render now

}

/* Main function: GLUT runs as a console application starting at main() */

int main(int argc, char** argv) {

glutInit(&argc, argv); // Initialize GLUT

glutCreateWindow("RAINBOW FLAG"); // Create window with the given title

glutInitWindowSize(620, 620); // Set the window's initial width & height

glutInitWindowPosition(50, 50); // Position the window's initial top-left corner

glutDisplayFunc(display); // Register callback handler for window re-paint event

initGL(); // Our own OpenGL initialization

glutMainLoop(); // Enter the event-processing loop

return 0;

}
