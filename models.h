#ifndef _MODELS_H_
#define _MODELS_H_


 class Model{
	 public:
		Model(){}
		~Model(){}
		void drawSnowman();
		void drawBuildings(int x,int y,int z,int size,GLuint texture);
		void rectangle();
		void drawStadium(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4);	
		void drawSignBoard(GLuint texture);
		void drawRoute(GLuint texture);
		void drawGround(GLuint texture);
		void drawSky();
		void drawGrass(float pHeight);
		void drawCylinder(float pHeight,GLuint texture);
		void drawCone(float pHeight,GLuint texture);      
};
GLUquadricObj *quadratic;

#include "models.cpp"

#endif
