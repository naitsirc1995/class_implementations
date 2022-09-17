//handler
#include "cli/handlers/handlers.h"
#include "cli/handlers/utils.h"
#include "convexHull/pointExclussion.h"

int main()
{        
    //insideCountryHandler("France");
    //giftWrappingAlgorithmHandler();
    //measureGWAEfficiency();
    int numberOfPoints = 8;
    Point arbitratyPoints[numberOfPoints] = {{1,0},{0,1},{-1,0},{0,-1},{0,0},{0.5,0},{0.5,0.82},{-0.5,0.82}};
    PointExclusionStruct* pointExclusionStruct  = fastConvexHull(arbitratyPoints,numberOfPoints);
    Point* excludedPoints = pointExclusionStruct->excludedPoints;
    int numberOfExcludedPoints = pointExclusionStruct->numberOfExcludedPoints;
    Point* includedPoints = pointExclusionStruct->includedPoints;
    int numberOfIncludedPoints = pointExclusionStruct->numberOfIncludedPoints;
    
    std::cout << "First the included points " << std::endl;
    for (int i = 0; i < numberOfIncludedPoints; i++){
        Point currentPoint = includedPoints[i];
        std::cout << "(" << currentPoint.x_coordinate << "," << currentPoint.y_coordinate << ")" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Now the excluded points " << std::endl;
    std::cout << "Number of excluded points " << numberOfExcludedPoints << std::endl;
    for (int i = 0; i < numberOfExcludedPoints; i++){
        Point currentPoint = excludedPoints[i];
        std::cout << "(" << currentPoint.x_coordinate << "," << currentPoint.y_coordinate << ")" << std::endl;
    }

    std::cout << std::endl;

    ExcludePolygonVertices* excludePolygonVertices = pointExclusionStruct->excludePolygonVertices;

    std::cout << "xMax=(" << excludePolygonVertices->xMax.x_coordinate << "," << excludePolygonVertices->xMax.y_coordinate << ") yMax=" << excludePolygonVertices->yMax.x_coordinate << "," << excludePolygonVertices->yMax.y_coordinate << ") xMin=" << excludePolygonVertices->xMin.x_coordinate << "," << excludePolygonVertices->xMin.y_coordinate << ") " <<" yMin=(" << excludePolygonVertices->yMin.x_coordinate << "," << excludePolygonVertices->yMin.y_coordinate << ")" << std::endl;

    Point polygonTest[4] = {{1,0},{0,1},{-1,0},{0,-1}}; 
    Polygon myPol = Polygon(polygonTest,4);
    std::cout << myPol.isInside(Point{0,0}) << std::endl;
    return 0;
}