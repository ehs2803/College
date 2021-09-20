#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <time.h>



GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

GLboolean pink = true;
GLboolean yellow = false;
GLboolean orange = false;

GLboolean IsSmall = true;

void display()
{
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
/*
void MyDisplay() {
    glViewport(0, 0, 1000, 1000);
    glClear(GL_COLOR_BUFFER_BIT);

    if (pink == true) glColor3f(1.0, 0.0, 0.9);
    else if (yellow == true) glColor3f(1.0, 1.0, 0.0);
    else glColor3f(1.0, 0.7, 0.0);

    if (IsSmall == true) {
        glBegin(GL_POLYGON);
        glVertex3f(TopLeftX / 1000.0, (1000 - TopLeftY) / 1000.0, 0.0);
        glVertex3f(TopLeftX / 1000.0, (1000 - BottomRightY) / 1000.0, 0.0);
        glVertex3f(BottomRightX / 1000.0, (1000 - BottomRightY) / 1000.0, 0.0);
        glVertex3f(BottomRightX / 1000.0, (1000 - TopLeftY) / 1000.0, 0.0);
        glEnd();
    }
    else {
        glBegin(GL_POLYGON);
        glVertex3f((TopLeftX / 1000.0) * (-0.1), ((1000 - TopLeftY) / 1000.0) * (0.1), 0.0);
        glVertex3f((TopLeftX / 1000.0) * (-0.1), ((1000 - BottomRightY) / 1000.0) * (-0.1), 0.0);
        glVertex3f((BottomRightX / 1000.0) * (0.1), ((1000 - BottomRightY) / 1000.0) * (-0.1), 0.0);
        glVertex3f((BottomRightX / 1000.0) * (0.1), ((1000 - TopLeftY) / 1000.0) * (0.1), 0.0);
        glEnd();
    }
    glFlush();
}
*/

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_RIGHT:
        break;
    case 'P':
        pink = true;
        yellow = false;
        orange = false;
        glutPostRedisplay();
        break;
    case 'p':
        pink = true;
        yellow = false;
        orange = false;
        glutPostRedisplay();
        break;
    case 'Y':
        pink = false;
        yellow = true;
        orange = false;
        glutPostRedisplay();
        break;
    case 'y':
        pink = false;
        yellow = true;
        orange = false;
        glutPostRedisplay();
        break;
    case 'O':
        pink = false;
        yellow = false;
        orange = true;
        glutPostRedisplay();
        break;
    case 'o':
        pink = false;
        yellow = false;
        orange = true;
        glutPostRedisplay();
        break;
    }

}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
}

void MyMainMenu(int entryID) { }

void MySubMenu_size(int entryID) {
    if (entryID == 1)
        IsSmall = true;
    else if (entryID == 2)
        IsSmall = false;
    glutPostRedisplay();
}

void MySubMenu_fast(int entryID) {
    if (entryID == 1)
        IsSmall = true;
    else if (entryID == 2)
        IsSmall = false;
    glutPostRedisplay();
}

void MySubMenu_color(int entryID) {
    if (entryID == 1) {
        pink = true;
        yellow = false;
        orange = false;
    }
    else if (entryID == 2) {
        pink = false;
        yellow = true;
        orange = false;
    }
    else if (entryID == 3) {
        pink = false;
        yellow = false;
        orange = true;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2019305059 이현수");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    GLint MySubMenuID1 = glutCreateMenu(MySubMenu_size);
    glutAddMenuEntry("작게", 1);
    glutAddMenuEntry("크게", 2);

    GLint MySubMenuID2 = glutCreateMenu(MySubMenu_fast);
    glutAddMenuEntry("느리게", 1);
    glutAddMenuEntry("빠르게", 2);

    GLint MySubMenuID3 = glutCreateMenu(MySubMenu_color);
    glutAddMenuEntry("핑크", 1);
    glutAddMenuEntry("노랑", 2);
    glutAddMenuEntry("주황", 3);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("크기", MySubMenuID1);
    glutAddSubMenu("속도", MySubMenuID2);
    glutAddSubMenu("색", MySubMenuID3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    return 0;
}