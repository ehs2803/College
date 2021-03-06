

////// Includes
//#include <windows.h>					// standard Windows app include
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

////// Global Variables
float angle = 0.0f;						// current angle of the rotating triangle
//HDC g_HDC;								// global device context
bool fullScreen = false;					
float location = -15.0;

////// Robot variables
float legAngle[4] = { 0.0f, 0.0f,-30.0f,-30.0f };		// each leg's current angle
float armAngle[4] = {0.0f, 0.0f,90.0f,90.0f };

// DrawCube
// desc: since each component of the robot is made up of
//       cubes, we will use a single function that will
//		 draw a cube at a specified location.
void DrawCube(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.0f, 0.0f);	// top face
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, 0.0f, 0.0f);
			
			glVertex3f(0.0f, 0.0f, 0.0f);	// front face
			glVertex3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, 0.0f);
			
			// right face
			glVertex3f(0.0f, 0.0f, -1.0f);	
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, -1.0f);

			glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
			glVertex3f(-1.0f, 0.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			
			glVertex3f(0.0f, -1.0f, 0.0f);	// bottom face   mid = 0.0
			glVertex3f(0.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			
			// back face
			glVertex3f(0.0f, 0.0f, -1.0f);	
			glVertex3f(0.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, -1.0f, -1.0f);
			glVertex3f(-1.0f, 0.0f, -1.0f);
			
		glEnd();
	glPopMatrix();
}

// DrawArm
// desc: draws one arm
void DrawArm(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);	// red
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
		DrawCube(0.0f, 0.0f, 0.0f);

	glPopMatrix();
}
//DrawArm(2.5f, 0.0f, -0.5f);
void DrawArm1(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 1.0f);	// red
	glTranslatef(2.5, -1.0, 2.0);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);

	glColor3f(0.9f, 0.7f, 0.2f);
	glTranslatef(0.0, -1.0, 0.0);
	glScalef(1.0f, 0.2f, 1.0f);
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
// DrawHead
// desc: draws the robot head
void DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);	// white
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
		DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawTorso
// desc: draws the robot torso
void DrawTorso(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);	// blue
		glTranslatef(xPos, yPos, zPos);
		glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
		DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawLeg
// desc: draws a single leg
void DrawLeg(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);	// yellow
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
		DrawCube(0.0f, 0.0f, 0.0f);
		
		
	glPopMatrix();
}

void DrawLeg1(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.0f, 0.5f, 1.0f);	
	glTranslatef(-0.5, -6.0 , -4.0);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glTranslatef(0.0, -1.0, 0.0);
	glScalef(1.5f, 0.2f, 1.5f);
	DrawCube(0.0f, 0.0f, 0.0f);

	glPopMatrix();
}

