#ifndef _INTROPAGE_H_
#define _INTROPAGE_H_

class IntroWindow{
	public:
		static void playSound();
		static void init(int Width, int Height);
		static void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );
		static void changeSize(int w, int h);
		static void main_screen();
		static void keyPressed(unsigned char key, int x, int y);
		static void mouse(int btn, int state, int x, int y);
};

#include "introPage.cpp"

#endif


