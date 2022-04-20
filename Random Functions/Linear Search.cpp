int linSearch(const vector<int>& myVec, int key)
{
  for (int i = 0; i < myVec.size();++i){
    if (myVec[i] == key)
    {
      return i;
    }
  }
  return -1;
}
