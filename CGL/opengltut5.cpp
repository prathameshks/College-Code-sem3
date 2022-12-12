#include <GL/glut.h>

#include <iostream>
// #include<GL/gl.h>
// #include<GL/glu.h>
using namespace std;
void init() {
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}

float angle = 0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -5);
    glRotatef(angle, 1, 0, 1);
    // glRotatef(angle, 1, 1, 1);
    // glRotatef(angle, 1, 1, 0);
    // glRotatef(angle, 0, 1, 1);

    // draw here
    glBegin(GL_QUADS);

    // front
    glColor3f(1, 0, 0);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);

    // back
    glColor3f(1, 1, 0);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);

    // left
    glColor3f(1, 0, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);

    // right
    glColor3f(0, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);

    // top
    glColor3f(0, 1.0, 0);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);

    // bottom
    glColor3f(0, 0, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);

    glEnd();
    // glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);  // default - GL_MODELVIEW

    glLoadIdentity();

    gluPerspective(45, 1, 1, 10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int a) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    angle += 0.5;
    if(angle>350) angle = 0;
}

int main(int argc, char** argv) {
    // glutInit();
    // gluBeginCurve();
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(100, 100);  // pixel screen coords
    glutInitWindowSize(500, 500);

    glutCreateWindow("Title of Window");

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();
}
