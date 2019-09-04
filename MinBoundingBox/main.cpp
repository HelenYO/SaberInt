#ifdef __APPLE__

#include <GLUT/glut.h>
#include <iostream>

#else
#include <GL/glut.h>
#endif

#include <cmath>
#include "MBB/MBBox.h"

//#include <GL/glut.h>

const int w = 700;
const int h = 700;
const float d_alfa = 2;
float alfa = 0.0;

void face() {
    glBegin(GL_QUADS);
    glVertex3f(-2, 0.0, -2);
    glVertex3f(-2, 0.0, 2);
    glVertex3f(2, 0.0, 2);
    glVertex3f(2, 0.0, -2);
    glEnd();
}

void figure() {
    /////низ
    glPushMatrix();
    glTranslatef(0.0, -2, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    face();
    glPopMatrix();

    /////верх
    glPushMatrix();
    glTranslatef(0.0, 2, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    face();
    glPopMatrix();

    /////левая
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-2, 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    face();
    glPopMatrix();

    /////правая
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(2, 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    face();
    glPopMatrix();

    /////задняя
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, -2);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    face();
    glPopMatrix();

    /////передняя
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, 2);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    face();
    glPopMatrix();
}

void rotation() {
    alfa += d_alfa;
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);/////Это очень важная штука, само определяет, какая грань впереди
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, 1.0, 1.0, 20.0);
    gluLookAt(7.0, 7.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glRotatef(alfa, 0.3, 1.0, 1.2);
    //glTranslatef(5.0, 0.0, 0.0); /////Перемещать в пространстве
    figure();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(w, h);
    glutCreateWindow("WoW CuBe");
    glutDisplayFunc(drawScene);
    glutIdleFunc(rotation);
    init();
    glutMainLoop();
    return 0;
}