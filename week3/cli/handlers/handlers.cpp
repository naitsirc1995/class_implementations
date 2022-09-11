#include "handlers.h"

// utils 
Point* generateNRandomPoints(int numberOfPoints,int LOWER_BOUND,int UPPER_BOUND)
{
    srand(time(NULL));
    Point* pointList = new Point[numberOfPoints];
    for (int i = 0; i < numberOfPoints ; i++)
    {
        float randx = LOWER_BOUND + (std::rand()/float(RAND_MAX))*(UPPER_BOUND-LOWER_BOUND);
        float randy = LOWER_BOUND + (std::rand()/float(RAND_MAX))*(UPPER_BOUND-LOWER_BOUND);
        pointList[i] = {randx,randy};
    }

    return pointList;
}

// ----------------------------------------------------------------------------------



// gift-wrapping algorithm handler------------------------------------------------
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
//----------------------------------------------------------------------------------