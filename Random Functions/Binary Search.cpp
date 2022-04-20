int binSearch(const vector<int>& myVec, int i, int& j, int key)
{
  int mid = (i + j) / 2;
  if (myVec[mid] == key)
  {
    return mid;
  }
  else if(key < myVec[mid])
  {
    j = mid - 1;
  }
  else
  {
    i = mid + 1;
  }
  return mid;
}
