#ifndef UTILS_H
#define UTILS_H


// External libraries
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>
#include <tuple>
//----------------------------------------


// Personal code
#include "../../geometry/Point.h"

std::vector<std::pair<std::string,std::vector<int>>> read_csv(std::string filename);

std::tuple<Point*,int> readCountry(std::string countryName);
std::tuple<Point*,int> readCountry(std::string countryName,std::string basePath);
const std::string basePathCountries = "data/countries/countrydata/";
const int xCoordinateConst = 0;
const int yCoordinateConst = 1;
void printBrasilPoint();


// generate n-random numbers
Point* generateNRandomPoints(int numberOfPoints,int LOWER_BOUND,int UPPER_BOUND);

#endif