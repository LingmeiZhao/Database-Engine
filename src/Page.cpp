#include "Page.h"

Page::Page(std::ofstream &stream, int pageNumber, vector<Header> headers,
           uint16_t numOfEntry, uint16_t endOfFreeSpace)
    : stream{stream}, pageNumber{pageNumber}, numOfEntry{numOfEntry},
      endOfFreeSpace{endOfFreeSpace}, headers{headers} {}

void Page::WriteOneRowAt(vector<Field> fields, vector<string> row,
                         ofstream &indexFile) {
  int n = row.size();
  uint16_t rowLength = 0;
  for (int i = 0; i < n; i++) {
    if (fields[i].dataType == "INTEGER" || fields[i].dataType == "REAL") {
      rowLength += 8;
    } else {
      rowLength += row[i].size();
    }
  }
  endOfFreeSpace = pageNumber * pageSize + endOfFreeSpace - rowLength;
  DataWriter::writeOneRow(fields, row, endOfFreeSpace, stream, pageNumber,
                          numOfEntry, indexFile);
  numOfEntry++;
}

uint16_t Page::GetNumberOfEntries() { return numOfEntry; }

uint16_t Page::GetEndOfFreeSpace() { return endOfFreeSpace; }

int Page::GetPageNumber() { return pageNumber; }

void Page::AddEntry(uint16_t location, uint16_t size) {
  int pos =
      pageNumber * pageSize + sizeof(uint16_t) + numOfEntry * sizeof(uint16_t);
  stream.seekp(pos);
  stream.put(location);
  stream.put(size);
}
