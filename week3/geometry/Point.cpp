#include "Point.h"

float dist(Point p1, Point p2)
{
    return sqrt( pow((p2.x_coordinate-p1.x_coordinate),2) + pow((p2.y_coordinate-p2.x_coordinate),2));
}