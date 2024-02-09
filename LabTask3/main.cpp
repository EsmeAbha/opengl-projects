#include <windows.h>
#include <GL/glut.h>
#include<math.h>



void display() {



glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque



glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


//building
            glBegin(GL_POLYGON);
            glColor3ub(247,197,197);
            glVertex2f(0.950f, 0.700f);
            glVertex2f(0.950f, -0.900f);
            glVertex2f(0.250f, -0.900f);
            glVertex2f(0.250f, 0.700f);
            glEnd();
//border
            glBegin(GL_LINES);
            glColor3ub(0,0,0);
             glVertex2f(0.950f, 0.700f);
            glVertex2f(0.950f, -0.900f);

            glVertex2f(0.950f, -0.900f);
            glVertex2f(0.250f, -0.900f);

            glVertex2f(0.250f, -0.900f);
            glVertex2f(0.250f, 0.700f);

            glVertex2f(0.250f, 0.700f);
            glVertex2f(0.950f, 0.700f);
            glEnd();

             glBegin(GL_LINES);
            glColor3ub(0,0,0);

            glVertex2f(0.950f, -0.58f);
            glVertex2f(0.250f, -0.580f);

            glVertex2f(0.250f, -0.26f);
            glVertex2f(0.950f, -0.26f);

            glVertex2f(0.250f, 0.06f);
            glVertex2f(0.950f, 0.06f);

            glVertex2f(0.250f, 0.38f);
            glVertex2f(0.950f, 0.38f);
            glEnd();
//door
             glBegin(GL_POLYGON);
            glColor3ub(124,14,72);
            glVertex2f(0.750f, -0.650f);
            glVertex2f(0.750f, -0.900f);
            glVertex2f(0.500f, -0.900f);
            glVertex2f(0.500f, -0.650f);
            glEnd();
//Window left
            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.380f, -0.420f);
            glVertex2f(0.300f, -0.420f);
            glVertex2f(0.300f, -0.340f);
            glVertex2f(0.380f, -0.340f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.380f, -0.10f);
            glVertex2f(0.300f, -0.10f);
            glVertex2f(0.300f, -0.02f);
            glVertex2f(0.380f, -0.02f);
            glEnd();


            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.380f, 0.22f);
            glVertex2f(0.300f, 0.22f);
            glVertex2f(0.300f, 0.3f);
            glVertex2f(0.380f, 0.3f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.380f, 0.54f);
            glVertex2f(0.300f, 0.54f);
            glVertex2f(0.300f, 0.62f);
            glVertex2f(0.380f, 0.62f);
            glEnd();

            //Window right
             glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.820f, -0.420f);
            glVertex2f(0.900f, -0.420f);
            glVertex2f(0.900f, -0.340f);
            glVertex2f(0.820f, -0.340f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.820f, -0.10f);
            glVertex2f(0.900f, -0.10f);
            glVertex2f(0.900f, -0.02f);
            glVertex2f(0.820f, -0.02f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.820f, 0.22f);
            glVertex2f(0.900f, 0.22f);
            glVertex2f(0.900f, 0.3f);
            glVertex2f(0.820f, 0.3f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(212,253,255);
            glVertex2f(0.820f, 0.54f);
            glVertex2f(0.900f, 0.54f);
            glVertex2f(0.900f, 0.62f);
            glVertex2f(0.820f, 0.62f);
            glEnd();


            //lamppost
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(0.12f, -0.550f);
            glVertex2f(0.12f, -0.900f);
            glVertex2f(0.15f, -0.900f);
            glVertex2f(0.15f, -0.550f);
            glEnd();

             glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(0.12f, -0.550f);
            glVertex2f(0.10f, -0.480f);
            glVertex2f(0.17f, -0.480f);
            glVertex2f(0.15f, -0.550f);
            glEnd();

             glBegin(GL_POLYGON);
            glColor3ub(255,255,102);
            glVertex2f(0.13f, -0.545f);
            glVertex2f(0.11f, -0.485f);
            glVertex2f(0.16f, -0.485f);
            glVertex2f(0.14f, -0.545f);
            glEnd();


            //bench body
            glBegin(GL_POLYGON);
            glColor3ub(255,204,153);
            glVertex2f(0.f, -0.8f);
            glVertex2f(-0.05f, -0.75f);
            glVertex2f(-0.3f, -0.75f);
            glVertex2f(-0.25f, -0.8f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(255,204,153);
            glVertex2f(-0.05f, -0.65f);
            glVertex2f(-0.05f, -0.75f);
            glVertex2f(-0.3f, -0.75f);
            glVertex2f(-0.3f, -0.65f);
            glEnd();

            //bench border and leg
            glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(-0.3f, -0.75f);
            glVertex2f(-0.25f, -0.8f);

            glVertex2f(0.f, -0.8f);
            glVertex2f(-0.05f, -0.75f);

            glVertex2f(0.f, -0.8f);
            glVertex2f(-0.25f, -0.8f);

            glVertex2f(-0.05f, -0.65f);
            glVertex2f(-0.3f, -0.65f);

            glVertex2f(0.0f, -0.8f);
            glVertex2f(0.0f, -0.88f);

            glVertex2f(-0.25f, -0.8f);
            glVertex2f(-0.25f, -0.88f);

            glVertex2f(-0.3f, -0.75f);
            glVertex2f(-0.3f, -0.65f);

            glVertex2f(-0.05f, -0.75f);
            glVertex2f(-0.05f, -0.65f);

            glVertex2f(-0.05f, -0.80f);
            glVertex2f(-0.05f, -0.85f);

            glVertex2f(-0.3f, -0.85f);
            glVertex2f(-0.3f, -0.75f);

            glVertex2f(-0.05f, -0.75f);
            glVertex2f(-0.3f, -0.75f);
            glEnd();

            //tree

            glColor3ub(220,80,10);
            glBegin(GL_POLYGON);
            glVertex2f(-0.4f, -1.0f);
            glVertex2f(-0.6f, -1.0f);

            glVertex2f(-0.55f, -0.9f);
            glVertex2f(-0.45f, -0.9f);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(-0.45f, -0.60f);
            glVertex2f(-0.55f, -0.60f);

            glVertex2f(-0.55f, -0.9f);
            glVertex2f(-0.45f, -0.9f);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(-0.45f, -0.60f);
            glVertex2f(-0.55f, -0.60f);
            glVertex2f(-0.6f, -0.5f);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(-0.45f, -0.60f);
            glVertex2f(-0.55f, -0.60f);
            glVertex2f(-0.4f, -0.5f);
            glEnd();



    glLineWidth(7.5);
	glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin

		for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.85,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.45,y-0.25 );
        }
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,1.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.65,y-0.45 );
        }
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.9,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.68,y-0.35 );
        }

    for(int i=0;i<200;i++)
        {
            glColor3f(0.0,1.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.35,y-0.45 );
        }
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.9,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-0.32,y-0.35 );
        }


	glEnd();



glFlush(); // Render now



}



/* Main function: GLUT runs as a console application starting at main() */



int main(int argc, char** argv) {



glutInit(&argc, argv); // Initialize GLUT



glutCreateWindow("Building"); // Create a window with the given title



glutInitWindowSize(320, 320); // Set the window's initial width & height



glutDisplayFunc(display); // Register display callback handler for window re-paint



glutMainLoop(); // Enter the event-processing loop



return 0;



}
