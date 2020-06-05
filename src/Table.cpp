#include "Table.h"

Table::Table(vector<Field> fields, ofstream &dataFile, ofstream &indexFile)
    : fields{fields}, dataFile{dataFile}, indexFile{indexFile}
{
    numOfPage = 0;
}

bool needAddPage(){
    if(pages.size() == 0 || pages.back().isFull() == true){
        return true;
    }else{
        return false;
    }
}

void Table::addPage(Page page){
    if(needAddPage() == true){
        pages.push_back(page);
        numOfPage++;
    }else{
        return;
    }
}