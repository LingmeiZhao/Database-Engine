#include "SearchResult.h"


SearchResult::SearchResult(TreeLeaf leaf, int index, bool found){
    this->leafLoc = leaf;
    this->index = index;
    this->found = found;
    ovfValues.push_back(leafLoc.getValueAt(index));
}


SearchResult::SearchResult(TreeLeaf leaf, int index, list<string> vals){
    this->leafLoc = leaf;
    this->index = index;
    this->found = true;
    this->ovfValues = vals;
}

TreeLeaf SearchResult::getLeaf(){
    return this->leafLoc;
}

list<string> SearchResult::getValues(){
    return this->ovfValues;
}

long SearchResult::getKey(){
    return this->leafLoc.getKeyAt(index);
}

bool SearchResult::isFound(){
    return found;
}

int SearchResult:: getIndex(){
    return index;
}