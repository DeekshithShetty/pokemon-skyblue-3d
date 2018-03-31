#ifndef _GARY_H_
#define _GARY_H_


#define UPPER_ARM_RADIUS_GARY  0.5
#define LOWER_ARM_RADIUS_GARY  0.5
#define HEAD_HEIGHT_GARY 1.1
#define HEAD_RADIUS_GARY 0.8

bool flag1G=true, flag2G=false, 
	 flag3G=true, flag4G=false,
	 flag5G=true, flag6G=false,
	 hflagG=true;

/*
Initialization of body parts' angles
*/
static GLfloat thetaG[17] = {0.0,   0.0,   0.0, 90.0,
							-20.0, 90.0, -20.0, 180.0,
							0.0, 180.0, 0.0, 0.0,
						    0.0, 0.0,  0.0, 0.0, 
							0.0
							};
static GLint choiseG = 2;
static GLint m_choiseG = 0;

/*
Body parts
*/
GLUquadricObj *tG,   *hG,   *nG,    *lhG,
			 *rhG,   *lfG,  *rfG,   *jpG,
			 *lhndG, *lftG, *luaG,  *llaG,
			 *ruaG,  *rlaG, *lllG,  *rllG, 
			 *rulG,  *lulG, *rhndG, *rftG;
/*
Mouse control area & view point translation initialization
*/
typedef struct _areaG {
    int id;
    int x, y;
    float min, max;
    float value;
    float step;
} areaG;

area translationG[5] = {
    { 0, 120, 40, -30.0, 30.0, 0.0, 0.05,},
    { 1, 180, 40, -30.0, 30.0, 0.0, 0.05,},
    { 2, 180, 40, -200.0, 200.0, 0.0, 0.1,},
	{ 3, 180, 120, -100, 100, 0.0, 0.5},
	{ 4, 240, 120, -100, 100, 0.0, 0.5}
};

/*
gluLookAt initial values, view point rotation
*/
GLfloat eyeG[3] = { 0.0, 0.0, 60.0 };
GLfloat atG[3]  = { 0.0, 0.0, 0.0 };
GLfloat upG[3]  = { 0.0, 1.0, 0.0 };

/*
Animation variables and angles
*/
GLuint texture1G=0; 
GLuint texture2G=0;
GLuint texture3G=0;
GLuint texture4G=0;

GLuint old_thetaW3G=0;
GLuint old_thetaX4G=0;
GLuint old_thetaE5G=0;
GLuint old_thetaC6G=0;
GLuint old_thetaS11G=0;
GLuint old_thetaD12G=0;

GLint selectionG = 0;

void redisplay_all(void);

class GaryModel{
	public:
		GaryModel(){}
		~GaryModel(){}
		void head(GLuint texture1,GLuint texture2);
		void neck(GLuint texture);
		void torso(GLuint texture);
		void joint_point(GLuint texture);
		void joint_point2(GLuint texture);
		void left_upper_arm(GLuint texture);
		void left_lower_arm(GLuint texture);
		void left_hand(GLuint texture);
		void right_upper_arm(GLuint texture);
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
		void pointHand();
		static void timer_walk(int nm);
};

#include "gary.cpp"

#endif
