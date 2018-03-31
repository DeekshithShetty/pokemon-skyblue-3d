#include "headers.h"
#include "models.h"
#include "ashKetchum.h"
#include "gary.h"
#include "pikachu.h"
#include "marill.h"
#include "charmander.h"
#include "oddish.h"
#include "trees.h"
#include "screen.h"
#include "common.h"
#include "introPage.h"
#include "about.h"
#include "battle.h"
#include "imageLoader.h"  

//List variables
GLuint  tree,grass;

/* Local variables declaration */
int window1,window2,window3;
int screen = 999;
GLfloat rquad;
float x,y;
float deltaMove = 0.0; // initially camera doesn't move
int yo = 0,viewType = 0,battleButton = 0;;

// Camera direction
float lx = -1.0, ly = 2.0; // camera points initially along y-axis
float angle = 10.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

//Model objects
AshModel ash;
GaryModel gary;
PikachuModel pika;
MarillModel marill;
CharmanderModel charmander;
Tree T;

//texture arrays
GLuint texture[7];
GLuint pikaTexture[5],ashTexture[7],garyTexture[7],marillTexture[4];

GLvoid BuildLists()                                 // Build tree Display List
{
    Tree T;
    Model m;
    tree=glGenLists(2);
    glNewList(tree,GL_COMPILE); 
        T.drawTrees();
    glEndList();                                   // Done Building The tree List
    grass=glGenLists(2);                           // Build grass Display List
    glNewList(grass,GL_COMPILE); 
        m.drawGrass(1.0);
    glEndList();                                   // Done Building The grass List          
}
//---------------------------------------------------------------------------------------------------------
// Load Bitmaps And Convert To Textures
void LoadGLTextures() {	
    //system("mplayer Sound/103-title-main-theme-.mp3");
    ImageLoader imageLoader;

    imageLoader.ashImageLoad(ashTexture);
    imageLoader.pikachuImageLoad(pikaTexture);
    imageLoader.garyImageLoad(garyTexture);
    imageLoader.marillImageLoad(marillTexture);
    imageLoader.mainPageImageLoad(texture);
    
};
//----------------------------------------------------------------------------------------
void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar ){
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;
	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;
	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}
