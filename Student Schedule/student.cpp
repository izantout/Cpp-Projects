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
  while(myCourses->head){ //while not empty
    myCourses->deleteNode((myCourses->head)->value); // Delete the nodes of myCourses for us to add different stuff to it
  }
  ListNode<Course>* currentNode = mmyCourse->head; 
  while(currentNode != nullptr){// while nott the end of the linked list
    myCourses->insertNode(currentNode->value);
    currentNode = currentNode->next; //
  }
}

// Get initial function
string Student::getInitial(){
  string finalString = "";
  finalString += firstName[0]; 
  finalString += ".";
  finalString += lastName[0];
  finalString += ".";
  return finalString;
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
