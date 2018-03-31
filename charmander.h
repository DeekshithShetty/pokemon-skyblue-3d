#ifndef _CHARMANDER_H_
#define _CHARMANDER_H_

#define WIN_WIDTH_CHAR 800
#define WIN_HEIGHT_CHAR 800

#define TORSO_HEIGHT_CHAR 1.5
#define TORSO_RADIUS_CHAR 1.5
#define UPPER_ARM_HEIGHT_CHAR 2.0
#define LOWER_ARM_HEIGHT_CHAR 0.0
#define UPPER_ARM_RADIUS_CHAR  0.5
#define LOWER_ARM_RADIUS_CHAR  0.4
#define UPPER_LEG_RADIUS_CHAR  0.6
#define LOWER_LEG_RADIUS_CHAR  0.6
//#define LOWER_LEG_HEIGHT_CHAR 2.5
#define LOWER_LEG_HEIGHT_CHAR 0.0
#define UPPER_LEG_HEIGHT_CHAR 3.0
#define HEAD_HEIGHT_CHAR 1.2
#define HEAD_RADIUS_CHAR 1.0
#define HAND_RADIUS_CHAR 0.4
#define HAND_HEIGHT_CHAR 0.8
#define FOOT_RADIUS_CHAR 0.3
#define FOOT_HEIGHT_CHAR 1.1
#define NECK_RADIUS_CHAR 0.6
#define NECK_HEIGHT_CHAR 0.6
#define JOINT_POINT_RADIUS_CHAR 0.4
#define JOINT_POINT_HEIGHT_CHAR 0.5
#define TAIL_RADIUS_CHAR  0.8
#define TAIL_HEIGHT_CHAR 6.0

/*
Initialization of CharmanderModel parts' angles
*/
static GLfloat thetaC[17] = {0.0,   0.0,   0.0, 90.0,
							-20.0, 90.0, -20.0, 180.0,
							0.0, 180.0, 0.0, 0.0,
						    0.0, 0.0,  0.0, 0.0, 
							0.0
							};

/*
CharmanderModel parts
*/
GLUquadricObj *tC,   *hC,   *nC,    *lhC,
			 *rhC,   *lfC,  *rfC,   *jpC,
			 *lhndC, *lftC, *luaC,  *llaC,
			 *ruaC,  *rlaC, *lllC,  *rllC, 
			 *rulC,  *lulC, *rhndC, *rftC;

class CharmanderModel{
	public:
		CharmanderModel(){}
		~CharmanderModel(){}
		void head(GLuint texture1,GLuint texture2);
		void neck(GLuint texture);
		void torso(GLuint texture);
		void joint_point(GLuint texture);
		void joint_point2();
		void left_upper_arm(GLuint texture);
		void left_hand();
		void right_upper_arm(GLuint texture);
		void right_hand();
		void left_upper_leg(GLuint texture);
		void left_lower_leg(GLuint texture);
		void left_foot();
		void right_upper_leg(GLuint texture);
		void right_lower_leg(GLuint texture);
		void right_foot();
		void tail(GLuint texture1,GLuint texture2);
		void drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5);
		void enableShade();
		void disableShade();
};

#include "charmander.cpp"

#endif
