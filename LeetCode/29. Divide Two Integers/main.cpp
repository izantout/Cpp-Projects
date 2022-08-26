class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN and divisor == -1) return INT_MAX;
        if (dividend == INT_MIN and divisor == 1) return INT_MIN;
        
        bool isNegative = (dividend < 0) ^ (divisor < 0); // if both are - or both are + its false else its true
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        
        int quotient = 0;
        // while(dividend <= divisor){ // this methode takes O(N)
        //     dividend -= divisor;
        //     quotient ++;
        // }
        
        // while(dividend <= divisor){ // this methode takes O((logN)^2)
        //     int i=1, accum=divisor;
        //     while(accum>INT_MIN>>1 and dividend <= accum+accum) { // comparing accum with the half of minimum integer for no overflow
        //         i += i;
        //         accum += accum;
        //     }
        //     dividend -= accum;
        //     quotient += i;
        // }
        int i=1, accum = divisor;
        while(accum >= INT_MIN >> 1 and dividend <= accum + accum){ // this meathode takes Olog(N)
            i <<= 1; // adding i but in another way
            accum += accum;
        }
        while(dividend <= divisor){// subtraction
            if(dividend <= accum){ // check if the accum is still larger than  the dividend
                dividend -= accum;
                quotient += i;
            }
            accum >>= 1; // accum/2
            i >>= 1; // i/2
        }
        return isNegative ? -quotient : quotient;
    }
};
