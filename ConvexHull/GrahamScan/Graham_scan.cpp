//
// Created by Елена on 2019-07-10.
//

#include "Graham_scan.h"

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

GrahamHull::GrahamHull(const std::vector<Point> &points) : points(points) {}

std::vector<Point> *GrahamHull::find_convex_hull() {

    size_t min_p_index = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        if (points[i].y < points[min_p_index].y) {
            min_p_index = i;
        } else if (points[i].y == points[min_p_index].y & points[i].x > points[min_p_index].x) {
            min_p_index = i;
        }
    }
    points[0].swap(points[min_p_index]);

    Point p0 = points[0];
    std::sort(points.begin() + 1, points.end(), [this, p0](const Point &p1, const Point &p2) {
        double temp = vector_mul(p1, p2, p0, p0);
        if (temp == 0) {
            return distance_in_pow2(p1, p0) < distance_in_pow2(p2, p0);
        } else {
            return temp > 0;
        }
    });

    hull.push_back(p0);
    assert(points.size() > 2);
    hull.push_back(points[1]);

    for (size_t i = 2; i < points.size(); ++i) {
        while (vector_mul(hull[hull.size() - 1], points[i], hull[hull.size() - 2], hull[hull.size() - 1]) < 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return &hull;
}

float GrahamHull::distance_in_pow2(const Point &p1, const Point &p0) {
    return (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y);
}

float GrahamHull::vector_mul(const Point &a, const Point &b, const Point &p, const Point &p2) {
    return (a.x - p.x) * (b.y - p2.y) - (a.y - p.y) * (b.x - p2.x);
}
