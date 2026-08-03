class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;
        // O(NxlogN)
        // O(N)
        for (int i = 0;i < nums.size();i++) {
            sum += nums[i];
            int remove = sum - k;
            count += mp[remove];
            mp[sum]++;
        }

        return count;
    }
};