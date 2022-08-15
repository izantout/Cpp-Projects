class Solution {
public:
    const int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string intToRoman(int N) { //  N = 70
        string ans = "";
        for (int i = 0; N; i++)
            while (N >= val[i]) ans += rom[i], N -= val[i];
        return ans;
    }
};

/*
- for loop starts with i=0, comparing N with 1000 if N < 1000 it goes to 900.... until N becomes >= to val[i]. 
- It adds rom[i] to the string and removes val[i] from N and keeps doing it untill N becomes less than val[i]
- it increments i meaning the number N is compared to becomes smaller
- does the same thing, takes the rom[i] and subtracts N until N becomes 0 and you return the string
