class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        vector<pair<int,int>> v (mp.begin(), mp.end());

        sort(v.begin(), v.end(), [&](auto a, auto b) {
            return a.second > b.second;
        });

        auto vpair = v.front();
        return vpair.first;
    }
};