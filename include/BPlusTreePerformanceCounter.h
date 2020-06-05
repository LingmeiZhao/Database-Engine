#ifndef BPLUSTREEPERFORMANCECOUNTER_H
#define BPLUSTREEPERFORMANCECOUNTER_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "BPlusTree.h"
#include "DeleteResult.h"
#include "SearchResult.h"
#include "RangeResult.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

class BPlusTreePerformanceCounter{
private:
    int totalNodeReads;
    int totalInternalNodeReads;
    int totalLeafNodeReads;
    int totalOverflowReads;
    int totalNodeWrites;
    int totalInternalNodeWrites;
    int totalLeafNodeWrites;
    int totalOverflowWrites;

    int totalInsertionReads;
    int totalDeletionReads;
    int totalSearchReads;
    int totalRangeQueryReads;
    int totalInsertionWrites;
    int totalDeletionWrites;
    int totalSearchWrites;
    int totalRangeQueryWrites;

    int pageReads;
    int pageWrites;

    int pageInternalReads;
    int pageLeafReads;
    int pageOverflowReads;
    int pageInternalWrites;
    int pageLeafWrites;
    int pageOverflowWrites;

    int totalInsertions;
    int totalDeletions;
    int totalSearches;
    int totalRangeQueries;

    int totalSplits;
    int totalRootSplits;
    int totalInternalNodeSplits;
    int totalLeafSplits;

    int totalPages;
    int totalOverflowPages;
    int totalInternalNodes;
    int totalLeaves;
    
    int totalInternalNodeDeletions;
    int totalLeafNodeDeletions;
    int totalOverflowPagesDeletions;

    int bool trackIO;
    BPlusTree bt;

    void incrementTotalNodeReads();
    void incrementTotalNodeWrites();
    void incrementTotalDeletions();
    void incrementPageReads();
    void incrementPageWrites();
    void setDefaults();
    void resetIntermittentPageTracking();
    int totalOperationCount();
public:
    BPlusTreePerformanceCounter(bool trackIO);
    void setTrackIO(bool trackIO);
    void setBTree(BPlusTree bt);
    void incrementTotalPages();
    void incrementTotalOverflowPages();
    void incrementTotalInternalNodes();
    void incrementTotalLeaves();
    void incrementTotalInsertions();
    void incrementTotalInternalNodeDeletions();
    void incrementTotalLeafNodeDeletions();
    void incrementTotalOverflowPageDeletions();
    void incrementTotalSearches();
    void incrementTotalRangeQueries();
    void incrementTotalSplits();
    void incrementRootSplits();
    void incrementInternalNodeSplits();
    void incrementTotalLeafSplits();
    void startPageTracking();
    int getPageReads();
    int getPageWrites();
    int getInterminentInternalPageReads();
    int getInterminentLeafPageReads();
    int getInterminentOverflowPageReads();
    int getInterminentInternalPageWrites();
    int getInterminentLeafPageWrites();
    int getInterminentOverflowPageWrites();
    vector<int> deleteIO(long key, bool unique, bool verbose);
    vector<int> searchIO(long key, bool unique, bool verbose);
    vector<int> rangeIO(long minKey, long maxKey, bool unique, bool verbose);
    vector<int> insertIO(long key, string value, bool unique, bool verbose);
    int getTotalIntermittentInsertionReads();
    int getTotalIntermittentInsertionWrites();
    void incrementIntermittentInternalNodeReads();
    void incrementIntermittentLeafNodeReads();
    void incrementIntermittentOverflowPageReads();
    void incrementIntermittentInternalNodeWrites();
    void incrementIntermittentLeafNodeWrites();
    void incrementIntermittentOverflowPageWrites();
    void incrementTotalInternalNodeReads();
    void incrementTotalLeafNodeReads();
    void incrementTotalOverflowReads();
    void incrementTotalInternalNodeWrites();
    void incrementTotalLeafNodeWrites();
    void incrementTotalOverflowNodeWrites();
    void printTotalStatistics();
    void resetAllMetrics();
};




#endif // BPLUSTREEPERFORMANCECOUNTER_H