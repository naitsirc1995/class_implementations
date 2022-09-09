#ifndef POLYGON_H
#define POLYGON_H 

#include "Point.h"

struct PolygonVertex {
    Point point;
    PolygonVertex *next;
    PolygonVertex *previous;
};

class Polygon {

    public:
        Polygon(Point *polygonPoints,int numberOfPoligonPoints);
        PolygonVertex* getVertices();
        int getNumberOfVertices();
    
    private:
        PolygonVertex* polygonVertices;
        int numberOfVertices;
        

};

#endif 