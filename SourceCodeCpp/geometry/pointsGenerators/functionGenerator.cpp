#include "functionGenerators.h"

Point* boundaryGenerator(
    float initialPoint, 
    float endPoint,
    int numberOfSteps,
    float numberOfFunctions, 
    float (**fx)(float t),
    float (**fy)(float t)    
){
    int totalNubmerOfPoints = numberOfSteps*numberOfFunctions;

    float stepSize = (endPoint - initialPoint)/(numberOfSteps-1);
    int pointCounter=0;
    Point* finalPoints = new Point[totalNubmerOfPoints];
    for (int funcIdx = 0; funcIdx < numberOfFunctions; funcIdx++ ){
        for (int stepIdx = 0; stepIdx < numberOfSteps; stepIdx++){            
            float t = initialPoint + stepSize*stepIdx;
            float x = (*fx[funcIdx])(t);
            float y = (*fy[funcIdx])(t);
            Point p = {x,y};
            finalPoints[pointCounter] = p;
            pointCounter++;
        }
    }    
    return finalPoints;
}

PolygonInterior* interiorGenerator(
    Point* polygonPoints, 
    int numberOfPolygonPoints, 
    int numberOfRandomPoints
){
    std::cout << "[info] remember that the function interiorGenerator is expecting polygon points counterclockwise" << std::endl;
    Polygon* polygon = new Polygon(polygonPoints,numberOfPolygonPoints);

    Point p1 = polygonPoints[0];

    float xMax , xMin, yMax, yMin; 
    xMax = p1.x_coordinate;
    xMin = p1.x_coordinate;
    yMax = p1.y_coordinate;
    yMin = p1.y_coordinate;

    for (int i = 1; i < numberOfPolygonPoints; i++ ){
        Point currentPoint = polygonPoints[i];        

        if (currentPoint.x_coordinate > xMax){
            xMax = currentPoint.x_coordinate;
        }        

        if (currentPoint.x_coordinate < xMin ){
            xMin = currentPoint.x_coordinate;
        } 

        if (currentPoint.y_coordinate > yMax){
            yMax = currentPoint.y_coordinate;
        }        

        if (currentPoint.y_coordinate < yMin){
            yMin = currentPoint.y_coordinate;
        }        
    }    
    Point* interiorPoints = new Point[numberOfRandomPoints];
    int numberOfInteriorPoints = 0;
    for (int i = 0; i < numberOfRandomPoints;i++ ){
        float randx = xMin + (std::rand()/float(RAND_MAX))*(xMax-xMin);
        float randy = yMin + (std::rand()/float(RAND_MAX))*(yMax-yMin);
        Point p = {randx,randy};
        if (polygon->isInside(p)){
            interiorPoints[numberOfInteriorPoints] = p;
            numberOfInteriorPoints++;
        }
    }

    return new PolygonInterior{
        interiorPoints,
        numberOfInteriorPoints
    };
};

PolygonGenerated* CircleGenerator(
    int numberOfBoundaryPoints,
    int numberOfInteriorPoints,
    bool includeBoundary,
    float initialPoint, 
    float endPoint,    
    float numberOfFunctions
){
    int arrayCapacity = numberOfBoundaryPoints + numberOfInteriorPoints;
    int numbersToReturn = numberOfInteriorPoints;

    if (includeBoundary == true) numbersToReturn+=numberOfBoundaryPoints;
    float (*fx[numberOfBoundaryPoints])(float t);
    float (*fy[numberOfBoundaryPoints])(float t);

    fx[0] = circleX;
    fy[0] = circleY;

    Point* boundaryPoints = boundaryGenerator(initialPoint,endPoint,numberOfBoundaryPoints,numberOfFunctions,fx,fy);
    PolygonInterior* polygonInterior = interiorGenerator(boundaryPoints,numberOfBoundaryPoints,numberOfInteriorPoints);

    if (!includeBoundary){
        return new PolygonGenerated{
            polygonInterior->interiorPoints,
            polygonInterior->numberOfInteriorPoints
        };
    } else {
        int capacity = numberOfBoundaryPoints + polygonInterior->numberOfInteriorPoints;
        Point* pointsGenerated;
        int numberOfInteriorPoints = polygonInterior->numberOfInteriorPoints;
        for (int i = 0; i < numberOfInteriorPoints; i++ ){
            pointsGenerated[i] = polygonInterior->interiorPoints[i];
        }

        for (int i = 0; i < numberOfBoundaryPoints; i++ ){
            pointsGenerated[i+numberOfInteriorPoints] = boundaryPoints[i];
        }

        return new PolygonGenerated{
            pointsGenerated,
            capacity
        };
    }
};

PolygonGenerated* CircleGenerator(
    int numberOfBoundaryPoints,
    int numberOfInteriorPoints    
){
    return CircleGenerator(
        numberOfBoundaryPoints,
        numberOfInteriorPoints,
        includeCircleBoundary,
        initialCirclePoint,
        endCirclePoint,
        numberOfCircleFunctions
    );
}


PolygonGenerated* CircleBoundaryGenerator(
    int numberOfBoundaryPoints,        
    float initialPoint, 
    float endPoint, 
    float numberOfFunctions
){     
    
    float (*fx[numberOfBoundaryPoints])(float t);
    float (*fy[numberOfBoundaryPoints])(float t);

    fx[0] = circleX;
    fy[0] = circleY;

    Point* boundaryPoints = boundaryGenerator(initialPoint,endPoint,numberOfBoundaryPoints,numberOfFunctions,fx,fy);    
    

    return new PolygonGenerated{
        boundaryPoints,
        numberOfBoundaryPoints
    };
    
}


PolygonGenerated* CircleBoundaryGenerator(
    int numberOfBoundaryPoints
){
    return CircleBoundaryGenerator(
        numberOfBoundaryPoints,
        initialCirclePoint,
        endCirclePoint,
        numberOfCircleFunctions
    );
}