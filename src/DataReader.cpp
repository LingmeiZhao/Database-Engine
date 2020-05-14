#include "DataReader.h"

using std::cout;
using std::endl;

DataReader::DataReader() {}

vector<string> DataReader::readOneRow(vector<Field> fields, uint16_t startPosition,
                            std::ifstream &dataFile) {
  int n = fields.size();
  vector<string> result;
  dataFile.seekg(startPosition);
  for (int i = 0; i < n; i++) {
    if (fields[i].dataType == "INTEGER") {
      long value = 0;
      dataFile.read((char *)&value, 8);
      result.push_back(std::to_string(value));
    } else if (fields[i].dataType == "REAL") {
      double value = 0.0;
      dataFile.read((char *)&value, 8);
      result.push_back(std::to_string(value));
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
      result.push_back(text);
    }
  }
  return result;
}
