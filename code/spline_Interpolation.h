#ifndef CODE_SPLINE_INTERPOLATION_H
#define CODE_SPLINE_INTERPOLATION_H

#include <vector>
#include <utility>

#include "sets.h"
#include "matrix_operations.h"

using namespace std;

vector<VALUE_TYPE> TridiagonalMatrixAlgorithm (vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable, int NodesNumber);

void forward_stroke(TridiagonalMatrix &TridiagonalMatrix, int NodesNumber);

void reverse_stroke(TridiagonalMatrix &TridiagonalMatrix, int NodesNumber);

TridiagonalMatrix coefficients_search(vector<VALUE_TYPE> &c_i, vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable);

vector<pair<VALUE_TYPE, VALUE_TYPE>> spline_interpolation(vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable, vector<VALUE_TYPE> &x, int NodesNumber);

#endif //CODE_SPLINE_INTERPOLATION_H
