#ifndef PAGEREADER_H
#define PAGEREADER_H
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
  int readEndOfFreeSpace(int pageNumber, int32_t pageSize);
};

#endif // PAGEREADER_H
