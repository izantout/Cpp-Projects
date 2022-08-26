class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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
};

// faster solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        //We will store our values and the indices here.
        unordered_map<int,int> map;        
		
        //We iterate through the loop.
        for(int index = 0; index < nums.size(); index++){
			if(map.find(target-nums[index]) != map.end()){
                //If map contains the value target - nums[index] return the indices of these two values.
                return {index, map[target-nums[index]]};
            }			
            map[nums[index]] = index;
            //If not add nums[index] to map.
        }
        
        //If there is no solution return an empty vector.        
        return {};
    }   
};
