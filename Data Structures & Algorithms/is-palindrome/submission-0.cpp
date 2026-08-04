class Solution {
public:
    bool isPalindrome(string s) {
        auto new_end = remove_if(s.begin(),s.end(),[](unsigned char c) {
            return !isalnum(c);
        });

        s.erase(new_end,s.end());

        transform(s.begin(),s.end(),s.begin(),[](unsigned char c) {
            return tolower(c);
        });

        string s1 =     s;
        reverse(s1.begin(),s1.end());
        return (s1 == s);
    }
};
