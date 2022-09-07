// Custom code 
#include "grapher/graph.h"
#include "geometry/Polygon.h"
#include "geometry/Point.h"

// external libraries 
#include <iostream>


int main()
{
    int polygonTotalPoints = 3;        
    Point pointList[polygonTotalPoints];
    pointList[0] = {1,2};
    pointList[1] = {2,3};
    pointList[2] = {1,4};

    
    Polygon(pointList,polygonTotalPoints);

    
    
    do_nice_graph();
    return 0; 
}