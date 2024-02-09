#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;

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

void DrawWheel(float x, float y, float radius) {
    const int numSegments = 50;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; ++i) {
        float theta = 2.0f * PI * float(i) / float(numSegments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}
void car(){
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.20f, 1.0f);
glVertex2f(0.1688717871834, 0.8483038868723);
glVertex2f(0.7288208760308, 0.516905446534);
glVertex2f(0.5231252923725, 0.4506257584664);
glVertex2f(-0.0370713765878, 0.7699607569833);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.20f, 0.20f, 1.0f);
glVertex2f(0.2337250189964, 0.5653858165625);
glVertex2f(-0.1023153998919, 0.3704783293016);
glVertex2f(-0.6621581704156, 0.690090060235);
glVertex2f(-0.3216567838657, 0.8906307541539);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.20f, 0.20f, 0.8f);
    glVertex2f(0.512647845376, 0.4482373003565);
glVertex2f(0.2309235937558, 0.5678372184971);
glVertex2f(-0.3240569814495, 0.8893384865879);
glVertex2f(-0.0379053215229, 0.7672592937402);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.20f, 0.20f, 0.8f);
glVertex2f(-0.6648390720314, 0.6966889454467);
glVertex2f(-0.1050480942046, 0.3639339369552);
glVertex2f(-0.2800910934631, -0.0589422196694);
glVertex2f(-0.2796719562143, -0.2290408973489);
glVertex2f(-0.8398820712899, 0.0883711955482);
glVertex2f(-0.8381489722873, 0.2599479968016);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.20f, 0.20f, 0.65f);
    glVertex2f(-0.2771432642224, -0.2336702699502);
glVertex2f(0.7318081061215, 0.3357195658872);
glVertex2f(0.7318081061215, 0.5211885677887);
glVertex2f(0.5259375140109, 0.4470009670281);
glVertex2f(0.2366058710447, 0.563846438226);
glVertex2f(-0.106511782473, 0.3709586762485);
glVertex2f(-0.2808526442604, -0.0648934782199);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.50f, 0.50f, 0.5f);
glVertex2f(0.1113683831708, 0.2497420142034);
glVertex2f(0.4388305578278, 0.4322847583739);
glVertex2f(0.2200579560357, 0.5228594024279);
glVertex2f(0.0653843331126, 0.4434324068728);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.50f, 0.50f, 0.5f);
glVertex2f(0.0821058058611, 0.2302336293302);
glVertex2f(-0.1868312141763, 0.0755600064071);
glVertex2f(-0.0878958337481, 0.3514643067564);
glVertex2f(0.0444824921771, 0.4294978462491);
glEnd();
glBegin(GL_POLYGON);
    glColor3f(0.50f, 0.50f, 0.5f);
glVertex2f(-0.1526518996102, 0.3557086931019);
glVertex2f(-0.2864236815977, 0.0268530623826);
glVertex2f(-0.7567547436857, 0.2901522400121);
glVertex2f(-0.6215895056358, 0.6217947828562);
glEnd();


    const float wheelRadius = 0.1f;
    const float wheelOffset = 0.2f;
    DrawWheel(0.5f, 0.2f, wheelRadius);
    DrawWheel(0.05f, -0.03f, wheelRadius);

}


void Tree() {
    glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
glVertex2f(0.8998690813896, 0.0646881088762);
glVertex2f(0.9027515490542, 0.1799868154604);
glVertex2f(0.8508671310913, 0.1857517507896);
glVertex2f(0.8335723251037, 0.2693433130631);
glVertex2f(0.5482080263078, 0.4192316316226);
glVertex2f(0.225371647872, 0.5806498208405);
glVertex2f(-0.1522316161913, 0.4682335819209);
glVertex2f(0.035128782008, 0.2693433130631);
glVertex2f(0.3579651604438, 0.07333551187);
glVertex2f(0.3694950311022, -0.1140248863293);
    glPopMatrix();
    glEnd();
        glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1522316161913, 0.4682335819209);
glVertex2f(0.035128782008, 0.2693433130631);
glVertex2f(0.3579651604438, 0.07333551187);
glVertex2f(0.3694950311022, -0.1140248863293);
glVertex2f(0.1686393841418, -0.1554724607912);
glVertex2f(-0.3020029694221, 0.0193375562469);
glVertex2f(-0.2926631277112, 0.4899694207589);
      glEnd();
  glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
glVertex2f(0.2196865410288, 0.5728751780023);
glVertex2f(-0.1568126869097, 0.6740242243141);
glVertex2f(-0.4883567831541, 0.5391588292317);
glVertex2f(-0.1315254253318, 0.4520582615742);
    glEnd();

    glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(0.050690796927, 0.6250997643529);
glVertex2f(-0.1497445804919, 0.6793661110776);
glVertex2f(0.0344984192752, 0.7686430040764);
glVertex2f(0.5702856229633, 0.6545531475339);
glVertex2f(0.6517535909028, 0.6697099787785);
glVertex2f(0.5513395839076, 0.6242394850448);
glVertex2f(0.1572619715489, 0.7303373037567);
    glEnd();

    glColor3f(0.0f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2928152041605, 0.458886546995);
