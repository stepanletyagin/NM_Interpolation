#ifndef CODE_NORM_H
#define CODE_NORM_H

#include <vector>

#include "sets.h"
#include "test_functions.h"

using namespace std;

VALUE_TYPE norm_error (vector<pair<VALUE_TYPE,VALUE_TYPE>> FunctionValues, vector<pair<VALUE_TYPE,VALUE_TYPE>> InterpolatedTable);

#endif //CODE_NORM_H
