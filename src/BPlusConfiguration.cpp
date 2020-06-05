#include "BPlusConfiguration.h"

BPlusConfiguration::BPlusConfiguration(){
    basicParams(1024, 8, 20);
    initializeCommon(pageSize, keySize, entrySize, 1000);
}

BPlusConfiguration::BPlusConfiguration(int pageSize){
    basicParams(pageSize, 8, 20);
    initializeCommon(pageSize, keySize, entrySize, 1000);
}

BPlusConfiguration::BPlusConfiguration(int pageSize, int keySize, int entrySize){
    basicParams(pageSize, keySize, entrySize);
    initializeCommon(pageSize, keySize, entrySize, 1000);
}

BPlusConfiguration::BPlusConfiguration(int pageSize, int keySize, int entrySize, int conditionThreshold){
    basicParams(pageSize, keySize, entrySize);
    initializeCommon(pageSize, keySize, entrySize, conditionThreshold);
}



void BPlusConfiguration::basicParams(int pageSize, int keySize, int entrySize){
    this->pageSize = pageSize;
    this->keySize = keySize;
    this->entrySize = entrySize;
}

void BPlusConfiguration::initializeCommon(int pageSize, int keySize, int entrySize, int conditionThreshold){
    this->headerSize = (sizeof(int) * 4 + 4 * sizeof(long)) / 8;
    this->internalNodeHeaderSize = 0;
    // to understand
}

int BPlusConfiguration::getMaxInternalNodeCapacity(){
    int capacity = 2 * treeDegree - 1;
    return capacity;
}

int BPlusConfiguration::getMaxLeafNodeCapacity(){
    int capacity = 2 * leafNodeDegree - 1;
    return capacity;
}

int BPlusConfiguration::getMaxOverflowNodeCapacity(){
    int capacity = 2 * overflowPageDegree - 1;
    return capacity;
}

int BPlusConfiguration::getMaxLookupPageOverflowCapacity(){
    int capacity = 2 * lookupOverflowPageDegree - 1;
    return capacity;
}

int BPlusConfiguration::getMinLeafNodeCapacity(){
    return (leafNodeDegree - 1);
}

int BPlusConfiguration::getMinInternalNodeCapacity(){
    return (treeDegree - 1);
}

int BPlusConfiguration::getKeySize(){
    return keySize;
}

int BPlusConfiguration::getLeafNodeDegree(){
    return leafNodeDegree;
}

int BPlusConfiguration::getLookupPageDegree(){
    int degree = pageSize / keySize;
    return degree;
}

int BPlusConfiguration::getLookupPageSize(){
    return lookupPageSize;
}

int BPlusConfiguration::getLoopupPageOffset(){
    int offset = pageSize - lookupPageSize;
    return offset;
}

int BPlusConfiguration::getConditionThreshold(){
    return conditionThreshold;
}

void BPlusConfiguration::setConditionThreshold(int conditionThreshold){
    this->conditionThreshold = conditionThreshold;
}

int BPlusConfiguration::getHeaderSize(){
    return headerSize;
}


int BPlusConfiguration::getPageCountOffset(){
    return (headerSize - 16);
}