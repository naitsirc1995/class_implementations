#include "gift_wrapping.h"
#include <iostream>

int orientation(Point* p1, Point* p2, Point* p3)
{
    float x1 = p1->x_coordinate;
    float x2 = p2->x_coordinate;
    float x3 = p3->x_coordinate;

    float y1 = p1->y_coordinate;
    float y2 = p2->y_coordinate;
    float y3 = p3->y_coordinate;

    float d = (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);

    if (d>0){
        return 1;
    } else if (d<0){
        return -1;
    } else {
        return 0;
    }    
}


Polygon* gift_wrapping(Point* arbitraryPoints,int numberOfPoints)
{
    Point onHull = arbitraryPoints[0];
    Point* hull = (Point*) malloc(sizeof(Point)*numberOfPoints);

    for (int i = 0 ; i < numberOfPoints; i++)
    {
        if (arbitraryPoints[i].x_coordinate < onHull.x_coordinate )
        {
            onHull = arbitraryPoints[i];
        }
    }

    int i = 0;
    
    while (true)
    {
        hull[i] = onHull;
        Point nextPoint = arbitraryPoints[0];
        //std::cout << "The next point in polygon would be (" << nextPoint.x_coordinate << "," << nextPoint.y_coordinate << ")" << std::endl;
        for (int i = 0; i < numberOfPoints ; i++)
        {
            Point point = arbitraryPoints[i];
            int o = orientation(&onHull,&nextPoint,&point);
            if ((nextPoint == onHull || o == 1) || (o == 0 && (dist(onHull,point) > dist(onHull,nextPoint))))
            {
                nextPoint = point;
            }
        }
        onHull = nextPoint;
        if (onHull == hull[0]) break;
        i++;        
    }
        
    
    return new Polygon(hull,numberOfPoints);
}