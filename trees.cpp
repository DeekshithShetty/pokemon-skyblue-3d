#include "headers.h"

void Tree::drawCylinder(float pHeight){
	glColor3f(0.2f, 0.25f, 0.05f);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 0.8f, 0.8f, pHeight, 32, 32);
	    glFlush();
	glDisable(GL_TEXTURE_2D);    

}

void Tree::drawCone(float pHeight){
	glColor3f(0.1, 0.4, 0.1);
		quadratic = gluNewQuadric();
		gluCylinder(quadratic, 2.5f, 0.0f, pHeight, 32, 32);
	    glFlush();  
}

void Tree::drawTrees(){
	glPushMatrix();
        glTranslatef(-15.0,-15.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-15.0, -7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-15.0, 0.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-15.0,7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-7.5, -15.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-7.5, -7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-7.5, 0.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-7.5,7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    //-----------------------------------
    glPushMatrix();
        glTranslatef(0.0, -15.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, -7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();
    //--------------------------------------------
    glPushMatrix();
        glTranslatef(7.5, -15.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7.5, -7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7.5, 0.0, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7.5, 7.5, 0);
            drawCylinder(3.0); 
            glPushMatrix();
                glTranslatef(0.0,0.0, 3.0);
                drawCone(4.0);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0,0.0, 6.0);
                drawCone(4.0);
            glPopMatrix();
    glPopMatrix();
    
    	glDisable(GL_TEXTURE_2D);
}