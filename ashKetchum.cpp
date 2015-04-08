//================================Ash Ketchum====================================
#include "headers.h"


void AshModel::head(GLuint texture1,GLuint texture2){
	glPushMatrix();
   	glColor3f (1.0, 0.0, 5.0);
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glRotatef(15.0, 0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);                      //lower head
	   	h = gluNewQuadric();
		gluQuadricNormals(h, GLU_SMOOTH);
		gluQuadricTexture(h, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture2);
	   	glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);
	  	gluSphere(h,0.75,10,10);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();   
	glRotatef(-90.0, 1.0, 0.0, 0.0);                                                  //upper head
	glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT-1.2, 0.8);
	//glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT-1.4, 0.55);       //bACKUP
	glEnable(GL_TEXTURE_2D);
	   	GLUquadricObj *hzz;
	   	hzz = gluNewQuadric();
		gluQuadricNormals(hzz, GLU_SMOOTH);
		gluQuadricTexture(hzz, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture1);
	   	glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS+0.1);
	  	gluSphere(h,0.95,10,10);
	glDisable(GL_TEXTURE_2D);
   	glPopMatrix();
   	disableShade();
   	glColor3f (0.8078431372, 0.3372549019, 0.1725490196);
   	glPushMatrix();                                                     //cap
	glTranslatef(-0.2, NECK_HEIGHT+0.5*HEAD_HEIGHT-0.8, -0.8);
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	glRotatef(15.0, 0.0, 0.0, 1.0);
	
		glRotatef(160.0, 1.0, 0.0, 0.0);
	   	glScalef(HEAD_HEIGHT-20, HEAD_HEIGHT-29, HEAD_RADIUS);
	  	gluSphere(h,0.06,10,10);
	glDisable(GL_TEXTURE_2D);
   	glPopMatrix();
   	enableShade();
}
void AshModel::cap(){
	disableShade();
	glPushMatrix();
    glScalef(1.0, 0.0, 0.0); // scale sphere into a flat pancake
    glColor3f(1.0, 0.0, 0.2);
    glutSolidSphere(8.0, 40, 40); // shadow same size as body
  glPopMatrix();
  enableShade();
}
void AshModel::neck(GLuint texture1,GLuint texture2){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		   	n = gluNewQuadric();
			gluQuadricNormals(n, GLU_SMOOTH);
			gluQuadricTexture(n, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture1);
		  	gluCylinder(n,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
		//glDisable(GL_TEXTURE_2D);
			
		  		n = gluNewQuadric();
			gluQuadricNormals(n, GLU_SMOOTH);
			gluQuadricTexture(n, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture2);

			glColor3f(0.0,0.0,0.0);
			//glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
			glEnable(GL_TEXTURE_GEN_T);
			glBindTexture(GL_TEXTURE_2D,texture2);
			glPushMatrix();
				glTranslatef(0.0,1.5,-2.3);
				glScalef(0.5,0.25,0.75);
				glutSolidCube(4.0);
			glPopMatrix();	
			glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
			glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
}
void AshModel::torso(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
	   	t = gluNewQuadric();
		gluQuadricNormals(t, GLU_SMOOTH);
		gluQuadricTexture(t, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);
	glDisable(GL_TEXTURE_2D); 
		glPopMatrix();
}
void AshModel::joint_point(GLuint texture){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	   	jp = gluNewQuadric();
		gluQuadricNormals(jp, GLU_SMOOTH);
		gluQuadricTexture(jp, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, 
								JOINT_POINT_RADIUS);
   		gluSphere(jp,1.0,10,10);
	glDisable(GL_TEXTURE_2D);	
   	glPopMatrix();
}
void AshModel::joint_point2(){
	glPushMatrix();
	glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, 
								JOINT_POINT_RADIUS);
   		gluSphere(jp,1.0,10,10);	
   	glPopMatrix();
}
void AshModel::left_upper_arm(){
	glPushMatrix();
   	gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, 
									UPPER_ARM_HEIGHT,10,10);
   	glPopMatrix();
}
void AshModel::left_lower_arm(GLuint texture){
	glPushMatrix();
	glColor3f(1.0,0.8549019607,0.7254901960); //skin
   	glRotatef(0.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	lla = gluNewQuadric();
			gluQuadricNormals(lla, GLU_SMOOTH);
			gluQuadricTexture(lla, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(lla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, 
										LOWER_ARM_HEIGHT,10,10);
		glDisable(GL_TEXTURE_2D); 
   	glPopMatrix();
}
void AshModel::left_hand(GLuint texture){
	glPushMatrix();
	glColor3f(0.0,0.8,0.3);
   	glRotatef(90.0, 1.0, 0.0, 0.0);
   	glEnable(GL_TEXTURE_2D);
		   	lhnd = gluNewQuadric();
			gluQuadricNormals(lhnd, GLU_SMOOTH);
			gluQuadricTexture(lhnd, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
   		gluSphere(lhnd,1.0,10,10);
	glDisable(GL_TEXTURE_2D); 	
   	glPopMatrix();

}
void AshModel::right_upper_arm(){
	glPushMatrix();
   	gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, 
									UPPER_ARM_HEIGHT,10,10);
   	glPopMatrix();
}
void AshModel::right_lower_arm(GLuint texture){
	glPushMatrix();
  	glColor3f(1.0,0.8549019607,0.7254901960);
   	glEnable(GL_TEXTURE_2D);
		   	rla = gluNewQuadric();
			gluQuadricNormals(rla, GLU_SMOOTH);
			gluQuadricTexture(rla, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(rla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, 
									LOWER_ARM_HEIGHT,10,10);
	glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void AshModel::right_hand(GLuint texture){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glEnable(GL_TEXTURE_2D);
		   	rhnd = gluNewQuadric();
			gluQuadricNormals(rhnd, GLU_SMOOTH);
			gluQuadricTexture(rhnd, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
  			gluSphere(rhnd,1.0,10,10);
	glDisable(GL_TEXTURE_2D); 	
   glPopMatrix();
}
void AshModel::left_upper_leg(GLuint texture){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   glEnable(GL_TEXTURE_2D);
	   	lul = gluNewQuadric();
		gluQuadricNormals(lul, GLU_SMOOTH);
		gluQuadricTexture(lul, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
									UPPER_LEG_HEIGHT,10,10);
	glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void AshModel::left_lower_leg(GLuint texture){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   glEnable(GL_TEXTURE_2D);
	   	lll = gluNewQuadric();
		gluQuadricNormals(lll, GLU_SMOOTH);
		gluQuadricTexture(lll, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
									LOWER_LEG_HEIGHT,10,10);
	glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void AshModel::left_foot(){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
   gluSphere(lft,1.0,10,10);
   glPopMatrix();
}
void AshModel::right_upper_leg(GLuint texture){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   glEnable(GL_TEXTURE_2D);
	   	rul = gluNewQuadric();
		gluQuadricNormals(rul, GLU_SMOOTH);
		gluQuadricTexture(rul, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
									UPPER_LEG_HEIGHT,10,10);
	glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void AshModel::right_lower_leg(GLuint texture){
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   glEnable(GL_TEXTURE_2D);
	   	rll = gluNewQuadric();
		gluQuadricNormals(rll, GLU_SMOOTH);
		gluQuadricTexture(rll, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
									LOWER_LEG_HEIGHT,10,10);
	glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void AshModel::right_foot(){
   glPushMatrix();
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
   gluSphere(rft,1.0,10,10);
   glPopMatrix();
}

void AshModel::drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5,GLuint texture6,GLuint texture7){
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glRotatef(theta[0], 0.0, 1.0, 0.0);
    torso(texture3);
	glPushMatrix();

	glTranslatef(0,TORSO_HEIGHT, 0.0);
	neck(texture5,texture7);

	glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT, 0.0);  
    head(texture1,texture2);

	glPopMatrix();//add JOINT_POINT_
    glPushMatrix();//add JOINT_POINT_

	glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
									0.9*TORSO_HEIGHT, 0.0);
	joint_point2();

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(theta[3], 1.0, 0.0, 0.0);
	glRotatef(theta[11], 0.0, 0.0, 1.0);
    left_upper_arm();

	glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
	joint_point2();

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[4], 1.0, 0.0, 0.0);
    left_lower_arm(texture5);

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
	left_hand(texture6);

    glPopMatrix();
    glPushMatrix();

	glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
									0.9*TORSO_HEIGHT, 0.0);
	joint_point2();

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(theta[5], 1.0, 0.0, 0.0);
	glRotatef(theta[12], 0.0, 0.0, 1.0);
    right_upper_arm();

    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
	joint_point2();

	//glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[6], 1.0, 0.0, 0.0);
    right_lower_arm(texture5);

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
	right_hand(texture6);

    glPopMatrix();
    glPushMatrix();
	
	glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS), 
							-0.15*JOINT_POINT_HEIGHT, 0.0);
	joint_point2();

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[7], 1.0, 0.0, 0.0);
	glRotatef(theta[13], 0.0, 0.0, 1.0);
    left_upper_leg(texture4);

	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	joint_point(texture4);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[8], 1.0, 0.0, 0.0);
    left_lower_leg(texture4);

    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
	glRotatef(theta[15], 1.0, 0.0, 0.0);
	left_foot();

    glPopMatrix();
    glPushMatrix();

    glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS, 
							-0.15*JOINT_POINT_HEIGHT, 0.0);
	joint_point(texture4);

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[9], 1.0, 0.0, 0.0);
	glRotatef(theta[14], 0.0, 0.0, 1.0);
    right_upper_leg(texture4);

	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	joint_point(texture4);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[10], 1.0, 0.0, 0.0);
    right_lower_leg(texture4);
	
	glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
	glRotatef(theta[16], 1.0, 0.0, 0.0);
	right_foot();
    
	glPopMatrix();
}
void AshModel::enableShade(){
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
    h=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	
	n=gluNewQuadric();
	gluQuadricDrawStyle(n, GLU_FILL);

	t=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);

	jp=gluNewQuadric();
	gluQuadricDrawStyle(jp, GLU_FILL);

    lua=gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);

    lla=gluNewQuadric();
    gluQuadricDrawStyle(lla, GLU_FILL);

    lhnd=gluNewQuadric();
	gluQuadricDrawStyle(lhnd, GLU_FILL);

	rhnd=gluNewQuadric();
	gluQuadricDrawStyle(rhnd, GLU_FILL);

	rft=gluNewQuadric();
	gluQuadricDrawStyle(rft, GLU_FILL);

	lft=gluNewQuadric();
	gluQuadricDrawStyle(lft, GLU_FILL);

	rua=gluNewQuadric();
    gluQuadricDrawStyle(rua, GLU_FILL);

    rla=gluNewQuadric();
    gluQuadricDrawStyle(rla, GLU_FILL);

    lul=gluNewQuadric();
    gluQuadricDrawStyle(lul, GLU_FILL);

    lll=gluNewQuadric();
    gluQuadricDrawStyle(lll, GLU_FILL);

    rul=gluNewQuadric();
    gluQuadricDrawStyle(rul, GLU_FILL);

    rll=gluNewQuadric();
    gluQuadricDrawStyle(rll, GLU_FILL);
}
void AshModel::disableShade(){
	glDisable(GL_LIGHTING); 
    glDisable(GL_LIGHT0);
}
void AshModel::timer_walk(int nm) {
	if(flag1) {
		theta[3] += 3.0;
	}
	else {
		theta[3] -= 3.0;
	}
	if(theta[3] >= 110.0) flag1 = false;
	if(theta[3] <= 70.0)  flag1 = true;
	
	if(flag2) {
	theta[5] += 3.0;
	}
	else {
		theta[5] -= 3.0;
	}
	if(theta[5] >= 110.0) flag2 = false;
	if(theta[5] <= 70.0)  flag2 = true;
	
	if(flag3) {
		theta[9] += 3.0;
	}
	else {
		theta[9] -= 3.0;
	}
	if(theta[9] >= 200.0) flag3 = false;
	if(theta[9] <= 160.0)  flag3 = true;
	
	if(flag4) {
		theta[7] += 3.0;
	}
	else {
		theta[7] -= 3.0;
	}
	if(theta[7] >= 200.0) flag4 = false;
	if(theta[7] <= 160.0)  flag4 = true;
	
	if(hflag) {
		theta[2] += 3.0;
	}
	else {
		theta[2] -= 3.0;
	}
	if(theta[2] >= 30.0) hflag = false;
	if(theta[2] <= -30.0) hflag = true;
	
	glutPostRedisplay();
    //glutTimerFunc(100,timer_walk,0);
}
