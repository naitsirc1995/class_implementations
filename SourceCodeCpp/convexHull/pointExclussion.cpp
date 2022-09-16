#include "pointExclussion.h"


pointExclussionStruct* fastConvexHull(Point* arbitraryPoints,int numberOfPoints)
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

    std::cout << "xMax (" << xMax.x_coordinate << "," << xMax.y_coordinate << ")" << std::endl;
    std::cout << "yMax (" << yMax.x_coordinate << "," << yMax.y_coordinate << ")" << std::endl;
    std::cout << "xMin (" << xMin.x_coordinate << "," << xMin.y_coordinate << ")" << std::endl;
    std::cout << "yMin (" << yMin.x_coordinate << "," << yMin.y_coordinate << ")" << std::endl;
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
        return new pointExclussionStruct{
        excludePolygonVertices,
        arbitraryPoints,
        numberOfPoints,
        nullptr,
        0
    };
    } else if (xMax == yMax && xMin == yMin){
        return new pointExclussionStruct{
        excludePolygonVertices,
        arbitraryPoints,
        numberOfPoints,
        nullptr,
        0
    };
    }
    
    

    return new pointExclussionStruct{
        new ExcludePolygonVertices{
            xMax,
            yMax,
            xMin,
            yMin
        },
        new Point{1,2},
        1,
        new Point{1,3},
        1
    };
}

