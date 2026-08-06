class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for (int i = 0;i < n-3;i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1;j < n-2;j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j + 1, r = n-1;
                long long required_sum = (long long) target - nums[i] - nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] == required_sum) {
                        result.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    } else if (nums[l] + nums[r] > required_sum) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }

        return result;
    }
};