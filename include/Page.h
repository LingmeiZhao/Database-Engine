#ifndef PAGE_H
#define PAGE_H
#include "DataWriter.h"

struct Header {
  uint16_t location;
  uint16_t size;
};

class Page {
public:
  ofstream &stream;
  int pageNumber;
  uint16_t numOfEntry;
  uint16_t endOfFreeSpace;
  static const int32_t pageSize = 65536;
  vector<Header> headers;

  Page(ofstream &stream, int32_t pageNumber, vector<Header> headers,
       uint16_t numOfEntry, uint16_t endOfFreeSpace);

  void WriteOneRowAt(vector<Field> fields, vector<string> row,
                     ofstream &indexFile);

  uint16_t GetNumberOfEntries();

  uint16_t GetEndOfFreeSpace();

  int GetPageNumber();

  bool canWrite(int rowLength);

  bool isFull();

  void AddEntry(uint16_t location, uint16_t size);

  void writeHeader();
};

#endif // PAGE_H
