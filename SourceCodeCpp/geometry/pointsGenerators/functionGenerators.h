#ifndef FUNCTION_GENERATORS_H
#define FUNCTION_GENERATORS_H
#include "../Point.h"
#include "../Polygon.h"
#include <iostream>

// Function for boundary generation
Point* boundaryGenerator(
    float initialPoint, 
    float endPoint,
    int numberOfSteps,
    float numberOfFunctions, 
    float (**fx)(float t ),
    float (**fy)(float t )    
);
//----------------------------------


// Elements for polygon interior generation
struct PolygonInterior{
    Point* interiorPoints;
    int numberOfInteriorPoints;
};

PolygonInterior* interiorGenerator(Point* polygonPoints, int numberOfPolygonPoints, int numberOfRandomPoints);
//----------------------------------------------------------------------------------------------------

#endif