glVertex2f(-0.4947699725796, 0.552324644602);
glVertex2f(-0.551684498225, 0.4809179762771);
glVertex2f(-0.5700440226268, 0.4258394030719);
glVertex2f(-0.5902394994687, 0.363417020106);
glVertex2f(-0.5773878323875, 0.3230260664221);
glVertex2f(-0.5718799750669, 0.289978922499);
glVertex2f(-0.5902394994687, 0.2606036834562);
glVertex2f(-0.5810597372678, 0.0751724869987);
glVertex2f(-0.2964871090408, -0.0194768020913);
glVertex2f(-0.2964871090408, 0.112087012644);
glVertex2f(-0.3, 0.3);
    glEnd();
    glColor3f(0.0f, 0.88f, 0.88f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2339999432905, 0.5373624801147);
glVertex2f(-0.3001251852949, 0.6062429405359);
glVertex2f(-0.6, 0.6);
glVertex2f(-0.8814762712503, 0.2425541095117);
glVertex2f(-0.962937844824, 0.2091970151314);
glVertex2f(-0.8178976020503, 0.121071298003);
glVertex2f(-0.825241411811, 0.1724779663279);
glVertex2f(-0.4580509237762, 0.5543560738841);
    glEnd();

glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
     glVertex2f(-0.5775000408175, 0.1822055354878);
glVertex2f(-0.7576171996973, 0.2471845105267);
glVertex2f(-0.7781368760254, 0.2369246723627);
glVertex2f(-0.7952366062988, 0.2221049061257);
glVertex2f(-0.8, 0.2);
glVertex2f(-0.7940966242806, 0.1787855894331);
glVertex2f(-0.6424790158564, 0.1252064345765);
glVertex2f(-0.6470389439293, 0.148006074941);
glVertex2f(-0.6276592496195, 0.1639658231962);
glVertex2f(-0.6014396632003, 0.1844854995242);
     glEnd();

     glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5668179872495, 0.650659402129);
glVertex2f(0.7523490353291, 0.540547479285);
glVertex2f(0.7496239687727, 0.5740402229216);
glVertex2f(0.7717622684243, 0.5866906798653);
glVertex2f(0.8, 0.6);
glVertex2f(0.8255267104352, 0.5761486324122);
glVertex2f(0.6191825939918, 0.6888146117854);
glVertex2f(0.6, 0.7);
glVertex2f(0.5778491771085, 0.6985401216403);
glVertex2f(0.5640713714807, 0.6880041526308);
glVertex2f(0.5511040250075, 0.6750368061576);
glVertex2f(0.5519144841621, 0.6596380822207);
     glEnd();


      glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5429451632702, 0.4264180995186);
glVertex2f(0.2361446618815, 0.5828261982658);
glVertex2f(0.0472518041637, 0.5455288824107);
glVertex2f(-0.1163751299102, 0.4625122761526);
glVertex2f(0.0472518041637, 0.2603848870024);
glVertex2f(0.2686294208521, 0.3602454423564);
      glEnd();
      glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
      glVertex2f(-0.0020235560812, 0.1596649016911);
glVertex2f(0.0140965478321, 0.2624305641382);
glVertex2f(-0.1450894783115, 0.4377366941951);
glVertex2f(-0.2680052706503, 0.4538567981084);
glVertex2f(-0.2700202836394, 0.222130304355);
glEnd();

 glColor3f(0.0f, 0.88f, 0.88f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2339999432905, 0.5373624801147);
    glVertex2f(-0.3001251852949, 0.6062429405359);
    glVertex2f(-0.6, 0.6);
    glVertex2f(-0.8814762712503, 0.2425541095117);
    glVertex2f(-0.962937844824, 0.2091970151314);
    glVertex2f(-0.8178976020503, 0.121071298003);
    glVertex2f(-0.825241411811, 0.1724779663279);
    glVertex2f(-0.4580509237762, 0.5543560738841);
    glEnd();

    // Headlights
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5775000408175, 0.1822055354878);
    glVertex2f(-0.6470389439293, 0.148006074941);
    glVertex2f(-0.6276592496195, 0.1639658231962);
    glEnd();

    // Exhaust pipes
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.7940966242806, 0.1787855894331);
    glVertex2f(-0.6424790158564, 0.1252064345765);
    glVertex2f(-0.6470389439293, 0.148006074941);
    glVertex2f(-0.6276592496195, 0.1639658231962);
    glEnd();

    // Spoiler
    glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5519144841621, 0.6596380822207);
    glVertex2f(0.5511040250075, 0.6750368061576);
    glVertex2f(0.5640713714807, 0.6880041526308);
    glVertex2f(0.5778491771085, 0.6985401216403);
    glVertex2f(0.6, 0.7);
    glVertex2f(0.6191825939918, 0.6888146117854);
    glVertex2f(0.8255267104352, 0.5761486324122);
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

    car();
    glutSwapBuffers();
        glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25.0, 25.0, -20.0, 20.0); // Set the projection matrix

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Background changing animation");
    glutDisplayFunc(display);
//    glutTimerFunc(20, display, 0);
    glutMainLoop();

    return 0;
}
