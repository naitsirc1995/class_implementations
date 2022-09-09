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
    pointList[0] = {100,4};
    pointList[1] = {50,3};
    pointList[2] = {1,2};
    
    Polygon *convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);
    PolygonVertex* firstConvexHullPolygonVertex = convexHullPolygon->getVertices();
    std::cout << "am I even doing something here?" << std::endl;
    std::cout << "(" << (firstConvexHullPolygonVertex->point).x_coordinate << "," << (firstConvexHullPolygonVertex->point).y_coordinate << ")" << std::endl;
    //std::cout << "(" << (convexHullPolygon->getVertices()->point).x_coordinate << "," << (convexHullPolygon->getVertices()->point).y_coordinate << ")" << std::endl;
    //Polygon myPol = Polygon(pointList,polygonTotalPoints);  
    
    do_nice_graph();
    return 0;
}