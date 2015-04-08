#ifndef _HEADERS_H_
#define _HEADERS_H_


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h> // standard definitions
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>

// escape key (for exit)
#define ESC 27

/*
Define of humanoid body properties 
*/
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 1.5
#define UPPER_ARM_HEIGHT 2.5
#define LOWER_ARM_HEIGHT 2.3
#define UPPER_ARM_RADIUS  0.5
#define LOWER_ARM_RADIUS  0.4
#define UPPER_LEG_RADIUS  0.6
#define LOWER_LEG_RADIUS  0.6
#define LOWER_LEG_HEIGHT 3.1
#define UPPER_LEG_HEIGHT 3.3
#define HEAD_HEIGHT 1.2
#define HEAD_RADIUS 1.0
#define HAND_RADIUS 0.5
#define HAND_HEIGHT 0.9
#define FOOT_RADIUS 0.7
#define FOOT_HEIGHT 1.1
//#define NECK_RADIUS 0.5
//#define NECK_HEIGHT 0.8
#define NECK_RADIUS 0.6
#define NECK_HEIGHT 0.6
#define JOINT_POINT_RADIUS 0.4
#define JOINT_POINT_HEIGHT 0.5

struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
typedef struct Image Image;

#endif