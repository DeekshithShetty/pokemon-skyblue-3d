#include <stdio.h>
#include <GL/glut.h>
#include <string.h>
#include "screen.h"
#include "common.h"
#include "headers.h"
#include "mainPage.h"

GLuint textureAbout[1];

void About::init(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	ImageLoader image;
	image.aboutScreenImageLoad(textureAbout);
	glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Clear The Background Color To Blue 
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing					
	glDepthFunc(GL_LEQUAL);		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix
	perspectiveGL(60.0f,(GLfloat)Width/(GLfloat)Height,1.0f,100.0f);	// Calculate The Aspect Ratio Of The Window
	glMatrixMode(GL_MODELVIEW);
}

void About::perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar ){
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;
	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;
	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

void About::changeSize(int w, int h) {
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	perspectiveGL(45.0, ratio, 0.1, 100.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}


void About::screen12()
{
	CommonFunctions c;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureAbout[0]);   // choose the texture to use.
	glPushMatrix();           
	  	glBegin(GL_QUADS);                  // Draw A Quad
	  		glTexCoord2f(0.0f, 0.0f);
		    glVertex3f(50,40,0); 

		    glTexCoord2f(0.0f, 1.0f);       
		    glVertex3f(50,HEIGHT-20,0);

		    glTexCoord2f(1.0f, 1.0f);          
		    glVertex3f(WIDTH-60,HEIGHT-20,0);

		    glTexCoord2f(1.0f, 0.0f);          
		    glVertex3f(WIDTH-60,40,0);          
	  	glEnd();                      // Done Drawing The Quad
  	glPopMatrix();
  	glDisable(GL_TEXTURE_2D);

	glColor3f(0.9,0.0,0.1);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	c.drawString(GLUT_BITMAP_TIMES_ROMAN_24,"INSTRUCTIONS",WIDTH-700,HEIGHT-100);
	glColor3f(0.9,0.9,0.9);
	
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Hold Arrow keys to move",280,HEIGHT-140);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Press 'z' to change camera to front view",280,HEIGHT-180);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Press 'x' to change camera back to third person view",280,HEIGHT-220);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Go on pressing 'v' to change view type",280,HEIGHT-260);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Press 'ENTER' to enter battle",280,HEIGHT-300);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Attacks Keys:",280,HEIGHT-360);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"* Pikachu         :  'z'  -  Thunderbolt    'x' - Lightball",WIDTH-1000,HEIGHT-400);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"* Oddish          :  'm' -  RazorLeaf",WIDTH-1000,HEIGHT-440);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"* Marill            :   'a'  -  Bubble            's' - Icebeam",WIDTH-1000,HEIGHT-480);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"* Charmander  :  'l'   -   Ember",WIDTH-1000,HEIGHT-520);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"- Press 'q' or 'ESC' to quit",280,HEIGHT-560);

	glColor3f(0.9,0.0,0.1);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"*** LEGAL: This product is not affiliated with or licensed by Nintendo Corporation ***",380,HEIGHT-610);
	
	glColor3f(0.9,0.0,0.1);
	c.drawRectf(20.0, 20.0, (HEIGHT-20), (WIDTH-20));
	glColor3f(0.9,0.9,0.9);
	c.drawRectf(30.0, 30.0, (HEIGHT-40), (WIDTH-40));
	glColor3f(0.6,0.0,0.0);
	c.drawRectfilled(200,70,40,150);
	glColor3f(0.8,0.8,0.8);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"EXIT",235,83);
	glColor3f(0.6,0.0,0.0);
	c.drawRectfilled(1000,70,40,150);
	glColor3f(0.8,0.8,0.8);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"BACK",1050,83);
	glColor3f(1.0,0.0,0.0);
	glColor3f(0.6,0.0,0.0);
	c.drawRectfilled(600,70,40,150);
	glColor3f(0.8,0.8,0.8);
	c.drawString(GLUT_BITMAP_HELVETICA_18,"ENTER",650,83);
	//glFlush();
	glutSwapBuffers();
}


void About::keyPressed(unsigned char key, int x, int y){
	if (key == ESC || key == 'q' || key == 'Q') {
		system("killall -9 mplayer");
		exit(0);
	}	
	if (key == 'b'){
		screen = 1;
		display();
	}
	if (key == 13){
		screen = 3;
		display();
	}
}

void About::mouse(int btn, int state, int x, int y){
	int yy,xx;
	int a0x0=200,a0x1=350, a0y0=70,a0y1=110;//exit
	int bx0=600,bx1=750, by0=70,by1=110;//enter
	int cx0=1000,cx1=1150, cy0=70,cy1=110;//back
	yy = glutGet(GLUT_WINDOW_HEIGHT);
	y = yy - y;
	if (state == GLUT_DOWN)
	{
		if (btn==GLUT_LEFT_BUTTON)
		{
			//printf("DOWN: x=%3d  y=%3d \n", x, y);
			if(x>=a0x0 && x<=a0x1 && y>=a0y0 && y<=a0y1)
			{
				exit(0);
			}
			if(x>=bx0 && x<=bx1 && y>=by0 && y<=by1)
			{
				screen = 3;
				display();
			}
			else if(x>=cx0 && x<cx1 && y>=cy0 && y<=cy1)
			{
				screen = 1;
				display();
			}
		}
	}
}


/* ------------------------------------------------------------------------------------------------------------------ */





