class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        roman.insert(make_pair('I',1));
        roman.insert(make_pair('V',5));
        roman.insert(make_pair('X',10));
        roman.insert(make_pair('L',50));
        roman.insert(make_pair('C',100));
        roman.insert(make_pair('D',500));
        roman.insert(make_pair('M',1000));
        
        int final = 0, strLength = s.length();
        for(int i=0; i<strLength; i++){
            if(i == (strLength-1) || (roman[s[i]]>= roman[s[i+1]])){
                final += roman[s[i]];
            } else {
                final += (roman[s[i+1]] - roman[s[i]]);
                i++;
            }
        }
        return final;
    }
};
