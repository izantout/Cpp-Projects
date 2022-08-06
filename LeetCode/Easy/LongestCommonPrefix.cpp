class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int current = 0;
        for(int i=0;i < strs[0].length();i++){
            int isOk = 1;
            for(auto& s  : strs){
                if(current >= s.length() or s[current] != strs[0][current]){
                    isOk = 0;
                    break;
                }
            }
            if(isOk){
                current++;
            }
            else{
                break;
            }
        }
        return strs[0].substr(0,current);
    }
};
