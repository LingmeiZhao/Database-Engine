#include "TreeInternalNode.h"


TreeInternalNode::TreeInternalNode(TreeNodeType nodeType, long pageIndex): TreeNode(nodeType, pageIndex){
    
}

void TreeInternalNode::removePointerAt(int index){
    std::list<long>::iterator it = pointerArray.begin();
    std::advance(it, index);
    pointerArray.erase(it);
}

long TreeInternalNode::getPointerAt(int index){
    if(index < 0 || index >= pointerArray.size()){
        return -1;
    }else{
        std::list<long>::iterator it = pointerArray.begin();
        std::advance(it, index);
        long value = *it;
        return it;
    }
}


long TreeInternalNode::popPointer(){
    return pointerArray.pop_front();
}

long TreeInternalNode::removeLastPointer(){
    return pointerArray.pop_back();
}

void TreeInternalNode::addPointerAt(int index, long value){
    std::list<long>::iterator it = pointerArray.begin();
    std::advance(it, index);
    overflowList.insert(it, value);
}

void TreeInternalNode::addPointerLast(long value){
    pointerArray.push_back(value);
}


void TreeInternalNode::setPointerAt(int index, long value){
    std::list<long>::iterator it = pointerArray.begin();
    std::advance(it, index);
    *it = value;
}

int TreeInternalNode::getPointerListSize(){
    return pointerArray.size();
}

void TreeInternalNode::pushToPointerArray(long value){
    pointernArray.push_front(value);
}