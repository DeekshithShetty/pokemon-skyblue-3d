#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
#include"screen.h"
#include"common.h"

void CommonFunctions::init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(0,SCREEN_W ,0, SCREEN_H,-1,1);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_TEXTURE_2D);							
	glShadeModel(GL_SMOOTH);												
	glEnable(GL_DEPTH_TEST);							
	glDepthFunc(GL_LEQUAL);								
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	glLoadIdentity();
}

void CommonFunctions::drawString(void *font,char * s,float x,float y)
{
	unsigned int i;
	glRasterPos2f(x,y);
	glPixelZoom(10.0,10.0);
	for(i=0;i<strlen(s);i++)
		glutBitmapCharacter(font,s[i]);
}

void CommonFunctions::drawRectf(float x1, float y1, float height, float width){
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x1,y1+height);
	glVertex2f(x1+width,y1+height);
	glVertex2f(x1+width,y1);
	glEnd();
}

void CommonFunctions::drawRectfilled(float x1, float y1, float height, float width){
			glBegin(GL_POLYGON);
			glVertex2f(x1,y1);
			glVertex2f(x1,y1+height);
			glVertex2f(x1+width,y1+height);
			glVertex2f(x1+width,y1);
			glEnd();
}


