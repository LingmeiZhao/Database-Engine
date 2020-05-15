#include "Table.h"

Table::Table(vector<Field> fields, ofstream &dataFile, ofstream &indexFile)
    : fields{fields}, dataFile{dataFile}, indexFile{indexFile}
{
    numOfPage = 0;
}

void Table::addPage(){
    numOfPage++;
}