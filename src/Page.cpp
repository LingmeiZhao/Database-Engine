#include "Page.h"

using std::cout;
using std::endl;

Page::Page(std::ofstream &stream, int pageNumber, vector<Header> headers,
           uint16_t numOfEntry, uint16_t endOfFreeSpace)
    : stream{stream}, pageNumber{pageNumber}, numOfEntry{numOfEntry},
      endOfFreeSpace{endOfFreeSpace}, headers{headers} {
  stream.write((char *)&numOfEntry, sizeof(uint16_t));
  stream.write((char *)&endOfFreeSpace, sizeof(uint16_t));
}

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
  if (canWrite(rowLength) == false) {
    return;
  }
  uint16_t pos = pageNumber * pageSize + endOfFreeSpace - rowLength;
  DataWriter::writeOneRow(fields, row, pos, stream, pageNumber, numOfEntry,
                          indexFile);
  numOfEntry++;
  endOfFreeSpace = endOfFreeSpace - rowLength;
  writeHeader();
  cout << "row length:" << rowLength << endl;
  AddEntry(pos, rowLength);
}

uint16_t Page::GetNumberOfEntries() { return numOfEntry; }

uint16_t Page::GetEndOfFreeSpace() { return endOfFreeSpace; }

int Page::GetPageNumber() { return pageNumber; }

bool Page::canWrite(int rowLength) {
  uint16_t headerLength = sizeof(uint16_t) * 2 + numOfEntry * sizeof(uint16_t);
  uint16_t freeSpace = endOfFreeSpace - headerLength;
  if (rowLength <= freeSpace) {
    return true;
  } else {
    return false;
  }
}

bool Page::isFull() {
  uint16_t headerLength = sizeof(uint16_t) * 2 + numOfEntry * sizeof(uint16_t);
  uint16_t freeSpace = endOfFreeSpace - headerLength;
  if (freeSpace == 0) {
    return true;
  } else {
    return false;
  }
}

void Page::AddEntry(uint16_t location, uint16_t size) {
  int pos =
      pageNumber * pageSize + sizeof(uint16_t) + numOfEntry * sizeof(uint16_t);
  stream.seekp(pos);
  stream.write((char*)&location, sizeof(uint16_t));
  stream.write((char*)&size, sizeof(uint16_t));
  //stream.put(location / 256);
  //stream.put(location % 256);
  //stream.put(size );
}

void Page::writeHeader(){
  int pos = pageNumber * pageSize;
  stream.seekp(pos);
  stream.write((char*)& numOfEntry, sizeof(uint16_t));
  stream.write((char*)& endOfFreeSpace, sizeof(uint16_t));
}
