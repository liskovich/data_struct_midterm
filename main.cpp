// Liskovskis Ricards 221RDB484

#include "file_helpers.hpp"
#include "geometry.hpp"
#include <iostream>

using namespace std;

int main()
{
  FileReader reader;

  // read from .txt file
  vector<double> numbers = reader.readTxtFile("points.txt");
  vector<Point> points_txt;
  vector<Line> lines_txt;
  vector<Quadrilateral> quads_txt;
  
  // write numbers to Point structs
  for (int i = 0; i < numbers.size(); i += 2)
  {
    Point p = Point(numbers[i], numbers[i + 1]);
    points_txt.push_back(p);
  }
  cout << "Points amount txt: " << points_txt.size() << endl;

  // write Points to Line structs
  for (int j = 0; j < points_txt.size(); j += 2)
  {
    Line l = Line(points_txt[j], points_txt[j + 1]);
    lines_txt.push_back(l);
  }
  cout << "Lines amount txt: " << lines_txt.size() << endl;

  // write Lines to Quadrilateral structs
  for (int k = 0; k < lines_txt.size(); k += 4)
  {
    Quadrilateral q = Quadrilateral(lines_txt[k], lines_txt[k + 1], lines_txt[k + 2], lines_txt[k + 3]);
    quads_txt.push_back(q);
  }
  cout << "Quads amount txt: " << quads_txt.size() << endl;

  double maxTxtArea = 0.0;
  for (auto quad : quads_txt)
  {
    // ignore non-square
    cout << "is square: " << quad.isSquare() << endl;
    if (!quad.isSquare())
    {
      continue;
    }
    
    double area = quad.getArea();
    cout << "Area is: " << area << endl;

    if (area > maxTxtArea)
    {
      maxTxtArea = area;
    }
  }

  cout << "Max area from txt file is: " << maxTxtArea << endl;

  // vector<RowData> rows = reader.readCsvFile("lines.csv");
  // for (const RowData &row : rows)
  // {
  //   cout << row.col1 << " # " << row.col2 << " # " << row.col3 << " # " << row.col4 << endl;
  // }

  return 0;
}