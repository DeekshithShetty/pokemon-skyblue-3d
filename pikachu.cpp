//================================Humanoid Robot====================================
#include "headers.h"


void PikachuModel::head(GLuint texture){
	glPushMatrix();
	glColor3f (1.0, 0.0, 5.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glRotatef(15.0, 0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
		h1 = gluNewQuadric();
		gluQuadricNormals(h1, GLU_SMOOTH);
		gluQuadricTexture(h1, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		glScalef(HEAD_HEIGHT_PIKA, HEAD_HEIGHT_PIKA, HEAD_RADIUS_PIKA);
		gluSphere(h1,1.0,10,10);
	glDisable(GL_TEXTURE_2D);  
	glPopMatrix();
}
void PikachuModel::right_ear(GLuint texture){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 1.0, -1.0);
	glEnable(GL_TEXTURE_2D);
	n1 = gluNewQuadric();
	gluQuadricNormals(n1, GLU_SMOOTH);
	gluQuadricTexture(n1, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluCylinder(n1,EAR_RADIUS_PIKA, 0.0, EAR_HEIGHT_PIKA,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void PikachuModel::left_ear(GLuint texture){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	n1 = gluNewQuadric();
	gluQuadricNormals(n1, GLU_SMOOTH);
	gluQuadricTexture(n1, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluCylinder(n1,EAR_RADIUS_PIKA, 0.0, EAR_HEIGHT_PIKA,10,10);
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
}
void PikachuModel::neck(){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(n1,NECK_RADIUS_PIKA, NECK_RADIUS_PIKA, NECK_HEIGHT_PIKA,10,10);
	glPopMatrix();
}
void PikachuModel::torso(GLuint texture){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	t1 = gluNewQuadric();
	gluQuadricNormals(t1, GLU_SMOOTH);
	gluQuadricTexture(t1, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(t1,TORSO_RADIUS_PIKA, TORSO_RADIUS_PIKA, TORSO_HEIGHT_PIKA,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
/*
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(t1,TORSO_RADIUS_PIKA, TORSO_RADIUS_PIKA, TORSO_HEIGHT_PIKA,10,10);
	glPopMatrix();*/
}
void PikachuModel::joint_point(){
	glPushMatrix();
	glScalef(JOINT_POINT_RADIUS_PIKA, JOINT_POINT_HEIGHT_PIKA, 
		JOINT_POINT_RADIUS_PIKA);
	gluSphere(jp1,1.0,10,10);
	glPopMatrix();
}
void PikachuModel::left_upper_arm(GLuint texture){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
		lua1 = gluNewQuadric();
		gluQuadricNormals(lua1, GLU_SMOOTH);
		gluQuadricTexture(lua1, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		gluCylinder(lua1,UPPER_ARM_RADIUS_PIKA, UPPER_ARM_RADIUS_PIKA, 
		UPPER_ARM_HEIGHT_PIKA,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void PikachuModel::left_lower_arm(){
	glPushMatrix();
	glRotatef(0.0, 1.0, 0.0, 0.0);
	gluCylinder(lla1,LOWER_ARM_RADIUS_PIKA, LOWER_ARM_RADIUS_PIKA, 
		LOWER_ARM_HEIGHT_PIKA,10,10);
	//glRotateflPopMatrix();
	glPopMatrix();
}
void PikachuModel::left_hand(){
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(HAND_RADIUS_PIKA, HAND_HEIGHT_PIKA, HAND_RADIUS_PIKA);
	gluSphere(lhnd1,1.0,10,10);
	glPopMatrix();
}
void PikachuModel::right_upper_arm(GLuint texture){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
		rua1 = gluNewQuadric();
		gluQuadricNormals(rua1, GLU_SMOOTH);
		gluQuadricTexture(rua1, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		gluCylinder(rua1,UPPER_ARM_RADIUS_PIKA, UPPER_ARM_RADIUS_PIKA, 
			UPPER_ARM_HEIGHT_PIKA,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void PikachuModel::right_lower_arm(){
	glPushMatrix();
	gluCylinder(rla1,LOWER_ARM_RADIUS_PIKA, LOWER_ARM_RADIUS_PIKA, 
		LOWER_ARM_HEIGHT_PIKA,10,10);
	glPopMatrix();
}
void PikachuModel::right_hand(){
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(HAND_RADIUS_PIKA, HAND_HEIGHT_PIKA, HAND_RADIUS_PIKA);
	gluSphere(rhnd1,1.0,10,10);
	glPopMatrix();
}
void PikachuModel::left_upper_leg(){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lul1,UPPER_LEG_RADIUS_PIKA, UPPER_LEG_RADIUS_PIKA, 
		UPPER_LEG_HEIGHT_PIKA,10,10);
	glPopMatrix();
}
void PikachuModel::left_lower_leg(){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lll1,LOWER_LEG_RADIUS_PIKA, LOWER_LEG_RADIUS_PIKA, 
		LOWER_LEG_HEIGHT_PIKA,10,10);
	glPopMatrix();
}
void PikachuModel::left_foot(GLuint texture){
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
		lft1 = gluNewQuadric();
		gluQuadricNormals(lft1, GLU_SMOOTH);
		gluQuadricTexture(lft1, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		glScalef(FOOT_RADIUS_PIKA, FOOT_HEIGHT_PIKA, FOOT_RADIUS_PIKA);
		gluSphere(lft1,1.0,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void PikachuModel::right_upper_leg(){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rul1,UPPER_LEG_RADIUS_PIKA, UPPER_LEG_RADIUS_PIKA, 
		UPPER_LEG_HEIGHT_PIKA,10,10);
	glPopMatrix();
}
void PikachuModel::right_lower_leg(){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rll1,LOWER_LEG_RADIUS_PIKA, LOWER_LEG_RADIUS_PIKA, 
		LOWER_LEG_HEIGHT_PIKA,10,10);
	glPopMatrix();
}
void PikachuModel::right_foot(GLuint texture){
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
		rft1 = gluNewQuadric();
		gluQuadricNormals(rft1, GLU_SMOOTH);
		gluQuadricTexture(rft1, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		glScalef(FOOT_RADIUS_PIKA, FOOT_HEIGHT_PIKA, FOOT_RADIUS_PIKA);
		gluSphere(rft1,1.0,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void PikachuModel::tail(GLuint texture){
	glPushMatrix();
		glRotatef(270.0, 1.0, -1.0, 1.0);
		glScalef(1.0,0.1,1.0);
		glEnable(GL_TEXTURE_2D);
			rll1 = gluNewQuadric();
			gluQuadricNormals(rll1, GLU_SMOOTH);
			gluQuadricTexture(rll1, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluCylinder(rll1,0.0, TAIL_RADIUS_PIKA,TAIL_HEIGHT_PIKA,10,10);
		glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
}
void PikachuModel::drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5){
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glRotatef(theta1[0], 0.0, 1.0, 0.0);
	torso(texture3);
	glPushMatrix();

	glTranslatef(0,TORSO_HEIGHT_PIKA, 0.0);
	neck();

	glTranslatef(0.0, NECK_HEIGHT_PIKA+0.5*HEAD_HEIGHT_PIKA, 0.0);
	//glRotatef(theta[1], 1.0, 0.0, 0.0);
	//glRotatef(theta[2], 0.0, 1.0, 0.0);

	head(texture2);

	glTranslatef(-0.60, NECK_HEIGHT_PIKA+0.5*HEAD_HEIGHT_PIKA, 0.0);
	right_ear(texture1);
	glTranslatef(1.20, -0.6+NECK_HEIGHT_PIKA+0.5*HEAD_HEIGHT_PIKA, 0.0);
	left_ear(texture1);

	glTranslatef(-1.0, -0.6+NECK_HEIGHT_PIKA+0.5*HEAD_HEIGHT_PIKA-3, 0.0);
	tail(texture4);

	glPopMatrix();//add JOINT_POINT_
	glPushMatrix();//add JOINT_POINT_

	glTranslatef(-0.85*(TORSO_RADIUS_PIKA+JOINT_POINT_RADIUS_PIKA), 
		0.9*TORSO_HEIGHT_PIKA, 0.0);
	joint_point();

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(theta1[3], 1.0, 0.0, 0.0);
	glRotatef(theta1[11], 0.0, 0.0, 1.0);
	left_upper_arm(texture5);

	glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT_PIKA);
	joint_point();
	/*
	glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	glRotatef(theta1[4], 1.0, 0.0, 0.0);
	left_lower_arm();
	*/
	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_PIKA);
	left_hand();

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.85*(TORSO_RADIUS_PIKA+JOINT_POINT_RADIUS_PIKA), 
		0.9*TORSO_HEIGHT_PIKA, 0.0);
	joint_point();

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(theta1[5], 1.0, 0.0, 0.0);
	glRotatef(theta1[12], 0.0, 0.0, 1.0);
	right_upper_arm(texture5);

	glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT_PIKA);
	joint_point();

	//glBindTexture(GL_TEXTURE_2D, texture4);
	glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	glRotatef(theta1[6], 1.0, 0.0, 0.0);
	right_lower_arm();

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_PIKA);
	right_hand();

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-(TORSO_RADIUS_PIKA-JOINT_POINT_RADIUS_PIKA), 
		-0.15*JOINT_POINT_HEIGHT_PIKA, 0.0);
	joint_point();

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	glRotatef(theta1[7], 1.0, 0.0, 0.0);
	glRotatef(theta1[13], 0.0, 0.0, 1.0);
	left_upper_leg();

	glTranslatef(0.0, UPPER_LEG_HEIGHT_PIKA, 0.0);
	joint_point();

	glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	glRotatef(theta1[8], 1.0, 0.0, 0.0);
	left_lower_leg();

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	//glTranslatef(0.0, LOWER_LEG_HEIGHT_PIKA, -0.5*FOOT_HEIGHT_PIKA);
	glRotatef(theta1[15], 1.0, 0.0, 0.0);
	left_foot(texture5);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(TORSO_RADIUS_PIKA-JOINT_POINT_RADIUS_PIKA, 
		-0.15*JOINT_POINT_HEIGHT_PIKA, 0.0);
	joint_point();

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	glRotatef(theta1[9], 1.0, 0.0, 0.0);
	glRotatef(theta1[14], 0.0, 0.0, 1.0);
	right_upper_leg();

	glTranslatef(0.0, UPPER_LEG_HEIGHT_PIKA, 0.0);
	joint_point();

	glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_PIKA, 0.0);
	glRotatef(theta1[10], 1.0, 0.0, 0.0);
	right_lower_leg();

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_PIKA-0.2, 0.0);
	//glTranslatef(0.0, LOWER_LEG_HEIGHT_PIKA, -0.5*FOOT_HEIGHT_PIKA);
	glRotatef(theta1[11], 1.0, 0.0, 0.0);
	right_foot(texture5);

	glPopMatrix();
}

void PikachuModel::enableShade(){
	GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
	GLfloat mat_diffuse[]={1.0, 1.0, 1.0, 1.0};
	GLfloat mat_ambient[]={1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess={100.0};
	GLfloat light_ambient[]={0.0, 0.0, 0.0, 1.0};
	GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[]={10.0, 10.0, 10.0, 0.0};

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);

	/* allocate quadrics with filled drawing style */
	h1=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);

	n1=gluNewQuadric();
	gluQuadricDrawStyle(n, GLU_FILL);

	t1=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);

	jp1=gluNewQuadric();
	gluQuadricDrawStyle(jp, GLU_FILL);

	lua1=gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);

	lla1=gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);

	lhnd1=gluNewQuadric();
	gluQuadricDrawStyle(lhnd, GLU_FILL);

	rhnd1=gluNewQuadric();
	gluQuadricDrawStyle(rhnd, GLU_FILL);

	rft1=gluNewQuadric();
	gluQuadricDrawStyle(rft, GLU_FILL);

	lft1=gluNewQuadric();
	gluQuadricDrawStyle(lft, GLU_FILL);

	rua1=gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);

	rla1=gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);

	lul1=gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);

	lll1=gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);

	rul1=gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);

	rll1=gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
}

