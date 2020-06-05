#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H
#include <iostream>
#include <stdlib.h>
#include <list>
#include <string>
#include "TreeLeaf.h"

using std::list;
using std::string

class SearchResult {
private:
    int index;
    bool found;
    TreeLeaf leafLoc;
    list<string> ovfValues;
publics:
    SearchResult(TreeLeaf leaf, int index, bool found);
    SearchResult(TreeLeaf leaf, int index, list<string> vals);
    TreeLeaf getLeaf();
    list<string> getValues();
    long getKey();
    bool isFound();
    int getIndex();
};





#endif // SEARCHRESULT_H