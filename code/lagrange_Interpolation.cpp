#include "lagrange_Interpolation.h"

VALUE_TYPE Calculate_ck (vector<pair<VALUE_TYPE,VALUE_TYPE>> x_k, VALUE_TYPE x, int k, int n)
{
    VALUE_TYPE ck = 1;

    for (int j = 0; j < n; j++)
    {
        ck *= (j != k) ? (x - x_k[j].first) / (x_k[k].first - x_k[j].first) : 1;
    }

    return ck;
}

vector<VALUE_TYPE> CreateArgValues(pair<VALUE_TYPE,VALUE_TYPE> Limits)
{
    vector<VALUE_TYPE> x;

    for(int i = 0; i <= (Limits.second - Limits.first) / EPSILON; i++)
    {
        x.push_back(EPSILON * i + Limits.first);
    }

    return x;
}

vector<pair<VALUE_TYPE,VALUE_TYPE>> LagrangeInterpolation(vector<pair<VALUE_TYPE,VALUE_TYPE>> &Table, vector<VALUE_TYPE> &x, int n)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> InterpolatedTable;

    for (VALUE_TYPE x_i : x)
    {
        VALUE_TYPE y_i = 0;
        for (int j = 0; j < n; j++)
        {
            y_i += Calculate_ck(Table, x_i, j, n) * Table[j].second;
        }
        InterpolatedTable.push_back(make_pair(x_i, y_i));
    }
    return InterpolatedTable;
}

VALUE_TYPE Lagranzh_single(vector<pair<VALUE_TYPE,VALUE_TYPE>> table_init, VALUE_TYPE point)
{
    VALUE_TYPE sum = 0; //Значение функции
    for (int i = 0; i < table_init.size(); i ++)
    {
        VALUE_TYPE mul = 1.0;
        for (int j = 0; j < table_init.size(); j++)
        {
            if(j != i){
                mul *= (point - table_init[j].first)/(table_init[i].first - table_init[j].first);
            }
        }
        sum += table_init[i].second * mul;
    }
    point = sum;

    return point;
}