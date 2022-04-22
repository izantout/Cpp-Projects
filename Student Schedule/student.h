#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "course.h"

class Student{
  public:
    // Default Constructor
    Student();

    // Overloaded Constructer
    Student(std::string mstudentID, std::string mfirstName, std::string mlastName, LinkedList<Course>* mmyCourses);

    // Destructor
    ~Student();

    // Getters
    std::string getID();
    std::string getFirst();
    std::string getLast();
    LinkedList<Course>* getSchedule();

    // Setters
    void setID(std::string mID);
    void setFirst(std::string mFirst);
    void setLast(std::string mLast);
    void setSchedule(LinkedList<Course>* mmyCourse);

    // Get initial function
    std::string getInitial();

    // Get Full Name Function
    std::string getFullName();

    // Drop Course
    void dropCourse(Course myCourse);

    // Add Course
    void addCourse(Course myCourse);

    // Sort Courses
    void sortCourses();

    // toString 
    std::string toString();

  private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    LinkedList<Course>* myCourses;
};

#endif
