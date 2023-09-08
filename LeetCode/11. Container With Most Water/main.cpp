class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxArea = 0;

        // have a loop shrinking the box around numbers
        while(left < right){
            // current area is the shortest height and the length
            int currentArea = min(height[left], height[right]) * (right - left);
            // max area is the biggest value between currentArea and the stored max area
            maxArea = max(maxArea, currentArea);
            // check which side is smaller
            if(height[left] < height[right]){
                // if left is smaller remove it and keep right
                left++;
            } else {
                // if right is smaller remove it and keep left
                right--;
            }
        }
        return maxArea;
    }
};
