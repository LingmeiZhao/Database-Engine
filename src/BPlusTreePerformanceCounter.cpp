#include "BPlusTreePerformanceCounter.h"

BPlusTreePerformanceCounter::BPlusTreePerformanceCounter(bool trackIO){
    this->trackIO = trackIO;
    resetAllMetrics();
}

void BPlusTreePerformanceCounter::setTrackIO(bool trackIO){
    this->trackIO = trackIO;
}

void BPlusTreePerformanceCounter::setBTree(BPlusTree bt){
    this->bt = bt;
}

void BPlusTreePerformanceCounter::incrementTotalPages(){
    if(trackIO == true){
        this->totalPages++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalOverflowPages(){
    if(tackIO == true){
        totalOverflowPages++;
        incrementTotalPages();
    }
}

void BPlusTreePerformanceCounter::incrementTotalInternalNodes(){
    if(trackIO == true){
        totalInternalNodes++;
        incrementTotalPages();
    }
}

void BPlusTreePerformanceCounter::incrementTotalLeaves(){
    if(trackIO == true){
        totalLeaves++;
        incrementTotalPages();
    }
}

void BPlusTreePerformanceCounter::incrementTotalNodeReads(){
    if(trackIO == true){
        totalNodeReads++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalNodeWrites(){
    if(trackIO == true){
        totalNodeWrites++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalInsertions(){
    if(trackIO == true){
        totalInsertions++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalDeletions(){
    if(trackIO == true){
        totalDeletions++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalInternalNodeDeletions(){
    if(trackIO == true){
        totalInternalNodeDeletions++;
        incrementTotalDeletions();
    }
}

void BPlusTreePerformanceCounter::incrementTotalLeafNodeDeletions(){
    if(trackIO == true){
        totalLeafNodeDeletions++;
        incrementTotalDeletions();
    }
}

void BPlusTreePerformanceCounter::incrementTotalOverflowPageDeletions(){
    if(trackIO == true){
        totalOverflowPagesDeletions++;
        incrementTotalDeletions();
    }
}

void BPlusTreePerformanceCounter::incrementTotalSearches(){
    if(trackIO == true){
        totalSearches++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalRangeQueries(){
    if(trackIO == true){
        totalRangeQueries++;
    }
}

void BPlusTreePerformanceCounter::incrementTotalSplits(){
    if(trackIO == true){
        totalSplits++;
    }
}

void BPlusTreePerformanceCounter::incrementRootSplits(){
    if(trackIO == true){
        totalRootSplits++;
        incrementTotalSplits();
    }
}

void BPlusTreePerformanceCounter::incrementInternalNodeSplits(){
    if(trackIO == true){
        totalInternalNodeSplits++;
        incrementTotalSplits();
    }
}

 void BPlusTreePerformanceCounter::incrementTotalLeafSplits(){
     if(trackIO == true){
         totalLeafSplits++;
         incrementTotalSplits();
     }
 }

 void BPlusTreePerformanceCounter::incrementPageReads(){
     if(trackIO == true){
         pageReads++;
     }
 }

 void BPlusTreePerformanceCounter::incrementPageWrites(){
     if(trackIO == true){
         pageWrites++;
     }
 }

 void BPlusTreePerformanceCounter::startPageTracking(){
     setDefaults();
 }


void BPlusTreePerformanceCounter::setDefaults(){
    pageReads = 0;
    pageWrites = 0;
    pageInternalReads = 0;
    pageLeafReads = 0;
    pageOverflowReads = 0;

    pageInternalWrites = 0;
    pageLeafWrites = 0;
    pageOverflowWrites = 0;

}


void BPlusTreePerformanceCounter::resetIntermittentPageTracking(){
    setDefaults();
}

int BPlusTreePerformanceCounter::getPageReads(){
    return pageReads;
}

int BPlusTreePerformanceCounter::getPageWrites(){
    return pageWrites;
}

int BPlusTreePerformanceCounter::getInterminentInternalPageReads(){
    return pageInternalReads;
}

int BPlusTreePerformanceCounter::getInterminentLeafPageReads(){
    return pageLeafReads;
}

int BPlusTreePerformanceCounter::getInterminentOverflowPageReads(){
    return pageOverflowReads;
}

int BPlusTreePerformanceCounter::getInterminentInternalPageWrites(){
    return pageInternalWrites;
}

int BPlusTreePerformanceCounter::getInterminentLeafPageWrites();{
    return pageLeafWrites;
}

int BPlusTreePerformanceCounter::getInterminentOverflowPageWrites(){
    return pageOverflowWrites;
}

vector<int> BPlusTreePerformanceCounter::deleteIO(long key, bool unique, bool verbose){
    startPageTracking();
    DeleteResult r = bt.deleteKey(key, unique);
    if(verbose){
        if(r.isFound()){
            cout << "Key " + key + "has been found" << endl;
            cout << "Number of results returned: " + r.getValues().size();
        }else{
            cout << "Key " + key + "was not found" << endl;
        }

        cout << "Total page reads for this deletion: " + getPageReads()<< endl;
        cout << "Total page writes for this deletion: " + getPageWrites() << endl;
        //to finish

    }
    vector<int> res;
    res.push_back(getPageReads());
    res.push_back(getPageWrites());
    res.push_back(getInterminentInternalPageReads());
    res.push_back(getInterminentInternalPageWrites());
    res.push_back(getInterminentLeafPageReads());
    res.push_back(getInterminentLeafPageWrites());
    res.push_back(getInterminentOverflowPageReads());
    res.push_back(getInterminentOverflowPageWrites());
    if(r.isFound()){
        res.push_back(1);
    }else{
        res.push_back(0);
    }
    totalDeletionReads += pageReads;
    totalDeletionWrites += pageWrites;

    resetIntermittentPageTracking();
    return res;
}

vector<int> BPlusTreePerformanceCounter::searchIO(long key, bool unique, bool verbose){
    startPageTracking();
    SearchResult r = bt.searchKey(key, unique);
    if(verbose){
        if(r.isfound()){
            cout << "Key " + key + " has been found." << endl;
            cout << "Number of results returned: " + r.getValues.size() << endl;
        }else{
            cout << "Key " + key + " was not found." << endl;
        }
        cout << "Total page reads for this search: " + getPageReads() << endl;
        cout << "Total page writes for this search: " + getPageWrites << endl;
        // To finish
    }
    vector<int> res;
    res.push_back(getPageReads());
    res.push_back(getPageWrites());
    res.push_back(getInterminentInternalPageReads());
    res.push_back(getInterminentInternalPageWrites());
    res.push_back(getInterminentLeafPageReads());
    res.push_back(getInterminentLeafPageWrites());
    res.push_back(getInterminentOverflowPageReads());
    res.push_back(getInterminentOverflowPageWrites());
    if(r.isFound()){
        res.push_back(1);
    }else{
        res.push_back(0);
    }
    totalSearchReads += pageReads;
    totalSearchWrites += pageWrites;
    resetIntermittentPageTracking();
    return res;
}

vector<int> BPlusTreePerformanceCounter::rangeIO(long minKey, long maxKey, bool unique, bool verbose){
    startPageTracking();
    RangeResult rangeQRes = bt.rangeSearch(minKey, maxKey, unique);
    if(verbose){
        if(rangeQRes.getQueryResult() != nullptr){
            cout << "Range Query returned: " + rangeQRes.getQueryresult().size() + " results." << endl;
        }else{
            cout << "Range Query returned: " + 0 + " results." << endl;
        }
        cout << "Total page reads for this search: " + getPageReads();
        cout << "Total page writes for this search: " + getPageWrites();
        // To finish
    }
    vector<int> res;
    res.push_back(getPageReads());
    res.push_back(getPageWrites());
    res.push_back(getInterminentInternalPageReads());
    res.push_back(getInterminentInternalPageWrites());
    res.push_back(getInterminentLeafPageReads());
    res.push_back(getInterminentLeafPageWrites());
    res.push_back(getInterminentOverflowPageReads());
    res.push_back(getInterminentOverflowPageWrites());
    totalRangeQueryReads += pageReads;
    totalRangeQueryWrites += pageWrites;

    resetIntermittentPageTracking();
    return res;
}

vector<int> BPlusTreePerformanceCounter::insertIO(long key, string value, bool unique, bool verbose){
    startPageTracking();
    bt.insertKey(key, value, unique);
    if(verbose){
        cout << "Total page reads for this insertion: " + getPageReads() << endl;
        cout << "Total page writes for this insertion: " << getPageWrites() << endl;
        //To finish
    }
    vector<int> res;
    res.push_back(getPageReads());
    res.push_back(getPageWrites());
    res.push_back(getInterminentInternalPageReads());
    res.push_back(getInterminentInternalPageWrites());
    res.push_back(getInterminentLeafPageReads());
    res.push_back(getInterminentLeafPageWrites());
    res.push_back(getInterminentOverflowPageReads());
    res.push_back(getInterminentOverflowPageWrites());

    totalInsertionReads += pageReads;
    totalInsertionWrites += pageReads;

    resetIntermittentPageTracking();
    return res; 
}

int BPlusTreePerformanceCounter::getTotalIntermittentInsertionReads(){
    return totalInsertionReads;
}

int BPlusTreePerformanceCounter::getTotalIntermittentInsertionWrites(){
    return totalInsertionWrites;
}

void BPlusTreePerformanceCounter::incrementIntermittentInternalNodeReads(){
    if(trackIO){
        pageInternalReads++;
        incrementPageReads();
    }
}

void BPlusTreePerformanceCounter::incrementIntermittentLeafNodeReads(){
    if(trackIO){
        pageLeafReads++;
        incrementPageReads();
    }
}

void BPlusTreePerformanceCounter::incrementIntermittentOverflowPageReads(){
    if(trackIO){
        pageOverflowReads++;
        incrementPageReads();
    }
}

void BPlusTreePerformanceCounter::incrementIntermittentInternalNodeWrites(){
    if(trackIO){
        pageInternalWrites++;
        incrementPageWrites();
    }
}

void BPlusTreePerformanceCounter::incrementIntermittentLeafNodeWrites(){
    if(trackIO){
        pageLeafWrites++;
        incrementPageWrites();
    }
}

void BPlusTreePerformanceCounter::incrementIntermittentOverflowPageWrites(){
    if(trackIO){
        pageOverflowWrites++;
        incrementPageWrites();
    }
}

void BPlusTreePerformanceCounter::incrementTotalInternalNodeReads(){
    if(trackIO){
        totalInternalNodeReads++;
        incrementTotalNodeReads();
        incrementIntermittentInternalNodeReads();
    }
}

void BPlusTreePerformanceCounter::incrementTotalLeafNodeReads(){
    if(trackIO){
        totalLeafNodeReads++;
        incrementTotalNodeReads();
        incrementIntermittentLeafNodeReads();
    }
}

void BPlusTreePerformanceCounter::incrementTotalOverflowReads(){
    if(trackIO){
        totalOverflowReads++;
        incrementTotalNodeReads();
        incrementIntermittentOverflowPageReads();
    }
}

void BPlusTreePerformanceCounter::incrementTotalInternalNodeWrites(){
    if(trackIO){
        totalInternalNodeWrites++;
        incrementTotalNodeWrites();
        incrementIntermittentInternalNodeWrites();
    }
}

void BPlusTreePerformanceCounter::incrementTotalLeafNodeWrites(){
    if(trackIO){
        totalLeafNodeWrites++;
        incrementTotalNodeWrites();
        incrementIntermittentLeafNodeReads();
    }
}

void BPlusTreePerformanceCounter::incrementTotalOverflowNodeWrites(){
    if(trackIO){
        totalOverflowWrites++;
        incrementTotalNodeWrites();
        incrementIntermittentOverflowPageWrites();
    }
}

int BPlusTreePerformanceCounter::totalOperationCount(){
    int val = totalInsertions + totalSearches + totalRangeQueries + totalDeletions;
    return val;
}   

void BPlusTreePerformanceCounter::printTotalStatistics(){
    cout << "\n !! Printing total recorded statistics !!" << endl;
    cout << "\n Operations break down" << endl;
    cout << "\n\tTotal insertions: " + totalInsertions << endl;
    cout << "\tTotal searches: " + totalSearches << endl;
    cout << "\tTotal range queries: " + totalRangeQueries << endl;
    cout << "\tTotal performed up count: " + totalOperationCount() << endl;

    cout << "\nTotal I/O break down (this run only)" << endl;
    cout << "\nTotal Read statistics" << endl;
    cout << "\n\tTotal reads: " + totalNodeReads << endl;
    cout << "\tTotal Internal node reads: " + totalInternalNodeReads << endl;
    cout << "\tTotal Leaf node reads: " + totalLeafNodeReads << endl;
    cout << "\tTotal overflow node reads: " + totalOverflowReads << endl;

    cout << "\nTotal write statistics: " << endl;
    cout << "\n\tTotal writes: " + totalNodeWrites << endl;
    cout << "\tTotal Internal node writes: " + totalInternalNodeWrites << endl;
    cout << "\tTotal Leaf node writes: " + totalLeafNodeWrites << endl;
    cout << "\tTotal Overflow node writes: " + totalOverflowWrites << endl;

    cout << "\nPage creation break down." << endl;
    cout << "\n\tTotal pages created: " + totalPages << endl;
    cout << "\tTotal Internal nodes created: " + totalInternalNodes << endl;
    cout << "\tTotal Leaf nodes created: " + totalLeaves << endl;
    cout << "\tTotal Overflow nodes created: " + totalOverflowPages << endl;

    cout << "\nPage deletion break down." << endl;
    cout << "\n\tTotal pages deleted: " + totalDeletions << endl;
    cout << "\tTotal Internal nodes deleted: " + totalInternalNodeDeletions << endl;
    cout << "\tTotal Leaf nodes deleted: " + totalLeafNodeDeletions << endl;
    cout << "\tTotal Overflow pages deleted: " + totalOverflowPagesDeletions << endl;

    cout << "\nPage split statistics." << endl;
    cout << "\n\tTota page splits: " + totalSplits << endl;
    cout << "\tActual Root splits: " + totalRootSplits << endl;
    cout << "\tInternal node splits: " + totalInternalNodeSplits << endl;
    cout << "\tTotal node split: " + totalLeafSplits << endl;
}

void BPlusTreePerformanceCounter::resetAllMetrics(){
    totalPages = 0; 
    totalInternalNodes = 0;
    totalLeaves = 0;
    totalOverflowPages = 0;

    totalNodeReads = 0;
    totalInternalNodeReads = 0;
    totalOverflowReads = 0;
    totalLeafNodeReads = 0; 

    totalNodeWrites =0;
    totalInternalNodeWrites = 0;
    totalLeafNodeWrites = 0;
    totalOverflowWrites = 0;

    totalInternalNodeDeletions = 0;
    totalLeafNodeDeletions = 0;
    totalOverflowPagesDeletions = 0;
    
    totalDeletions = 0;
    totalInsertions = 0;
    totalSearches = 0;
    totalRangeQueries = 0;

    totalSplits = 0;
    totalRootSplits = 0;
    totalInternalNodeSplits = 0;
    totalLeafSplits = 0;

    setDefaults();

    totalSearchReads =0;
    totalSearchWrites = 0;
    totalRangeQueryReads = 0;
    totalRangeQueryWrites = 0;
    totalInsertionReads = 0;
    totalInsertionWrites = 0;
    totalDeletionReads = 0;
    totalDeletionWrites = 0;
}