#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Prototypes
void myVecInit();
void printVector();
void mySwap();
void selectionSort();
void frequencyCount();
void vectorMin();
void vectorMax();
void averageFind();
void maxFrequency();
int myMin();

// Function Decleration
void myVecInit(vector<int>& myVec)
{
  ifstream infile("input.txt"); // Open input text file
  char data = ' '; // data is an empty char
  string temp = ""; // temp is an empty string
  while(infile >> data) // while there are things in the text file
    {
      temp.push_back(data); // pushback everything in text file into data as characters because of the commas
    }

  stringstream ss(temp); // splitstring to use functions to remove the commas

  for (int i; ss >> i;) {
      myVec.push_back(i);  // pushback all integers into myVec  
      if (ss.peek() == ',') // looks ahead to check if there are commas
          ss.ignore(); // ignore commas
  }
  infile.close(); // close the input text file
}

void printVector(const vector<int>& myVec)
{
  cout << "This is myVec: ";
  for(int val : myVec) // for int in myVec
    {
      cout << val << " "; // cout that int
    }
  cout << endl;
}

int myMin(const vector<int>& myVec, int start_idx, int end_idx)
{
  int min_index = start_idx; // minimum is index 0 because we want the smallest int to be in the beginning
  for(int i = start_idx; i <= end_idx; ++i)
    {
      if(myVec[i] < myVec[min_index]) // if the value of myVec[i] is smaller than the min index
      {
        min_index = i; // replace min index with i
      }
    }
  return min_index;
}

void mySwap(int& x, int& y)
{
  int temp = x; // define temp to hold x value
  x = y; // x changes its value to become equal to y 
  y = temp; // give y the value of temp which is x's old value
}

void selectionSort(vector<int>& myVec)
{
  for (int i=0; i < myVec.size(); ++i)
    {
      int min_index = myMin(myVec, i, myVec.size()); // check for the smallest index
      mySwap(myVec[min_index], myVec[i]); // swaps the place of the smallest value to the beginning of the vector
    }
}

void vectorMin(vector<int>& myVec, int& min)
{
  min = myVec[1]; // After sorting the minimum value is in the beginning always
}

void vectorMax(vector<int>& myVec, int& max, int& size)
{
  size = myVec.size(); // The amount of numbers inside the vector is just the size of the vector
  max = myVec[size - 1]; // the maximum number is always the last number in the vector after sorting
}

void averageFind(vector<int>& myVec, double& average)
{
  int size = 0; 
  double sum = 0.0;
  size = myVec.size();
  for (int i=0;i<size;++i)
    {
      sum += myVec[i]; // adding all the numbers that are in the vector
    }
  average = sum/size; // average is equal to all the numbers in the vector divided by the number of numbers
}

int main() 
{
  // Global variable decleration
  vector<int> myVec;
  int size = 0;
  int value = 1;
  double average = 0.0;
  int max = 0;
  int min = 0;
  int maxFrequency;

  // Output text file opening
  ofstream outfile("frequency.txt");
  
  // Function calling
  myVecInit(myVec);
  selectionSort(myVec);
  vectorMax(myVec, max, size);
  vectorMin(myVec, min);
  averageFind(myVec, average);

  for (int i=0;i<myVec.size();i++)
  { // frequency counts how many times a number is in the vector
  // This loop is to find out what is the max frequency of the most used number inside the vector
    int frequency = count(myVec.begin(), myVec.end(), value); // counts the frequency of the number in the sorted vector
    if (frequency > maxFrequency) // if the current frequency is greater than the max frequency
    {
      maxFrequency = frequency; // New maxFrequency is equal to the highest frequency
    }
    value ++; // value is increased
    frequency  = 0; // frequency goes back to 0
  }
  int temp = maxFrequency+2;
  // Outfile code to format text file the way we want
  value = 1; // value is set back to 1
  for (int i=0;i<myVec.size();i++)
    { // frequency counts how many times a number is in the vector
      int frequency = count(myVec.begin(), myVec.end(), value);
      // setw sets the width to alilgn the text in the output text file
      outfile << setw(4) << value << ":" << string(frequency, '*') << setw(temp-frequency) << "(" << frequency << ")" << endl;
      //string,frequency,* is just concatinating the number of stars depending on the frequency of the number
      //setw(50-frequency) to allign the frequency on the right when the number of stars change
      value ++; // value goes to the next number
      frequency = 0; // frequency goes back to 0
    }
  outfile << "There are " << size << " numbers." << endl << "The maximum is " << max << "." << endl << "The minimum is " << min << "." << endl << "The average is "<< fixed << setprecision(2) << average << ".";
  // <fixed << setprecision(2) means we need to have 2 numbers after the decimal points always. if we dont use fixed, if the numbers are 0 they dont add the 2 0s

  outfile.close(); // closing the output text file
  return 0;
}
