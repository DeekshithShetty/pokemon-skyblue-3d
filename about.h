#ifndef _ABOUT_H_
#define _ABOUT_H_

class About{
	public:
		static void init(int Width, int Height);
		static void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );
		static void changeSize(int w, int h);
		static void screen12();
		static void keyPressed(unsigned char key, int x, int y);
		static void mouse(int btn, int state, int x, int y);
};

#include "about.cpp"

#endif


