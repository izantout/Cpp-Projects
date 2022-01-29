#include <iostream>

using namespace std;

int main() 
{
  int number;
  int total;
  total = 1;
  cout << "n = ";  // Code outputs a statement to ask the user for a number between 0 and 1,000,000
  cin >> number;                                            // Code asks the user for a number input 
  cout << number;
  while (number > 0 and number < 1000000)                   // This loop will keep going until number = 1;
  {
    total += 1;
    if (number == 1) // checks if original number is 1
    {
      cout << " " << endl;
      break;
    }
    else
    {
      if (number % 2 == 0 and number != 0)
      {
        number = number / 2;
        cout << ", " << number;
        if (number == 1) // checks if original number is 1
        {
          cout << " " << endl;;
          break;
        }
      }
      else
      {
        number = (number * 3) + 1;
        cout << ", " << number;
        if (number == 1) // checks if original number is 1
        {
          cout << " " << endl;;
          break;
        }
      } 
    }
  }
  cout <<"There are " << total << " numbers" << endl;
  return 0;
}     
