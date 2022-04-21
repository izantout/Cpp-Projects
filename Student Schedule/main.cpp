#include <iostream>
#include "course.h"
#include "LinkedList.h"
#include "Student.h"

using namespace std;

int main() 
  {
    LinkedList<Course>* sortedCourses;
    Course myCourse("CECS 275", "Programming and Data Structure", "MW 5:30 PM - 7:45 PM", "Spring 2022");
    Course myCourse2("CECS 301", "Logic Design II", "TH 2:00 PM - 2:50 PM", "Spring 2022");
    LinkedList<Course> myCourses;
    Student Issam("027941626", "Issam", "Zantout", &myCourses);
    Issam.addCourse(myCourse);
    Issam.addCourse(myCourse2);
    cout << Issam.toString() << endl;
    Issam.dropCourse(myCourse);    
    cout << Issam.toString() << endl;
    Issam.addCourse(myCourse);
    cout << Issam.toString() << endl;
    Issam.sortCourses(sortedCourses);
    Issam.setSchedule(sortedCourses);
    cout << Issam.toString() << endl;
  }
