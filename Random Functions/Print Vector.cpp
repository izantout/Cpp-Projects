void printVector(vector<string>& myVec)
{
  for(int i=0; i<myVec.size(); i++)
    {
      cout << myVec[i] << " ";
    }
  cout << endl;
}

void printVector(vector<string> myVec)
{
  for(string val : myVec)
    {
      cout << val << " ";
    }
  cout << endl;
}
