#include "geometry.hpp"
#include <cmath>

using namespace std;

// dot product: https://medium.com/intuitionmath/why-is-the-inner-product-of-orthogonal-vectors-zero-88469043decf
double dotProduct(Point &v1, Point &v2)
{
  return (v1.getX() * v2.getX()) + (v1.getY() * v2.getY());
}

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
  bool formsClosedShape = (l1.getEnd() == l2.getStart() && l2.getEnd() == l3.getStart() &&
                           l3.getEnd() == l4.getStart() && l4.getEnd() == l1.getStart());

  // check that adjacent lines are equal
  bool adjacentLinesEqualLength = abs(l1.lineLength() - l2.lineLength()) < 1e-6;

  // and perpendicular (can be found using dot product, which must be 0)
  // get direction vectors of both lines - acutally we had it in Linear Algebra yesterday :)
  Point direction1 = {l1.getEnd().getX() - l1.getStart().getX(), l1.getEnd().getY() - l1.getStart().getY()};
  Point direction2 = {l2.getEnd().getX() - l2.getStart().getX(), l2.getEnd().getY() - l2.getStart().getY()};
  bool adjacentLinesPerpendicular = abs(dotProduct(direction1, direction2)) < 1e-6;

  // meets all criteria
  return formsClosedShape && adjacentLinesEqualLength && adjacentLinesPerpendicular;
}

double Quadrilateral::getArea()
{
  return 0.0;
}