#include <GL/glut.h>
void changePerspective();

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();  // resets modelview matrix

    glTranslatef(0.0, 0.0, -10.0);
    // glScalef(2.0,2.0,0.0);
    // glRotatef(-180.0,1.0,0.0,0.0);
    glRotatef(-60.0, 1.0, 1.0, 0.0);
    changePerspective();

    glBegin(GL_QUADS);
    // front (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);

    // back (green)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // right (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // left (yellow)
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // top (cyan)
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // bottom (magenta)
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glEnd();

    glutSwapBuffers();
    // glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // resets projection matrix
    gluPerspective(60, 1, 2.0, 50.0);
    // glOrtho(-10,10,-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

int angle = 0;
bool dir = true;

void changePerspective() {
    if (angle < 120) {
        glRotatef(-angle, 1.0, 1.0, 0.0);
    } else if (angle > 120 and angle < 240) {
        glRotatef(-angle, 1.0, 0.0, 1.0);

    } else {
        glRotatef(-angle, 0.0, 1.0, 1.0);
    }

    switch (dir) {
        case true:
            if (angle < 360) {
                angle++;
            } else {
                dir = false;
            }
            break;

        case false:
            if (angle > 0) {
                angle--;
            } else {
                dir = true;
            }
            break;
    }
}

void timer(int a) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D transformations");
    glutDisplayFunc(mydisplay);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000 / 60, timer, 0);
    init();
    glutMainLoop();
}
