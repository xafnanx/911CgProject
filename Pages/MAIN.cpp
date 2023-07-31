#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.1416
int slide=0;
float xx=0;

static float c1 = 0.0; // Cloud 1
static float c2 = 0.0; // Cloud 2
static float c3 = 0.0; // Cloud 3
static float c4 = 0.0; // Cloud 4
float cloud_rad=5;

float explo_val = 0.0;

GLfloat a=0,a1=1500,b=0,c=0,d=0,e=0,cloud=0,z=0,y=0,w=0,u=0,q=0;

void update(int value)
{
	a+=10.0;
	a1-=10.0;	///Vertical Height of X axis (i)
	b-=10.0;	///Runway Movement
	c=150;	   ///take off angle on y axis
	cloud+=0.5;
	c1-=0.2;
	c2-=0.1;
	c3+=0.1;
	z+=1.0;
	y+=1.0;
	w+=0.0001;
	u-=10;
	if(c<=150){
		c+=10.0;
	}
	
	if(a>=800.0){
		//explo_val = 0.0;
		a=0.0;
	} 
	//if(a<800)
	//	a+=10.0
		if(b<=-80.0)
		b=0.0;
	if(z>=50){
		z=0;
		y=0;
	}
	if(a1<=850){
		a1=1500.0;
		//explo_val = 0.0;
	}
		
		
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
	//if(explo_val<50.0)
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

void Plane_Body(int x,int p)
{
	if(p==0){
		p=a;
	}
	else{
		p=a1;
	}
    ///--------BODY OF THE PLANE----------
    glPushMatrix();
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
    glColor3f(0.1,0.1,0.1);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
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
    glTranslated(p,c,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//rectangular body
        glVertex2f(x*120.0,45.0);
        glVertex2f(x*120.0,50.0);
        glVertex2f(x*130.0,50.0);
        glVertex2f(x*130.0,45.0);
    glEnd();
    glPopMatrix();
    
    
}
void smoke(){
	//main smoke
	glPushMatrix();
//	glTranslatef(310.0,150.0,0.0);
//	glColor3f(0.0881,0.0881,0.0881);
//	circle(60,80);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(240.0,110.0,0.0);
	glColor3f(0.0881,0.0881,0.0881);
	 glBegin(GL_POLYGON);//rectangular body
        glVertex2f(10.0,45.0);
        glVertex2f(10.0,180.0);
        glVertex2f(70.0,230.0);
        glVertex2f(130.0,180.0);
        glVertex2f(130.0,45.0);
    glEnd();
    glPopMatrix();
	//small smoke 0
	glPushMatrix();
	glTranslatef(290.0-z,200.0+y-50,0.0);
	glColor3f(0.1001,0.1001,0.1001);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0-(z*0.5),210.0+y-50,0.0);
	glColor3f(0.1001,0.1001,0.1001);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(310.0,220.0+y-50,0.0);
	glColor3f(0.1001,0.1001,0.1001);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(320.0+(z*0.5),210.0+y-50,0.0);
	glColor3f(0.1001,0.1001,0.1001);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(330.0+z,200.0+y-50,0.0);
	glColor3f(0.1001,0.1001,0.1001);
	circle(30,40);
	glPopMatrix();
	//small smoke 1
	glPushMatrix();
	glTranslatef(290.0-z,200.0+y,0.0);
	glColor3f(0.1221,0.1221,0.1221);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0-(z*0.5),210.0+y,0.0);
	glColor3f(0.1221,0.1221,0.1221);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(310.0,220.0+y,0.0);
	glColor3f(0.1221,0.1221,0.1221);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(320.0+(z*0.5),210.0+y,0.0);
	glColor3f(0.1221,0.1221,0.1221);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(330.0+z,200.0+y,0.0);
	glColor3f(0.1221,0.1221,0.1221);
	circle(30,40);
	glPopMatrix();
	//small smoke 2
	glPushMatrix();
	glTranslatef(290.0-z,250.0+y,0.0);
	glColor3f(0.1551,0.1551,0.1551);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0-(z*0.5),260.0+y,0.0);
	glColor3f(0.1551,0.1551,0.1551);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(310.0,270.0+y,0.0);
	glColor3f(0.1551,0.1551,0.1551);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(320.0+(z*0.5),260.0+y,0.0);
	glColor3f(0.1551,0.1551,0.1551);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(330.0+z,250.0+y,0.0);
	glColor3f(0.1551,0.1551,0.1551);
	circle(30,40);
	glPopMatrix();
	//small smoke 3
	glPushMatrix();
	glTranslatef(290.0-z,300.0+y,0.0);
	glColor3f(0.1881,0.1881,0.1881);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0-(z*0.5),310.0+y,0.0);
	glColor3f(0.1881,0.1881,0.1881);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(310.0,320.0+y,0.0);
	glColor3f(0.1881,0.1881,0.1881);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(320.0+(z*0.5),310.0+y,0.0);
	glColor3f(0.1881,0.1881,0.1881);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(330.0+z,300.0+y,0.0);
	glColor3f(0.1881,0.1881,0.1881);
	circle(30,40);
	glPopMatrix();
	//small smoke 4
	glPushMatrix();
	glTranslatef(290.0-z,300.0+y+50,0.0);
	glColor3f(0.2,0.2,0.2);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0-(z*0.5),310.0+y+50,0.0);
	glColor3f(0.2,0.2,0.2);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(310.0,320.0+y+50,0.0);
	glColor3f(0.2,0.2,0.2);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(320.0+(z*0.5),310.0+y+50,0.0);
	glColor3f(0.2,0.2,0.2);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(330.0+z,300.0+y+50,0.0);
	glColor3f(0.2,0.2,0.2);
	circle(30,40);
	glPopMatrix();
	//small smoke 5
	glPushMatrix();
	glTranslatef(290.0-z,300.0+y+100,0.0);
	glColor3f(0.2222,0.2222,0.2222);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(300.0-(z*0.5),310.0+y+100,0.0);
	glColor3f(0.2222,0.2222,0.2222);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(310.0,320.0+y+100,0.0);
	glColor3f(0.2222,0.2222,0.2222);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(320.0+(z*0.5),310.0+y+100,0.0);
	glColor3f(0.2222,0.2222,0.2222);
	circle(30,40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(330.0+z,300.0+y+100,0.0);
    glColor3f(0.2222,0.2222,0.2222);
	circle(30,40);
	glPopMatrix();
	
	
	
	
	
	
	
}


