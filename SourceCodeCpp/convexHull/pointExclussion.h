#ifndef POINT_EXCLUSSION_H
#define POINT_EXCLUSSION_H

#include<iostream>

// Geometry Classes by me
#include "../geometry/Point.h"
#include "../geometry/Polygon.h"

struct ExcludePolygonVertices {
    Point xMax;
    Point yMax;
    Point xMin;
    Point yMin;
};

struct PointExclusionStruct {
    ExcludePolygonVertices* excludePolygonVertices;
    Point* includedPoints;
    int numberOfIncludedPoints;
    Point* excludedPoints;
    int numberOfExcludedPoints;    
};

PointExclusionStruct* fastConvexHull(Point* arbitraryPoints,int numberOfPoints);

#endif