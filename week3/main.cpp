// Custom code 
#include "grapher/graph.h"
#include "geometry/Polygon.h"
#include "geometry/Point.h"
#include "convexHull/gift_wrapping.h"
#include "cli/handlers/handlers.h"
// external libraries 
#include <iostream>


int main()
{
    //srand(time(NULL));
    //int polygonTotalPoints = 100;
    //int limit = 100;
    //Point* pointList = new Point[polygonTotalPoints];

    // for (int i = 0; i<polygonTotalPoints; i++){
    //     float randx = (std::rand()/float(RAND_MAX))*limit;
    //     float randy = (std::rand()/float(RAND_MAX))*limit;
    //     pointList[i] = {randx,randy};
    // }
        
    // Polygon* convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);
    // PolygonVertex* firstConvexHullPolygonVertex = convexHullPolygon->getVertices();
    
    // graphPolygonAndRandomPoints(convexHullPolygon,pointList,polygonTotalPoints);

    giftWrappingAlgorithmHandler(100);

    
    return 0;
}