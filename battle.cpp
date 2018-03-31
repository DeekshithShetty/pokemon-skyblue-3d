#include <stdio.h>
#include <GL/glut.h>
#include <string.h>
#include "headers.h"
#include "mainPage.h"
#include "common.h"
#include "screen.h"
#include "imageLoader.h"

GLuint pikaTexture2[5],ashTexture2[7],garyTexture2[7],marillTexture2[4],charmanderTexture[5],oddishTexture2[2];
GLuint texture200[7];

GLUquadricObj *pokeBall;

AshModel ash2;
GaryModel gary2;
PikachuModel pika2;
MarillModel marill2;
CharmanderModel charmander2;
OddishModel oddish2;

float garyMovement = 0.0,garyMovement2 = 0.0,garyMovement3 = 0.0,ashMovement = 0.0,ashMovement2 = 0.0,ashMovement3 = 0.0;
//attack movements
float bubbleMovement = 0.0,icebeamMovement = 0.0,thunderboltMovement = 0.0,lightballMovement = 0.0;
float emberMovement = 0.0,razorleafMovement = 0.0;
int start = 0,buttonStart = 0;
//attacks
int bubble = 0,icebeam = 0,thunderbolt = 0,lightball = 0,ember =0,razorleaf = 0;
int garyBattleBeginString = 1,garySentOutMarillString = 1,ashSentOutPikachuString = 1,garySentOutCharmanderString = 0,ashSentOutOddishString = 1;
//faint strings
int marillFaintedString = 0,charmanderFaintedString = 0;
int pikachuFaintedString = 0,oddishFaintedString = 0;
//pokemon faints
int marillFainted = 0,pikachuFainted = 0,charmanderFainted = 0,oddishFainted = 0;

float powReduceOfMarill =0.0f;        //marills power
float powReduceOfPikachu = 0.0f;		//pikachus power
float powReduceOfCharmander = 0.0f;		//marill2 s power -0.25 to cope up with decrement
float powReduceOfOddish = 0.0f;		//marill2 s power -0.25 to cope up with decrement

void Battle::setOrthographicProjection() {
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the 
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, WIDTH, HEIGHT, 0);	
	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}


void Battle::resetPerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void Battle::renderSpacedBitmapString(

			float x, 
			float y,
			int spacing, 
			void *font,
			char *string) {

  char *c;
  int x1=x;

  for (c=string; *c != '\0'; c++) {

	glRasterPos2f(x1,y);
	glutBitmapCharacter(font, *c);
	x1 = x1 + glutBitmapWidth(font,*c) + spacing;
  }
}

void Battle::renderVerticalBitmapString(

			float x, 
			float y, 
			int bitmapHeight, 
			void *font,
			char *string) {

  char *c;
  int i;
  
  for (c=string,i=0; *c != '\0'; i++,c++) {
  
	glRasterPos2f(x, y+bitmapHeight*i);
	glutBitmapCharacter(font, *c);
  }
}

void Battle::drawString(float x, float y,char *string){
	glPushMatrix();
		setOrthographicProjection();
		glPushMatrix();
			glLoadIdentity();
			renderSpacedBitmapString(x,y,0,GLUT_BITMAP_TIMES_ROMAN_24,string);
		glPopMatrix();
		resetPerspectiveProjection();
	glPopMatrix();
}

// Load Bitmaps And Convert To Textures
void Battle::LoadGLTextures() {	
    // Load Texture     
	ImageLoader imageLoader2;

    imageLoader2.ashImageLoad(ashTexture2);
    imageLoader2.pikachuImageLoad(pikaTexture2);
    imageLoader2.garyImageLoad(garyTexture2);
    imageLoader2.marillImageLoad(marillTexture2);
    imageLoader2.charmanderImageLoad(charmanderTexture);
    imageLoader2.oddishImageLoad(oddishTexture2);
    imageLoader2.battleImageLoad(texture200);
   
}

void Battle::perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;

	//fH = tan( (fovY / 2) / 180 * pi ) * zNear;
	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;

	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}
//----------------------------------------------------------------------------------------
int Battle::InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	system("killall -9 mplayer");
	system("mplayer -loop 0 Sound/battle-gary.mp3 >> /dev/null &");
	LoadGLTextures();
	glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Clear The Background Color To Blue 
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	//glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading							
	glDepthFunc(GL_LEQUAL);		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix

	perspectiveGL(60.0f,(GLfloat)Width/(GLfloat)Height,1.0f,100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
	return 1;
}
//------------------------------------------------------------------------------------------------

