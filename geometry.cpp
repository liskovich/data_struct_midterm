#include "geometry.hpp"
#include <cmath>

using namespace std;

double Line::lineLength()
{
  double xDiff = pow(end.getX() - start.getX(), 2);
  double yDiff = pow(end.getY() - start.getY(), 2);
  return sqrt(xDiff + yDiff);
}

bool Quadrilateral::isSquare()
{
  return true;
}

double Quadrilateral::getArea()
{
  return 0.0;
}