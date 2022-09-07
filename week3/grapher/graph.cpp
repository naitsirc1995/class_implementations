#include "graph.h"
#include "../externalLibraries/matplotlibCpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

void do_nice_graph()
{
    std::vector<float> x = {1,2,3};
    plt::plot(x);
    plt::show();
};