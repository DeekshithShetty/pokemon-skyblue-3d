#ifndef _COMMON_H_
#define _COMMON_H_

class CommonFunctions{
	public:
		void init();
		void drawString(void * ,char *  ,float  ,float  );
		void drawRectf(float x1, float y1, float height, float width);
		void drawRectfilled(float x1, float y1, float height, float width);
};

#include "common.cpp"

#endif

