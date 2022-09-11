#include "handlers.h"

void giftWrappingAlgorithmHandler(int numberOfRandomPoints)
{
    giftWrappingAlgorithmHandler(numberOfRandomPoints,MAX_DEFAULT_LIMIT);
}


void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int limit)
{
    srand(time(NULL));
    int polygonTotalPoints = numberOfRandomPoints;    
    Point* pointList = new Point[polygonTotalPoints];

    for (int i = 0; i<polygonTotalPoints; i++){
        float randx = (std::rand()/float(RAND_MAX))*limit;
        float randy = (std::rand()/float(RAND_MAX))*limit;
        pointList[i] = {randx,randy};
    }
        
    Polygon* convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);
    PolygonVertex* firstConvexHullPolygonVertex = convexHullPolygon->getVertices();
    
    graphPolygonAndRandomPoints(convexHullPolygon,pointList,polygonTotalPoints);
}