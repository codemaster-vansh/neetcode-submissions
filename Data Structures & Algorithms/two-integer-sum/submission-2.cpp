class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        for (int i = 0;i < n;i++) {
            hashMap[nums[i]] = i;
        }

        for (int i = 0;i < n;i++) {
            int x = target - nums[i];
            if (hashMap.count(x) && hashMap[x] != i) {
                return {i, hashMap[x]};
            }
        }

        return {};
    }
};
