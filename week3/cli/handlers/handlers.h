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
//----------------------------------------------------------------------



// utils 
Point* generateNRandomPoints(int numberOfPoints,int LOWER_BOUND,int UPPER_BOUND);
//


// external libraries
#include <iostream>


#endif