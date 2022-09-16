#include "utils.h"

std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename){
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<int>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;

    // Read the column names
    if(myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while(std::getline(ss, colname, ',')){
            
            // Initialize and add <colname, int vector> pairs to result
            result.push_back({colname, std::vector<int> {}});
        }
    }

    // Read data, line by line
    while(std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);
        
        // Keep track of the current column index
        int colIdx = 0;
        
        // Extract each integer
        while(ss >> val){
            
            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);
            
            // If the next token is a comma, ignore it and move on
            if(ss.peek() == ',') ss.ignore();
            
            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}

void printBrasilPoint()
{
    std::vector<std::pair<std::string, std::vector<int>>> brazil = read_csv("data/countries/countrydata/Brazil.txt");
    std::cout << brazil.at(0).second.at(0) << "," << brazil.at(1).first  << std::endl;   
}


std::tuple<Point*,int> readCountry(std::string countryName)
{
    return readCountry(countryName,basePathCountries);
}

std::tuple<Point*,int> readCountry(std::string countryName,std::string basePath)
{
    std::string txt = ".txt";
    std::string finalPath = basePath + countryName + txt;
    std::vector<std::pair<std::string, std::vector<int>>> country = read_csv(finalPath);

    std::pair<std::string,std::vector<int>> xCoordinates = country.at(xCoordinateConst);
    std::pair<std::string,std::vector<int>> yCoordinates = country.at(yCoordinateConst);

    int totalPoints = xCoordinates.second.size();
    Point* points = new Point[totalPoints];
    float firstXCoordinate = ::atof(xCoordinates.first.c_str());
    float firstYCoordinate = ::atof(yCoordinates.first.c_str());
    Point firstPoint = {firstXCoordinate,firstYCoordinate};
    points[0] = firstPoint;
    for (int i = 1; i < totalPoints ; i++)
    {
        float xCoordinate = xCoordinates.second.at(i-1);
        float yCoordinate = yCoordinates.second.at(i-1);
        points[i] = {xCoordinate,yCoordinate};
    }

    return std::make_tuple(points,totalPoints);
}



Point* generateNRandomPoints(int numberOfPoints,int LOWER_BOUND,int UPPER_BOUND)
{
    srand(time(NULL));
    Point* pointList = new Point[numberOfPoints];
    for (int i = 0; i < numberOfPoints ; i++)
    {
        float randx = LOWER_BOUND + (std::rand()/float(RAND_MAX))*(UPPER_BOUND-LOWER_BOUND);
        float randy = LOWER_BOUND + (std::rand()/float(RAND_MAX))*(UPPER_BOUND-LOWER_BOUND);
        pointList[i] = {randx,randy};
    }

    return pointList;
}