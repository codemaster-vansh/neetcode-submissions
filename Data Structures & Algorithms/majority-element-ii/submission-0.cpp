class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = (int)floor((float) n / 3.0);

        vector<int> result;

        unordered_map<int,int> mp;
        for (int i = 0;i < n;i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > x) {
                result.push_back(nums[i]);
                mp[nums[i]] = -50000;
            }
        }
        return result;
    }
};