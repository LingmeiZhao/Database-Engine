#ifndef TREEINTERNALNODE_H
#define TREEINTERNALNODE_H
#include "TreeNode.h"
#include <iostream>
#include <stdlib.h>
#include <list>

using std::list;


class TreeInternalNode: public TreeNode {
private:
    list<long> pointerArray;
public:
    TreeInternalNode(TreeNodeType nodeType, long pageIndex);
    void removePointerAt(int index);
    long getPointerAt(int index);
    long popPointer();
    long removeLastPointer();
    void addPointerAt(int index, long value);
    void addPointerLast(long value);
    void setPointerAt(int index, long value);
    int getPointerListSize();
    void pushToPointerArray(long value);
};




#endif // TREEINTERNALNODE_H