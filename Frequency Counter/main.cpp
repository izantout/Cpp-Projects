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
  ifstream infile("input.txt");
  char data = ' ';
  string temp = "";
  while(infile >> data)
    {
      temp.push_back(data);
    }

  stringstream ss(temp);

  for (int i; ss >> i;) {
      myVec.push_back(i);    
      if (ss.peek() == ',')
          ss.ignore();
  }
}

void printVector(const vector<int>& myVec)
{
  cout << "This is myVec: ";
  for(int val : myVec)
    {
      cout << val << " ";
    }
  cout << endl;
}

int myMin(const vector<int>& myVec, int start_idx, int end_idx)
{
  int min_index = start_idx;
  for(int i = start_idx; i <= end_idx; ++i)
    {
      if(myVec[i] < myVec[min_index])
      {
        min_index = i;
      }
    }
  return min_index;
}

void mySwap(int& x, int& y)
{
  int temp = x;
  x = y;
  y = temp;
}

void selectionSort(vector<int>& myVec)
{
  for (int i=0; i < myVec.size(); ++i)
    {
      int min_index = myMin(myVec, i, myVec.size());
      mySwap(myVec[min_index], myVec[i]);
    }
}

void vectorMin(vector<int>& myVec, int& min)
{
  min = myVec[1];
}

void vectorMax(vector<int>& myVec, int& max, int& size)
{
  size = myVec.size();
  max = myVec[size - 1];
}

void averageFind(vector<int>& myVec, double& average)
{
  int size = 0; 
  double sum = 0.0;
  size = myVec.size();
  for (int i=0;i<size;++i)
    {
      sum += myVec[i];
    }
  average = sum/size;
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
  ofstream outfile("frequency.txt");
  
  // Function calling
  myVecInit(myVec);
  selectionSort(myVec);
  vectorMax(myVec, max, size);
  vectorMin(myVec, min);
  averageFind(myVec, average);

  // Outfile code to format text file the way we want
  for (int i=0;i<myVec.size();i++)
    {
      int frequency = count(myVec.begin(), myVec.end(), value);
      outfile << setw(4) << value << ":" << string(frequency, '*') << setw(50-frequency) << "(" << frequency << ")" << endl;
      value ++;
      frequency = 0;
    }
  outfile << "There are " << size << " numbers." << endl << "The maximum is " << max << "." << endl << "The minimum is " << min << "." << endl << "The average is "<< fixed << setprecision(2) << average << ".";
  return 0;
}
