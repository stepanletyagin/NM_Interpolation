#ifndef CODE_TEST_FUNCTIONS_H
#define CODE_TEST_FUNCTIONS_H

#include <vector>
#include <utility>

#include "sets.h"

using namespace std;

struct Function
{
    pair<VALUE_TYPE,VALUE_TYPE> Limits; //Пределы
    vector<pair<VALUE_TYPE,VALUE_TYPE>> Table; //Таблица значений
    int NodesNumber = 100; //Кол-во значений
};

vector<pair<VALUE_TYPE,VALUE_TYPE>> FirstFunction (vector<VALUE_TYPE> Arguments);

vector<pair<VALUE_TYPE,VALUE_TYPE>> SecondFunction (vector<VALUE_TYPE> Arguments);

vector<pair<VALUE_TYPE,VALUE_TYPE>> ThirdFunction (vector<VALUE_TYPE> Arguments);

vector<pair<VALUE_TYPE,VALUE_TYPE>> FourthFunction (vector<VALUE_TYPE> Arguments);

vector<pair<VALUE_TYPE,VALUE_TYPE>> EXP_func (vector<VALUE_TYPE> Arguments);

#endif //CODE_TEST_FUNCTIONS_H
