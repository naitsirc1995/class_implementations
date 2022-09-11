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





void measureGWAEfficiency()
{
    measureGWAEfficiency(EXPERIMENTATION_POINTS);
}

void measureGWAEfficiency(std::vector<int> experimetationPoints)
{
    int vectorLength = experimetationPoints.size();
    float* TIMES = new float[vectorLength];
    int* NUMBER_VERTICES = new int[vectorLength];
    int i = 0;
    while (experimetationPoints.size() != 0)
    {
        int number_points = experimetationPoints.front();
        experimetationPoints.erase(experimetationPoints.begin());
        std::cout << "this is the number of points for experimentation " << number_points << std::endl;
        srand(time(NULL));
        int polygonTotalPoints = number_points;
        Point* pointList = generateNRandomPoints(number_points,LOWER_BOUND_GWA,UPPER_BOUND_GWA);
        auto start = std::chrono::high_resolution_clock::now();
        Polygon* convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);        
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
        NUMBER_VERTICES[i] = polygonTotalPoints;
        TIMES[i] = duration.count();
        i++;
        free(pointList);
        free(convexHullPolygon);
    }

    std::cout << "N(Vertices) " << " | " << "T(miliseconds)" << std::endl;

    for (int i = 0; i < vectorLength ; i++)
    {
        std::cout << NUMBER_VERTICES[i] << " | " << TIMES[i] << std::endl;
    }
    free(NUMBER_VERTICES);
    free(TIMES);
}