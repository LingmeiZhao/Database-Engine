#include "TreeLeaf.h"

TreeLeaf::TreeLeaf(long nextPagePointer, long prevPagePointer, 
TreeNodeType nodeType, long pageIndex): TreeNode(nodeType, pageIndex){
    if(nodeType == TreeNodeType::TREE_ROOT_LEAF && nextPagePointer > 0){
        cout << "can not have leaf root with non-null next pointer." << endl;
        return;
    }
    this->nextPagePointer = nextPagePointer;
    this->prevPagePointer = prevPagePointer;
}


void TreeLeaf::addToOverflowList(int index, long value){
    std::list<long>::iterator it = overflowList.begin();
    std::advance(it, index);
    overflowList.insert(it, value);
}


void TreeLeaf::addLastToOverflowList(long value){
    overflowList.push_back(value);
}

void TreeLeaf::addLastToValueList(string value){
    valueList.push_back(value);
}

long TreeLeaf::getOverflowPointerAt(int index){
    if(overflowList.size() > index){
        std::list<long>::iterator it = overflowList.begin();
        std::advance(it, index);
        long value = *it;
        return value;
    }else{
        cout << "can not find element at this index" << endl;
        return 0;
    }
}

void TreeLeaf::pushToOverflowList(long overflowPointer){
    overflowList.push_front(overflowPointer);
}

void TreeLeaf::popOverflowPointer(){
    return overflowList.pop_front();
}

void TreeLeaf::setoverflowPointerAt(int index, long value){
    // to do
}

long TreeLeaf::removeLastOverflowPointer(){
    return overflowList.pop_front();
}

long TreeLeaf::getLastOverflowPoint(){
    return overflowList.front();
}

string TreeLeaf::getValueAt(int index){
     if(valueList.size() > index){
        std::list<string>::iterator it = valueList.begin();
        std::advance(it, index);
        string value = *it;
        return value;
    }else{
        cout << "can not find element at this index" << endl;
        return "";
    }
}

void TreeLeaf::pushToValueList(string value){
    valueList.push_front(value);
}

string TreeLeaf::popValue(){
    return valueList.pop_front();
}

string TreeLeaf::removeLastValue(){
    return valueList.pop_back();
}   

long TreeLeaf::getNextPagePointer(){
    return nextPagePointer;
}

void TreeLeaf::setNextPagePointer(long next){
    nextPagePointer = next;
}

long TreeLeaf::getPrevPagePointer(){
    return prevPagePointer;
}

void TreeLeaf::setPrevPagePointer(long prev){
    prevPagePointer = prev;
}

string TreeLeaf::removeEntryAt(int index, BPlusConfiguration conf){
    // to do
}