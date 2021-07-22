#ifndef CODE_GRID_H
#define CODE_GRID_H

#include <vector>

#include "sets.h"

using namespace std;

vector<VALUE_TYPE> UniformGrid(pair<VALUE_TYPE,VALUE_TYPE> limits, int nodes);

vector<VALUE_TYPE> ChebyshevGrid(pair<VALUE_TYPE,VALUE_TYPE> limits, int nodes);

#endif //CODE_GRID_H
