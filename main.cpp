// Liskovskis Ricards 221RDB484

#include "file_helpers.hpp"
#include "geometry.hpp"
#include <iostream>

using namespace std;

int main()
{
  FileReader reader;

  // ----------------------------------------------------------
  // read from .txt file
  // ----------------------------------------------------------
  vector<double> numbers = reader.readTxtFile("points.txt");
  vector<Point> pointsTxt;
  vector<Line> linesTxt;
  vector<Quadrilateral> quadsTxt;

  // write numbers to Point structs
  for (int i = 0; i < numbers.size(); i += 2)
  {
    Point p = Point(numbers[i], numbers[i + 1]);
    pointsTxt.push_back(p);
  }

  // write Points to Line structs
  for (int j = 0; j < pointsTxt.size(); j += 2)
  {
    Line l = Line(pointsTxt[j], pointsTxt[j + 1]);
    linesTxt.push_back(l);
  }

  // write Lines to Quadrilateral structs
  for (int k = 0; k < linesTxt.size(); k += 4)
  {
    Quadrilateral q = Quadrilateral(linesTxt[k], linesTxt[k + 1], linesTxt[k + 2], linesTxt[k + 3]);
    quadsTxt.push_back(q);
  }

  double maxTxtArea = 0.0;
  for (auto quad : quadsTxt)
  {
    // ignore non-square
    if (!quad.isSquare())
    {
      continue;
    }

    double area = quad.getArea();
    if (area > maxTxtArea)
    {
      maxTxtArea = area;
    }
  }

  cout << "Max area from txt file is: " << maxTxtArea << endl;

  // ----------------------------------------------------------
  // read from .csv file (normal)
  // ----------------------------------------------------------
  vector<RowData> rows = reader.readCsvFile("lines.csv");
  vector<Line> linesCsv;
  vector<Quadrilateral> quadsCsv;

  // write numbers to Points and Line structs
  for (int i = 0; i < rows.size(); i++)
  {
    Point p1 = Point(rows[i].col1, rows[i].col2);
    Point p2 = Point(rows[i].col3, rows[i].col4);
    Line l = Line(p1, p2);
    linesCsv.push_back(l);
  }

  // write Lines to Quadrilateral structs
  for (int k = 0; k < linesCsv.size(); k += 4)
  {
    Quadrilateral q = Quadrilateral(linesCsv[k], linesCsv[k + 1], linesCsv[k + 2], linesCsv[k + 3]);
    quadsCsv.push_back(q);
  }

  double maxCsvArea = 0.0;
  for (auto quad : quadsCsv)
  {
    // ignore non-square
    if (!quad.isSquare())
    {
      continue;
    }

    double area = quad.getArea();
    if (area > maxCsvArea)
    {
      maxCsvArea = area;
    }
  }

  cout << "Max area from csv (normal) file is: " << maxCsvArea << endl;

  // ----------------------------------------------------------
  // read from .csv file (dirty)
  // ----------------------------------------------------------
  vector<RowData> rowsDirty = reader.readCsvFile("dirty_lines.csv");
  vector<Line> linesCsvDirty;
  vector<Quadrilateral> quadsCsvDirty;

  // write numbers to Points and Line structs
  for (int i = 0; i < rowsDirty.size(); i++)
  {
    Point p1 = Point(rowsDirty[i].col1, rowsDirty[i].col2);
    Point p2 = Point(rowsDirty[i].col3, rowsDirty[i].col4);
    Line l = Line(p1, p2);
    linesCsvDirty.push_back(l);
  }

  // write Lines to Quadrilateral structs
  for (int k = 0; k < linesCsvDirty.size(); k += 4)
  {
    Quadrilateral q = Quadrilateral(linesCsvDirty[k], linesCsvDirty[k + 1], linesCsvDirty[k + 2], linesCsvDirty[k + 3]);
    quadsCsvDirty.push_back(q);
  }

  double maxCsvDirtyArea = 0.0;
  for (auto quad : quadsCsvDirty)
  {
    // ignore non-square
    if (!quad.isSquare())
    {
      continue;
    }

    double area = quad.getArea();
    if (area > maxCsvDirtyArea)
    {
      maxCsvDirtyArea = area;
    }
  }

  cout << "Max area from csv (dirty) file is: " << maxCsvDirtyArea << endl;

  return 0;
}