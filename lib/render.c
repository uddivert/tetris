// C program to demonstrate
// drawing a circle using
// OpenGL
#include<stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include "font.h"


void display(void)
{
    makeRasterFont();
    GLfloat white[3] = { 1.0, 1.0, 1.0 };

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(white);

    glRasterPos2i(20, 60);

    printString("I GUESS I KINDA MISS U");
    glRasterPos2i(20, 40);
    printString("FROM UR SECRET ADMIRER");
    glFlush ();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0.0, w, 0.0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
    }
}

int initialize(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 100);
    glutInitWindowPosition (100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
/*
void display (void) 
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderBitmapString(0,0,0, GLUT_BITMAP_9_BY_15, "hello world");;
    glEnd();
    glutSwapBuffers();
}
  
int initialize(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
      
    // giving window size in X- and Y- direction
    glutInitWindowSize((glutGet(GLUT_SCREEN_WIDTH))/2, glutGet(GLUT_SCREEN_HEIGHT)/2);
    glutInitWindowPosition(600,200);

    // Giving name to window
    glutCreateWindow("Circle Drawing");
      
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
*/
