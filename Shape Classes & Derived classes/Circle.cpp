#include <iostream>
#include "circle.h"
#include "shape.h"

using namespace std;
    /*
      * Default Constructor
    */
Circle::Circle()
{
  
}

    /*
      * Constructs a circle
      @ param x for centerX
      @ param y for centerY
      @ param r for radius
    */
Circle::Circle(int x, int y, int r)
{
  centerX = x;
  centerY = y;
  radius = r;
}

    /*
      * Sets the x coordinant of the center of the circle
      @ param x for centerX
    */
void Circle::setCenterX(int x)
{
  centerX = x;  
}

    /*
      * Sets the y coordinant of the center of the circle
      @ param y for centerY
    */
void Circle::setCenterY(int y)
{
  centerY = y;
}

    /*
      * Sets the radius of the circle
      @ param r for radius
    */
void Circle::setRadius(int r)
{
  radius = r;
}

    /*
      * Gets x coordinate of the center of the circle
    */
int Circle::getCenterX()
{
  return centerX;
}

    /*
      * Gets y coordinate of the center of the circle
    */
int Circle::getCenterY()
{
  return centerY;
}

    /*
      * Gets the radius of the circle
    */
int Circle::getRadius()
{
  return radius;
}

    /*
      * Calculates the area of the circle
    */
double Circle::calcArea()
{
  return (3.14 * radius * radius);
}

    /*
      * Draws the circle
      @ param r for the radius of the circle
    */
void Circle::draw(int r)
{       
// a rectangle can be seen as a square of size n * n
int N = 2 * r + 1;
int x, y;  // Coordinates inside the rectangle
// Draw a square of size N*N.
  for (int i = 0; i < N; i++)  //equation to increment our shapes
  {
    for (int j = 0; j < N; j++)
    {
      // Start from the top left of the wanted shape
      x = i - r;
      y = j - r;
      // Checks to see if point is inside of the wanted circle and if it is it prints *
      if (x * x + y * y <= r * r + 1 )
      {
        cout << "**";
      }
      else // If outside the circle it prints space
      {
        cout << " " << " ";
      }
    }
    cout << "\n";
  }
}

    /*
      * Circle destructor
    */
Circle::~Circle()
{
  
}
