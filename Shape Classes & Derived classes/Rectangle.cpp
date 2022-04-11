#include <iostream>
#include "shape.h"
#include "rectangle.h"

using namespace std;

    /*
      * Default constructor
    */
Rectangle::Rectangle()
{
  
}

    /*
      * Constructs a rectangle
      @ param w for width
      @ param h for height
      @ param x for x coordinate of the center of the circle
      @ param y for y coordinate of the center of the circle
    */
Rectangle::Rectangle(int w, int h, int x, int y)
{
  width = w;
  height = h;
  centerX = x;
  centerY = y;
}

    /*
      * Sets the x coordinant of the center of the rectangle
      @ param x for centerX
    */
void Rectangle::setCenterX(int x)
{
    centerX = x;
}

    /*
      * Sets the y coordinant of the center of the rectangle
      @ param y for centerY
    */
void Rectangle::setCenterY(int y)
{
    centerY = y;
}

    /*
      * Sets the width of the rectangle
      @ param w for width
    */
void Rectangle::setWidth(int w)
{
    width = w;
}

    /*
      * Sets the height of the rectangle
      @ param h for height
    */
void Rectangle::setHeight(int h)
{
    height = h;
}

    /*
      * Gets x coordinate of the center of the rectangle
    */
int Rectangle::getCenterX()
{
    return centerX;
}

    /*
      * Gets y coordinate of the center of the rectangle
    */
int Rectangle::getCenterY()
{
    return centerY;
}

    /*
      * Gets the width of the rectangle
    */
int Rectangle::getWidth()
{
    return width;
}

    /*
      * Gets the height of the rectangle
    */
int Rectangle::getHeight()
{
    return height;
}
    /*
      * Draws the rectangle
      @ param h for the height of the recangle
      @ param w for the width of the rectangle
    */

void Rectangle::draw(int h, int w)
{
  // i runs for the height of our rectangle
  for(int i = 0;i < h;i++)
  {
    // j runs for the width of our rectangle
    for(int j = 0;j < w;j++)
    {
      // print '*' at the sides of rectangular 2d array table
      if(i == 0 || j == 0 || i == h - 1 || j == w-1)
      {
        cout << "*";
      }
      // and else, print a blank space
      else
      {
        cout << " ";
      }
    }
    cout << "\n";
  }
}

    /*
      * Calculates the area of the rectangle
    */
double Rectangle::calcArea()
{
    return (height*width);
}

    /*
      * destroys the rectangle
    */
Rectangle::~Rectangle()
{
  
}
