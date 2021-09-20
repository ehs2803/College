#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>	

float angle = 0.0f;						// current angle of the rotating triangle
								// global device context
bool fullScreen = false;

////// Robot variables
float legAngle[2] = { 0.0f, 0.0f };		// each leg's current angle
float armAngle[2] = { 0.0f, 0.0f };

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
void DrawArm(float xPos, float yPos, float zPos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r, g, b);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);

	glPopMatrix();
}
//DrawArm(2.5f, 0.0f, -0.5f);
void DrawArm1(float xPos, float yPos, float zPos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r, g, b);	// red
	//glTranslatef(2.5, -1.0, 2.0);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);

	glColor3f(r, g, b);
	glTranslatef(0.0, -1.0, 0.0);
	glScalef(1.0f, 0.2f, 1.0f);
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
// DrawHead
// desc: draws the robot head
void DrawHead(float xPos, float yPos, float zPos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r, g, b);	// white
	glTranslatef(xPos, yPos, zPos);
	glTranslatef(-1.0, -1.0, -1.0);
	glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();
}

// DrawTorso
// desc: draws the robot torso
void DrawTorso(float xPos, float yPos, float zPos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r, g, b);	// blue
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void DrawTorso1(float xPos, float yPos, float zPos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r, g, b);	// blue
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawLeg
// desc: draws a single leg
void DrawLeg(float xPos, float yPos, float zPos, float r, float g, float b)
{
	//glPushMatrix();
	glColor3f(r, g, b);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);


	//glPopMatrix();
}

void DrawLeg1(float xPos, float yPos, float zPos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslatef(-0.5, -6.0, -4.0);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);

	glColor3f(r, g, b);
	glTranslatef(0.0, -1.0, 0.0);
	glScalef(1.5f, 0.2f, 1.5f);
	DrawCube(0.0f, 0.0f, 0.0f);

	glPopMatrix();
}

// DrawRobot
// desc: draws the robot located at (xpos,ypos,zpos)
void DrawRobot(float xPos, float yPos, float zPos, float r, float g, float b)
{
	static bool leg1 = true;		// robot's leg states
	static bool leg2 = false;		// true = forward, false = back

	static bool arm1 = true;
	static bool arm2 = false;



	//###############################################################################################################


	glTranslatef(xPos, yPos, zPos);	// draw robot at desired coordinates

// draw components
	glColor3f(0.0f, 1.0f, 0.0f);
	DrawHead(1.0f, 2.0f, 0.0f, r, g, b);
	DrawTorso(1.5f, 0.0f, 0.0f, r, g, b);
	
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
	DrawArm(2.5f, 0.0f, -0.5f, r, g, b);


	
	//###############################################################################################################

	
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
	DrawArm1(2.5f, 0.0f, -0.5f, r, g, b);
	glPopMatrix();

	//###############################################################################################################
	
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
	DrawArm(-1.5f, 0.0f, -0.5f, r, g, b);
	//DrawArm1(2.5f, 0.0f, -0.5f);
	
	//###############################################################################################################
	
	// if leg is moving forward, increase angle, else decrease angle
	if (arm2)
		armAngle[3] = armAngle[3] + 0.03f;
	else
		armAngle[3] = armAngle[3] - 0.03f;


	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngle[3], 1.0f, 0.0f, 0.0f);
	//DrawArm(-1.5f, 0.0f, -0.5f);
	DrawArm1(2.5f, 0.0f, -0.5f, r, g, b);



	//###############################################################################################################
	// we want to rotate the legs relative to the robot's position in the world
	// this is leg 1, the robot's right leg


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
	DrawLeg(-0.5f, -5.0f, -0.5f, r, g, b);
	//DrawLeg1(-0.5f, -5.0f, -0.5f);
	

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
	DrawLeg1(-0.5f, -5.0f, -0.5f, r, g, b);

	//###############################################################################################################



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
	DrawLeg(1.5f, -5.0f, -0.5f, r, g, b);



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
	DrawLeg1(-0.5f, -5.0f, -0.5f, r, g, b);

}


void InitLight() {
	GLfloat light0_ambient[] = { 1.0, 1.0, 1.0, 0.0 };     //조명 특성
	GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 0.0 };

	GLfloat material_ambient[] = { 0.4, 0.4, 0.4, 1.0 };  //물체 특성
	GLfloat material_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat material_shininess[] = { 25.0 };

	glShadeModel(GL_SMOOTH);    //구로 셰이딩
	glEnable(GL_DEPTH_TEST);    //깊이 버퍼 활성화
	glEnable(GL_LIGHTING);      //조명 활성화
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
}

void glInit(void) { // 지엘 초기화 함수 
	glEnable(GL_DEPTH_TEST); // 깊이 테스팅 사용
	glEnable(GL_NORMALIZE);  // 정규화
	glEnable(GL_SMOOTH);     // 각 정점의 색상을 부드럽게 연결하여 칠해지도록  하므로, 각정점에 적용된 색상이 혼합되어 적용된다. 
	glEnable(GL_LIGHTING);   // 지엘 조명. 빛을 받는 각도에 따라 로봇 색상이 변화

	/* 빛을 받는 각도에 따라 로봇 색깔의 변화를 위한 설정 */
	GLfloat ambientLight[] = { 0.3f,0.3f,0.3f,1.0f };
	GLfloat diffuseLight[] = { 0.7f,0.7f,0.7f,1.0f };
	GLfloat specular[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat specref[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat position[] = { 400.0,300.0,-700.0,1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glClearColor(1.0, 1.0, 1.0, 1.0); // 배경 검은색
	glMatrixMode(GL_PROJECTION);   // 모드 설정
	glLoadIdentity();              // CTM 값 초기화 
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시 범위 설정
}

int Width = 700, Height = 700;
// Render
// desc: handles drawing of scene
void Render()
{
	/*
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0f, 5.0f, -1.0f); DrawRobot(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0f, 5.0f, -1.0f); DrawRobot(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	glTranslatef(0.0f, 5.0f, -1.0f); DrawRobot(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(30, 1.0, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0f, 5.0f, -1.0f); DrawRobot(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
	*/
	GLfloat LightPosition[] = { 0.0, 0.0, 0.0, 1.0 };
	//glEnable(GL_DEPTH_TEST);				// enable depth testing
	glClear(GL_COLOR_BUFFER_BIT);
	// do rendering here
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);					// clear to black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// clear screen and depth buffer
	//glLoadIdentity();										// reset modelview matrix


	glPushMatrix();							// put current matrix on stack
	//glLoadIdentity();					// reset matrix
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	//glTranslatef(0.0f, 5.0f, -1.0f);	// move to (0, 0, -30)
	glRotatef(angle, 0.0f, 1.0f, 0.0f);	// rotate the robot on its y-axis
	DrawRobot(0.0f, 0.0f, 0.0f,1.0,0.0,0.0);		// draw the robot

	glPopMatrix();							// dispose of current matrix

	glFlush();

}

void MyTimer(int Value) {
	angle = angle + 1.0f;
	if (angle >= 360.0f)					// if we've gone in a circle, reset counter
		angle = 0.0f;
	glutPostRedisplay();
	glutTimerFunc(10, MyTimer, 1);
}

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	//glOrtho(-10.0, 10.0, -10.0, 10.0, -15.0, 15.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	//Init();
	//InitLight();
	glInit();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -15.0, 15.0);
	glutDisplayFunc(Render);
	glutTimerFunc(10, MyTimer, 1);
	glutMainLoop();
	return 0;
}