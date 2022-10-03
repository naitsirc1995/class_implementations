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
    int* POLYGON_VERTICES = new int[vectorLength];
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
        POLYGON_VERTICES[i] = convexHullPolygon->getNumberOfVertices();
        TIMES[i] = duration.count();
        i++;
        free(pointList);
        free(convexHullPolygon);
    }

    std::cout << "N(RandomPoints) " << " | " << "N(Vertices) " << "T(microseconds)" << std::endl;

    for (int i = 0; i < vectorLength ; i++)
    {
        std::cout << NUMBER_VERTICES[i] << " | " << POLYGON_VERTICES[i] << " | " << TIMES[i] << std::endl;
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

    fx[0] = eqTf1x;
    fx[1] = eqTf2x;
    fx[2] = eqTf3x;

    fy[0] = eqTf1y;
    fy[1] = eqTf2y;
    fy[2] = eqTf3y;

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
    
    PointExclusionStruct* pointExclusionStruct = fastConvexHull(polygonInterior->interiorPoints,polygonInterior->numberOfInteriorPoints);
    ExcludePolygonVertices* excludePolygonVertices = pointExclusionStruct->excludePolygonVertices;

    std::vector<float> xE = {excludePolygonVertices->xMax.x_coordinate,excludePolygonVertices->yMax.x_coordinate,excludePolygonVertices->xMin.x_coordinate,excludePolygonVertices->yMin.x_coordinate};
    std::vector<float> yE = {excludePolygonVertices->xMax.y_coordinate,excludePolygonVertices->yMax.y_coordinate,excludePolygonVertices->xMin.y_coordinate,excludePolygonVertices->yMin.y_coordinate};

    plt::scatter(xE,yE,500);

    std::vector<float> l1x = { excludePolygonVertices->xMax.x_coordinate, excludePolygonVertices->yMax.x_coordinate};
    std::vector<float> l1y = { excludePolygonVertices->xMax.y_coordinate, excludePolygonVertices->yMax.y_coordinate};

    std::vector<float> l2x = { excludePolygonVertices->yMax.x_coordinate, excludePolygonVertices->xMin.x_coordinate};
    std::vector<float> l2y = { excludePolygonVertices->yMax.y_coordinate, excludePolygonVertices->xMin.y_coordinate};

    std::vector<float> l3x = { excludePolygonVertices->yMin.x_coordinate, excludePolygonVertices->xMin.x_coordinate};
    std::vector<float> l3y = { excludePolygonVertices->yMin.y_coordinate, excludePolygonVertices->xMin.y_coordinate};

    std::vector<float> l4x = { excludePolygonVertices->yMin.x_coordinate, excludePolygonVertices->xMax.x_coordinate};
    std::vector<float> l4y = { excludePolygonVertices->yMin.y_coordinate, excludePolygonVertices->xMax.y_coordinate};

    plt::plot(l1x,l1y);
    plt::plot(l2x,l2y);
    plt::plot(l3x,l3y);
    plt::plot(l4x,l4y);
    
    std::vector<float> xIncluded;
    std::vector<float> yIncluded;

    for (int i = 0 ; i < pointExclusionStruct->numberOfIncludedPoints;i++ ){
        Point p = pointExclusionStruct->includedPoints[i];
        xIncluded.push_back(p.x_coordinate);
        yIncluded.push_back(p.y_coordinate);
    }

    plt::scatter(xIncluded,yIncluded,100);

    Polygon* polygon = executeFaxConvexHull(polygonInterior->interiorPoints,polygonInterior->numberOfInteriorPoints);    
    PolygonVertex* vertices = polygon->getVertices();
    for (int i = 0; i < polygon->getNumberOfVertices() ; i++ ){
        PolygonVertex v = vertices[i];
        Point p1 = v.point;
        Point p2 = v.next->point;
        std::vector<float> x = {p1.x_coordinate,p2.x_coordinate};
        std::vector<float> y = {p1.y_coordinate,p2.y_coordinate};
        plt::plot(x,y);
    }

    plt::plot(x,y);
    plt::plot(xI,yI,"g*");
    plt::show();

    free(receivedPoints);
}


