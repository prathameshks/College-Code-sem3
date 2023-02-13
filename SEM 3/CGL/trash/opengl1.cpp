#include <GL/glut.h>

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glTranslatef(100,100,0);
    glScalef(2,2,0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0, 50);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-50, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(50, 0);
    glColor3f(1.0,1.0,0.0);glVertex2f(0,150);

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("my first window");
    glutDisplayFunc(mydisplay);
    init();
    glutMainLoop();
}