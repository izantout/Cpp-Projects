#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

class Course
  {
    public:
      // Default Constructor
      Course();

      // Overloaded Constructor
      Course(std::string mCNumber, std::string mCName, std::string mCTime, std::string mCSemester);

      // Destructor
      ~Course();

      // Getters
      std::string getCNumber();
      std::string getCName();
      std::string getCTime();
      std::string getCSemester();

      // Setters
      void setCNumber(std::string mCNumber);
      void setCName(std::string mCName);
      void setCTime(std::string mdays, std::string sCTime, std::string eCTime);
      void setCSemester(std::string mCSemester, std::string mYear);

      //ToString Function
      std::string toString();

    private:
      std::string courseNumber;
      std::string courseName;
      std::string courseTime;
      std::string courseSemester;
  };

#endif
