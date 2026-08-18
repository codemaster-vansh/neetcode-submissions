class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];

        for (int i = 1;i < nums.size();i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        auto f = [&](int maxSum) {
            int count = 1;
            int start = 0;

            for (int i = 0; i < nums.size(); i++) {
                int subSum = prefixSum[i] - (start > 0 ? prefixSum[start - 1] : 0);

                if (subSum > maxSum) {
                    count++;
                    start = i;

                    // nums[i] itself cannot fit
                    if (nums[i] > maxSum)
                        return false;
                }
            }

            return count <= k;
        };

        int lo = *max_element(nums.begin(),nums.end());
        int hi = prefixSum[nums.size() - 1];

        int res = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;

            if (f(mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return res;
    }
};