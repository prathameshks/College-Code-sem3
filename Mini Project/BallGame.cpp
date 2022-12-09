// Creating ball in the basket game
#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
}

void ball() {
    glColor3f(1, 0, 0);
    glutSolidSphere(0.2, 25, 25);
}
void basket() {
    glColor3f(0, 1, 0);
    glutSolidCone(0.3, 0.5, 25, 25);
}
void poll() {
    glColor3f(0, 0, 1);
    glutSolidCube(1);
}
float ballX = 0, ballY = 1.8, basketX = 0, basketY = -1.5, pollX = 0.9,
      pollY = 1.8;
// int rand();
int r, flagout = 0, count = 0;
float ballSpeed = 0;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // cout<<"ballX= "<<ballX<<endl;
    // cout<<"ballY= "<<ballY<<endl;
    // cout<<"basketX= "<<basketX<<endl;
    // cout<<"basketY= "<<basketY<<endl;

    if (count == 3) {
        ballSpeed += 0.008;
        count = 0;
    }

    if (ballY < -1.5 && (ballX > basketX - 0.3 && ballX < basketX + 0.3)) {
        count++;
        ballY = 1.8;
        r = rand() % 4;
        if (r == 0) {
            ballX = -1.8;
            pollX = -1.8 + 0.9;
        }
        if (r == 1) {
            ballX = -1;
            pollX = -1 + 0.9;
        }
        if (r == 2) {
            ballX = 1;
            pollX = 1 + 0.9;
        }
        if (r == 3) {
            ballX = 1.8;
            pollX = 1.8 + 0.9;
        }
    }

    if (flagout == 0) ballY -= 0.02 + ballSpeed;

    if (ballY < -2) {
        flagout = 1;
        cout << "Score is " << count << endl;

        }

    glPushMatrix();
    glTranslatef(ballX, ballY, 0);
    ball();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(basketX, basketY, 0);
    glRotatef(90, 1, 0, 0);
    basket();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(pollX, pollY, 0);
    glScalef(1.5, 0.4, 1);
    poll();
    glPopMatrix();

    glutSwapBuffers();
    glutPostRedisplay();
}

void skeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) basketX -= 0.3;
    if (key == GLUT_KEY_RIGHT) basketX += 0.3;
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Catch the balls");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(skeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
