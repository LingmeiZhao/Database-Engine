#ifndef BPLUSTREE_H
#define BPLUSTREE_H
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;

struct Index {
  int64_t primaryKey; 
  int pointer; 
};

struct Record{
  int64_t primaryKey;
  int pos;
};

struct BPlusTreeNode{
  
}

class BPlusTree{
public:
  BPlusTree();
  void insert();
}





#endif // BPLUSTREE_H