void *currentfont;
void setFont(void *font)
{
	currentfont=font;
}
void drawString(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,1);
 
	for(c=string;*c!='\0';c++)
	{	
		glutBitmapCharacter(currentfont,*c);
	}
}

void firstpage(void)
{
	glLineWidth(1.0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0,0.0,1.0);
	drawString(140.0,470.0,0.0,"MANGALORE INSTITUTE OF TECHNOLOGY & ENGINEERING");
	drawString(200,450,0.0,"MOODABIDRI, MANGALORE");
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawString(170,430.0,0.0,"DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0,0.0,0.0);
	drawString(168,370.0,0.0,"COMPUTER GRAPHICS AND VISUALIZATION");
	glColor3f(0.7, 0.0, 0.0);
	drawString(220,330,0.0,"MINI PROJECT ON");
	drawString(228,310,0.0,"9/11 TRAGEDY");
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,0.0,0.0);
	drawString(10,200,0.0,"MUHAMMED AFNAN HANIF");
	drawString(10,185,0.0,"4MT20CS104");
	drawString(420,200,0.0,"HENCY JOSTAN DSOUZA");
	drawString(457,185,0.0,"4MT20CS074");
	glColor3f(0.0,0.0,0.0);
	drawString(215,100,0.0,"UNDER THE GUIDANCE OF");
	glColor3f(1.0,0.0,0.0);
	drawString(235,80,0.0,"SUNITHA N V");
	drawString(215,65,0.0,"ASSISTANT PROFESSOR");
	drawString(234,50,0.0,"DEPT OF CSE");	
}

void thanku(){
	glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawString(220,260.0,0.0,"THANK YOU");
	
}

