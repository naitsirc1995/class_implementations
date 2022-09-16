#ifndef HANDLERS_H
#define HANDLERS_H

// Objects and variables associated to the gift-wrapping algorithm
#include "../../grapher/graph.h"
#include "../../geometry/Polygon.h"
#include "../../geometry/Point.h"
#include "../../convexHull/gift_wrapping.h"
#include <vector>

void giftWrappingAlgorithmHandler();
void giftWrappingAlgorithmHandler(int numberOfRandomPoints);
void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int UPPER_BOUND);
void giftWrappingAlgorithmHandler(int numberOfRandomPoints,int UPPER_BOUND,int LOWER_BOUND);
const int TOTAL_RANDOM_POINTS = 10;
const int UPPER_BOUND_GWA = 200;
const int LOWER_BOUND_GWA = 100;
//----------------------------------------------------------------------


// Measuring efficiency for the gift Wrapping Algorithm
#include <chrono>
const std::vector<int> EXPERIMENTATION_POINTS = {10,50,100,500,1000,5000,10000,50000};
void measureGWAEfficiency();
void measureGWAEfficiency(std::vector<int> number_random_points);
//----------------------------------------------------------------------



// external libraries
#include <iostream>

// Inside country handler.
void insideCountryHandler(std::string countryName);
#endif