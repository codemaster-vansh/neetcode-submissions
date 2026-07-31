class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            int l = s.length();
            result += to_string(l) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int idx = 0, len = s.length();

        while (idx < len) {
            int l = 0;
            char c = s[idx];
            while (c != '#') {
                l = 10*l + (c - '0');
                idx++;
                c = s[idx];
            }
            idx++;
            string res = "";
            for (int i = 0;i < l;i++) {
                res += s[idx];
                idx++;
            }
            result.push_back(res);
        }
        return result;
    }
};
