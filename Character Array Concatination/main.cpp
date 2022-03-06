#include <iostream>
#include <cstring>

using namespace std;

// Prototypes
void concat();

// Function Initialization
void concat(const char a[], const char b[], char result[], int result_maxlength)
{
  strcpy(result, a); // Copy what is in a to result
  strcat(result, b); // Concatinate what is in b to result
  int resultlength = strlen(a) + strlen(b);
  if(result_maxlength>resultlength)
  {
    result_maxlength = resultlength;
  }
  
  for (int i=0; i<result_maxlength; i++) // for loop that goes from 0 to the number the user wants
    {
      cout << result[i]; // cout the result untill it reaches where the user specified
    }
}



int main()
{
  char a[] = "12345"; // declaring the character array a
  char b[] = "6789"; // declaring the character array b
  int resultlength = strlen(a) + strlen(b); // declaring resultlength to be the length of a and the length of b incase the user wants to output both a and b, result should be that big
  int result_maxlength = 3; // initializing result_maxlength to be whatever we want
  char result[resultlength]; // initializing the array of characters result to be of size (alength + blength)

  // Function calling
  concat(a, b, result, result_maxlength);
  return 0;
}
