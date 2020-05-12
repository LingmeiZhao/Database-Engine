#ifndef BPLUSTREE_H
#define BPLUSTREE_H
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

typedef struct BplusTree {
  int *d;
  struct BplusTree **child_ptr;
  bool l;
  int n;
} BplusTree_t;

static BplusTree_t *r = NULL;
static BplusTree_t *np = NULL;
static BplusTree_t *x = NULL;

BplusTree_t *init();
void traverse(BplusTree_t *p);
void sort(int *p, int n);
int split_child(BplusTree_t *x, int i);
void insert(int a);
#endif // BPLUSTREE_H
