#include <GL/glut.h>
// #include<GL/gl.h>
// #include<GL/glu.h>

void init() { glClearColor(0, 0, 0, 1); }

float x_positon = -10;
bool state = true;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, x_positon);

    // draw here
    glBegin(GL_POLYGON);
    glVertex2f(0, 2);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);

    glEnd();
    // glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);  // default - GL_MODELVIEW

    glLoadIdentity();

    gluPerspective(60, 1, 2, 20);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int a) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    switch (state) {
        case true:
            if (x_positon < -2) {
                x_positon += 0.1;
            } else {
                state = false;
            }
            break;

        case false:
            if (x_positon > -10) {
                x_positon -= 0.1;
            } else {
                state = true;
            }
            break;
    }
}

int main(int argc, char** argv) {
    // glutInit();
    // gluBeginCurve();

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(700, 600);  // pixel screen coords
    glutInitWindowSize(600, 400);

    glutCreateWindow("Title of Window");

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();
}
