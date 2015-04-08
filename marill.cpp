//================================Humanoid Robot====================================
#include "headers.h"


void MarillModel::head(GLuint texture){
	glPushMatrix();
		glColor3f (1.0, 0.0, 5.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glRotatef(15.0, 0.0, 0.0, 1.0);
		glEnable(GL_TEXTURE_2D);
			h1 = gluNewQuadric();
			gluQuadricNormals(h1, GLU_SMOOTH);
			gluQuadricTexture(h1, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(HEAD_HEIGHT_MARILL, HEAD_HEIGHT_MARILL, HEAD_RADIUS_MARILL);
			gluSphere(h1,1.0,10,10);
		glDisable(GL_TEXTURE_2D);  
	glPopMatrix();
}
void MarillModel::right_ear(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 1.0);
		glEnable(GL_TEXTURE_2D);
			nM = gluNewQuadric();
			gluQuadricNormals(nM, GLU_SMOOTH);
			gluQuadricTexture(nM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluSphere(nM,EAR_RADIUS_MARILL,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void MarillModel::left_ear(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 1.0);
		glEnable(GL_TEXTURE_2D);
			nM = gluNewQuadric();
			gluQuadricNormals(nM, GLU_SMOOTH);
			gluQuadricTexture(nM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluSphere(nM,EAR_RADIUS_MARILL,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void MarillModel::neck(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(nM,NECK_RADIUS_MARILL, NECK_RADIUS_MARILL, NECK_HEIGHT_MARILL,10,10);
	glPopMatrix();
}
void MarillModel::torso(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			hM = gluNewQuadric();
			gluQuadricNormals(hM, GLU_SMOOTH);
			gluQuadricTexture(hM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluSphere(hM,TORSO_RADIUS_MARILL,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void MarillModel::joint_point(){
	glPushMatrix();
		glScalef(JOINT_POINT_RADIUS_MARILL, JOINT_POINT_HEIGHT_MARILL, 
			JOINT_POINT_RADIUS_MARILL);
		gluSphere(jpM,1.0,10,10);
	glPopMatrix();
}
void MarillModel::left_upper_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			luaM = gluNewQuadric();
			gluQuadricNormals(luaM, GLU_SMOOTH);
			gluQuadricTexture(luaM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluCylinder(luaM,UPPER_ARM_RADIUS_MARILL, UPPER_ARM_RADIUS_MARILL, 
				UPPER_ARM_HEIGHT_MARILL,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void MarillModel::left_lower_arm(){
	glPushMatrix();
		glRotatef(0.0, 1.0, 0.0, 0.0);
		gluCylinder(llaM,LOWER_ARM_RADIUS_MARILL, LOWER_ARM_RADIUS_MARILL, 
			LOWER_ARM_HEIGHT_MARILL,10,10);
			   	//glRotateflPopMatrix();
	glPopMatrix();
}
void MarillModel::left_hand(){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(HAND_RADIUS_MARILL, HAND_HEIGHT_MARILL, HAND_RADIUS_MARILL);
		gluSphere(lhndM,1.0,10,10);
	glPopMatrix();
}
void MarillModel::right_upper_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			ruaM = gluNewQuadric();
			gluQuadricNormals(ruaM, GLU_SMOOTH);
			gluQuadricTexture(ruaM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluCylinder(ruaM,UPPER_ARM_RADIUS_MARILL, UPPER_ARM_RADIUS_MARILL, 
				UPPER_ARM_HEIGHT_MARILL,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void MarillModel::right_lower_arm(){
	glPushMatrix();
		gluCylinder(rlaM,LOWER_ARM_RADIUS_MARILL, LOWER_ARM_RADIUS_MARILL, 
			LOWER_ARM_HEIGHT_MARILL,10,10);
	glPopMatrix();
}
void MarillModel::right_hand(){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(HAND_RADIUS_MARILL, HAND_HEIGHT_MARILL, HAND_RADIUS_MARILL);
		gluSphere(rhndM,1.0,10,10);
	glPopMatrix();
}
void MarillModel::left_upper_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(lulM,UPPER_LEG_RADIUS_MARILL, UPPER_LEG_RADIUS_MARILL, 
			UPPER_LEG_HEIGHT_MARILL,10,10);
	glPopMatrix();
}
void MarillModel::left_lower_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(lllM,LOWER_LEG_RADIUS_MARILL, LOWER_LEG_RADIUS_MARILL, 
			LOWER_LEG_HEIGHT_MARILL_MARILL,10,10);
	glPopMatrix();
}
void MarillModel::left_foot(GLuint texture){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			lftM = gluNewQuadric();
			gluQuadricNormals(lftM, GLU_SMOOTH);
			gluQuadricTexture(lftM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(FOOT_RADIUS_MARILL, FOOT_HEIGHT_MARILL, FOOT_RADIUS_MARILL);
			gluSphere(lftM,1.0,10,10);
		glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
}
void MarillModel::right_upper_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(rulM,UPPER_LEG_RADIUS_MARILL, UPPER_LEG_RADIUS_MARILL, 
			UPPER_LEG_HEIGHT_MARILL,10,10);
	glPopMatrix();
}
void MarillModel::right_lower_leg(){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(rllM,LOWER_LEG_RADIUS_MARILL, LOWER_LEG_RADIUS_MARILL, 
			LOWER_LEG_HEIGHT_MARILL_MARILL,10,10);
	glPopMatrix();
}
void MarillModel::right_foot(GLuint texture){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			rftM = gluNewQuadric();
			gluQuadricNormals(rftM, GLU_SMOOTH);
			gluQuadricTexture(rftM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(FOOT_RADIUS_MARILL, FOOT_HEIGHT_MARILL, FOOT_RADIUS_MARILL);
			gluSphere(rftM,1.0,10,10);
		glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
}
void MarillModel::tail(GLuint texture){
	glPushMatrix();
		glRotatef(-180.0, 1.0, 1.0, 1.0);
			   //glScalef(FOOT_RADIUS_MARILL, FOOT_HEIGHT_MARILL, FOOT_RADIUS_MARILL);
		disableShade();
		glColor3f(0.1,0.1,0.1);
		gluCylinder(rllM,0.07, 0.07,TAIL_HEIGHT_MARILL+3.4,10,10);
		enableShade();
			glEnable(GL_TEXTURE_2D);
			nM = gluNewQuadric();
			gluQuadricNormals(nM, GLU_SMOOTH);
			gluQuadricTexture(nM, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTranslatef(-0.1, -0.6+NECK_HEIGHT_MARILL+0.5*HEAD_HEIGHT_MARILL-0.4, 6.4);
			gluSphere(nM,TAIL_RADIUS_MARILL,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void MarillModel::drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4){
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glRotatef(thetaM[0], 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0,TORSO_HEIGHT_MARILL-1.0, 0.0);
	torso(texture3);
	glPopMatrix();
	glPushMatrix();

	glTranslatef(0,TORSO_HEIGHT_MARILL, 0.0);
	neck();

	glTranslatef(0.0, NECK_HEIGHT_MARILL+0.5*HEAD_HEIGHT_MARILL-0.3, 0.0);
			//glRotatef(theta[1], 1.0, 0.0, 0.0);
		    //glRotatef(theta[2], 0.0, 1.0, 0.0);

	head(texture2);

	glTranslatef(-0.70, NECK_HEIGHT_MARILL+0.5*HEAD_HEIGHT_MARILL+0.5, 0.0);
	right_ear(texture1);
	glTranslatef(1.30, -0.6+NECK_HEIGHT_MARILL+0.5*HEAD_HEIGHT_MARILL, 0.0);
	left_ear(texture1);

	glTranslatef(-0.5, -0.6+NECK_HEIGHT_MARILL+0.5*HEAD_HEIGHT_MARILL-4, 0.0);
	tail(texture4);

	glPopMatrix();//add JOINT_POINT_
    glPushMatrix();//add JOINT_POINT_

    glTranslatef(-0.85*(TORSO_RADIUS_MARILL+JOINT_POINT_RADIUS_MARILL), 
    	0.9*TORSO_HEIGHT_MARILL, 0.0);
    joint_point();

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(thetaM[3], 1.0, 0.0, 0.0);
    glRotatef(thetaM[11], 0.0, 0.0, 1.0);
    left_upper_arm(texture4);

    glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT_MARILL);
    joint_point();
/*
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    glRotatef(thetaM[4], 1.0, 0.0, 0.0);
    left_lower_arm();
*/
    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_MARILL);
	//left_hand();

    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.85*(TORSO_RADIUS_MARILL+JOINT_POINT_RADIUS_MARILL), 
    	0.9*TORSO_HEIGHT_MARILL, 0.0);
    joint_point();

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(thetaM[5], 1.0, 0.0, 0.0);
    glRotatef(thetaM[12], 0.0, 0.0, 1.0);
    right_upper_arm(texture4);

    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT_MARILL);
    joint_point();

	//glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    glRotatef(thetaM[6], 1.0, 0.0, 0.0);
    right_lower_arm();

    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_MARILL);
	//right_hand(texture3);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(-(TORSO_RADIUS_MARILL-JOINT_POINT_RADIUS_MARILL), 
    	-0.15*JOINT_POINT_HEIGHT_MARILL, 0.0);
	//joint_point();

    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    glRotatef(thetaM[7], 1.0, 0.0, 0.0);
    glRotatef(thetaM[13], 0.0, 0.0, 1.0);
    //left_upper_leg();

    glTranslatef(0.0, UPPER_LEG_HEIGHT_MARILL, 0.0);
	//joint_point();

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    glRotatef(thetaM[8], 1.0, 0.0, 0.0);
    //left_lower_leg();

    glTranslatef(0.7, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    //glTranslatef(0.0, LOWER_LEG_HEIGHT_MARILL_MARILL, -0.5*FOOT_HEIGHT_MARILL);
    glRotatef(thetaM[15], 1.0, 0.0, 0.0);
    left_foot(texture4);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(TORSO_RADIUS_MARILL-JOINT_POINT_RADIUS_MARILL, 
    	-0.15*JOINT_POINT_HEIGHT_MARILL, 0.0);
	//joint_point();

    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    glRotatef(thetaM[9], 1.0, 0.0, 0.0);
    glRotatef(thetaM[14], 0.0, 0.0, 1.0);
    //right_upper_leg();

    glTranslatef(0.0, UPPER_LEG_HEIGHT_MARILL, 0.0);
	//joint_point();

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_MARILL, 0.0);
    glRotatef(thetaM[10], 1.0, 0.0, 0.0);
    //right_lower_leg();

    glTranslatef(-0.3, 0.1*JOINT_POINT_HEIGHT_MARILL-0.2, 0.0);
	//glTranslatef(0.0, LOWER_LEG_HEIGHT_MARILL_MARILL, -0.5*FOOT_HEIGHT_MARILL);
    glRotatef(thetaM[11], 1.0, 0.0, 0.0);
    right_foot(texture4);
    
    glPopMatrix();
}
void MarillModel::enableShade(){
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
void MarillModel::disableShade(){
	glDisable(GL_LIGHTING); 
	glDisable(GL_LIGHT0);
}
void MarillModel::timer_walk(int nm) {
	if(flag1M) {
		thetaM[3] += 3.0;
	}
	else {
		thetaM[3] -= 3.0;
	}
	if(thetaM[3] >= 110.0) flag1M = false;
	if(thetaM[3] <= 70.0)  flag1M = true;
	
	if(flag2M) {
		thetaM[5] += 3.0;
	}
	else {
		thetaM[5] -= 3.0;
	}
	if(thetaM[5] >= 110.0) flag2M = false;
	if(thetaM[5] <= 70.0)  flag2M = true;
	
	if(flag3M) {
		thetaM[9] += 3.0;
	}
	else {
		thetaM[9] -= 3.0;
	}
	if(thetaM[9] >= 200.0) flag3M = false;
	if(thetaM[9] <= 160.0)  flag3M = true;
	
	if(flag4M) {
		thetaM[7] += 3.0;
	}
	else {
		thetaM[7] -= 3.0;
	}
	if(thetaM[7] >= 200.0) flag4M = false;
	if(thetaM[7] <= 160.0)  flag4M = true;
	
	if(hflagM) {
		thetaM[12] += 3.0;
	}
	else {
		thetaM[2] -= 3.0;
	}
	if(thetaM[2] >= 30.0) hflagM = false;
	if(thetaM[2] <= -30.0) hflagM = true;
	
	glutPostRedisplay();
    //glutTimerFunc(100,timer_walk,0);
}
