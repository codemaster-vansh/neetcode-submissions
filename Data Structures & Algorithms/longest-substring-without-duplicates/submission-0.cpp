class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLen = 0;
        unordered_map<char, int> counter;
        for (int r = 0;r < s.length();r++) {
            counter[s[r]]++;
            while (counter[s[r]] > 1) {
                counter[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }   
        return maxLen;
    }
};
