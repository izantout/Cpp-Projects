#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// class Circle derived from Shape
class Circle : public Shape
{

// private members of class shape
  private:
    int centerX, centerY, radius;

// public members 
  public:
    // Default constructor
    Circle();
    // Overloaded constructor
    Circle(int x, int y, int r);

    // Setters

    void setCenterX(int x);
    void setCenterY(int y);
    void setRadius(int r);

    // Getters
    int getCenterX();
    int getCenterY();
    int getRadius();

    // Calculate the area of the circle
    double calcArea();

    // Draw the circle
    void draw(int r); 

    // Destructor
    ~Circle();
};

#endif
