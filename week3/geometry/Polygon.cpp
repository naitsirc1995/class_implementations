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
    //std::cout << "[info] polygon of " << numberOfPoligonPoints << " vertices has been created" << std::endl;
}

PolygonVertex* Polygon::getVertices(){return polygonVertices;};

int Polygon::getNumberOfVertices(){return numberOfVertices;};


int Polygon::countPointIntersections(Point p)
{
    int finalCount = 0;

    for (int i = 0; i < numberOfVertices; i++)
    {
        PolygonVertex* currentVertex = &polygonVertices[i];
        PolygonVertex* previousVertex = currentVertex->previous;
        PolygonVertex* nextVertex = currentVertex->next;

        Point currentPoint = currentVertex->point;
        Point nextPoint = nextVertex->point;
        Point previousPoint = previousVertex->point;        

        if ( std::max(currentPoint.x_coordinate,nextPoint.x_coordinate) < p.x_coordinate)
        {
            //std::cout << "The line is to the left so does not count " << std::endl;
            continue;
        }
        else if (currentPoint.y_coordinate == nextPoint.y_coordinate)
        {
            //std::cout << std::endl;
            //std::cout << "The line is horizontal so does not count " << std::endl;
            //std::cout << "p1= (" << currentPoint.x_coordinate << "," << currentPoint.y_coordinate << ") p2= (" << nextPoint.x_coordinate << "," << nextPoint.y_coordinate << ")" << std::endl;
            continue;
        } else if (p.y_coordinate == currentPoint.y_coordinate)
        {
            //std::cout << " Vertex intersection!!" << std::endl;
            if ( (previousPoint.y_coordinate - currentPoint.y_coordinate)*(nextPoint.y_coordinate - currentPoint.y_coordinate) < 0 )
            {
                //std::cout << " Line intersection was with valid vertex so it is augmented by 1 " << std::endl;
                finalCount++;
            } 
        } else 
        {            
            float yMin = std::min(currentPoint.y_coordinate,nextPoint.y_coordinate);
            float yMax = std::max(currentPoint.y_coordinate,nextPoint.y_coordinate);
            //std::cout << std::endl;
            //std::cout << "p1= (" << currentPoint.x_coordinate << "," << currentPoint.y_coordinate << ") p2= (" << nextPoint.x_coordinate << "," << nextPoint.y_coordinate << ")" << std::endl;
            //std::cout << "yMin ="<<yMin << " yMax=" << yMax << std::endl;
            //std::cout << " is yMax less than p.y_coordinate? " << (yMax < p.y_coordinate) << std::endl;
            if ((yMin >= p.y_coordinate) ||  (yMax <= p.y_coordinate))
            {                
                continue;
            }
            
            float xIntersection;

            if (currentPoint.x_coordinate == nextPoint.x_coordinate)
            {
                xIntersection = currentPoint.x_coordinate;
            } else 
            {
                xIntersection = ((p.y_coordinate - currentPoint.y_coordinate)/(nextPoint.y_coordinate - currentPoint.y_coordinate))*(nextPoint.x_coordinate-currentPoint.x_coordinate) + currentPoint.x_coordinate;
            }

            //std::cout << " x-intersection =" << xIntersection << std::endl;

            if (xIntersection < p.x_coordinate)
            {
                continue;
            } else 
            {
                //std::cout << "Valid line intersection " << std::endl;
                //std::cout << "p1= (" << currentPoint.x_coordinate << "," << currentPoint.y_coordinate << ") p2= (" << nextPoint.x_coordinate << "," << nextPoint.y_coordinate << ")" << std::endl;
                finalCount++;
            }
        }
    }

    return finalCount;
}


bool Polygon::isInside(Point p)
{
    return countPointIntersections(p)%2 != 0;
}