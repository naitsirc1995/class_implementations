#include "pointExclussion.h"


PointExclusionStruct* fastConvexHull(Point* arbitraryPoints,int numberOfPoints)
{
    Point p1 = arbitraryPoints[0];

    Point xMax , xMin, yMax, yMin; 
    xMax = p1;
    xMin = p1;
    yMax = p1;
    yMin = p1;

    for (int i = 1; i < numberOfPoints; i++ ){
        Point currentPoint = arbitraryPoints[i];        

        if (currentPoint.x_coordinate > xMax.x_coordinate){
            xMax = currentPoint;
        }

        if (currentPoint.x_coordinate == xMin.x_coordinate && currentPoint.y_coordinate < xMin.y_coordinate){
            xMin = currentPoint;
        }

        if (currentPoint.x_coordinate < xMin.x_coordinate ){
            xMin = currentPoint;
        }

        if (currentPoint.x_coordinate == xMax.x_coordinate && currentPoint.y_coordinate > xMax.y_coordinate){
            xMin = currentPoint;
        }

        if (currentPoint.y_coordinate > yMax.y_coordinate ){            
            yMax = currentPoint;            
        }

        if (currentPoint.y_coordinate == yMax.y_coordinate && currentPoint.x_coordinate > yMax.x_coordinate){            
            yMax = currentPoint;
        }

        if (currentPoint.y_coordinate < yMin.y_coordinate){            
            yMin = currentPoint;            
        }

        if (currentPoint.y_coordinate == yMin.y_coordinate && currentPoint.x_coordinate < yMin.x_coordinate){            
            yMin = currentPoint;            
        }
    }

    ExcludePolygonVertices* excludePolygonVertices = new ExcludePolygonVertices{xMax,yMax,xMin,yMin};
    
    int numBoundaryVertices;

    // 3 sub-problems bools     

    Polygon* polygon;

    if (xMin == yMax && xMax != yMin){        
        numBoundaryVertices = 3;
        Point points[numBoundaryVertices] = {xMax,xMin,yMin};
        polygon = new Polygon(points,numBoundaryVertices);
    } else if (xMax == yMax && xMin != yMin){        
        numBoundaryVertices = 3;
        Point points[numBoundaryVertices] = {xMax,xMin,yMin};
        polygon = new Polygon(points,numBoundaryVertices);
    } else if (xMax == yMin && xMin != yMax){
        numBoundaryVertices = 3;
        Point points[numBoundaryVertices] = {yMax,xMin,xMax};
        polygon = new Polygon(points,numBoundaryVertices);
    } else if ( xMin == yMax && xMax == yMin ){
        return new PointExclusionStruct{
        excludePolygonVertices,
        arbitraryPoints,
        numberOfPoints,
        nullptr,
        0
    };
    } else if (xMax == yMax && xMin == yMin){
        return new PointExclusionStruct{
        excludePolygonVertices,
        arbitraryPoints,
        numberOfPoints,
        nullptr,
        0
    };
    } else {
        numBoundaryVertices = 4;
        Point points[numBoundaryVertices] = {xMax,yMax,xMin,yMin};
        polygon = new Polygon(points,numBoundaryVertices);
    }
    
    

    int numberOfIncludedPoints,numberOfExcludedPoints;
    Point* includedPoints = new Point[numberOfPoints];
    Point* excludedPoints = new Point[numberOfPoints];    

    for (int i = 0; i < numberOfPoints;i++){
        Point currentPoint = arbitraryPoints[i];        
        if (currentPoint == xMax || currentPoint == yMax || currentPoint == xMin || currentPoint == yMin){
            continue;
        }        
        else if (polygon->isInside(currentPoint)){            
            excludedPoints[numberOfExcludedPoints] = currentPoint;
            numberOfExcludedPoints++;
        } else {            
            includedPoints[numberOfIncludedPoints] = currentPoint;
            numberOfIncludedPoints++;
        }
    }

    
    return new PointExclusionStruct{
        excludePolygonVertices,
        includedPoints,
        numberOfIncludedPoints,
        excludedPoints,
        numberOfExcludedPoints
    };
}

