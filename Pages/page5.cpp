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

float explo_val = 0.0;

GLfloat a=0,b=0,c=0,d=0,e=0,cloud=0;

void update(int value)
{
	a+=10.0;	///Vertical Height of X axis (i)
	b-=10.0;	///Runway Movement
	c=150;	   ///take off angle on y axis
	cloud+=0.5;
	c1-=0.2;
	c2-=0.1;
	c3+=0.1;
	if(a>=800.0){
		explo_val = 0.0;
		a=0.0;
	} 
	//if(a<800)
	//	a+=10.0;
		
	if(cloud>=160.0)
		cloud=0.0;
		
	glutPostRedisplay();
	glutTimerFunc(200,update,0);//delay
}

void explosion_timer(int value)
{
	//if(a<=400&&a>=600)
	//if(a>=799.0)
		//explo_val = 0.0;
	if(explo_val<50.0)
		explo_val+=0.7;
	glutPostRedisplay();
	glutTimerFunc(200,explosion_timer,0);//delay
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

void Plane_Body(int x)
{
	
    ///--------BODY OF THE PLANE----------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.750,0.750,0.750);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*15.0,30.0);
        glVertex2f(x*0.0,55.0);
        glVertex2f(x*135.0,55.0);
        glVertex2f(x*135.0,30.0);
    glEnd();
    glPopMatrix();
    ///--------COCKPIT OF THE PLANE----------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//upper triangle construction plane
        glVertex2f(x*135.0,55.0);
        glVertex2f(x*150.0,50.0);
        glVertex2f(x*155.0,45.0);
        glVertex2f(x*160.0,40.0);
        glVertex2f(x*135.0,40.0);
    glEnd();
    glPopMatrix();
    ///--------COCKPIT OUTLINE DIVIDER----------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x*135.0,55.0);
        glVertex2f(x*150.0,50.0);
        glVertex2f(x*155.0,45.0);
        glVertex2f(x*160.0,40.0);
        glVertex2f(x*135.0,40.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.750,0.750,0.750);
    glBegin(GL_POLYGON);//lower triangle
        glVertex2f(x*135.0,40.0);
        glVertex2f(x*160.0,40.0);
        glVertex2f(x*160.0,37.0);
        glVertex2f(x*145.0,30.0);
        glVertex2f(x*135.0,30.0);
    glEnd();
    glPopMatrix();

    ///---------TAIL-------------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(.33,.46,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(x*0.0,55.0);
        glVertex2f(x*0.0,80.0);
        glVertex2f(x*10.0,80.0);
        glVertex2f(x*40.0,55.0);
    glEnd();
    glPopMatrix();

    ///---------LEFT WING-------------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(x*65.0,55.0);
        glVertex2f(x*50.0,70.0);
        glVertex2f(x*75.0,70.0);
        glVertex2f(x*90.0,55.0);
    glEnd();
    glPopMatrix();
    ///---------RIGHT WING-------------
    glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(x*70.0,40.0);
        glVertex2f(x*100.0,40.0);
        glVertex2f(x*80.0,15.0);
        glVertex2f(x*50.0,15.0);
    glEnd();

    glPopMatrix();
    	///-----------------WINDOW1---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*20.0,45.0);
        glVertex2f(x*20.0,50.0);
        glVertex2f(x*30.0,50.0);
        glVertex2f(x*30.0,45.0);
    glEnd();
    glPopMatrix();
    
      	///-----------------WINDOW2---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*40.0,45.0);
        glVertex2f(x*40.0,50.0);
        glVertex2f(x*50.0,50.0);
        glVertex2f(x*50.0,45.0);
    glEnd();
    glPopMatrix();
      	///-----------------WINDOW3---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*60.0,45.0);
        glVertex2f(x*60.0,50.0);
        glVertex2f(x*70.0,50.0);
        glVertex2f(x*70.0,45.0);
    glEnd();
    glPopMatrix();
      	///-----------------WINDOW4---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*80.0,45.0);
        glVertex2f(x*80.0,50.0);
        glVertex2f(x*90.0,50.0);
        glVertex2f(x*90.0,45.0);
    glEnd();
    glPopMatrix(); 
      	///-----------------WINDOW5---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*100.0,45.0);
        glVertex2f(x*100.0,50.0);
        glVertex2f(x*110.0,50.0);
        glVertex2f(x*110.0,45.0);
    glEnd();
    glPopMatrix();
      	///-----------------WINDOW6---------
	 glPushMatrix();
    glTranslated(a,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*120.0,45.0);
        glVertex2f(x*120.0,50.0);
        glVertex2f(x*130.0,50.0);
        glVertex2f(x*130.0,45.0);
    glEnd();
    glPopMatrix();
    
    
}

void building()
{
	float i=0;
	
	glColor3f(0.700,0.700,0.700);
	glBegin(GL_POLYGON);
      	glVertex2f(360.0,0.0);
        glVertex2f(360.0,350.0);
        glVertex2f(420.0,400.0);
        glVertex2f(420.0,0.0);
    glEnd();
    
    //window lines
    //horizontal
    for(i=0;i<400;i+=5){
    	glColor3d(0.5411,0.5411,0.5411);
    	glPushMatrix();
    	glTranslatef(0.0,-50.0,0.0);
    	glBegin(GL_LINES);
    		glVertex2f(360.0,0.0+i);
    		glVertex2f(420.0,50.0+i);
    	glEnd();
    	glPopMatrix();
    }
    //verticle
    for(i=0;i<60;i+=5){
    	glColor3d(0.5411,0.5411,0.5411);
    	glPushMatrix();
    	glTranslatef(0.0,0.0,0.0);
    	glBegin(GL_LINES);
    		glVertex2f(360.0+i,0.0);
    		glVertex2f(360.0+i,350.0+(i*0.85));
    	glEnd();
    	glPopMatrix();
    }
    
    glColor3f(0.550,0.550,0.550);
	glBegin(GL_POLYGON);
        glVertex2f(420.0,0.0);
        glVertex2f(420.0,400.0);
        glVertex2f(480.0,350.0);
        glVertex2f(480.0,0.0);
    glEnd();
    
    //window lines
    //horizontal
    for(i=0;i<400;i+=5){
    	glColor3d(0.3921,0.3921,0.3921);
    	glPushMatrix();
    	glTranslatef(0.0,-50.0,0.0);
    	glBegin(GL_LINES);
    		glVertex2f(420.0,50.0+i);
    		glVertex2f(480.0,0.0+i);
    	glEnd();
    	glPopMatrix();
    }
    //verticle
    for(i=0;i<60;i+=5){
    	
    	glPushMatrix();
    	glColor3d(0.3921,0.3921,0.3921);
    	glTranslatef(0.0,0.0,0.0);
    	glBegin(GL_LINES);
    		glVertex2f(420.0+i,0.0);
    		glVertex2f(420.0+i,400.0-(i*0.85));
    	glEnd();
    	glPopMatrix();
    }
    
    glColor3d(0.3098,0.3098,0.3098);
	glBegin(GL_POLYGON);
      	glVertex2f(360.0,330.0);
        glVertex2f(360.0,350.0);
        glVertex2f(420.0,400.0);
        glVertex2f(420.0,380.0);
    glEnd();
    
    //top part
    glBegin(GL_POLYGON);
        glVertex2f(420.0,380.0);
        glVertex2f(420.0,400.0);
        glVertex2f(480.0,350.0);
        glVertex2f(480.0,330.0);
    glEnd();
    
    //white lines
    glColor3f(1.0,1.0,1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    	glVertex2f(360.0,0.0);
        glVertex2f(360.0,350.0);
        glVertex2f(360.0,350.0);
        glVertex2f(420.0,400.0);
        glVertex2f(420.0,400.0);
        glVertex2f(420.0,0.0);
        glVertex2f(360.0,330.0);
        glVertex2f(420.0,380.0);
        glVertex2f(480.0,0.0);
        glVertex2f(480.0,350.0);
        glVertex2f(420.0,380.0);
    	glVertex2f(480.0,330.0);
    	glVertex2f(480.0,350.0);
        glVertex2f(420.0,400.0);
    glEnd();
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

void explosion(int size,float val){
	
	glPushMatrix();
	
	glTranslatef(280.0,150.0,0.0);
	circle(size+(explo_val)*val,size*2+(explo_val)*val);
	glPopMatrix();
}

void circle2(int r,int x,int y,float h)//r is radius, xy is center and h is a factor that makes it into an ellipse
{
    float theta;
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
       theta=i*3.142/180;
       glVertex2f(x+r*cos(theta)/h,y+r*sin(theta));
     }
     glEnd();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	
	background();
	
	//clouds
	glPushMatrix();
	glScalef(2.5,2.5,1.0);
	glTranslatef(50.0+cloud,100.0,0.0);
	clouds();
	glPopMatrix();
	
	//left building
	glPushMatrix();
	glTranslatef(-110.0,-60.0,0.0);
	building();
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
	glTranslatef(0.0,100.0,0.0);
	Plane_Body(1);
	glPopMatrix();
	
	//glPushMatrix();

	//	glScalef(0.5,0.5,0.5);
	//	glTranslatef(0.0,300.0,0.0);
	//	Plane_Body(-1);
	//glPopMatrix();
	
	glPushMatrix();
	if(a>400){
		glColor3f(0.9411,0.4980,0.0745);
		explosion(10.0,1.8);
	}	
	glPopMatrix();
	
	glPushMatrix();
	if(a>400){
		glColor3f(0.9921,0.8117,0.3450);
		explosion(10.0,1.0);
	}	
	
	
	glPopMatrix();
	
	//right building
	glPushMatrix();
	building();
	glPopMatrix();
	
	glutSwapBuffers();
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
    //glutFullScreen();
    glutDisplayFunc(display);
    myinit();
    //glutTimerFunc(100,update,0);
    update(0);
    explosion_timer(0);
    glutMainLoop();
    return 0;
}
