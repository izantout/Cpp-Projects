class Solution {
public:
    template<typename K, typename V>
    void printUnorderedMap(const unordered_map<K, V>& myMap) {
        cout << '[';
        for (const auto& pair : myMap) {
            cout << pair.first << ':' << pair.second << ',';
        }
        cout << ']' << endl;
    }

    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<int, int> myMap;
        // Go through each character of s
        for(int start=0, end=0; end<s.length(); ++end){
            // if the character is in the map already
            if(myMap.count(s[end]) > 0){
                // Update the start value
                start = max(start, myMap[s[end]] + 1);
            }
            // Add the character to the map
            myMap[s[end]] = end;
            // Update longest value
            longest = max(longest, end - start + 1);
        }
        return longest;
    }
};
