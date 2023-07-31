#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.1416
static float c1 = 0.0; // Cloud 1
static float c2 = 0.0; // Cloud 2
static float c3 = 0.0; // Cloud 3
static float c4 = 0.0; // Cloud 4
float cloud_rad=5;

GLfloat a=0,b=0,c=0,d=0,e=0,cloud=0;

void runway();
void update(int value)
{
	a+=15.0;	///Vertical Height of X axis (i)
	b-=10.0;	///Runway Movement
	c=150;	   ///take off angle on y axis
	if(a>=900.0)
		a=0.0;
	cloud+=0.5;
	if(cloud>=160.0)
		cloud=0.0;

	if(b<=-80.0)
		b=0.0;
	glutPostRedisplay();
	glutTimerFunc(200,update,0);//delay
}

void circle(float radiusX,float radiusY){
    int i;
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(i=0;i<100;i++){
            angle= 2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));

        }
    glEnd();
}

void clouds(){
	    //Cloud - 1
    glPushMatrix();
    glTranslatef(80+c1,80,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80+c1,75,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75+c1,75,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(85+c1,80,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    //Cloud - 2
    glPushMatrix();
    glTranslatef(40+c2,90,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40+c2,85,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35+c2,90,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(45+c2,84,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    //Cloud - 3
    glPushMatrix();
    glTranslatef(0+c3,70,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+c3,65,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5+c3,70,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5+c3,70,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+c3,73,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    //Cloud - 4
    glPushMatrix();
    glTranslatef(-40+c4,85,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40+c4,80,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45+c4,82,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35+c4,84,0);
    glColor3f(1,1,1);
    circle(cloud_rad, cloud_rad);
    glPopMatrix();
}



void Plane_Body(void)
{
    



    ///--------BODY OF THE PLANE----------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.750,0.750,0.750);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(15.0,30.0);
        glVertex2f(0.0,55.0);
        glVertex2f(135.0,55.0);
        glVertex2f(135.0,30.0);
    glEnd();
    glPopMatrix();
    ///--------COCKPIT OF THE PLANE----------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
    glEnd();
    glPopMatrix();
    ///--------COCKPIT OUTLINE DIVIDER----------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(135.0,55.0);
        glVertex2f(150.0,50.0);
        glVertex2f(155.0,45.0);
        glVertex2f(160.0,40.0);
        glVertex2f(135.0,40.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.750,0.750,0.750);
    glBegin(GL_POLYGON);//lower triangle
        glVertex2f(135.0,40.0);
        glVertex2f(160.0,40.0);
        glVertex2f(160.0,37.0);
        glVertex2f(145.0,30.0);
        glVertex2f(135.0,30.0);
    glEnd();
    glPopMatrix();

    ///---------TAIL-------------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(.33,.46,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0.0,55.0);
        glVertex2f(0.0,80.0);
        glVertex2f(10.0,80.0);
        glVertex2f(40.0,55.0);
    glEnd();
    glPopMatrix();

    ///---------LEFT WING-------------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(65.0,55.0);
        glVertex2f(50.0,70.0);
        glVertex2f(75.0,70.0);
        glVertex2f(90.0,55.0);
    glEnd();
    glPopMatrix();
    ///---------RIGHT WING-------------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(70.0,40.0);
        glVertex2f(100.0,40.0);
        glVertex2f(80.0,15.0);
        glVertex2f(50.0,15.0);
    glEnd();

    glPopMatrix();
    	///-----------------WINDOW1---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(20.0,45.0);
        glVertex2f(20.0,50.0);
        glVertex2f(30.0,50.0);
        glVertex2f(30.0,45.0);
    glEnd();
    glPopMatrix();
    
      	///-----------------WINDOW2---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(40.0,45.0);
        glVertex2f(40.0,50.0);
        glVertex2f(50.0,50.0);
        glVertex2f(50.0,45.0);
    glEnd();
    glPopMatrix();
      	///-----------------WINDOW3---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(60.0,45.0);
        glVertex2f(60.0,50.0);
        glVertex2f(70.0,50.0);
        glVertex2f(70.0,45.0);
    glEnd();
    glPopMatrix();
      	///-----------------WINDOW4---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(80.0,45.0);
        glVertex2f(80.0,50.0);
        glVertex2f(90.0,50.0);
        glVertex2f(90.0,45.0);
    glEnd();
    glPopMatrix(); 
      	///-----------------WINDOW5---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(100.0,45.0);
        glVertex2f(100.0,50.0);
        glVertex2f(110.0,50.0);
        glVertex2f(110.0,45.0);
    glEnd();
    glPopMatrix();
      	///-----------------WINDOW6---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(120.0,45.0);
        glVertex2f(120.0,50.0);
        glVertex2f(130.0,50.0);
        glVertex2f(130.0,45.0);
    glEnd();
    glPopMatrix();
    
    
    
    
    
    
    glFlush();
    glutSwapBuffers();
}

void background(){ 
	glBegin(GL_POLYGON);
		glColor3f(0.6980,0.8588,0.9137);
		glVertex2f(0.0,0.0);
		glVertex2f(1400.0,0.0);
		glColor3f(0.0,0.4431,0.7098);
		glVertex2f(1400.0,680.0);
		glVertex2f(0.0,680.0);
	glEnd();
}


void display(){
	background();
	glPushMatrix();
		glScalef(2.5,2.5,1.0);
		glTranslatef(50.0+cloud,100.0,0.0);
		clouds();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
		Plane_Body();
	glPopMatrix();
}






void myinit()
{
    glClearColor(0.0f,1.0f,1.0f,0.0f);
    glColor3f(1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400.0,680.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Takeoff of an Airplane");
    glutDisplayFunc(display);
    myinit();
    glutTimerFunc(100,update,0);
    glutMainLoop();
    return 0;
}
