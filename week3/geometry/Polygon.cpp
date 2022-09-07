#include "Polygon.h"
#include <iostream>
#include <stdexcept>


Polygon::Polygon(Point *polygonPoints,int numberOfPoligonPoints)
{
    //PolygonVertex* polygonVertices;
     //   int numberOfVertices;
    
    numberOfVertices = numberOfPoligonPoints;

    if (numberOfVertices < 3)
    {
        throw std::invalid_argument("[error] simple polygon must have at least 3 points");
    }

    polygonVertices = (PolygonVertex*) malloc(sizeof(PolygonVertex)*numberOfPoligonPoints);

    for (int i = 0; i< numberOfPoligonPoints; i++)
    {                
        polygonVertices[i].point = polygonPoints[i];        
    }

    for (int i = 0 ; i < numberOfPoligonPoints ; i++)
    {
        if (i == numberOfPoligonPoints-1)
        {
            polygonVertices[i].next = &polygonVertices[0];
        } else {
            polygonVertices[i].next = &polygonVertices[i+1];
        }
    }

    for (int i = numberOfPoligonPoints-1 ; i >= 0 ; i--)
    {
        if (i == 0)
        {
            polygonVertices[0].previous = &polygonVertices[numberOfPoligonPoints-1];
        } else {
            polygonVertices[i].previous = &polygonVertices[i-1];
        }
    }
    std::cout << "[info] polygon of " << numberOfPoligonPoints << " vertices has been created" << std::endl;
}

PolygonVertex* Polygon::getVertices(){return polygonVertices;};