// Custom code 
#include "grapher/graph.h"
#include "geometry/Polygon.h"
#include "geometry/Point.h"
#include "convexHull/gift_wrapping.h"

// external libraries 
#include <iostream>


int main()
{
    int polygonTotalPoints = 3;   
    Point *pointList = new Point[polygonTotalPoints];
    pointList[0] = {1,0};
    pointList[1] = {0,1};
    pointList[2] = {0,0};
    
    Polygon *convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);
    PolygonVertex* firstConvexHullPolygonVertex = convexHullPolygon->getVertices();
    
    graphPolygon(convexHullPolygon);
    return 0;
}