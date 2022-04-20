void selectionSort(vector<int>& myVec)
{
  for (int i=0; i < myVec.size(); ++i)
    {
      int min_index = myMin(myVec, i, myVec.size());
      cout << i << " ";
      printVector(myVec);
      mySwap(myVec[min_index], myVec[i]);
    }
}
