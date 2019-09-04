//
// Created by Елена on 2019-09-02.
//

#include "MBBox.h"

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point() : x(0), y(0) {}

void Point::swap(Point &p) {
    float tx = p.x;
    float ty = p.y;
    p.x = x;
    p.y = y;
    x = tx;
    y = ty;
}