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
  int32_t startPos;
  static const int32_t pageSize = 65536;

  Page(ofstream &stream, int32_t pageNumber);

  void WriteAt(int32_t offset, const std::vector<char> &bytes);

  uint16_t GetNumberOfEntries();

  void AddEntry(uint16_t location, uint16_t size);

  Header ReadEntryInfo(int index);
};

#endif // PAGE_H