void Battle::changeSize(int w, int h) 
{
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	perspectiveGL(45.0, ratio, 0.1, 100.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}
//------------------------------------------------------------------------------

void Battle::ReSizeGLScene(int Width, int Height)
{
	if (Height==0)				
		Height=1;

	glViewport(0, 0, Width, Height);		

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(75.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
}
//--------------------------------------------------------------------------------------------
void Battle::drawBackground(){
	//style
	glBegin(GL_QUADS);
		glColor3f(0.9, 0.9, 0.9);
	 	glVertex3f(-40.0, 50.0, 0.0);	// Bottom Left Of The Texture and Quad
	 	glColor3f(0.4745098039, 0.4823529411, 0.4549019607);
	    glVertex3f(-40.0, 50.0, 25.0);	// Bottom Right Of The Texture and Quad
	    glColor3f(0.4745098039, 0.4823529411, 0.4549019607);
	    glVertex3f(40, 50.0, 25.0);	// Top Right Of The Texture and Quad
	    glColor3f(0.9, 0.9, 0.9);
	    glVertex3f( 40,50.0, 0.0);	// Top Left Of The Texture and Quad
	glEnd();
}
void Battle::drawBattleGround(GLuint texture){
	glColor3f(0.6745098039, 0.6823529411, 0.6549019607);
	//glColor3f(0.0, 0.0, 0.0);
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	 	glVertex3f(-4.0, 0.0, 0.0);	// Bottom Left Of The Texture and Quad
	    glVertex3f(-4.0, 30.0, 0.0);	// Bottom Right Of The Texture and Quad
	    glVertex3f(15, 30.0, 0.0);	// Top Right Of The Texture and Quad
	    glVertex3f( -0.5,0.0, 0.0);	// Top Left Of The Texture and Quad
	glEnd();	
	//176,176,144
	glColor3f(0.3901960784f, 0.3901960784f, 0.2647058823);
	glPushMatrix();
		glTranslatef(-1.5, 3.0, 0.01);	// translate to just above ground
		glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
		glutSolidSphere(1.3, 20, 20); // shadow same size as body
	glPopMatrix();
	//glColor3f(0.6705882352f, 0.6588235294f, 0.3607843137f);
	glPushMatrix();
		glTranslatef(0.8, 18.0, 0.01);	// translate to just above ground
		glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
		glutSolidSphere(4, 20, 20); // shadow same size as body
	glPopMatrix();
	
}
void Battle::drawPokeBall(GLuint texture){
	glColor3f (0.8, 0.8, 0.8);
   	//glRotatef(-90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);                      //lower head
	   	pokeBall = gluNewQuadric();
		gluQuadricNormals(pokeBall, GLU_SMOOTH);
		gluQuadricTexture(pokeBall, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	gluSphere(pokeBall,0.2,20,20);
	glDisable(GL_TEXTURE_2D);
}
void Battle::drawPowerStatusBox(){
	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(-2.8f, 0.0f, 0.0f);          // Top Left
	    glVertex3f(5.2f, 0.0f,  0.0f);          // Top Right
	    glVertex3f(5.2f, 0.0f, -2.2f);          // Bottom Right
	    glVertex3f(-2.8f, 0.0f, -2.2f);          // Bottom Left
	glEnd();

  	glBegin(GL_QUADS);                  // Draw A Quad
  		glColor3f (0.8, 0.8, 0.8);
	    glVertex3f(-3.0f, 0.0f, 0.2f);          // Top Left
	    glColor3f (0.8, 0.8, 0.8);
	    glVertex3f(5.0f, 0.0f,  0.2f);          // Top Right
	    glColor3f (0.7, 0.7, 0.7);
	    glVertex3f(5.0f, 0.0f, -2.0f);          // Bottom Right
	    glColor3f (0.7, 0.7, 0.7);
	    glVertex3f(-3.0f, 0.0f, -2.0f);          // Bottom Left
  	glEnd();                      // Done Drawing The Quad

  	glLineWidth(2.0);
  	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-3.0f, 0.0f, 0.2f);          // Top Left
	    glVertex3f(5.0f, 0.0f,  0.2f);          // Top Right
	    glVertex3f(5.0f, 0.0f, -2.0f);          // Bottom Right
	    glVertex3f(-3.0f, 0.0f, -2.0f);          // Bottom Left
	glEnd();
}
void Battle::drawHPMeterMarill(){
	glColor3f(0.1,0.1,0.1);
    drawString(380,290,"MARILL           Lv50");

    glColor3f (1.0, 1.0, 1.0);
  	glBegin(GL_QUADS);                  // Draw A Quad
	    glVertex3f(-2.0f, 0.0f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, 0.0f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, 0.0f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, 0.0f, -1.0f);          // Bottom Left
  	glEnd();                      // Done Drawing The Quad

	if(powReduceOfMarill <= 6.0){
		glColor3f (0.0, 0.8, 0.0);
		if(powReduceOfMarill >=3)glColor3f (0.8, 0.4, 0.0);
		if(powReduceOfMarill >=5)glColor3f (0.8, 0.0, 0.0);	
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-2.0f, -0.01f, -0.5f);          // Top Left
		    glVertex3f( 4.0f-powReduceOfMarill, -0.01f, -0.5f);          // Top Right
		    glVertex3f( 4.0f-powReduceOfMarill, -0.01f, -1.0f);          // Bottom Right
		    glVertex3f(-2.0f, -0.01f, -1.0f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
	}else{

		marillFaintedString = 1;
		marillFainted = 1;
		garySentOutCharmanderString = 1;                            
	}
	
	glLineWidth(2.0);           //outline
  	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, -0.011f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, -0.011f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, -0.011f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, -0.011f, -1.0f);          // Bottom Left
	glEnd();

}
void Battle::drawHPMeterCharmander(){
	glColor3f(0.1,0.1,0.1);
    drawString(380,290,"CHARMANDER          Lv50");

    glColor3f (1.0, 1.0, 1.0);
  	glBegin(GL_QUADS);                  // Draw A Quad
	    glVertex3f(-2.0f, 0.0f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, 0.0f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, 0.0f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, 0.0f, -1.0f);          // Bottom Left
  	glEnd();                      // Done Drawing The Quad

	if(powReduceOfCharmander <= 6.0){
		glColor3f (0.0, 0.8, 0.0);
		if(powReduceOfCharmander >=3)glColor3f (0.8, 0.4, 0.0);
		if(powReduceOfCharmander >=5)glColor3f (0.8, 0.0, 0.0);	
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-2.0f, -0.01f, -0.5f);          // Top Left
		    glVertex3f( 4.0f-powReduceOfCharmander, -0.01f, -0.5f);          // Top Right
		    glVertex3f( 4.0f-powReduceOfCharmander, -0.01f, -1.0f);          // Bottom Right
		    glVertex3f(-2.0f, -0.01f, -1.0f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
	}else{
		charmanderFaintedString = 1;
		charmanderFainted = 1;
	}
	glLineWidth(2.0);           //outline
  	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, -0.011f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, -0.011f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, -0.011f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, -0.011f, -1.0f);          // Bottom Left
	glEnd();
	
}
void Battle::drawHPMeterPikachu(){
	glColor3f(0.1,0.1,0.1);
    drawString(930,520,"PIKACHU           Lv50");
    //white background
    glColor3f (1.0, 1.0, 1.0);
  	glBegin(GL_QUADS);                  // Draw A Quad
	    glVertex3f(-2.0f, 0.0f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, 0.0f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, 0.0f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, 0.0f, -1.0f);          // Bottom Left
  	glEnd();                      // Done Drawing The Quad

	if(powReduceOfPikachu <=6.0){
		glColor3f (0.0, 0.8, 0.0);
		if(powReduceOfPikachu >=3)glColor3f (0.8, 0.4, 0.0);
		if(powReduceOfPikachu >=5)glColor3f (0.8, 0.0, 0.0);	
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-2.0f, -0.01f, -0.5f);          // Top Left
		    glVertex3f( 4.0f-powReduceOfPikachu, -0.01f, -0.5f);          // Top Right
		    glVertex3f( 4.0f-powReduceOfPikachu, -0.01f, -1.0f);          // Bottom Right
		    glVertex3f(-2.0f, -0.01f, -1.0f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
	}else{
		//glColor3f(0.9,0.9,0.9);
    	//drawString(50,670,"PIKACHU FAINTED!");

		pikachuFainted = 1;
		pikachuFaintedString = 1;
		ashSentOutOddishString = 1; 
	}
	glLineWidth(2.0);           //outline
  	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, -0.011f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, -0.011f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, -0.011f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, -0.011f, -1.0f);          // Bottom Left
	glEnd();
	
}
void Battle::drawHPMeterOddish(){
	glColor3f(0.1,0.1,0.1);
    drawString(930,520,"ODDISH         Lv50");
    //white background
    glColor3f (1.0, 1.0, 1.0);
  	glBegin(GL_QUADS);                  // Draw A Quad
	    glVertex3f(-2.0f, 0.0f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, 0.0f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, 0.0f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, 0.0f, -1.0f);          // Bottom Left
  	glEnd();                      // Done Drawing The Quad

	if(powReduceOfOddish <=6.0){
		glColor3f (0.0, 0.8, 0.0);
		if(powReduceOfOddish >=3)glColor3f (0.8, 0.4, 0.0);
		if(powReduceOfOddish >=5)glColor3f (0.8, 0.0, 0.0);
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-2.0f, -0.01f, -0.5f);          // Top Left
		    glVertex3f( 4.0f-powReduceOfOddish, -0.01f, -0.5f);          // Top Right
		    glVertex3f( 4.0f-powReduceOfOddish, -0.01f, -1.0f);          // Bottom Right
		    glVertex3f(-2.0f, -0.01f, -1.0f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
	}else{

		oddishFainted = 1;
		oddishFaintedString = 1;
	}
	glLineWidth(2.0);           //outline
  	glColor3f (0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, -0.011f, -0.5f);          // Top Left
	    glVertex3f( 4.0f, -0.011f, -0.5f);          // Top Right
	    glVertex3f( 4.0f, -0.011f, -1.0f);          // Bottom Right
	    glVertex3f(-2.0f, -0.011f, -1.0f);          // Bottom Left
	glEnd();
	
}

