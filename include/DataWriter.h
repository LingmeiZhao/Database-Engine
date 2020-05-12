#ifndef DATAWRITER_H
#define DATAWRITER_H
#include "Field.h"
#include <fstream>
#include <iostream>
#include <vector>

using std::ofstream;
using std::string;
using std::vector;

class DataWriter {
public:
  DataWriter();
  static void writeOneRow(vector<Field> fields, vector<string> row,
                          uint16_t startPosition, ofstream &dataFile,
                          int32_t pageNumber, uint16_t entryNumber,
                          ofstream &indexFile);
};

#endif // DATAWRITER_H
