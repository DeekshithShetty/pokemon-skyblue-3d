#ifndef _MARILL_H_
#define _MARILL_H_

/*
Define of humanoid PickachuModel properties 
*/
#define WIN_WIDTH_MARILL 800
#define WIN_HEIGHT_MARILL 800
#define TORSO_HEIGHT_MARILL 2.5
#define TORSO_RADIUS_MARILL 1.5
#define UPPER_ARM_HEIGHT_MARILL 0.7
#define LOWER_ARM_HEIGHT_MARILL 1.3
#define UPPER_ARM_RADIUS_MARILL  0.2
#define LOWER_ARM_RADIUS_MARILL  0.0
#define UPPER_LEG_RADIUS_MARILL  0.0
#define LOWER_LEG_RADIUS_MARILL  0.0
#define LOWER_LEG_HEIGHT_MARILL_MARILL 1.1
#define UPPER_LEG_HEIGHT_MARILL 0.0
#define EAR_HEIGHT_MARILL 2.9
#define EAR_RADIUS_MARILL 0.4
#define TAIL_RADIUS_MARILL  0.7
#define TAIL_HEIGHT_MARILL 3.3
#define HEAD_HEIGHT_MARILL 1.0
#define HEAD_RADIUS_MARILL 1.0
#define HAND_RADIUS_MARILL 0.0
#define HAND_HEIGHT_MARILL 0.3
#define FOOT_RADIUS_MARILL 0.2
#define FOOT_HEIGHT_MARILL 0.5
#define NECK_RADIUS_MARILL 0.2
#define NECK_HEIGHT_MARILL 0.1
#define JOINT_POINT_RADIUS_MARILL 0.0
#define JOINT_POINT_HEIGHT_MARILL 0.1



bool flag1M=true, flag2M=false, 
	 flag3M=true, flag4M=false,
	 flag5M=true, flag6M=false,
	 hflagM=true;

	/*
	Initialization of PickachuModel parts' angles
	*/
	static GLfloat thetaM[17] = {0.0,   0.0,   0.0, 90.0,
								-20.0, 90.0, -20.0, 180.0,
								0.0, 180.0, 0.0, 0.0,
							    0.0, 0.0,  0.0, 0.0, 
								0.0
								};

	/*
	PickachuModel parts
	*/
	GLUquadricObj *tM,   *hM,   *nM,    *lhM,
				 *rhM,   *lfM,  *rfM,   *jpM,
				 *lhndM, *lftM, *luaM,  *llaM,
				 *ruaM,  *rlaM, *lllM,  *rllM, 
				 *rulM,  *lulM, *rhndM, *rftM;

class MarillModel{
	public:
		MarillModel(){}
		~MarillModel(){}
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
		void drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4);
		void enableShade();	
		void disableShade();
		static void timer_walk(int nm);
};

#include "marill.cpp"

#endif				 