//----------------------------------------------------------------------------------------
int InitGL(int Width, int Height,float xx,float yy)	        // We call this right after our OpenGL window is created.
{
	system("killall -9 mplayer");
	system("mplayer -loop 0 Sound/champion-road.mp3 >> /dev/null &");
    x = xx;
    y = yy; // initially 5 units south of origin (backup)
	LoadGLTextures();
    BuildLists();
	glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping
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


void changeSize(int w, int h) {
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	perspectiveGL(45.0, ratio, 0.1, 100.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}
//------------------------------------------------------------------------------
void ReSizeGLScene(int Width, int Height){
	if (Height==0)				
		Height=1;
	glViewport(0, 0, Width, Height);		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void update(void) {
    if (isDragging) { 
        // only when dragging
        // update the change in angle
        angle += deltaAngle*0.6; 
        // camera's direction is set to angle
        lx = sin(angle);
        ly = -cos(angle);
        glLoadIdentity();
        gluLookAt(x, y, 1.0, 
              x + lx,y + ly,1.0,
           0.0f,1.0f,0.0f);
    }
	if (deltaMove) { // update camera position
        x = x + deltaMove*(lx)*0.2;           
        y = y + deltaMove*(ly)*0.2;
        pika.timer_walk(0);
        ash.timer_walk(0);
        glLoadIdentity();
        gluLookAt(x, y, 1.0, 
              x + lx,y + ly,1.0,
           0.0f,1.0f,0.0f);
    	}

	    glutPostRedisplay(); // redisplay everything
}

void processNormalKeys(unsigned char key, int xx, int yy){
	if (key == ESC || key == 'q' || key == 'Q') {
		system("killall -9 mplayer");
		exit(0);
	}	
	if (key == 'z'){ yo =1;}
	if (key == 'x'){ yo =0;}
    if (key == 'a'){ 
                        x -= 0.1;
                        pika.timer_walk(0);
                        ash.timer_walk(0);
                    }
    if (key == 'd'){ 
                        x += 0.1;
                        pika.timer_walk(0);
                        ash.timer_walk(0);
                    }
    if (key == 'n'){ 
                        lx -= 0.1;
                    }
    if (key == 'm'){ 
                        lx += 0.1;
                    }
    if (key == 'v'){ 
                       viewType = (viewType + 1)%4;
                    }
	if (key == 'b'){ 
                       battleButton = !battleButton;
                    }                                         
	if (key == 13){
		  //printf("Y: %d\n",ly);
          screen = 4;
          display();
        
	}
} 

void pressSpecialKey(int key, int xx, int yy){
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 1.0;break;
		case GLUT_KEY_DOWN : deltaMove = -1.0; break;
		case GLUT_KEY_LEFT : { // left mouse button pressed
                                deltaAngle = 0.03f;
								isDragging = 1; // start dragging
								xDragStart = x; // save x where button first pressed
								break;
							}
		case GLUT_KEY_RIGHT : { // left mouse button pressed
                                deltaAngle = -0.03f;
								isDragging = 1; // start dragging
								xDragStart = x; // save x where button first pressed
								break;
							}             					
	}
} 

void releaseSpecialKey(int key, int x, int y) 
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.0; break;
		case GLUT_KEY_DOWN : deltaMove = 0.0;break;
		case GLUT_KEY_LEFT : { // left mouse button pressed
                                if (deltaAngle < 0.0f) 
                                    deltaAngle = 0.0f;
								angle += deltaAngle; // update camera turning angle
								isDragging = 0; // no longer dragging
								break;
							}
		case GLUT_KEY_RIGHT : { // left mouse button pressed
                                if (deltaAngle > 0.0f) 
                                    deltaAngle = 0.0f;
								angle -= deltaAngle; // update camera turning angle
								isDragging = 0; // no longer dragging
								break;
							}					
	}
	
} 
//----------------------------------------------------------------------
// Process mouse drag events
// 
// This is called when dragging motion occurs. The variable
// angle stores the camera angle at the instance when dragging
// started, and deltaAngle is a additional angle based on the
// mouse movement since dragging started.
//----------------------------------------------------------------------
/*
void mouseMove(int x, int y) 
{ 	
	if (isDragging) { // only when dragging
		// update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;
		// camera's direction is set to angle + deltaAngle
		lx = -sin(angle + deltaAngle);
		ly = cos(angle + deltaAngle);
		//printf("lx : %f \t ly : %f\n",lx,ly);
		//glutPostRedisplay();
	}
}

void mouseButton(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
			glutPostRedisplay();
		}
		else  { 
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}
*/
void mouseButton(int button, int state, int x, int y) {
	int ax0=1093,ax1=1249, ay0=914,ay1=872;//enter 1058  y= 75 1148  y= 99
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			if(battleButton == 1){
				//printf("Main...DOWN: x=%3d  y=%3d \n", x, y);
				if(x>=ax0 && x<=ax1 && y>=ay1 && y<=ay0)
				{
					screen = 4;
		      		display();
				}
			}			
		}
	}
}

