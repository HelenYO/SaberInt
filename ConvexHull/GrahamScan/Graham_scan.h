//
// Created by Елена on 2019-07-10.
//

#ifndef CONVEXHULL_GRAHAM_SCAN_H
#define CONVEXHULL_GRAHAM_SCAN_H

#include <vector>

struct Point {
    float x, y;

    Point();

    Point(float x, float y);

    void swap(Point &p);
};

class GrahamHull {
    std::vector<Point> points;
    std::vector<Point> hull;

public:
    explicit GrahamHull(const std::vector<Point> &points);

    std::vector<Point> *find_convex_hull();

private:

    float distance_in_pow2(const Point &p1, const Point &p0);

    float vector_mul(const Point &a, const Point &b, const Point &p, const Point &p2);
};

#endif //CONVEXHULL_GRAHAM_SCAN_H