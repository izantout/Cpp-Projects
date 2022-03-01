#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream infile;
  ofstream outfile;
  infile.open("input.txt");
  outfile.open("result.txt");
  string temp;
  int n;
  int tempn = 0;
  int finalFrequency = 0;
  string finalString;
  string str, str2;
  while (infile >> n >> str)
  {
  
  string list[(str.length() - (n - 1))];
  for (int i = 0; i < str.length() - (n - 1); i++) {
    str2 = str.substr(i, (i + n) - i);
    list[i] = str2;

    int tempFreq = 0;
    for (int j = 0; j < (str.length() - (n - 1)); j++) {
      if (str2 == list[j])
      {
        tempFreq++;
        if (tempFreq > finalFrequency) 
        {
          finalFrequency = tempFreq;
          finalString = list[i];
        }
      }
    }
  }
  outfile << "The most used word is " << finalString
<< " and this word is used " << finalFrequency << " times" << endl;
    }
  infile.close();
  outfile.close();
  return 0;
}
