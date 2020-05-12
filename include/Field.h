#ifndef FIELD_H
#define FIELD_H
#include <string>

struct Field {
  std::string name;
  std::string dataType;
  bool isPrimaryKey;
};

#endif // FIELD_H