void circleConvexHullHandler(){
    float initialPoint = 0;
    float endPoint = 2*M_PI;
    int numberOfSteps = 500;
    int numberOfFunctions = 1;
    float (*fx[numberOfFunctions])(float t);
    float (*fy[numberOfFunctions])(float t);

    fx[0] = circleX;
    fy[0] = circleY;
    
    Point* receivedPoints = boundaryGenerator(initialPoint,endPoint,numberOfSteps,numberOfFunctions,fx,fy);    
    std::vector<float> x;
    std::vector<float> y;    
    for (int i = 0; i < 500;i++){
        Point currentPoint = receivedPoints[i];
        x.push_back(currentPoint.x_coordinate);
        y.push_back(currentPoint.y_coordinate);
    }


    PolygonInterior* polygonInterior = interiorGenerator(receivedPoints,500,1000);    
    std::vector<float> xI;
    std::vector<float> yI;
    for (int i = 0; i < polygonInterior->numberOfInteriorPoints;i++){
        Point currentPoint = polygonInterior->interiorPoints[i];
        xI.push_back(currentPoint.x_coordinate);
        yI.push_back(currentPoint.y_coordinate);
    }
    
    PointExclusionStruct* pointExclusionStruct = fastConvexHull(polygonInterior->interiorPoints,polygonInterior->numberOfInteriorPoints);
    ExcludePolygonVertices* excludePolygonVertices = pointExclusionStruct->excludePolygonVertices;

    std::vector<float> xE = {excludePolygonVertices->xMax.x_coordinate,excludePolygonVertices->yMax.x_coordinate,excludePolygonVertices->xMin.x_coordinate,excludePolygonVertices->yMin.x_coordinate};
    std::vector<float> yE = {excludePolygonVertices->xMax.y_coordinate,excludePolygonVertices->yMax.y_coordinate,excludePolygonVertices->xMin.y_coordinate,excludePolygonVertices->yMin.y_coordinate};

    plt::scatter(xE,yE,500);

    std::vector<float> l1x = { excludePolygonVertices->xMax.x_coordinate, excludePolygonVertices->yMax.x_coordinate};
    std::vector<float> l1y = { excludePolygonVertices->xMax.y_coordinate, excludePolygonVertices->yMax.y_coordinate};

    std::vector<float> l2x = { excludePolygonVertices->yMax.x_coordinate, excludePolygonVertices->xMin.x_coordinate};
    std::vector<float> l2y = { excludePolygonVertices->yMax.y_coordinate, excludePolygonVertices->xMin.y_coordinate};

    std::vector<float> l3x = { excludePolygonVertices->xMin.x_coordinate, excludePolygonVertices->yMin.x_coordinate};
    std::vector<float> l3y = { excludePolygonVertices->xMin.y_coordinate, excludePolygonVertices->yMin.y_coordinate};

    std::vector<float> l4x = { excludePolygonVertices->yMin.x_coordinate, excludePolygonVertices->xMax.x_coordinate};
    std::vector<float> l4y = { excludePolygonVertices->yMin.y_coordinate, excludePolygonVertices->xMax.y_coordinate};

    plt::plot(l1x,l1y);
    plt::plot(l2x,l2y);
    plt::plot(l3x,l3y);
    plt::plot(l4x,l4y);
    
    std::vector<float> xIncluded;
    std::vector<float> yIncluded;

    for (int i = 0 ; i < pointExclusionStruct->numberOfIncludedPoints;i++ ){
        Point p = pointExclusionStruct->includedPoints[i];
        xIncluded.push_back(p.x_coordinate);
        yIncluded.push_back(p.y_coordinate);
    }

    plt::scatter(xIncluded,yIncluded,100);

    Polygon* polygon = executeFaxConvexHull(polygonInterior->interiorPoints,polygonInterior->numberOfInteriorPoints);    
    PolygonVertex* vertices = polygon->getVertices();
    for (int i = 0; i < polygon->getNumberOfVertices() ; i++ ){
        PolygonVertex v = vertices[i];
        Point p1 = v.point;
        Point p2 = v.next->point;
        std::vector<float> x = {p1.x_coordinate,p2.x_coordinate};
        std::vector<float> y = {p1.y_coordinate,p2.y_coordinate};
        plt::plot(x,y);
    }

    plt::plot(x,y);
    plt::plot(xI,yI,"g*");
    plt::show();

    free(receivedPoints);    
}


