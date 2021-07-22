#include "spline_Interpolation.h"

void forward_stroke(TridiagonalMatrix &TridiagonalMatrix, int NodesNumber)
{
    int size = NodesNumber - 2;

    TridiagonalMatrix.c[0] /= ((-1) * TridiagonalMatrix.b[0]); //alpha_2
    TridiagonalMatrix.d[0] /= TridiagonalMatrix.b[0]; //beta_2
    TridiagonalMatrix.b[0] = 1; //x1 = aplha_2 * x2 + beta_2

    for (int i = 1; i < size - 1; i++)
    {
        TridiagonalMatrix.c[i] = TridiagonalMatrix.c[i] / ((-1) * TridiagonalMatrix.b[i] - TridiagonalMatrix.a[i - 1] * TridiagonalMatrix.c[i- 1]);
        TridiagonalMatrix.d[i] = ((-1) * TridiagonalMatrix.d[i] + TridiagonalMatrix.a[i] * TridiagonalMatrix.d[i - 1]) /
                                 ((-1) * TridiagonalMatrix.b[i] - TridiagonalMatrix.a[i] * TridiagonalMatrix.c[i - 1]);

        TridiagonalMatrix.a[i - 1] = 0;
        TridiagonalMatrix.b[i] = 1; //x_i
    }

    TridiagonalMatrix.d[size - 1] = ((-1) * TridiagonalMatrix.d[size - 1] + TridiagonalMatrix.a[size - 2] * TridiagonalMatrix.d[size - 2]) /
                                    ((-1) * TridiagonalMatrix.b[size - 1] - TridiagonalMatrix.a[size - 2] * TridiagonalMatrix.c[size - 2]);
    TridiagonalMatrix.a[size - 2] = 0;
    TridiagonalMatrix.b[size - 1] = 1;
}

void reverse_stroke(TridiagonalMatrix &TridiagonalMatrix, int NodesNumber)
{
    int size = NodesNumber - 2;

    for (int i = size - 2; i >=0; i--)
    {
        TridiagonalMatrix.d[i] += TridiagonalMatrix.c[i] * TridiagonalMatrix.d[i + 1];
        TridiagonalMatrix.c[i] = 0;
    }
}

vector<VALUE_TYPE> TridiagonalMatrixAlgorithm (vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable, int NodesNumber)
{
    vector<VALUE_TYPE> Solution;
    //int size = NodesNumber - 2;

    if (NodesNumber == 3)
    {
        VALUE_TYPE d = 3 * ((InitialTable[2].second - InitialTable[1].second) / (InitialTable[2].first - InitialTable[1].first) -
                            (InitialTable[1].second - InitialTable[0].second) / (InitialTable[1].first - InitialTable[0].first)) - (InitialTable[1].first - InitialTable[0].first) - (InitialTable[2].first - InitialTable[1].first);//- (InitialTable[1].first - InitialTable[0].first) - (InitialTable[2].first - InitialTable[1].first) - для 1 теста
        VALUE_TYPE b = 2 * ((InitialTable[1].first - InitialTable[0].first) + (InitialTable[2].first - InitialTable[1].first));
        Solution.push_back(d / b);
    }
    else
    {
        struct TridiagonalMatrix tridiagonalMatrix = CreateTridiagonalMatrix(InitialTable, NodesNumber);

        forward_stroke(tridiagonalMatrix, NodesNumber);
        reverse_stroke(tridiagonalMatrix, NodesNumber);

        for (int i = 0; i < NodesNumber - 2; i++)
        {
            Solution.push_back(tridiagonalMatrix.d[i]);
        }
    }

    Solution.insert(Solution.begin(), 0); //1-ки для 1го теста
    Solution.push_back(0);

    return Solution;
}

TridiagonalMatrix coefficients_search(vector<VALUE_TYPE> &c_i, vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable)
{
    TridiagonalMatrix coefficients;
    //c_i.insert(c_i.begin(), 1);
    //c_i.insert(c_i.end(), 1);

    for(int i = 1; i < InitialTable.size(); i++)
    {
        coefficients.a.push_back(InitialTable[i - 1].second);
        coefficients.b.push_back((InitialTable[i].second - InitialTable[i - 1].second) / (InitialTable[i].first - InitialTable[i - 1].first) -
                                 (c_i[i] + 2 * c_i[i - 1]) * (InitialTable[i].first - InitialTable[i - 1].first) / 3);
        coefficients.c.push_back(c_i[i - 1]);
        coefficients.d.push_back((c_i[i] - c_i[i - 1]) / (3 * (InitialTable[i].first - InitialTable[i - 1].first)));
    }

    return coefficients;
}

vector<pair<VALUE_TYPE, VALUE_TYPE>> spline_interpolation(vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable, vector<VALUE_TYPE> &x, int NodesNumber)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> InterpolatedTable;

    //TridiagonalMatrix tridiagonalMatrix = CreateTridiagonalMatrix(InitialTable, NodesNumber);
    vector<VALUE_TYPE> solution = TridiagonalMatrixAlgorithm(InitialTable, NodesNumber);
    TridiagonalMatrix coefficients = coefficients_search(solution, InitialTable);

    VALUE_TYPE y_j;
    int j = 0;
    for (int i = 1; i < NodesNumber; i++)
    {
        for(; ((x[j] <= InitialTable[i].first) && (j < x.size())); j++)
        {
            VALUE_TYPE delta = x[j] - InitialTable[i - 1].first;
            y_j = coefficients.a[i - 1] + coefficients.b[i - 1] * delta + coefficients.c[i - 1] * pow(delta, 2) + coefficients.d[i - 1] * pow(delta, 3);
            InterpolatedTable.push_back(make_pair(x[j], y_j));
        }
    }

    return InterpolatedTable;
}