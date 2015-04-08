//================================Gary Oak====================================
#include "headers.h"


void GaryModel::head(GLuint texture1,GLuint texture2){
	glPushMatrix();
   	glColor3f (1.0, 0.0, 5.0);
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glRotatef(15.0, 0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);                      //lower head
	   	h = gluNewQuadric();
		gluQuadricNormals(h, GLU_SMOOTH);
		gluQuadricTexture(h, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture2);
	   	glScalef(HEAD_HEIGHT_GARY, HEAD_HEIGHT_GARY, HEAD_RADIUS_GARY);
	  	gluSphere(h,0.75,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix(); 
	glRotatef(-90.0, 1.0, 0.0, 0.0);                                                   //upper head
	glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT_GARY-1.3, 0.7);
	//glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT_GARY-1.4, 0.55);       //bACKUP
	glEnable(GL_TEXTURE_2D);
	   	GLUquadricObj *hzz;
	   	hzz = gluNewQuadric();
		gluQuadricNormals(hzz, GLU_SMOOTH);
		gluQuadricTexture(hzz, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture1);
	   	glScalef(HEAD_HEIGHT_GARY, HEAD_HEIGHT_GARY, HEAD_RADIUS_GARY+0.1);
	  	gluSphere(h,0.94,10,10);
	glDisable(GL_TEXTURE_2D);
   	glPopMatrix();
}
void GaryModel::neck(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		   	nG = gluNewQuadric();
			gluQuadricNormals(nG, GLU_SMOOTH);
			gluQuadricTexture(nG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(nG,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
		glPopMatrix();
}
void GaryModel::torso(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			tG = gluNewQuadric();
			gluQuadricNormals(tG, GLU_SMOOTH);
			gluQuadricTexture(tG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluCylinder(tG,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void GaryModel::joint_point(GLuint texture){
	glPushMatrix();
   	glEnable(GL_TEXTURE_2D);
		   	jpG = gluNewQuadric();
			gluQuadricNormals(jpG, GLU_SMOOTH);
			gluQuadricTexture(jpG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, 
				JOINT_POINT_RADIUS);
			gluSphere(jpG,1.0,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::joint_point2(GLuint texture){
	glPushMatrix();
   	glEnable(GL_TEXTURE_2D);
		   	jpG = gluNewQuadric();
			gluQuadricNormals(jpG, GLU_SMOOTH);
			gluQuadricTexture(jpG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, 
				JOINT_POINT_RADIUS);
			gluSphere(jpG,1.0,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::left_upper_arm(GLuint texture){
	glPushMatrix();
   	glEnable(GL_TEXTURE_2D);
		   	luaG = gluNewQuadric();
			gluQuadricNormals(luaG, GLU_SMOOTH);
			gluQuadricTexture(luaG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(luaG,UPPER_ARM_RADIUS_GARY, UPPER_ARM_RADIUS_GARY, 
					UPPER_ARM_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::left_lower_arm(GLuint texture){
	glPushMatrix();
	glRotatef(0.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	llaG = gluNewQuadric();
			gluQuadricNormals(llaG, GLU_SMOOTH);
			gluQuadricTexture(llaG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(llaG,LOWER_ARM_RADIUS_GARY, LOWER_ARM_RADIUS_GARY, 
					LOWER_ARM_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::left_hand(GLuint texture){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			lhndG = gluNewQuadric();
			gluQuadricNormals(lhndG, GLU_SMOOTH);
			gluQuadricTexture(lhndG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
		gluSphere(lhndG,1.0,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void GaryModel::right_upper_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			ruaG = gluNewQuadric();
			gluQuadricNormals(ruaG, GLU_SMOOTH);
			gluQuadricTexture(ruaG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluCylinder(ruaG,UPPER_ARM_RADIUS_GARY, UPPER_ARM_RADIUS_GARY, 
				UPPER_ARM_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void GaryModel::right_lower_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			rlaG = gluNewQuadric();
			gluQuadricNormals(rlaG, GLU_SMOOTH);
			gluQuadricTexture(rlaG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluCylinder(rlaG,LOWER_ARM_RADIUS_GARY, LOWER_ARM_RADIUS_GARY, 
			LOWER_ARM_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void GaryModel::right_hand(GLuint texture){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
			rhndG = gluNewQuadric();
			gluQuadricNormals(rhndG, GLU_SMOOTH);
			gluQuadricTexture(rhndG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
			glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
			gluSphere(rhndG,1.0,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void GaryModel::left_upper_leg(GLuint texture){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	lulG = gluNewQuadric();
			gluQuadricNormals(lulG, GLU_SMOOTH);
			gluQuadricTexture(lulG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(lulG,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
				UPPER_LEG_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::left_lower_leg(GLuint texture){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	lllG = gluNewQuadric();
			gluQuadricNormals(lllG, GLU_SMOOTH);
			gluQuadricTexture(lllG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(lllG,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
				LOWER_LEG_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::left_foot(){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
		gluSphere(lftG,1.0,10,10);
	glPopMatrix();
}
void GaryModel::right_upper_leg(GLuint texture){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	rulG = gluNewQuadric();
			gluQuadricNormals(rulG, GLU_SMOOTH);
			gluQuadricTexture(rulG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(rulG,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
				UPPER_LEG_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::right_lower_leg(GLuint texture){
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	rllG = gluNewQuadric();
			gluQuadricNormals(rllG, GLU_SMOOTH);
			gluQuadricTexture(rllG, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(rllG,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
				LOWER_LEG_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void GaryModel::right_foot(){
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
		gluSphere(rftG,1.0,10,10);
	glPopMatrix();
}

void GaryModel::drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5,GLuint texture6,GLuint texture7){
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glRotatef(thetaG[0], 0.0, 1.0, 0.0);
	torso(texture3);
	glPushMatrix();
	glTranslatef(0,TORSO_HEIGHT, 0.0);
	neck(texture5);

	//glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT_GARY, 0.0);
	glTranslatef(0.0, NECK_HEIGHT+0.2, 0.0);
	head(texture1,texture2);

	glPopMatrix();//add JOINT_POINT_
    glPushMatrix();//add JOINT_POINT_

    glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
    	0.9*TORSO_HEIGHT, 0.0);
    joint_point(texture6);

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(thetaG[3], 1.0, 0.0, 0.0);
    glRotatef(thetaG[11], 0.0, 0.0, 1.0);
    left_upper_arm(texture6);

    glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
    joint_point(texture6);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(thetaG[4], 1.0, 0.0, 0.0);
    left_lower_arm(texture6);

    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
    left_hand(texture5);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
    	0.9*TORSO_HEIGHT, 0.0);
    joint_point(texture6);

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(thetaG[5], 1.0, 0.0, 0.0);
    glRotatef(thetaG[12], 0.0, 0.0, 1.0);
    right_upper_arm(texture6);

    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
    joint_point(texture6);

	//glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(thetaG[6], 1.0, 0.0, 0.0);
    right_lower_arm(texture6);

    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
    right_hand(texture5);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS), 
    	-0.15*JOINT_POINT_HEIGHT, 0.0);
    joint_point2(texture6);

    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(thetaG[7], 1.0, 0.0, 0.0);
    glRotatef(thetaG[13], 0.0, 0.0, 1.0);
    left_upper_leg(texture7);

    glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
    joint_point2(texture6);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(thetaG[8], 1.0, 0.0, 0.0);
    left_lower_leg(texture7);

    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
    glRotatef(thetaG[15], 1.0, 0.0, 0.0);
    left_foot();

    glPopMatrix();
    glPushMatrix();

    glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS, 
    	-0.15*JOINT_POINT_HEIGHT, 0.0);
    joint_point2(texture6);

    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(thetaG[9], 1.0, 0.0, 0.0);
    glRotatef(thetaG[14], 0.0, 0.0, 1.0);
    right_upper_leg(texture7);

    glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
    joint_point2(texture6);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(thetaG[10], 1.0, 0.0, 0.0);
    right_lower_leg(texture7);

    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
    glRotatef(thetaG[16], 1.0, 0.0, 0.0);
    right_foot();
    
    glPopMatrix();
}
void GaryModel::enableShade(){
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
	hG=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	
	nG=gluNewQuadric();
	gluQuadricDrawStyle(n, GLU_FILL);

	tG=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);

	jpG=gluNewQuadric();
	gluQuadricDrawStyle(jp, GLU_FILL);

	luaG=gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);

	llaG=gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);

	lhndG=gluNewQuadric();
	gluQuadricDrawStyle(lhnd, GLU_FILL);

	rhndG=gluNewQuadric();
	gluQuadricDrawStyle(rhnd, GLU_FILL);

	rftG=gluNewQuadric();
	gluQuadricDrawStyle(rft, GLU_FILL);

	lftG=gluNewQuadric();
	gluQuadricDrawStyle(lft, GLU_FILL);

	ruaG=gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);

	rlaG=gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);

	lulG=gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);

	lllG=gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);

	rulG=gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);

	rllG=gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
}
void GaryModel::disableShade(){
	glDisable(GL_LIGHTING); 
	glDisable(GL_LIGHT0);
}
void GaryModel::timer_walk(int nm) {
	if(flag1G) {
		thetaG[3] += 3.0;
	}
	else {
		thetaG[3] -= 3.0;
	}
	if(thetaG[3] >= 110.0) flag1G = false;
	if(thetaG[3] <= 70.0)  flag1G = true;
	
	if(flag2G) {
		thetaG[5] += 3.0;
	}
	else {
		thetaG[5] -= 3.0;
	}
	if(thetaG[5] >= 110.0) flag2G = false;
	if(thetaG[5] <= 70.0)  flag2G = true;
	
	if(flag3G) {
		thetaG[9] += 3.0;
	}
	else {
		thetaG[9] -= 3.0;
	}
	if(thetaG[9] >= 200.0) flag3G = false;
	if(thetaG[9] <= 160.0)  flag3G = true;
	
	if(flag4G) {
		thetaG[7] += 3.0;
	}
	else {
		thetaG[7] -= 3.0;
	}
	if(thetaG[7] >= 200.0) flag4G = false;
	if(thetaG[7] <= 160.0)  flag4G = true;
	
	if(hflagG) {
		thetaG[2] += 3.0;
	}
	else {
		thetaG[2] -= 3.0;
	}
	if(thetaG[2] >= 30.0) hflagG = false;
	if(thetaG[2] <= -30.0) hflagG = true;
	
	glutPostRedisplay();
    //glutTimerFunc(100,timer_walk,0);
}

void GaryModel::pointHand(){
	thetaG[5] = 20;
}
