#ifndef CS25_A26_H
#define CS25_A26_H

#include <iostream>
using std::ostream;
using namespace std;

struct Point {
    float x;
    float y;
};

bool operator == (Point& point1, Point& point2) {
    return((point1.x == point2.x) && (point1.y == point2.y));
}

ostream& operator<< (ostream& stream, Point& point1){
    stream << "(" << point1.x << ", " << point1.y << ")";
    return stream;
}

#endif