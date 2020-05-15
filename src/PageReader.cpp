#include "PageReader.h"

using std::cout;
using std::endl;

PageReader::PageReader(ifstream &stream) : stream{stream} {}

vector<Header> PageReader::readHeaders(int pageNumber, int32_t pageSize) {
  int pos = sizeof(uint16_t) * 2 + pageNumber * pageSize;
  int numOfEntry = readNumOfEntry(pageNumber, pageSize);
  stream.seekg(pos);
  vector<Header> headers;
  for (int i = 0; i < numOfEntry; i++) {
    uint16_t location = 0;
    stream.read((char *)&location, sizeof(uint16_t));
    cout << "location in reader: " << location << endl;
    uint16_t size = 0;
    stream.read((char *)&size, sizeof(uint16_t));
    cout << "location in size: " << size << endl;
    Header header = {location, size};
    headers.push_back(header);
  }
  return headers;
}

uint16_t PageReader::readNumOfEntry(int pageNumber, int32_t pageSize) {
  int pos = pageNumber * pageSize;
  stream.seekg(pos);
  uint16_t numOfEntry = 0;
  stream.read((char *)&numOfEntry, sizeof(uint16_t));
  return numOfEntry;
}

uint16_t PageReader::readEndOfFreeSpace(int pageNumber, int32_t pageSize) {
  int pos = sizeof(uint16_t) + pageNumber * pageSize;
  stream.seekg(pos);
  uint16_t endOfFreeSpace = 0;
  stream.read((char *)&endOfFreeSpace, sizeof(uint16_t));
  return endOfFreeSpace;
}

vector<string> PageReader::readRow(Header header, vector<Field> fields){
  uint16_t location = header.location;
  uint16_t size = header.size;
  vector<string> result = DataReader::readOneRow(fields, location, stream);
  return result;
}
