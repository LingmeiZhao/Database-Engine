#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <stdlib.h>
#include <list>
#include <fstream>
#include "BPlusConfiguration.h"
#include "BPlusTreePerformanceCounter.h"

using std::cout;
using std::endl;
using std::list;
using std::ofstream;

enum class TreeNodeType{
    TREE_LEAF,
    TREE_INTERNAL_NODE,
    TREE_ROOT_INTERNAL,
    TREE_ROOT_LEAF,
    TREE_LEAF_OVERFLOW,
    TREE_LOOKUP_OVERFLOW
};

class TreeNode{
private:
    TreeNodeType nodeType;
    long pageIndex;
    int currentCapacity;
    bool beingDeleted;
public:
    list<long> keyArray;
    TreeNode(TreeNodeType nodeType, long pageIndex);
    bool isFull(BPlusConfiguration conf);
    bool isLeaf();
    bool isOverflow();
    bool isEmpty();
    bool isRoot();
    bool isInternalNode();
    bool isLookupPageOverflowNode();
    bool isTimeToMerge(BPlusConfiguration conf);
    int getCurrentCapacity();
    void setCurrentCapacity(int newCap);
    void incrementCapacity(BPlusConfiguration conf);
    void decrementCapacity();
    bool getBeingDeleted();
    void setBeingDeleted(bool beingDeleted);
    TreeNodeType getNodeType();
    void setNodeType(TreeNodeType nodeType);
    long getKeyAt(int index);
    long getPageIndex();
    void setPageIndex(long pageIndex);
    void setKeyArrayAt(int index, long key);
    void addToKeyArrayAt(int index, long key);
    void pushToKeyArray(long key);
    void addLastToKeyArray(long key);
    long getLastKey();
    long getFirstKey();
    long popKey();
    long removeLastKey();
    void removeKeyAt(int index);
    int getPageType();
    virtual void writeNode(ofstream &r, BPlusConfiguration conf, BPlusTreePerformanceCounter bPerf) = 0;
    virtual void printNode() = 0;
};



#endif // TREENODE_H
