#ifndef _ASHKETCHUM_H_
#define _ASHKETCHUM_H_

bool flag1=true, flag2=false, 
	 flag3=true, flag4=false,
	 flag5=true, flag6=false,
	 hflag=true;

/*
Initialization of AshModel parts' angles
*/
static GLfloat theta[17] = {0.0,   0.0,   0.0, 90.0,
							-20.0, 90.0, -20.0, 180.0,
							0.0, 180.0, 0.0, 0.0,
						    0.0, 0.0,  0.0, 0.0, 
							0.0
							};
static GLint choise = 2;
static GLint m_choise = 0;

/*
AshModel parts
*/
GLUquadricObj *t,   *h,   *n,    *lh,
			 *rh,   *lf,  *rf,   *jp,
			 *lhnd, *lft, *lua,  *lla,
			 *rua,  *rla, *lll,  *rll, 
			 *rul,  *lul, *rhnd, *rft;
/*
Mouse control area & view point translation initialization
*/
typedef struct _area {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
} area;

area translation[5] = {
    { 0, 120, 40, -30.0, 30.0, 0.0, 0.05,},
    { 1, 180, 40, -30.0, 30.0, 0.0, 0.05,},
    { 2, 180, 40, -200.0, 200.0, 0.0, 0.1,},
	{ 3, 180, 120, -100, 100, 0.0, 0.5},
	{ 4, 240, 120, -100, 100, 0.0, 0.5}
};
/*
gluLookAt initial values, view point rotation
*/
GLfloat eye[3] = { 0.0, 0.0, 60.0 };
GLfloat at[3]  = { 0.0, 0.0, 0.0 };
GLfloat up[3]  = { 0.0, 1.0, 0.0 };

/*
Animation variables and angles
*/
GLuint texture1=0; 
GLuint texture2=0;
GLuint texture3=0;
GLuint texture4=0;

GLuint old_thetaW3=0;
GLuint old_thetaX4=0;
GLuint old_thetaE5=0;
GLuint old_thetaC6=0;
GLuint old_thetaS11=0;
GLuint old_thetaD12=0;

GLint selection = 0;

void redisplay_all(void);

class AshModel{
	public:
		AshModel(){}
		~AshModel(){}
		void head(GLuint texture1,GLuint texture2);
		void cap();
		void neck(GLuint texture,GLuint texture2);
		void torso(GLuint texture);
		void joint_point(GLuint texture);
		void joint_point2();
		void left_upper_arm();
		void left_lower_arm(GLuint texture);
		void left_hand(GLuint texture);
		void right_upper_arm();
		void right_lower_arm(GLuint texture);
		void right_hand(GLuint texture);
		void left_upper_leg(GLuint texture);
		void left_lower_leg(GLuint texture);
		void left_foot();
		void right_upper_leg(GLuint texture);
		void right_lower_leg(GLuint texture);
		void right_foot();

		void drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5,GLuint texture6,GLuint texture7);
		void enableShade();
			
		void disableShade();
		static void timer_walk(int nm);
};

#include "ashKetchum.cpp"

#endif
