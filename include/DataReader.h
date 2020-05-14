#ifndef DATAREADER_H
#define DATAREADER_H
#include "Field.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

class DataReader {
public:
  DataReader();
  static vector<string> readOneRow(vector<Field> fields, uint16_t startPosition,
                         ifstream &dataFile);
};

#endif // DATAREADER_H
