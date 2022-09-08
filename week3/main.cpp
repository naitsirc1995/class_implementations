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
    pointList[0] = {1,2};
    pointList[1] = {50,3};
    pointList[2] = {100,4};
    
    //Polygon *convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);
    //std::cout << "(" << (convexHullPolygon->getVertices()->point).x_coordinate << "," << (convexHullPolygon->getVertices()->point).y_coordinate << ")" << std::endl;
    Polygon myPol = Polygon(pointList,polygonTotalPoints);
    PolygonVertex *firstVertex = myPol.getVertices()->previous->previous -> previous -> previous;

    std::cout << "(" << (firstVertex -> point).x_coordinate << "," << (firstVertex -> point).y_coordinate << ")" << std::endl;    
    
    do_nice_graph();
    return 0;
}