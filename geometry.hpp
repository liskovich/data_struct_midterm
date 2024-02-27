#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

struct Point
{
private:
  double x;
  double y;

public:
  Point(double x_p, double y_p) : x(x_p), y(y_p) {}
};

struct Line
{
private:
  Point start;
  Point end;

public:
  Line(Point start_p, Point end_p) : start(start_p), end(end_p) {}

  double lineLength();
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
};


#endif