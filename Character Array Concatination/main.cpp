#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void concat(const char a[], const char b[], char result[], int result_maxlength)
{
  strcpy(result, a);
  strcat(result, b);
  for (int i=0; i<result_maxlength; i++)
    {
      cout << result[i];
    }
}



int main()
{
  char a[10] = "12345";
  char b[10] = "6789";
  int resultlength = strlen(a) + strlen(b);
  int result_maxlength = 5;
  char result[resultlength];
  
  concat(a, b, result, result_maxlength);
  return 0;
}