// DrawRobot
// desc: draws the robot located at (xpos,ypos,zpos)
void DrawRobot(float xPos, float yPos, float zPos)
{
	static bool leg1 = true;		// robot's leg states
	static bool leg2 = false;		// true = forward, false = back
	
	static bool arm1 = true;
	static bool arm2 = false;

	

	//###############################################################################################################
	glPushMatrix();	

		glTranslatef(xPos, yPos, zPos);	// draw robot at desired coordinates

	// draw components
		DrawHead(1.0f, 2.0f, 0.0f);		
		DrawTorso(1.5f, 0.0f, 0.0f);
		glPushMatrix();
			// if leg is moving forward, increase angle, else decrease angle
			if (arm1) {
				armAngle[0] = armAngle[0] + 0.03f;
			}
			else {
				armAngle[0] = armAngle[0] - 0.03f;
			}

			// once leg has reached its maximum angle in a direction,
			// reverse it
			if (armAngle[0] >= 15.0f)
					arm1 = false;
			if (armAngle[0] <= -15.0f)
					arm1 = true;

			// move the leg away from the torso and rotate it to give "walking" effect
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);
			DrawArm(2.5f, 0.0f, -0.5f);

			
		glPopMatrix();
		//###############################################################################################################
		
		glPushMatrix();
		// if leg is moving forward, increase angle, else decrease angle
		if (arm1)
			armAngle[2] = armAngle[2] + 0.03f;
		else
			armAngle[2] = armAngle[2] - 0.03f;

		// once leg has reached its maximum angle in a direction,
		// reverse it
		

		// move the leg away from the torso and rotate it to give "walking" effect
		glTranslatef(-4.0f, -0.5f, 0.0f);
		glRotatef(armAngle[2], 1.0f, 0.0f, 0.0f);
		DrawArm1(2.5f, 0.0f, -0.5f);
		glPopMatrix();
		
		//###############################################################################################################
		glPushMatrix();
			// if leg is moving forward, increase angle, else decrease angle
			if (arm2)
				armAngle[1] = armAngle[1] + 0.03f;
			else
				armAngle[1] = armAngle[1] - 0.03f;

			// once leg has reached its maximum angle in a direction,
			// reverse it
			if (armAngle[1] >= 15.0f)
					arm2 = false;
			if (armAngle[1] <= -15.0f)
					arm2 = true;

			// move the leg away from the torso and rotate it to give "walking" effect
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);
			DrawArm(-1.5f, 0.0f, -0.5f);
			//DrawArm1(2.5f, 0.0f, -0.5f);
		glPopMatrix();
		//###############################################################################################################
		glPushMatrix();
		// if leg is moving forward, increase angle, else decrease angle
		if (arm2)
			armAngle[3] = armAngle[3] + 0.03f;
		else
			armAngle[3] = armAngle[3] - 0.03f;


		// move the leg away from the torso and rotate it to give "walking" effect
		glTranslatef(0.0f, -0.5f, 0.0f);
		glRotatef(armAngle[3], 1.0f, 0.0f, 0.0f);
		//DrawArm(-1.5f, 0.0f, -0.5f);
		DrawArm1(2.5f, 0.0f, -0.5f);
		glPopMatrix();


		//###############################################################################################################
		// we want to rotate the legs relative to the robot's position in the world
		// this is leg 1, the robot's right leg
		glPushMatrix();					

			// if leg is moving forward, increase angle, else decrease angle
			if (leg1)
				legAngle[0] = legAngle[0] + 0.03f;
			else
				legAngle[0] = legAngle[0] - 0.03f;

			// once leg has reached its maximum angle in a direction,
			// reverse it
			if (legAngle[0] >= 15.0f)
					leg1 = false;
			if (legAngle[0] <= -15.0f)
					leg1 = true;

			// move the leg away from the torso and rotate it to give "walking" effect
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(legAngle[0], 1.0f, 0.0f, 0.0f);

			// draw the leg
			DrawLeg(-0.5f, -5.0f, -0.5f);
			//DrawLeg1(-0.5f, -5.0f, -0.5f);
		glPopMatrix();
		//###############################################################################################################
		glPushMatrix();

		// if leg is moving forward, increase angle, else decrease angle
		if (leg1)
			legAngle[2] = legAngle[2] + 0.03f;
		else
			legAngle[2] = legAngle[2] - 0.03f;

		// once leg has reached its maximum angle in a direction,
		// reverse it
		if (legAngle[0] >= 15.0f)
			leg1 = false;
		if (legAngle[0] <= -15.0f)
			leg1 = true;

		// move the leg away from the torso and rotate it to give "walking" effect
		glTranslatef(0.0f, -0.5f, 0.0f);
		glRotatef(legAngle[2], 1.0f, 0.0f, 0.0f);

		// draw the leg
		//DrawLeg(-0.5f, -5.0f, -0.5f);
		DrawLeg1(-0.5f, -5.0f, -0.5f);
		glPopMatrix();
		//###############################################################################################################


		// do the same as above with leg 2, the robot's left leg
		glPushMatrix();

			if (leg2)
				legAngle[1] = legAngle[1] + 0.03f;
			else
				legAngle[1] = legAngle[1] - 0.03f;

			if (legAngle[1] >= 15.0f)
				leg2 = false;
			if (legAngle[1] <= -15.0f)
				leg2 = true;

			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(legAngle[1], 1.0f, 0.0f, 0.0f);
			DrawLeg(1.5f, -5.0f, -0.5f);
			
		glPopMatrix();
		//#############################################
		glPushMatrix();

		if (leg2)
			legAngle[3] = legAngle[3] + 0.03f;
		else
			legAngle[3] = legAngle[3] - 0.03f;

		if (legAngle[1] >= 15.0f)
			leg2 = false;
		if (legAngle[1] <= -15.0f)
			leg2 = true;

		
		glRotatef(legAngle[3], 1.0f, 0.0f, 0.0f);
	
		glTranslatef(2.0f, -0.1f, 0.0f);
		DrawLeg1(-0.5f, -5.0f, -0.5f);
		glPopMatrix();

	glPopMatrix();
}


void DrawGround() {
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);       //?????????? ?????? ???? ????
	glColor3f(0.5, 0.5, 0.5);           //????
	glTranslatef(-0.5, -0.5, -0.5);
	glScaled(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);                //??????
	glVertex3f(2.0f, -0.05f, 0.0f);	// top face
	glVertex3f(2.0f, -0.05f, -1.0f);
	glVertex3f(-2.1f, -0.05f, -1.0f);
	glVertex3f(-2.1f, -0.05f, 0.0f);

	glEnd();
	glFlush();
	glPopMatrix();

}

// Render
// desc: handles drawing of scene
void Render()
{
	int temp = 0.0;
	glEnable(GL_DEPTH_TEST);				// enable depth testing

	// do rendering here
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);					// clear to black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear screen and depth buffer
	glPushMatrix();
	//glLoadIdentity();
	DrawGround();
	glPopMatrix();
	//angle = angle + 0.05f;					// increase our rotation angle counter
	location = location + 0.001;
	if (location >= 15.0) location = -15.0;
	if (angle >= 360.0f)					// if we've gone in a circle, reset counter
		angle = 0.0f;
	

	glPushMatrix();							// put current matrix on stack
		glLoadIdentity();					// reset matrix
		glTranslatef(location, 0.0f, -30.0f);	// move to (0, 0, -30)
		glRotatef(270.0, 0.0f, 1.0f, 0.0f);	// rotate the robot on its y-axis
		DrawRobot(0.0f, 0.0f, 0.0f);		// draw the robot
	glPopMatrix();							// dispose of current matrix

	glFlush();

	//SwapBuffers(g_HDC);			// bring backbuffer to foreground
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("2019305059 ??????");
	glClearColor(1.0, 1.0, 1.0, 1.0);   //?????? ???? ????
	glutDisplayFunc(DrawGround);
	//glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}
