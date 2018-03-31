#ifndef _TREES_H_
#define _TREES_H_

class Tree{
	public:
		Tree(){}
		~Tree(){}
		void drawCylinder(float pHeight);
		void drawCone(float pHeight);
		void drawTrees();
};

#include "trees.cpp"

#endif