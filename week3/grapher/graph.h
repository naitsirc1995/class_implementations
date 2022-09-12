#ifndef GRAPH_H
#define GRAPH_H
#include "../geometry/Polygon.h"
#include "../cli/handlers/utils.h"
// example function for matplotlib in Cpp----
void do_nice_graph();
//---------------------------------------------


// grapher for the convex hull theorem-----------------------------------------------------------
void graphPolygonAndRandomPoints(Polygon* polygon,Point* randomPoints,int numberOfRandomPoints);
// -----------------------------------------------------------------------------------------------


// grapher for the is_inside algorithm using a country--------------------
void graphCountryPoints(Point* country, int countryTotalVertices);
const int NUMBER_RANDOM_POINTS = 10000;
//------------------------------------------------------------------------
#endif 