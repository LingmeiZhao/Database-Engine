#ifndef DELETERESULT_H
#define DELETERESULT_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

using std::string;
using std::list;

class DeleteResult{
private:
    long key;
    bool found;
    list<string> values;

public:
    DeleteResult(long key, string* value);
    DeleteResult(long key, list<string> values);
    list<string> getValues();
    long getKey();
    bool isFound();
}




#endif // DELETERESULT_H