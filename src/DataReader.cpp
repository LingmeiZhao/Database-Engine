#include "DateReader.h"

using std::cout;
using std::endl;

DataReader::DataReader() {}

void DataReader::readOneRow(vector<Field> fields, uint16_t startPosition,
                            std::ifstream &dataFile) {
  int n = fields.size();
  dataFile.seekg(startPosition);
  for (int i = 0; i < n; i++) {
    if (fields[i].dataType == "INTEGER") {
      long value = 0;
      dataFile.read((char *)&value, 8);
      cout << fields[i].name << ": " << value << endl;
    } else if (fields[i].dataType == "REAL") {
      double value = 0.0;
      dataFile.read((char *)&value, 8);
      cout << fields[i].name << ": " << value << endl;
    } else {
      uint8_t b1;
      uint8_t b2;
      b1 = (uint8_t)dataFile.get();
      b2 = (uint8_t)dataFile.get();
      uint16_t size = b1 * 256 + b2;
      std::cout << "size = " << size << std::endl;
      string text;
      text.reserve(size);
      for (int i = 0; i < size; i++) {
        text.push_back((char)dataFile.get());
      }
      cout << fields[i].name << ": " << text << endl;
    }
  }
}
