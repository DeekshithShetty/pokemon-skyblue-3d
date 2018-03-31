//================================Humanoid Robot====================================
#include "headers.h"


void OddishModel::head(GLuint texture){
			glColor3f(0.0, 0.6, 0.1);
	glPushMatrix();
		glColor3f(0.0,0.8,0.0);
		glEnable(GL_TEXTURE_2D);
		hO = gluNewQuadric();
		gluQuadricNormals(hO, GLU_SMOOTH);
		gluQuadricTexture(hO, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		glRotatef(90.0, -1.0, 0.0, 1.0);
		gluCylinder(hO, 0.3f, 0.0f, 3.5, 32, 32);
		glRotatef(90.0, 0.0, 1.0, 1.0);
		gluCylinder(hO, 0.3f, 0.0f, 3.5, 32, 32);
		glRotatef(90.0, 0.0,-1.0, 1.0);
		gluCylinder(hO, 0.3f, 0.0f, 3.5, 32, 32);
		glRotatef(90.0, 1.0,0.0, 1.0);
		gluCylinder(hO, 0.3f, 0.0f, 3.5, 32, 32);
		glRotatef(90.0, 1.0,1.0,0.0);
		gluCylinder(hO, 0.3f, 0.0f, 3.5, 32, 32);
		glRotatef(90.0, -1.0,1.0,0.0);
		gluCylinder(hO, 0.3f, 0.0f, 3.5, 32, 32);
	glPopMatrix();
}
void OddishModel::torso(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			hM = gluNewQuadric();
			gluQuadricNormals(hM, GLU_SMOOTH);
			gluQuadricTexture(hM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluSphere(hM,TORSO_RADIUS_ODDISH,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void OddishModel::joint_point(){
	glPushMatrix();
		glScalef(JOINT_POINT_RADIUS_ODDISH, JOINT_POINT_HEIGHT_ODDISH, 
			JOINT_POINT_RADIUS_ODDISH);
		gluSphere(jpM,1.0,10,10);
	glPopMatrix();
}
void OddishModel::left_upper_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			luaM = gluNewQuadric();
			gluQuadricNormals(luaM, GLU_SMOOTH);
			gluQuadricTexture(luaM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glRotatef(-90.0, 1.0, 1.0, 0.0);
			gluCylinder(luaM,UPPER_ARM_RADIUS_ODDISH, UPPER_ARM_RADIUS_ODDISH, 
				UPPER_ARM_HEIGHT_ODDISH,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void OddishModel::left_lower_arm(){
	glPushMatrix();
		glRotatef(0.0, 1.0, 0.0, 0.0);
		gluCylinder(llaM,LOWER_ARM_RADIUS_ODDISH, LOWER_ARM_RADIUS_ODDISH, 
			LOWER_ARM_HEIGHT_ODDISH,10,10);
			   	//glRotateflPopMatrix();
	glPopMatrix();
}
void OddishModel::left_hand(){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(HAND_RADIUS_ODDISH, HAND_HEIGHT_ODDISH, HAND_RADIUS_ODDISH);
		gluSphere(lhndM,1.0,10,10);
	glPopMatrix();
}
void OddishModel::right_upper_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			ruaM = gluNewQuadric();
			gluQuadricNormals(ruaM, GLU_SMOOTH);
			gluQuadricTexture(ruaM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glRotatef(-90.0, -1.0, 1.0, 0.0);
			gluCylinder(ruaM,UPPER_ARM_RADIUS_ODDISH, UPPER_ARM_RADIUS_ODDISH, 
				UPPER_ARM_HEIGHT_ODDISH,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void OddishModel::right_lower_arm(){
	glPushMatrix();
		gluCylinder(rlaM,LOWER_ARM_RADIUS_ODDISH, LOWER_ARM_RADIUS_ODDISH, 
			LOWER_ARM_HEIGHT_ODDISH,10,10);
	glPopMatrix();
}
void OddishModel::right_hand(){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(HAND_RADIUS_ODDISH, HAND_HEIGHT_ODDISH, HAND_RADIUS_ODDISH);
		gluSphere(rhndM,1.0,10,10);
	glPopMatrix();
}
void OddishModel::left_upper_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(lulM,UPPER_LEG_RADIUS_ODDISH, UPPER_LEG_RADIUS_ODDISH, 
			UPPER_LEG_HEIGHT_ODDISH,10,10);
	glPopMatrix();
}
void OddishModel::left_lower_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(lllM,LOWER_LEG_RADIUS_ODDISH, LOWER_LEG_RADIUS_ODDISH, 
			LOWER_LEG_HEIGHT_ODDISH_ODDISH,10,10);
	glPopMatrix();
}
void OddishModel::left_foot(GLuint texture){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			lftM = gluNewQuadric();
			gluQuadricNormals(lftM, GLU_SMOOTH);
			gluQuadricTexture(lftM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(FOOT_RADIUS_ODDISH, FOOT_HEIGHT_ODDISH, FOOT_RADIUS_ODDISH);
			gluSphere(lftM,1.0,10,10);
		glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
}
void OddishModel::right_upper_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(rulM,UPPER_LEG_RADIUS_ODDISH, UPPER_LEG_RADIUS_ODDISH, 
			UPPER_LEG_HEIGHT_ODDISH,10,10);
	glPopMatrix();
}
void OddishModel::right_lower_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(rllM,LOWER_LEG_RADIUS_ODDISH, LOWER_LEG_RADIUS_ODDISH, 
			LOWER_LEG_HEIGHT_ODDISH_ODDISH,10,10);
	glPopMatrix();
}
void OddishModel::right_foot(GLuint texture){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			rftM = gluNewQuadric();
			gluQuadricNormals(rftM, GLU_SMOOTH);
			gluQuadricTexture(rftM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(FOOT_RADIUS_ODDISH, FOOT_HEIGHT_ODDISH, FOOT_RADIUS_ODDISH);
			gluSphere(rftM,1.0,10,10);
		glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
}
void OddishModel::drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3){
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glRotatef(thetaO[0], 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0,TORSO_HEIGHT_ODDISH-1.0, 0.0);
	torso(texture2);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0,TORSO_HEIGHT_ODDISH, 0.0);

	glTranslatef(0.0, NECK_HEIGHT_ODDISH+0.5*HEAD_HEIGHT_ODDISH-0.3, 0.0);
	head(texture1);

	glTranslatef(-0.70, NECK_HEIGHT_ODDISH+0.5*HEAD_HEIGHT_ODDISH+0.5, 0.0);
	glTranslatef(1.30, -0.6+NECK_HEIGHT_ODDISH+0.5*HEAD_HEIGHT_ODDISH, 0.0);

	glTranslatef(-0.5, -0.6+NECK_HEIGHT_ODDISH+0.5*HEAD_HEIGHT_ODDISH-4, 0.0);

	glPopMatrix();//add JOINT_POINT_
    glPushMatrix();//add JOINT_POINT_

    glTranslatef(-0.85*(TORSO_RADIUS_ODDISH+JOINT_POINT_RADIUS_ODDISH), 
    	0.9*TORSO_HEIGHT_ODDISH, 0.0);
    joint_point();

    glTranslatef(0.0, -0.5, 0.0);
    //glRotatef(thetaO[3], 1.0, 0.0, 0.0);
    glRotatef(thetaO[3], 1.0, 0.0, 0.0);
    glRotatef(thetaO[11], 0.0, 0.0, 1.0);
    left_upper_arm(texture3);

    glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT_ODDISH);
    joint_point();
/*
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    glRotatef(thetaO[4], 1.0, 0.0, 0.0);
    left_lower_arm();
*/
    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_ODDISH);
	//left_hand();

    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.85*(TORSO_RADIUS_ODDISH+JOINT_POINT_RADIUS_ODDISH), 
    	0.9*TORSO_HEIGHT_ODDISH, 0.0);
    joint_point();

    glTranslatef(0.4, -0.5, 0.0);
    glRotatef(thetaO[5], 1.0, 0.0, 0.0);
    glRotatef(thetaO[12], 0.0, 0.0, 1.0);
    right_upper_arm(texture3);

    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT_ODDISH);
    joint_point();

	//glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    glRotatef(thetaO[6], 1.0, 0.0, 0.0);
    right_lower_arm();

    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_ODDISH);
	//right_hand(texture3);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(-(TORSO_RADIUS_ODDISH-JOINT_POINT_RADIUS_ODDISH), 
    	-0.15*JOINT_POINT_HEIGHT_ODDISH, 0.0);
	//joint_point();

    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    glRotatef(thetaO[7], 1.0, 0.0, 0.0);
    glRotatef(thetaO[13], 0.0, 0.0, 1.0);
    //left_upper_leg();

    glTranslatef(0.0, UPPER_LEG_HEIGHT_ODDISH, 0.0);
	//joint_point();

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    glRotatef(thetaO[8], 1.0, 0.0, 0.0);
    //left_lower_leg();

    glTranslatef(0.7, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    //glTranslatef(0.0, LOWER_LEG_HEIGHT_ODDISH_ODDISH, -0.5*FOOT_HEIGHT_ODDISH);
    glRotatef(thetaO[15], 1.0, 0.0, 0.0);
    left_foot(texture3);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(TORSO_RADIUS_ODDISH-JOINT_POINT_RADIUS_ODDISH, 
    	-0.15*JOINT_POINT_HEIGHT_ODDISH, 0.0);
	//joint_point();

    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    glRotatef(thetaO[9], 1.0, 0.0, 0.0);
    glRotatef(thetaO[14], 0.0, 0.0, 1.0);
    //right_upper_leg();

    glTranslatef(0.0, UPPER_LEG_HEIGHT_ODDISH, 0.0);
	//joint_point();

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_ODDISH, 0.0);
    glRotatef(thetaO[10], 1.0, 0.0, 0.0);
    //right_lower_leg();

    glTranslatef(-0.3, 0.1*JOINT_POINT_HEIGHT_ODDISH-0.2, 0.0);
	//glTranslatef(0.0, LOWER_LEG_HEIGHT_ODDISH_ODDISH, -0.5*FOOT_HEIGHT_ODDISH);
    glRotatef(thetaO[11], 1.0, 0.0, 0.0);
    right_foot(texture3);
    
    glPopMatrix();
}
void OddishModel::enableShade(){
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
	hM=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	
	nM=gluNewQuadric();
	gluQuadricDrawStyle(n, GLU_FILL);

	tM=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);

	jpM=gluNewQuadric();
	gluQuadricDrawStyle(jp, GLU_FILL);

	luaM=gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);

	llaM=gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);

	lhndM=gluNewQuadric();
	gluQuadricDrawStyle(lhnd, GLU_FILL);

	rhndM=gluNewQuadric();
	gluQuadricDrawStyle(rhnd, GLU_FILL);

	rftM=gluNewQuadric();
	gluQuadricDrawStyle(rft, GLU_FILL);

	lftM=gluNewQuadric();
	gluQuadricDrawStyle(lft, GLU_FILL);

	ruaM=gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);

	rlaM=gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);

	lulM=gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);

	lllM=gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);

	rulM=gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);

	rllM=gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
}
void OddishModel::disableShade(){
	glDisable(GL_LIGHTING); 
	glDisable(GL_LIGHT0);
}
