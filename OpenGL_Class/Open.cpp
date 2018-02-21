#include <GLAUX.H>
#include <GLUT.h>
#include <GL.H>


float cloudX = 30;
float chX = -30;
bool moveRight = true;
bool chMove = false;
bool birdFly =false;
float angelLeg = 0;
float birdX = 0;
float birdY = 0;

bool legDir = true;
void backGroungColor(){ 
	glClearColor(0.0,0.7,0.9,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void keyboard (unsigned char c , int x ,int y ){

switch(c){

	case 'r': chMove = !chMove;break;

	case 's': 
		 chMove = false;
		 birdFly =false;
		 birdX = 0;
		 birdY = 0;
		 chX = -30;
		 angelLeg = 0;
		 break;

}



}

void land(){
	glBegin(GL_POLYGON);
	glColor3f(0,1,0.2);
	glVertex3f(-45,-45,-1);
	glVertex3f(-45,15,-1);
	glVertex3f(45,15,-1);
	glVertex3f(45,-45,-1);
	glEnd();
}
void sun(){
	glPushMatrix();
	glColor3f(1,1,0);
	glTranslatef(-30,35,0);
	glScalef(1,1,0);
	auxSolidSphere(4);

	for(int i = 0; i <= 360; i+=30){
	glPushMatrix();
	glRotated(i,0,0,1);
	glTranslatef(0,3,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.3,1);
	glVertex2f(0.3,1);
	glVertex2f(0,4);
	glEnd();
	glPopMatrix();
	}
	glPopMatrix();


}
void cloud(){
	if(moveRight){
	if(cloudX <= 50) cloudX += 0.01;
		else moveRight = false;
	}

	if(!moveRight){
	if(cloudX >= -50) cloudX -= 0.01;
		else moveRight = true;
	}

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(cloudX,35,0);
	glScalef(1,1,0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(cloudX+2.4,34,0);
	glScalef(1,1,0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(cloudX-2.4,34,0);
	glScalef(1,1,0);
	auxSolidSphere(2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(cloudX,33,0);
	glScalef(1,1,0);
	auxSolidSphere(2);
	glPopMatrix();

}
void Tree(){
	glPushMatrix();
	glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(27,-30);
		glVertex2f(20,-30);
		glVertex2f(20,-8);
		glVertex2f(27,-8);
	glEnd();
	glTranslatef(0,0,1);
	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(18,-8,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(29,-8,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(18+4,-8+6,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(29-4,-8+6,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(18+5,-8,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(20,-8+5,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(27,-8+5,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();


	
	glPushMatrix();
	glColor3f(0,0.5,0);
	glTranslatef(23.5,-8+11,0);
	glScalef(1,1,0);
	auxSolidSphere(4);
	glPopMatrix();

	glPopMatrix();

}


void chicken(){
	
	if(chMove){

		chX += 0.01;
		if(legDir){
		if((int)angelLeg%30 < 29)angelLeg += 0.1;
		else legDir = false;
		}else
		{
			if((int)angelLeg%30 > -29)angelLeg -= 0.1;

			else legDir = true;
		}
		if(chX>0) birdFly = true;

		if(chX>10) chMove = false;
	}

	glPushMatrix();
	
	glTranslatef(chX,-25,0);
	
	glPushMatrix();
	glTranslatef(6.7,3,0);
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2f(-1,1);
	glVertex2f(-0.5,4.5);
	glVertex2f(0,3.5);
	glVertex2f(0.5,4.5);
	glVertex2f(0.5,1);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(6.7,3,0);
	glBegin(GL_TRIANGLES);
	glColor3f(1,0.7,0);
	glVertex2f(1,1.5);
	glVertex2f(1,-1.5);
	glVertex2f(6,0);
	glEnd();
	glPopMatrix();


	
	glPushMatrix();
	glRotatef(-angelLeg,0,0,1);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(1,1);
	glVertex2f(1,-10);
	glVertex2f(1,-10);
	glVertex2f(3,-10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angelLeg,0,0,1);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(1,1);
	glVertex2f(1,-10);
	glVertex2f(1,-10);
	glVertex2f(3,-10);
	glEnd();
	glPopMatrix();

	glColor3f(1,1,1);
	glTranslatef(0,0,0);
	glScaled(1,1,0);
	auxSolidSphere(5);

	glTranslatef(6.7,3,0);
	glScaled(1,1,0);
	auxSolidSphere(3);

	glColor3f(0,0,0);
	glTranslatef(1,1,0);
	glScaled(1,1,0);
	auxSolidSphere(0.5);

	
	

	glPopMatrix();
}

void bird(){

	if(birdFly){

		if(birdY < 30) birdY +=0.02;
		if(birdX < 10 && birdY > 15) birdX +=0.02;
	}

	glPushMatrix();
	glTranslatef(birdX,birdY,0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(15,-27);
	glVertex2f(17,-30);
	glVertex2f(17,-30);
	glVertex2f(19,-27);
	glEnd();
	glPopMatrix();
}

void view(){
	land();
	sun();
	cloud();
	Tree();
	chicken();
	bird();
}
void  draw(void)
{
	backGroungColor();
	glLoadIdentity();
	glTranslatef(0,0,-100);
	view();
	glutPostRedisplay();
	glutSwapBuffers();
}
void  myInit(void)
{
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1,5.0,-100.0);
	//glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
}

int main(int argc, char **argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
   	glutCreateWindow("First Example");
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	myInit();
	glutMainLoop();
	return 0;
}