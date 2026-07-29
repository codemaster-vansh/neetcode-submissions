class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int arr[26] = {0};

        for (char c : s) arr[c - 'a']++;
        for (char c : t) arr[c - 'a']--;

        for (int i = 0;i < 26;i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }
};
