class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;
        int final = 0;
        
        while(start<= end){ // start is 1 and end is x=8
             int mid = start + (end - start) / 2; // calculate mid 1 + (8-1)/2 = 4
            if(mid <=  x / mid){ // if the mid is less than or equal to x/mid => 4 <= 8/4 not true
                start = mid + 1; // now start is 3 and we break out of the while loop
                final = mid; // we found the sqrt
            } else{
                end = mid - 1; // end is now 3, after that its 2
            }
        }
        return final;
    }
};
