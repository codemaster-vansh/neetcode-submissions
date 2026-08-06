class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() == 3) {
            int sum = nums[0] + nums[1] + nums[2];
            if (sum == 0) {
                return {{nums[0],nums[1],nums[2]}};
            } else {
                return {};
            }
        }

        int n = nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for (int k = 0;k < n-2;k++) {
            if (k> 0 && nums[k] == nums[k-1]) continue;
            int i = k + 1, j = n-1;

            int required_sum = -1*nums[k];
            while (i < j) {
                if (nums[i] + nums[j] == required_sum) {
                    result.push_back({nums[k],nums[i],nums[j]});
                    while (i < j && nums[j] == nums[j-1]) j--;
                    while (i < j && nums[i] == nums[i+1]) i++;
                    i++;j--;
                } else if (nums[i] + nums[j] > required_sum) {
                    j--;
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};
