aLength = strlen(a);
bLength = strlen(b);
aSmallerLength = aLength-result_maxlength;
if (result_maxlength >= aLength)
  {
    for (int i=0; i<aLength; i++)
      {
        cout << a[i];
      }
  }
  else if (result_maxlength < aLength)
  {
    for (int i=0; i < (aSmallerLength);i++)
      {
        cout << a[i];
      }
  }

  if (aSmallerLength > 0)
  {
    for (int i=0; i<aLengt-result_maxlength; i++)
      {
        cout << b[i];
      }
  }
  else if (aSmallerLength <= 0)
  {
   cout << ""; 
  }