void Battle::drawNotePad(){
	glPushMatrix();
    	glColor3f(0.8117647058, 0.3176470588, 0.1960784313);
		//glTranslatef (0.0, 1.5, 0.1);
		glScalef(0.5,0.5,0.5);                                                 //red
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-3.0f, 0.0f, 1.0f);          // Top Left
		    glVertex3f(3.0f, 0.0f,  1.0f);          // Top Right
		    glVertex3f(3.0f, 0.0f,  0.0f);          // Bottom Right
		    glVertex3f(-3.0f, 0.0f, 0.0f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
    glPopMatrix();
    glPushMatrix();
    //88,144,152;
    	glColor3f(0.2, 0.2, 0.2);
		//glTranslatef (0.0, 1.5, 0.1);
		glScalef(0.5,0.5,0.5);                                                 //blue
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-2.23f, 0.0f, 0.95f);          // Top Left
		    glVertex3f(2.23f, 0.0f,  0.95f);          // Top Right
		    glVertex3f(2.23f, 0.0f,  0.6f);          // Bottom Right
		    glVertex3f(-2.23f, 0.0f, 0.6f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
    glPopMatrix();

    glPushMatrix();
    	glColor3f(0.9, 0.9, 0.9);
		glScalef(0.5,0.5,0.5);                                                 //white
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(1.1f, 0.0f, 0.92f);          // Top Left
		    glVertex3f(2.20f, 0.0f,  0.92f);          // Top Right
		    glVertex3f(2.20f, 0.0f,  0.63f);          // Bottom Right
		    glVertex3f(1.1f, 0.0f, 0.63f);          // Bottom Left
	  	glEnd();                      // Done Drawing The Quad
    glPopMatrix();
}
void Battle::drawThunderBolt(){
	//glColor3f(0.2,0.2,0.2);
	glColor3f(1.0,1.0,0.0);
  	gluSphere(h,0.4,10,10);
  	glColor3f(0.8,0.8,0.0);

  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(90,0.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(180,0.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(270,0.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(360,0.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);

  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(90,1.0,0.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(180,1.0,0.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(270,1.0,0.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(360,1.0,0.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);

  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(90,0.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(180,0.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(270,0.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);
  	glRotatef(360,0.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 0.8, 32, 32);

  	glRotatef(90,1.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,1.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,1.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,1.0,0.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,0.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,0.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,0.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,0.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,1.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,1.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,1.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,1.0,1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,1.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,1.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,1.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,1.0,1.0,1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);

  	glRotatef(90,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(180,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(270,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	glRotatef(360,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.05f, 0.05f, 1.0, 32, 32);
  	
}
void Battle::drawKoffing(){
	//glColor3f(0.2,0.2,0.2);
	glColor3f(0.7,0.0,0.7);
  	gluSphere(h,0.8,10,10);
  	glColor3f(0.2,0.2,0.2);

  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(90,0.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(180,0.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(270,0.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(360,0.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
/*
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(90,1.0,0.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(180,1.0,0.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(270,1.0,0.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(360,1.0,0.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);*/

  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(90,0.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(180,0.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(270,0.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
  	glRotatef(360,0.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 0.8, 32, 32);
/*
  	glRotatef(90,1.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,1.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,1.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,1.0,0.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);*/

  	glRotatef(90,0.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,0.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,0.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,0.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);

  	glRotatef(90,1.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,1.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,1.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,1.0,1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);

  	glRotatef(90,1.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,1.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,1.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,1.0,1.0,1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);

  	glRotatef(90,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,-1.0,0.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);

  	glRotatef(90,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,0.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);

  	glRotatef(90,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,-1.0,-1.0,0.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);

  	glRotatef(90,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(180,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(270,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	glRotatef(360,-1.0,-1.0,-1.0);
  	gluCylinder(h, 0.15f, 0.15f, 1.0, 32, 32);
  	
}


void Battle::main_screen(){
	int i, j;
	// Clear color and depth buffers
	glClearColor(0.9, 0.9, 0.9, 1.0); 
	//glClearColor(0.6745098039, 0.6823529411, 0.6549019607, 1.0); // sky color is light blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //PlaySound("242-champion-road.mp3", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

	// Reset transformations
	glLoadIdentity();
	// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	
	gluLookAt(
			0,      0,      1.0,
			0.0, 1.0, 1.0,
			0.0,    0.0,    1.0);

	 glPushMatrix();
		glTranslatef(0.0,0.0,0.0);
		//glRotatef(5,1.0,0.0,0.0);
		glRotatef(-15,0.0,0.0,1.0);
        drawBattleGround(texture200[0]);
    glPopMatrix();

    drawBackground();
   
    glColor3f(0.9,0.9,0.9);
    if(garyBattleBeginString)
	drawString(50,670,"GARY WANTS TO BATTLE!");

    if(start == 1)                                     //start = 1 after pressing start
    	ashMovement += 0.015;
    glPushMatrix();                                     //draw ash
    	glTranslatef(-0.5-ashMovement,2.0,0.5);
        glRotatef(90,1.0,0.0,0.0);
       	glScalef(0.07,0.07,0.07);
        ash2.enableShade();
        ash2.drawCyborg(ashTexture2[0],ashTexture2[1],ashTexture2[2],ashTexture2[3],ashTexture2[4],ashTexture2[5],ashTexture2[6]);
        ash2.disableShade();
    glPopMatrix();
    if(ashMovement >= 2){ 
		glPushMatrix();  
			glTranslatef(-0.5,2.0,2.0-((ashMovement*2)/3.5)); 
			glScalef(0.2,0.2,0.2);                                          //draw pokeball
			glRotatef(180,0.0,0.0,1.0);
			drawPokeBall(texture200[1]);
    	glPopMatrix();
	}
    

    if(ashMovement >= 3){                                //draw pikachu
    	garySentOutMarillString = 0;
    	glColor3f(0.9,0.9,0.9);
    	if(ashSentOutPikachuString)
			drawString(50,670,"ASH: PIKACHU I CHOOSE YOU!!!");
		if(!pikachuFainted){
			glPushMatrix();
		    	glTranslatef(-0.5,2.0,0.3);
		        glRotatef(90,1.0,0.0,0.0);
		       	glScalef(0.1,0.1,0.1);
		        pika2.enableShade();
		        pika2.drawCyborg(pikaTexture2[0],pikaTexture2[1],pikaTexture2[2],pikaTexture2[3],pikaTexture2[4]);
		        pika2.disableShade();
	    	glPopMatrix();
	    	glPushMatrix();                            //pickachu PowerStatusBox
	    		glTranslatef(0.7,1.8,0.75);
	    		glScalef(0.1,0.1,0.1);
	    		drawPowerStatusBox();
	    	glPopMatrix();
	    	glPushMatrix();
		    	glTranslatef(0.7,1.8,0.75);
	    		glScalef(0.1,0.1,0.1);
		    	drawHPMeterPikachu();
		    glPopMatrix();
	    	//for(int j=0;j<100000;j+= 1);
	    		//bubble =1;
		}else{
			glColor3f(0.9,0.9,0.9);
    		if(pikachuFaintedString && !bubble && !icebeam && !ember)
    			drawString(50,670,"PIKACHU FAINTED!");
    		glPushMatrix();                                        //draw ash again
		    	glTranslatef(-0.5-ashMovement2,2.0,0.5);
		        glRotatef(90,1.0,0.0,0.0);
		       	glScalef(0.07,0.07,0.07);
		        ash2.enableShade();
		        ash2.drawCyborg(ashTexture2[0],ashTexture2[1],ashTexture2[2],ashTexture2[3],ashTexture2[4],ashTexture2[5],ashTexture2[6]);
		        ash2.disableShade();
			glPopMatrix();
			if(ashMovement2 >= 2){ 
				glPushMatrix();  
					glTranslatef(-0.5,2.0,2.0-((ashMovement2*2)/3.5)); 
					glScalef(0.2,0.2,0.2);                                          //draw pokeball again
					glRotatef(180,0.0,0.0,1.0);
					drawPokeBall(texture200[1]);
		    	glPopMatrix();
			}
		}    
	}
	//logic for ashs 2nd pokemon
	if(pikachuFainted){
		ashMovement2 += 0.015;
		if(ashMovement2 >= 3){  
			pikachuFaintedString = 0;                            //draw pikachu2
			glColor3f(0.9,0.9,0.9);
			if(ashSentOutOddishString)
				drawString(50,670,"ASH SENT OUT ODDISH!");
			if(!oddishFainted){
	    		glPushMatrix();
			    	glTranslatef(-0.5,2.0,0.3);
			        glRotatef(90,1.0,0.0,0.0);
			       	//glScalef(0.1,0.1,0.1);
			       	//marill2.enableShade();
					//marill2.drawCyborg(marillTexture2[0],marillTexture2[1],marillTexture2[2],marillTexture2[3]);
					//marill2.disableShade();
					glScalef(0.15,0.15,0.15);
					oddish2.enableShade();
        			oddish2.drawCyborg(oddishTexture2[0],oddishTexture2[1],marillTexture2[3]);
        			oddish2.disableShade();
					//glScalef(0.4,0.4,0.4);
					//drawKoffing();
		    	glPopMatrix();
		    	glPushMatrix();                            //pickachu2 PowerStatusBox
		    		glTranslatef(0.7,1.8,0.75);
		    		glScalef(0.1,0.1,0.1);
		    		drawPowerStatusBox();
		    	glPopMatrix();
		    	glPushMatrix();
			    	glTranslatef(0.7,1.8,0.75);
		    		glScalef(0.1,0.1,0.1);
			    	drawHPMeterOddish();
			    glPopMatrix();
	    	}else{
	    		glColor3f(0.9,0.9,0.9);
	    		if(oddishFaintedString && !bubble && !icebeam && !ember)
	    			drawString(50,670,"ODDISH FAINTED!");
	    		glPushMatrix();                                        //draw ash again
	    			if(ashMovement3 >= 2.0){
			    		//glTranslatef(-0.5+ashMovement3,2.0,0.5);
			    		glTranslatef(-0.5,2.0,0.5);
			    		oddishFaintedString = 0;
			    	}else{
			    		glTranslatef(-2.5+ashMovement3,2.0,0.5);
			    		
			    	}
			        glRotatef(90,1.0,0.0,0.0);
			       	glScalef(0.07,0.07,0.07);
			        ash2.enableShade();
			        ash2.drawCyborg(ashTexture2[0],ashTexture2[1],ashTexture2[2],ashTexture2[3],ashTexture2[4],ashTexture2[5],ashTexture2[6]);
			        ash2.disableShade();
				glPopMatrix();
				glColor3f(0.9,0.9,0.9);
				if(!oddishFaintedString && !bubble)
	    			drawString(50,670,"ASH: .............");
	    	}
		}
	}
	if(oddishFainted)
		ashMovement3 += 0.015;
//-------------------------------------------------------------------------------------------------------------------	

    if(start == 1)
    	garyMovement += 0.06;
	glPushMatrix();                                        //draw gary
    	glTranslatef(5.0+garyMovement,15.0,1.2);
        glRotatef(90,1.0,0.0,0.0);
        glRotatef(150,0.0,1.0,0.0);
       	glScalef(0.2,0.2,0.2);
        gary2.enableShade();
		gary2.drawCyborg(garyTexture2[0],garyTexture2[1],garyTexture2[2],garyTexture2[3],garyTexture2[4],garyTexture2[5],garyTexture2[6]);
		gary2.pointHand();
		gary2.disableShade();
	glPopMatrix();
	if(garyMovement >= 2){ 
		glPushMatrix();  
			glTranslatef(5.0,15.0,2.6-((garyMovement*1.5)/4));                                     //draw pokeball
			drawPokeBall(texture200[1]);
    	glPopMatrix();
	}

	if(garyMovement >= 8){                                                  //draw marill
		glColor3f(0.9,0.9,0.9);
		if(garySentOutMarillString)
			drawString(50,670,"GARY SENT OUT MARILL!");
		if(!marillFainted){
    		glPushMatrix();
		    	glTranslatef(5.0,15.0,0.0);
		        glRotatef(90,1.0,0.0,0.0);
		        glRotatef(150,0.0,1.0,0.0);
		       	glScalef(0.3,0.3,0.3);
		       	marill2.enableShade();
				marill2.drawCyborg(marillTexture2[0],marillTexture2[1],marillTexture2[2],marillTexture2[3]);
				marill2.disableShade();
	    	glPopMatrix();                                                //draw maril PowerStatusBox
	    	glPushMatrix();
	    		glTranslatef(-4.0,18.0,3.0);
	    		drawPowerStatusBox();
	    	glPopMatrix();
	    	glPushMatrix();
	    		glTranslatef(-4.0,18.0,3.0);
	    		drawHPMeterMarill();
	    	glPopMatrix();
    	}else{
    		glColor3f(0.9,0.9,0.9);
    		if(marillFaintedString && !thunderbolt && !lightball && !razorleaf)
    			drawString(50,670,"MARILL FAINTED!");
    		glPushMatrix();                                        //draw gary again
		    	glTranslatef(5.0+garyMovement2,15.0,1.2);
		        glRotatef(90,1.0,0.0,0.0);
		        glRotatef(150,0.0,1.0,0.0);
		       	glScalef(0.2,0.2,0.2);
		        gary2.enableShade();
				gary2.drawCyborg(garyTexture2[0],garyTexture2[1],garyTexture2[2],garyTexture2[3],garyTexture2[4],garyTexture2[5],garyTexture2[6]);
				gary2.disableShade();
			glPopMatrix();
			if(garyMovement2 >= 2){ 
				glPushMatrix();  
					glTranslatef(5.0,15.0,2.6-((garyMovement2*1.5)/4));                                     //draw pokeball
					drawPokeBall(texture200[1]);
		    	glPopMatrix();
			}
    	}
	}
	//logic for garys 2nd pokemon
	if(marillFainted){
		garyMovement2 += 0.06;
		if(garyMovement2 >= 8){  
			marillFaintedString = 0;                            //draw marill
			glColor3f(0.9,0.9,0.9);
			if(garySentOutCharmanderString)
				drawString(50,670,"GARY SENT OUT CHARMANDER!");
			if(!charmanderFainted){
	    		glPushMatrix();
			    	glTranslatef(5.0,15.0,0.9);
			        glRotatef(90,1.0,0.0,0.0);
			        glRotatef(150,0.0,1.0,0.0);
			        glRotatef(-40,0.0,1.0,0.0);
			       	glScalef(0.27,0.27,0.27);
			       	charmander2.enableShade();
        			charmander2.drawCyborg(charmanderTexture[0],charmanderTexture[1],charmanderTexture[2],charmanderTexture[3],charmanderTexture[4]);
        			charmander2.disableShade();
			       	//pika2.enableShade();
			        //pika2.drawCyborg(pikaTexture2[0],pikaTexture2[1],pikaTexture2[2],pikaTexture2[3],pikaTexture2[4]);
			        //pika2.disableShade();
		    	glPopMatrix();                                                //draw maril PowerStatusBox
		    	glPushMatrix();
		    		glTranslatef(-4.0,18.0,3.0);
		    		drawPowerStatusBox();
		    	glPopMatrix();
		    	glPushMatrix();
		    		glTranslatef(-4.0,18.0,3.0);
		    		drawHPMeterCharmander();
		    	glPopMatrix();
	    	}else{
	    		glColor3f(0.9,0.9,0.9);
	    		if(charmanderFaintedString && !thunderbolt && !lightball && !razorleaf)
	    			drawString(50,670,"CHARMANDER FAINTED!");
	    		glPushMatrix();                                        //draw gary again
	    			if(garyMovement3 <= 9.0){
			    		glTranslatef(14.0-garyMovement3,15.0,1.2);
			    	}else{
			    		glTranslatef(5.0,15.0,1.2);
			    		charmanderFaintedString = 0;
			    	}
			        glRotatef(90,1.0,0.0,0.0);
			        glRotatef(150,0.0,1.0,0.0);
			       	glScalef(0.2,0.2,0.2);
			        gary2.enableShade();
					gary2.drawCyborg(garyTexture2[0],garyTexture2[1],garyTexture2[2],garyTexture2[3],garyTexture2[4],garyTexture2[5],garyTexture2[6]);
					gary2.disableShade();
				glPopMatrix();
				glColor3f(0.9,0.9,0.9);
				if(!charmanderFaintedString && !thunderbolt)
	    			drawString(50,670,"GARY: WHAT?.....NO! THAT CANT BE ! ITS NOT FAIR !");
	    	}
		}
	}
	if(charmanderFainted)
		garyMovement3 += 0.06;
//-------------------------------------------------------------------------------------------------------	
	
	glPushMatrix();
		glTranslatef (0.0, 1.5, 0.1);
		drawNotePad();
	glPopMatrix();

	//marills attacks
	if(bubble){
		glColor3f(0.9,0.9,0.9);
		//if(marBub)
			drawString(50,670,"MARILL USED BUBBLE!");
    	bubbleMovement += 0.08;
		glPushMatrix();
			if((15.0-bubbleMovement*2.0) <= 1.5){
				glColor3f(0.9,0.9,0.9);
				drawString(50,700,"It's not very effective.");
				//water effect
				glPushMatrix();
					glTranslatef(-0.5,2.0,0.3);
					glColor3f(0.0,0.0,0.8);
					//gluSphere(h,1.0+bubbleMovement*2.0,10,10);
					//gluCylinder(h, 0.8f+bubbleMovement, 0.8f-bubbleMovement, 5.0, 32, 32);
				glPopMatrix();
				powReduceOfPikachu = powReduceOfPikachu + 0.01;
				if(pikachuFainted && !pikachuFaintedString) 
					powReduceOfOddish = powReduceOfOddish + 0.02;
			}
			if((15.0-bubbleMovement*2.0) <= -10.0){                         //decrease opponent power
				bubble = !bubble;
			}
			
			glColor3f(0.1,0.1,0.9);
	    	glTranslatef(5.2-(bubbleMovement*1.6)/2,15.0-bubbleMovement*2.0,0.4);
	        gluSphere(h,0.2,10,10);
	        glTranslatef(5.1-(bubbleMovement*1.6)/2,15.0-bubbleMovement*2.0,0.2);
	        gluSphere(h,0.15,10,10);
	        glTranslatef(5.0-(bubbleMovement*1.6)/2,15.0-bubbleMovement*2.0,0.3);
	        gluSphere(h,0.25,10,10);
    	glPopMatrix(); 
	}
	if(icebeam){
		glColor3f(0.9,0.9,0.9);
		//if(marBub)
			drawString(50,670,"MARILL USED ICEBEAM!");
    	icebeamMovement += 0.08;
		glPushMatrix();
			if((15.0-icebeamMovement*2.0) <= 1.5){
				glColor3f(0.9,0.9,0.9);
				drawString(50,700,"The opponent was frozen.");
				//water effect
				glPushMatrix();
					glTranslatef(0.0,-5.0,0.2);
					glColor3f(0.0,0.0,0.8);
					//gluSphere(h,1.0+bubbleMovement*2.0,10,10);
					//gluCylinder(h, 0.6f+icebeamMovement*2.0, 0, 2.0, 32, 32);
				glPopMatrix();
				powReduceOfPikachu = powReduceOfPikachu + 0.02;
				if(pikachuFainted && !pikachuFaintedString) 
					powReduceOfOddish = powReduceOfOddish + 0.03;
			}
			if((15.0-icebeamMovement*2.0) <= -10.0){                         //decrease opponent power
				icebeam = !icebeam;
			}
			glColor4f(1.0,1.0,1.0,1.0);
	    	glTranslatef(5.0-(icebeamMovement*1.7)/2,15.0-icebeamMovement*2.0,0.4);
	        gluSphere(h,0.2,10,10); 
	        glColor4f(0.8,0.8,1.0,0.6);
	        //glTranslatef(5.0-(icebeamMovement*1.6)/2,15.0-icebeamMovement*2.0,0.2);
	        gluSphere(h,0.4,10,10);
    	glPopMatrix(); 
	}
	//Charmanders attack
	if(ember){
		glColor3f(0.9,0.9,0.9);
		//if(marBub)
			drawString(50,670,"CHARMANDER USED EMBER!");
    	emberMovement += 0.08;
		glPushMatrix();
			if((15.0-emberMovement*2.0) <= 1.5){
				glColor3f(0.9,0.9,0.9);
				drawString(50,700,"The opponent was burned out.");
				//water effect
				glPushMatrix();
					glTranslatef(0.0,-5.0,0.2);
					glColor3f(0.0,0.0,0.8);
					//gluSphere(h,1.0+bubbleMovement*2.0,10,10);
					//gluCylinder(h, 0.6f+icebeamMovement*2.0, 0, 2.0, 32, 32);
				glPopMatrix();
				powReduceOfPikachu = powReduceOfPikachu + 0.02;
				if(pikachuFainted && !pikachuFaintedString) 
					powReduceOfOddish = powReduceOfOddish + 0.04;
			}
			if((15.0-emberMovement*2.0) <= -9.0){                         //decrease opponent power
				ember = !ember;
			}
			glColor4f(0.5,0.0,0.0,1.0);
			glScalef(emberMovement,emberMovement,1.0);
			glTranslatef(5.0-(emberMovement*1.7)/2.5,15.0-emberMovement*2.0,0.9);
	        gluSphere(h,0.21,10,10);
	        glTranslatef(5.1-(emberMovement*1.7)/2.5,15.0-emberMovement*2.0,0.9);
	        gluSphere(h,0.2,10,10); 
	        glTranslatef(4.9-(emberMovement*1.7)/2.5,15.0-emberMovement*2.0,0.9);
	        gluSphere(h,0.1,10,10);  
    	glPopMatrix(); 
	}

	//Pikachus attacks
	if(thunderbolt){
		glColor3f(0.9,0.9,0.9);
		drawString(50,670,"PIKACHU USED THUNDERBOLT!");
    	thunderboltMovement += 0.08;
		glPushMatrix();
			//glColor3f(0.9,0.9,0.0);
			if((2.0+thunderboltMovement*2.0) >= 15.0){
				glColor3f(0.9,0.9,0.9);
				drawString(50,700,"The opponent was paralysed.");
				//electric effect
				glPushMatrix();
					glTranslatef(0.0,0.0,2.4);
					glColor3f(0.8,0.8,0.0);
					gluSphere(h,8.0-thunderboltMovement,10,10);
				glPopMatrix();
				powReduceOfMarill = powReduceOfMarill + 0.05;
				if(marillFainted && !marillFaintedString) 
					powReduceOfCharmander = powReduceOfCharmander + 0.03;
			}
			if((2.0+thunderboltMovement*2.0) >= 25.0){                //decrease opponent power
				thunderbolt = !thunderbolt;
			}
	    	glTranslatef(-0.5+(thunderboltMovement*1.6)/2,2.0+thunderboltMovement*2.0,0.4);
	    	glScalef(0.4,0.4,0.4);
	    	glRotatef(90 + thunderboltMovement*100.0,1.0,1.0,1.0);
	        drawThunderBolt();
    	glPopMatrix(); 
	}
	if(lightball){
		glColor3f(0.9,0.9,0.9);
		drawString(50,670,"PIKACHU USED LIGHTBALL!");
    	lightballMovement += 0.08;
		glPushMatrix();
			//glColor3f(0.9,0.9,0.0);
			if((2.0+lightballMovement*2.0) >= 15.0){
				glColor3f(0.9,0.9,0.9);
				drawString(50,700,"The opponent was paralysed.");
				//electric effect
				glPushMatrix();
					glTranslatef(0.0,0.0,2.4);
					glColor3f(0.8,0.8,0.0);
					gluSphere(h,8.0-lightballMovement,10,10);
				glPopMatrix();
				powReduceOfMarill = powReduceOfMarill + 0.03;
				if(marillFainted && !marillFaintedString) 
					powReduceOfCharmander = powReduceOfCharmander + 0.03;
			}
			if((2.0+lightballMovement*2.0) >= 25.0){                //decrease opponent power
				lightball = !lightball;
			}
	    	glTranslatef(-0.5+(lightballMovement*1.6)/2,2.0+lightballMovement*2.0,0.4);
	    	glColor4f(0.9,0.9,0.0,0.7);
	        gluSphere(h,0.3,10,10); 
    	glPopMatrix(); 
	}
	//oddish's attacks
	if(razorleaf){
		glColor3f(0.9,0.9,0.9);
		drawString(50,670,"ODDISH USED RAZORLEAF!");
    	razorleafMovement += 0.08;
		glPushMatrix();
			//glColor3f(0.9,0.9,0.0);
			if((2.0+razorleafMovement*2.0) >= 15.0){
				glColor3f(0.9,0.9,0.9);
				drawString(50,700,"It cut through opponent skin.");
				//electric effect
				glPushMatrix();
					glTranslatef(0.0,0.0,2.4);
					glColor3f(0.0,0.9,0.0);
					gluSphere(h,8.0- razorleafMovement,10,10);
				glPopMatrix();
				powReduceOfMarill = powReduceOfMarill + 0.05;
				if(marillFainted && !marillFaintedString) 
					powReduceOfCharmander = powReduceOfCharmander + 0.02;
			}
			if((2.0+razorleafMovement*2.0) >= 25.0){                //decrease opponent power
				razorleaf = !razorleaf;
			}
			glColor4f(0.0,0.9,0.0,0.7);
	    	glTranslatef(-0.5+(razorleafMovement*1.6)/2,2.0+razorleafMovement*2.0,0.4);
	    	glRotatef(95.0, 1.0,0.0, 1.0);
			gluCylinder(h, 0.1f, 0.0f, 1.0, 32, 32);
			glRotatef(275.0, -1.0,0.0, -1.0);
			gluCylinder(h, 0.1f, 0.0f, 1.0, 32, 32);
			/*glRotatef(-95.0, 1.0,0.0, 1.0);
			gluCylinder(h, 0.1f, 0.0f, 1.0, 32, 32);
			glRotatef(175.0, 1.0,0.0, 1.0);
			gluCylinder(h, 0.1f, 0.0f, 1.0, 32, 32);*/
    	glPopMatrix(); 
	}


	glColor3f(0.1,0.1,0.1);
	drawString(1050,670,"START");
	if(buttonStart){
		glColor3f(0.1,0.1,0.1);
		drawString(1023,670,">>");
	}

	glColor3f(0.1,0.1,0.1);
	drawString(1206,670,"EXIT");

	glutSwapBuffers();
}



void Battle::keyPressed(unsigned char key, int x, int y){
	if(key ==27){
		exit(0);
	}
	if(key == 13){
		start = 1;
		buttonStart = 1;
		garyBattleBeginString = 0;
	}
	if(key == 'a'){
		bubble = !bubble;
		ashSentOutPikachuString = 0;
		ashSentOutOddishString = 0;
		garySentOutCharmanderString = 0;
		bubbleMovement = 0.0;
		start = 0;
	}
	if(key == 's'){
		icebeam = !icebeam;
		ashSentOutPikachuString = 0;
		ashSentOutOddishString = 0;
		garySentOutCharmanderString = 0;
		icebeamMovement = 0.0;
		start = 0;
	}
	if(key == 'z'){
		thunderbolt = !thunderbolt;
		ashSentOutPikachuString = 0;
		ashSentOutOddishString = 0;
		garySentOutCharmanderString = 0;
		thunderboltMovement = 0.0;
		start = 0;
	}
	if(key == 'x'){
		lightball = !lightball;
		ashSentOutPikachuString = 0;
		ashSentOutOddishString = 0;
		garySentOutCharmanderString = 0;
		lightballMovement = 0.0;
		start = 0;
	}
	if(key == 'm'){
		razorleaf = !razorleaf;
		ashSentOutPikachuString = 0;
		ashSentOutOddishString = 0;
		garySentOutCharmanderString = 0;
		razorleafMovement = 0.0;
		start = 0;
	}
	if(key == 'l'){
		ember = !ember;
		ashSentOutPikachuString = 0;
		ashSentOutOddishString = 0;
		garySentOutCharmanderString = 0;
		emberMovement = 0.0;
		start = 0;
	}
	if(key == 'q'){
		screen = 5;
		display();
	}
}

void Battle::mouse(int btn, int state, int x, int y){
	int yy,xx;
	int a0x0=1218,a0x1=1280, a0y0=76,a0y1=99;//exit 1218  y= 76 1280  y= 99
	int bx0=1058,bx1=1148, by0=75,by1=99;//enter 1058  y= 75 1148  y= 99

	yy = glutGet(GLUT_WINDOW_HEIGHT);
	y = yy - y;
	if (state == GLUT_DOWN)
	{
		if (btn==GLUT_LEFT_BUTTON)
		{
			//printf("DOWN: x=%3d  y=%3d \n", x, y);
			if(x>=a0x0 && x<=a0x1 && y>=a0y0 && y<=a0y1)
			{
				screen = 5;
				display();
			}
			if(x>=bx0 && x<=bx1 && y>=by0 && y<=by1)
			{
				start = 1;
				buttonStart = 1;
				garyBattleBeginString = 0;
			}
		}
	}
}