#ifndef CODE_MATRIX_OPERATIONS_H
#define CODE_MATRIX_OPERATIONS_H

#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

#include "sets.h"

using namespace std;

struct TridiagonalMatrix
{
    vector<VALUE_TYPE> a;
    vector<VALUE_TYPE> b;
    vector<VALUE_TYPE> c;
    vector<VALUE_TYPE> d;
};


TridiagonalMatrix CreateTridiagonalMatrix(vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable, int NodesNumber);


#endif //CODE_MATRIX_OPERATIONS_H
