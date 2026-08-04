class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0,j=0;
        int n = word1.length();
        int m = word2.length();

        bool flag = true;
        string result = "";
        while (i < n && j < m) {
            if (flag) {
                result += word1[i++];
            } else {
                result += word2[j++];
            }
            flag ^= 1;
        }

        while (i < n) {
            result += word1[i++];
        }

        while (j < m) {
            result += word2[j++];
        }

        return result;
    }
};