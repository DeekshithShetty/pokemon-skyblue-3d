#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

extern GLfloat cAngle[];
extern GLfloat cPos[];
extern GLfloat cAim[]; 
extern GLfloat cUp[] ;
extern int window1;
extern int screen;
extern GLfloat rquad;
//extern GLuint texture[7];
void display();
extern float x ,z,y ; // initially 5 units south of origin
extern float deltaMove; // initially camera doesn't move

// Camera direction
extern float lx, lz,ly; // camera points initially along y-axis
extern float angle; // angle of rotation for the camera direction
extern float deltaAngle; // additional angle change when dragging

// Mouse drag control
extern int isDragging; // true when dragging
extern int xDragStart ; // records the x-coordinate when dragging starts

//#include "MainPage.cpp"

#endif


