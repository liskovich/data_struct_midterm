#ifndef FILE_HELPERS_HPP
#define FILE_HELPERS_HPP

#include <vector>
#include <string>

using namespace std;

struct RowData
{
  double col1;
  double col2;
  double col3;
  double col4;
};

class FileReader
{
public:
  vector<double> readTxtFile(const string &filename);
  vector<RowData> readCsvFile(const string &filename);
};

#endif