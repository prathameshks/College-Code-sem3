#include <GL/glut.h>
// #include<GL/gl.h>
// #include<GL/glu.h>

void init() { glClearColor(0, 0, 0, 1); }

float x_positon = -10;
float y_positon = 10;
bool state = true;
bool ystate = true;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(0,10);
    glVertex2f(0,-10);
    glVertex2f(10,0);
    glVertex2f(-10,0);
    glEnd();


    glTranslatef(5,5,1);

    // draw here
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(2 + 1, 2);
    glColor3f(0, 1, 0);
    glVertex2f(2, 2 + 2);
    glColor3f(0, 0, 1);
    glVertex2f(2 + 2, 2 + 2);

    glEnd();

    // glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);  // default - GL_MODELVIEW

    glLoadIdentity();

    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int a) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    /*
        switch (state) {
            case true:
                if (x_positon < 8) {
                    x_positon += 0.25;
                } else {
                    state = false;
                }
                break;

            case false:
                if (x_positon > -10) {
                    x_positon -= 0.2;
                } else {
                    state = true;
                }
                break;
        }

        switch (ystate) {
            case true:
                if (y_positon < 8) {
                    y_positon += 0.15;
                } else {
                    ystate = false;
                }
                break;

            case false:
                if (y_positon > -10) {
                    y_positon -= 0.23;
                } else {
                    ystate = true;
                }
                break;
        }*/
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
