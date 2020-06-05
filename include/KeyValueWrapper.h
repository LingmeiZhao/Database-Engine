#ifndef KEYVALUEWRAPPER_H
#define KEYVALUEWRAPPER_H
#include <iostream>
#include <stdlib.h>
#include <string>

using std::string;

class KeyValueWrapper{
private:
    long key;
    string value;

public:
    KeyValueWrapper(long key, string value);
    long getKey();
    string getValue();
};





#endif // KEYVALUEWRAPPER_H