void simplifiedTestHandler(){
    

    srand(time(NULL));
    int polygonTotalPoints = 5000;
    Point* pointList = generateNRandomPoints(polygonTotalPoints,0,100);
    Polygon* convexHullPolygon = grahamScan(pointList,polygonTotalPoints);
    graphPolygonAndRandomPoints(convexHullPolygon,pointList,polygonTotalPoints);    

    int numBoundaryPoints = 50;
    int numInteriorPoints = 500;
    //PolygonGenerated* convexHullPoints = CircleBoundaryGenerator(numBoundaryPoints);
    PolygonGenerated* convexHullPoints = CircleGenerator(numBoundaryPoints,numInteriorPoints);
    
    //Polygon* polygon = gift_wrapping(convexHullPoints->points,numBoundaryPoints);
    
    Polygon* polygon = grahamScan(convexHullPoints->points,convexHullPoints->numberOfPoints);
    
    graphPolygonAndRandomPoints(polygon,convexHullPoints->points,convexHullPoints->numberOfPoints);



    int numBoundaryPoints2 = 100;    
    PolygonGenerated* convexHullPoints2 = CircleBoundaryGenerator(numBoundaryPoints2);
     
    
    Polygon* polygon2 = grahamScan(convexHullPoints2->points,convexHullPoints2->numberOfPoints);
    
    graphPolygonAndRandomPoints(polygon2,convexHullPoints2->points,convexHullPoints2->numberOfPoints);


    auto [points, numberOfPoints] = readCountry("Brazil");

    PolygonInterior* polygonInterior = interiorGenerator(points,numberOfPoints,3000);

    Polygon* polygon3 = grahamScan(polygonInterior->interiorPoints,polygonInterior->numberOfInteriorPoints);

    graphPolygonAndRandomPoints(polygon3,polygonInterior->interiorPoints,polygonInterior->numberOfInteriorPoints);


    auto [points1, numberOfPoints1] = readCountry("France");

    PolygonInterior* polygonInterior1 = interiorGenerator(points1,numberOfPoints1,3000);

    Polygon* polygon4 = grahamScan(polygonInterior1->interiorPoints,polygonInterior1->numberOfInteriorPoints);

    graphPolygonAndRandomPoints(polygon4,polygonInterior1->interiorPoints,polygonInterior1->numberOfInteriorPoints);
}

void convexHullEfficiencySquare(){
    convexHullEfficiencySquare(EXPERIMENTATION_POINTS);
}

void convexHullEfficiencySquare(std::vector<int> experimetationPoints){
    int vectorLength = experimetationPoints.size();
    float* TIMES_GW = new float[vectorLength];
    float* TIMES_FCH = new float[vectorLength];
    float* TIMES_GCH = new float[vectorLength];
    float* TIMES_MS = new float[vectorLength];
    int* NUMBER_VERTICES = new int[vectorLength];
    int* POLYGON_VERTICES = new int[vectorLength];
    int i = 0;
    while (experimetationPoints.size() != 0)
    {
        int number_points = experimetationPoints.front();
        experimetationPoints.erase(experimetationPoints.begin());
        std::cout << "this is the number of points for experimentation " << number_points << std::endl;
        srand(time(NULL));
        int polygonTotalPoints = number_points;

        Point* pointList = generateNRandomPoints(number_points,LOWER_BOUND_GWA,UPPER_BOUND_GWA);
        auto start_gw = std::chrono::high_resolution_clock::now();
        Polygon* convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);        
        auto stop_gw = std::chrono::high_resolution_clock::now();
        auto durationGiftWrapping = std::chrono::duration_cast<std::chrono::microseconds>(stop_gw-start_gw);


        auto start_fch = std::chrono::high_resolution_clock::now();
        Polygon* fastConvexHull = executeFaxConvexHull(pointList,polygonTotalPoints);
        auto stop_fch = std::chrono::high_resolution_clock::now();
        auto durationFCH = std::chrono::duration_cast<std::chrono::microseconds>(stop_fch-start_fch);


        auto start_gch = std::chrono::high_resolution_clock::now();
        Polygon* grahamConvexHull = grahamScan(pointList,polygonTotalPoints);
        auto stop_gch = std::chrono::high_resolution_clock::now();
        auto durationGCH = std::chrono::duration_cast<std::chrono::microseconds>(stop_gch-start_gch);

        auto start_ms = std::chrono::high_resolution_clock::now();        
        std::sort(pointList,pointList+(number_points-1),POLAR_ORDER);
        auto stop_ms = std::chrono::high_resolution_clock::now();
        auto durationMS = std::chrono::duration_cast<std::chrono::microseconds>(stop_ms-start_ms);

        NUMBER_VERTICES[i] = polygonTotalPoints;
        POLYGON_VERTICES[i] = convexHullPolygon->getNumberOfVertices();
        TIMES_GW[i] = durationGiftWrapping.count();
        TIMES_FCH[i] = durationFCH.count();
        TIMES_GCH[i] = durationGCH.count();
        TIMES_MS[i] = durationMS.count();
        i++;
        free(pointList);
        free(convexHullPolygon);
    }

    std::cout << "N(RandomPoints)" << "|" << "N(Vertices)" << "|" << "T_GW" << "|" << "T_FCH" << "|" << "T_GCH" << "|" << "T_MS" << std::endl;

    for (int i = 0; i < vectorLength ; i++)
    {
        std::cout << NUMBER_VERTICES[i] << "|" << POLYGON_VERTICES[i] << "|" << TIMES_GW[i] << "|" << TIMES_FCH[i] << "|" << TIMES_GCH[i] << "|" << TIMES_MS[i] << std::endl;
    }
    
}


