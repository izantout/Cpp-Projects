class Solution {
public:

    void printMap(unordered_map<char, int> myMap){
        for (const auto& pair : myMap) {
            cout << pair.first << ": " << pair.second << endl;
        }
        cout << endl;
    };

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLength = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            printMap(charMap);
            // CONTAINS
            if (charMap.count(s[i]) > 0) {
                // New start is current index
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};
