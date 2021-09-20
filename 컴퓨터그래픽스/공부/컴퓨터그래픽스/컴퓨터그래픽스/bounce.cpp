/* bounce.c */

/*
 * Bouncing ball demo.
 *
 * This program is in the public domain
 *
 * Brian Paul
 */

 /* Conversion to GLUT by Mark J. Kilgard */
/*
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define COS(X)   cos( (X) * 3.14159/180.0 )
#define SIN(X)   sin( (X) * 3.14159/180.0 )

#define RED 1
#define WHITE 2
#define CYAN 3

GLuint Ball;
GLenum Mode;
GLfloat Zrot = 0.0, Zstep = 6.0;
GLfloat Xpos = 0.0, Ypos = 1.0;
GLfloat Xvel = 0.2, Yvel = 0.0;
GLfloat Xmin = -4.0, Xmax = 4.0;
GLfloat Ymin = -3.8, Ymax = 4.0;
GLfloat G = -0.1;

static GLuint
make_ball(void)
{
    GLuint list;
    GLfloat a, b;
    GLfloat da = 18.0, db = 18.0;
    GLfloat radius = 1.0;
    GLuint color;
    GLfloat x, y, z;

    list = glGenLists(1);

    glNewList(list, GL_COMPILE);

    color = 0;
    for (a = -90.0; a + da <= 90.0; a += da) {

        glBegin(GL_QUAD_STRIP);
        for (b = 0.0; b <= 360.0; b += db) {

            if (color) {
                glIndexi(RED);
            }
            else {
                glIndexi(WHITE);
            }

            x = COS(b) * COS(a);
            y = SIN(b) * COS(a);
            z = SIN(a);
            glVertex3f(x, y, z);

            x = radius * COS(b) * COS(a + da);
            y = radius * SIN(b) * COS(a + da);
            z = radius * SIN(a + da);
            glVertex3f(x, y, z);

            color = 1 - color;
        }
        glEnd();

    }

    glEndList();

    return list;
}

static void
reshape(int width, int height)
{
    glViewport(0, 0, (GLint)width, (GLint)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0);
    glMatrixMode(GL_MODELVIEW);
}


static void
key(unsigned char k, int x, int y)
{
    switch (k) {
    case 27: 
        exit(0);
    }
}

static void
draw(void)
{
    GLint i;

    glClear(GL_COLOR_BUFFER_BIT);

    glIndexi(CYAN);
    glBegin(GL_LINES);
    for (i = -5; i <= 5; i++) {
        glVertex2i(i, -5);
        glVertex2i(i, 5);
    }
    for (i = -5; i <= 5; i++) {
        glVertex2i(-5, i);
        glVertex2i(5, i);
    }
    for (i = -5; i <= 5; i++) {
        glVertex2i(i, -5);
        glVertex2f(i * 1.15, -5.9);
    }
    glVertex2f(-5.3, -5.35);
    glVertex2f(5.3, -5.35);
    glVertex2f(-5.75, -5.9);
    glVertex2f(5.75, -5.9);
    glEnd();

    glPushMatrix();
    glTranslatef(Xpos, Ypos, 0.0);
    glScalef(2.0, 2.0, 2.0);
    glRotatef(8.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(Zrot, 0.0, 0.0, 1.0);

    glCallList(Ball);

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

static void
idle(void)
{
    static float vel0 = -100.0;

    Zrot += Zstep;

    Xpos += Xvel;
    if (Xpos >= Xmax) {
        Xpos = Xmax;
        Xvel = -Xvel;
        Zstep = -Zstep;
    }
    if (Xpos <= Xmin) {
        Xpos = Xmin;
        Xvel = -Xvel;
        Zstep = -Zstep;
    }
    Ypos += Yvel;
    Yvel += G;
    if (Ypos < Ymin) {
        Ypos = Ymin;
        if (vel0 == -100.0)
            vel0 = fabs(Yvel);
        Yvel = vel0;
    }
    glutPostRedisplay();
}

void
visible(int vis)
{
    if (vis == GLUT_VISIBLE)
        glutIdleFunc(idle);
    else
        glutIdleFunc(NULL);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_INDEX | GLUT_DOUBLE);

    glutCreateWindow("Bounce");
    Ball = make_ball();
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glDisable(GL_DITHER);
    glShadeModel(GL_FLAT);

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutVisibilityFunc(visible);
    glutKeyboardFunc(key);

    glutSetColor(RED, 1.0, 0.0, 0.0);
    glutSetColor(WHITE, 1.0, 1.0, 1.0);
    glutSetColor(CYAN, 0.0, 1.0, 1.0);

    glutMainLoop();
    return 0;            
}

*/

/*
title: OpenGL GLUT bouncing ball code
tags:
- OpenGL
- C++
*/
#include <GL/glut.h>
#include <Math.h>

const float PI = 3.14159265f;

GLfloat ballRadius = 0.1f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
GLfloat ballXMax, ballXMin, ballYMax, ballYMin;
GLfloat xSpeed = 0.008f;
GLfloat ySpeed = 0.01f;
GLfloat xAcceleration = 0.0000f;
GLfloat yAcceleration = -0.0005f;
bool isPaused = false;
int refreshMillis = 16;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void display()
{
    if (isPaused) return;
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(ballX, ballY, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    int numSegments = 100;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++)
    {
        angle = i * 2.0f * PI / numSegments;
        glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
    }
    glEnd();

    glutSwapBuffers();
    xSpeed += xAcceleration;
    ySpeed += yAcceleration;
    ballX += xSpeed;
    ballY += ySpeed;
    if (ballX > ballXMax)
    {
        ballX = ballXMax;
        xSpeed = -xSpeed;
    }
    else if (ballX < ballXMin)
    {
        ballX = ballXMin;
        xSpeed = -xSpeed;
    }
    if (ballY > ballYMax)
    {
        ballY = ballYMax;
        ySpeed = -ySpeed;
    }
    else if (ballY < ballYMin)
    {
        ballY = ballYMin;
        ySpeed = -ySpeed;
    }
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height)
    {
        clipAreaXLeft = -1.0 * aspect;
        clipAreaXRight = 1.0 * aspect;
        clipAreaYBottom = -1.0;
        clipAreaYTop = 1.0;
    }
    else
    {
        clipAreaXLeft = -1.0;
        clipAreaXRight = 1.0;
        clipAreaYBottom = -1.0 / aspect;
        clipAreaYTop = 1.0 / aspect;
    }
    gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
    ballXMin = clipAreaXLeft + ballRadius;
    ballXMax = clipAreaXRight - ballRadius;
    ballYMin = clipAreaYBottom + ballRadius;
    ballYMax = clipAreaYTop - ballRadius;
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshMillis, timer, 0);

}

void keyboard(unsigned char key, int x, int y) {
    switch (key)
    {
    case 32:
        isPaused = !isPaused; break;
    default: break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("bouncing-ball");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}