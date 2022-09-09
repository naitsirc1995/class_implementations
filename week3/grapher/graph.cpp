#include "graph.h"
#include "../externalLibraries/matplotlibCpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

void do_nice_graph()
{
    std::vector<float> x = {1,2,3};
    plt::plot(x);
    plt::show();
};


void graphPolygonAndRandomPoints(Polygon* polygon,Point* randomPoints,int numberOfRandomPoints)
{
    int numberOfPoints = polygon->getNumberOfVertices();
    PolygonVertex* polygonVertices = polygon->getVertices();
    
    for (int i = 0; i < numberOfPoints; i++)
    {        
        PolygonVertex* currentVertex = &polygonVertices[i];
        std::vector<float> x = {currentVertex->point.x_coordinate,currentVertex->next->point.x_coordinate};
        std::vector<float> y = {currentVertex->point.y_coordinate,currentVertex->next->point.y_coordinate};
        plt::plot(x,y);
    }
    
    std::vector<float> xrand;
    std::vector<float> yrand;

    for (int i = 0; i < numberOfRandomPoints; i++)
    {
        xrand.push_back(randomPoints[i].x_coordinate);
        yrand.push_back(randomPoints[i].y_coordinate);
    }
    plt::plot(xrand,yrand,"r+");
    plt::show();
}