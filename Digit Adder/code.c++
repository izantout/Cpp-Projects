#include <iostream>

using namespace std;

// Prototypes

void digitAdd();
void numCheck();

// Function decleration

void digitAdd(int& num) // Function that adds the digits of the number inputed
{
  if (num > 0)
  {
  int cnum = num;
  int total = 0;
  int r = 0;
  while(num > 0)
  {
  r = num % 10;
  total += r;
  num /= 10;
  }
  cout << "The sum of all the digits of " << cnum << " is " << total << "." << endl << endl;
  }
}

void numCheck(int& num)
{
  int cnum = num;
  if (num > 0)
  {
    cout << "You have entered " << cnum << endl;
  }
  else if (num == 0)
  {
    cout << "You have entered 0. Please try again! " << endl << endl;
  }
  else
  {
    cout << "You have entered a negative number. Please try again! " << endl << endl;
  }
}

int main()
{
  int num;
  while(true)
  {
    cout << "Please enter a positive integer: ";
    cin >> num;
    numCheck(num);
    digitAdd(num);
  }
  return 0;
}
