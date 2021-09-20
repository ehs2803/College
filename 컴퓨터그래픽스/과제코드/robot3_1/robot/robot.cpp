#define WIN32_LEAN_AND_MEAN				// trim the excess fat from Windows

/*****************************************************

	Robot Example

	
	Animates a walking robot-like figure.

******************************************************/

////// Includes
#include <windows.h>					// standard Windows app include
#include <gl/gl.h>						// standard OpenGL include
#include <gl/glu.h>						// OpenGL utilties

////// Global Variables
float angle = 0.0f;						// current angle of the rotating triangle
HDC g_HDC;								// global device context
bool fullScreen = false;					
float location = -15.0;

////// Robot variables
float legAngle[4] = { 0.0f, 0.0f,-30.0f,-30.0f };		// each leg's current angle
float armAngle[4] = {0.0f, 0.0f,90.0f,90.0f };
int Width = 800, Height = 600;
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

void Drawground1() {
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);	// red
	glTranslatef(50, -10, 50);
	glScalef(100.0f, 1.0f, 100.0f);		// arm is a 1x4x1 cube
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

	
	glPushMatrix();
		Drawground1();
		glTranslatef(0.0f+location, 0.0f, 0.0f + location);
	glPopMatrix();
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
	glClear(GL_COLOR_BUFFER_BIT);       //�÷����ۿ� �ʱ�ȭ ���� ����
	//glColor3f(0.5, 0.0, 0.5);           //ȸ��
	//glTranslatef(0.0, 0.0, -30.0);
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(20.0, 0.0, 20.0);
	glVertex3f(20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, 20.0);
	glEnd();
	glPopMatrix();
	glFlush();
	/*
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);       //�÷����ۿ� �ʱ�ȭ ���� ����
	glColor3f(0.5, 0.0, 0.5);           //ȸ��
	glTranslatef(0.0, -1.0, 0.0);
	//glScaled(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);                //�簢��
	glVertex3f(100.0f, 0.0f, -100.0f);	// top face
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glEnd();
	
	glPopMatrix();
glFlush();
*/
}


// Render
// desc: handles drawing of scene
void Render()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -10.0, 25.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT);       //�÷����ۿ� �ʱ�ȭ ���� ����
	//glColor3f(0.5, 0.0, 0.5);           //ȸ��
	//glTranslatef(0.0, 0.0, -30.0);
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(20.0, 0.0, 20.0);
	glVertex3f(20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, -20.0);
	glVertex3f(-20.0, 0.0, 20.0);
	glEnd();
	glPopMatrix();
	glFlush();
	
	/// <summary>
	/// ////////////////////////////////////////
	/// </summary>
	//DrawGround();
	

	location = location + 0.001;
	if (location >= 15.0) location = -15.0;
	if (angle >= 360.0f)					// if we've gone in a circle, reset counter
		angle = 0.0f;
	glTranslatef(location, 0.0f, 0.0f);

	glClear(GL_COLOR_BUFFER_BIT);
	

	/*
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(10.0, -10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glTranslatef(location, 0.0f, 0.0f);
	//glRotatef(180.0, 0.0f, 1.0f, 0.0f);
	DrawRobot(0.0f, 0.0f, 0.0f);

	//glTranslatef(location, 0.0f, 0.0f);
	glPopMatrix();

	*/

	glViewport(02, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(70.0, -1.0, 1.0, 130.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(10.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawRobot(0.0f, 0.0f, 0.0f);
	glRotatef(90.0, 0.0f, 1.0f, 0.0f);
	DrawRobot(0.0f, 0.0f, 10.0f);
	glPopMatrix();
	/*
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(70.0, -1.0, 1.0, 130.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(15.0, 15.0, -15.0,     1.0, 0.0, 0.0,     0.0, 1.0, 0.0);
	glRotatef(90.0, 0.0f, 1.0f, 0.0f);
	DrawRobot(10.0f, 0.0f, 0.0f);
	glRotatef(-90.0, 0.0f, 1.0f, 0.0f);
	DrawRobot(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	*/
	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	glFlush();

	SwapBuffers(g_HDC);
	
	/*
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

	SwapBuffers(g_HDC);			// bring backbuffer to foreground
	*/
}

// function to set the pixel format for the device context
void SetupPixelFormat(HDC hDC)
{
	int nPixelFormat;					// our pixel format index

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),	// size of structure
		1,								// default version
		PFD_DRAW_TO_WINDOW |			// window drawing support
		PFD_SUPPORT_OPENGL |			// OpenGL support
		PFD_DOUBLEBUFFER,				// double buffering support
		PFD_TYPE_RGBA,					// RGBA color mode
		32,								// 32 bit color mode
		0, 0, 0, 0, 0, 0,				// ignore color bits, non-palettized mode
		0,								// no alpha buffer
		0,								// ignore shift bit
		0,								// no accumulation buffer
		0, 0, 0, 0,						// ignore accumulation bits
		16,								// 16 bit z-buffer size
		0,								// no stencil buffer
		0,								// no auxiliary buffer
		PFD_MAIN_PLANE,					// main drawing plane
		0,								// reserved
		0, 0, 0 };						// layer masks ignored

	nPixelFormat = ChoosePixelFormat(hDC, &pfd);	// choose best matching pixel format

	SetPixelFormat(hDC, nPixelFormat, &pfd);		// set pixel format to device context
}