void PikachuModel::disableShade(){
	glDisable(GL_LIGHTING); 
	glDisable(GL_LIGHT0);
}

void PikachuModel::timer_walk(int nm) {
	if(flag11) {
		theta1[3] += 3.0;
	}
	else {
		theta1[3] -= 3.0;
	}
	if(theta1[3] >= 110.0) flag11 = false;
	if(theta1[3] <= 70.0)  flag11 = true;

	if(flag12) {
		theta1[5] += 3.0;
	}
	else {
		theta1[5] -= 3.0;
	}
	if(theta1[5] >= 110.0) flag12 = false;
	if(theta1[5] <= 70.0)  flag12 = true;

	if(flag13) {
		theta1[9] += 3.0;
	}
	else {
		theta1[9] -= 3.0;
	}
	if(theta1[9] >= 200.0) flag13 = false;
	if(theta1[9] <= 160.0)  flag13 = true;

	if(flag14) {
		theta1[7] += 3.0;
	}
	else {
		theta1[7] -= 3.0;
	}
	if(theta1[7] >= 200.0) flag14 = false;
	if(theta1[7] <= 160.0)  flag14 = true;

	if(hflag1) {
		theta1[12] += 3.0;
	}
	else {
		theta1[2] -= 3.0;
	}
	if(theta1[2] >= 30.0) hflag1 = false;
	if(theta1[2] <= -30.0) hflag1 = true;

	glutPostRedisplay();
	//glutTimerFunc(100,timer_walk,0);
}
