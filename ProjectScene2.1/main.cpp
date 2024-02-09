#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<Mmsystem.h>
#include <string>
using std::string;
#define STROKEFONT  GLUT_STROKE_ROMAN

int DisplaySizeX = 50;
int DisplaySizeY = 30;
GLfloat BackgroundPosition = 0;
bool rightMouseClicked=false;
GLfloat BackgroundMoveSpeed = 0.185f;
GLfloat FinalDestination =0;
bool isProcessing = false;
GLfloat RocketPosition = 0;
GLfloat RocketMoveSpeed = 0.005f;
GLfloat RocketAngle = 0;
GLfloat RocketSpinSpeed = 0.35f;
GLfloat RocketSize = 1;
GLfloat RocketSizeChanger = 0.001;
bool isRocketinGalaxy = false;
bool canRocketControl = false;
GLfloat RocketPositionY = 0;
GLfloat SCPosition = 0;
GLfloat SCMoveSpeed = 0.15f;
GLfloat SCAngle = 0;
GLfloat SCSpinSpeed = 0.35f;
GLfloat SCSize = 1;
GLfloat SCSizeChanger = 0.001;
bool isSCinGalaxy = false;
GLfloat SCPositionY = 0;
GLfloat FTPosition = 0;
GLfloat FTMoveSpeed = 0.15f;
GLfloat FTAngle = 0;
GLfloat FTSpinSpeed = 0.35f;
GLfloat FTSize = 1;
GLfloat FTSizeChanger = 0.001;
bool isFTinGalaxy = false;
bool canFTControl = false;
GLfloat FTPositionY = 0;
GLfloat BigMeteorPosition = 110;
GLfloat BigMeteorMoveSpeed = 0.35f;
GLfloat SmallMeteorPosition = 110;
GLfloat SmallMeteorMoveSpeed = 0.085f;
bool rocketInGalaxy = false;
bool fuelTankDetached = false;
bool shuttleCockDetached=false;
int detachmentTime = 8000;
float _scale=0.0f;
bool IsFire=false;
GLfloat StarsPosition = 0;
GLfloat StarsMoveSpeed = 0.05f;
GLfloat StarsAngle = 0;


//AB001
void E_Circle(float radius,int steps,float X,float Y,int CC1,int CC2=0,int CC3=0,int CC4=0){

    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glBegin(GL_POLYGON);
    if(CC2 == 0 && CC3 == 0 && CC4 == 0) glColor3ub(CC1,CC1,CC1);  //Static Color
    else glColor4ub(CC1,CC2,CC3,CC4);         //Dynamic Color
    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}

//AB002
void E_CirclePoints(float radius,int steps,float X,float Y,int PointSize,int r,int g,int b){

    float Radius = radius;              //Circle's Radius
    int Steps = steps;                  //Increase to get Smooth Circle
    float Pi=3.1416f;                   //PI
    glPushMatrix();
    glTranslatef(X, Y, 0);              //Move Circle Along Axes
    glPointSize(PointSize);             //Point Size
    glBegin(GL_POINTS);
    glColor3ub(r,g,b);  // Color

    for(int i=0;i<Steps;i++)
        {
            float A=(i*2*Pi)/Steps;
            float x = Radius * cos(A);
            float y = Radius * sin(A);
            glVertex2f(x,y);
        }
    glEnd();
    glPopMatrix();
}
void E_scale(int value)
            {
        _scale += 0.2; // Increase scale after each iteration
            if (_scale > 1.0)
            {
            _scale = 0.0;
            }
            glutPostRedisplay();
            glutTimerFunc(200, E_scale, 0);// Reset scale to 0 after reaching 2.0
            }
