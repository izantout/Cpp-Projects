#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

// class Rectangle derived from Shape
class Rectangle: public Shape
{
// private members
  private:
    int width, height, centerX, centerY;
// public members
  public:
    // Default constructor
    Rectangle();

    // Overloaded constructor
    Rectangle(int w, int h, int x, int y);

    // Setters
    void setCenterX(int x);
    void setCenterY(int y);
    void setWidth(int w);
    void setHeight(int h);

    // Getters
    int getCenterX();
    int getCenterY();
    int getWidth();
    int getHeight();

    // Calculate the area
    double calcArea();

    // Draw the rectangle
    void draw(int h, int w);

    // Destructor
    ~Rectangle();  
};

#endif
