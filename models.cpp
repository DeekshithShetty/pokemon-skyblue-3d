#include "headers.h"

void Model::drawBuildings(int x,int y,int z,int size,GLuint texture){
    glPushMatrix();
    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glBindTexture(GL_TEXTURE_2D,texture);
		glTranslatef(x,y,z);
    	glutSolidCube(size);
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
    	
    glPopMatrix();										// Done Drawing The Quad
    glFlush();
}

void Model::rectangle(){
	glPushMatrix();           
	  	glBegin(GL_QUADS);                  // Draw A Quad
		    glVertex3f(-10.5f, 0.0f,  10.5f);          
		    glVertex3f(10.5f, 0.0f,  10.5f);          
		    glVertex3f(10.5f, 0.0f, -10.5f);          
		    glVertex3f(-10.5f, 0.0f, -10.5f);          
	  	glEnd();                      // Done Drawing The Quad
  	glPopMatrix();
}
void Model::drawStadium(GLuint texture1,GLuint texture2,GLuint texture3,GLuint texture4){
	glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture1);   // choose the texture to use.
	 glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quad
   		glColor3f(0.8f, 0.8f, 0.8f);     // Green
  	 	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.0f, -9.0f,  9.0f);	
	    glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.0f, -9.0f,  9.0f);	// Bottom Right Of The Texture and Quad
	    glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.0f, -9.0f, -0.0f);	// Top Right Of The Texture and Quad
	    glTexCoord2f(1.0f, 0.0f); glVertex3f(7.0f, -9.0f, -0.0f);	// Top Left Of The Texture and Quad
 	glEnd();

 	glBindTexture(GL_TEXTURE_2D, texture3);   // choose the texture to use.
	 glBegin(GL_QUADS);
 	// Back face (z = -1.0f)

	 glColor3f(0.6f, 0.6f, 0.6f);
	 	glTexCoord2f(0.0f, 0.0f); glVertex3f( 9.0f, -9.0f, 0.01f);	// Bottom Left Of The Texture and Quad
	    glTexCoord2f(1.0f, 0.0f); glVertex3f(-9.0f, -9.0f, 0.01f);	// Bottom Right Of The Texture and Quad
	    glTexCoord2f(1.0f, 1.0f); glVertex3f(-9.0f,  15.0f, 0.01f);	// Top Right Of The Texture and Quad
	    glTexCoord2f(0.0f, 1.0f); glVertex3f(9.0f,  15.0f, 0.01f);	// Top Left Of The Texture and Quad
 	glEnd();
 	

   //glBindTexture(GL_TEXTURE_2D, texture3); 
  glBegin(GL_POLYGON);
    glColor3f(0.1,0.0,0.8);
    //glTexCoord2f(0.0f, 0.0f);
     glVertex3f(-15.0f,-8.99f,0.0f);
    //glTexCoord2f(1.0f, 0.0f);
     glVertex3f(0.0f,-8.99f,16.5f);
    //glTexCoord2f(1.0f, 1.0f);
     glVertex3f(15.0f,-8.99f,0.0f);
  glEnd();
  glDisable(GL_TEXTURE_2D);

 	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
     	glColor3f(0.7f, 0.0f, 0.0f);     // Red
	 	glVertex3f(7.0f, -9.0f,  9.0f);	// Bottom Left Of The Texture and Quad
	    glVertex3f(9.0f, -7.0f,  9.0f);	// Bottom Right Of The Texture and Quad
	    glVertex3f(9.0f, -7.0f,  0.0f);	// Top Right Of The Texture and Quad
	    glVertex3f(7.0f, -9.0f, 0.0f);	// Top Left Of The Texture and Quad
 	glEnd();

 	glBegin(GL_QUADS); 
 		glColor3f(0.7f, 0.0f, 0.0f);     // Red
	 	glVertex3f(-9.0f, -7.0f,  9.0f);	// Bottom Left Of The Texture and Quad
	    glVertex3f(-7.0f, -9.0f,  9.0f);	// Bottom Right Of The Texture and Quad
	    glVertex3f(-7.0f, -9.0f, 0.0f);	// Top Right Of The Texture and Quad
	    glVertex3f(-9.0f, -7.0f, 0.0f);
 	glEnd();

