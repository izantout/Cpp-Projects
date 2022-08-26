class Solution {
public:
    int reverse(int x) { 
        long res = 0;
        while (x != 0) {
            // while x is not 0
            res = 10 * res + x % 10;
            // res = 0*10 + 120%10 = 0 -> 0*10 + 12%10=2 -> 2*10+1%10=21
            x /= 10;
            // 120/10=12 -> 12/10=1 -> 1/10=0
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res; // if res > max for integer, return 0 else if res < minimum integer return res
    }
};
