#ifndef RANGERESULT_H
#define RANGERESULT_H
#include <iostream>
#include <stdlib.h>
#include <list>
#include "KeyValueWrapper.h"

using std::list;


class RangeResult{
private:
    list<KeyValueWrapper> queryResult;

public:
    RangeResult();
    list<KeyValueWrapper> getQueryResult();
};



#endif // RANGERESULT_H