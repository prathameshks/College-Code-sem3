/*
Write C++ program to draw 3-D cube and perform following transformations on
it using OpenGL i) Scaling ii) Translation iii) Rotation about an axis (X/Y/Z).
*/

#include <iostream>
#include<GL/glut.h>


using namespace std;


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0,0,-10);
    glScalef(1.5,2,2);
    glRotatef(-60, 1.0, 1.0, 0.0);
    cout<<"1";


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
    // glSwapBuffers();
    glutSwapBuffers();
}

void init(){
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2,50);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("CG PRACTICAL");
    glutInitWindowSize(600,600);
    glutPositionWindow(100,100);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();
    return 0;
}