#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

#include "../geometry/Point.h"
#include "../geometry/Polygon.h"



int ccw(Point a, Point b, Point c);

float sqrDist(Point a, Point b);

bool POLAR_ORDER(Point a, Point b);

Polygon* grahamScan(Point* points, int N);
