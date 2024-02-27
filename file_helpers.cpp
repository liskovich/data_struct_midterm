#include "file_helpers.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// counts commas in a line of a .csv file
int countCommas(string line)
{
  int count = 0;
  for (int i = 0; i < line.size(); i++)
  {
    if (line[i] == ',')
    {
      count++;
    }
  }
  return count;
}

vector<double> FileReader::readTxtFile(const string &filename)
{
  ifstream file(filename);
  vector<double> numbers;
  string line;

  if (file.is_open())
  {
    // read each line from .txt file
    while (getline(file, line))
    {
      numbers.push_back(stod(line));
    }
    file.close();
  }
  else
  {
    cerr << "Error: Could not open file " << filename << endl;
  }
  return numbers;
}

vector<RowData> FileReader::readCsvFile(const string &filename)
{
  ifstream file(filename);
  vector<RowData> rows;
  string line;

  if (file.is_open())
  {
    // read each line from .csv file
    while (getline(file, line))
    {
      // skip lines without exactly 4 columns
      if (countCommas(line) != 3)
      {
        continue;
      }

      string valueStr;
      vector<double> row;
      RowData row_data;

      stringstream ss(line);

      // iterate through chars in a line and check if it is not a comma
      // inspired from: https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/
      while (ss.good())
      {
        getline(ss, valueStr, ',');
        double num;
        try
        {
          num = stod(valueStr);
        }
        catch (const exception &e)
        {
          // if conversion failed, go to next line
          break;
        }
        row.push_back(num);
      }

      // write to row representation struct
      if (row.size() == 4)
      {
        row_data.col1 = row[0];
        row_data.col2 = row[1];
        row_data.col3 = row[2];
        row_data.col4 = row[3];

        rows.push_back(row_data);
      }
      else
      {
        continue;
      }
    }
    file.close();
  }
  else
  {
    cerr << "Error: Could not open file " << filename << endl;
  }

  return rows;
}
