#ifndef HANDLERS_H
#define HANDLERS_H

// Objects and variables associated to the gift-wrapping algorithm
#include "../../grapher/graph.h"
#include "../../geometry/Polygon.h"
#include "../../geometry/Point.h"
#include "../../geometry/pointsGenerators/functionGenerators.h"
#include "../../convexHull/gift_wrapping.h"
#include <vector>

void giftWrappingAlgorithmHandler();
void giftWrappingAlgorithmHandler(int numberOfRandomPoints);
void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int UPPER_BOUND);
void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int UPPER_BOUND,int LOWER_BOUND);
const int TOTAL_RANDOM_POINTS = 2000;
const int UPPER_BOUND_GWA = 200;
const int LOWER_BOUND_GWA = 100;
//----------------------------------------------------------------------


// Measuring efficiency for the gift Wrapping Algorithm
#include <chrono>
const std::vector<int> EXPERIMENTATION_POINTS = {10,50,100,500,1000,5000,10000,30000,40000,45000};
void measureGWAEfficiency();
void measureGWAEfficiency(std::vector<int> number_random_points);
void convexHullEfficiencySquare();
void convexHullEfficiencySquare(std::vector<int> experimetationPoints);
void convexHullEfficiencyCircleBoundary();
void convexHullEfficiencyCircleBoundary(std::vector<int> experimetationPoints);
//----------------------------------------------------------------------



// external libraries
#include <iostream>

// Inside country handler.
void insideCountryHandler(std::string countryName);

//-------------------------------------------------------------


// Fast ConvexHull Algorithm
#include "../../geometry/pointsGenerators/equilateralTriangle/equilateralTriangle.h"
#include "../../externalLibraries/matplotlibCpp/matplotlibcpp.h"
#include "../../convexHull/pointExclussion.h"
#include "../../convexHull/gift_wrapping.h"
void testPointGeneratorHandler();
namespace plt = matplotlibcpp;
//---------------------------------------


// Circle Fast ConvexHull Algorithm
#include "../../geometry/pointsGenerators/circle/circle.h"
#include "../../convexHull/pointExclussion.h"
#include "../../convexHull/gift_wrapping.h"
void circleConvexHullHandler();
//---------------------------------------



// Simplified code handler
#include "../../convexHull/graham_scam.h"
void simplifiedTestHandler();
#endif