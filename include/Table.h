#ifndef TABLE_H
#define TABLE_H
#include "Field.h"
#include "Page.h"
#include <fstream>

using std::ofstream;
using std::vector;

class Table
{
public:
    ofstream &dataFile;
    ofstream &indexFile;
    vector<Field> fields;
    int32_t numOfPage;
    Table(vector<Field> fields, ofstream &dataFile, ofstream &indexFile);
    void addPage();
};

#endif // TABLE_H