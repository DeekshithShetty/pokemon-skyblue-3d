#ifndef _ODDISH_H_
#define _ODDISH_H_

/*
Define of humanoid PickachuModel properties 
*/
#define WIN_WIDTH_ODDISH 800
#define WIN_HEIGHT_ODDISH 800
#define TORSO_HEIGHT_ODDISH 1.9
#define TORSO_RADIUS_ODDISH 1.0
#define UPPER_ARM_HEIGHT_ODDISH 0.7
#define LOWER_ARM_HEIGHT_ODDISH 1.3
#define UPPER_ARM_RADIUS_ODDISH  0.2
#define LOWER_ARM_RADIUS_ODDISH  0.0
#define UPPER_LEG_RADIUS_ODDISH  0.0
#define LOWER_LEG_RADIUS_ODDISH  0.0
#define LOWER_LEG_HEIGHT_ODDISH_ODDISH 1.1
#define UPPER_LEG_HEIGHT_ODDISH 0.0
#define EAR_HEIGHT_ODDISH 2.9
#define EAR_RADIUS_ODDISH 0.4
#define HEAD_HEIGHT_ODDISH 0.4
#define HEAD_RADIUS_ODDISH 1.0
#define HAND_RADIUS_ODDISH 0.0
#define HAND_HEIGHT_ODDISH 0.3
#define FOOT_RADIUS_ODDISH 0.2
#define FOOT_HEIGHT_ODDISH 0.5
#define NECK_RADIUS_ODDISH 0.2
#define NECK_HEIGHT_ODDISH 0.1
#define JOINT_POINT_RADIUS_ODDISH 0.0
#define JOINT_POINT_HEIGHT_ODDISH 0.1

	/*
	Initialization of PickachuModel parts' angles
	*/
static GLfloat thetaO[17] = {0.0,   0.0,   0.0, 90.0,
							-20.0, 90.0, -20.0, 180.0,
							0.0, 180.0, 0.0, 0.0,
							   0.0, 0.0,  0.0, 0.0, 
							0.0
							};

	/*
	PickachuModel parts
	*/
	GLUquadricObj *tO,   *hO,   *nO,    *lhO,
				 *rhO,   *lfO,  *rfO,   *jpO,
				 *lhndO, *lftO, *luaO,  *llaO,
				 *ruaO,  *rlaO, *lllO,  *rllO, 
				 *rulO,  *lulO, *rhndO, *rftO;

class OddishModel{
	public:
		OddishModel(){}
		~OddishModel(){}
		void head(GLuint texture);
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
		void drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3);
		void enableShade();	
		void disableShade();
};

#include "oddish.cpp"

#endif				 
