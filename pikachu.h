#ifndef _PIKACHU_H_
#define _PIKACHU_H_

/*
Define of humanoid PickachuModel properties 
*/
#define WIN_WIDTH_PIKA 800
#define WIN_HEIGHT_PIKA 800
#define TORSO_HEIGHT_PIKA 2.5
#define TORSO_RADIUS_PIKA 1.0
#define UPPER_ARM_HEIGHT_PIKA 1.0
#define LOWER_ARM_HEIGHT_PIKA 1.3
#define UPPER_ARM_RADIUS_PIKA  0.2
#define LOWER_ARM_RADIUS_PIKA  0.0
#define UPPER_LEG_RADIUS_PIKA  0.0
#define LOWER_LEG_RADIUS_PIKA  0.0
#define LOWER_LEG_HEIGHT_PIKA 1.1
#define UPPER_LEG_HEIGHT_PIKA 0.0
#define EAR_HEIGHT_PIKA 2.0
#define EAR_RADIUS_PIKA 0.3
#define TAIL_RADIUS_PIKA  0.5
#define TAIL_HEIGHT_PIKA 3.3
#define HEAD_HEIGHT_PIKA 1.2
#define HEAD_RADIUS_PIKA 1.2
#define HAND_RADIUS_PIKA 0.0
#define HAND_HEIGHT_PIKA 0.3
#define FOOT_RADIUS_PIKA 0.2
#define FOOT_HEIGHT_PIKA 0.5
#define NECK_RADIUS_PIKA 0.2
#define NECK_HEIGHT_PIKA 0.1
#define JOINT_POINT_RADIUS_PIKA 0.1
#define JOINT_POINT_HEIGHT_PIKA 0.1



bool flag11=true, flag12=false, 
	 flag13=true, flag14=false,
	 flag15=true, flag16=false,
	 hflag1=true;

	/*
	Initialization of PickachuModel parts' angles
	*/
	static GLfloat theta1[17] = {0.0,   0.0,   0.0, 90.0,
								-20.0, 90.0, -20.0, 180.0,
								0.0, 180.0, 0.0, 0.0,
							    0.0, 0.0,  0.0, 0.0, 
								0.0
								};

	/*
	PickachuModel parts
	*/
	GLUquadricObj *t1,   *h1,   *n1,    *lh1,
				 *rh1,   *lf1,  *rf1,   *jp1,
				 *lhnd1, *lft1, *lua1,  *lla1,
				 *rua1,  *rla1, *lll1,  *rll1, 
				 *rul1,  *lul1, *rhnd1, *rft1;
	/*
	Mouse control area & view point translation initialization
	*/
	typedef struct _area1 {
	    int id;
	    int x, y;
	    float min, max;
	    float value;
	    float step;
	} area1;

	area1 translation1[5] = {
	    { 0, 120, 40, -30.0, 30.0, 0.0, 0.05,},
	    { 1, 180, 40, -30.0, 30.0, 0.0, 0.05,},
	    { 2, 180, 40, -200.0, 200.0, 0.0, 0.1,},
		{ 3, 180, 120, -100, 100, 0.0, 0.5},
		{ 4, 240, 120, -100, 100, 0.0, 0.5}
	};

	/*
	Animation variables and angles
	*/
	GLuint texture11=0; 
	GLuint texture12=0;
	GLuint texture13=0;
	GLuint texture14=0;

	GLint selection1 = 0;

	void redisplay_all(void);

class PikachuModel{
	public:
		PikachuModel(){}
		~PikachuModel(){}
		void head(GLuint texture);
		void right_ear(GLuint texture);
		void left_ear(GLuint texture);
		void neck();
		void torso(GLuint texture);
		void joint_point();
		void left_upper_arm(GLuint texture);
		void left_lower_arm();
		void left_hand();
		void right_upper_arm(GLuint texture);
		void right_lower_arm();
		void right_hand();
		void left_upper_leg();
		void left_lower_leg();
		void left_foot(GLuint texture);
		void right_upper_leg();
		void right_lower_leg();
		void right_foot(GLuint texture);
		void tail(GLuint texture);
		void drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5);
		void enableShade();	
		void disableShade();
		static void timer_walk(int nm);
};

#include "pikachu.cpp"

#endif
