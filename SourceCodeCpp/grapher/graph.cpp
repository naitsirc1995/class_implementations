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

    free(polygon);
    free(randomPoints);
    
    plt::plot(xrand,yrand,"r+");
    plt::show();
}


void graphCountryPoints(Point* country, int countryTotalVertices)
{
    Polygon countryPolygon = Polygon(country,countryTotalVertices);

    PolygonVertex* vertices = countryPolygon.getVertices();

    float xLowest  = vertices[0].point.x_coordinate;
    for (int i = 1; i < countryTotalVertices; i++)
    {
        float xPresent = vertices[i].point.x_coordinate;
        if (xPresent < xLowest)
        {
            xLowest = xPresent;
        }
    }

    float xHighest  = vertices[0].point.x_coordinate;
    for (int i = 1; i < countryTotalVertices; i++)
    {
        float xPresent = vertices[i].point.x_coordinate;
        if (xPresent > xHighest)
        {
            xHighest = xPresent;
        }
    }


    float yLowest  = vertices[0].point.y_coordinate;
    for (int i = 1; i < countryTotalVertices; i++)
    {
        float yPresent = vertices[i].point.y_coordinate;
        if (yPresent < yLowest)
        {
            yLowest = yPresent;
        }
    }

    float yHighest  = vertices[0].point.y_coordinate;
    for (int i = 1; i < countryTotalVertices; i++)
    {
        float yPresent = vertices[i].point.y_coordinate;
        if (yPresent > yHighest)
        {
            yHighest = yPresent;
        }
    }

    float lowerBound = std::min(xLowest,yLowest);
    float upperBound = std::max(xHighest,yHighest);
    Point* points = generateNRandomPoints(NUMBER_RANDOM_POINTS,(int)lowerBound,(int)upperBound);

    std::vector<float> xInside;
    std::vector<float> yInside;

    std::vector<float> xOutside;
    std::vector<float> yOutside;


    for (int i = 0 ; i < NUMBER_RANDOM_POINTS; i++)
    {
        if (countryPolygon.isInside(points[i]))
        {
            xInside.push_back(points[i].x_coordinate);
            yInside.push_back(points[i].y_coordinate);
        } else 
        {
            xOutside.push_back(points[i].x_coordinate);
            yOutside.push_back(points[i].y_coordinate);
        }
    }

    plt::plot(xInside,yInside,"g+");
    plt::plot(xOutside,yOutside,"r+");

    int numberOfPoints = countryPolygon.getNumberOfVertices();
    PolygonVertex* polygonVertices = countryPolygon.getVertices();
    
    for (int i = 0; i < numberOfPoints; i++)
    {        
        PolygonVertex* currentVertex = &polygonVertices[i];
        std::vector<float> x = {currentVertex->point.x_coordinate,currentVertex->next->point.x_coordinate};
        std::vector<float> y = {currentVertex->point.y_coordinate,currentVertex->next->point.y_coordinate};
        plt::plot(x,y);
    }

    plt::show();
    free(country);
    free(points);
}


void do_scatter(std::vector<float> x,std::vector<float> y){
    //plt::plot(x,y); 
}