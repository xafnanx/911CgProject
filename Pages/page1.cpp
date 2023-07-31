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
   //Plane_Body();

   // Add text to the center of the window
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.5f, 0.9f);  // Set the text position
   char *text = "MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING"; // Define the text string
   int len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   glColor3f(1.0, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.23, 0.8f);  // Set the text position
   text = "MOODBIDRI, MANGALORE"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.27f, 0.7f);  // Set the text position
   text = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.38f, 0.2f);  // Set the text position
   text = "COMPUTER GRAPHICS AND VISUALIZATION"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.15f, 0.1f);  // Set the text position
   text = "MINI PROJECT ON"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.1f, 0.0f);  // Set the text position
   text = "9/11 Tragedy"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.96f, -0.5f);  // Set the text position
   text = "MUHAMMED AFNAN HANIF"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.96f, -0.56f);  // Set the text position
   text = "4MT20CS104"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(0.535f, -0.5f);  // Set the text position
   text = "HENCY JOSTAN DSOUZA"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(0.81f, -0.56f);  // Set the text position
   text = "4MT20CS074"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.13f, -0.88f);  // Set the text position
   text = "UNDER THE GUIDANCE OF"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]); // Draw each character of the text
   }
   
   glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
   glRasterPos2f(-0.08f, -0.96f);  // Set the text position
   text = "Ms. Sunitha"; // Define the text string
   len = strlen(text);      // Get the length of the text string
   for (int i = 0; i < len; i++)
   {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]); 
   }
   
   glutSwapBuffers(); 
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv); // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
   glutInitWindowSize(1400.0,680.0);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("OpenGL Mini Project");
   glutDisplayFunc(display);  
            
   glutMainLoop();     

   return 0;
}