void runway()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);//black road
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,100.0);
        glVertex2f(500.0,100.0);
        glVertex2f(500.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);//white strips on road
        glVertex2f(0.0,40.0);
        glVertex2f(8.0,60.0);
        glVertex2f(58.0,60.0);
        glVertex2f(50.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(100.0,40.0);
        glVertex2f(108.0,60.0);
        glVertex2f(158.0,60.0);
        glVertex2f(150.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(200.0,40.0);
        glVertex2f(208.0,60.0);
        glVertex2f(258.0,60.0);
        glVertex2f(250.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(300.0,40.0);
        glVertex2f(308.0,60.0);
        glVertex2f(358.0,60.0);
        glVertex2f(350.0,40.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(b,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(400.0,40.0);
        glVertex2f(408.0,60.0);
        glVertex2f(458.0,60.0);
        glVertex2f(450.0,40.0);
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
void myinit()
{
    glClearColor(.0f,0.0f,0.0f,0.0f);
    
	glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
    
}

void scene1()
{
	myinit();
	glPushMatrix();
	glTranslatef(-100.0,-100.0,0.0);
	background();
	glPopMatrix();
   //Plane_Body();

 	glPushMatrix();
	firstpage();
	glPopMatrix();
	
   
   	glFlush(); 
	glutSwapBuffers();
}
 
void scene2()
{
  //glMatrixMode(GL_PROJECTION);
	
	myinit();
	background();
	glPushMatrix();
		glScalef(2.5,2.5,1.0);
		glTranslatef(50.0+cloud,100.0,0.0);
		clouds();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.5,0.5,0.5);
		Plane_Body(1,0);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void scene3()
{
	//myinit();
		
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
	Plane_Body(1,0);
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

void scene4()
{
	//myinit();
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
	smoke();
	glPopMatrix();
	//glPushMatrix();

	//	glScalef(0.5,0.5,0.5);
	//	glTranslatef(0.0,300.0,0.0);
	//	Plane_Body(-1);
	//glPopMatrix();
	
	/*glPushMatrix();
	if(a>400){
		glColor3f(0.9411,0.4980,0.0745);
		explosion(20.0,1.8);
	}	
	glPopMatrix();
	
	glPushMatrix();
	if(a>400){
		glColor3f(0.9921,0.8117,0.3450);
		explosion(15.0,1.0);
	}	
	glPopMatrix();*/
	
	//right building
	glPushMatrix();
	building();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.5,0.5,0.5);
		glTranslatef(0.0,350.0,0.0);
		Plane_Body(-1,1);
	glPopMatrix();
	
	//second tower explosion
	glPushMatrix();
		glTranslatef(150.0,120.0,0.0);
		glPushMatrix();
		if(a1<1020){
			glColor3f(0.9411,0.4980,0.0745);
			explosion(10.0,1.8);
		}	
		glPopMatrix();
		
		glPushMatrix();
		if(a1<1020){
			glColor3f(0.9921,0.8117,0.3450);
			explosion(10.0,1.0);
		}	
		glPopMatrix();
	glPopMatrix();


	glutSwapBuffers();
}

void scene5()
{
	//myinit();
	glClear(GL_COLOR_BUFFER_BIT);
	
	

	background();
	
	//clouds
	glPushMatrix();
	glScalef(2.5,2.5,1.0);
	glTranslatef(50.0+cloud,100.0,0.0);
	clouds();
	glPopMatrix();
	//falling building
	glPushMatrix();
	glTranslatef(0,u,0);
	//left building
	glPushMatrix();
	glTranslatef(-110.0,-60.0,0.0);
	building();
	glPopMatrix();

		glPushMatrix();
	smoke();
	glPopMatrix();
    //right building 
	glPushMatrix();
	building();
	glPopMatrix();
	
	
	glPushMatrix();
		glTranslatef(110.0,58.0,0);
		smoke();
	glPopMatrix();
	glPopMatrix();
	
	
	


	glutSwapBuffers();
}

void scene6()
{
	glPushMatrix();
	glTranslatef(-100.0,-100.0,0.0);
	background();
	glPopMatrix();

	glPushMatrix();
	thanku();
	glPopMatrix();
	
	glutSwapBuffers();
}

void key(unsigned char key,int x,int y)
{

	if(key=='1'){
		slide=0;
	}
	else if(key=='2'){
		a=0,a1=1500,b=0,c=0,d=0,e=0,cloud=0,z=0,y=0,w=0,u=0,q=0;
		slide=1;
	}
	else if(key=='3'){
		explo_val = 0.0;
		a=0,a1=1500,b=0,c=0,d=0,e=0,cloud=0,z=0,y=0,w=0,u=0,q=0;
		slide=2;
	}	
	else if(key=='4'){
		explo_val = 0.0;
		a=0,a1=1500,b=0,c=0,d=0,e=0,cloud=0,z=0,y=0,w=0,u=0,q=0;
		slide=3;
	}
	else if(key=='5'){
		a=0,a1=1500,b=0,c=0,d=0,e=0,cloud=0,z=0,y=0,w=0,u=0,q=0;
		slide=4;
	}
	else if(key=='6')
		slide=5;
}


void display(){
	if(slide==0)
	{
		scene1();
	}
	else if(slide==1)
	{
		scene2();
	}
	else if(slide==2)
	{
		scene3();
	}
	else if(slide==3)
	{
		scene4();
	}
	else if(slide==4)
	{
		scene5();
	}
	else if(slide==5)
	{
		scene6();
	}

}




int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400.0,680.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Takeoff of an Airplane");
    glutFullScreen();
    glutDisplayFunc(display);
    //myinit();
    //glutTimerFunc(100,update,0);
    update(0);
    explosion_timer(0);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
