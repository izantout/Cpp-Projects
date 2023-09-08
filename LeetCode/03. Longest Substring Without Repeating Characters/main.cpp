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
        unordered_map<char, int> myMap; // Use char as the key type

        for (int start = 0, end = 0; end < s.length(); ++end) {
            if (myMap.count(s[end]) > 0) {
                start = max(start, myMap[s[end]] + 1); // Update the starting index
            }
            myMap[s[end]] = end;
            longest = max(longest, end - start + 1);
        }
        return longest;
    }
};
