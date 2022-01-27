#include <iostream>

using namespace std;

int main() 
{
  int number;
  cout << "Please enter a number between 0 and 1000000: ";  // Code outputs a statement to ask the user for a number between 0 and 1,000,000
  cin >> number;                                            // Code asks the user for a number input 
  cout << number << endl;                                   // Code outputs the number provided by the user

  while (number > 0 and number < 1000000)                   // This loop will keep going until number = 1;
  {
    if (number == 1)                                        // Checks if original number is 1
    {
      cout << "Code ended" << endl;                         // Code outputs Code ended
      break;                                                // If original number is 1, exit the code
    }
    else                                                    // If the original number is not 1
    {
      number = number / 2;                                  // Divide the number by 2
      cout << number << endl;                               // Output the number
      if (number ==1)                                       // Check if the new number is 1
      {
        cout << "Code ended" << endl;                       // Code outputs Code ended
        break;                                              // If the new number is 1, exit the code
      }
      number = (number * 3) + 1;                            // If the new number is not 1, multiply by 3 and add 1
      cout << number << endl;                               // Output the new number
      if (number == 1)                                      // Check if the new number is 1
      {
        cout << "Code ended" << endl;                       // Code outputs Code ended
        break;                                              // If the new number is 1, exit the code
      }
    }
  }
  return 0;
}     
