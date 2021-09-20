#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void MyDisplay1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0, 1.0, 0.0);
    glLoadIdentity();
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.0, 0.0);
    glutSolidCube(0.3);
    glFlush();

    glColor3f(0.0, 1.0, 0.0);
    glLoadIdentity();
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glutSolidCube(0.3);
    glFlush();
}

void MyDisplay2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glutSolidCube(0.3);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2019305059 ÀÌÇö¼ö");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay1);
    //glutDisplayFunc(MyDisplay2);
    glutMainLoop();
    return 0;
}