void E_DrawTextStroke(float x,float y,float z,float FSize,float Density,char *CharectersArray){
	char Charecter;
    glLineWidth(Density);
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(FSize,FSize,FSize);

	for(int i = 0; *(CharectersArray+i)!='\0' ;i++)
	{
	    Charecter = *(CharectersArray + i);
        glutStrokeCharacter(STROKEFONT ,Charecter);
	}
    glPopMatrix();
}
LPSTR E_StringToSLPSTR(string s){
return const_cast<char *>(s.c_str());
}
//AB003
void E_Sky(){
    glBegin(GL_QUADS);
    glColor3ub(236,246, 255);
    glVertex2f(-50,-30);
    glColor3ub(190,215, 255);
    glVertex2f(-50,60);
    glColor3ub(190,215, 255);
    glVertex2f(50,60);
    glColor3ub(236,246, 255);
    glVertex2f(50,-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(190,215, 255);
    glVertex2f(-50,40);
    glColor3ub(0,0,20);
    glVertex2f(-50,120);
    glColor3ub(0,0,20);
    glVertex2f(50,120);
    glColor3ub(190,215, 255);
    glVertex2f(50,40);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(10,10,10);
    glVertex2f(-50,120);
    glVertex2f(-50,210);
    glVertex2f(50,210);
    glVertex2f(50,120);
    glEnd();
}
//AB004
void E_Windows1(float x, float y, float width, float height, float alpha) {
    glColor4f(0.7, 0.9, 1.0, alpha); // Light blue color for windows

    int numWindows = 5; // Adjust the number of windows as needed
    float windowWidth = width / 4;
    float windowHeight = height / 4.5;
    float spacingX = (width - numWindows * windowWidth) / (numWindows + 1);
    float spacingY = height / 9.5;

    for (int i = 0; i < numWindows; ++i) {
        float windowX = x + (i + 1) * spacingX + i * windowWidth;
        for (int j = 0; j < 4; ++j) {
            float windowY = y + (j + 1) * spacingY + j * windowHeight;
            glBegin(GL_POLYGON);
            glVertex2f(windowX, windowY);
            glVertex2f(windowX + windowWidth, windowY);
            glVertex2f(windowX + windowWidth, windowY + windowHeight);
            glVertex2f(windowX, windowY + windowHeight);
            glEnd();
        }
    }
}
//AB005
void E_Windows2(float x, float y, float width, float height, float alpha) {
    glColor4f(0.7, 0.9, 1.0, alpha); // Light blue color for windows

    int numWindows = 4; // Adjust the number of windows as needed
    float windowWidth = width * 0.2;
    float windowHeight = height * 0.2;
    float spacing = (width - numWindows * windowWidth) / (numWindows + 1);

    for (int i = 0; i < numWindows; ++i) {
        float windowX = x + (i + 1) * spacing + i * windowWidth;
        float windowY = y + height * 0.6;
        glBegin(GL_POLYGON);
        glVertex2f(windowX, windowY);
        glVertex2f(windowX + windowWidth, windowY);
        glVertex2f(windowX + windowWidth, windowY + windowHeight);
        glVertex2f(windowX, windowY + windowHeight);
        glEnd();
    }
}
//AB006
void E_buildingtype1(float x, float y, float height, float width, float r, float g, float b, float alpha) {
    // Set color with opacity
    glColor4f(r, g, b, alpha-0.5);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    glColor4f(0.4, 0.2, 0.0, alpha); // Brown color for the door
    float doorWidth = width * 0.2;
    float doorHeight = height * 0.35;
    float doorX = x + (width - doorWidth) / 2;
    float doorY = y;
    glBegin(GL_POLYGON);
    glVertex2f(doorX, doorY);
    glVertex2f(doorX + doorWidth, doorY);
    glVertex2f(doorX + doorWidth, doorY + doorHeight);
    glVertex2f(doorX, doorY + doorHeight);
    glEnd();
    E_Windows2(x, y, width, height, alpha);
}
//AB007
void E_buildingtype2(float x, float y, float height, float width, float r, float g, float b, float alpha) {
    // Set color with opacity
    glColor4f(r, g, b, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x + width / 2, y + height + width / 2);
    glVertex2f(x, y + height);
    glEnd();
    glColor4f(0.4, 0.2, 0.0, alpha); // Brown color for the door
    float doorWidth = width * 0.4;
    float doorHeight = height * 0.2;
    float doorX = x + (width - doorWidth) / 2;
    float doorY = y;
    glBegin(GL_POLYGON);
    glVertex2f(doorX, doorY);
    glVertex2f(doorX + doorWidth, doorY);
    glVertex2f(doorX + doorWidth, doorY + doorHeight);
    glVertex2f(doorX, doorY + doorHeight);
    glEnd();
    E_Windows1(x + width * 0.2, y + height * 0.1, width * 0.6, height * 0.7, alpha);
}
//AB008
void E_workshopBuilding(float x, float y, float height, float width, float r, float g, float b, float alpha) {
    // Set color with opacity
    glColor4f(r, g, b, alpha);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x , y + height +4  );
    glVertex2f(x, y + height);
    glEnd();

    glColor4f(0.4, 0.2, 0.30, alpha); // Brown color for the door
    float doorWidth = width * 0.35;
    float doorHeight = height * 0.28;
    float doorX = x + (width - doorWidth) / 2;
    float doorY = y;
    glBegin(GL_POLYGON);
    glVertex2f(doorX, doorY);
    glVertex2f(doorX + doorWidth, doorY);
    glVertex2f(doorX + doorWidth, doorY + doorHeight);
    glVertex2f(doorX, doorY + doorHeight);
    glEnd();
    glColor4f(0.753, 0.941, 1, alpha);
    int num = 4; // Adjust the number of windows as needed
    float Width = width / 5;
    float Height = height / 4;
    float spacingX = (width - num * Width) / (num + 1);
    float spacingY = height / 6;

    for (int i = 0; i < num; ++i) {
        float X = x + (i + 1) * spacingX + i * Width;
        float Y = y + height * 0.4;
        glBegin(GL_POLYGON);
        glVertex2f(X, Y);
        glVertex2f(X + Width, Y);
        glVertex2f(X + Width, Y + Height);
        glVertex2f(X, Y + Height);
        glEnd();
    }
    glBegin(GL_POLYGON);
    glVertex2f(8.8f,-5.0f);
    glVertex2f(28.0f,-5.0f);
    glVertex2f(28.0f,-5.0f+3.0f);
    glVertex2f(8.8f,-5.0f+3.0f);
    glEnd();
     glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glTranslatef(9.6f, 0.1f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0,0.70,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9.6f, 0.1f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.9,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=1.;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    glPopMatrix();
    //satdish
glBegin(GL_POLYGON);
glColor3ub(100, 100, 100);
glVertex2f(17,0.04);
glVertex2f(16,0.24);
glVertex2f(16,2.5);
glVertex2f(17,2.5);
glEnd();

//Antena
glPointSize(3);
glColor3ub(205,205,205);
glColor3ub(0,0,0);
}
//AB009
void E_fire(float x,float y){
    if(IsFire){
 glPushMatrix();
glTranslatef(x,y,0);

        glScalef(1.8,-_scale+1.5,0);
        glRotatef(180,0,0,1);
        glBegin(GL_POLYGON);
        glColor3ub(250,168,4);
        glVertex2f(-6.63022604633, -4.2481012424478);
        glVertex2f(-6.7465559980783, -4.2297333553297);
        glVertex2f(-6.8934990950236, -4.1929975810933);
        glVertex2f(-7.0281969338902, -4.1072807745419);
        glVertex2f(-7.1077911114022, -4.0093187099117);
        glVertex2f(-7.1751400308355, -3.9236019033603);
        glVertex2f(-7.2363663212293, -3.7950266935332);
        glVertex2f(-7.2975926116232, -3.6603288546666);
        glVertex2f(-7.2975926116232, -3.5378762738789);
        glVertex2f(-7.3037152406626, -3.4031784350124);
        glVertex2f(-7.2731342956184, -3.2530613230128);
        glVertex2f(-7.2317340992589, -3.1150606684812);
        glVertex2f(-7.1855082943277, -3.0266532824312);
        glVertex2f(-7.1666570335488, -3.0989164487502);
        glVertex2f(-7.14780577277, -3.1586121078832);
        glVertex2f(-7.1038194976193, -3.2403009045916);
        glVertex2f(-7.0786844832475, -3.2811453029458);
        glVertex2f(-7.0472657152827, -3.1806052454586);
        glVertex2f(-7.0127050705215, -3.0926326951572);
        glVertex2f(-6.9718606721673, -2.9889507608735);
        glVertex2f(-6.9121650130342, -2.8632756890144);
        glVertex2f(-6.8493274771047, -2.7784450155095);
        glVertex2f(-6.7770643107857, -2.6779049580223);
        glVertex2f(-6.6985173908738, -2.5899324077209);
        glVertex2f(-6.6168285941654, -2.5019598574196);
        glVertex2f(-6.5382816742535, -2.4391223214901);
        glVertex2f(-6.462876631138, -2.3919941695429);
        glVertex2f(-6.4785860151204, -2.5082436110125);
        glVertex2f(-6.4848697687134, -2.5962161613139);
        glVertex2f(-6.4785860151204, -2.6873305884117);
        glVertex2f(-6.4660185079345, -2.7753031387131);
        glVertex2f(-6.4471672471556, -2.853850058625);
        glVertex2f(-6.4094647255979, -2.9166875945545);
        glVertex2f(-6.3780459576332, -2.9669576232982);
        glVertex2f(-6.3277759288895, -3.0423626664136);
        glVertex2f(-6.2743640233494, -3.117767709529);
        glVertex2f(-6.2303777481988, -3.2025983830339);
        glVertex2f(-6.2021008570305, -3.2811453029458);
        glVertex2f(-6.1738239658622, -3.3345572084859);
        glVertex2f(-6.1549727050833, -3.3785434836366);
        glVertex2f(-6.0984189227467, -3.2780034261494);
        glVertex2f(-6.0324395100207, -3.1806052454586);
        glVertex2f(-5.9538925901088, -3.124051463122);
        glVertex2f(-5.9732645569233, -3.1875985965982);
        glVertex2f(-5.9850346874527, -3.2582193797749);
        glVertex2f(-6, -3.3);
        glVertex2f(-6.0068935012931, -3.3372473990441);
        glVertex2f(-6.0035306068562, -3.4196383127502);
        glVertex2f(-6.0035306068562, -3.4196383127502);
        glVertex2f(-6.0018491596377, -3.48689620149);
        glVertex2f(-6.0055175561859, -3.6216138681457);
        glVertex2f(-6.0132346222923, -3.7367462720148);
        glVertex2f(-6.0307633596626, -3.8384129487625);
        glVertex2f(-6.0728323293513, -3.92255088814);
        glVertex2f(-6.1219127939881, -4.0031830800433);
        glVertex2f(-6.1955334909434, -4.0627807871023);
        glVertex2f(-6.2621426929505, -4.1293899891094);
        glVertex2f(-6.3287518949576, -4.1819762012203);
        glVertex2f(-6.4, -4.2);
            glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(250,78,4);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glVertex2f(-6.249969451022, -3.7398782521956);
        glVertex2f(-6.2816318998933, -3.7062369002698);
        glVertex2f(-6.3172521548736, -3.6587432269628);
        glVertex2f(-6.3172521548736, -3.6053128444924);
        glVertex2f(-6.319231057928, -3.5597980742399);
        glVertex2f(-6.344956797636, -3.5182411100962);
        glVertex2f(-6.3726614403984, -3.4766841459526);
        glVertex2f(-6.3944293739974, -3.4371060848635);
        glVertex2f(-6.4221340167598, -3.3915913146109);
        glVertex2f(-6.4597331747945, -3.3520132535217);
        glVertex2f(-6.5, -3.3);
        glVertex2f(-6.5230580725372, -3.2629626160711);
        glVertex2f(-6.5487838122452, -3.2095322336008);
        glVertex2f(-6.5764884550076, -3.1640174633482);
        glVertex2f(-6.5923196794433, -3.1185026930957);
        glVertex2f(-6.6148690407736, -3.0553333670344);
        glVertex2f(-6.639136829248, -2.9916304222892);
        glVertex2f(-6.6816054590781, -3.0462329463565);
        glVertex2f(-6.7119401946711, -3.0887015761867);
        glVertex2f(-6.7544088245012, -3.1402706266947);
        glVertex2f(-6.8, -3.2);
        glVertex2f(-6.8277637305715, -3.272916152333);
        glVertex2f(-6.8360368402787, -3.3446164364619);
        glVertex2f(-6.8608561694002, -3.4080436108835);
        glVertex2f(-6.8884332017574, -3.482501598248);
        glVertex2f(-6.9049794211717, -3.5321402564911);
        glVertex2f(-6.9491026729433, -3.5790212114984);
        glVertex2f(-7, -3.6);
        glVertex2f(-7.0704416153152, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6259021665057);
        glVertex2f(-7.1338687897368, -3.6865716376916);
        glVertex2f(-7.1311110865011, -3.7444834056418);
        glVertex2f(-7.1200802735582, -3.8079105800635);
        glVertex2f(-7.1145648670868, -3.8575492383065);
        glVertex2f(-7.1035340541439, -3.912703303021);
        glVertex2f(-7.0897455379652, -3.9816458839141);
        glVertex2f(-7.0594108023723, -4.0505884648071);
        glVertex2f(-6.9904682214792, -4.1305618586431);
        glVertex2f(-6.9353141567647, -4.1664120007075);
        glVertex2f(-6.8774023888145, -4.1939890330648);
        glVertex2f(-6.8112175111571, -4.2270814718935);
        glVertex2f(-6.7615788529141, -4.2491430977793);
        glVertex2f(-6.7091824914354, -4.2601739107222);
        glVertex2f(-6.6816054590781, -4.2601739107222);
        glVertex2f(-6.6337519252008, -4.2555968981756);
        glVertex2f(-6.5531197332974, -4.2415739082793);
        glVertex2f(-6.4759932888681, -4.2275509183831);
        glVertex2f(-6.4, -4.2);
        glVertex2f(-6.3287518949576, -4.1539302214279);
        glVertex2f(-6.2726599353727, -4.1083555042651);
        glVertex2f(-6.2380960326952, -4.0683761592356);
        glVertex2f(-6.2, -4);
        glVertex2f(-6.1826867471704, -3.9199584301513);
        glVertex2f(-6.1727922318981, -3.8546546293541);
        glVertex2f(-6.1628977166258, -3.7873719255026);
        glVertex2f(-6.1668555227347, -3.7557094766312);
        glVertex2f(-6.202475777715, -3.7656039919035);
        glEnd();
        glPopMatrix();
    }
}
//AB010
void E_shuttleCock(){
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(SCPosition,SCPositionY,0);
    glRotatef(SCAngle,0,0,1);
    glScalef(SCSize,SCSize,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-6.0f, -10.0f);
    glVertex2f(-3.5f, -10.0f);
    glVertex2f(-3.0f, -10.50f);
    glVertex2f(-6.5f, -10.50f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-6.0f, -10.0f);
    glVertex2f(-3.5f, -10.0f);
    glVertex2f(-3.5f, 3.0f);
    glVertex2f(-6.0f, 3.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(-4.75f, 3.0f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/400;
            float r=1.25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(6.0f, -10.0f);
    glVertex2f(3.5f, -10.0f);
    glVertex2f(3.0f, -10.50f);
    glVertex2f(6.5f, -10.50f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(6.0f, -10.0f);
    glVertex2f(3.5f, -10.0f);
    glVertex2f(3.5f, 3.0f);
    glVertex2f(6.0f, 3.0f);
    glEnd();
   glPushMatrix();
    glTranslatef(4.75f, 3.0f, 0.0f);
    glLineWidth(7.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/400;
            float r=1.25;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
	glFlush();
    E_fire(-11.8f,-20.0f);
    E_fire(-21.8f,-20.0f);
    glPopMatrix();
    glPopMatrix();

}
//AB011
void E_fuelTank() {
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(FTPosition, FTPositionY, 0);
    glRotatef(FTAngle, 0, 0, 1);
    glScalef(FTSize, FTSize, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.778, 0.5, 0.002);
    glVertex2f(-4.0f, -10.f);
    glVertex2f(4.0f, -10.f);
    glVertex2f(2.5f, -8.0f);
    glVertex2f(-2.5f, -8.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.778, 0.5, 0.002);
    glVertex2f(-3.3f, -8.0f);
    glVertex2f(3.3f, -8.0f);
    glVertex2f(3.3f, 10.0f);
    glVertex2f(-3.3f, 10.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.778, 0.5, 0.002);
    glVertex2f(-3.3f, 10.0f);
    glVertex2f(3.3f, 10.0f);
    glVertex2f(0.0f, 13.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-3.3f, -8.0f);
    glVertex2f(3.3f, -8.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.2, 0.0);
    glVertex2f(-3.0f, -9.50f);
    glVertex2f(3.0f, -9.50f);
    glVertex2f(2.0f, -8.5f);
    glVertex2f(-2.0f, -8.5f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2.5f, -8.0f);
    glVertex2f(2.5f, -8.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-3.0f, -6.0f);
    glVertex2f(3.0f, -6.0f);
    glVertex2f(-3.0f, -7.0f);
    glVertex2f(3.0f, -7.0f);
    glVertex2f(-3.0f, -6.50f);
    glVertex2f(3.0f, -6.50f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.3, 0.0);
    glVertex2f(-1.0f, -8.0f);
    glVertex2f(1.0f, -8.0f);
    glVertex2f(0.0f, -7.0f);
    glEnd();
    E_fire(-13.8f, -15.5f);
    E_fire(-11.8f, -15.5f);
    E_fire(-9.8f, -15.5f);
    glPopMatrix();
}
void E_timer1(int value) {
    if (rightMouseClicked) {

        SCPositionY -= 0.80; // Adjust the translation distance as needed
        SCAngle -= 5;
        glutPostRedisplay();
    }
    glutTimerFunc(20, E_timer1, 0);

}
void E_timer2(int value) {
    if (rightMouseClicked) {
        FTPositionY -= 0.80; // Adjust the translation distance as needed
        glutPostRedisplay();
    }
    glutTimerFunc(20, E_timer2, 0);
}
//AB012
void E_Rocket(){
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(RocketPosition,RocketPositionY,0);
    glRotatef(RocketAngle,0,0,1);
    glScalef(RocketSize,RocketSize,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.95f, 0.90f, 0.90f);
    glVertex2f(-0.5f, 6.0f);
    glVertex2f(0.5f, 6.0f);
    glVertex2f(0.0f, 7.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.70f, 0.70f, 0.70f);
    glVertex2f(-0.5f, 6.0f);
    glVertex2f(-2.0f, 4.0f);
    glVertex2f(-2.5f, 3.0f);
    glVertex2f(-2.5f, -4.0f);
    glVertex2f(2.5f, -4.0f);
    glVertex2f(2.5f, 3.0f);
    glVertex2f(2.0f, 4.0f);
    glVertex2f(0.5f, 6.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(-0.50f, 5.90f);
    glVertex2f(-1.5f, 4.0f);
    glVertex2f(-2.0f, -5.0f);
    glVertex2f(2.0f, -5.0f);
    glVertex2f(1.5f, 4.0f);
    glVertex2f(0.50f, 5.90f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(-1.0f, 2.0f);
    glVertex2f(-3.0f, -0.50f);
    glVertex2f(-3.0f, -1.50f);
    glVertex2f(-5.5f, -3.0f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-1.0f, -3.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.40f, 0.40f, 0.40f);
    glVertex2f(1.0f, 2.0f);
    glVertex2f(3.0f, -0.50f);
    glVertex2f(3.0f, -1.50f);
    glVertex2f(5.5f, -3.0f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(1.0f, -3.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.767, 0.975, 0.979);
    glVertex2f(-0.50f, 5.0f);
    glVertex2f(-1.2f, 4.0f);
    glVertex2f(-1.42f, 1.3f);
    glVertex2f(1.42f, 1.3f);
    glVertex2f(1.2f, 4.0f);
    glVertex2f(0.50f, 5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(-1.58f, 1.3f);
    glVertex2f(-1.98f, 0.8f);
    glVertex2f(1.98f, 0.8f);
    glVertex2f(1.58f, 1.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-5.5f, -3.0f);
    glVertex2f(-6.2f, -3.0f);
    glVertex2f(-6.2f, -5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.80f, 0.20f, 0.20f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(5.5f, -3.0f);
    glVertex2f(6.2f, -3.0f);
    glVertex2f(6.2f, -5.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(4.0, -5.0f);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(5.4f, -1.0f);
    glVertex2f(5.4f, -5.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.937, 0.949);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(5.4f, -1.0f);
    glVertex2f(4.75f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-4.0, -5.0f);
    glVertex2f(-4.0f, -1.0f);
    glVertex2f(-5.4f, -1.0f);
    glVertex2f(-5.4f, -5.0f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.937, 0.937, 0.949);
    glVertex2f(-4.0f, -1.0f);
    glVertex2f(-5.4f, -1.0f);
    glVertex2f(-4.75f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(2.0, 0.7f);
    glVertex2f(2.0f, -3.5f);
    glVertex2f(3.4f, -4.0f);
    glVertex2f(3.4f, -.75f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(2.0f, 0.0f);
    glVertex2f(3.4f, -0.75f);
    glVertex2f(2.f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(-2.0, 0.7f);
    glVertex2f(-2.0f, -3.5f);
    glVertex2f(-3.4f, -4.0f);
    glVertex2f(-3.4f, -.75f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.85f, 0.85f, 0.85f);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(-3.4f, -0.75f);
    glVertex2f(-2.f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(1.0f, -3.5f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, -3.5f);
    glVertex2f(-1.2f, -3.5f);
    glVertex2f(-1.2f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -3.5f);
    glVertex2f(1.2f, -3.5f);
    glVertex2f(1.2f, 0.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.90f, 0.90f, 0.90f);
    glVertex2f(-0.50f, -1.0f);
    glVertex2f(-0.50f, -2.5f);
    glVertex2f(0.50f, -2.5f);
    glVertex2f(0.50f, -1.0f);
    glEnd();
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.50f, 0.50f);
    glVertex2f(-0.25f, -1.10f);
    glVertex2f(-0.85f, -1.45f);
    glVertex2f(-0.25f, -1.60f);
    glVertex2f(-0.85f, -1.95f);
    glVertex2f(-0.25f, -2.10f);
    glVertex2f(-0.85f, -2.45f);
    glVertex2f(0.25f, -1.10f);
    glVertex2f(0.85f, -1.45f);
    glVertex2f(0.25f, -1.60f);
    glVertex2f(0.85f, -1.95f);
    glVertex2f(0.25f, -2.10f);
    glVertex2f(0.85f, -2.45f);
    glEnd();
    glColor3f(0.80f, 0.8f, 0.80f);
    glPushMatrix();
    glTranslatef(0.0f, 0.50f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(2.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, -5.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(-1.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glTranslatef(2.0f, -0.0f, 0.0f);
    glutSolidSphere(0.15f, 200, 200);
    glPopMatrix();
    glBegin(GL_LINES);
    glColor4ub(0,0,0,0);
    glVertex2f(-3,5);
    glVertex2f(-3,5);
    glVertex2f(1.5,0);
    glVertex2f(-1.5,0);
    glVertex2f(1.5,-1);
    glVertex2f(-1.5,-1);
    glEnd();
    glPopMatrix();
}
//AB013
void E_RocketHolder(){
    glBegin(GL_POLYGON);
    glColor3f(0.843f, 0.771f, 0.863f);
    glVertex2f(-15.0f, -12.0f);
    glVertex2f(15.0f, -12.0f);
    glVertex2f(13.0f, -10.50f);
    glVertex2f(-13.0f, -10.50f);
    glEnd();
     glLineWidth(6.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-7.0f, 0.0f);
    glVertex2f(-5.5f, 0.0f);
    glVertex2f(-7.0f, -5.0f);
    glVertex2f(-5.5f, -5.0f);
    glVertex2f(-12.5f, -10.50f);
    glVertex2f(-12.5f, 8.0f);
    glVertex2f(-12.5f, 8.0f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-12.5f, 7.0f);
    glVertex2f(-11.0f, 7.0f);
    glVertex2f(-12.5f, 6.0f);
    glVertex2f(-11.0f, 6.0f);
    glVertex2f(-12.5f, 5.0f);
    glVertex2f(-11.0f, 5.0f);
    glVertex2f(-12.5f, 4.0f);
    glVertex2f(-11.0f, 4.0f);
    glVertex2f(-12.5f, 3.0f);
    glVertex2f(-11.0f, 3.0f);
    glVertex2f(-12.5f, 2.0f);
    glVertex2f(-11.0f, 2.0f);
    glVertex2f(-12.5f, 1.0f);
    glVertex2f(-11.0f, 1.0f);
    glVertex2f(-12.5f, 0.0f);
    glVertex2f(-11.0f, 0.0f);
    glVertex2f(-12.5f, -10.0f);
    glVertex2f(-11.0f, -10.0f);
    glVertex2f(-12.5f, -9.0f);
    glVertex2f(-11.0f, -9.0f);
    glVertex2f(-12.5f, -8.0f);
    glVertex2f(-11.0f, -8.0f);
    glVertex2f(-12.5f, -7.0f);
    glVertex2f(-11.0f, -7.0f);
    glVertex2f(-12.5f, -6.0f);
    glVertex2f(-11.0f, -6.0f);
    glVertex2f(-12.5f, -5.0f);
    glVertex2f(-11.0f, -5.0f);
    glVertex2f(-12.5f, -4.0f);
    glVertex2f(-11.0f, -4.0f);
    glVertex2f(-12.5f, -3.0f);
    glVertex2f(-11.0f, -3.0f);
    glVertex2f(-12.5f, -2.0f);
    glVertex2f(-11.0f, -2.0f);
    glVertex2f(-12.5f, -1.0f);
    glVertex2f(-11.0f, -1.0f);
    glVertex2f(-7.0f, -10.50f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-11.0f, -10.50f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-7.0f, 8.0f);
    glVertex2f(-11.0f, 4.0f);
    glVertex2f(-7.0f, 4.0f);
    glVertex2f(-11.0f, 0.0f);
    glVertex2f(-7.0f, 0.0f);
    glVertex2f(-11.0f, -4.0f);
    glVertex2f(-7.0f, -4.0f);
    glVertex2f(-11.0f, -8.0f);
    glVertex2f(-7.0f, 4.0f);
    glVertex2f(-11.0f, 8.0f);
    glVertex2f(-7.0f, 0.0f);
    glVertex2f(-11.0f, 4.0f);
    glVertex2f(-7.0f, -4.0f);
    glVertex2f(-11.0f, -0.0f);
    glVertex2f(-7.0f, -8.0f);
    glVertex2f(-11.0f, -4.0f);
    glVertex2f(-7.0f, -8.0f);
    glVertex2f(-11.0f, -8.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(5.5f, 0.0f);
    glVertex2f(7.0f, -5.0f);
    glVertex2f(5.5f, -5.0f);
    glVertex2f(7.0f, -10.50f);
    glVertex2f(7.0f, 8.0f);
    glVertex2f(11.0f, -10.50f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(7.0f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(7.0f, 8.0f);
    glVertex2f(11.0f, 4.0f);
    glVertex2f(7.0f, 4.0f);
    glVertex2f(11.0f, 0.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(11.0f, -4.0f);
    glVertex2f(7.0f, -4.0f);
    glVertex2f(11.0f, -8.0f);
    glVertex2f(7.0f, 4.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(11.0f, 4.0f);
    glVertex2f(7.0f, -4.0f);
    glVertex2f(11.0f, -0.0f);
    glVertex2f(7.0f, -8.0f);
    glVertex2f(11.0f, -4.0f);
    glVertex2f(7.0f, -8.0f);
    glVertex2f(11.0f, -8.0f);
    glVertex2f(12.5f, -10.50f);
    glVertex2f(12.5f, 8.0f);
    glVertex2f(12.5f, 8.0f);
    glVertex2f(11.0f, 8.0f);
    glVertex2f(12.5f, 7.0f);
    glVertex2f(11.0f, 7.0f);
    glVertex2f(12.5f, 6.0f);
    glVertex2f(11.0f, 6.0f);
    glVertex2f(12.5f, 5.0f);
    glVertex2f(11.0f, 5.0f);
    glVertex2f(12.5f, 4.0f);
    glVertex2f(11.0f, 4.0f);
    glVertex2f(12.5f, 3.0f);
    glVertex2f(11.0f, 3.0f);
    glVertex2f(12.5f, 2.0f);
    glVertex2f(11.0f, 2.0f);
    glVertex2f(12.5f, 1.0f);
    glVertex2f(11.0f, 1.0f);
    glVertex2f(12.5f, 0.0f);
    glVertex2f(11.0f, 0.0f);
    glVertex2f(12.5f, -10.0f);
    glVertex2f(11.0f, -10.0f);
    glVertex2f(12.5f, -9.0f);
    glVertex2f(11.0f, -9.0f);
    glVertex2f(12.5f, -8.0f);
    glVertex2f(11.0f, -8.0f);
    glVertex2f(12.5f, -7.0f);
    glVertex2f(11.0f, -7.0f);
    glVertex2f(12.5f, -6.0f);
    glVertex2f(11.0f, -6.0f);
    glVertex2f(12.5f, -5.0f);
    glVertex2f(11.0f, -5.0f);
    glVertex2f(12.5f, -4.0f);
    glVertex2f(11.0f, -4.0f);
    glVertex2f(12.5f, -3.0f);
    glVertex2f(11.0f, -3.0f);
    glVertex2f(12.5f, -2.0f);
    glVertex2f(11.0f, -2.0f);
    glVertex2f(12.5f, -1.0f);
    glVertex2f(11.0f, -1.0f);
    glEnd();
     glColor3f(0.361f, 0.369f, 0.263f);
    glBegin(GL_POLYGON);
    glVertex2f(-25.0f, -12.0f);
    glVertex2f(25.0f, -12.0f);
    glVertex2f(25.0f, -20.0f);
    glVertex2f(-25.0f, -20.0f);
    glEnd();
}
//AB014
void E_sun(){
    E_Circle(4.5,35,0,32,255,255,51,255);
}
//AB015
void E_Cloud(){
glPushMatrix();
glTranslatef(5,15,0);
E_Circle(2,30,2.5,-1,255);
E_Circle(2,30,-1,-2,255);
E_Circle(2,30,1,0,255);
E_Circle(2.3,35,-2.5,1,255);
glPopMatrix();
glPushMatrix();
glTranslatef(20,25,0);
glScalef(1.0,1.0,0);
E_Circle(2,30,2.5,-1,255);
E_Circle(2,30,-1,-2,255);
E_Circle(2,30,1,0,255);
E_Circle(2.3,35,-2.5,1,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-20,35,0);
glScalef(1.0,1.0,0);
E_Circle(2.5,30,2.5,-1,255);
E_Circle(2.5,30,-1,-2,255);
E_Circle(2.5,30,1,0,255);
E_Circle(2.8,35,-2.5,1,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-20,9,0);
glScalef(1.0,1.0,0);
E_Circle(1.5,30,-2.2,-1,255);
E_Circle(1.5,30,-1.2,-1.2,255);
E_Circle(1.5,30,1.2,-1.6,255);
E_Circle(1.8,35,2.2,-0.7,255);
glPopMatrix();
glPushMatrix();
glTranslatef(-15,18,0);
glScalef(0.50,0.50,0);
E_Circle(1.5,30,-2.2,-1,255);
E_Circle(1.5,30,-1.2,-1.2,255);
E_Circle(1.5,30,1.2,-1.6,255);
E_Circle(1.8,35,2.2,-0.7,255);
glPopMatrix();
}
//AB016
void E_bigMeteor1(){
glPushMatrix();
            glTranslatef(BigMeteorPosition,150,0);
            glScalef(18.0f,18.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(197,124,22);
            glVertex2f(-0.16, 0.45);
            glVertex2f(-0.12, 0.45);
            glVertex2f(-0.06, 0.41);
            glVertex2f(-0.04, 0.39);
            glVertex2f(-0.03, 0.38);
            glVertex2f(-0.01, 0.4);
            glVertex2f(0.03, 0.39);
            glVertex2f(0.05, 0.36);
            glVertex2f(0.05, 0.32);
            glVertex2f(0.06, 0.28);
            glVertex2f(0.06, 0.26);
            glVertex2f(0.07, 0.22);
            glVertex2f(0.05, 0.18);
            glVertex2f(0.05, 0.14);
            glVertex2f(0.04, 0.13);
            glVertex2f(0.02, 0.11);
            glVertex2f(-0.08, 0.09);
            glVertex2f(-0.11, 0.11);
            glVertex2f(-0.11, 0.09);
            glVertex2f(-0.18, 0.08);
            glVertex2f(-0.21, 0.02);
            glVertex2f(-0.26, 0.05);
            glVertex2f(-0.27, 0.05);
            glVertex2f(-0.3, 0.11);
            glVertex2f(-0.36, 0.11);
            glVertex2f(-0.36, 0.15);
            glVertex2f(-0.41, 0.18);
            glVertex2f(-0.41, 0.2);
            glVertex2f(-0.39, 0.23);
            glVertex2f(-0.42, 0.26);
            glVertex2f(-0.39, 0.29);
            glVertex2f(-0.39, 0.29);
            glVertex2f(-0.39, 0.32);
            glVertex2f(-0.38, 0.34);
            glVertex2f(-0.38, 0.37);
            glVertex2f(-0.35, 0.37);
            glVertex2f(-0.34, 0.39);
            glVertex2f(-0.31, 0.39);
            glVertex2f(-0.3, 0.39);
            glVertex2f(-0.3, 0.41);
            glVertex2f(-0.28, 0.42);
            glVertex2f(-0.25, 0.43);
            glVertex2f(-0.23, 0.45);
            glVertex2f(-0.19, 0.45);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(197,124,22);
            glVertex2f(-0.05, 0.3);
            glVertex2f(-0.02, 0.26);
            glVertex2f(-0.04, 0.23);
            glVertex2f(-0.06, 0.22);
            glVertex2f(-0.09, 0.24);
            glVertex2f(-0.09, 0.3);
            glEnd();
glPopMatrix();
}
//AB017
void E_bigMeteor2(){
            glPushMatrix();
            glTranslatef(BigMeteorPosition,190,0);
            glScalef(10.0f,10.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(96,82,82);
            glVertex2f(-0.14, 0.46);
            glVertex2f(-0.06, 0.5);
            glVertex2f(-0.01, 0.5);
            glVertex2f(0.05, 0.48);
            glVertex2f(0.14, 0.48);
            glVertex2f(0.15, 0.5);
            glVertex2f(0.22, 0.5);
            glVertex2f(0.25, 0.44);
            glVertex2f(0.32, 0.4);
            glVertex2f(0.38, 0.36);
            glVertex2f(0.39, 0.3);
            glVertex2f(0.41, 0.28);
            glVertex2f(0.38, 0.23);
            glVertex2f(0.34, 0.18);
            glVertex2f(0.38, 0.13);
            glVertex2f(0.3, 0.09);
            glVertex2f(0.36, -0.03);
            glVertex2f(0.33, -0.04);
            glVertex2f(0.27, -0.04);
            glVertex2f(0.23, 0.02);
            glVertex2f(0.23, 0.09);
            glVertex2f(0.21, 0.09);
            glVertex2f(0.18, 0.08);
            glVertex2f(0.18, 0.07);
            glVertex2f(0.17, 0.04);
            glVertex2f(0.2, 0);
            glVertex2f(0.23, -0.01);
            glVertex2f(0.23, -0.01);
            glVertex2f(0.23, -0.01);
            glVertex2f(0.2, 0.09);
            glVertex2f(0.11, 0.1);
            glVertex2f(0.12, 0.05);
            glVertex2f(0.12, 0.05);
            glVertex2f(0.18, 0.05);
            glVertex2f(0.08, 0.01);
            glVertex2f(-0.07, 0.08);
            glVertex2f(-0.14, 0.07);
            glVertex2f(-0.14, 0.14);
            glVertex2f(-0.22, 0.14);
            glVertex2f(-0.19, 0.2);
            glVertex2f(-0.19, 0.2);
            glVertex2f(-0.19, 0.2);
            glVertex2f(-0.22, 0.18);
            glVertex2f(-0.23, 0.21);
            glVertex2f(-0.23, 0.25);
            glVertex2f(-0.23, 0.25);
            glVertex2f(-0.22, 0.26);
            glVertex2f(-0.21, 0.26);
            glVertex2f(-0.22, 0.29);
            glVertex2f(-0.22, 0.29);
            glVertex2f(-0.22, 0.29);
            glVertex2f(-0.19, 0.33);
            glVertex2f(-0.18, 0.33);
            glVertex2f(-0.18, 0.36);
            glVertex2f(-0.18, 0.37);
            glVertex2f(-0.13, 0.38);
            glVertex2f(-0.15, 0.42);
            glVertex2f(-0.15, 0.42);
            glVertex2f(-0.12, 0.46);
            glVertex2f(-0.12, 0.48);
            glEnd();
            glPopMatrix();
}
//AB018
void E_bigMeteor3(){
            glPushMatrix();
            glTranslatef(BigMeteorPosition,140,0);
            glScalef(20.0f,20.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(192,141,114);
            glVertex2f(-0.21, 0.24);
            glVertex2f(-0.16, 0.29);
            glVertex2f(-0.12, 0.28);
            glVertex2f(-0.09, 0.31);
            glVertex2f(-0.05, 0.31);
            glVertex2f(-0.02, 0.28);
            glVertex2f(0.02, 0.27);
            glVertex2f(0.05, 0.25);
            glVertex2f(0.05, 0.21);
            glVertex2f(0.08, 0.18);
            glVertex2f(0.08, 0.13);
            glVertex2f(0.11, 0.07);
            glVertex2f(0.07, 0.02);
            glVertex2f(0.07, -0.02);
            glVertex2f(0.05, -0.06);
            glVertex2f(-0.03, -0.06);
            glVertex2f(-0.05, -0.11);
            glVertex2f(-0.09, -0.12);
            glVertex2f(-0.14, -0.15);
            glVertex2f(-0.17, -0.14);
            glVertex2f(-0.19, -0.11);
            glVertex2f(-0.23, -0.11);
            glVertex2f(-0.23, -0.08);
            glVertex2f(-0.27, -0.06);
            glVertex2f(-0.27, -0.04);
            glVertex2f(-0.26, 0);
            glVertex2f(-0.29, 0);
            glVertex2f(-0.33, 0.03);
            glVertex2f(-0.31, 0.08);
            glVertex2f(-0.39, 0.09);
            glVertex2f(-0.37, 0.13);
            glVertex2f(-0.37, 0.17);
            glVertex2f(-0.33, 0.17);
            glVertex2f(-0.33, 0.21);
            glVertex2f(-0.31, 0.21);
            glVertex2f(-0.3, 0.22);
            glVertex2f(-0.25, 0.23);
            glVertex2f(-0.25, 0.25);
            glEnd();
            glPopMatrix();
}
//AB019
void E_bigMeteor4(){
            glPushMatrix();
            glTranslatef(BigMeteorPosition,165,0);
            glScalef(20.0f,20.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(192,141,114);
            glVertex2f(-0.21, 0.24);
            glVertex2f(-0.16, 0.29);
            glVertex2f(-0.12, 0.28);
            glVertex2f(-0.09, 0.31);
            glVertex2f(-0.05, 0.31);
            glVertex2f(-0.02, 0.28);
            glVertex2f(0.02, 0.27);
            glVertex2f(0.05, 0.25);
            glVertex2f(0.05, 0.21);
            glVertex2f(0.08, 0.18);
            glVertex2f(0.08, 0.13);
            glVertex2f(0.11, 0.07);
            glVertex2f(0.07, 0.02);
            glVertex2f(0.07, -0.02);
            glVertex2f(0.05, -0.06);
            glVertex2f(-0.03, -0.06);
            glVertex2f(-0.05, -0.11);
            glVertex2f(-0.09, -0.12);
            glVertex2f(-0.14, -0.15);
            glVertex2f(-0.17, -0.14);
            glVertex2f(-0.19, -0.11);
            glVertex2f(-0.23, -0.11);
            glVertex2f(-0.23, -0.08);
            glVertex2f(-0.27, -0.06);
            glVertex2f(-0.27, -0.04);
            glVertex2f(-0.26, 0);
            glVertex2f(-0.29, 0);
            glVertex2f(-0.33, 0.03);
            glVertex2f(-0.31, 0.08);
            glVertex2f(-0.39, 0.09);
            glVertex2f(-0.37, 0.13);
            glVertex2f(-0.37, 0.17);
            glVertex2f(-0.33, 0.17);
            glVertex2f(-0.33, 0.21);
            glVertex2f(-0.31, 0.21);
            glVertex2f(-0.3, 0.22);
            glVertex2f(-0.25, 0.23);
            glVertex2f(-0.25, 0.25);
            glEnd();
            glPopMatrix();
}
//AB020
void E_smallMeteor1(){
    glPushMatrix();
    glTranslatef(SmallMeteorPosition,180,0);
    glScalef(10.0f,10.0f,0.0);
            glBegin(GL_POLYGON);
            glColor3ub(168,79,16);
            glVertex2f(0.41, 0.81);
            glVertex2f(0.48, 0.91);
            glVertex2f(0.56, 0.86);
            glVertex2f(0.6, 0.77);
            glVertex2f(0.58, 0.69);
            glVertex2f(0.59, 0.63);
            glVertex2f(0.54, 0.57);
            glVertex2f(0.47, 0.55);
            glVertex2f(0.42, 0.56);
            glVertex2f(0.39, 0.64);
            glVertex2f(0.34, 0.64);
            glVertex2f(0.29, 0.74);
            glVertex2f(0.36, 0.79);
            glEnd();
    glPopMatrix();
}
//AB021
void E_smallMeteor2(){
        glPushMatrix();
        glTranslatef(SmallMeteorPosition,180,0);
        glScalef(8.0f,18.0f,0.0);
          glBegin(GL_POLYGON);
            glColor3ub(120,120,120);
            glVertex2f(-0.3, 0.27);
            glVertex2f(-0.2, 0.29);
            glVertex2f(-0.11, 0.3);
            glVertex2f(-0.07, 0.27);
            glVertex2f(0.04, 0.29);
            glVertex2f(0.06, 0.31);
            glVertex2f(0.08, 0.31);
            glVertex2f(0.14, 0.29);
            glVertex2f(0.15, 0.29);
            glVertex2f(0.18, 0.3);
            glVertex2f(0.21, 0.32);
            glVertex2f(0.3, 0.28);
            glVertex2f(0.3, 0.23);
            glVertex2f(0.25, 0.18);
            glVertex2f(0.12, 0.19);
            glVertex2f(0.16, 0.14);
            glVertex2f(0.15, 0.11);
            glVertex2f(0.1, 0.11);
            glVertex2f(0.05, 0.15);
            glVertex2f(0.05, 0.14);
            glVertex2f(0.02, 0.12);
            glVertex2f(0, 0.1);
            glVertex2f(-0.07, 0.1);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.12, 0.07);
            glVertex2f(-0.14, 0.04);
            glVertex2f(-0.15, 0.04);
            glVertex2f(-0.17, 0.04);
            glVertex2f(-0.2, 0.05);
            glVertex2f(-0.22, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.25, 0.07);
            glVertex2f(-0.24, 0.05);
            glVertex2f(-0.25, 0.04);
            glVertex2f(-0.32, 0.04);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.31, 0.06);
            glVertex2f(-0.34, 0.1);
            glVertex2f(-0.36, 0.1);
            glVertex2f(-0.41, 0.12);
            glVertex2f(-0.41, 0.14);
            glVertex2f(-0.39, 0.17);
            glVertex2f(-0.41, 0.17);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.36, 0.22);
            glVertex2f(-0.37, 0.23);
            glVertex2f(-0.34, 0.28);
            glVertex2f(-0.34, 0.27);
            glVertex2f(-0.36, 0.3);
            glVertex2f(-0.31, 0.3);
            glVertex2f(-0.31, 0.29);
            glVertex2f(-0.22, 0.29);
            glEnd();
glPopMatrix();

}
//AB022
void E_smallMeteor3(){
        glPushMatrix();
        glTranslatef(SmallMeteorPosition,175,0);
        glScalef(6.0f,10.0f,0.0);
          glBegin(GL_POLYGON);
            glColor3ub(120,170,120);
            glVertex2f(-0.3, 0.27);
            glVertex2f(-0.2, 0.29);
            glVertex2f(-0.11, 0.3);
            glVertex2f(-0.07, 0.27);
            glVertex2f(0.04, 0.29);
            glVertex2f(0.06, 0.31);
            glVertex2f(0.08, 0.31);
            glVertex2f(0.14, 0.29);
            glVertex2f(0.15, 0.29);
            glVertex2f(0.18, 0.3);
            glVertex2f(0.21, 0.32);
            glVertex2f(0.3, 0.28);
            glVertex2f(0.3, 0.23);
            glVertex2f(0.25, 0.18);
            glVertex2f(0.12, 0.19);
            glVertex2f(0.16, 0.14);
            glVertex2f(0.15, 0.11);
            glVertex2f(0.1, 0.11);
            glVertex2f(0.05, 0.15);
            glVertex2f(0.05, 0.14);
            glVertex2f(0.02, 0.12);
            glVertex2f(0, 0.1);
            glVertex2f(-0.07, 0.1);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.09, 0.14);
            glVertex2f(-0.12, 0.07);
            glVertex2f(-0.14, 0.04);
            glVertex2f(-0.15, 0.04);
            glVertex2f(-0.17, 0.04);
            glVertex2f(-0.2, 0.05);
            glVertex2f(-0.22, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.23, 0.06);
            glVertex2f(-0.25, 0.07);
            glVertex2f(-0.24, 0.05);
            glVertex2f(-0.25, 0.04);
            glVertex2f(-0.32, 0.04);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.32, 0.05);
            glVertex2f(-0.31, 0.06);
            glVertex2f(-0.34, 0.1);
            glVertex2f(-0.36, 0.1);
            glVertex2f(-0.41, 0.12);
            glVertex2f(-0.41, 0.14);
            glVertex2f(-0.39, 0.17);
            glVertex2f(-0.41, 0.17);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.41, 0.24);
            glVertex2f(-0.36, 0.22);
            glVertex2f(-0.37, 0.23);
            glVertex2f(-0.34, 0.28);
            glVertex2f(-0.34, 0.27);
            glVertex2f(-0.36, 0.3);
            glVertex2f(-0.31, 0.3);
            glVertex2f(-0.31, 0.29);
            glVertex2f(-0.22, 0.29);
            glEnd();
        glPopMatrix();
}
//AB023
void E_Stars(){
glPushMatrix();
glRotatef(StarsAngle,0,0,1);
glScalef(1.5,1.5,0);
glPushMatrix();
glTranslatef(StarsPosition,125,0);
E_CirclePoints(30,20,0,0,6,255,255,255);
E_CirclePoints(20,10,0,0,6,255,255,255);
E_CirclePoints(10,5,0,0,5,255,255,255);
E_CirclePoints(5,5,0,0,5,255,255,255);
glPopMatrix();
glPushMatrix();
glTranslatef(StarsPosition+65,125,0);
E_CirclePoints(30,20,0,0,5,255,255,255);
E_CirclePoints(20,10,0,0,5,255,255,255);
E_CirclePoints(10,5,0,0,5,255,255,255);
E_CirclePoints(5,5,0,0,5,255,255,255);
E_CirclePoints(25,15,0,0,9,255,0,255);
E_CirclePoints(12,5,0,0,5,255,0,0);
E_CirclePoints(13,5,0,0,8,0,0,255);
E_CirclePoints(16,5,0,0,8,0,0,255);
glPopMatrix();
glPopMatrix();
}
void E_GradientEffect(){
    glBegin(GL_POLYGON);

    // Define gradient colors with alpha values
    glColor4ub(15, 15, 15, 80);
    glVertex2f(-50, -30);
    glColor4ub(20, 20, 20, 80);
    glVertex2f(-50, 150);
    glColor4ub(0, 0, 0, 80);
    glVertex2f(-50, 210);
    glColor4ub(0, 0, 0, 80);
    glVertex2f(50, 210);
    glColor4ub(20, 20, 20, 80);
    glVertex2f(50, 150);
    glColor4ub(195, 195, 195, 80);
    glVertex2f(50, -30);

    glEnd();
}
void E_ControlsInfo(){
glColor3ub(255,255,255);
E_DrawTextStroke(-30,15,0,0.015,5,"Press Mouse Left To Launch Rocket");
E_DrawTextStroke(-18,180,0,0.015,3,"Press W & S To Control Rocket");
E_DrawTextStroke(-015.5,175,0,0.015,3,"Press Q To Increase Speed");
}
void E_PrintFunction(){
    glPushMatrix();
    glTranslatef(0,BackgroundPosition,0);
    E_Sky();
    E_Cloud();
    E_sun();
    E_buildingtype1(5.0, -12.0, 20.0, 12.0, 0.9, 0.9, 0.9, 0.95);
    E_buildingtype1(-18.0, -12.0, 17.0, 12.0, 0.9, 0.9, 0.9, 0.90);
    E_buildingtype1(-12.0, -12.0, 18.0, 6.0, 0.9, 0.9, 0.9, 0.90);
    E_buildingtype1(0.0, -12.0, 15.0, 11.0, 0.9, 0.9, 0.9, 0.90);
    E_buildingtype1(-19.0, -12.0, 16.0, 16.0, 0.92, 0.92, 0.92, 0.95);
    E_buildingtype1(16.0, -12.0, 19.0, 6.0, 0.9, 0.9, 0.9, 0.95);
    E_buildingtype1(0.0, -12.0, 14.0, 6.0, 0.9, 0.9, 0.9, 0.95);
    E_buildingtype2(-25.0, -12.0, 14.0, 11.0, 0.55, 0.5, 0.5, 0.90);
    E_buildingtype2(12.0, -12.0, 13.0, 11.0, 0.55, 0.5, 0.5, 0.99);
    E_buildingtype1(-8.0, -12.0, 19.0, 16.0, 0.8, 0.8, 0.8, 1.0);
    E_buildingtype1(-18.0, -12.0, 13.0, 12.0, 0.3, 0.3, 0.3, 1.0);
    E_buildingtype1(-20.0, -12.0, 7.0, 6.0, 0.7, 0.7, 0.7, 1.0);
    E_buildingtype1(0.0, -12.0, 17.0, 11.0, 0.7, 0.7, 0.7, 1.0);
    E_buildingtype1(-10.0, -12.0, 12.0, 16.0, 0.72, 0.72, 0.72, 1.0);
    E_buildingtype1(20.0, -12.0, 18.0, 6.0, 0.7, 0.7, 0.7, 1.0);
    E_buildingtype1(0.0, -12.0, 18.0, 6.0, 0.5, 0.5, 0.5, 1.0);
    E_workshopBuilding(8.0, -12.0, 10.0, 20.0, 0.99, 0.99, 0.99, 1.0);
    E_buildingtype1(-06.0, -12.0, 8.0, 13.0, 0.7, 0.7, 0.7, 1.0);
    E_RocketHolder();
    E_Stars();
    glPopMatrix();
    E_shuttleCock();
    E_fuelTank();
    E_Rocket();
    glPushMatrix();
    glTranslatef(0,BackgroundPosition,0);
    E_bigMeteor1();
    E_bigMeteor2();
    E_bigMeteor3();
    E_bigMeteor4();
    E_smallMeteor1();
    E_smallMeteor2();
    E_smallMeteor3();
    glPopMatrix();
}
//AAB01
void E_BigMeteorMoveAnimation(int value){
   if(BigMeteorPosition > -195){BigMeteorPosition -= BigMeteorMoveSpeed;}
   else{BigMeteorPosition = 110;}
   glutPostRedisplay();
   glutTimerFunc(10,E_BigMeteorMoveAnimation,0);
}
//AAB02
void E_SmallMeteorMoveAnimation(int value){
   if(SmallMeteorPosition > -195){SmallMeteorPosition -= SmallMeteorMoveSpeed;}
   else{SmallMeteorPosition = 110;}
   glutPostRedisplay();
   glutTimerFunc(10,E_SmallMeteorMoveAnimation,0);

}
//AAB03
void E_StarsAnimation(int value){
    if(StarsPosition > -65){
    StarsPosition-=StarsMoveSpeed;
    StarsAngle = 0;
    }
    else
    {
      StarsPosition = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(10,E_StarsAnimation, 0);
}
//AAB04
void E_detachFuelTank(int value) {
    fuelTankDetached = true;
    }
//AAB05
void E_RocketInGalaxyAnimation(int value){
        FTSize = 1.2;
       SCSize = 1.2;

if(RocketAngle>-90)
    {
        RocketAngle -= RocketSpinSpeed;
    }
else
    {
        RocketAngle = -90;
    }

if(RocketAngle == -90)
    {
    if(RocketPosition > -20)
    {
        RocketPosition -= RocketMoveSpeed;
    }
    else {
            RocketPosition = -20;
         }
    if(RocketSize > 0.7)
    {
         RocketSize -= RocketSizeChanger;
         }
    else {
            RocketSize = 0.7;
         }
    }

    if(!(RocketPosition == -20)){
        glutPostRedisplay();
        glutTimerFunc(500,E_RocketInGalaxyAnimation, 0);
    }
    else{
        isProcessing = false;
        canRocketControl = true;
    }
    if(!(FTPosition == -20&&SCPosition == -20)){
        glutPostRedisplay();
        glutTimerFunc(500,E_RocketInGalaxyAnimation, 0);
    }else{
        isProcessing = false;
        glutTimerFunc(detachmentTime, E_detachFuelTank, 0);
    }

}
void E_BackgroundTowardGround(int);
//AAB06
void E_RocketInGround(int value){

    if(RocketPosition < 0)
        RocketPosition += RocketMoveSpeed;
    else
        RocketPosition = 0;
    if(RocketSize < 1)
        RocketSize += RocketSizeChanger;
    else
        RocketSize = 1;



    if(RocketPositionY < 0)
        RocketPositionY += RocketMoveSpeed;
    else if(RocketPositionY > 0)
        RocketPositionY -= RocketMoveSpeed;
    else
        RocketPositionY = 0;

    if((RocketPosition == 0)){
        BigMeteorMoveSpeed = 0.15;
        SmallMeteorMoveSpeed = 0.065;
        if(RocketAngle < 0)
            RocketAngle += RocketSpinSpeed;
        else
            RocketAngle = 0;
    }
    if(!(RocketAngle == 0)){
        glutPostRedisplay();
        glutTimerFunc(10,E_RocketInGround, 0);
    }
}
//AAB07
void E_BackgroundTowardGalaxy(int value){

    if(BackgroundPosition > FinalDestination){ BackgroundPosition -=BackgroundMoveSpeed;}
    else{BackgroundPosition = FinalDestination;}

    glutPostRedisplay();

    if(BackgroundPosition == FinalDestination){
        isRocketinGalaxy = true;
        glutTimerFunc(10,E_RocketInGalaxyAnimation,0);
    }
    if(!isRocketinGalaxy){
        glutTimerFunc(10, E_BackgroundTowardGalaxy, 0);
    }
}
void E_UpdateFunctions(){
 glutTimerFunc(10,E_BigMeteorMoveAnimation,0);
 glutTimerFunc(10,E_SmallMeteorMoveAnimation,0);
 glutTimerFunc(100,E_detachFuelTank,0);
 glutTimerFunc(3000, E_scale, 0);
 glutTimerFunc(10,E_StarsAnimation,0);

}
void E_mouse(int button,int state,int x,int y){
    switch(button)
    {
        if(!isProcessing)
        {
            case GLUT_LEFT_BUTTON:
            {
                if(state==GLUT_DOWN && !isProcessing && !isRocketinGalaxy){
                    isProcessing = true;        ///Start Process - Rocket toward Galaxy
                    FinalDestination = -180;
                    glutTimerFunc(10, E_BackgroundTowardGalaxy, 0);
                    rightMouseClicked = true;
                    IsFire = true;
                    glutTimerFunc(8000, E_timer1, 0);
                    glutTimerFunc(12000, E_timer2, 0);

                }
            } break;

            case GLUT_RIGHT_BUTTON:
            {
                if(state==GLUT_DOWN && !isProcessing && isRocketinGalaxy){
                    isProcessing = true;
                    canRocketControl = false;
                    FinalDestination = 0;
                    //glutTimerFunc(10,RocketInGround, 0);
                }
            } break;

            default:
                break;
        }
    }
}
void E_keyboard(unsigned char key, int x, int y){
    if(canRocketControl)
    {
        if(key=='w' || key=='W')
        {
            RocketPositionY+=RocketMoveSpeed*5;
            FTPositionY+=FTMoveSpeed*5;
            SCPositionY+=SCMoveSpeed*5;
        }
        if(key=='s' || key=='S')
        {
            RocketPositionY-=RocketMoveSpeed*5;
            FTPositionY-=FTMoveSpeed*5;
            SCPositionY-=SCMoveSpeed*5;
        }
        if(key=='q' || key=='Q'){
           BigMeteorMoveSpeed = 1;
           SmallMeteorMoveSpeed = 0.55;
           StarsMoveSpeed=0.5;
        }
        if(key=='a' || key=='A'){
           BigMeteorMoveSpeed = 0.085;
           SmallMeteorMoveSpeed = 0.35;
           StarsMoveSpeed=0.05;
        }
    }
}
void E_inttDefaultDisplay(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glPointSize(5.0f);
	glLineWidth(5.0f);
	glColor3ub(0, 0, 0);
    gluOrtho2D(-25.0, 25.0, -20.0, 20.0);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void E_display(){
    glClear(GL_COLOR_BUFFER_BIT);
    E_PrintFunction();
    glutSwapBuffers();
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);                 //Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);         // Color Mode
	glutInitWindowPosition(0,0);       // Window Position
    glutInitWindowSize(1920, 1080);          // Set the window's initial width & height
	glutCreateWindow("Rocket journey"); // Create a window with the given title
	glutDisplayFunc(E_display);              // Register display callback handler for window re-paint
    E_inttDefaultDisplay();          	           // Set "clearing" or background color
    E_UpdateFunctions();                         //Call Functions To Start Animation
    glutMouseFunc(E_mouse);                    //To Control with mouse
    glutKeyboardFunc(E_keyboard);               //To Control with keyboard
	glutMainLoop();                        // Enter the event-processing loop
	return 0;
}


