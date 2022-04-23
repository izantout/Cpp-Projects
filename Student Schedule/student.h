#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "course.h"

class Student{
  public:
    /*
      * Default Constructor
    */
    Student();

    /*
      * Overloaded Constructer
    */
    Student(std::string mstudentID, std::string mfirstName, std::string mlastName, LinkedList<Course>* mmyCourses);

    /*
      * Destructor
    */
    ~Student();

    /*
      * Gets the student ID number
    */
    std::string getID();

    /*
      * Gets the students first name
    */
    std::string getFirst();

    /*
      * Gets the students last name
    */
    std::string getLast();

    /*
      * Gets the students schedule
    */
    LinkedList<Course>* getSchedule();

    /*
      * Sets the student's ID number to a new one
      @ param string mID for the ID number
    */
    void setID(std::string mID);

    /*
      * Sets the student's first name to a new one
      @ param string mFirst for the first name
    */
    void setFirst(std::string mFirst);

    /*
      * Sets the student's last name to a new one
      @ param string mLast for the last name
    */
    void setLast(std::string mLast);

    /*
      * Sets the student's schedule to a new one
      @ param LinkedList pointer mmyCourse for the new schedule
    */
    void setSchedule(LinkedList<Course>* mmyCourse);

    /*
      * Returns the Initials of the student formatted nicely
    */
    std::string getInitial();

    /*
      * Returns the full name of the student formatted nicely
    */
    std::string getFullName();

    /*
      * Drops a course from the student's schedule
      @ param myCourse for the course thats going to get dropped
    */
    void dropCourse(Course myCourse);

    /*
      * Adds a course to the student's schedule
      @ param myCourse for the course thats going to get added
    */
    void addCourse(Course myCourse);

    /*
      * Sorts the student's courses
    */
    void sortCourses();

    /*
      * returns the schedule of the courses and the student's information nicely
    */ 
    std::string toString();

  private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    LinkedList<Course>* myCourses;
};

#endif
