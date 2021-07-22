#include "norm.h"

VALUE_TYPE norm_error(vector<pair<VALUE_TYPE,VALUE_TYPE>> FunctionValues, vector<pair<VALUE_TYPE,VALUE_TYPE>> InterpolatedTable)
{
    VALUE_TYPE norm = 0;

    vector<VALUE_TYPE> delta_x(InterpolatedTable.size());

    for (int i = 0; i < InterpolatedTable.size(); i++)
    {
        delta_x[i] = fabs(InterpolatedTable[i].second - FunctionValues[i].second);
        if (delta_x[i] > norm)
        {
            norm = delta_x[i];
        }
    }

    return norm;
}

