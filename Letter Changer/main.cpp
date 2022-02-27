#include <iostream>
using namespace std;

int main() 
{
  string s, scopy;
  scopy="";                                                // String s for the original string, scopy for the pushback of the changed string
  int length, i, n,half;                                   // Int length for string length, int i for for loop index, int n for the step number
  bool IsOne;                                              // Bool IsOne that changes if half got to one and keeps or exits loop
  bool extra;
  while(true)                                              // Loop that keeps asking an input from the user
  {
    cout << endl << "Please enter a string: ";
    cin >> s;
    cout << endl << "You entered: " << s << endl << endl;
    length = s.length();                                       // Calculates the length of the string inputed
    half = length/2;                                           // Calculates the half of the length
    IsOne = true;                                              // Set IsOne to true
    n=1;
    extra = false;
    while(IsOne)                                               // While IsOne is true
    {
      if (half == 1 || half == 0)                              // If half reaches one or reaches zer if length = 1
      {
        IsOne = false;                                         // IsOne is false to break out of 2nd loop
      }
      else
      {
        IsOne = true;
        cout << "Part " << n << ": ";                          // Cout part n for display and n changes
        for (i=0; i<(length-half); i++)
        {
          scopy=scopy+s[i];
          //scopy.push_back(s[i]);                             // For loop that prints the 1st half unchanged and adds those string parts to scopy
        }

        for(i=length-1; i>=length-half; i--)
        {
          scopy=scopy+s[i];
          //scopy.push_back(s[i]);                             // For loop that prints the 2nd half changed and adds those string parts to scopy
        }
        
        cout << scopy << endl;                                 // Cout scopy which is the part n
        half = half/2;                                         // Divided half by 2 to make next iteration switch half of half
        if (extra)
        {
          half=1;
          cout << "Part " << n+1 << ": " << scopy << endl; 
        }
        if (half == 3)                                         // Checks if half was 3 and became 1.5 to add one more step
        {
          extra=true;      
        }
        n+=1;                                                  // Increase n after every iteration for display of part n
        s = scopy;                                             // Set s = scopy for next iteration to change new s
        scopy="";                                              // Set scopy to an empty string to pushback to an empty string
      }
    }
  }
  return 0;
} 
