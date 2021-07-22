#ifndef CODE_LAGRANGE_INTERPOLATION_H
#define CODE_LAGRANGE_INTERPOLATION_H

#include <vector>
#include <utility>

#include "test_functions.h"
#include "sets.h"

using namespace std;

//Calculate С_k coef
VALUE_TYPE Calculate_ck (VALUE_TYPE x, int k, int n);

//Vector of new X values
vector<VALUE_TYPE> CreateArgValues(pair<VALUE_TYPE,VALUE_TYPE> Limits);

//Lagrange Interpolation
vector<pair<VALUE_TYPE,VALUE_TYPE>> LagrangeInterpolation(vector<pair<VALUE_TYPE,VALUE_TYPE>> &Table, vector<VALUE_TYPE> &x, int n);

VALUE_TYPE Lagranzh_single(vector<pair<VALUE_TYPE,VALUE_TYPE>> table_init, VALUE_TYPE point);

#endif //CODE_LAGRANGE_INTERPOLATION_H
