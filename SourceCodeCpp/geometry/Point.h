#ifndef POINT_H
#define POINT_H
#include <math.h>

struct Point {
    float x_coordinate;
    float y_coordinate;
    
inline bool operator==(const Point& point)
{
    return (x_coordinate == point.x_coordinate && y_coordinate == point.y_coordinate);
}


inline bool operator!=(const Point& point)
{
    return (x_coordinate != point.x_coordinate || y_coordinate != point.y_coordinate);
}

};

float dist(Point p1, Point p2);


#endif