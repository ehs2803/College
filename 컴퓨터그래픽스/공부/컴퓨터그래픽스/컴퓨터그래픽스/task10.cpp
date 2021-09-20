#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
//#include <time.h>


GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

GLboolean pink = true;
GLboolean yellow = false;
GLboolean orange = false;

GLboolean IsSmall = true;

GLboolean IsFast = false;

GLboolean IsplusX = true;
GLboolean IsplusY = true;

GLfloat DeltaX = 0.0;
GLfloat DeltaY = 0.0;

GLboolean IsClick = false;

void MyDisplay() {
    glViewport(0, 0, 1000, 1000);
    glClear(GL_COLOR_BUFFER_BIT);

    if (pink == true) glColor3f(1.0, 0.0, 0.9);
    else if (yellow == true) glColor3f(1.0, 1.0, 0.0);
    else glColor3f(1.0, 0.7, 0.0);

    if (IsSmall) {
        if (BottomRightX / 1000.0 + DeltaX >= 1000.0 / 1000.0) {
            IsplusX = false;
        }
        else if (TopLeftX / 1000.0 + DeltaX <= 0.0) {
            IsplusX = true;
        }
    }
    else {
        if (BottomRightX / 1000.0 + 10.0 / 1000.0 + DeltaX >= 1000.0 / 1000.0) {
            IsplusX = false;
        }
        else if (TopLeftX / 1000.0 - 10.0 / 1000.0 + DeltaX <=0.0) {
            IsplusX = true;
        }
    }

    if (IsSmall) {
        if ((1000 - TopLeftY) / 1000.0 + DeltaY >= 1000.0 / 1000.0) {
            IsplusY = false;
        }
        else if ((1000 - BottomRightY) / 1000.0 + DeltaY <= 0.0) {
            IsplusY = true;
        }
    }
    else {
        if ((1000 - TopLeftY) / 1000.0 + 10.0 / 1000.0 + DeltaY >= 1000.0 / 1000.0) {
            IsplusY = false;
        }
        else if ((1000 - BottomRightY) / 1000.0 - 10.0 / 1000.0 + DeltaY <= 0.0) {
            IsplusY = true;
        }
    }

    if (IsSmall == true) {
        glBegin(GL_POLYGON);
        glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000 - TopLeftY) / 1000.0+ DeltaY, 0.0);
        glVertex3f(TopLeftX / 1000.0 + DeltaX, (1000 - BottomRightY) / 1000.0+ DeltaY, 0.0);
        glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000 - BottomRightY) / 1000.0+ DeltaY, 0.0);
        glVertex3f(BottomRightX / 1000.0 + DeltaX, (1000 - TopLeftY) / 1000.0+ DeltaY, 0.0);
        glEnd();
    }
    else {
        glBegin(GL_POLYGON);
        glVertex3f(TopLeftX / 1000.0 - 10.0 / 1000.0 + DeltaX, (1000 - TopLeftY) / 1000.0 + 10.0 / 1000.0+DeltaY, 0.0);
        glVertex3f(TopLeftX / 1000.0 - 10.0 / 1000.0 + DeltaX, (1000 - BottomRightY) / 1000.0 - 10.0 / 1000.0 + DeltaY, 0.0);
        glVertex3f(BottomRightX / 1000.0 + 10.0 / 1000.0 + DeltaX, (1000 - BottomRightY) / 1000.0 - 10.0 / 1000.0 + DeltaY, 0.0);
        glVertex3f(BottomRightX / 1000.0 + 10.0 / 1000.0 + DeltaX, (1000 - TopLeftY) / 1000.0 + 10.0 / 1000.0 + DeltaY, 0.0);
        glEnd();
    }
    glFlush();
}

void MyTimer(int Value) {
    if (IsClick) {
        DeltaX = DeltaX + 0;
        DeltaY = DeltaY + 0;
    }
    else {
        if (IsplusX) {
            if (IsFast) DeltaX = DeltaX + 0.01;
            else DeltaX = DeltaX + 0.001;
        }
        else {
            if (IsFast) DeltaX = DeltaX - 0.01;
            else DeltaX = DeltaX - 0.001;
        }
        if (IsplusY) {
            if (IsFast) DeltaY = DeltaY + 0.01;
            else DeltaY = DeltaY + 0.001;
        }
        else {
            if (IsFast) DeltaY = DeltaY - 0.01;
            else DeltaY = DeltaY - 0.001;
        }
        glutPostRedisplay();
        glutTimerFunc(10, MyTimer, 1);
    }
    //glutPostRedisplay();
    //glutTimerFunc(10, MyTimer, 1);
}

void DoSpecial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT:
        IsFast = false;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        IsFast = true;
        glutPostRedisplay();
        break;
    }
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
    case 'Q':
        exit(0); break;
    case 'q':
        exit(0); break;
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

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
        IsClick = false;
    }
    else if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        IsClick = true;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = Y;
    DeltaX = 0;
    DeltaY = 0;
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
        IsFast = false;
    else if (entryID == 2)
        IsFast = true;
    glutPostRedisplay();
}

void MySubMenu_color(int entryID) {
    if (entryID == 1){
        pink = true;
        yellow = false;
        orange = false;
    }                
    else if (entryID == 2) {
        pink = false;
        yellow = true;
        orange = false;
    } 
    else if(entryID==3){
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

    glClearColor(0.7, 0.7, 0.7, 1.0);
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
    glutSpecialFunc(DoSpecial);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutTimerFunc(10, MyTimer, 0);
    glutMainLoop();
    return 0;
}

/*
void MyMainMenu(int entryID) {
    if (entryID == 1)
        IsSphere = true;                //원구 그리기
    else if (entryID == 2)
        IsSphere = false;               //원환체 그리기
    else if (entryID == 3)
        exit(0);                        //프로그램 종료
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
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    GLint MySubMenuID1 = glutCreateMenu(MySubMenu_size);
    glutAddMenuEntry("작게", 1);
    glutAddMenuEntry("크게", 2);

    GLint MySubMenuID2 = glutCreateMenu(MySubMenu_fast);
    glutAddMenuEntry("느리게", 1);
    glutAddMenuEntry("빠르게", 2);

    GLint MySubMenuID3 = glutCreateMenu(MySubMenu_color);
    glutAddMenuEntry("핑크",1);
    glutAddMenuEntry("노랑", 2);
    glutAddMenuEntry("주황", 3);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("크기", MySubMenuID1);
    glutAddMenuEntry("속도", MySubMenuID2);
    glutAddSubMenu("색", MySubMenuID3);

    

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    return 0;
}
*/
/*
GLint MySubMenuID = glutCreateMenu(MySubMenu);
glutAddMenuEntry("Small One", 1);
glutAddMenuEntry("Big One", 2);
GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
glutAddMenuEntry("Draw Sphere", 1);
glutAddMenuEntry("Draw Torus", 2);
glutAddSubMenu("Change Size", MySubMenuID);
glutAddMenuEntry("Exit", 3);

glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

*/