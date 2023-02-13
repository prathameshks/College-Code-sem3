#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>

using namespace std;

void function() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glBegin(GL_QUAD_STRIP);

    glColor3f(1, 0, 0);
    glVertex2f(1, 1);

    glColor3f(0, 1, 0);
    glVertex2f(1, 10);

    glColor3f(0, 0, 1);
    glVertex2f(10, 1);

    glColor3f(1, 0, 0);
    glVertex2f(10, 10);

    glColor3f(0, 1, 0);
    glVertex2f(20, 1);

    glColor3f(0, 0, 1);
    glVertex2f(20, 10);

    glEnd();
    glFlush();
}

void init() { glClearColor(1, 1, 1, 1); }

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 30, 30, -10);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char c, int x, int y) {
    cout << "c =" << c << endl;
    cout << "x =" << x << endl;
    cout << "y =" << y << endl;
}

void mouse(int a, int b, int x, int y) {
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    cout << "x =" << x << endl;
    cout << "y =" << y << endl;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Sample GL PREMITIVES");
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(400, 300);
    glutDisplayFunc(function);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}