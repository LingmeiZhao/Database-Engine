#ifndef BPLUSCONFIGURATION_H
#define BPLUSCONFIGURATION_H

class BPlusConfiguration{
private:
    int pageSize;
    int keySize;
    int entrySize;
    int treeDegree;
    int headerSize;
    int leafHeaderSize;
    int internalNodeHeaderSize;
    int lookupOverflowPageDegree;
    int lookupOverflowHeaderSize;
    int leafNodeDegree;
    int overflowPageDegree;
    int lookupPageSize;
    int conditionThreshold;
    void basicParams(int pageSize, int keySize, int entrySize);
    void initializeCommon(int pageSize, int keySize, int entrySize, int conditionThreshold);
public:
    BPlusConfiguration();
    BPlusConfiguration(int pageSize);
    BPlusConfiguration(int pageSize, int keySize, int entrySize);
    BPlusConfiguration(int pageSize, int keySize, int entrySize, int conditionThreshold);
    int getMaxInternalNodeCapacity();
    int getMaxLeafNodeCapacity();
    int getMaxOverflowNodeCapacity();
    int getMaxLookupPageOverflowCapacity();
    int getMinLeafNodeCapacity();
    int getMinInternalNodeCapacity();
    int getKeySize();
    int getLeafNodeDegree();
    int getLookupPageDegree();
    int getLookupPageSize();
    int getLoopupPageOffset();
    int getConditionThreshold();
    void setConditionThreshold(int conditionThreshold);
    int getHeaderSize();
    int getPageCountOffset();
}





#endif // BPLUSCONFIFURATION_H