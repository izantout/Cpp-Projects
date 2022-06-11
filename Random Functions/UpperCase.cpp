string toUpper(string value)
{
  for (int i=0;i<value.length(); i++)
    {
      value[i] = toupper(value[i]);
    }
  return value;
}
