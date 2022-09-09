#include "graph.h"
#include "../externalLibraries/matplotlibCpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

void do_nice_graph()
{
    std::vector<float> x = {1,2,3};
    plt::plot(x);
    plt::show();
};


void graphPolygon(Polygon* polygon)
{
    int numberOfPoints = polygon->getNumberOfVertices();
    PolygonVertex* polygonVertices = polygon->getVertices();
    
    for (int i = 0; i < numberOfPoints; i++)
    {        
        PolygonVertex* currentVertex = &polygonVertices[i];
        std::cout << "x-coordinates: " <<  currentVertex->point.x_coordinate << " " << currentVertex->next->point.x_coordinate << std::endl;
        std::cout << "y-coordinates: " <<  currentVertex->point.y_coordinate << " " << currentVertex->next->point.y_coordinate << std::endl;
        std::vector<float> x = {currentVertex->point.x_coordinate,currentVertex->next->point.x_coordinate};
        std::vector<float> y = {currentVertex->point.y_coordinate,currentVertex->next->point.y_coordinate};
        plt::plot(x,y);
    }
    
    
    plt::show();
}