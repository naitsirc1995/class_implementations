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
void giftWrappingAlgorithmHandler()
{
    giftWrappingAlgorithmHandler(TOTAL_RANDOM_POINTS);
}

void giftWrappingAlgorithmHandler(int numberOfRandomPoints)
{
    giftWrappingAlgorithmHandler(numberOfRandomPoints,UPPER_BOUND_GWA);
}


void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int UPPER_BOUND)
{
    giftWrappingAlgorithmHandler(numberOfRandomPoints,UPPER_BOUND,LOWER_BOUND_GWA);
}

void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int UPPER_BOUND,int LOWER_BOUND)
{
    srand(time(NULL));
    int polygonTotalPoints = numberOfRandomPoints;    
    Point* pointList = generateNRandomPoints(numberOfRandomPoints,LOWER_BOUND,UPPER_BOUND);        
    Polygon* convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);    
    graphPolygonAndRandomPoints(convexHullPolygon,pointList,polygonTotalPoints);
}
//----------------------------------------------------------------------------------