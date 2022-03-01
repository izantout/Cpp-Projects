#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void concat(const char a[], const char b[],int result_maxlength)
{
  string temp;
  int aLength = strlen(a);
  int bLength = strlen(b);
  for (int i=0; i<aLength; i++)
    {
      temp.push_back(a[i]);
    }
  for (int i=0; i<bLength; i++)
    {
      temp.push_back(b[i]);
    }
  for (int i=0; i<result_maxlength; i++)
    {
      cout << temp[i];
    }
}

int main()
{
  concat("12345", "6789", 8);
  return 0;
}
