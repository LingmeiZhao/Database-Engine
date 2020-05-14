#include "DataWriter.h"
#include <cmath>

using std::cout;
using std::endl;
DataWriter::DataWriter() {}

void DataWriter::writeOneRow(vector<Field> fields, vector<string> row,
                             uint16_t startPosition, ofstream &dataFile,
                             int32_t pageNumber, uint16_t entryNumber,
                             ofstream &indexFile) {
  uint16_t n = row.size();
  dataFile.seekp(startPosition);
  for (int i = 0; i < n; i++) {
    bool isKey = false;
    if (fields[i].isPrimaryKey == true) {
      isKey = true;
    }
    if (fields[i].dataType == "INTEGER") {
      int64_t value = stol(row[i]);
      dataFile.write((char *)&value, 8);
    } else if (fields[i].dataType == "REAL") {
      double_t value = stod(row[i]);
      dataFile.write((char *)&value, 8);
    } else {
      int size = row[i].size();
      dataFile.put((char)(size / 256));
      dataFile.put((char)(size % 256));
      for (char c : row[i]) {
        dataFile.put(c);
      }
    }
    if (isKey == true) {
      if (fields[i].dataType == "INTEGER") {
        int64_t value = stol(row[i]);
        indexFile.write((char *)&value, 8);
      } else if (fields[i].dataType == "TEXT") {
        int size = row[i].size();
        indexFile.put((char)(size / 256));
        indexFile.put((char)(size % 256));
        for (char c : row[i]) {
          indexFile.put(c);
        }
      }
      indexFile.write((char *)&pageNumber, sizeof(int32_t));
      indexFile.write((char *)&entryNumber, sizeof(uint16_t));
    }
  }
  if (!dataFile.good()) {
    cout << "Error happens when writing data file!" << endl;
    return;
  }
  if (!indexFile.good()) {
    cout << "Error happens when writing index file!" << endl;
    return;
  }
}