void newDisplay(){
	int i, j;
	float z =2.0;
	Model m;
	// Clear color and depth buffers
	glClearColor(0.0, 0.5, 1.0, 1.0); // sky color is light blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //PlaySound("242-champion-road.mp3", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

	// Reset transformations
	glLoadIdentity();
	// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	if(yo == 0){
		gluLookAt(
			x,      y,      1.0,
			x + lx, y + ly, 1.0,
			0.0,    0.0,    1.0);
	}else{
        gluLookAt(
            x+lx,      y+ly+5,      1.0,
            x, y, 1.0,
            0.0,    0.0,    1.0);
    }

	m.drawGround(texture[1]);

    glPushMatrix();
        m.drawRoute(texture[5]);
    glPopMatrix();   
                                                       // Draw trees
    glPushMatrix();
        glTranslatef(-12,-10.0,0.0);
        glCallList(tree);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(25,-10.0,0.0);
        glCallList(tree);
    glPopMatrix();
                                                     //grass
    glPushMatrix();
        glTranslatef(-3,5.0,0.0);
        for(i = -3; i < 3; i++)
            for(j = -3; j < 3; j++) {
                glPushMatrix();
                    glTranslatef(i*0.8,j*0.8 ,0.0);
                    glRotatef(85,1.0,0.0,0.0);
                    glCallList(grass);
                glPopMatrix();
            }
    glPopMatrix();
    glPushMatrix();
        glTranslatef(11,5.0,0.0);
        for(i = -3; i < 3; i++)
            for(j = -3; j < 3; j++) {
                glPushMatrix();
                    glTranslatef(i*0.8,j*0.8 ,0.0);
                    glRotatef(85,1.0,0.0,0.0);
                    glCallList(grass);
                glPopMatrix();
            }
    glPopMatrix();

    if(WIDTH == 1280 && HEIGHT == 1024){         //display "battle" button
            //printf("Y : %f\n",y);
        if(y > 23.542894) battleButton = 1;

        if(battleButton == 1){
            Battle battle;
            glColor3f(1.0,1.0,1.0);
            battle.drawString(1100,890,"BATTLE !");
            glPushMatrix();
                glColor3f(0.0,0.2,0.5);
                glTranslatef(x,y,0.0);
                glRotatef(angle* 57.2957795, 0,0,1);
                glPushMatrix();                                      
                    glRotatef(90,1.0,0.0,0.0);
                    //glScalef(0.075,0.075,0.075);
                    glScalef(0.4,0.2,0.5);
                    glTranslatef(-3.5,0.1,6.0);
                    glPushMatrix();
                         glRotatef(90,1.0,0.0,0.0);
                         m.rectangle();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        }    
    }


   if(viewType == 0){                                             //move both ash and pikachu(on shoulder)
        glPushMatrix();
        glTranslatef(x,y,0.0);
        glRotatef(angle* 57.2957795, 0,0,1);
        glPushMatrix();                                       //ash ketchum
            glRotatef(90,1.0,0.0,0.0);
            //glRotatef(180,0.0,1.0,0.0);
            glScalef(0.075,0.075,0.075);
            glTranslatef(0,6.0,40.0);
            //glRotatef(angle* 57.2957795, 0,1,0);
            glPushMatrix();
                glRotatef(180,0.0,1.0,0.0);
                ash.enableShade();
                ash.drawCyborg(ashTexture[0],ashTexture[1],ashTexture[2],ashTexture[3],ashTexture[4],ashTexture[5],ashTexture[6]);
                ash.disableShade();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();    

    glPushMatrix();
        glTranslatef(x,y,0.0);
        glRotatef(angle* 57.2957795, 0,0,1);
        glPushMatrix();                                       //pickachu
            glRotatef(90,1.0,0.0,0.0);
            glScalef(0.15,0.15,0.15);
            //glTranslatef(-3.0,0.0,19.0);   --down 
            //glScalef(0.3,0.3,0.3);         --down
            glTranslatef(-0.7,5.2,19.5);      //shoulder
            glScalef(0.3,0.3,0.3);
            glPushMatrix();
                glRotatef(180,0.0,1.0,0.0);
                pika.enableShade();
                pika.drawCyborg(pikaTexture[0],pikaTexture[1],pikaTexture[2],pikaTexture[3],pikaTexture[4]);
                pika.disableShade();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();    
   }else if(viewType == 1){                                             //move both ash and pikachu(on ground)
        glPushMatrix();
        glTranslatef(x,y,0.0);
        glRotatef(angle* 57.2957795, 0,0,1);
        glPushMatrix();                                       //ash ketchum
            glRotatef(90,1.0,0.0,0.0);
            //glRotatef(180,0.0,1.0,0.0);
            glScalef(0.075,0.075,0.075);
            glTranslatef(0,6.0,40.0);
            //glRotatef(angle* 57.2957795, 0,1,0);
            glPushMatrix();
                glRotatef(180,0.0,1.0,0.0);
                ash.enableShade();
                ash.drawCyborg(ashTexture[0],ashTexture[1],ashTexture[2],ashTexture[3],ashTexture[4],ashTexture[5],ashTexture[6]);
                ash.disableShade();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();    

    glPushMatrix();
        glTranslatef(x,y,0.0);
        glRotatef(angle* 57.2957795, 0,0,1);
        glPushMatrix();                                       //pickachu
            glRotatef(90,1.0,0.0,0.0);
            glScalef(0.15,0.15,0.15);
            glTranslatef(-3.0,0.5,19.0);   //--down 
            glScalef(0.3,0.3,0.3);         //--down
            //glTranslatef(-0.7,5.2,19.5);      //shoulder
            //glScalef(0.3,0.3,0.3);
            glPushMatrix();
                glRotatef(180,0.0,1.0,0.0);
                pika.enableShade();
                pika.drawCyborg(pikaTexture[0],pikaTexture[1],pikaTexture[2],pikaTexture[3],pikaTexture[4]);
                pika.disableShade();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();          
   }else if(viewType == 2){                                   //move onli ash
        glPushMatrix();
        glTranslatef(x,y,0.0);
        glRotatef(angle* 57.2957795, 0,0,1);
        glPushMatrix();                                       //ash ketchum
            glRotatef(90,1.0,0.0,0.0);
            //glRotatef(180,0.0,1.0,0.0);
            glScalef(0.075,0.075,0.075);
            glTranslatef(0,6.0,40.0);
            //glRotatef(angle* 57.2957795, 0,1,0);
            glPushMatrix();
                glRotatef(180,0.0,1.0,0.0);
                ash.enableShade();
                ash.drawCyborg(ashTexture[0],ashTexture[1],ashTexture[2],ashTexture[3],ashTexture[4],ashTexture[5],ashTexture[6]);
                ash.disableShade();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix(); 
   }else if(viewType == 3){                     //move onli pikachu
        glPushMatrix();
        glTranslatef(x,y,0.0);
        glRotatef(angle* 57.2957795, 0,0,1);
        glPushMatrix();                                       //pickachu
            glRotatef(90,1.0,0.0,0.0);
            glScalef(0.15,0.15,0.15);
            //glTranslatef(-3.0,6.0,18.0);
            glTranslatef(-3.0,0.5,19.0);
           glScalef(0.3,0.3,0.3);
            glPushMatrix();
                glRotatef(180,0.0,1.0,0.0);
                pika.enableShade();
                pika.drawCyborg(pikaTexture[0],pikaTexture[1],pikaTexture[2],pikaTexture[3],pikaTexture[4]);
                pika.disableShade();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();    
   }
    
	glPushMatrix();                                       //gary
		glRotatef(90,1.0,0.0,0.0);
		glRotatef(180,0.0,1.0,0.0);
		glScalef(0.08,0.08,0.08);  //garys
		glTranslatef(-40,6.0,500); //garys
		glRotatef(0,0.0,1.0,0.0);
		 gary.enableShade();
        gary.drawCyborg(garyTexture[0],garyTexture[1],garyTexture[2],garyTexture[3],garyTexture[4],garyTexture[5],garyTexture[6]);
        gary.disableShade();
	glPopMatrix();

	glPushMatrix();                                       //marill
		glRotatef(90,1.0,0.0,0.0);
		glRotatef(180,0.0,1.0,0.0);
		glScalef(0.1,0.1,0.1);
		glTranslatef(-41,0.0,400);               //near gary
		glRotatef(0,0.0,1.0,0.0);              //near gary
		marill.enableShade();
		marill.drawCyborg(marillTexture[0],marillTexture[1],marillTexture[2],marillTexture[3]);
		marill.disableShade();
	glPopMatrix();

 	glPushMatrix();
		glTranslatef(3.5, 32.0, 0);
		m.drawStadium(texture[0],texture[1],texture[2],texture[3]);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		m.drawBuildings(30,30,0,10,texture[5]);
		glColor3f(0.5, 0.4, 0.4);
		m.drawBuildings(20,40,0,8,texture[6]);		
		glColor3f(0.3, 0.3, 0.3);
		m.drawBuildings(-50,40,4,25,texture[5]);
		glColor3f(0.3, 0.1, 0.3);
		m.drawBuildings(-30,80,8,30,texture[6]);
		glColor3f(0.4, 0.4, 0.5);
		m.drawBuildings(20,70,12,40,texture[5]);
	glPopMatrix();	

	glPushMatrix();
		glTranslatef(3.5, 32.0, 0);
		m.drawSignBoard(texture[4]);
	glPopMatrix();
                     
	glPushMatrix();                                   //tree1
		glTranslatef(-10.0, 18.0, 0);
		m.drawCylinder(3.0,texture[1]);	
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10.0, 18.0, 3.0);
		m.drawCone(4.0,texture[1]);
	glPopMatrix();
  	glPushMatrix();
    	glTranslatef(-10.0, 18.0, 6.0);
    	m.drawCone(4.0,texture[1]);
  	glPopMatrix();

  	glPushMatrix();                                   //tree2
    	glTranslatef(17.0, 18.0, 0);
    	m.drawCylinder(3.0,texture[1]);  
  	glPopMatrix();
  	glPushMatrix();
    	glTranslatef(17.0, 18.0, 3.0);
    	m.drawCone(4.0,texture[1]);
  	glPopMatrix();
  	glPushMatrix();
    	glTranslatef(17.0, 18.0, 6.0);
    	m.drawCone(4.0,texture[1]);
  	glPopMatrix();

	glutSwapBuffers(); // Make it all visible

}