// the Windows Procedure event handler
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hRC;					// rendering context
	static HDC hDC;						// device context
	int width, height;					// window width and height

	switch(message)
	{
		case WM_CREATE:					// window is being created

			hDC = GetDC(hwnd);			// get current window's device context
			g_HDC = hDC;
			SetupPixelFormat(hDC);		// call our pixel format setup function

			// create rendering context and make it current
			hRC = wglCreateContext(hDC);
			wglMakeCurrent(hDC, hRC);

			return 0;
			break;

		case WM_CLOSE:					// windows is closing

			// deselect rendering context and delete it
			wglMakeCurrent(hDC, NULL);
			wglDeleteContext(hRC);

			// send WM_QUIT to message queue
			PostQuitMessage(0);

			return 0;
			break;

		case WM_SIZE:
			height = HIWORD(lParam);		// retrieve width and height
			width = LOWORD(lParam);

			if (height==0)					// don't want a divide by zero
			{
				height=1;					
			}

			glViewport(0, 0, width, height);		// reset the viewport to new dimensions
			glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
			glLoadIdentity();						// reset projection matrix

			// calculate aspect ratio of window
			gluPerspective(54.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);

			glMatrixMode(GL_MODELVIEW);				// set modelview matrix
			glLoadIdentity();						// reset modelview matrix

			return 0;
			break;

		default:
			break;
	}

	return (DefWindowProc(hwnd, message, wParam, lParam));
}

// the main windows entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASSEX windowClass;		// window class
	HWND	   hwnd;			// window handle
	MSG		   msg;				// message
	bool	   done;			// flag saying when our app is complete
	DWORD	   dwExStyle;						// Window Extended Style
	DWORD	   dwStyle;						// Window Style
	RECT	   windowRect;

	// temp var's
	int width = 800;
	int height = 600;
	int bits = 32;

	//fullScreen = TRUE;

	windowRect.left=(long)0;						// Set Left Value To 0
	windowRect.right=(long)width;						// Set Right Value To Requested Width
	windowRect.top=(long)0;							// Set Top Value To 0
	windowRect.bottom=(long)height;						// Set Bottom Value To Requested Height

	// fill out the window class structure
	windowClass.cbSize			= sizeof(WNDCLASSEX);
	windowClass.style			= CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc		= WndProc;
	windowClass.cbClsExtra		= 0;
	windowClass.cbWndExtra		= 0;
	windowClass.hInstance		= hInstance;
	windowClass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);	// default icon
	windowClass.hCursor			= LoadCursor(NULL, IDC_ARROW);		// default arrow
	windowClass.hbrBackground	= NULL;								// don't need background
	windowClass.lpszMenuName	= NULL;								// no menu
	windowClass.lpszClassName	= "MyClass";
	windowClass.hIconSm			= LoadIcon(NULL, IDI_WINLOGO);		// windows logo small icon

	// register the windows class
	if (!RegisterClassEx(&windowClass))
		return 0;

	if (fullScreen)								// fullscreen?
	{
		DEVMODE dmScreenSettings;					// device mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);	
		dmScreenSettings.dmPelsWidth = width;			// screen width
		dmScreenSettings.dmPelsHeight = height;			// screen height
		dmScreenSettings.dmBitsPerPel = bits;				// bits per pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// 
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// setting display mode failed, switch to windowed
			MessageBox(NULL, "Display mode failed", NULL, MB_OK);
			fullScreen=FALSE;	
		}
	}

	if (fullScreen)								// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;					// Window Extended Style
		dwStyle=WS_POPUP;						// Windows Style
		ShowCursor(FALSE);						// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;					// Windows Style
	}

	AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// class registered, so now create our window
	hwnd = CreateWindowEx(NULL,									// extended style
						  "MyClass",							// class name
						  "2019305059 ������",		// app name
						  dwStyle | WS_CLIPCHILDREN |
						  WS_CLIPSIBLINGS,
						  0, 0,								// x,y coordinate
						  windowRect.right - windowRect.left,
						  windowRect.bottom - windowRect.top, // width, height
						  NULL,									// handle to parent
						  NULL,									// handle to menu
						  hInstance,							// application instance
						  NULL);								// no extra params

	// check if window creation failed (hwnd would equal NULL)
	if (!hwnd)
		return 0;

	ShowWindow(hwnd, SW_SHOW);			// display the window
	UpdateWindow(hwnd);					// update the window

	done = false;						// intialize the loop condition variable

	// main message loop
	while (!done)
	{
		PeekMessage(&msg, hwnd, NULL, NULL, PM_REMOVE);

		if (msg.message == WM_QUIT)		// do we receive a WM_QUIT message?
		{
			done = true;				// if so, time to quit the application
		}
		else
		{
			Render();

			TranslateMessage(&msg);		// translate and dispatch to event queue
			DispatchMessage(&msg);
		}
	}

	if (fullScreen)
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);						// Show Mouse Pointer
	}

	return msg.wParam;
}
