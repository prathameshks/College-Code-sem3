#include<GL/glut.h>
// #include<GL/gl.h>
// #include<GL/glu.h>

void init(){
    glClearColor(0,0,0,1);
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //draw here
    glBegin(GL_QUADS);
    glVertex2f(3,3);
    glVertex2f(3,-3);
    glVertex2f(-3,-3);
    glVertex2f(-3,3);

    glEnd();


    glFlush();
}

void reshape(int w, int h){
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION); //default - GL_MODELVIEW

    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);

}


int main(int argc,char**argv){
    // glutInit();
    // gluBeginCurve();

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(700,600); //pixel screen coords
    glutInitWindowSize(600,400);


    glutCreateWindow("Title of Window");

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    init();
    


    glutMainLoop();
}

