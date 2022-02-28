  
if (result_maxlength >= strlen(a))
  {
    for (int i=0; i<strlen(a); i++)
      {
        cout << a[i];
      }
  }
  else
  {
    for (int i=0; i < (strlen(a)-result_maxlength);i++)
      {
        cout << a[i];
      }
  }
  if (strlen(a)-result_maxlength > 0)
  {
    for (int i=0; i<strlen(a)-result_maxlength; i++)
      {
        cout << b[i];
      }
  }
  else
  {
   cout << ""; 
  }
  cout << result << endl;
