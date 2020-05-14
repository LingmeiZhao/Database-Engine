#ifndef PAGEREADER_H
#define PAGEREADER_H
#include "DataReader.h"
#include "Field.h"
#include "Page.h"
#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::vector;
class PageReader {
public:
  ifstream &stream;
  PageReader(ifstream &stream);
  vector<Header> readHeaders(int pageNumber, int32_t pageSize);
  uint16_t readNumOfEntry(int pageNumber, int32_t pageSize);
  uint16_t readEndOfFreeSpace(int pageNumber, int32_t pageSize);
  vector<string> readRow(Header header, vector<Field> fields);
};

#endif // PAGEREADER_H
