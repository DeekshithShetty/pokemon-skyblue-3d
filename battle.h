#ifndef _BATTLE_H_
#define _BATTLE_H_

class Battle{
	
	public:
		static void setOrthographicProjection();
		static void resetPerspectiveProjection() ;
		static void renderSpacedBitmapString(float x, float y,int spacing, void *font,char *string);
		static void renderVerticalBitmapString(float x, float y, int bitmapHeight, void *font,char *string); 
		static void drawString(float x, float y,char *string);

		static int ImageLoad(char *filename, Image *image);
		static void LoadGLTextures();
		static void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar );
		static int InitGL(int Width, int Height);
		static void changeSize(int w, int h);
		static void ReSizeGLScene(int Width, int Height);
		static void main_screen();
		static void drawBattleGround(GLuint texture);
		static void drawBackground();
		static void drawPokeBall(GLuint texture);
		static void drawPowerStatusBox();

		static void drawHPMeterMarill();
		static void drawHPMeterPikachu();
		static void drawHPMeterCharmander();
		static void drawHPMeterOddish();

		static void drawNotePad();

		static void drawThunderBolt();
		static void drawKoffing();

		static void keyPressed(unsigned char key, int x, int y);
		static void mouse(int btn, int state, int x, int y);
};

#include "battle.cpp"
//#include "battle1280.cpp"

#endif