/*
  glPushMatrix();
    glTranslatef(-0.5f, 0.0f, 0.1f);  // translate to just above ground
    glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
    glColor3f(1.0, 0.0, 0.2);
    glutSolidSphere(2.0, 20, 20); // shadow same size as body
  glPopMatrix();
*/
 	glBegin(GL_QUADS); 

 		glColor3f(0.0f, 0.0f, 0.1f);     // Green-Statdium back
      glVertex3f( 9.0f, 15.0f, -1.0f);
      glVertex3f(-9.0f, 15.0f, -1.0f);
      glVertex3f(-9.0f, 15.0f,  9.0f);
      glVertex3f( 9.0f, 15.0f,  9.0f);

      // Bottom face (y = -1.0f)
      glColor3f(0.0f, 0.0f, 0.0f);     // front door
      glVertex3f( 2.0f, -9.01f,  3.0f);
      glVertex3f(-2.0f, -9.01f,  3.0f);
      glVertex3f(-2.0f, -9.01f, -3.0f);
      glVertex3f( 2.0f, -9.01f, -3.0f);

      glColor3f(0.0f, 0.0f, 0.0f);     //  door back
      glVertex3f( 2.0f, -8.98f,  3.0f);
      glVertex3f(-2.0f, -8.98f,  3.0f);
      glVertex3f(-2.0f, -8.98f, -3.0f);
      glVertex3f( 2.0f, -8.98f, -3.0f);

      // Front face  (z = 1.0f)
      glColor3f(0.1f, 0.1f, 0.1f);     // Black-stadium top
      glVertex3f( 9.0f,  15.0f, 9.0f);
      glVertex3f(-9.0f,  15.0f, 9.0f);
      glVertex3f(-9.0f, -9.0f, 9.0f);
      glVertex3f( 9.0f, -9.0f, 9.0f);
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 0.1f);     // Blue-stadium left(my)
      glVertex3f(-9.0f,  15.0f,  9.0f);
      glVertex3f(-9.0f,  15.0f, -9.0f);
      glVertex3f(-9.0f, -7.0f, -9.0f);
      glVertex3f(-9.0f, -7.0f,  9.0f);

      // Right face (x = 1.0f)
      glColor3f(0.0f, 0.0f, 0.1f);     // Magenta-stadium right
      glVertex3f(9.0f,  15.0f, -9.0f);
      glVertex3f(9.0f,  15.0f,  9.0f);
      glVertex3f(9.0f, -7.0f,  9.0f);
      glVertex3f(9.0f, -7.0f, -9.0f);

	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 0.4f);     // Blue-stadium left(my)
      	glVertex3f(-9.0f, -7.0f, 0.0f);
      	glVertex3f(-9.0f, -7.0f,  9.0f);
      	glVertex3f(-13.0f,-7.0f,  9.0f);

      	glVertex3f(9.0f, -7.0f, 0.0f);
      	glVertex3f(9.0f, -7.0f,  9.0f);
      	glVertex3f(13.0f,-7.0f,  9.0f);
	glEnd();

     glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture4);
	 //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	 //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 glBegin(GL_QUADS); 

      	//glColor3f(0.5f, 0.5f, 0.5f);
	 	glColor3f(1.0f, 1.0f, 0.0f);
      	//glColor3f(1.0f, 1.0f, 1.0f);
      	glTexCoord2f(2.0f, 2.0f);     //  Audience Left(my)
      	glVertex3f(-8.99f,  15.0f,  4.0f);
      	glTexCoord2f(2.0f, 0.0f);
      	glVertex3f(-4.99f,  15.0f, -4.0f);
      	glTexCoord2f(0.0f, 0.0f);
      	glVertex3f(-4.99f, -7.0f, -4.0f);
      	glTexCoord2f(0.0f, 2.0f);
      	glVertex3f(-8.99f, -7.0f,  4.0f);
 

      //glColor3f(0.5f, 0.5f, 0.5f);     //  Audience(Right)
      	glColor3f(1.0f, 1.0f, 0.0f);
      //glColor3f(1.0f, 1.0f, 1.0f);
      glTexCoord2f(2.0f, 0.0f);  
      glVertex3f(4.99f,  15.0f, -4.0f);
      glTexCoord2f(2.0f, 2.0f);
      glVertex3f(8.99f,  15.0f,  4.0f);
      glTexCoord2f(0.0f, 2.0f);
      glVertex3f(8.99f, -7.0f,  4.0f);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(4.99f, -7.0f, -4.0f);

      //glColor3f(0.5f, 0.5f, 0.5f);    //  Audience Back
      glColor3f(1.0f, 1.0f, 0.0f);
      //glColor3f(1.0f, 1.0f, 1.0f);
      glTexCoord2f(1.0f, 0.0f); 
      glVertex3f( 9.0f, 12.99f, 0.0f);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-9.0f, 12.99f, 0.0f);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-9.0f, 14.99f,  4.0f);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f( 9.0f, 14.99f,  4.0f);

    glDisable(GL_TEXTURE_2D);

   glEnd();  // End of drawing color-cube
 	
}
void Model::drawSignBoard(GLuint texture){
	glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture);
	

 	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quad
   		glColor3f(1.f, 1.0f, 1.0f);     // Green
  	 	glTexCoord2f(0.0f, 1.0f);
  	 	 glVertex3f(-28.0f, -12.0f,  7.0f);	// Bottom Left Of The Texture and Quad
	    glTexCoord2f(1.0f, 1.0f); 
	    glVertex3f(-20.0f, -6.0f,  7.0f);	// Bottom Right Of The Texture and Quad
	    glTexCoord2f(1.0f, 0.0f);
	     glVertex3f(-20.0f, -6.0f, 1.0f);	// Top Right Of The Texture and Quad
	    glTexCoord2f(0.0f, 0.0f); 
	    glVertex3f(-28.0f, -12.0f, 1.0f);	// Top Left Of The Texture and Quad
 	glEnd();
 	glPushMatrix();
	 	glTranslatef(-28.0,-12.0, 0.0);
	 	GLUquadricObj *quadratic3;
		quadratic3 = gluNewQuadric();
		gluCylinder(quadratic3, 0.1f, 0.1f, 5.0, 32, 32);
		glFlush();
	glPopMatrix();	
	glPushMatrix();
		glTranslatef(-20.0,-6.0, 0.0);
	 	GLUquadricObj *quadratic4;
		quadratic4 = gluNewQuadric();
		gluCylinder(quadratic4, 0.1f, 0.1f, 5.0, 32, 32);
		glFlush();
	glPopMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quad
   		glColor3f(1.0f, 1.0f, 1.0f);     // Green
  	 	 glVertex3f(8.0f, -9.0f,  17.0f);	// Bottom Left Of The Texture and Quad
	    glVertex3f(-8.0f, -9.0f,  17.0f);	// Bottom Right Of The Texture and Quad
	     glVertex3f(-8.0f, -9.0f, 9.5f);	// Top Right Of The Texture and Quad
	    glVertex3f(8.0f, -9.0f, 9.5f);	// Top Left Of The Texture and Quad
 	glEnd();

	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quad
   		glColor3f(1.f, 1.0f, 1.0f);     // Green
  	 	glTexCoord2f(1.0f, 1.0f);
  	 	 glVertex3f(7.0f, -9.0f,  16.0f);	// Bottom Left Of The Texture and Quad
	    glTexCoord2f(0.0f, 1.0f); 
	    glVertex3f(-7.0f, -9.0f,  16.0f);	// Bottom Right Of The Texture and Quad
	    glTexCoord2f(0.0f, 0.0f);
	     glVertex3f(-7.0f, -9.0f, 10.5f);	// Top Right Of The Texture and Quad
	    glTexCoord2f(1.0f, 0.0f); 
	    glVertex3f(7.0f, -9.0f, 10.5f);	// Top Left Of The Texture and Quad
 	glEnd();

	glDisable(GL_TEXTURE_2D);
				
}

