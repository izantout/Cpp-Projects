#include <iostream>
using namespace std;

int main() 
{
  string s;
  int length,i;
  cout << "s = ";                                           // Outputs the message to ask for the user input
  cin >> s;
  length = s.length();
  cout << "Step 1: ";                                       // Outputs Step 1 

  for (i=0; i<=(length-1)/2; i++)                           // For loop to print first unchanged half
  {
    cout << s[i];                                           // Outputs each unchanged ith of the string
  }

  for(i=length-1; i>(length-1)/2; i--)                      // For loop for the change of the 2nd half
  {
    cout << s[i];                                           // Outputs the changed half
  }
  cout << "" << endl;
  cout << "Step 2: ";                                       // Outputs Step 2

  for (i=0; i<=(length-1)/2; i++)                           // For loop to output first unchanged half
  {
    cout << s[i];                                           // Outputs each unchanged ith of the string
  }

  for(i=length-1; i>=length-(length/4); i--)                // For loop to output 1st changed half that didnt change for the 2nd time
  {
    cout << s[i];                                           // Outputs the changed half
  }

  for (i=(length+1)/2; i<length-(length/4); i++)            // For loop to change the last half of the changed half
  {
    cout << s[i];                                           // Outputs the changed half
  }
  return 0;
}     
