#include <GL/glut.h>

void init() { glClearColor(0.99, 0.65, 0.32, 1); }

void display() {
    glClear(GL_CLEAR_BUFFER);

    glBegin(GL_QUADS);
    glColor3f(0.99, 0.65, 0.32);
    glVertex2f(0,0);
    glVertex2f(0,20);
    glVertex2f(20,20);
    glVertex2f(20,0);

    glEnd();



    glFlush();



}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sunrise - Sunset");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glOrtho(0,20,0,20,-5,5);
    init();
    glutMainLoop();
    return 0;
}