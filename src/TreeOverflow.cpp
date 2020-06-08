#include "TreeOverflow.h"


TreeOverflow::TreeOverflow(long nextPagePointer, long prevPagePointer, 
                    long pageIndex): TreeNode(TreeNodeType::TREE_LEAF_OVERFLOW, pageIndex){
                        this->nextPagePointer = nextPagePointer;
                        this->prevPagePointer = prevPagePointer;
}

void TreeOverflow::pushToValueList(string value){
    valueList.push_front(value);
}

string TreeOverflow::removeLastValue(){
    valueList.pop_back();
}

void TreeOverflow::addToValueList(int index, string value){
    std::list<string>::iterator it = valueList.begin();
    std::advance(it, index);
    valueList.insert(it, value);
}

string TreeOverflow::getValueAt(int index){
    std::list<string>::iterator it = valueList.begin();
    std::advance(it, index);
    string value = *it;
    return value;
}

long TreeOverflow::getNextPagePointer(){
    return nextPagePointer;
}

void TreeOverflow::setNextPagePointer(long next){
    this->nextPagePointer = next;
}

long TreeOverflow::getPrevPagePointer(){
    return this->prevPagePointer;
}

void TreeOverflow::setPrevPagePointer(long prev){
    this->prevPagePointer = prev;
}


void TreeOverflow::writeNode(ofstream &r, BPlusConfiguration conf, BPlusTreePerformanceCounter bPerf){
    long index = getPageIndex();
    r.seekp(index);
    int pageType = getPageType();
    r.write((char *) &pageType, sizeof(int));
    r.write((char *) &nextPagePointer, sizeof(long));
    r.write((char *) prevPagePointer, sizeof(long));
    int currentCapacity = getCurrentCapacity();
    r.write((char *) &currentCapacity, sizeof(int));
    
    // now write the values
    std::list<string>::iterator it;
    for(it = valueList.begin(); it != valueList.end(); ++it){
        string value = *it;
        r.write((char *) &value, value.size());
    }

    //annoying correction to do

    bPerf.incrementTotalOverflowNodeWrites();
    
}


void TreeOverflow::printNode(){
    cout << "\nPrinting node of type: " + std::to_string(getNodeType()) + " with index: " + getPageIndex() << endl;
    cout << "Current node capacity is: " + getCurrentCapacity() << endl;
    cout << "Next pointer (index): " + getNextPagePointer();
    cout << "Prev pointer (index): " + getPrevPagePointer << endl;
    cout << "\nPrinting stored values: "<< endl;
    std::list<string>::iterator it = valueList.begin();
    for(int i = 0; i < keyArray.size(); i++){
        cout << " " + *it + " ";
        it++;
    }
    cout << "\n" << endl;
}