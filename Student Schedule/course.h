#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course
  {
    public:
    /*
      * Default Constructor
    */
      Course();

    /*
      * Overloaded Constructor
    */
      Course(std::string mCNumber, std::string mCName, std::string mCTime, std::string mCSemester);

    /*
      * Destructor
    */
      ~Course();

    /*
      * Gets the course number
    */
      std::string getCNumber();

    /*
      * gets the course name
    */
      std::string getCName();

    /*
      * gets the course time
    */
      std::string getCTime();

    /*
      * gets the course semester
    */
      std::string getCSemester();

    /*
      * Sets the course number to a new one
      @ param string mCNumber for the new course number
    */
      void setCNumber(std::string mCNumber);

    /*
      * Sets the course name to a new one
      @ param string mCName for the new course name
    */
      void setCName(std::string mCName);

    /*
      * Sets the course time to a new one
      @ param string mdays for the new course days
      @ paramm sCTime for course start time
      @ param eCTime for course end time
    */
      void setCTime(std::string mdays, std::string sCTime, std::string eCTime);

    /*
      * Sets the course semester to a new one
      @ param string mCSemester for the new course semester
      @ param mYear for the new course year
    */
      void setCSemester(std::string mCSemester, std::string mYear);

    /*
      * Returns the course details nicely formatted
    */
      std::string toString();

    private:
      std::string courseNumber;
      std::string courseName;
      std::string courseTime;
      std::string courseSemester;
  };

#endif
