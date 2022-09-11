#ifndef HANDLERS_H
#define HANDLERS_H

// Objects and variables associated to the gift-wrapping algorithm
#include "../../grapher/graph.h"
#include "../../geometry/Polygon.h"
#include "../../geometry/Point.h"
#include "../../convexHull/gift_wrapping.h"
void giftWrappingAlgorithmHandler(int numberOfRandomPoints);
void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int limit);
const int MAX_DEFAULT_LIMIT = 100;

//-----------------------------------------------------------------------------



// external libraries
#include <iostream>


#endif