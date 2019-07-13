#ifdef __APPLE__

#include <GLUT/glut.h>
#include <iostream>

#else
#include <GL/glut.h>
#endif


#include <cmath>
#include "Graphics.h"
#include "GrahamScan/Graham_scan.h"

std::vector<Point> generate(int count) {
    std::vector<Point> ans;
    for (int i = 0; i < count; i++) {
        Point temp;
        temp.x = ((float) rand() * WINDOW_WIDTH) / RAND_MAX;
        temp.y = ((float) rand() * WINDOW_HEIGHT) / RAND_MAX;
        ans.push_back(temp);
    }
    return ans;
}

std::vector<Point> generateCircle(int count) {
    std::vector<Point> ans;

    float radius = 200;
    for (int i = 0; i < count; i++) {
        Point temp;
        float x, y;
        x = (float) rand() * 2 * radius / RAND_MAX - radius;
        auto dy = (float) pow(radius * radius - x * x, 0.5);
        y = (float) rand() * 2 * dy / RAND_MAX - dy;
        temp.x = x + (float) WINDOW_WIDTH / 2;
        temp.y = y + (float) WINDOW_HEIGHT / 2;
        ans.push_back(temp);
    }
    return ans;
}

void drawScene() {
    //std::vector<Point> gen_points = generate(23);
    std::vector<Point> gen_points = generateCircle(100);
    GrahamHull g(gen_points);
    std::vector<Point> *hull = g.find_convex_hull();

    clearWindow();

    setColor(MAGENTA);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(5);
    glBegin(GL_POINTS);

    for (auto &gen_point : gen_points) {
        glVertex2f(gen_point.x, gen_point.y);
    }
    glEnd();

    setColor(GREEN);
    glBegin(GL_LINE_LOOP);
    for (auto p : *hull) {
        glVertex2f(p.x, p.y);
    }
    glEnd();

    glutSwapBuffers();
    glFinish();
}

int main(int argc, char **argv) {
    graphicsSetup(argc, argv);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 1;
}