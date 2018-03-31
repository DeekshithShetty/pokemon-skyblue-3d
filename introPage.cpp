#include <stdio.h>
#include <GL/glut.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#include "headers.h"
#include "screen.h"
#include "common.h"
#include "introPage.h"
#include "mainPage.h"
#include "imageLoader.h" 

GLuint textureIntro[1];


void IntroWindow::init(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	system("mplayer -loop 0 Sound/title.mp3 >> /dev/null &");
	ImageLoader image;
	image.startScreenImageLoad(textureIntro);
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

void IntroWindow::perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar ){
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;
	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;
	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

void IntroWindow::changeSize(int w, int h) {
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	perspectiveGL(45.0, ratio, 0.1, 100.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}

void IntroWindow::main_screen(){
	CommonFunctions c;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

  	glColor3f(1.0,1.0,1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureIntro[0]);   // choose the texture to use.
	glPushMatrix();           
	  	glBegin(GL_QUADS);                  // Draw A Quad
	  		glTexCoord2f(0.0f, 0.0f);
		    glVertex3f(20,20,0); 

		    glTexCoord2f(0.0f, 1.0f);       
		    glVertex3f(20,HEIGHT,0);

		    glTexCoord2f(1.0f, 1.0f);          
		    glVertex3f(WIDTH,HEIGHT,0);

		    glTexCoord2f(1.0f, 0.0f);          
		    glVertex3f(WIDTH,20,0);          
	  	glEnd();                      // Done Drawing The Quad
  	glPopMatrix();
  	glDisable(GL_TEXTURE_2D);

	glutSwapBuffers();
}



void IntroWindow::keyPressed(unsigned char key, int x, int y){
	if (key == ESC || key == 'q' || key == 'Q') {
		system("killall -9 mplayer");
		exit(0);
	}	
	if (key == 13){
		screen = 2;
		display();
	}
}

void IntroWindow::mouse(int btn, int state, int x, int y){
	int yy,xx;
	int a0x0=400,a0x1=550, a0y0=70,a0y1=110;//exit
	int cx0=800,cx1=950, cy0=70,cy1=110;//continue
	/*
	int a0x0=800,a0x1=950, a0y0=70,a0y1=110;//continue
	int cx0=1000,cx1=1150, cy0=70,cy1=110;//exit
	*/
	yy = glutGet(GLUT_WINDOW_HEIGHT);
	y = yy - y;
	if (state == GLUT_DOWN)
	{
		if (btn==GLUT_LEFT_BUTTON)
		{
			//printf("DOWN: x=%3d  y=%3d \n", x, y);
			if(x>=a0x0 && x<=a0x1 && y>=a0y0 && y<=a0y1 )
			{
				exit(0);
			}
			else if(x>=cx0 && x<cx1 && y>=cy0 && y<=cy1)
			{
				screen = 2;
				display();
			}
		}
	}
}

