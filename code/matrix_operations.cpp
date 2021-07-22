#include "matrix_operations.h"

TridiagonalMatrix CreateTridiagonalMatrix(vector<pair<VALUE_TYPE, VALUE_TYPE>> &InitialTable, int NodesNumber)
{
    TridiagonalMatrix matrix;

    int size = NodesNumber - 1;

    matrix.b.push_back(2 * (InitialTable[2].first - InitialTable[0].first));
    matrix.c.push_back(InitialTable[2].first - InitialTable[1].first);

    matrix.d.push_back(3 * ((InitialTable[2].second - InitialTable[1].second) / (InitialTable[2].first - InitialTable[1].first) -
                            (InitialTable[1].second - InitialTable[0].second) / (InitialTable[1].first - InitialTable[0].first)) - InitialTable[1].first - InitialTable[0].first);//- InitialTable[1].first - InitialTable[0].first - для 1 теста

    for (int i = 3; i < size; i++)
    {
        matrix.a.push_back(InitialTable[i - 1].first - InitialTable[i - 2].first);
        matrix.b.push_back(2 * (InitialTable[i].first - InitialTable[i - 2].first));
        matrix.c.push_back(InitialTable[i].first - InitialTable[i - 1].first);

        matrix.d.push_back(3 * ((InitialTable[i].second - InitialTable[i - 1].second) / (InitialTable[i].first - InitialTable[i - 1].first) -
                                (InitialTable[i - 1].second - InitialTable[i - 2].second) / (InitialTable[i - 1].first - InitialTable[i - 2].first)));
    }

    matrix.a.push_back(InitialTable[size - 1].first - InitialTable[size - 2].first);
    matrix.b.push_back(2 * (InitialTable[size].first - InitialTable[size - 2].first));

    matrix.d.push_back(3 * ((InitialTable[size].second - InitialTable[size - 1].second) / (InitialTable[size].first - InitialTable[size - 1].first) -
                            (InitialTable[size - 1].second - InitialTable[size - 2].second) / (InitialTable[size - 1].first - InitialTable[size - 2].first)) - InitialTable[size - 1].first - InitialTable[size - 2].first);//- InitialTable[size - 1].first - InitialTable[size - 2].first - для 1 теста

    return matrix;
}

