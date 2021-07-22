#include "test_functions.h"

//Table for y = x^2
vector<pair<VALUE_TYPE,VALUE_TYPE>> FirstFunction (vector<VALUE_TYPE> Arguments)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> Table;
    Table.resize(Arguments.size());
    for (int i = 0; i < Arguments.size(); i++)
    {
        Table[i].first = Arguments[i];
        Table[i].second = pow(Arguments[i], 2);
    }
    return Table;
}

//Table for y = 1/(1+25x^2)
vector<pair<VALUE_TYPE,VALUE_TYPE>> SecondFunction (vector<VALUE_TYPE> Arguments)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> Table;
    Table.resize(Arguments.size());
    for (int i = 0; i < Arguments.size(); i++)
    {
        Table[i].first = Arguments[i];
        //Table[i].second = 1 / (1 + 25 * sqr(Arguments[i]));
        Table[i].second = 5;
    }
    return Table;
}

//Table for y = 1/(arctg(1 + 10x^2))
vector<pair<VALUE_TYPE,VALUE_TYPE>> ThirdFunction (vector<VALUE_TYPE> Arguments)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> Table;
    Table.resize(Arguments.size());
    for (int i = 0; i < Arguments.size(); i++)
    {
        Table[i].first = Arguments[i];
        Table[i].second = 1 / atan(1 + 10 * sqr(Arguments[i]));
    }
    return Table;
}

//Table for y = (4x^3 + 2x^2 - 4x + 2)^(sqrt(2)) + arcsin(1/(5 + x - x^2)) - 5
vector<pair<VALUE_TYPE,VALUE_TYPE>> FourthFunction (vector<VALUE_TYPE> Arguments)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> Table;
    Table.resize(Arguments.size());
    for (int i = 0; i < Arguments.size(); i++)
    {
        Table[i].first = Arguments[i];
        Table[i].second = pow((4 * pow(Arguments[i], 3) + 2 * pow(Arguments[i] , 2) - 4 * Arguments[i] + 2), sqrt(2)) + asin(1 / (5 + Arguments[i] - pow(Arguments[i], 2))) - 5;
    }
    return Table;
}

vector<pair<VALUE_TYPE,VALUE_TYPE>> EXP_func (vector<VALUE_TYPE> Arguments)
{
    vector<pair<VALUE_TYPE,VALUE_TYPE>> Table;
    Table.resize(Arguments.size());
    for (int i = 0; i < Arguments.size(); i++)
    {
        Table[i].first = Arguments[i];
        Table[i].second = exp(Arguments[i]);
    }
    return Table;
}