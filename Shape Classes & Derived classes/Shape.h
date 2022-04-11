#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape{

//the private members included in the class Shape
  private:
      double area;

//public member functions of problem 2
  public:
    // Getters
    double getArea();

    // Setters
    void setArea(double a);

    // virtual calculate area function
    virtual double calcArea() = 0;

     // Draw function
    void draw();

};

#endif