void convexHullEfficiencyCircleBoundary(){
    convexHullEfficiencyCircleBoundary(EXPERIMENTATION_POINTS);
};

void convexHullEfficiencyCircleBoundary(std::vector<int> experimetationPoints){
    int vectorLength = experimetationPoints.size();
    float* TIMES_GW = new float[vectorLength];
    float* TIMES_FCH = new float[vectorLength];
    float* TIMES_GCH = new float[vectorLength];
    float* TIMES_MS = new float[vectorLength];
    int* NUMBER_VERTICES = new int[vectorLength];
    int* POLYGON_VERTICES = new int[vectorLength];
    int i = 0;
    while (experimetationPoints.size() != 0)
    {
        int number_points = experimetationPoints.front();
        experimetationPoints.erase(experimetationPoints.begin());
        std::cout << "this is the number of points for experimentation " << number_points << std::endl;
        srand(time(NULL));
        int polygonTotalPoints = number_points;

        //Point* pointList = generateNRandomPoints(number_points,LOWER_BOUND_GWA,UPPER_BOUND_GWA);
        PolygonGenerated* polygonGenerated = CircleBoundaryGenerator(number_points);
        Point* pointList = polygonGenerated->points;
        auto start_gw = std::chrono::high_resolution_clock::now();
        Polygon* convexHullPolygon = gift_wrapping(pointList,polygonTotalPoints);        
        auto stop_gw = std::chrono::high_resolution_clock::now();
        auto durationGiftWrapping = std::chrono::duration_cast<std::chrono::microseconds>(stop_gw-start_gw);


        auto start_fch = std::chrono::high_resolution_clock::now();
        Polygon* fastConvexHull = executeFaxConvexHull(pointList,polygonTotalPoints);
        auto stop_fch = std::chrono::high_resolution_clock::now();
        auto durationFCH = std::chrono::duration_cast<std::chrono::microseconds>(stop_fch-start_fch);


        auto start_gch = std::chrono::high_resolution_clock::now();
        Polygon* grahamConvexHull = grahamScan(pointList,polygonTotalPoints);
        auto stop_gch = std::chrono::high_resolution_clock::now();
        auto durationGCH = std::chrono::duration_cast<std::chrono::microseconds>(stop_gch-start_gch);

        auto start_ms = std::chrono::high_resolution_clock::now();        
        std::sort(pointList,pointList+(number_points-1),POLAR_ORDER);
        auto stop_ms = std::chrono::high_resolution_clock::now();
        auto durationMS = std::chrono::duration_cast<std::chrono::microseconds>(stop_ms-start_ms);

        NUMBER_VERTICES[i] = polygonTotalPoints;
        POLYGON_VERTICES[i] = convexHullPolygon->getNumberOfVertices();
        TIMES_GW[i] = durationGiftWrapping.count();
        TIMES_FCH[i] = durationFCH.count();
        TIMES_GCH[i] = durationGCH.count();
        TIMES_MS[i] = durationMS.count();
        i++;
        free(pointList);
        free(convexHullPolygon);
    }

    std::cout << "N(RandomPoints)" << "|" << "N(Vertices)" << "|" << "T_GW" << "|" << "T_FCH" << "|" << "T_GCH" << "|" << "T_MS" << std::endl;

    for (int i = 0; i < vectorLength ; i++)
    {
        std::cout << NUMBER_VERTICES[i] << "|" << POLYGON_VERTICES[i] << "|" << TIMES_GW[i] << "|" << TIMES_FCH[i] << "|" << TIMES_GCH[i] << "|" << TIMES_MS[i] << std::endl;
    }
};