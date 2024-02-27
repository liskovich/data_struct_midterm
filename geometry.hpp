#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cmath>

using namespace std;

struct Point
{
private:
  double x;
  double y;

public:
  Point(double x_p, double y_p) : x(x_p), y(y_p) {}

  double getX()
  {
    return x;
  }
  double getY()
  {
    return y;
  }

  // to be able to compatre two points
  bool operator==(const Point &other) const
  {
    // Check if both x and y coordinates are equal within a small tolerance
    return abs(x - other.x) < 1e-6 && abs(y - other.y) < 1e-6;
  }
};

struct Line
{
private:
  Point start;
  Point end;

public:
  Line(Point start_p, Point end_p) : start(start_p), end(end_p) {}

  double lineLength();

  Point getStart()
  {
    return start;
  }
  Point getEnd()
  {
    return end;
  }
};

struct Quadrilateral
{
private:
  Line l1;
  Line l2;
  Line l3;
  Line l4;

public:
  Quadrilateral(Line l1_p, Line l2_p, Line l3_p, Line l4_p) : l1(l1_p), l2(l2_p), l3(l3_p), l4(l4_p) {}

  bool isSquare();
  double getArea();

  Line getLine1()
  {
    return l1;
  }
  Line getLine2()
  {
    return l2;
  }
  Line getLine3()
  {
    return l3;
  }
  Line getLine4()
  {
    return l4;
  }
};

#endif