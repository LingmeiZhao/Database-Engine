#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include "Page.h"
#include "PageReader.h"
using namespace std;

using ByteArray = std::vector<char>;

void creatTable(std::vector<Field> fields, string tableName)
{
  ofstream wf(tableName, ios::out | ios ::binary);
  if (!wf)
  {
    cout << "Can not open table name file" << endl;
    return;
  }
  int n = fields.size();
  for (int i = 0; i < n; i++)
  {
    wf.write((char *)&fields[i], sizeof(Field));
  }
  if (!wf.good())
  {
    cout << "Something error happens when writing file" << endl;
  }
  wf.close();
}

void writeOneRow(std::vector<Field> fields, std::vector<std::string> row,
                 std::ofstream &dataFile, std::ofstream &indexFile)
{
  int n = row.size();
  uint64_t address = dataFile.tellp();
  for (int i = 0; i < n; i++)
  {
    bool isKey = false;
    if (fields[i].isPrimaryKey == true)
    {
      isKey = true;
    }
    if (fields[i].dataType == "INTEGER")
    {
      int64_t value = stol(row[i]);
      dataFile.write((char *)&value, 8);
    }
    else if (fields[i].dataType == "REAL")
    {
      double_t value = stod(row[i]);
      dataFile.write((char *)&value, 8);
    }
    else
    {
      int size = row[i].size();
      dataFile.put((char)(size / 256));
      dataFile.put((char)(size % 256));
      for (char c : row[i])
      {
        dataFile.put(c);
      }
    }
    if (isKey == true)
    {
      if (fields[i].dataType == "INTEGER")
      {
        int64_t value = stol(row[i]);
        indexFile.write((char *)&value, 8);
      }
      else if (fields[i].dataType == "TEXT")
      {
        int size = row[i].size();
        indexFile.put((char)(size / 256));
        indexFile.put((char)(size % 256));
        for (char c : row[i])
        {
          indexFile.put(c);
        }
      }
      indexFile.write((char *)&address, sizeof(uint64_t));
    }
  }
  if (!dataFile.good())
  {
    cout << "Error happens when writing data file!" << endl;
    return;
  }
  if (!indexFile.good())
  {
    cout << "Error happens when writing index file!" << endl;
    return;
  }
}

void readOneDataRow(std::vector<Field> fields, std ::ifstream &dataFile)
{
  int n = fields.size();
  for (int i = 0; i < n; i++)
  {
    if (fields[i].dataType == "INTEGER")
    {
      long value = 0;
      dataFile.read((char *)&value, 8);
      cout << fields[i].name << ": " << value << endl;
    }
    else if (fields[i].dataType == "REAL")
    {
      double value = 0.0;
      dataFile.read((char *)&value, 8);
      cout << fields[i].name << ": " << value << endl;
    }
    else
    {
      uint8_t b1;
      uint8_t b2;
      b1 = (uint8_t)dataFile.get();
      b2 = (uint8_t)dataFile.get();
      uint16_t size = b1 * 256 + b2;
      std::cout << "size = " << size << std::endl;
      string text;
      text.reserve(size);
      for (int i = 0; i < size; i++)
      {
        text.push_back((char)dataFile.get());
      }
      cout << fields[i].name << ": " << text << endl;
    }
  }
}

struct Student
{
  int ID : 4;
  char name[8];
};

void readFile()
{
  ifstream rf("student.dat", ios::out | ios::binary);
  rf.seekg(100);
  if (!rf)
  {
    cout << "Can not open file!" << endl;
    return;
  }
  Student rstu[3];
  for (int i = 0; i < 3; i++)
  {
    rf.read((char *)&rstu[i], sizeof(Student));
  }
  rf.close();
  if (!rf.good())
  {
    cout << "Error occurred at reading time!" << endl;
    return;
  }
  cout << "Students' Details" << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << "ID: " << rstu[i].ID << endl;
    cout << "Name: " << rstu[i].name << endl;
    cout << endl;
  }
}

void testWriteOneRow()
{
  ofstream dataFile("data.dat", ios::out | ios::binary);
  ofstream indexFile("index.dat", ios::out | ios::binary);
  std::vector<Field> fields = {{"ID", "INTEGER", true},
                               {"Name", "TEXT", false}};
  std::vector<std::string> row = {"98", "Nancy"};
  writeOneRow(fields, row, dataFile, indexFile);
  row = {"72", "Jack"};
  writeOneRow(fields, row, dataFile, indexFile);
  row = {"1282", "Julia"};
  writeOneRow(fields, row, dataFile, indexFile);
  dataFile.close();
  indexFile.close();
}

void testReadOneRow()
{
  ifstream dataFile("data.dat", ios::in | ios::binary);
  std::vector<Field> fields = {{"ID", "INTEGER", true},
                               {"Name", "TEXT", false}};

  readOneDataRow(fields, dataFile);
  readOneDataRow(fields, dataFile);
  readOneDataRow(fields, dataFile);
}

void getRow(std::vector<Field> fields, int pkIndex, std::string pkValue) {}

int main()
{

  ofstream dataFile("dataTest.dat", ios::out | ios::binary);
  vector<Header> headers = {};
  int32_t pageNumber = 0;
  uint16_t numOfEntry = 0;
  uint16_t endOfFreeSpace = 65535;
  Page page(dataFile, pageNumber, headers, numOfEntry, endOfFreeSpace);
  std::vector<Field> fields = {{"ID", "INTEGER", true},
                               {"Name", "TEXT", false}};
  std::vector<std::string> row = {"98", "Nancy"};
  ofstream indexFile("indexTest.dat", ios::out | ios::binary);
  page.WriteOneRowAt(fields, row, indexFile);
  cout << "End of free space: " << page.GetEndOfFreeSpace() << endl;
  cout << "Number of entry: " << page.GetNumberOfEntries() << endl;
  row = {"1282", "John"};
  page.WriteOneRowAt(fields, row, indexFile);
  cout << "End of free space: " << page.GetEndOfFreeSpace() << endl;
  cout << "Number of entry: " << page.GetNumberOfEntries() << endl;
  row = {"100", "Julia"};
  page.WriteOneRowAt(fields, row, indexFile);
  cout << "End of free space: " << page.GetEndOfFreeSpace() << endl;
  cout << "Number of entry: " << page.GetNumberOfEntries() << endl;
  dataFile.close();
  ifstream readFile("dataTest.dat", ios::in | ios::binary);
  PageReader pageReader(readFile);
  headers = pageReader.readHeaders(pageNumber, 65535);
  int n = headers.size();
  cout << "Read number of entry: " << pageReader.readNumOfEntry(pageNumber, 65535) << endl;
  cout << "Read end of free space: " << pageReader.readEndOfFreeSpace(pageNumber, 65535) << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Location: " << headers[i].location << "  "
         << "Size: " << headers[i].size << endl;
  }
  Header header = {65491, 15};
  vector<string> result = pageReader.readRow(header, fields);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " " << endl;
  }
  readFile.close();
  return 0;
}
