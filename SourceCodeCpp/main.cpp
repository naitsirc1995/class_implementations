//handler
#include "cli/handlers/handlers.h"
#include "cli/handlers/utils.h"
#include "convexHull/pointExclussion.h"

int main()
{        
    //insideCountryHandler("France");
    //giftWrappingAlgorithmHandler();
    //measureGWAEfficiency();
    Point randomElements[4] = {{1,1},{-1,1},{-1,-1},{1,-1}};
    
    fastConvexHull(randomElements,4);
    return 0;
}