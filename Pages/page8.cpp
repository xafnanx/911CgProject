#include <GL/glut.h>
#include<math.h>
#include <string.h>

void background(){ 
	glBegin(GL_POLYGON);
		glColor3f(0.6980,0.8588,0.9137);
		//glColor3f(0.0,0.0,0.0);
		glVertex2f(0.0,0.0);
		glVertex2f(1400.0,0.0);
		glColor3f(0.0,0.4431,0.7098);
		glVertex2f(1400.0,680.0);
		glVertex2f(0.0,680.0);
	glEnd();
}


void display()
{
	glPushMatrix();
	glTranslatef(-100.0,-100.0,0.0);
	background();
	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
	glRasterPos2f(-0.1, 0.0);  // Set the text position
	char *text = "THANK YOU"; // Define the text string
	int len = strlen(text);      // Get the length of the text string
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
	}
   
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

int main(int argc, char **argv)
{
   glutInit(&argc, argv); // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(1400.0,680.0);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("OpenGL Mini Project");
   //timer(0);
   //myinit();
   glutDisplayFunc(display);  
            
   glutMainLoop();     

   return 0;
}
