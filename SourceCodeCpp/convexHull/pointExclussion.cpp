#include "pointExclussion.h"


pointExclussionStruct* fastConvexHull(Point* arbitraryPoints,int numberOfPoints)
{
    Point p1 = arbitraryPoints[0];

    Point xMax , xMin, yMax, yMin; 
    xMax = p1;
    xMin = p1;
    yMax = p1;
    yMin = p1;    

    for (int i = 1; i < numberOfPoints; i++ ){
        Point currentPoint = arbitraryPoints[i];        

        if (currentPoint.x_coordinate > xMax.x_coordinate){
            xMax = currentPoint;
        }

        if (currentPoint.x_coordinate == xMin.x_coordinate && currentPoint.y_coordinate < xMin.y_coordinate){
            xMin = currentPoint;
        }

        if (currentPoint.x_coordinate < xMin.x_coordinate ){
            xMin = currentPoint;
        }

        if (currentPoint.x_coordinate == xMax.x_coordinate && currentPoint.y_coordinate < xMax.y_coordinate){
            xMin = currentPoint;
        }

        if (currentPoint.y_coordinate > yMax.y_coordinate ){            
            yMax = currentPoint;            
        }

        if (currentPoint.y_coordinate == yMax.y_coordinate && currentPoint.x_coordinate > yMax.x_coordinate){            
            yMax = currentPoint;
        }

        if (currentPoint.y_coordinate < yMin.y_coordinate){            
            yMin = currentPoint;            
        }

        if (currentPoint.y_coordinate == yMin.y_coordinate && currentPoint.x_coordinate > yMin.x_coordinate){            
            yMin = currentPoint;            
        }
    }


    std::cout << "Final result " << std::endl;
    std::cout << "xMin (" << xMin.x_coordinate << "," << xMin.y_coordinate << ")" << std::endl;
    std::cout << "xMax (" << xMax.x_coordinate << "," << xMax.y_coordinate << ")" << std::endl;
    std::cout << "yMin (" << yMin.x_coordinate << "," << yMin.y_coordinate << ")" << std::endl;
    std::cout << "yMax (" << yMax.x_coordinate << "," << yMax.y_coordinate << ")" << std::endl;

    return new pointExclussionStruct{
        new ExcludePolygonVertices{
            xMax,
            yMax,
            xMin,
            yMin
        },
        new Point{1,2},
        1,
        new Point{1,3},
        1
    };
}

