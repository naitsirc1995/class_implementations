#include "handlers.h"
#include "utils.h"



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

    std::cout << "N(Vertices) " << " | " << "T(microseconds)" << std::endl;

    for (int i = 0; i < vectorLength ; i++)
    {
        std::cout << NUMBER_VERTICES[i] << " | " << TIMES[i] << std::endl;
    }
    free(NUMBER_VERTICES);
    free(TIMES);
}



void insideCountryHandler(std::string countryName)
{
    auto [points, numberOfPoints] = readCountry(countryName);
    graphCountryPoints(points,numberOfPoints);
}


//---------------------------------------------------------------------

void testPointGeneratorHandler()
{
    float initialPoint = 0;
    float endPoint = 1;
    int numberOfSteps = 500;
    int numberOfFunctions = 3;
    float (*fx[numberOfFunctions])(float t);
    float (*fy[numberOfFunctions])(float t);

    fx[0] = f1x;
    fx[1] = f2x;
    fx[2] = f3x;

    fy[0] = f1y;
    fy[1] = f2y;
    fy[2] = f3y;

    Point* receivedPoints = boundaryGenerator(initialPoint,endPoint,numberOfSteps,numberOfFunctions,fx,fy);    
    std::vector<float> x;
    std::vector<float> y;    
    for (int i = 0; i < 1500;i++){
        Point currentPoint = receivedPoints[i];
        x.push_back(currentPoint.x_coordinate);
        y.push_back(currentPoint.y_coordinate);
    }


    PolygonInterior* polygonInterior = interiorGenerator(receivedPoints,1500,500);
    std::vector<float> xI;
    std::vector<float> yI;
    for (int i = 0; i < polygonInterior->numberOfInteriorPoints;i++){
        Point currentPoint = polygonInterior->interiorPoints[i];
        xI.push_back(currentPoint.x_coordinate);
        yI.push_back(currentPoint.y_coordinate);
    }
            

    plt::plot(x,y);
    plt::plot(xI,yI,"g*");
    plt::show();

    free(fx);
    free(fy);
    free(receivedPoints);
}