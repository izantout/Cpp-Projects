#include <iostream>
#include <string>
#include "course.h"

using namespace std;

// Default Constructor
Course::Course(){
  
}

// Overloaded Constructor
Course::Course(string mCNumber, string mCName, string mCTime, string mCSemester){
  courseNumber = mCNumber;
  courseName = mCName;
  courseTime = mCTime;
  courseSemester = mCSemester;
    
}

// Destructor
Course::~Course(){
  
}

// Getters
string Course::getCNumber(){
  return courseNumber;
}

string Course::getCName(){
  return courseName;
}

string Course::getCTime(){
  return courseTime;
}

string Course::getCSemester(){
  return courseSemester;
}

// Setters
void Course::setCNumber(string mCNumber){
  courseNumber = mCNumber;
}

void Course::setCName(string mCName){
  courseName = mCName;
}

void Course::setCTime(string mdays, string sCTime, string eCTime){
  courseTime = mdays + " " + sCTime + " - " + eCTime;
}

void Course::setCSemester(string mCSemester, string mYear){
  courseSemester = mCSemester + " " + mYear;
}

//ToString Function
string Course::toString(){ // returns the info in a nice format
  return courseSemester + " " + courseNumber + ": " + courseTime + "\n";
}
