#ifndef TREEOVERFLOW_H
#define TREEOVERFLOW_H
#include "TreeNode.h"
#include <iostream>
#include <stdlib.h>
#include <list>
#include <string>

using std::list;
using std::string;
using std::cout;
using std::endl;

class TreeOverflow: public TreeNode {
private:
    list<string> valueList;
    long nextPagePointer;
    long prevPagePointer;

public:
    TreeOverflow(long nextPagePointer, long prevPagePointer, long pageIndex);
    void pushToValueList(string value);
    string removeLastValue();
    void addToValueList(int index, string value);
    string getValueAt(int index);
    long getNextPagePointer();
    void setNextPagePointer(long next);
    long getPrevPagePointer();
    void setPrevPagePointer(long prev);
    void writeNode(ofstream &r, BPlusConfiguration conf, BPlusTreePerformanceCounter bPerf) override;
    void printNode() override;
}






#endif 