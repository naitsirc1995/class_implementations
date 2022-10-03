#ifndef FUNCTION_GENERATORS_H
#define FUNCTION_GENERATORS_H
// Internal Code ----------------------
#include "../Point.h"
#include "../Polygon.h"
#include "circle/circle.h"
//-------------------------------------


// External libraries
#include <iostream>
#include "math.h"
//-------------------------------------



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

PolygonInterior* interiorGenerator(
    Point* polygonPoints, 
    int numberOfPolygonPoints, 
    int numberOfRandomPoints
);
//----------------------------------------------------------------------------------------------------


// Generating Struct
struct PolygonGenerated {
    Point* points;
    int numberOfPoints;
};
//-------------------------

PolygonGenerated* CircleGenerator(
    int numberOfBoundaryPoints,
    int numberOfInteriorPoints,
    bool includeBoundary,
    float initialPoint, 
    float endPoint, 
    float numberOfFunctions
);

PolygonGenerated* CircleGenerator(
    int numberOfBoundaryPoints,
    int numberOfInteriorPoints    
);


PolygonGenerated* CircleBoundaryGenerator(
    int numberOfBoundaryPoints,        
    float initialPoint, 
    float endPoint, 
    float numberOfFunctions
);


PolygonGenerated* CircleBoundaryGenerator(
    int numberOfBoundaryPoints
);


const bool includeCircleBoundary = false;
const float initialCirclePoint = 0;
const float endCirclePoint = 2*M_PI;
const float numberOfCircleFunctions = 1;
#endif