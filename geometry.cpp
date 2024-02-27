#include "geometry.hpp"
#include <cmath>

using namespace std;

double Line::lineLength()
{
  // inspired from gemini
  // prompt: Given coordinates (x,y) of 2 points in 2D space, calculate the length of line between them
  double xDiff = pow(end.getX() - start.getX(), 2);
  double yDiff = pow(end.getY() - start.getY(), 2);
  return sqrt(xDiff + yDiff);
}

bool Quadrilateral::isSquare()
{
  // check that previous line's end point is next line's start point
  // and that they form a closed shape
  return (l1.getEnd() == l2.getStart() && l2.getEnd() == l3.getStart() &&
          l3.getEnd() == l4.getStart() && l4.getEnd() == l1.getStart());
}

double Quadrilateral::getArea()
{
  return 0.0;
}