void display(){
	if(screen == 2){
		About::screen12();
		glutKeyboardFunc(About::keyPressed);
		glutMouseFunc(About::mouse);
		glutPostRedisplay();
	}
	else if(screen == 1){

		//IntroWindow::init(SCREEN_W , SCREEN_H);
		IntroWindow::main_screen();
		glutKeyboardFunc(IntroWindow::keyPressed);
		glutMouseFunc(IntroWindow::mouse);
		glutPostRedisplay();
	}
	else if(screen == 3){
		glutDestroyWindow(window1);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(SCREEN_W , SCREEN_H );
		glutInitWindowPosition(10,10);
		window2 = glutCreateWindow("Pokemon Sky Blue 3D Version");
        glutFullScreen();
		LoadGLTextures();				// Load The Texture(s) 
	    glEnable(GL_TEXTURE_2D);			// Enable Texture Mapping

		// register callbacks
		glutReshapeFunc(changeSize); // window reshape callback
		glutDisplayFunc(newDisplay); // (re)display callback
		glutIdleFunc(update); // incremental update 
		//glutIdleFunc(newDisplay);
		glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
		glutMouseFunc(mouseButton); // process mouse button push/release
		//glutMotionFunc(mouseMove); // process mouse dragging motion
		glutKeyboardFunc(processNormalKeys); // process standard key clicks
		glutSpecialFunc(pressSpecialKey); // process special key pressed
							// Warning: Nonstandard function! Delete if desired.
		glutSpecialUpFunc(releaseSpecialKey); // process special key release

		// OpenGL init
		glEnable(GL_DEPTH_TEST);
		//InitGL(640, 480);
		InitGL(SCREEN_W , SCREEN_H ,4.0,-30.0);
		// enter GLUT event processing cycle
		glutMainLoop();
	}
	else if(screen == 4){
		Battle b;
        glutDestroyWindow(window2);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        //glutInitWindowPosition(100, 100);
        glutInitWindowSize(SCREEN_W , SCREEN_H);
        glutInitWindowPosition(10,10);
        window3 = glutCreateWindow("Pokemon Sky Blue 3D Version : Battle");
        //glutGameModeString("1366x768");
        //glutEnterGameMode();
        glutFullScreen();
        // register callbacks
        glutReshapeFunc(Battle::changeSize); // window reshape callback
        glutDisplayFunc(Battle::main_screen); // (re)display callback
        glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
        glutMouseFunc(Battle::mouse); // process mouse button push/release
        glutKeyboardFunc(Battle::keyPressed); // process standard key clicks
        glEnable(GL_DEPTH_TEST);
        Battle::InitGL(SCREEN_W , SCREEN_H);
        // enter GLUT event processing cycle
        glutMainLoop();

	}else if(screen == 5){
        glutDestroyWindow(window3);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowSize(SCREEN_W , SCREEN_H );
        glutInitWindowPosition(10,10);
        window2 = glutCreateWindow("Pokemon Sky Blue 3D Version");
        glutFullScreen();
        LoadGLTextures();               // Load The Texture(s) 
        glEnable(GL_TEXTURE_2D);            // Enable Texture Mapping

        // register callbacks
        glutReshapeFunc(changeSize); // window reshape callback
        glutDisplayFunc(newDisplay); // (re)display callback
        glutIdleFunc(update); // incremental update 
        //glutIdleFunc(newDisplay);
        glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
        glutMouseFunc(mouseButton); // process mouse button push/release
        //glutMotionFunc(mouseMove); // process mouse dragging motion
        glutKeyboardFunc(processNormalKeys); // process standard key clicks
        glutSpecialFunc(pressSpecialKey); // process special key pressed
                            // Warning: Nonstandard function! Delete if desired.
        glutSpecialUpFunc(releaseSpecialKey); // process special key release

        // OpenGL init
        glEnable(GL_DEPTH_TEST);
        //InitGL(640, 480);
        InitGL(SCREEN_W , SCREEN_H ,4.0,25.0);
        // enter GLUT event processing cycle
        glutMainLoop();
    }
	else{
		IntroWindow intro;
		glutKeyboardFunc(IntroWindow::keyPressed);
		glutMouseFunc(IntroWindow::mouse);
		intro.main_screen();
		glutPostRedisplay();
	}
}

int main(int argc,char** argv)
{
	CommonFunctions c;
    printf("\n\
-----------------------------------------------------------------------\n\
  \t\t\t\tPokemon SkyBlue 3D Version\n\
  \n\
 - Hold Arrow keys to move\n\
 - Press 'z' to change camera to front view\n\
 - Press 'x' to change camera back to third person view\n\
 - Go on pressing 'v' to change view type\n\
 \n\
 - Press 'ENTER' to enter battle\n\
  \n\
 - Attacks Keys:\n\
      * Pikachu    : 'z'-Thunderbolt  'x'-Lightball\n\
      * Oddish     : 'm'-RazorLeaf\n\
      * Marill     : 'a'-Bubble       's'-Icebeam\n\
      * Charmander : 'l'-Ember\n\
  \n\   
 - Press 'q' or 'ESC' to quit\n\
  \
-----------------------------------------------------------------------\n");
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(SCREEN_W , SCREEN_H );  
	glutInitWindowPosition(0, 0);  
	window1 = glutCreateWindow("Main Page");
	glutFullScreen();
	glutDisplayFunc(display);
	IntroWindow::init(SCREEN_W , SCREEN_H);
	About::init(SCREEN_W , SCREEN_H);
	c.init();
	glutMainLoop();
}