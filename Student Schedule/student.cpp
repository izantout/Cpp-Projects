#include "Student.h"
#include "LinkedList.h"
#include "course.h"
#include <string>

using namespace std;

// Default Constructor
Student::Student(){
  
}

// Overloaded Constructer
Student::Student(string mstudentID, string mfirstName, string mlastName, LinkedList<Course>* mmyCourses){
  studentID = mstudentID;
  firstName = mfirstName;
  lastName = mlastName;
  myCourses = mmyCourses;
}

// Destructor
Student::~Student(){
  
}

// Getters
string Student::getID(){
  return studentID;
}

string Student::getFirst(){
  return firstName;
}

string Student::getLast(){
  return lastName;
}

LinkedList<Course>* Student::getSchedule(){
  return myCourses;
}

// Setters
void Student::setID(string mID){
  studentID = mID;
}

void Student::setFirst(string mFirst){
  firstName = mFirst;
}

void Student::setLast(string mLast){
  lastName = mLast;
}

void Student::setSchedule(LinkedList<Course>* mmyCourse){
  cout << "I'm prepping to set the schedule " << endl;
  while(myCourses->head){
    cout << "Inside while1" << endl;
    myCourses->deleteNode((myCourses->head)->value);
  }
  cout << "Between whiles" << endl;
  ListNode<Course>* currentNode = mmyCourse->head; 
  cout << "Directly before while" << endl;
  while(currentNode != nullptr){
    cout << "Inside while 2" << endl;
    //myCourses->insertNode(currentNode->value);
    currentNode = currentNode->next;
  }
}

// Get initial function
string Student::getInitial(){
  return to_string(firstName[0]) + "." + to_string(lastName[0]) + ".";
}

// Get Full Name Function
string Student::getFullName(){
  return lastName + ", " + firstName;
}

// Drop Course
void Student::dropCourse(Course myCourse){
  myCourses->deleteNode(myCourse);
}

// Add Course
void Student::addCourse(Course myCourse){
  myCourses->appendNode(myCourse);
}

void Student::sortCourses(){ 
  LinkedList<Course> sortedCourses;
  ListNode<Course>* currentNode;
  if(myCourses->head){
    currentNode = myCourses->head;
    while(currentNode){
      sortedCourses.insertNode(currentNode->value);
      currentNode = currentNode->next;
    }
  while(myCourses->head){
    myCourses->deleteNode((myCourses->head)->value);
  }
  ListNode<Course>* currentNode = sortedCourses.head; 
  while(currentNode != nullptr){
    myCourses->insertNode(currentNode->value);
    currentNode = currentNode->next;
  }
  }
}

// toString 
string Student::toString(){
  return "ID: " + studentID +"\n" + "First Name: " + firstName +"\n" + "Last Name: " + lastName + "\n" + "Schedule for " + myCourses->head->value.getCSemester() + "\n" + myCourses->toString();
    
}
