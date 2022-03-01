#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Text file decleration
  ifstream infile;
  ofstream outfile;

  // Text file open
  infile.open("input.txt");
  outfile.open("result.txt");

  // Variable decleration
  string temp;
  int n;
  int tempn = 0;
  int finalFrequency = 0;
  string finalString;
  string str, str2;
  // main while loop that takes inputs from text file
  while (infile >> n >> str) // takes the integer value and gives it to n, and takes the string value and gives it to str
  {
  
  string list[(str.length() - (n - 1))]; // list initialization and size
  for (int i = 0; i < str.length() - (n - 1); i++) {
    str2 = str.substr(i, (i + n) - i);
    list[i] = str2; // making the array full of substrings of length n

    int tempFreq = 0;
    for (int j = 0; j < (str.length() - (n - 1)); j++) { // for loop to count the frequency of each substring 
      if (str2 == list[j])
      { // Searches the array and checks if theres any substring equal to the newest one to output the frequency value of that substring
        tempFreq++;
        if (tempFreq > finalFrequency) 
        { // Checks if that substring's frequency is greater than the max frequency
          finalFrequency = tempFreq; // if the substring's frequency is greater than the max frequency, it replaces the max frequency to that substring's frequency
          finalString = list[i]; // replaces the substring that was previously the most used substring to the newest most used substirng
        }
      }
    }
  }
  outfile << "The most used word is " << finalString
<< " and this word is used " << finalFrequency << " times" << endl; // outfiles in result.txt the most used word and the frequency (how much it was used)
    }
  infile.close(); // close input.txt
  outfile.close(); // close output.txt
  return 0;
}
