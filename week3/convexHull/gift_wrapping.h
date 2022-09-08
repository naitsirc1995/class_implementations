#ifndef GIFT_WRAPPING_H
#define GIFT_WRAPPING_H
#include "../geometry/Point.h"
#include "../geometry/Polygon.h"

Polygon* gift_wrapping(Point* arbitraryPoints,int numberOfPoints);
int orientation(Point* p1, Point* p2, Point* p3);

#endif