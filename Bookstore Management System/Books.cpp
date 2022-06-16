#include "Books.h"
#include <iostream>
#include <string>

using namespace std;

string pageMaker(string mContent);

Books::Books(){
  
}

Books::Books(string mName){
  Name = mName;
}

Books::Books(string mName, string mAuthorName, string mAuthorLast, int mPages, double mPrice, string mContent){
  Name = mName;
  AuthorName = mAuthorName;
  AuthorLast = mAuthorLast;
  Pages = mPages;
  Price = mPrice;
  Content = mContent;
}

Books::~Books(){
  
}

string Books::getName(){
  return Name;
}
string Books::getAuthor(){
  return AuthorName + ", " + AuthorLast;
}

int Books::getPages(){
  return Pages;
}

double Books::getPrice(){
  return Price;
}

string Books::getContent(){
  return Content;
}

void Books::setName(string mname){
  Name = mname;
}

void Books::setAuthor(string mAuthorFirst, string mAutherLast){
  AuthorName = mAuthorFirst;
  AuthorLast = mAutherLast;
}

void Books::setPages(int mpages){
  Pages = mpages;
}

void Books::setPrice(double mprice){
  Price = mprice;
}

void Books::setContent(string mContent){
  Content = pageMaker(mContent);
}

string pageMaker(string mContent){
  string final;
  int spaceCount = 0;
  int pageCount = 1;
  for (char i : mContent){
    final.push_back(i);
    if (i == ' '){
      spaceCount ++;
      final.push_back(i);
    }
    if (spaceCount >= 100){
      final.push_back('\n');
      final.push_back('\n');
      final += "Page ";
      final += to_string(pageCount);
      final.push_back('\n');
      final.push_back('\n');
      pageCount ++;
      spaceCount = 0;
    }
  }
  final.push_back('\n');
  final.push_back('\n');
  final += "Page ";
  final += to_string(pageCount);
  return final;
}
