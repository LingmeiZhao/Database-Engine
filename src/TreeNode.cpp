#include "TreeNode.h"

TreeNode::TreeNode(TreeNodeType nodeType, long pageIndex)
:nodeType{nodeType}, pageIndex{0},
currentCapacity{0}, keyArray{}, beingDeleted{true}{

}


bool TreeNode::isFull(BPlusConfiguration conf){
    if(isLeaf()){
        if(isOverflow() == true){
            return conf.getMaxOverflowNodeCapacity() == currentCapacity;
        }else{
            return conf.getMaxLeafNodeCapacity() == currentCapacity;
        }
    }else{
        return conf.getMaxInternalNodeCapacity() == currentCapacity;
    }
}


bool TreeNode::isLeaf(){
        return(nodeType == TreeNodeType::TREE_LEAF ||
                nodeType == TreeNodeType::TREE_LEAF_OVERFLOW ||
                nodeType == TreeNodeType::TREE_ROOT_LEAF);
}

bool TreeNode::isOverflow(){
    if(nodeType == TreeNodeType::TREE_LEAF_OVERFLOW){
        return true;
    }else{
        return false;
    }
}

bool TreeNode::isEmpty(){
    return (currentCapacity == 0);
}

bool TreeNode::isRoot(){
    return (nodeType == TreeNodeType::TREE_ROOT_INTERNAL ||
            nodeType == TreeNodeType::TREE_ROOT_LEAF);
}

bool TreeNode::isInternalNode(){
    return (nodeType == TreeNodeType::TREE_INTERNAL_NODE ||
            nodeType == TreeNodeType::TREE_ROOT_INTERNAL);
}

bool TreeNode::isLookupPageOverflowNode(){
    return (nodeType == TreeNodeType::TREE_LOOKUP_OVERFLOW);
}

bool TreeNode::isTimeToMerge(BPlusConfiguration conf){
    if(isRoot()){
        return (getCurrentCapacity() <= 1);
    }else if(isLeaf()){
        if(isOverflow()){
            return (isEmpty());
        }else{
            return (conf.getMinLeafNodeCapacity() >= currentCapacity)
        }
    }else{
        return (conf.getMinInternalNodeCapacity >= currentCapacity);
    }
}

int TreeNode::getCurrentCapacity(){
    return currentCapacity;
}

void TreeNode::setCurrentCapacity(int newCap){
    this->currentCapacity = newCap;
}

void TreeNode::incrementCapacity(BPlusConfiguration conf){
    currentCapacity++;
    // validateNodeCapacityLimits(conf);
    // Need to figure out how to throw exception.
}


void TreeNode::decrementCapacity(){
    currentCapacity--;
}

bool TreeNode::getBeingDeleted(){
    return beingDeleted;
}

void TreeNode::setBeingDeleted(bool beingDeleted){
    this->beingDeleted = beingDeleted;
}

TreeNodeType TreeNode::getNodeType(){
    return nodeType;
}


void TreeNode::setNodeType(TreeNodeType nodeType){
    if(isLeaf()){
        this->nodeType = nodeType;
        if(isInternalNode()){
            cout << "Can not convert leaf to internal node." << endl;
        }
    }else{
        this->nodeType = nodeType;
        if(isLeaf()){
            cout << "Can not convert internal node to leaf." << endl;
        }
    }
}

long TreeNode::getKeyAt(int index){
    if(keyArray.size() > index){
        std::list<string>::iterator it = keyArray.begin();
        std::advance(it, index);
        long value = *it;
        return value;
    }else{
        cout << "can not find element at this index" << endl;
        return 0;
    }
}

long TreeNode::getPageIndex(){
    return pageIndex;
}

void TreeNode::setPageIndex(long pageIndex){
    this->pageIndex = pageIndex;
}

void TreeNode::setKeyArrayAt(int index, long key){
    // to do 
}

void TreeNode::addToKeyArrayAt(int index, long key){
    std::list<long>::iterator it = keyArray.begin();
    std::advance(it, index);
    keyArray.insert(it, value);
}

void TreeNode::pushToKeyArray(long key){
    this->keyArray.push_front(key);
}

void TreeNode::addLastToKeyArray(long key){
    this->keyArray.push_back(key);
}

long TreeNode::getLastKey(){
    return this->keyArray.back();
}

long TreeNode::getFirstKey(){
    return this->keyArray.front();
}


long TreeNode::popKey(){
    return this->keyArray.pop_front();
}

long TreeNode::removeLastKey(){
    return this->keyArray.pop_back();
}

void TreeNode::removeKeyAt(int index){
    this->keyArray.erase(index) 
}

int TreeNode::getPageType(){
    switch (getNodeType())
    {
    case TREE_LEAF:
        {return 1;}
    case TREE_INTERNAL_NODE:
        {return 2;}
    case TREE_ROOT_INTERNAL:
        {return 3;}
    case TREE_ROOT_LEAF:
        {return 4;}
    case TREE_LEAF_OVERFLOW:
        {return 5;}
    case TREE_LOOKUP_OVERFLOW:
        {return 6;}
    
    default:
        {cout << "Unkown node value read" << endl;}
    }
}