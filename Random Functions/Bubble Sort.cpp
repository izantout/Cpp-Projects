void bubbleSort(vector<int>& myVec)
{
  for(int i = 0;i < myVec.size();++i)
    {
      for(int j = 0; j < myVec.size();++j)
        {
          if (myVec[i]<myVec[j])
          {
            mySwap(myVec[i], myVec[j]);
          }
        }
    }
}
