#include <iostream>

using namespace std;

// Prototypes
void reverseFunction();

// Function decleration
void reverseFunction(char s[])
{
  int charLength = strlen(s);  // Getting the length of the character array
    while(charLength >= 0) // while the length is greater or equal to 0 meaning it will keep decreasing to output the characters in reverse
    {
      cout << s[charLength]; // cout the character starting from position char.length()
      --charLength; // decrease char length by 1
    } // Outputs from the end of the character array to the beginning of the character array making the output the reverse of whatever was inputed.
}

int main()
{
  reverseFunction("Hello");
  return 0;
}
