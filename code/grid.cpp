#include "grid.h"

using namespace std;

vector<VALUE_TYPE> UniformGrid(pair<VALUE_TYPE,VALUE_TYPE> limits, int nodes)
{
    //int step = (limits.second - limits.first)/nodes;
    vector<VALUE_TYPE> Arguments(nodes);

    for (int i = 0; i < nodes; i++)
    {
        Arguments[i] = limits.first + (i * (limits.second - limits.first))/(nodes - 1);
    }
    return Arguments;
}

vector<VALUE_TYPE> ChebyshevGrid(pair<VALUE_TYPE,VALUE_TYPE> limits, int nodes)
{
    vector<VALUE_TYPE> Arguments(nodes);

    for (int i = 0; i < nodes; i++)
    {
        Arguments[i] = (limits.first + limits.second) / 2 + cos((2 * i + 1) * PI / (2 * nodes)) * (limits.second - limits.first) / 2 ;
    }
    sort (Arguments.begin(), Arguments.end());
    return Arguments;
}

