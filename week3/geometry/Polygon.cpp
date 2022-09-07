#include "Polygon.h"
#include <iostream>



Polygon::Polygon(Point *polygonPoints,int numberOfPoligonPoints)
{
    
    
    for (int i = 0; i< numberOfPoligonPoints; i++)
    {        
        std::cout << "(" << polygonPoints[i].x_coordinate << "," << polygonPoints[i].y_coordinate << ")";
    }
    
    std::cout << std::endl;
    
}