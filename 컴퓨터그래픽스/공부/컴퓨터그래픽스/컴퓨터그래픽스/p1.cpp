#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat rotatex = 0.0;
GLfloat rotatey = 0.0;

GLfloat MyVertices[6][3] = {
    { -0.25, 0.0, 0.0 },
    { 0.0, 0.0, -0.25 },
    { 0.25, 0.0, 0.0 },
    { 0.0, 0.0, 0.25 },
    { 0.0, -0.25, 0.0 },
    { 0.0, 0.25, 0.0 }
};
GLfloat MyColors[8][3] = {
    { 0.7, 0.2, 0.2 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    { 1.0, 1.0, 0.0 },
    { 0.0, 1.0, 1.0 },
    { 1.0, 0.0, 1.0 },
    { 0.5, 0.5, 0.7 },
    { 1.0, 0.0, 0.0 }
};
GLubyte MyVertexList[24] = {
    0,3,5,
    3,2,5,
    2,1,5,
    1,0,5,
    0,4,3,
    3,4,2,
    2,4,1,
    1,4,0
};

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    //glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    //glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(rotatex, 1.0, 0.0, 1.0);
    glRotatef(rotatey, 0.0, 1.0, 0.0);

    for (GLint i = 0; i < 8; i++) {
        glColor3f(MyColors[i][0], MyColors[i][1], MyColors[i][2]);
        glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, &MyVertexList[3 * i]);
    }

    glFlush();
}

void DoSpecial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_UP:
        rotatex += 10.0;
        break;
    case GLUT_KEY_DOWN:
        rotatex -= 10.0;
        break;
    case GLUT_KEY_RIGHT:
        rotatey += 10.0;
        break;
    case GLUT_KEY_LEFT:
        rotatey -= 10.0;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2019305059 ÀÌÇö¼ö");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(DoSpecial);
    glutMainLoop();
    return 0;
}
