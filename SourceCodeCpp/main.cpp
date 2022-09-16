//handler
#include "cli/handlers/handlers.h"
#include "cli/handlers/utils.h"
#include "convexHull/pointExclussion.h"

int main()
{        
    //insideCountryHandler("France");
    //giftWrappingAlgorithmHandler();
    //measureGWAEfficiency();
    Point randomElements[10] = {{-1,0},{0,1},{1,1},{0.8,0.9},{0.82,0.9},{0.83,0.9}};
    
    fastConvexHull(randomElements,4);
    return 0;
}