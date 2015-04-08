//================================Ash Ketchum====================================
#include "headers.h"


void CharmanderModel::head(GLuint texture1,GLuint texture2){
	glPushMatrix();
	   	glColor3f (1.0, 0.0, 5.0);
	   	glRotatef(-90.0, 1.0, 0.0, 0.0);
	   	glRotatef(15.0, 0.0, 0.0, 1.0);
	   	glTranslatef(-0.4,-0.8, 0.0);
		glEnable(GL_TEXTURE_2D);                      //lower head
		   	hC = gluNewQuadric();
			gluQuadricNormals(hC, GLU_SMOOTH);
			gluQuadricTexture(hC, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture2);
		   	//glScalef(HEAD_HEIGHT_CHAR, HEAD_HEIGHT_CHAR, HEAD_RADIUS_CHAR);
		   	glScalef(HEAD_HEIGHT_CHAR,1.5, HEAD_RADIUS_CHAR);
		  	gluSphere(hC,0.78,10,10);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();   
		glRotatef(-90.0, 1.0, 0.0, 0.0);                                                  //upper head
		glTranslatef(0.0, NECK_HEIGHT_CHAR+0.5*HEAD_HEIGHT_CHAR-1.2, 0.8);
		//glTranslatef(0.0, NECK_HEIGHT_CHAR+0.5*HEAD_HEIGHT_CHAR-1.4, 0.55);       //bACKUP
		glEnable(GL_TEXTURE_2D);
		   	GLUquadricObj *hzz;
		   	hzz = gluNewQuadric();
			gluQuadricNormals(hzz, GLU_SMOOTH);
			gluQuadricTexture(hzz, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture1);
		   	glScalef(HEAD_HEIGHT_CHAR, HEAD_HEIGHT_CHAR, HEAD_RADIUS_CHAR+0.1);
		  	gluSphere(hC,0.99,10,10);
		glDisable(GL_TEXTURE_2D);
   	glPopMatrix();
}
void CharmanderModel::neck(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		   	nC = gluNewQuadric();
			gluQuadricNormals(nC, GLU_SMOOTH);
			gluQuadricTexture(nC, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(nC,NECK_RADIUS_CHAR, NECK_RADIUS_CHAR, NECK_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
}
void CharmanderModel::torso(GLuint texture){
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glEnable(GL_TEXTURE_2D);
	   	tC = gluNewQuadric();
		gluQuadricNormals(tC, GLU_SMOOTH);
		gluQuadricTexture(tC, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	//gluCylinder(tC,TORSO_RADIUS_CHAR, TORSO_RADIUS_CHAR, TORSO_HEIGHT_CHAR,10,10);
	  	glScalef(TORSO_RADIUS_CHAR,TORSO_RADIUS_CHAR,3.0);
	  	//glScalef(0.0,0.0,0.0);
   		gluSphere(jpC,1.0,10,10);
		glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
}
void CharmanderModel::joint_point(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
	   	jpC= gluNewQuadric();
		gluQuadricNormals(jpC, GLU_SMOOTH);
		gluQuadricTexture(jpC, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
	  	glScalef(JOINT_POINT_RADIUS_CHAR, JOINT_POINT_HEIGHT_CHAR, 
								JOINT_POINT_RADIUS_CHAR);
   		gluSphere(jpC,1.0,10,10);
		glDisable(GL_TEXTURE_2D);	
   	glPopMatrix();
}
void CharmanderModel::joint_point2(){
	glPushMatrix();
		glScalef(JOINT_POINT_RADIUS_CHAR, JOINT_POINT_HEIGHT_CHAR, 
								JOINT_POINT_RADIUS_CHAR);
   		gluSphere(jpC,1.0,10,10);	
   	glPopMatrix();
}
void CharmanderModel::left_upper_arm(GLuint texture){

	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			   	luaC = gluNewQuadric();
				gluQuadricNormals(luaC, GLU_SMOOTH);
				gluQuadricTexture(luaC, GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture);
			  	gluCylinder(luaC,UPPER_ARM_RADIUS_CHAR, UPPER_ARM_RADIUS_CHAR-0.1, 
									UPPER_ARM_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D); 
   		
   	glPopMatrix();
}
void CharmanderModel::left_hand(){
	glPushMatrix();
		glColor3f(0.9,0.9,0.9);
	   	glRotatef(90.0, 1.0, 0.0, 0.0);
	   	//glEnable(GL_TEXTURE_2D);
			   	lhndC = gluNewQuadric();
			  	glScalef(HAND_RADIUS_CHAR, HAND_HEIGHT_CHAR, HAND_RADIUS_CHAR);
	   		gluSphere(lhndC,1.0,10,10);
		glDisable(GL_TEXTURE_2D); 	
   	glPopMatrix();

}
void CharmanderModel::right_upper_arm(GLuint texture){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			   	ruaC = gluNewQuadric();
				gluQuadricNormals(ruaC, GLU_SMOOTH);
				gluQuadricTexture(ruaC, GL_TRUE);
				glBindTexture(GL_TEXTURE_2D, texture);
			  	gluCylinder(ruaC,UPPER_ARM_RADIUS_CHAR, UPPER_ARM_RADIUS_CHAR-0.1, 
									UPPER_ARM_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D); 
   		
   	glPopMatrix();
}
void CharmanderModel::right_hand(){
   glPushMatrix();
   glColor3f(0.9,0.9,0.9);
	   glRotatef(90.0, 1.0, 0.0, 0.0);
	   //glEnable(GL_TEXTURE_2D);
			   	rhndC = gluNewQuadric();
			  	glScalef(HAND_RADIUS_CHAR, HAND_HEIGHT_CHAR, HAND_RADIUS_CHAR);
	  			gluSphere(rhndC,1.0,10,10);
		glDisable(GL_TEXTURE_2D); 	
   glPopMatrix();
}
void CharmanderModel::left_upper_leg(GLuint texture){
   glPushMatrix();
	   glRotatef(-90.0, 1.0, 0.0, 0.0);
	   glEnable(GL_TEXTURE_2D);
		   	lulC = gluNewQuadric();
			gluQuadricNormals(lulC, GLU_SMOOTH);
			gluQuadricTexture(lulC, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(lulC,UPPER_LEG_RADIUS_CHAR, UPPER_LEG_RADIUS_CHAR-0.2, 
										UPPER_LEG_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void CharmanderModel::left_lower_leg(GLuint texture){
   glPushMatrix();
	   glRotatef(-90.0, 1.0, 0.0, 0.0);
	   glEnable(GL_TEXTURE_2D);
		   	lllC = gluNewQuadric();
			gluQuadricNormals(lllC, GLU_SMOOTH);
			gluQuadricTexture(lllC, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(lllC,LOWER_LEG_RADIUS_CHAR, LOWER_LEG_RADIUS_CHAR, 
										LOWER_LEG_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void CharmanderModel::left_foot(){
   glPushMatrix();
	   glRotatef(90.0, 1.0, 0.0, 0.0);
	   glScalef(FOOT_RADIUS_CHAR, FOOT_HEIGHT_CHAR, FOOT_RADIUS_CHAR);
	   gluSphere(lftC,1.0,10,10);
   glPopMatrix();
}
void CharmanderModel::right_upper_leg(GLuint texture){
   glPushMatrix();
	   glRotatef(-90.0, 1.0, 0.0, 0.0);
	   glEnable(GL_TEXTURE_2D);
		   	rulC = gluNewQuadric();
			gluQuadricNormals(rulC, GLU_SMOOTH);
			gluQuadricTexture(rulC, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(rulC,UPPER_LEG_RADIUS_CHAR, UPPER_LEG_RADIUS_CHAR-0.2, 
										UPPER_LEG_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D);
   	glPopMatrix();
}
void CharmanderModel::right_lower_leg(GLuint texture){
   glPushMatrix();
	   glRotatef(-90.0, 1.0, 0.0, 0.0);
	   glEnable(GL_TEXTURE_2D);
		   	rllC = gluNewQuadric();
			gluQuadricNormals(rllC, GLU_SMOOTH);
			gluQuadricTexture(rllC, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture);
		  	gluCylinder(rllC,LOWER_LEG_RADIUS_CHAR, LOWER_LEG_RADIUS_CHAR, 
										LOWER_LEG_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
void CharmanderModel::right_foot(){
   glPushMatrix();
	   glRotatef(90.0, 1.0, 0.0, 0.0);
	   glScalef(FOOT_RADIUS_CHAR, FOOT_HEIGHT_CHAR, FOOT_RADIUS_CHAR);
	   gluSphere(rftC,1.0,10,10);
   glPopMatrix();
}
void CharmanderModel::tail(GLuint texture1,GLuint texture2){
	glPushMatrix();
		//glRotatef(210.0, 1.0, -1.0, 1.0);
		glEnable(GL_TEXTURE_2D);
		rllC = gluNewQuadric();
		gluQuadricNormals(rllC, GLU_SMOOTH);
		gluQuadricTexture(rllC, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture1);
		gluCylinder(rllC,TAIL_RADIUS_CHAR, 0.2,TAIL_HEIGHT_CHAR,10,10);
		glDisable(GL_TEXTURE_2D);

		glTranslatef(0.0,0.0,6.0);
		glRotatef(120,0.0,1.0,1.0);
		glPushMatrix();
			glColor3f(1.0,0.0,0.0);
			glEnable(GL_TEXTURE_2D);
			quadratic = gluNewQuadric();
			gluQuadricNormals(quadratic, GLU_SMOOTH);
			gluQuadricTexture(quadratic, GL_TRUE);
			glBindTexture(GL_TEXTURE_2D, texture2);
			glRotatef(75.0, -1.0, 0.0, 1.0);
			gluCylinder(quadratic, 0.2f, 0.0f, 2.0, 32, 32);
			glRotatef(75.0, 0.0, 1.0, 1.0);
			gluCylinder(quadratic, 0.2f, 0.0f, 2.0, 32, 32);
			glRotatef(75.0, 0.0,-1.0, 1.0);
			gluCylinder(quadratic, 0.2f, 0.0f, 2.0, 32, 32);
			glRotatef(75.0, 1.0,0.0, 1.0);
			gluCylinder(quadratic, 0.2f, 0.0f, 2.0, 32, 32);	
			glPopMatrix();
	glPopMatrix();
}

void CharmanderModel::drawCyborg(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4,GLuint texture5){
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glRotatef(thetaC[0], 0.0, 1.0, 0.0);
	glPushMatrix();
		glRotatef(30, 1.0, 0.0, 0.0);
		torso(texture3);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-thetaC[0], 0.0, 1.0, 0.0);
		//glRotatef(-300, 1.0, 0.0, 0.0);
		glPushMatrix();
			glTranslatef(-0.0,-1.0,-1.0);
			glRotatef(170, -1.0, 1.0, 1.0);
			//glRotatef(-270, 1.0, 0.0, 0.0);
			tail(texture4,texture5);
		glPopMatrix();	
	glPopMatrix();

	
	glPushMatrix();

	glTranslatef(0,TORSO_HEIGHT_CHAR, 0.0);
	//neck(texture5);

	glTranslatef(0.0, TORSO_HEIGHT_CHAR, 1.5);  
    head(texture1,texture2);

	glPopMatrix();//add JOINT_POINT_
    glPushMatrix();//add JOINT_POINT_

	glTranslatef(-0.85*(TORSO_RADIUS_CHAR+JOINT_POINT_RADIUS_CHAR), 
									0.9*TORSO_HEIGHT_CHAR, 0.0);
	//joint_point2();

	glTranslatef(0.5, 0.0, 0.0);
	glRotatef(10, 1.0, 0.0, 0.0);
	//glRotatef(thetaC[3], 1.0, 0.0, 0.0);
	glRotatef(thetaC[11], 0.0, 0.0, 1.0);
    	left_upper_arm(texture4);

	glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT_CHAR);
	//joint_point2();

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_CHAR, 0.0);
    glRotatef(thetaC[4], 1.0, 0.0, 0.0);
    //left_lower_arm(texture5);

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_CHAR);
	left_hand();

    glPopMatrix();
    glPushMatrix();

	glTranslatef(0.85*(TORSO_RADIUS_CHAR+JOINT_POINT_RADIUS_CHAR), 
									0.9*TORSO_HEIGHT_CHAR, 0.0);
	//joint_point2();

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(5, 1.0, 0.0, 0.0);
    //glRotatef(thetaC[5], 1.0, 0.0, 0.0);
	glRotatef(thetaC[12], 0.0, 0.0, 1.0);
	glPushMatrix();
    	right_upper_arm(texture4);
    glPopMatrix();	

    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT_CHAR);
	//joint_point2();

	//glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_CHAR, 0.0);
    glRotatef(thetaC[6], 1.0, 0.0, 0.0);
    //right_lower_arm(texture5);

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT_CHAR);
	right_hand();

    glPopMatrix();
    glPushMatrix();
	
	glTranslatef(-(TORSO_RADIUS_CHAR-JOINT_POINT_RADIUS_CHAR), 
							-0.15*JOINT_POINT_HEIGHT_CHAR, 0.0);
	//joint_point2();

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_CHAR, 0.0);
    glRotatef(175, 1.0, 0.0, 0.0);
    //glRotatef(thetaC[7], 1.0, 0.0, 0.0);
	glRotatef(thetaC[13], 0.0, 0.0, 1.0);
    left_upper_leg(texture4);

	glTranslatef(0.0, UPPER_LEG_HEIGHT_CHAR, 0.0);
	joint_point(texture4);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_CHAR, 0.0);
    glRotatef(thetaC[8], 1.0, 0.0, 0.0);
    left_lower_leg(texture4);

    glTranslatef(0.0, LOWER_LEG_HEIGHT_CHAR, -0.5*FOOT_HEIGHT_CHAR);
	glRotatef(thetaC[15], 1.0, 0.0, 0.0);
	left_foot();

    glPopMatrix();
    glPushMatrix();

    glTranslatef(TORSO_RADIUS_CHAR-JOINT_POINT_RADIUS_CHAR, 
							-0.15*JOINT_POINT_HEIGHT_CHAR, 0.0);
	joint_point(texture4);

	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT_CHAR, 0.0);
    //glRotatef(thetaC[9], 1.0, 0.0, 0.0);
    glRotatef(175, 1.0, 0.0, 0.0);
	glRotatef(thetaC[14], 0.0, 0.0, 1.0);
    right_upper_leg(texture4);

	glTranslatef(0.0, UPPER_LEG_HEIGHT_CHAR, 0.0);
	joint_point(texture4);

    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT_CHAR, 0.0);
    glRotatef(thetaC[10], 1.0, 0.0, 0.0);
    right_lower_leg(texture4);
	
	glTranslatef(0.0, LOWER_LEG_HEIGHT_CHAR, -0.5*FOOT_HEIGHT_CHAR);
	glRotatef(thetaC[16], 1.0, 0.0, 0.0);
	right_foot();
    
	glPopMatrix();
}
void CharmanderModel::enableShade(){
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
    hC=gluNewQuadric();
	gluQuadricDrawStyle(hC, GLU_FILL);
	
	nC=gluNewQuadric();
	gluQuadricDrawStyle(nC, GLU_FILL);

	tC=gluNewQuadric();
	gluQuadricDrawStyle(tC, GLU_FILL);

	jpC=gluNewQuadric();
	gluQuadricDrawStyle(jpC, GLU_FILL);

    luaC=gluNewQuadric();
	gluQuadricDrawStyle(luaC, GLU_FILL);

    llaC=gluNewQuadric();
    gluQuadricDrawStyle(llaC, GLU_FILL);

    lhndC=gluNewQuadric();
	gluQuadricDrawStyle(lhndC, GLU_FILL);

	rhndC=gluNewQuadric();
	gluQuadricDrawStyle(rhndC, GLU_FILL);

	rftC=gluNewQuadric();
	gluQuadricDrawStyle(rftC, GLU_FILL);

	lftC=gluNewQuadric();
	gluQuadricDrawStyle(lftC, GLU_FILL);

	ruaC=gluNewQuadric();
    gluQuadricDrawStyle(ruaC, GLU_FILL);

    rlaC=gluNewQuadric();
    gluQuadricDrawStyle(rlaC, GLU_FILL);

    lulC=gluNewQuadric();
    gluQuadricDrawStyle(lulC, GLU_FILL);

    lllC=gluNewQuadric();
    gluQuadricDrawStyle(lllC, GLU_FILL);

    rulC=gluNewQuadric();
    gluQuadricDrawStyle(rulC, GLU_FILL);

    rllC=gluNewQuadric();
    gluQuadricDrawStyle(rllC, GLU_FILL);
}
void CharmanderModel::disableShade(){
	glDisable(GL_LIGHTING); 
    glDisable(GL_LIGHT0);
}