void Model::drawGround(GLuint texture){
	glColor3f(0.0,0.5,0.1);
	glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture);   // choose the texture to use.
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
	 	glVertex3f(-100.0, -100.0, 0.0);	// Bottom Left Of The Texture and Quad
	    glTexCoord2f(0.0f, 10.0f); 
	    glVertex3f(-100.0,  100.0, 0.0);	// Bottom Right Of The Texture and Quad
	    glTexCoord2f(10.0f, 10.0f); 
	    glVertex3f(100.0,  100.0, 0.0);	// Top Right Of The Texture and Quad
	    glTexCoord2f(10.0f, 0.0f); 
	    glVertex3f( 100.0, -100.0, 0.0);	// Top Left Of The Texture and Quad
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void Model::drawRoute(GLuint texture){
	glColor3f(0.6705882352f, 0.6588235294f, 0.3607843137f);
	glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture);   // choose the texture to use.
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
	 	glVertex3f(1.0, -50.0, 0.01);	// Bottom Left Of The Texture and Quad
	    glTexCoord2f(0.0f, 10.0f); 
	    glVertex3f(1.0,  20.0, 0.01);	// Bottom Right Of The Texture and Quad
	    glTexCoord2f(10.0f, 10.0f); 
	    glVertex3f(6.0,  20.0, 0.01);	// Top Right Of The Texture and Quad
	    glTexCoord2f(10.0f, 0.0f); 
	    glVertex3f( 6.0, -50.0, 0.01);	// Top Left Of The Texture and Quad
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void Model::drawGrass(float pHeight){
	glColor3f(0.0, 0.6, 0.1);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glRotatef(85.0, -1.0, 0.0, 1.0);
	gluCylinder(quadratic, 0.1f, 0.0f, pHeight, 32, 32);
	glRotatef(85.0, 0.0, 1.0, 1.0);
	gluCylinder(quadratic, 0.1f, 0.0f, pHeight, 32, 32);
	glRotatef(85.0, 0.0,-1.0, 1.0);
	gluCylinder(quadratic, 0.1f, 0.0f, pHeight, 32, 32);
	glRotatef(85.0, 1.0,0.0, 1.0);
	gluCylinder(quadratic, 0.1f, 0.0f, pHeight, 32, 32);
	glFlush();
}
void Model::drawCylinder(float pHeight,GLuint texture){
	glColor3f(0.5f, 0.35f, 0.05f);
	glEnable(GL_TEXTURE_2D);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		gluQuadricNormals(quadratic, GLU_SMOOTH);
		gluQuadricTexture(quadratic, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		gluCylinder(quadratic, 0.8f, 0.8f, pHeight, 32, 32);
	    glFlush();
	glDisable(GL_TEXTURE_2D);    

}
void Model::drawCone(float pHeight,GLuint texture){
	glColor3f(0.1, 0.5, 0.2);
    glEnable(GL_TEXTURE_2D);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		gluQuadricNormals(quadratic, GLU_SMOOTH);
		gluQuadricTexture(quadratic, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture);
		gluCylinder(quadratic, 2.5f, 0.0f, pHeight, 32, 32);
	    glFlush();
	glDisable(GL_TEXTURE_2D);  
	glFlush();
}