int main(){
  vector<int> solution;
  for(int i=0;i<nums.size();i++){
    for(int j=0;j<nums.size();j++){
      if (nums[i]+nums[j] == target&& i!=j){ 
        solution.push_back(i);
        solution.push_back(j);
      }
    }
  }
  if (solution.size()>2){
    solution.resize(2);
  }
  return solution;
}
