#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

static int Day = 0, Time = 0, Day2=0, Time2;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0, 0.3, 0.3);
    glutWireSphere(0.1, 20, 16);

    glPushMatrix();
    glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.5, 0.6, 0.7);
    glutWireSphere(0.04, 10, 8);

    glPushMatrix();
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.1, 0.0, 0.0);
    glColor3f(0.9, 0.8, 0.2);
    glutWireSphere(0.02, 10, 8);
    ///////////////////////////////////////////////
    glLoadIdentity();
    glPushMatrix();
    //glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.7);
    glutWireSphere(0.06, 10, 8);

    glPushMatrix();
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glTranslatef(0.09, 0.0, 0.0);
    glColor3f(0.9, 0.1, 0.2);
    glutWireSphere(0.01, 10, 8);
    /// <summary>
    /// ////////////////////////////////////////////
    /// </summary>
    glLoadIdentity();
    glPushMatrix();
    glRotatef((GLfloat)Day2, 0.0, 1.0, 0.0);
    glTranslatef(0.9, 0.0, 0.0);
    glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.7, 0.0);
    glutWireSphere(0.07, 20, 18);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void MyTimer(int Value) {
    Day = (Day + 3) % 360;
    Day2 = (Day2 + 1) % 360;
    Time = (Time + 1) % 360;
    //Time2 = (Time + 0.5) % 360;
    glutPostRedisplay();
    glutTimerFunc(10, MyTimer, 1);
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'd':
        Day = (Day + 10) % 360;
        glutPostRedisplay();
        break;
    case 't':
        Time = (Time + 5) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2019305059 ÀÌÇö¼ö");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutTimerFunc(10, MyTimer, 0);
    glutMainLoop();
    return 0;
}
