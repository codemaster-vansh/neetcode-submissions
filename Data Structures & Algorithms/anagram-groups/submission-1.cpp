class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& word : strs) {
            int freq[26] = {0};
            for (char c : word) freq[c - 'a']++;

            string key;
            for (int i = 0;i < 26;i++) {
                if (freq[i] > 0) {
                    key += char('a' + i);
                    key += to_string(freq[i]);
                }
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> result;
        for (const auto& p : mp) {
            vector<string> ans;
            for (const auto& val : p.second) ans.push_back(val);
            result.push_back(ans);
        }

        return result;
    }
};
