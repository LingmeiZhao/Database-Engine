#ifndef TREELEAF_H
#define TREELEAF_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::list;
using std::string;


class TreeLeaf: public TreeNode{
private:
    long nextPagePointer;
    long prevPagePointer;
    list<string> valueList;
    list<long> overflowList;
public:
    TreeLeaf(long nextPagePointer, long prevPagePointer, TreeNodeType nodeType, long pageIndex);
    void addToOverflowList(int index, long value);
    void addLastToOverflowList(long value);
    void addLastToValueList(string value);
    long getOverflowPointerAt(int index);
    void pushToOverflowList(long overflowPointer);
    void popOverflowPointer();
    void setoverflowPointerAt(int index, long value);
    long removeLastOverflowPointer();
    long getLastOverflowPoint();
    string getValueAt(int index);
    void pushToValueList(string value);
    string popValue();
    string removeLastValue();
    long getNextPagePointer();
    void setNextPagePointer(long next);
    long getPrevPagePointer();
    void setPrevPagePointer(long prev);
    string removeEntryAt(int index, BPlusConfiguration conf);
    void writeNode(ofstream &r, BPlusConfiguration conf, BPlusTreePerformanceCounter bPerf) override;
    void printNode() override; 
};


#endif // TREELEAF_H