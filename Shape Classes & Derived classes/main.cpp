/*
 * This C++ program will program the console to output a circle and a rectangle with their appropriate dimentions
 * CECS 275 - Spring 2022
 * @author Ryan Kaia
 * @author Issam Zantout
 */

#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

using namespace std;

int main()
{
  
  // we must create circle class object and pass values to it's constructor in             order to get the function needed
  Circle c(1,3,4);
  //use get function to print radius of our wanted circle
  cout << "Radius of circle : " << c.getRadius() << endl;
  
  // print area of circle
  cout << "Area of circle : " << c.calcArea() << endl;
  
  // draw circle of given radius
  c.draw(c.getRadius());
        
  // make wanted rectangle
  Rectangle r(3,11,7,0);
  
  // print height and weight of rectangle uusing get 
  cout << "\nHeight of rectangle : " << r.getHeight() << endl;
  cout << "Width of rectangle : " << r.getWidth() << endl;
  
  // print area of rectangle
  cout << "Area of rectangle : " << r.calcArea() << endl;
  
  // print using 2d array
  r.draw(r.getHeight(),r.getWidth());     
  
  return 0;
} 
